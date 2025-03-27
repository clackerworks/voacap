/* IONGAIN.f -- translated by f2c (version 20240504).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    real d2r, dcl, gama, pi, pi2, pio2, r2d, rz, vofl;
} con_;

#define con_1 con_

/* Table of constant values */

static real c_b37 = 2.f;

/* # gain.f */
/* Subroutine */ int iongain_(integer *kop, real *toaz, real *ysig, real *
	yeps, real *ynd, real *ynl, real *ynh, real *tex, real *delta, real *
	fmc, real *rain, real *eff)
{
    /* System generated locals */
    real r__1;

    /* Builtin functions */
    double sin(doublereal);

    /* Local variables */
    static real eff_90__, toaz_0__, rain_90__, gmorph, delta_90__;
    extern /* Subroutine */ int iongain2_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Parameter adjustments */
    --tex;

    /* Function Body */
    iongain2_(kop, toaz, ysig, yeps, ynd, ynl, ynh, &tex[1], delta, fmc, rain,
	     eff);
/*          this is to adjust type 3 & 4 antennas so 90 deg elevation */
/*          angle is consistent no matter what the azimuth */
    if (*kop == 3 || *kop == 4) {
	toaz_0__ = 0.f;
	delta_90__ = 1.570796f;
	iongain2_(kop, &toaz_0__, ysig, yeps, ynd, ynl, ynh, &tex[1], &
		delta_90__, fmc, &rain_90__, &eff_90__);
/* Computing 4th power */
	r__1 = sin(*delta), r__1 *= r__1;
	gmorph = r__1 * r__1;
	*rain = rain_90__ * gmorph + *rain * (1.f - gmorph);
    }
    return 0;
} /* iongain_ */

/* -------------------------------------------------------------- */
/* Subroutine */ int iongain2_(integer *kop, real *toaz, real *ysig, real *
	yeps, real *ynd, real *ynl, real *ynh, real *tex, real *delta, real *
	fmc, real *rain, real *eff)
{
    /* Initialized data */

    static real rintw = 18.06f;

    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3, r__4;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer i_nint(real *);
    double cos(doublereal), sin(doublereal), sqrt(doublereal), atan(
	    doublereal), asin(doublereal), r_lg10(real *), log(doublereal), 
	    r_mod(real *, real *), tan(doublereal);

    /* Local variables */
    static real a, b, c__, d__, e, f, g, h__;
    static integer i__, j, m;
    static real p, q, r__, s, t, u, v, w, x, y, z__, f1, a6, h1, h2, g2, b6, 
	    a7, b7, f7, g7, f8, g8, u1, u2, v1, v2, u3, u4, w5, w6, w7, w8, 
	    w1, w2, w3, w4, y1, y2, y3, y4, z1, z2, z3, z4, v3, v4, x7, y7, 
	    x8, y8, ca[10], cb, cg, ch, eh, el, hk, sa[10];
    static integer ik;
    static real sb, er, ra, cv, sg, ht, ex[4], hq, dy, dz, yh, vk, dx, ep;
    static integer nn;
    static real ss, fn, ev, sv, fm, sx, sz, xr, yv, el1, xb1, xt1, xt2, fac, 
	    chi, arg, chq, brk, phi, uc27, rhi, uc18, uc45, rho, sok, ert, 
	    brv, shq, uc36;
    static integer nep;
    static real cvi, sel, xkh, xkv, fac1, fac2, fac3, fac4, hac2, hac4, fac6, 
	    cin2, cin4, beta, himg;
    extern /* Subroutine */ int cisi_(real *, real *, real *);
    static real rho12, reta, wave, psih, vimg, temp, cfac2, asxv, psiv, sfac2,
	     elfac, ci_kl__;
    static integer ibeta;
    static real alpha, codif, hreal, sidif, sigma, hrain, denom, si_kl__, 
	    relta, bprim, hwave, vreal, psihi, value, vrain, floor, sphip, 
	    twave, cosum, psivi, dummy, elfac2, sisum, ci_2kl__, si_2kl__, 
	    copsi1, copsi2, copsi3, copsi4, copsi5, copsi6, copsi7, copsi8, 
	    sin2kl, cin_kl__, htwave, cin_2kl__;

/* --------------------------------- */
/* .....ITR .LT. 0 INDICATES TO CALCULATE GROUND REFLECTION LOSS */
/*     ITR = 1 INDICATES TRANSMITTER ANTENNA */
/*     ITR = 2 INDICATES RECEIVER ANTENNA */

/*     POWER GAIN OF ANTENNA AND GROUND REFLECTION LOSS */
/*     FOR LOSS, KOP IS ZERO OR MINUS */
/*     DIMENSION A(10),B(10),CA(10),SA(10) */
/* toaz  is off azimuth in degrees */
/* DELTA IS ELEVATION ANGLE,RADIANS */
/* FMC  IS FREQUENCY,MHZ. */
/* BETA IS 0.0 FOR LOSS AND VARIES WITH ANTENNA TYPE. */
/* SIGMA IS GROUND CONDUCTIVITY, MHOS/METER. */
/* ER IS GROUND RELATIVE DIELECTRIC CONSTANT. */
/* PHI,EL,H AND EX(4) VARY WITH ANTENNA TYPE */
/* RAIN IS LOSS OR GAIN. */


/*     THE REFLECTION COEFFICIENTS ARE */
/*     KSUBV = -CV * EXP(I * PSIV),  KSUBV = CV * EXP(I * GAMMAV) */
/*     KSUBH = -CH * EXP(I * PSIH),  KSUBH = CH * EXP(I * GAMMAH) */
/*     IE  NORMALIZED WITH PSI = GAMMA + PI, PSI = GAMMA - PI */

/*     IONCAP REPORT VOLUME 1 PAGE 115 OR ITSA-1 PAGE 65 */
/*     N O T E THIS IS NOT THE SAME AS MA AND WALTERS, ITS-74, PAGE 8 */

/* cc      COMMON /DON /ALATD, AMIN, AMIND, BTR, BTRD */
/* cc      COMMON/GEOG/GYZ(5),RAT(5),GMDIP(5),CLCK(5),ABIY(5),ARTIC(5),SIGPAT */
/* cc     A (5),EPSPAT(5) */
    /* Parameter adjustments */
    --tex;

    /* Function Body */
/* .....RINTW IS "RA" FOR VERTICAL MONOPOLE AT H/LAMDA = .2 */
/* cc      write(*,'('' in iongain, kop='',i5,10f8.3)') */
/* cc     +         kop,toaz,ysig,yeps,ynd,ynl,ynh,tex */
    sok = 0.f;
    *rain = 0.f;
    *eff = 0.f;
    floor = -30.f;
/* ******************************************************** */
/*  minimum antenna gain value */
    sigma = *ysig;
    er = *yeps;
    beta = *toaz;
    phi = *ynd;
    el = *ynl;
    h__ = *ynh;
    for (ik = 1; ik <= 4; ++ik) {
/* L535: */
	ex[ik - 1] = tex[ik];
    }
    if (sigma <= 0.f) {
	s_stop("In GAIN, SIGMA<=0.", (ftnlen)18);
    }
/* ********************************************************************* */
/* .....THE EQUATIONS FOR THE FRESNEL REFLECTION COEFFICIENTS ARE IN */
/* .....VOLUME I OF THE OT REPORT ON THIS ANALYSIS PROGRAM */
    sok = 0.f;
    if (*delta <= 0.f) {
/*  elevation angle=0  force gain=-30 */
	*rain = floor;
	goto L610;
    }
    relta = *delta;
/*           for vertical beam, force off azimuth=0 so answers will be the same */
/* cc      if(abs(DELTA-PIO2).lt..0001) BETA=0. */
    ibeta = i_nint(&beta);
    x = sigma * 1.8e4f / *fmc;
    t = cos(relta);
    q = sin(relta);
    r__ = q * q;
    s = r__ * r__;
    ert = er - t * t;
    rho = sqrt(ert * ert + x * x);
    rho12 = sqrt(rho);
    alpha = -atan(x / ert);
    u = er * er + x * x;
    v = sqrt(u);
    asxv = asin(x / v);
    cv = sqrt(rho * rho + u * u * s - rho * 2.f * u * r__ * cos(alpha + asxv *
	     2.f)) / (rho + u * r__ + rho12 * 2.f * v * q * cos(alpha * .5f + 
	    asxv));
    *rain = 0.f;
    a = rho12 * 2.f * q * v * sin(alpha * .5f + asxv);
    wave = 299.7925f / *fmc;
    b = rho - u * r__;
    if (b < 0.f) {
	goto L135;
    } else if (b == 0) {
	goto L115;
    } else {
	goto L140;
    }
L115:
    if (a < 0.f) {
	goto L120;
    } else if (a == 0) {
	goto L125;
    } else {
	goto L130;
    }
L120:
    psiv = -1.570796f;
    goto L145;
L125:
    psiv = 0.f;
    goto L145;
L130:
    psiv = 1.570796f;
    goto L145;
L135:
    psiv = atan(a / b) + 3.141593f;
    goto L145;
L140:
    psiv = atan(a / b);
L145:
    sok = ex[0];
    reta = beta * .017453293f;
    psih = atan(rho12 * 2.f * q * sin(alpha * .5f) / (rho - r__));
    sb = sin(reta);
    cb = cos(reta);
    x = 1.f;
    ch = sqrt(rho * rho + s - rho * 2.f * r__ * cos(alpha)) / (rho + r__ + 
	    rho12 * 2.f * q * cos(alpha * .5f));
    if ((r__1 = cv - ch, dabs(r__1)) <= .001f) {
	cv = ch;
    }
    if (el >= 0.f) {
	goto L185;
    } else {
	goto L165;
    }
L165:
    el1 = dabs(el);
    fac = el1 * 3.1416f;
    goto L190;
L185:
    fac = el * 3.1416f / wave;
    el1 = el / wave;
L190:
    if (h__ <= 0.f) {
	goto L200;
    } else {
	goto L195;
    }
L195:
    hwave = h__ * 6.2832f / wave;
    h1 = h__ / wave;
    goto L220;
L200:
    h1 = dabs(h__);
    hwave = h1 * 6.2832f;
L220:
    rhi = phi * .017453293f;
/* .....THE EQUATIONS USED FOR EACH OF THE ANTENNAS SPECIFIED BELOW ARE IN */
/* .....VOLUME I OF THE OT REPORT ON THIS ANALYSIS PROGRAM */
    switch (*kop) {
	case 1:  goto L230;
	case 2:  goto L350;
	case 3:  goto L340;
	case 4:  goto L340;
	case 5:  goto L345;
	case 6:  goto L270;
	case 7:  goto L265;
	case 8:  goto L245;
	case 9:  goto L265;
	case 10:  goto L240;
    }

/*    TERMINATED RHOMBIC                          KOP=1 */

L230:
    u1 = 1.f - t * sin(rhi + reta);
    u2 = 1.f - t * sin(rhi - reta);
/* Computing 2nd power */
    r__1 = cos(rhi) * sin(fac * u1) * sin(fac * u2) / (u1 * u2);
/* Computing 2nd power */
    r__2 = cb - sin(rhi) * t;
    *rain = r__1 * r__1 * 3.2f * (r__2 * r__2 * (ch * ch + 1.f - ch * 2.f * 
	    cos(psih - hwave * 2.f * q)) + sb * sb * (cv * cv + 1.f - cv * 
	    2.f * cos(psiv - hwave * 2.f * q)) * r__);
    goto L385;

/*      TERMINATED INTERLACED RHOMBIC             KOP=10 */

L240:
    ht = ex[0];
    sok = 0.f;
    ss = ex[1];
    e = sin(rhi);
    f = cos(rhi);
    d__ = sqrt(ss * ss + ht * ht);
    sg = ht / d__;
    cg = ss / d__;
    htwave = ht * 6.283185308f / wave;
    yh = psih - hwave * 2.f * q;
    yv = psiv - hwave * 2.f * q;
    u1 = 1.f - t * sin(reta + rhi);
    u2 = 1.f - t * sin(rhi - reta);
    elfac = f * sin(fac * u1) * sin(fac * u2) / (u1 * u2);
    elfac2 = elfac * elfac;
    y = 6.283185308f / wave * (ss - d__ * (q * sg + t * cg * cb));
    z__ = y - htwave * 2.f * q;
    h1 = cos(y) + 1.f - ch * (cos(yh) * (cos(z__) + 1.f) - sin(yh) * sin(z__))
	    ;
    h2 = -sin(y) - ch * (-sin(yh) * (cos(z__) + 1.f) - cos(yh) * sin(z__));
    hk = h1 * h1 + h2 * h2;
    brk = cb - e * t;
    hrain = elfac2 * brk * brk * hk;
    v1 = cos(y) + 1.f - cv * (cos(yv) * (cos(z__) + 1.f) - sin(yv) * sin(z__))
	    ;
    v2 = -sin(y) - cv * (-sin(yv) * (cos(z__) + 1.f) - cos(yv) * sin(z__));
    vk = v1 * v1 + v2 * v2;
    brv = sb * sb * r__;
    vrain = elfac2 * brv * vk;
    *rain = (hrain + vrain) * .8f;
    goto L385;

/*      INVERTED L                                KOP=8 */

L245:
    fac2 = fac * 2.f;
    fac4 = fac * 4.f;
    twave = hwave * .15916f;
    if (twave - .2f >= 0.f) {
	goto L251;
    } else {
	goto L250;
    }
L250:
    *eff = twave * (twave * (67.95f - twave * (693.f - twave * 1600.f)) + 
	    6.335f);
    *eff = r_lg10(eff) * 20.f;
    goto L252;
L251:
    *eff = 0.f;
L252:
    hac2 = hwave + hwave;
    hac4 = hac2 + hac2;
    cisi_(&hac2, &w5, &w6);
    cisi_(&hac4, &w7, &w8);
    cin2 = log(hac2) + .577215f - w5;
    cin4 = log(hac4) + .577215f - w7;
    ra = (cos(hac2) * -.5f * cin4 + (cos(hac2) + 1.f) * cin2 + sin(hac2) * (
	    w8 * .5f - w6)) * 30.f;
    u = t * sb;
    hk = ch * ch + 1.f - ch * 2.f * cos(psih - hwave * 2.f * q);
    c__ = 1.f - cos(fac2 * u) * cos(fac2) - u * sin(fac2 * u) - sin(fac2) * 
	    .5f * sin(fac2) * (1.f - u * u);
    hq = q * hwave;
    chq = cos(hq);
    shq = sin(hq);
    cfac2 = cos(fac2);
    sfac2 = sin(fac2);
    a = cfac2 * chq - q * sfac2 * shq - cos(hwave + fac2);
    b = q * sfac2 * chq + cfac2 * shq - q * sin(hwave + fac2);
    bprim = 0.f;
    if (a != 0.f) {
	bprim = atan(b / a);
    }
    sphip = 1.f - u * u;
    g2 = 0.f;
    if (sphip != 0.f) {
/* Computing 2nd power */
	r__1 = c__ * 2.f * cb / sphip;
	g2 = hk * (r__1 * r__1);
    }
    f1 = 0.f;
    if (t != 0.f) {
	f1 = (a * a + b * b) * (1.f - cv * 2.f * cos(psiv - bprim * 2.f) + cv 
		* cv) / (t * t);
    }
    *rain = (g2 + f1) * 30.f / ra;
    x = 1.f;
    goto L385;

/* .....TERMINATED SLOPING VEE           KOP = 7, */
/* .....AND TERMINATED SLOPING RHOMBIC   KOP = 9. */
L265:
    ht = ex[0];
    sok = 0.f;
    if (ht < 0.f) {
	ht = dabs(ht);
    } else {
	ht /= wave;
    }
    g = (ht - h1) / el1;
    if (*kop == 9) {
	g *= .5f;
    }
    p = sqrt(1.f - g * g);
    e = sin(rhi);
    f = cos(rhi);
    rhi = asin(e / p);
    sisum = sin(rhi + reta);
    sidif = sin(reta - rhi);
    cosum = cos(rhi + reta);
    codif = cos(rhi - reta);
    copsi1 = q * g + t * p * codif;
    copsi2 = q * g + t * p * cosum;
    copsi3 = -q * g + t * p * codif;
    copsi4 = -q * g + t * p * cosum;
    copsi5 = t * g + q * p * codif;
    copsi6 = t * g + q * p * cosum;
    copsi7 = -t * g + q * p * codif;
    copsi8 = -t * g + q * p * cosum;
    u1 = 1.f - copsi1;
    u2 = 1.f - copsi2;
    u3 = 1.f - copsi3;
    u4 = 1.f - copsi4;
    w1 = cos(psih - hwave * 2.f * q);
    w2 = sin(psih - hwave * 2.f * q);
    w3 = cos(psiv - hwave * 2.f * q);
    w4 = sin(psiv - hwave * 2.f * q);
    fac2 = fac * 2.f;
    if (*kop - 9 >= 0) {
	goto L235;
    } else {
	goto L268;
    }
L268:
    y1 = u1 * sisum;
    y2 = u2 * sidif;
    y3 = u3 * sisum;
    y4 = u4 * sidif;
    z1 = cos(fac2 * u1) - 1.f;
    z2 = cos(fac2 * u2) - 1.f;
    z3 = cos(fac2 * u3) - 1.f;
    z4 = cos(fac2 * u4) - 1.f;
    v1 = sin(fac2 * u1);
    v2 = sin(fac2 * u2);
    v3 = sin(fac2 * u3);
    v4 = sin(fac2 * u4);
    uc27 = u2 * copsi7;
    uc18 = u1 * copsi8;
    uc45 = u4 * copsi5;
    uc36 = u3 * copsi6;
/* Computing 2nd power */
    r__1 = (y2 * z1 - y1 * z2) / (u1 * u2) - ch / (u3 * u4) * (y4 * (w1 * z3 
	    + w2 * v3) - y3 * (w1 * z4 + w2 * v4));
/* Computing 2nd power */
    r__2 = (-y2 * v1 + y1 * v2) / (u1 * u2) - ch / (u3 * u4) * (y4 * (w2 * z3 
	    - w1 * v3) - y3 * (w2 * z4 - w1 * v4));
/* Computing 2nd power */
    r__3 = (z1 * uc27 - z2 * uc18) / (u1 * u2) - cv / (u3 * u4) * (w3 * (z3 * 
	    uc45 - z4 * uc36) + w4 * (v3 * uc45 - v4 * uc36));
/* Computing 2nd power */
    r__4 = (-v1 * uc27 + v2 * uc18) / (u1 * u2) - cv / (u3 * u4) * (w3 * (-v3 
	    * uc45 + v4 * uc36) + w4 * (z3 * uc45 - z4 * uc36));
    *rain = (p * p * (r__1 * r__1 + r__2 * r__2) + r__3 * r__3 + r__4 * r__4) 
	    * .025f;
    *rain *= 2.f;
    x = 1.f;
    goto L385;
/*  FINISH TERMINATED SLOPING RHOMBIC , KOP = 9 */
L235:
    a6 = cos(fac2 * (u1 + u2)) + 1.f - cos(fac2 * u1) - cos(fac2 * u2);
    b6 = -sin(fac2 * (u1 + u2)) + sin(fac2 * u1) + sin(fac2 * u2);
    a7 = cos(fac2 * (u3 + u4)) + 1.f - cos(fac2 * u3) - cos(fac2 * u4);
    b7 = -sin(fac2 * (u3 + u4)) + sin(fac2 * u3) + sin(fac2 * u4);
    x7 = copsi8 / u2 - copsi7 / u1;
    y7 = copsi5 / u3 - copsi6 / u4;
    x8 = sidif / u1 - sisum / u2;
    y8 = sidif / u3 - sisum / u4;
/* .....SWITCH TO MA"S USE */
    psiv -= con_1.pi;
    psih += con_1.pi;
    w1 = cos(psih - hwave * 2.f * q);
    w2 = sin(psih - hwave * 2.f * q);
    w3 = cos(psiv - hwave * 2.f * q);
    w4 = sin(psiv - hwave * 2.f * q);
    f7 = x7 * a6 + y7 * cv * (a7 * w3 - b7 * w4);
    g7 = x7 * b6 + y7 * cv * (a7 * w4 + b7 * w3);
    f8 = x8 * a6 + y8 * ch * (a7 * w1 - b7 * w2);
    g8 = x8 * b6 + y8 * ch * (a7 * w2 + b7 * w1);
    *rain = (f7 * f7 + g7 * g7 + p * p * (f8 * f8 + g8 * g8)) * .05f;
    goto L385;

/*     CURTAIN                                    KOP=6 */
L270:
    if ((r__1 = *delta - con_1.pio2, dabs(r__1)) > 1.f) {
	goto L272;
    }
/*  not vertical */
L271:
    *rain = floor;
    goto L610;
L272:
    sok = 0.f;
/* .....ALLOW SPACING FOR CURTAIN TO BE IN WAVELENGTHS */
/* .....(TO ALLOW CCIR ANTENNA PATTERNS HR M/N/H WITH EX(4)=-.25) */

    dy = ex[1] / wave;
/*  horz spacing bet dipole cent */
    if (ex[1] <= 0.f) {
	dy = dabs(ex[1]);
    }
/*  wavelengths */
    dz = ex[2] / wave;
/*  vert spacing between dipoles */
    if (ex[2] <= 0.f) {
	dz = dabs(ex[2]);
    }
/*  wavelengths */
    dx = ex[3] / wave;
/*  distance to screen */
    if (ex[3] <= 0.f) {
	dx = dabs(ex[3]);
    }
/* .....HEIGHT OF BOTTOM ELEMENT IS H1 */
/*  wavelengths */
    chi = ch;
    psihi = psih;
    ch = -chi * cos(psihi);
    psih = -chi * sin(psihi);
    if (r_mod(&phi, &c_b37) != 0.f) {
	goto L275;
    } else {
	goto L280;
    }
L275:
    ep = 1.f;
    nep = 1;
    goto L285;
L280:
    ep = 0.f;
    nep = 0;
L285:
    nn = (phi - ep) / 2.f;
    m = ex[0];
    cvi = cv;
    psivi = psiv;
    cv = -cvi * cos(psivi);
    psiv = -cvi * sin(psivi);
    fac1 = fac;
    fac2 = fac * 2.f;
    fac3 = con_1.pi * dy;
    denom = 1.f - sb * sb * t * t;
    sel = cos(fac1 * sb * t) - cos(fac1);
    sv = sb * q;
    sz = sin(con_1.pi * 2.f * dx * cb * t);
    sx = ep;
    fac4 = t * sb;
    i__1 = nn;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fn = (real) ((i__ << 1) - 1 + nep);
/* L290: */
	sx += cos(fn * fac3 * fac4) * 2.f;
    }
    fac6 = sel * sx * sz / denom;
    hreal = 0.f;
    himg = 0.f;
    vreal = 0.f;
    vimg = 0.f;
    eh = 0.f;
    ev = 0.f;
    i__1 = m;
    for (j = 1; j <= i__1; ++j) {
	fm = (real) (j - 1);
	arg = con_1.pi * 2.f * q * (h1 + fm * dz);
	ca[j - 1] = cos(arg);
/* L295: */
	sa[j - 1] = sin(arg);
    }
    i__1 = m;
    for (j = 1; j <= i__1; ++j) {
	hreal += (ca[j - 1] * (ch + 1.f) + psih * sa[j - 1]) * 1.f;
	himg += (sa[j - 1] * (1.f - ch) + psih * ca[j - 1]) * 1.f;
/* L315: */
    }
    eh = fac6 * cb * sqrt(hreal * hreal + himg * himg);
    i__1 = m;
    for (j = 1; j <= i__1; ++j) {
	vreal += (ca[j - 1] * (cv + 1.f) + psiv * sa[j - 1]) * 1.f;
	vimg += (sa[j - 1] * (1.f - cv) + psiv * ca[j - 1]) * 1.f;
/* L330: */
    }
    ev = fac6 * sv * sqrt(vreal * vreal + vimg * vimg);
    value = sqrt(eh * eh + ev * ev);
    if (value <= 1e-5f) {
	goto L271;
    }
    *rain = r_lg10(&value) * 20.f;
    sok = 0.f;
    goto L610;

/*     HORIZONAL DIPOLE AND HORIZONAL YAGI        KOP=3 AND 4 */
L340:
    dummy = fac * 4.f;
    cisi_(&dummy, &w, &w1);
    dummy = fac * 2.f;
    cisi_(&dummy, &w2, &w3);
    g = 1.f / tan(fac);
    ss = sb * sb;
    c__ = t * t;
/* xxx      RAIN = 4. / ((1. - G * G) * (.5772 + ALOG (4. * FAC) + W) + 4. * G */
/* xxx     1 * G * (.5772 + ALOG (2. * FAC) + W2) + 2. * G * (W1 - 2. * W3)) * */
/* xxx     2 ((COS (FAC * SB * T) - COS (FAC)) / (1. - SS * C)) * * 2 * (CB * */
/* xxx     3CB * (CH * CH + 1. - 2. * CH * COS (PSIH - 2. * HWAVE * Q)) + SB * */
/* xxx     4 SB * R * (CV * CV + 1. - 2. * CV * COS (PSIV - 2. * HWAVE * Q))) */
    ci_kl__ = w2;
    si_kl__ = w3;
    ci_2kl__ = w;
    si_2kl__ = w1;
    cin_kl__ = log(fac * 2.f) + .577f - ci_kl__;
    cin_2kl__ = log(fac * 4.f) + .577f - ci_2kl__;
/* Computing 2nd power */
    r__1 = sin(fac * 2.f);
    sin2kl = r__1 * r__1;
    sin2kl = 1.f;
    xr = ((1.f - g * g) * cin_2kl__ + g * 4.f * g * cin_kl__ + g * 2.f * (
	    si_2kl__ - si_kl__ * 2.f)) * 30.f / sin2kl;
    xkv = cv * cv + 1.f - cv * 2.f * cos(psiv - hwave * 2.f * q);
    xkh = ch * ch + 1.f - ch * 2.f * cos(psih - hwave * 2.f * q);
    xt1 = cos(fac * sb * t) - cos(fac);
    xb1 = 1.f - ss * c__;
    xt2 = (xkv * ss * r__ + xkh * cb * cb) / sin2kl;
/* Computing 2nd power */
    r__1 = xt1 / xb1;
    *rain = 120.f / xr * (r__1 * r__1) * xt2;
/* cc      if(abs(DELTA-PIO2).lt..0001) then      !  90 degrees elevation angle */
/* cc      if(ibeta.eq.0 .or. ibeta.eq.90) then */
/* cc         write(15,'('' delta,beta='',2f10.4)') delta,beta */
/* cc         write(15,'('' sin_delta,cos_delta='',2f10.4)') q,t */
/* cc         write(15,'('' sin_beta ,cos_beta ='',2f10.4)') SB,CB */
/* cc         write(15,'('' SS,R,CB='',3e15.7)') SS,R,CB */
/* cc         write(15,'('' PXIV,PSIH='',2e15.7)') PSIV,PSIH */
/* cc         write(15,'('' xKv,xKh='',2e15.7)') xKv,xKh */
/* cc         write(15,'('' xR='',e15.7)') xR */
/* cc         write(15,'('' xt1='',e15.7)') xt1 */
/* cc         write(15,'('' xb1='',e15.7)') xb1 */
/* cc         write(15,'('' xt2='',e15.7)') xt2 */
/* cc         write(15,'('' RAIN='',e15.7)') RAIN */
/* cc         write(15,'('' CH,CV='',2e15.7)') CH,CV */
/* cc      end if */
/* cc      end if */
    goto L385;

/*        VERTICAL LOG PERIODIC                   KOP=5 */
L345:
    sok = ex[0];
    goto L351;
/*      VERTICAL MONOPOLE                          KOP = 2 */
L350:
    sok = h__;
L351:
    temp = h__;
    h__ = el;
    el = temp;
    e = er;
    if (h__ <= 0.f) {
	goto L360;
    } else {
	goto L355;
    }
L355:
    a = h__ * 6.283185f / wave;
    x = h__ / wave;
    goto L380;
L360:
    h1 = dabs(h__);
    a = h1 * 6.283185f;
    x = h1;
L380:
    d__ = a * 2.f;
    z__ = d__ * 2.f;
    cisi_(&z__, &w, &w1);
    cisi_(&d__, &w2, &w3);
    hwave = x * 6.283f;
    ra = (cos(d__) * -.5f * (log(z__) + .577215f - w) + (cos(d__) + 1.f) * (
	    log(d__) + .577215f - w2) + sin(d__) * (w1 * .5f - w3)) * 30.f;
    if (el1 - .2f >= 0.f) {
	goto L354;
    } else {
	goto L353;
    }
L353:
    ra = el1 * 400.f * el1 * rintw / 16.f;
L354:
    denom = cos(hwave * q) - cos(hwave);
    if (denom == 0.f) {
	denom = 1e-8f;
    }
    bprim = atan((sin(hwave * q) - q * sin(hwave)) / denom);
/* Computing 2nd power */
    r__1 = (cos(hwave * q) - cos(hwave)) / (t * cos(bprim));
    *rain = r__1 * r__1 * (cv * cv + 1.f - cv * 2.f * cos(psiv - bprim * 2.f))
	     * 30.f / ra;
L385:
    *rain = dmax(*rain,1e-5f);
    *rain = r_lg10(rain) * 10.f;
/* .....DO ANTENNA EFFICIENCY AS ITSA-1 RELBIL. */
L610:
    switch (*kop) {
	case 1:  goto L620;
	case 2:  goto L625;
	case 3:  goto L615;
	case 4:  goto L615;
	case 5:  goto L625;
	case 6:  goto L615;
	case 7:  goto L620;
	case 8:  goto L630;
	case 9:  goto L620;
	case 10:  goto L620;
	case 11:  goto L615;
    }
L615:
    *eff = 0.f;
    goto L405;
L620:
    *eff = -1.7f;
    goto L405;
L625:
    if (x >= .35f) {
	goto L615;
    }
    *eff = (((x * 6416.702573f - 6091.33295f) * x + 2179.890548f) * x - 
	    364.8173803f) * x + 25.64620146f;
    *eff = -(*eff);
    goto L405;
/*   EFF CALCULATED ABOVE, KOP=8 */
L630:
L405:
    *rain = *rain + *eff + sok;
    if (*kop == 2) {
	goto L420;
    }
    if (*rain <= floor) {
	*rain = floor + *eff;
    }
L420:
    return 0;
} /* iongain2_ */

