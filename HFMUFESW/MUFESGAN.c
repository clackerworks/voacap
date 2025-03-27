/* MUFESGAN.f -- translated by f2c (version 20240504).
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
    real d2r, dcl, gama, pi, pi2, pio2, r2d, ro, vofl;
} con_;

#define con_1 con_

struct {
    real dij, eil, hij;
    integer kode;
} cur_;

#define cur_1 cur_

struct {
    real cfac, ct, h2, prod1, rhi2, r21, x21, y0, z0;
} mut_;

#define mut_1 mut_

struct waits_1_ {
    real hh[48], xi[48];
};

#define waits_1 (*(struct waits_1_ *) &waits_)

struct {
    real d1d[20], ell[20];
    integer nmx, no;
    complex zs[20];
} hfmufes_one__;

#define hfmufes_one__1 hfmufes_one__

/* Initialized data */

struct {
    real e_1[96];
    } waits_ = { .0031533460523f, .007327553901f, .011477234579f, 
	    .015579315723f, .019616160457f, .023570760839f, .027426509708f, 
	    .031167227833f, .034777222565f, .038241351066f, .041545082943f, 
	    .044674560857f, .047616658492f, .050359035554f, .052890189485f, 
	    .0551995037f, .0572772921f, .059114839698f, .060704439166f, 
	    .06203942316f, .063114192286f, .063924238585f, .064466164436f, 
	    .064737696813f, .064737696813f, .064466164436f, .063924238585f, 
	    .063114192286f, .06203942316f, .060704439166f, .059114839698f, 
	    .0572772921f, .0551995037f, .052890189485f, .050359035554f, 
	    .047616658492f, .044674560857f, .041545082943f, .038241351066f, 
	    .034777222565f, .031167227833f, .027426509708f, .023570760839f, 
	    .019616160457f, .015579315723f, .011477234579f, .0073275539013f, 
	    .0031533460523f, -.99877100725f, -.99353017227f, -.98412458372f, 
	    -.97059159255f, -.95298770316f, -.93138669071f, -.90587913672f, 
	    -.87657202027f, -.84358826162f, -.80706620403f, -.76715903252f, 
	    -.72403413092f, -.67787237963f, -.62886739678f, -.57722472608f, 
	    -.52316097472f, -.46690290475f, -.40868648199f, -.34875588629f, 
	    -.28736248736f, -.22476379039f, -.16122235607f, -.097004699209f, 
	    -.032380170963f, .032380170963f, .097004699209f, .16122235607f, 
	    .22476379039f, .28736248736f, .34875588629f, .40868648199f, 
	    .46690290475f, .52316097472f, .57722472608f, .62886739678f, 
	    .67787237963f, .72403413092f, .76715903252f, .80706620403f, 
	    .84358826162f, .87657202027f, .90587913672f, .93138669071f, 
	    .95298770316f, .97059159255f, .98412458372f, .99353017227f, 
	    .99877100725f };


/* Table of constant values */

static complex c_b37 = {1.f,0.f};
static integer c__1 = 1;
static integer c__2 = 2;

/* SUBROUTINE GAIN             (NEXT) */
/*          this is the GAIN routine for HFMUFES ITS-78 antennas */
/* Subroutine */ int mufesgan_(integer *kop, integer *kas, real *toaz, real *
	ysig, real *yeps, real *ynd, real *ynl, real *ynh, real *tex, real *
	delta, real *freq, real *rain, real *eff)
{
    /* Initialized data */

    static real sqrtwo = 1.41421356237f;
    static real rintw = 18.06f;
    static real rinfr = 100.34f;
    static real xintr = .600012f;

    /* Format strings */
    static char fmt_276[] = "(\002TIP>H/WAVE  H,EL,WAVE,FREQ,EL1,TIP,X=\002,"
	    "7f10.4)";
    static char fmt_446[] = "(\002 Antenna type 10 not used for HFMUFES GA"
	    "IN.\002)";
    static char fmt_636[] = "(\002 TIP > X in HUMUFES GAIN calculations.\002)"
	    ;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    real r__1, r__2, r__3, r__4, r__5, r__6, r__7, r__8, r__9, r__10;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8, q__9, q__10, 
	    q__11, q__12, q__13, q__14, q__15, q__16, q__17, q__18, q__19, 
	    q__20, q__21, q__22, q__23, q__24, q__25, q__26, q__27, q__28, 
	    q__29, q__30, q__31, q__32, q__33;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);
    void c_sqrt(complex *, complex *), c_div(complex *, complex *, complex *);
    double c_abs(complex *), log(doublereal), r_imag(complex *), sqrt(
	    doublereal), atan2(doublereal, doublereal);
    void r_cnjg(complex *, complex *);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double asin(doublereal);
    void pow_ci(complex *, complex *, integer *);
    double acos(doublereal), r_lg10(real *), tan(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static real rain_min__, a, c__, d__[20], f, g, h__;
    static integer i__, j, k, m, n;
    static real p, q;
    static complex r__[25]	/* was [5][5] */;
    static real t;
    static complex v;
    static real x;
    static complex z__[400]	/* was [20][20] */, a1, b1;
    static real c1, d1, a2, b2, a4, b4, a5, b5, f2, g2, f1, g1, r1, r2, u1, 
	    u2, w1, w3, w4, w2, v1, w5, w6, u3, u4, z1, v2, z2, v3, z3, v4, 
	    z4, y1, y3, y2, y4, r4, aa, bb, cb, cc;
    static complex af;
    static real cd, f11, g11, ch, ci, f12, g12, am, el, bp, gi, as;
    static complex rc;
    static real er;
    static complex rh;
    static real cv, ex[4], cr, sb;
    static complex rp[25]	/* was [5][5] */;
    static real xk[20], yi[400]	/* was [20][20] */;
    static complex rt[50]	/* was [5][10] */, zm, rv;
    static real sr, hq, yr[400]	/* was [20][20] */, tx[400]	/* was [20][
	    20] */, ty[400]	/* was [20][20] */;
    static complex zt;
    static real rz, dp, qu, cw, rq, qq, eq, ta, xx, td, ts, tb, tt, uz, vz, 
	    pr, w33, el1;
    static integer nb, ne;
    static real dy, dz, dx;
    static integer ij, nm1, nm2, mn;
    static real em, en, ht, cs, ss;
    static complex wk2;
    static real sd, cp5, cp6, cp7, cp8, fu1, fu2, fu3, tx1, fu4, u12, u34, 
	    aa2, bb2, xl, xh, wk, wl, wh, wb, ab4, fac, wc, ab5, w2h, w4h, 
	    ci2;
    extern /* Subroutine */ int ech_(complex *);
    static integer nbb;
    static complex dif;
    static real ci4;
    static integer nee;
    static real cij;
    static complex eta, ctd;
    static real cxc, phi, eti;
    static complex azh;
    static real cix[20], ciy[20], rhi, ctk, rin;
    static complex ctu, rzb[5], rdz[50]	/* was [5][10] */, rze[5], azv;
    static real tsc, tcs;
    extern /* Subroutine */ int sim_(void);
    static real etr, stk, sis, fac2, tip, fac4, hac2;
    static complex ztr;
    static real hac4;
    static integer ipj;
    static real cmn, sbz;
    static complex rzz;
    static real scp, ccp, ssp, csp, eta1, eta2, sph, cph, eps, sig, wlh, swl, 
	    cwl, swb, cwb, swc, cwc, bpp, dab5, hab5, dab4, cin2, cin4, si2;
    extern /* Complex */ VOID csz1_(complex *, real *);
    static real si4, cw2h, sw2h, vrt, sum1, sum2, cm, cn, cmp, cnp, an, pam, 
	    pan, crb, srt, cbs, srq, cig, yz;
    static integer ii;
    extern doublereal cang_(complex *);
    static real cele, beta, sfac, caya, cbay, rhab;
    static integer nii;
    static complex ephi;
    static real cphi, flog;
    static complex acsq;
    static real cipj, reta;
    static complex rhcp, delz;
    extern doublereal onej_(real *);
    static integer ikex;
    static complex rdzb[10];
    static real wave;
    static complex qpar, rdze[25]	/* was [5][5] */;
    static real psih;
    static complex qper;
    static real plog;
    static complex sqrd;
    static real cpsi;
    extern /* Subroutine */ int coll_(complex *);
    static complex rpzb[5];
    static real cfac2;
    static complex rpze[5], rtzb[10];
    static real psiv;
    static complex rtze[25]	/* was [5][5] */;
    static real psig, swlh, cwlh;
    static complex rdzz[5];
    static real rvab, parv, sfac2;
    extern /* Subroutine */ int zmut_(complex *);
    static real c2kel, parh, cigp, sigp;
    static integer nip;
    static complex rpzz;
    static real delr1;
    static complex rtzz[5];
    static real delr2, ephi1, ephi2;
    static integer jj, mid;
    static real cot, s2kel, zts, yrn;
    static integer jend, jen;
    static real sphi2;
    static integer jl, jk;
    static real sum0, sumd, th, txs;
    static complex wkok2, wk2ok;
    static real swlh2, spsi2;
    static integer nj;
    static real epr, epi, cq2, arg5, cr5, sr5, ccb, scb, dd, dc, csb, di;
    static complex zsum1, zsum2, zsum3, zsum4;
    static real cbeta, alpha, r11, cdelp, tt2, epmag;
    static integer ijend;
    static real deltd, etmag, ts2, sts4, sigma;
    static integer mnend;
    static real cphip, cts4, tt1, sdelp, ts1, sts1, hwave, cayvh, cts1, train,
	     ratio, fi1, floor, fi4, psiph, fi2, const__, fmult, f4c, r4c, rb;
    static complex curnt;
    static real bi, ra, ai, em1, rzero, enn1, el2, fak, del, cdel, sdel, sx1, 
	    bp1, cp1, sp1, sx2, bp2, cp2, sp2, rp1m, eteta1, eteta2, rp2p, 
	    rm2m, rm1p, argl1, sl1, dmpio2, ethet1, ethet2, cl1, w1h1, w2h1, 
	    w3h1, w4h1, argl2, sl2, cl2, sphip2, w1h2, w2h2, w3h2, w4h2, c11, 
	    s11, c22, s22, c23, s23, c14, s14;
    static complex zterm1, zterm2, zterm3, zterm4;
    static real u1g, u2g, u3g, u4g, vr1, vi1, vr2, vi2, vr3, vi3, vr4, vi4, 
	    vr1g, vr2g, vr3g, vr4g, vr5g, vr6g, vr7g, deltap;
    static integer ipjend;
    static real vr8g, vi1g, vi2g, factor, vi3g, vi4g, vi5g, vi6g, vi7g, vi8g, 
	    vr1h;
    static complex hratio;
    static real cpsiph, stheta, vr2h, vr3h, hqwave;
    extern /* Subroutine */ int cmpinv_(real *, real *, real *, real *, 
	    integer *);
    static real vr4h, vr5h, thetaz, vr6h, vr7h, vr8h, vi1h, vi2h, vi3h, 
	    spsiph;
    extern /* Subroutine */ int mutual_(void);
    static real vi4h, vi5h, vi6h, vi7h, vi8h, e1r, e1i, e2r, e2i, e3r, e3i, 
	    e4r, e4i, e5r, e5i, e6r, e6i, e7r, e7i;
    static complex etheta1, etheta2;
    static real e8r, e8i, ethr, ethi, sp1m, sp2p, sm2m, sm1p, p1r, p1i, p2r, 
	    p2i, p3r, p3i, p4r, p4i, p5r, p5i, p6r, p6i, p7r, p7i, p8r, p8i, 
	    ephr, raine, spsiph2, cthetaz;

    /* Fortran I/O blocks */
    static cilist io___130 = { 0, 6, 0, fmt_276, 0 };
    static cilist io___317 = { 0, 6, 0, fmt_446, 0 };
    static cilist io___513 = { 0, 6, 0, fmt_636, 0 };



/*     GAIN - CALCULTES THE GAIN IN DECIBELS OF THE TRANSMITTING AND */
/*        RECEIVING ANTENNAS. */
/*     KOP       ANTENNA */
/*       1    TERMINATED RHOMBIC */
/*       2*   VERTICAL */
/*       3*   HORIZONTAL HALF-WAVE DIPOLE */
/*       4    HORIZONTAL YAGI */
/*       5    VERTICAL DIPOLE */
/*       6*   CURTAIN ARRAY WITH SCREEN */
/*       7    TERMINATED SLOPING VEE */
/*       8*   INVERTED L */
/*       9    TERMINATED SLOPING RHOMBIC */
/*      10    ANTENNA GAINS ARE IN THE PREVIOUSLY STORED ARRAY */
/*      11    SLOPING LONG WIRE */
/*      12    CONSTANT GAIN */
/*      13    HORIZONTAL LOG PERIODIC */
/*      14    ARBITRARY TILTED DIPOLE */
/*      15    HALF RHOMBIC */
/*      16    SLOPING DOUBLE RHOMBOID */
/*      17*   VERTICAL WITH A RADIAL CONDUCTOR GROUND SYSTEM */

/*        NOTE  THE ANTENNA NUMBERS, (KOP) WITH AN ASTERISK AFTER THEM */
/*        HAVE BEEN CHECKED AGAINST THE EQUATIONS IN MA AND WALTERS(1969) */
/*        AND WHERE NECESSARY BROUGHT INTO AGREEMENT WITH THAT REPORT */

/*        NOTE  FOR KAS .NE. 0, THE ARRAY IS FILLED AUTOMATICALLY (AS IN */
/*        METHOD=9) IN SUBROUTINE LUFFY IN ORDER TO */
/*        SAVE COMPUTATION TIME.  FOR KAS = 0, THEN, THIS ARRAY IS */
/*        INTERPOLATED ON TO OBTAIN THE GAIN AT A GIVEN FREQ AND ANGLE */


/*     ITR = 0 = CALCULATE GROUND REFLECTION LOSSES ONLY, */
/*         = 1 = TRANSMITTER ANTENNA GAIN CALCULATION */
/*         = 2 = RECEIVER ANTENNA GAIN CALCULATION */
/*     KAS = 0 = INTERPOLATE GAIN FROM ARRAY */
/*         = 1 = FIRST CALL FOR EACH FREQUENCY, SO CALCULATE THE */
/*               IMPEDANCES, CURRENTS, ETC., */
/*         .GT. 1 = NOT FIRST CALL OF FREQUENCY, SO SKIP CALCULATION */
/*                  OF IMPEDANCES, CURRENTS, ETC., */
/*     DELTA = TAKE-OFF ANGLE IN RADIANS, */
/*     FREQ = FREQUENCY IN MHZ., */
/*     RAIN = THE GAIN IN DB RETURNED TO THE CALLING ROUTINE, */
/*     EFF = THE ANTENNA EFFICIENCY IN DB RETURNED TO THE CALLING ROUTINE */
/*     THE OTHER ANTENNA PARAMETERS ARE COMMUNICATED TO GAIN VIA */
/*     PARAMETERS NTR, XFQB, XFQE, IANT, TOAZ, XQ, XP, XNH, XNL, XND, */
/*     AND TEX IN COMMON. */


/*     POWER GAIN OF ANTENNA AND GROUND REFLECTION LOSS. */

/*     SEE ITS-78, ESSA TECH REPORT ERL 104-ITS 74 (MA AND WALTERS, */
/*     APRIL 1969), AND ESSA TECH REPORT IER 54-ITSA 52 (MA AND WALTERS, */
/*     1967) FOR THE DETAILS OF SUBROUTINES GAIN, CZS1, ONEJ, COLL, */
/*     ECH, ZMUT, CIN, SIM, CMPINV, MATINV, SQMULT, MUTUAL, AGAUSS, */
/*     REACT, RESIST.  SEE ALSO ANY PARTICULAR REFERENCES GIVEN IN EACH. */
/* . . .SEE ALSO MA, M.T.(1974), THEORY AND APPLICATION OF ANTENNA ARRAYS */
/* . . .WILEY-INTERSCIENCE. THE MAIN REFERENCE IS MA AND WALTERS (1969). . */




/* cc      COMMON /AON /ARRAY (30, 91, 2), ITRP, ZANTP (3, 2), AEFF (30,2), */
/* cc     1 JA, JTR, J, MTR (2), JANT (20, 2), YNH (20, 2), YNL (20, 2), */
/* cc     2YND(20, 2),YETA (20, 2), TEY (4, 20, 2), YQ (20, 2), YP (20, 2), */
/* cc     3YFQB (20, 2), YFQE (20, 2) */

/* cc      COMMON /DON /ABI (24), ABIY (5, 24), ALATD, AMIN, AMIND, BRTD, BTR */
/* cc     1, BTRD, CLAT (5), CLCK (5, 24), CLONG (5), DLONG, DMP, EC (24), EM */
/* cc     2F (5, 24), ERTR, ESC (24), ESDL (24), ESDU (24), FC (24), FM (24), */
/* cc     3 FMM (5,24), FOES (5,24,3),SPDF (5,24), FOT (24), GCD, GCDKM, */
/* cc     4GEC (24), GLAT (5), GMA (5,24), GY (5,24), GYR (24), HO (24), */
/* cc     5HPFR (24), HY (5, 24), IANT (3, 2), IEA, IFQB, IFQE, IRCVR    , */
/* cc     6 ITRAN    , LUFP, NOISE, NTR (2), PMP, PMUF (10, 24), */
/* cc     7PWR, RD (5), RLAT, RLATD, RLONG, RLONGD, RSN, SIGTR, TEX (4, 3, 2) */
/* cc     8, TLAT, TLATD, TLONG, TLONGD, TOAZ (3, 2), XBTA (24), XETA (3, 2), */
/* cc     9 XFQB (3, 2), XFQE (3, 2), XLUF (24), XMUF (24), XND (3, 2), XNH ( */
/* cc     A3,2),XNL(3,2),XP(3,2),XQ(3,2),YM(24),ESMUF(24),ESHPF(24),ESBTA(24) */
/* cc     B,ESMODE */





/* cc      CHARACTER*8 ITRAN(2),IRCVR(2),ESMODE(24) */
/* cc      CHARACTER*16 ZANTP */

/*        48 POINT GAUSSIAN INTEGRATION - WEIGHTS AND ABSCISSAS */


/*            NOTE ALL EQUATION AND PAGE NUMBERS REFERRED TO BELOW ARE */
/*            FROM MA AND WALTERS(1969) UNLESS EXPLICITLY NOTED */
/*            OTHERWISE.                (J)= SQRT(-1). */


/* .....SET UP CONSTANTS AND PICK UP PARAMETERS........................... */
    /* Parameter adjustments */
    --tex;

    /* Function Body */

/* cc      DATA ARRAY/5460 * 0.0/,AEFF/60 * 0.0/ */

/* .....RINTW IS "RIN" FOR VERTICAL MONOPOLE AT H/LAMDA = .2 */
/* .....RINFR IS "RIN" FOR VERTICAL DIPOLE AT H/LAMDA = .4 */
/* .....XINTR = (4. - 1.) / (5. - 0.0001) */
/*     CHANGE (LENGTH/DIAMETER) RATIO FOR HALF-WAVE ANTENNA FROM 1000 */
/*     TO 4680. SEE MA (1974), TABLE 4.1, P. 254. */
    floor = -30.f;
/*  antenna gain floor value (was -10.) */
    rain_min__ = .001f;
    ratio = sqrtwo / 4680.f;
    deltd = *delta * con_1.r2d;
    beta = *toaz;
    sigma = *ysig;
    er = *yeps;
    h__ = *ynh;
    el = *ynl;
    phi = *ynd;
    for (ikex = 1; ikex <= 4; ++ikex) {
/* L110: */
	ex[ikex - 1] = tex[ikex];
    }
    if (*delta <= 0.f) {
	*rain = floor;
	*eff = 0.f;
	goto L630;
    }
    if (*kop == 12) {
	goto L475;
    }
/* .....CALCULATE WAVE=WAVELENGTH IN METERS AND SET EFFICIENCY=0DB */
    wave = con_1.vofl / *freq;
    *eff = 0.f;
/* .....CALCULATE SIN AND COS OF TAKE-OFF ANGLE (=90-ZENITH ANG.) */
    q = sin(*delta);
    t = cos(*delta);
/* .....DIF=COMPLEX DIELECTRIC CONSTANT=ER-(J)*18000*SIGMA/FREQ(MHZ) */
/*     SEE EQN.(11), P.6. */
    r__1 = sigma * -60.f * wave;
    q__1.r = er, q__1.i = r__1;
    dif.r = q__1.r, dif.i = q__1.i;
/* .....ACSQ=RATIO OF WAVE NUMBER IN MEDIA TO THAT IN FREE SPACE, */
/*     SEE EQN.(11), P. 6. */
/* Computing 2nd power */
    r__2 = t;
    r__1 = r__2 * r__2;
    q__2.r = dif.r - r__1, q__2.i = dif.i;
    c_sqrt(&q__1, &q__2);
    acsq.r = q__1.r, acsq.i = q__1.i;
/* .....CALCULATE COMPLEX FRESNEL REFLECTION COEFFICIENT FOR VERTICAL */
/*     (PERPENDICULAR) POLARIZATION(RV), EQN(9), P. 5. */
    q__3.r = q * dif.r, q__3.i = q * dif.i;
    q__2.r = q__3.r - acsq.r, q__2.i = q__3.i - acsq.i;
    q__5.r = q * dif.r, q__5.i = q * dif.i;
    q__4.r = q__5.r + acsq.r, q__4.i = q__5.i + acsq.i;
    c_div(&q__1, &q__2, &q__4);
    qper.r = q__1.r, qper.i = q__1.i;
    cv = c_abs(&qper);
    psiv = cang_(&qper);
/* .....CALCULATE COMPLEX FRESNEL REFLECTION COEFFICIENT FOR HORIZONTAL */
/*     (PARALLEL) POLARIZATION(RH), EQN(10), P. 5. */
    q__2.r = q - acsq.r, q__2.i = -acsq.i;
    q__3.r = q + acsq.r, q__3.i = acsq.i;
    c_div(&q__1, &q__2, &q__3);
    qpar.r = q__1.r, qpar.i = q__1.i;
    ch = c_abs(&qpar);
    psih = cang_(&qpar);
/* .....PUT PARAMETERS INTO WAVELENGTHS FOR ANTENNA GAIN CALCULATIONS..... */
    el1 = el / wave;
    if (el < 0.f) {
	el1 = dabs(el);
    }
    fac = con_1.pi * el1;
    fac2 = con_1.pi2 * el1;
    fac4 = fac2 * 2.f;
    x = h__ / wave;
    if (h__ < 0.f) {
	x = dabs(h__);
    }
    hwave = con_1.pi2 * x;
    hqwave = hwave * 2.f * q;
    rhi = phi * con_1.d2r;
    sr = sin(rhi);
    cr = cos(rhi);
    reta = beta * con_1.d2r;
    sb = sin(reta);
    cb = cos(reta);
/* ...ANTENNAS  1   2   3   4   5   6   7   8   9  10  11  12 13 14 15 16 17 =KOP */
    switch (*kop) {
	case 1:  goto L160;
	case 2:  goto L165;
	case 3:  goto L205;
	case 4:  goto L220;
	case 5:  goto L275;
	case 6:  goto L285;
	case 7:  goto L380;
	case 8:  goto L405;
	case 9:  goto L435;
	case 10:  goto L445;
	case 11:  goto L450;
	case 12:  goto L475;
	case 13:  goto L480;
	case 14:  goto L560;
	case 15:  goto L590;
	case 16:  goto L595;
	case 17:  goto L165;
    }
/* .....TERMINATED RHOMBIC ANTENNA, KOP=1................................. */
L160:
    tsc = 1.f - t * sr * cb;
    tcs = t * cr * sb;
    u1 = tsc - tcs;
    u2 = tsc + tcs;
    w1 = cos(psih - hqwave);
    w3 = cos(psiv - hqwave);
/* Computing 2nd power */
    r__1 = cr * sin(fac * u1) * sin(fac * u2) / (u1 * u2);
/* Computing 2nd power */
    r__2 = cb - sr * t;
/* Computing 2nd power */
    r__3 = ch;
/* Computing 2nd power */
    r__4 = sb;
/* Computing 2nd power */
    r__5 = cv;
/* Computing 2nd power */
    r__6 = q;
    *rain = r__1 * r__1 * 3.2f * (r__2 * r__2 * (r__3 * r__3 + 1.f + ch * 2.f 
	    * w1) + r__4 * r__4 * (r__5 * r__5 + 1.f - cv * 2.f * w3) * (r__6 
	    * r__6));
    *eff = -1.7f;
    goto L615;
/* .....VERTICAL ANTENNA, KOP=2........................................... */
L165:
    dmpio2 = (r__1 = *delta - con_1.pio2, dabs(r__1));
    *rain = 4e-5f;
    if (dmpio2 <= con_1.d2r * .5f) {
	goto L170;
    }
/* . . .CALCULATE A=A2,AS=B2,EQN.(30), P. 11 */
    sfac2 = sin(fac2);
    cfac2 = cos(fac2);
    hq = fac2 * q;
    a = cos(hq) - cfac2;
    as = sin(hq) - q * sfac2;
    if (*kas <= 1) {
/* . . .CALCULATE RIN, EQN.(33), P. 12 */
	flog = log(fac2);
	c2kel = cfac2 * 2.f * cfac2 - 1.f;
	s2kel = cfac2 * 2.f * sfac2;
	r__1 = fac2 * 4.f;
	csz1_(&q__1, &r__1);
	zt.r = q__1.r, zt.i = q__1.i;
/* . . .LN(2)=0.6931471806, LN(4)=1.3862943612 */
	rzero = (c2kel * (zt.r - flog - 1.3862943612f - con_1.gama) - s2kel * 
		r_imag(&zt)) * .5f;
	csz1_(&q__1, &fac4);
	zt.r = q__1.r, zt.i = q__1.i;
	q__1.r = -zt.r, q__1.i = -zt.i;
	rzero = (rzero + (c2kel + 1.f) * (q__1.r + flog + .6931471806f + 
		con_1.gama) + s2kel * r_imag(&zt)) * 30.f;
	rin = rzero;
	if (el1 < .2f) {
	    rin = el1 * 400.f * el1 * rintw / 16.f;
	}
	rzero = rin;
    }
/* .....FOR VERTICAL WITH GROUND SCREEN */
/* .....CALCULATE REST OF FACTORS PER PP 13-15 */
    if (*kop == 17) {
	goto L175;
    }
/* . . .CALCULATE GAIN USING EQNS. (29) AND (34), PP. 11-12 */
    w3 = cos(psiv);
    w4 = sin(psiv);
/* Computing 2nd power */
    r__1 = a * (cv * w3 + 1.f) + as * cv * w4;
/* Computing 2nd power */
    r__2 = a * cv * w4 + as * (1.f - cv * w3);
/* Computing 2nd power */
    r__3 = t;
    *rain = (r__1 * r__1 + r__2 * r__2) * 30.f / (rin * (r__3 * r__3));
    *rain = dmax(*rain,4e-5f);
L170:
    if (el1 >= .35f) {
	goto L615;
    }
    *eff = -((((el1 * 6416.702f - 6091.33f) * el1 + 2179.89f) * el1 - 
	    364.817f) * el1 + 25.646f);
    goto L615;
/* .....VERTICAL ANTENNA WITH A RADIAL CONDUCTOR GROUND SYSTEM, KOP=17.... */
L175:
    if (*kas <= 1) {
/*   . . .GET AA=LENGTH OF RADIALS IN WAVE LENGTHS */
	aa = phi / wave;
	if (phi < 0.f) {
	    aa = dabs(phi);
	}
/*   . . .CAYA=K*AA=WAVE NUMBER * LENGTH OF RADIALS */
	caya = con_1.pi2 * aa;
/*   . . .ETA FROM EQN. IN TEXT FOLLOWING EQN.(37), P. 13 */
/* Computing 2nd power */
	r__2 = con_1.pi;
	r__1 = r__2 * r__2 * 8.f * *freq * .1f;
	q__3.r = 0.f, q__3.i = r__1;
	r__3 = *freq * er * .001f / 18.f;
	q__4.r = sigma, q__4.i = r__3;
	c_div(&q__2, &q__3, &q__4);
	c_sqrt(&q__1, &q__2);
	eta.r = q__1.r, eta.i = q__1.i;
	alpha = cang_(&eta) + con_1.pio2;
/*   . . .LITTLE R0 AND LITTLE R1, P. 15 */
/* Computing 2nd power */
	r__1 = aa;
/* Computing 2nd power */
	r__2 = el1;
	rz = sqrt(r__1 * r__1 + r__2 * r__2);
	r1 = aa + rz;
	q__1.r = 0.f, q__1.i = con_1.pio2;
	ztr.r = q__1.r, ztr.i = q__1.i;
/*   . . .DELTAZ1, EQN.(39), P.14 */
	r__1 = con_1.pi2 * 2.f * (rz + el1);
	csz1_(&q__8, &r__1);
	q__7.r = q__8.r + ztr.r, q__7.i = q__8.i + ztr.i;
	q__9.r = c2kel, q__9.i = s2kel;
	q__6.r = q__7.r * q__9.r - q__7.i * q__9.i, q__6.i = q__7.r * q__9.i 
		+ q__7.i * q__9.r;
	r__2 = con_1.pi2 * 2.f * (rz - el1);
	csz1_(&q__12, &r__2);
	q__11.r = q__12.r + ztr.r, q__11.i = q__12.i + ztr.i;
	r__3 = -s2kel;
	q__13.r = c2kel, q__13.i = r__3;
	q__10.r = q__11.r * q__13.r - q__11.i * q__13.i, q__10.i = q__11.r * 
		q__13.i + q__11.i * q__13.r;
	q__5.r = q__6.r + q__10.r, q__5.i = q__6.i + q__10.i;
	r__4 = caya * 2.f;
	csz1_(&q__17, &r__4);
	q__16.r = q__17.r + ztr.r, q__16.i = q__17.i + ztr.i;
	q__15.r = q__16.r * 2.f, q__15.i = q__16.i * 2.f;
/* Computing 2nd power */
	r__6 = cfac2;
	r__5 = r__6 * r__6;
	q__14.r = r__5 * q__15.r, q__14.i = r__5 * q__15.i;
	q__4.r = q__5.r + q__14.r, q__4.i = q__5.i + q__14.i;
	r__7 = con_1.pi2 * r1;
	csz1_(&q__21, &r__7);
	q__20.r = q__21.r + ztr.r, q__20.i = q__21.i + ztr.i;
	q__19.r = q__20.r * 4.f, q__19.i = q__20.i * 4.f;
	q__18.r = cfac2 * q__19.r, q__18.i = cfac2 * q__19.i;
	q__3.r = q__4.r + q__18.r, q__3.i = q__4.i + q__18.i;
	r__8 = con_1.pi2 * (r1 - el1);
	csz1_(&q__26, &r__8);
	q__25.r = q__26.r + ztr.r, q__25.i = q__26.i + ztr.i;
	q__24.r = q__25.r * 4.f, q__24.i = q__25.i * 4.f;
	q__23.r = cfac2 * q__24.r, q__23.i = cfac2 * q__24.i;
	r__9 = -sfac2;
	q__27.r = cfac2, q__27.i = r__9;
	q__22.r = q__23.r * q__27.r - q__23.i * q__27.i, q__22.i = q__23.r * 
		q__27.i + q__23.i * q__27.r;
	q__2.r = q__3.r - q__22.r, q__2.i = q__3.i - q__22.i;
	r__10 = con_1.pi2 * (r1 + el1);
	csz1_(&q__32, &r__10);
	q__31.r = q__32.r + ztr.r, q__31.i = q__32.i + ztr.i;
	q__30.r = q__31.r * 4.f, q__30.i = q__31.i * 4.f;
	q__29.r = cfac2 * q__30.r, q__29.i = cfac2 * q__30.i;
	q__33.r = cfac2, q__33.i = sfac2;
	q__28.r = q__29.r * q__33.r - q__29.i * q__33.i, q__28.i = q__29.r * 
		q__33.i + q__29.i * q__33.r;
	q__1.r = q__2.r - q__28.r, q__1.i = q__2.i - q__28.i;
	delz.r = q__1.r, delz.i = q__1.i;
	q__2.r = delz.r * eta.r - delz.i * eta.i, q__2.i = delz.r * eta.i + 
		delz.i * eta.r;
	r__1 = con_1.pi2 * 2.f;
	q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
	delr1 = q__1.r;
	eta1 = eta.r;
	eta2 = r_imag(&eta);
/*   . . .DELTAZ2, EQN.(40), P. 15 */
	delr2 = 0.f;
	dp = aa / 2.f;
/* Computing 2nd power */
	r__1 = con_1.pi;
	qu = r__1 * r__1 * 240.f / ex[1];
	cw = wave * 1e3f / (ex[0] * ex[1]);
	for (j = 1; j <= 48; ++j) {
	    p = dp * (waits_1.xi[j - 1] + 1.f);
/* Computing 2nd power */
	    r__1 = p;
/* Computing 2nd power */
	    r__2 = el1;
	    rq = con_1.pi2 * sqrt(r__1 * r__1 + r__2 * r__2);
	    plog = log(p * cw);
	    qq = qu * p * plog;
	    eq = eta2 + qq;
	    ta = atan2(eq, eta1);
/* L180: */
/* Computing 2nd power */
	    r__1 = cfac2;
/* Computing 2nd power */
	    r__2 = eta1;
/* Computing 2nd power */
	    r__3 = eq;
	    delr2 += (cos(alpha - ta - rq * 2.f) + r__1 * r__1 * cos(alpha - 
		    ta - con_1.pi * 4.f * p) - cfac2 * 2.f * cos(alpha - ta - 
		    con_1.pi2 * p - rq)) / sqrt(r__2 * r__2 + r__3 * r__3) * 
		    plog * dp * waits_1.hh[j - 1];
	}
	delr2 = con_1.pi * -120.f * c_abs(&eta) / ex[1] * delr2;
/*   . . .RIN, EQN.(38), P. 14 */
	rin = rzero + delr1 + delr2;
    }
/* . . .HRATIO=A3+(J)*B3, EQN.(36), P. 13 */
    hratio.r = 0.f, hratio.i = 0.f;
    for (j = 1; j <= 48; ++j) {
	xx = caya / 2.f * (waits_1.xi[j - 1] + 1.f);
/* Computing 2nd power */
	r__1 = xx;
/* Computing 2nd power */
	r__2 = fac2;
	td = sqrt(r__1 * r__1 + r__2 * r__2);
	r__1 = xx * t;
	ts = onej_(&r__1);
/* L190: */
	r__1 = waits_1.hh[j - 1] * ts;
	r__2 = cos(td) - cos(xx) * cfac2;
	r__3 = -sin(td) + sin(xx) * cfac2;
	q__3.r = r__2, q__3.i = r__3;
	q__2.r = r__1 * q__3.r, q__2.i = r__1 * q__3.i;
	q__1.r = hratio.r + q__2.r, q__1.i = hratio.i + q__2.i;
	hratio.r = q__1.r, hratio.i = q__1.i;
    }
    q__5.r = caya * hratio.r, q__5.i = caya * hratio.i;
    q__4.r = q__5.r * eta.r - q__5.i * eta.i, q__4.i = q__5.r * eta.i + 
	    q__5.i * eta.r;
    q__3.r = t * q__4.r, q__3.i = t * q__4.i;
    r__1 = con_1.pi2 * 120.f * a;
    q__2.r = q__3.r / r__1, q__2.i = q__3.i / r__1;
    q__1.r = 1.f - q__2.r, q__1.i = -q__2.i;
    hratio.r = q__1.r, hratio.i = q__1.i;
    *rain = 0.f;
    if ((r__1 = hratio.r, dabs(r__1)) > 2.f || (r__2 = r_imag(&hratio), dabs(
	    r__2)) > 1.f) {
	goto L195;
    }
/* . . .GAIN FROM EQN.(41), P. 15 */
    bp = atan2(as, a);
/* Computing 2nd power */
    r__1 = cv;
    cayvh = r__1 * r__1 + 1.f + cv * 2.f * cos(psiv - bp * 2.f);
    tb = a / (t * cos(bp));
/* Computing 2nd power */
    r__2 = tb;
    r__1 = 30.f / rin * (r__2 * r__2) * cayvh;
    q__2.r = r__1 * hratio.r, q__2.i = r__1 * hratio.i;
    r_cnjg(&q__3, &hratio);
    q__1.r = q__2.r * q__3.r - q__2.i * q__3.i, q__1.i = q__2.r * q__3.i + 
	    q__2.i * q__3.r;
    *rain = q__1.r;
L195:
    if (el1 >= .35f) {
	goto L615;
    }
    *eff = -((((el1 * 6416.702f - 6091.33f) * el1 + 2179.89f) * el1 - 
	    364.817f) * el1 + 25.646f);
    goto L615;
/* .....HORIZONTAL HALFWAVE DIPOLE ANTENNA, KOP=3......................... */
/* . . .NOTE--THIS MODEL IS NOT VALID FOR ANTENNAS LESS THAN .15 */
/* . . .WAVELENGHTHS FROM THE GROUND. */
L205:
    sfac = sin(fac);
    mut_1.cfac = cos(fac);
    w1 = cos(psih - hqwave);
    w2 = sin(psih - hqwave);
    w3 = cos(psiv - hqwave);
    w4 = sin(psiv - hqwave);
    cphi = t * sb;
/* Computing 2nd power */
    r__1 = cphi;
    sphi2 = 1.f - r__1 * r__1;
    *rain = 0.f;
    if (sphi2 == 0.f) {
	goto L615;
    }
    gi = (cos(fac * cphi) - mut_1.cfac) / sphi2;
    aa = sqrt(cv * cv + 1.f - cv * 2.f * w3) * gi;
    bb = sqrt(ch * ch + 1.f + ch * 2.f * w1) * gi;
    if (*kas <= 1) {
/*   . . .CALCULATE RIN, EQNS. (27),(26),(25), PP. 9-10 */
	hfmufes_one__1.d1d[0] = hwave * 2.f;
	hfmufes_one__1.d1d[1] = ratio * fac;
	sfac2 = sin(fac2);
	cfac2 = cos(fac2);
	for (j = 1; j <= 2; ++j) {
/* Computing 2nd power */
	    r__1 = hfmufes_one__1.d1d[j - 1];
/* Computing 2nd power */
	    r__2 = fac2;
	    tt = sqrt(r__1 * r__1 + r__2 * r__2);
	    uz = tt - fac2;
	    vz = tt + fac2;
/* Computing 2nd power */
	    r__1 = hfmufes_one__1.d1d[j - 1];
/* Computing 2nd power */
	    r__2 = fac;
	    tt = sqrt(r__1 * r__1 + r__2 * r__2);
	    u1 = tt - fac;
	    v1 = tt + fac;
	    i__1 = j - 1;
	    csz1_(&q__6, &uz);
	    csz1_(&q__8, &u1);
	    q__7.r = q__8.r * 2.f, q__7.i = q__8.i * 2.f;
	    q__5.r = q__6.r - q__7.r, q__5.i = q__6.i - q__7.i;
	    r__1 = -sfac2;
	    q__9.r = cfac2, q__9.i = r__1;
	    q__4.r = q__5.r * q__9.r - q__5.i * q__9.i, q__4.i = q__5.r * 
		    q__9.i + q__5.i * q__9.r;
	    csz1_(&q__12, &vz);
	    csz1_(&q__14, &v1);
	    q__13.r = q__14.r * 2.f, q__13.i = q__14.i * 2.f;
	    q__11.r = q__12.r - q__13.r, q__11.i = q__12.i - q__13.i;
	    q__15.r = cfac2, q__15.i = sfac2;
	    q__10.r = q__11.r * q__15.r - q__11.i * q__15.i, q__10.i = 
		    q__11.r * q__15.i + q__11.i * q__15.r;
	    q__3.r = q__4.r + q__10.r, q__3.i = q__4.i + q__10.i;
	    csz1_(&q__18, &u1);
	    csz1_(&q__19, &v1);
	    q__17.r = q__18.r + q__19.r, q__17.i = q__18.i + q__19.i;
	    q__16.r = q__17.r * 2.f, q__16.i = q__17.i * 2.f;
	    q__2.r = q__3.r - q__16.r, q__2.i = q__3.i - q__16.i;
	    csz1_(&q__22, &hfmufes_one__1.d1d[j - 1]);
	    q__21.r = q__22.r * 2.f, q__21.i = q__22.i * 2.f;
	    r__2 = cfac2 + 2.f;
	    q__20.r = r__2 * q__21.r, q__20.i = r__2 * q__21.i;
	    q__1.r = q__2.r + q__20.r, q__1.i = q__2.i + q__20.i;
	    z__[i__1].r = q__1.r, z__[i__1].i = q__1.i;
/* L210: */
	    i__1 = j - 1;
	    i__2 = j - 1;
	    q__2.r = z__[i__2].r * 60.f, q__2.i = z__[i__2].i * 60.f;
	    r__1 = 1.f - cfac2;
	    q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
	    z__[i__1].r = q__1.r, z__[i__1].i = q__1.i;
	}
	c_sqrt(&q__1, &dif);
	sqrd.r = q__1.r, sqrd.i = q__1.i;
	q__3.r = 1.f - sqrd.r, q__3.i = -sqrd.i;
	q__4.r = sqrd.r + 1.f, q__4.i = sqrd.i;
	c_div(&q__2, &q__3, &q__4);
	q__1.r = z__[0].r * q__2.r - z__[0].i * q__2.i, q__1.i = z__[0].r * 
		q__2.i + z__[0].i * q__2.r;
	cxc = q__1.r;
	rin = z__[1].r + cxc;
    }
/* . . .GAIN= EQN.(28), P. 10 */
    *rain = (aa * aa * sb * sb * q * q + bb * bb * cb * cb) * 120.f / (rin * 
	    sfac * sfac);
    goto L615;
/* .....HORIZONTAL YAGI ANTENNA, KOP=4.................................... */
L220:
    *rain = 0.f;
    if (el1 < .25f || el1 > .75f) {
	goto L615;
    }
    w1 = ch * cos(psih - hqwave);
    w2 = ch * sin(psih - hqwave);
    w3 = cv * cos(psiv - hqwave);
    w4 = cv * sin(psiv - hqwave);
    n = ex[1];
    nm1 = n - 1;
    nm2 = n - 2;
    d__[nm1 - 1] = ex[3] / wave;
    if (ex[3] < 0.f) {
	d__[nm1 - 1] = dabs(ex[3]);
    }
    d__[0] = ex[2] / wave;
    if (ex[2] < 0.f) {
	d__[0] = dabs(ex[2]);
    }
    hfmufes_one__1.ell[n - 1] = con_1.pi * phi / wave;
    if (phi < 0.f) {
	hfmufes_one__1.ell[n - 1] = con_1.pi * dabs(phi);
    }
    hfmufes_one__1.ell[nm1 - 1] = fac;
    hfmufes_one__1.ell[0] = con_1.pi * ex[0] / wave;
    if (ex[0] < 0.f) {
	hfmufes_one__1.ell[0] = con_1.pi * dabs(ex[0]);
    }
    xk[0] = 0.f;
    if (n == 3) {
	goto L230;
    }
    if (nm2 < 2) {
	goto L670;
    }
    i__1 = nm2;
    for (j = 2; j <= i__1; ++j) {
	hfmufes_one__1.ell[j - 1] = hfmufes_one__1.ell[0];
/* L225: */
	d__[j - 1] = d__[0];
    }
L670:
L230:
    if (n < 2) {
	goto L675;
    }
    i__1 = n;
    for (j = 2; j <= i__1; ++j) {
/* L235: */
	xk[j - 1] = xk[j - 2] + d__[j - 2];
    }
L675:
    if (*kas > 1) {
	goto L265;
    }
/*     CALL TO CIN ELIMINATED - CODE INCORPORATED BELOW */
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	hfmufes_one__1.no = i__;
	hfmufes_one__1.nmx = i__;
	i__2 = hfmufes_one__1.no;
	for (k = 1; k <= i__2; ++k) {
	    hfmufes_one__1.d1d[k - 1] = con_1.pi2 * (r__1 = xk[i__ - 1] - xk[
		    k - 1], dabs(r__1));
	    if (i__ == k) {
		hfmufes_one__1.d1d[k - 1] = hfmufes_one__1.ell[i__ - 1] / 
			125.1579f;
	    }
/* L240: */
	}
	sim_();
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    i__3 = j - 1;
	    yr[hfmufes_one__1.nmx + j * 20 - 21] = hfmufes_one__1.zs[i__3].r;
	    yr[j + hfmufes_one__1.nmx * 20 - 21] = yr[hfmufes_one__1.nmx + j *
		     20 - 21];
	    yi[hfmufes_one__1.nmx + j * 20 - 21] = r_imag(&hfmufes_one__1.zs[
		    j - 1]);
	    yi[j + hfmufes_one__1.nmx * 20 - 21] = yi[hfmufes_one__1.nmx + j *
		     20 - 21];
/* L245: */
	}
    }
    cmpinv_(yr, yi, tx, ty, &n);
    i__2 = n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	cix[i__ - 1] = tx[i__ + nm1 * 20 - 21];
/* L250: */
	ciy[i__ - 1] = ty[i__ + nm1 * 20 - 21];
    }
    i__2 = nm1 - 1;
    i__1 = nm1 - 1;
    q__2.r = cix[i__2], q__2.i = ciy[i__1];
    c_div(&q__1, &c_b37, &q__2);
    v.r = q__1.r, v.i = q__1.i;
    sum1 = v.r;
/* Computing 2nd power */
    r__1 = x;
    tt = r__1 * r__1 * 4.f;
    i__2 = nm1;
    for (j = 1; j <= i__2; ++j) {
/* Computing 2nd power */
	i__1 = nm1 - j;
	tx1 = (real) (i__1 * i__1);
/* Computing 2nd power */
	r__1 = d__[j - 1];
	hfmufes_one__1.d1d[j - 1] = con_1.pi2 * sqrt(tt + tx1 * (r__1 * r__1))
		;
/* L255: */
    }
/* Computing 2nd power */
    r__1 = d__[nm1 - 1];
    hfmufes_one__1.d1d[n - 1] = con_1.pi2 * sqrt(tt + r__1 * r__1);
    hfmufes_one__1.nmx = nm1;
    hfmufes_one__1.no = n;
    sim_();
    v.r = 0.f, v.i = 0.f;
    i__2 = n;
    for (j = 1; j <= i__2; ++j) {
/* L260: */
	i__1 = j - 1;
	i__3 = j - 1;
	q__3.r = cix[i__1], q__3.i = ciy[i__3];
	i__4 = j - 1;
	q__2.r = q__3.r * hfmufes_one__1.zs[i__4].r - q__3.i * 
		hfmufes_one__1.zs[i__4].i, q__2.i = q__3.r * 
		hfmufes_one__1.zs[i__4].i + q__3.i * hfmufes_one__1.zs[i__4]
		.r;
	q__1.r = v.r + q__2.r, q__1.i = v.i + q__2.i;
	v.r = q__1.r, v.i = q__1.i;
    }
    c_sqrt(&q__1, &dif);
    sqrd.r = q__1.r, sqrd.i = q__1.i;
    q__4.r = 1.f - sqrd.r, q__4.i = -sqrd.i;
    q__3.r = v.r * q__4.r - v.i * q__4.i, q__3.i = v.r * q__4.i + v.i * 
	    q__4.r;
    q__5.r = sqrd.r + 1.f, q__5.i = sqrd.i;
    c_div(&q__2, &q__3, &q__5);
    i__1 = nm1 - 1;
    i__3 = nm1 - 1;
    q__6.r = cix[i__1], q__6.i = ciy[i__3];
    c_div(&q__1, &q__2, &q__6);
    sum2 = q__1.r;
    rin = sum1 + sum2;
L265:
    cpsi = t * sb;
/* Computing 2nd power */
    r__1 = cpsi;
    spsi2 = 1.f - r__1 * r__1;
    *rain = 0.f;
    if (spsi2 == 0.f) {
	goto L615;
    }
    etr = 0.f;
    eti = 0.f;
    pr = -cb * con_1.pi2 * t;
    if (n < 1) {
	goto L710;
    }
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	ctk = cos(pr * xk[j - 1]);
	stk = sin(pr * xk[j - 1]);
	sis = 1.f / sin(hfmufes_one__1.ell[j - 1]);
/* Computing 2nd power */
	r__1 = sis;
	tt = r__1 * r__1 * (cos(hfmufes_one__1.ell[j - 1] * cpsi) - cos(
		hfmufes_one__1.ell[j - 1]));
	etr += tt * (cix[j - 1] * ctk - ciy[j - 1] * stk);
	eti += tt * (cix[j - 1] * stk + ciy[j - 1] * ctk);
/* L270: */
    }
L710:
/* Computing 2nd power */
    r__1 = cb;
/* Computing 2nd power */
    r__2 = etr * (w1 + 1.f) - eti * w2;
/* Computing 2nd power */
    r__3 = eti * (w1 + 1.f) + etr * w2;
    epmag = r__1 * r__1 * (r__2 * r__2 + r__3 * r__3);
/* Computing 2nd power */
    r__1 = sb;
/* Computing 2nd power */
    r__2 = q;
/* Computing 2nd power */
    r__3 = etr * (1.f - w3) + eti * w4;
/* Computing 2nd power */
    r__4 = eti * (1.f - w3) - etr * w4;
    etmag = r__1 * r__1 * (r__2 * r__2) * (r__3 * r__3 + r__4 * r__4);
/* Computing 2nd power */
    r__1 = spsi2;
    *rain = rin * 120.f * (etmag + epmag) / (r__1 * r__1);
    goto L615;
/* .....VERTICAL DIPOLE ANTENNA, KOP=5.................................... */
L275:
    tip = el1 * .5f;
/* cc      IF (TIP .GT. X) GO TO 635 */
    if (tip > x) {
/*  antenna not physically valid */
	s_wsfe(&io___130);
	do_fio(&c__1, (char *)&h__, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&el, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&wave, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&(*freq), (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&el1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&tip, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&x, (ftnlen)sizeof(real));
	e_wsfe();
	*rain = floor;
	return 0;
    }
    mut_1.cfac = cos(fac);
/* Computing 2nd power */
    r__1 = q;
    sphi2 = 1.f - r__1 * r__1;
    *rain = 0.f;
    if (sphi2 == 0.f) {
	goto L615;
    }
    gi = (cos(fac * q) - mut_1.cfac) / sphi2;
    w3 = cos(psiv - hqwave);
    eteta1 = -t * gi * (cv * w3 + 1.f);
    w4 = sin(psiv - hqwave);
    eteta2 = -t * gi * cv * w4;
    hac2 = hwave + hwave;
    hac4 = hac2 + hac2;
    csz1_(&q__1, &hac2);
    azh.r = q__1.r, azh.i = q__1.i;
    w33 = azh.r;
    w4 = -r_imag(&azh);
    csz1_(&q__1, &hac4);
    azh.r = q__1.r, azh.i = q__1.i;
    w5 = azh.r;
    w6 = -r_imag(&azh);
    rin = ((cos(hac2) + 1.f) * (con_1.gama + log(hac2) - w33) - cos(hac2) * 
	    .5f * (con_1.gama + log(hac4) - w5) + sin(hac2) * (w6 * .5f - w4))
	     * 60.f;
    if (el1 - .4f >= 0.f) {
	goto L279;
    } else {
	goto L278;
    }
L278:
    rin = el1 * 800.f * el1 * rinfr / 128.f;
L279:
    fmult = 4.f - xintr * (sigma - 1e-4f);
    rin = fmult * 128.f * rin / rinfr;
/* Computing 2nd power */
    r__1 = eteta1;
/* Computing 2nd power */
    r__2 = eteta2;
    *rain = (r__1 * r__1 + r__2 * r__2) * 120.f / rin;
    goto L615;
/* .....CURTAIN ANTENNA ARRAY WITH PERFECTLY CONDUCTING SCREEN, KOP=6..... */
L285:
    if (beta < 90.f || beta > 270.f) {
	goto L286;
    }
    *rain = .05f;
    goto L615;
L286:
    thetaz = 90.f;
    deltap = 0.f;
    cur_1.eil = el1 * .5f;
    nb = dabs(phi);
    nbb = (r__1 = (dabs(phi) - nb) * 100.f, dabs(r__1)) + .5f;
/* . . .THE BAYS ARE FED IN ANTI-PHASE(MOD NBB) IF PHI NON-INTEGER . . . . */
    cbay = 1.f;
    if (nbb != 0) {
	cbay = -1.f;
    }
    if (nbb == 0) {
	nbb = 1;
    }
    ne = dabs(ex[0]);
    nee = (r__1 = (dabs(ex[0]) - ne) * 100.f, dabs(r__1)) + .5f;
/* . . .THE ELTS ARE FED IN ANTI-PHASE(MOD NEE) IF EX(1) IS NON-INTEGER. . */
    cele = 1.f;
    if (nee != 0) {
	cele = -1.f;
    }
    if (nee == 0) {
	nee = 1;
    }
    dy = ex[1] / wave;
    if (ex[1] < 0.f) {
	dy = dabs(ex[1]);
    }
    dz = ex[2] / wave;
    if (ex[2] < 0.f) {
	dz = dabs(ex[2]);
    }
    dx = ex[3] / wave;
    if (ex[3] < 0.f) {
	dx = dabs(ex[3]);
    }
    if (*kas > 1) {
	goto L355;
    }
/* . . .CALCULATE ALL SELF- AND MUTUAL-IMPEDANCES */
    cur_1.dij = cur_1.eil * .01767766952f;
    cur_1.hij = cur_1.eil;
    cur_1.kode = 1;
    zmut_(&rzz);
/* . . .SEE MA(1974),TABLE 4.1, P. 254, AND EQN.(4.114), P. 273 */
    if (rzz.r < 3631.53f) {
	goto L290;
    }
    rzz.r = 3631.53f, rzz.i = -2356.47f;
    cur_1.kode = -1;
    rin = (real) (nb * ne) * 3631.53f;
    goto L355;
L290:
    cur_1.dij = dx * 2.f;
    zmut_(&rpzz);
    i__1 = ne;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ci = (real) i__;
	tt = (ci - 1.f) * dz + x;
	cur_1.dij = tt * 2.f;
	zmut_(&rdzz[i__ - 1]);
/* Computing 2nd power */
	r__1 = dx;
/* Computing 2nd power */
	r__2 = tt;
	cur_1.dij = sqrt(r__1 * r__1 + r__2 * r__2) * 2.f;
/* L295: */
	zmut_(&rtzz[i__ - 1]);
    }
/* Computing 2nd power */
    r__1 = dx * 2.f;
    ts = r__1 * r__1;
    ijend = ne - 1;
    i__1 = ijend;
    for (ij = 1; ij <= i__1; ++ij) {
	cij = (real) ij;
	cur_1.dij = cij * dz;
	zmut_(&rzb[ij - 1]);
/* Computing 2nd power */
	r__1 = cij;
/* Computing 2nd power */
	r__2 = dz;
	cur_1.dij = sqrt(ts + r__1 * r__1 * (r__2 * r__2));
/* L300: */
	zmut_(&rpzb[ij - 1]);
    }
    ipjend = ne << 1;
    i__1 = ipjend;
    for (ipj = 2; ipj <= i__1; ++ipj) {
	cipj = (real) ipj;
	tt = (cipj - 2.f) * dz + x * 2.f;
	cur_1.dij = tt;
	zmut_(&rdzb[ipj - 1]);
/* Computing 2nd power */
	r__1 = tt;
	cur_1.dij = sqrt(ts + r__1 * r__1);
/* L305: */
	zmut_(&rtzb[ipj - 1]);
    }
    mnend = nb - 1;
    i__1 = mnend;
    for (mn = 1; mn <= i__1; ++mn) {
	cmn = (real) mn;
	cur_1.hij = cmn * dy - cur_1.eil;
	coll_(&rze[mn - 1]);
	cur_1.dij = dx * 2.f;
	ech_(&rpze[mn - 1]);
	i__3 = ne;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    ci = (real) i__;
	    tt = ((ci - 1.f) * dz + x) * 2.f;
	    cur_1.dij = tt;
	    ech_(&rdze[mn + i__ * 5 - 6]);
/* Computing 2nd power */
	    r__1 = tt;
	    cur_1.dij = sqrt(ts + r__1 * r__1);
/* L310: */
	    ech_(&rtze[mn + i__ * 5 - 6]);
	}
	i__3 = ijend;
	for (ij = 1; ij <= i__3; ++ij) {
	    cij = (real) ij;
	    cur_1.dij = cij * dz;
	    ech_(&r__[mn + ij * 5 - 6]);
/* Computing 2nd power */
	    r__1 = cij;
/* Computing 2nd power */
	    r__2 = dz;
	    cur_1.dij = sqrt(ts + r__1 * r__1 * (r__2 * r__2));
/* L315: */
	    ech_(&rp[mn + ij * 5 - 6]);
	}
	i__3 = ipjend;
	for (ipj = 2; ipj <= i__3; ++ipj) {
	    cipj = (real) ipj;
	    tt = (cipj - 2.f) * dz + x * 2.f;
	    cur_1.dij = tt;
	    ech_(&rdz[mn + ipj * 5 - 6]);
/* Computing 2nd power */
	    r__1 = tt;
	    cur_1.dij = sqrt(ts + r__1 * r__1);
/* L320: */
	    ech_(&rt[mn + ipj * 5 - 6]);
	}
/* L325: */
    }
/* . . .SUM ALL SELF-AND MUTUAL-IMPEDANCES FOR ALL REAL-REAL AND REAL-. . */
/* . . .IMAGE ELEMENT PAIRS . . . . . . . . . . . . . . . . . . . . ... . */
    zsum1.r = 0.f, zsum1.i = 0.f;
    zsum2.r = 0.f, zsum2.i = 0.f;
    zsum3.r = 0.f, zsum3.i = 0.f;
    zsum4.r = 0.f, zsum4.i = 0.f;
    i__1 = nb;
    for (m = 1; m <= i__1; ++m) {
	i__3 = ne;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__4 = nb;
	    for (n = 1; n <= i__4; ++n) {
		i__2 = ne;
		for (j = 1; j <= i__2; ++j) {
		    if (m != n || i__ != j) {
			goto L330;
		    }
		    zterm1.r = rzz.r, zterm1.i = rzz.i;
		    zterm2.r = rpzz.r, zterm2.i = rpzz.i;
		    i__5 = i__ - 1;
		    zterm3.r = rdzz[i__5].r, zterm3.i = rdzz[i__5].i;
		    i__5 = i__ - 1;
		    zterm4.r = rtzz[i__5].r, zterm4.i = rtzz[i__5].i;
		    goto L345;
L330:
		    if (m != n) {
			goto L335;
		    }
		    ij = (i__5 = i__ - j, abs(i__5));
		    i__5 = ij - 1;
		    zterm1.r = rzb[i__5].r, zterm1.i = rzb[i__5].i;
		    i__5 = ij - 1;
		    zterm2.r = rpzb[i__5].r, zterm2.i = rpzb[i__5].i;
		    i__5 = i__ + j - 1;
		    zterm3.r = rdzb[i__5].r, zterm3.i = rdzb[i__5].i;
		    i__5 = i__ + j - 1;
		    zterm4.r = rtzb[i__5].r, zterm4.i = rtzb[i__5].i;
		    goto L345;
L335:
		    if (i__ != j) {
			goto L340;
		    }
		    mn = (i__5 = m - n, abs(i__5));
		    i__5 = mn - 1;
		    zterm1.r = rze[i__5].r, zterm1.i = rze[i__5].i;
		    i__5 = mn - 1;
		    zterm2.r = rpze[i__5].r, zterm2.i = rpze[i__5].i;
		    i__5 = mn + i__ * 5 - 6;
		    zterm3.r = rdze[i__5].r, zterm3.i = rdze[i__5].i;
		    i__5 = mn + i__ * 5 - 6;
		    zterm4.r = rtze[i__5].r, zterm4.i = rtze[i__5].i;
		    goto L345;
L340:
		    mn = (i__5 = m - n, abs(i__5));
		    ij = (i__5 = i__ - j, abs(i__5));
		    i__5 = mn + ij * 5 - 6;
		    zterm1.r = r__[i__5].r, zterm1.i = r__[i__5].i;
		    i__5 = mn + ij * 5 - 6;
		    zterm2.r = rp[i__5].r, zterm2.i = rp[i__5].i;
		    i__5 = mn + (i__ + j) * 5 - 6;
		    zterm3.r = rdz[i__5].r, zterm3.i = rdz[i__5].i;
		    i__5 = mn + (i__ + j) * 5 - 6;
		    zterm4.r = rt[i__5].r, zterm4.i = rt[i__5].i;
L345:
		    q__1.r = zsum1.r + zterm1.r, q__1.i = zsum1.i + zterm1.i;
		    zsum1.r = q__1.r, zsum1.i = q__1.i;
		    q__1.r = zsum2.r + zterm2.r, q__1.i = zsum2.i + zterm2.i;
		    zsum2.r = q__1.r, zsum2.i = q__1.i;
		    q__1.r = zsum3.r + zterm3.r, q__1.i = zsum3.i + zterm3.i;
		    zsum3.r = q__1.r, zsum3.i = q__1.i;
		    q__1.r = zsum4.r + zterm4.r, q__1.i = zsum4.i + zterm4.i;
		    zsum4.r = q__1.r, zsum4.i = q__1.i;
/* L350: */
		}
	    }
	}
    }
/* . . .CALCULATE THE INPUT IMPEDANCE RIN. . . . . . . . . . . . . . . . . */
    c_sqrt(&q__1, &dif);
    sqrd.r = q__1.r, sqrd.i = q__1.i;
    q__2.r = 1.f - sqrd.r, q__2.i = -sqrd.i;
    q__3.r = sqrd.r + 1.f, q__3.i = sqrd.i;
    c_div(&q__1, &q__2, &q__3);
    rhcp.r = q__1.r, rhcp.i = q__1.i;
    q__2.r = zsum1.r - zsum2.r, q__2.i = zsum1.i - zsum2.i;
    q__4.r = zsum3.r - zsum4.r, q__4.i = zsum3.i - zsum4.i;
    q__3.r = rhcp.r * q__4.r - rhcp.i * q__4.i, q__3.i = rhcp.r * q__4.i + 
	    rhcp.i * q__4.r;
    q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
    rin = q__1.r;
/* . . .CALCULATE THE ELEMENT ARRAYING FACTOR (SIN(THETA)=SIN(90-DELTA)= */
/* . . .COS(DELTA)). . . . . . . . . . . . . .. . . . . . . . . . . . . . */
L355:
    stheta = cos(*delta);
    cpsi = stheta * sb;
    azv.r = 0.f, azv.i = 0.f;
    azh.r = 0.f, azh.i = 0.f;
    cthetaz = cos(thetaz * con_1.d2r);
    sbz = sin(deltap * con_1.d2r);
    factor = cele;
    i__2 = ne;
    for (m = 1; m <= i__2; ++m) {
	em = (real) m;
	r__1 = x + (em - 1.f) * dz;
	zm.r = r__1, zm.i = 0.f;
/* . . .IF ANTI-PHASE, GROUP IN NEE-TUPLES,E.G.,++,--,++,ETC FOR NEE=2 . . */
	if (m % nee == 1 || nee == 1) {
	    factor *= cele;
	}
	q__2.r = con_1.pi2 * zm.r, q__2.i = con_1.pi2 * zm.i;
	r__1 = q - cthetaz;
	q__1.r = r__1 * q__2.r, q__1.i = r__1 * q__2.i;
	tt = q__1.r;
	r__1 = cos(tt);
	r__2 = sin(tt);
	q__1.r = r__1, q__1.i = r__2;
	zt.r = q__1.r, zt.i = q__1.i;
	r__1 = con_1.pi2 * 2.f;
	q__2.r = r__1 * zm.r, q__2.i = r__1 * zm.i;
	q__1.r = q * q__2.r, q__1.i = q * q__2.i;
	tt = q__1.r;
	r__1 = cos(tt);
	r__2 = -sin(tt);
	q__1.r = r__1, q__1.i = r__2;
	ztr.r = q__1.r, ztr.i = q__1.i;
	q__5.r = qper.r * ztr.r - qper.i * ztr.i, q__5.i = qper.r * ztr.i + 
		qper.i * ztr.r;
	q__4.r = 1.f - q__5.r, q__4.i = -q__5.i;
	q__3.r = zt.r * q__4.r - zt.i * q__4.i, q__3.i = zt.r * q__4.i + zt.i 
		* q__4.r;
	q__2.r = factor * q__3.r, q__2.i = factor * q__3.i;
	q__1.r = azv.r + q__2.r, q__1.i = azv.i + q__2.i;
	azv.r = q__1.r, azv.i = q__1.i;
/* L360: */
	q__5.r = qpar.r * ztr.r - qpar.i * ztr.i, q__5.i = qpar.r * ztr.i + 
		qpar.i * ztr.r;
	q__4.r = q__5.r + 1.f, q__4.i = q__5.i;
	q__3.r = zt.r * q__4.r - zt.i * q__4.i, q__3.i = zt.r * q__4.i + zt.i 
		* q__4.r;
	q__2.r = factor * q__3.r, q__2.i = factor * q__3.i;
	q__1.r = azh.r + q__2.r, q__1.i = azh.i + q__2.i;
	azh.r = q__1.r, azh.i = q__1.i;
    }
/* . . .CALCULATE THE BAY ARRAYING FACTOR . . . . . . . . . . . . . . . . */
    af.r = 1.f, af.i = 0.f;
    if (nb <= 1) {
	goto L370;
    }
    af.r = 0.f, af.i = 0.f;
    factor = cbay;
    i__2 = nb;
    for (n = 1; n <= i__2; ++n) {
	en = (real) n;
/* . . .IF ANTI-PHASE, GROUP IN NBB-TUPLES,E.G.,++,--,++,ETC FOR NBB=2 . . */
	if (n % nbb == 1 || nbb == 1) {
	    factor *= cbay;
	}
	tt = con_1.pi2 * dy * (en - 1.f);
	ts = cpsi - stheta * sbz;
	r__1 = cos(tt * ts);
	r__2 = sin(tt * ts);
	q__1.r = r__1, q__1.i = r__2;
	zt.r = q__1.r, zt.i = q__1.i;
/* L365: */
	q__2.r = factor * zt.r, q__2.i = factor * zt.i;
	q__1.r = af.r + q__2.r, q__1.i = af.i + q__2.i;
	af.r = q__1.r, af.i = q__1.i;
    }
/* . . .CALCULATE REAL-IMAGE (SCREEN) ARRARYING FACTOR . . . . . . . . . */
L370:
    tt = sin(con_1.pi2 * dx * stheta * cb);
/* . . .CALCULATE THE GAIN. . . . . . . . . . . . . . . . . . . . . . . . */
/* Computing 2nd power */
    r__2 = sb;
/* Computing 2nd power */
    r__3 = q;
    r__1 = r__2 * r__2 * (r__3 * r__3);
    q__4.r = r__1 * azv.r, q__4.i = r__1 * azv.i;
    r_cnjg(&q__5, &azv);
    q__3.r = q__4.r * q__5.r - q__4.i * q__5.i, q__3.i = q__4.r * q__5.i + 
	    q__4.i * q__5.r;
/* Computing 2nd power */
    r__5 = cb;
    r__4 = r__5 * r__5;
    q__7.r = r__4 * azh.r, q__7.i = r__4 * azh.i;
    r_cnjg(&q__8, &azh);
    q__6.r = q__7.r * q__8.r - q__7.i * q__8.i, q__6.i = q__7.r * q__8.i + 
	    q__7.i * q__8.r;
    q__2.r = q__3.r + q__6.r, q__2.i = q__3.i + q__6.i;
/* Computing 2nd power */
    r__7 = tt;
    r__6 = r__7 * r__7;
    q__1.r = r__6 * q__2.r, q__1.i = r__6 * q__2.i;
    zt.r = q__1.r, zt.i = q__1.i;
/* Computing 2nd power */
    r__1 = cpsi;
    spsi2 = 1.f - r__1 * r__1;
    *rain = 0.f;
    if (spsi2 == 0.f) {
	goto L615;
    }
    tt = (cos(con_1.pi2 * cur_1.eil * cpsi) - cos(con_1.pi2 * cur_1.eil)) / 
	    spsi2;
    q__4.r = zt.r * af.r - zt.i * af.i, q__4.i = zt.r * af.i + zt.i * af.r;
    r_cnjg(&q__5, &af);
    q__3.r = q__4.r * q__5.r - q__4.i * q__5.i, q__3.i = q__4.r * q__5.i + 
	    q__4.i * q__5.r;
/* Computing 2nd power */
    r__2 = tt;
    r__1 = r__2 * r__2;
    q__2.r = r__1 * q__3.r, q__2.i = r__1 * q__3.i;
    q__1.r = q__2.r / rin, q__1.i = q__2.i / rin;
    train = q__1.r;
    if (cur_1.kode < 0) {
	goto L375;
    }
/* Computing 2nd power */
    r__1 = 1.f / sin(con_1.pi2 * cur_1.eil);
    *rain = r__1 * r__1 * 480.f * train;
    goto L615;
/* . . .SEE MA(1974) EQN.(4.114) P. 273 AND MA (PRIVATE COMM.) FOR. . . . */
/* . . .CTU AND CTD VALUES FOR FULL WAVELENGTH CASE . . . . . . . . . . . */
L375:
    ctu.r = -.041929f, ctu.i = .0461374f;
    ctd.r = -.0184019f, ctd.i = .0612938f;
    r__1 = sin(con_1.pi2 * cur_1.eil);
    r__2 = 1.f - cos(con_1.pi2 * cur_1.eil);
    q__3.r = r__2 * ctu.r, q__3.i = r__2 * ctu.i;
    q__2.r = r__1 + q__3.r, q__2.i = q__3.i;
    r__3 = 1.f - cos(con_1.pi * cur_1.eil);
    q__4.r = r__3 * ctd.r, q__4.i = r__3 * ctd.i;
    q__1.r = q__2.r + q__4.r, q__1.i = q__2.i + q__4.i;
    curnt.r = q__1.r, curnt.i = q__1.i;
    r__1 = train * 480.f;
    q__2.r = r__1, q__2.i = 0.f;
    r_cnjg(&q__4, &curnt);
    q__3.r = curnt.r * q__4.r - curnt.i * q__4.i, q__3.i = curnt.r * q__4.i + 
	    curnt.i * q__4.r;
    c_div(&q__1, &q__2, &q__3);
    *rain = q__1.r;
    goto L615;
/* .....TERMINATED SLOPING VEE ANTENNA, KOP=7............................. */
L380:
    ht = ex[0] / wave;
    if (ex[0] < 0.f) {
	ht = dabs(ex[0]);
    }
    deltap = asin((ht - x) / el1);
    cdelp = cos(deltap);
L385:
    rhi = asin(sr / cdelp);
    cr = cos(rhi);
    sr = sin(rhi);
    cd = cb * cr + sb * sr;
    cs = cb * cr - sb * sr;
    ss = sb * cr + cb * sr;
    sd = sb * cr - cb * sr;
    scp = t * cdelp;
    ccp = q * cdelp;
    sdelp = sin(deltap);
    ssp = t * sdelp;
    csp = q * sdelp;
    u1 = 1.f - (csp + scp * cd);
    u2 = 1.f - (csp + scp * cs);
    u3 = 1.f - (-csp + scp * cd);
    u4 = 1.f - (-csp + scp * cs);
    cp5 = ssp + ccp * cd;
    cp6 = ssp + ccp * cs;
    cp7 = -ssp + ccp * cd;
    cp8 = -ssp + ccp * cs;
    w1 = cos(psih - hqwave);
    w2 = sin(psih - hqwave);
    w3 = cos(psiv - hqwave);
    w4 = sin(psiv - hqwave);
    fu1 = fac2 * u1;
    v1 = sin(fu1);
    z1 = cos(fu1);
    fu2 = fac2 * u2;
    v2 = sin(fu2);
    z2 = cos(fu2);
    fu3 = fac2 * u3;
    v3 = sin(fu3);
    z3 = cos(fu3);
    fu4 = fac2 * u4;
    v4 = sin(fu4);
    z4 = cos(fu4);
    if (*kop == 9) {
	goto L440;
    }
    z1 += -1.f;
    z2 += -1.f;
    z3 += -1.f;
    z4 += -1.f;
    y1 = u1 * ss;
    y3 = u3 * ss;
    y2 = u2 * sd;
    y4 = u4 * sd;
    u12 = u1 * u2;
    u34 = u3 * u4;
    if (u12 == 0.f) {
	goto L390;
    }
    r__1 = (u2 * cp7 * z1 - u1 * z2 * cp8) / u12;
    a1.r = r__1, a1.i = 0.f;
    r__1 = (u1 * v2 * cp8 - u2 * v1 * cp7) / u12;
    b1.r = r__1, b1.i = 0.f;
    c1 = (y1 * z2 - y2 * z1) / u12;
    d1 = (y2 * v1 - y1 * v2) / u12;
    goto L395;
L390:
    a1.r = 0.f, a1.i = 0.f;
    b1.r = 0.f, b1.i = 0.f;
    c1 = 0.f;
    d1 = 0.f;
    if (u34 == 0.f) {
	goto L615;
    }
L395:
    if (u34 == 0.f) {
	goto L400;
    }
    a2 = u3 * z4 * cp6 - u4 * z3 * cp5;
    b2 = u3 * v4 * cp6 - u4 * v3 * cp5;
    r__1 = cv * (w3 * a2 + w4 * b2) / u34;
    q__1.r = a1.r + r__1, q__1.i = a1.i;
    a1.r = q__1.r, a1.i = q__1.i;
    r__1 = cv * (-b2 * w3 + w4 * a2) / u34;
    q__1.r = b1.r + r__1, q__1.i = b1.i;
    b1.r = q__1.r, b1.i = q__1.i;
    aa2 = y3 * z4 - y4 * z3;
    bb2 = y4 * v3 - y3 * v4;
    c1 += ch * (w1 * aa2 - w2 * bb2) / u34;
    d1 += ch * (w1 * bb2 + w2 * aa2) / u34;
L400:
    pow_ci(&q__4, &a1, &c__2);
    pow_ci(&q__5, &b1, &c__2);
    q__3.r = q__4.r + q__5.r, q__3.i = q__4.i + q__5.i;
/* Computing 2nd power */
    r__2 = cdelp;
/* Computing 2nd power */
    r__3 = c1;
/* Computing 2nd power */
    r__4 = d1;
    r__1 = r__2 * r__2 * (r__3 * r__3 + r__4 * r__4);
    q__2.r = q__3.r + r__1, q__2.i = q__3.i;
    q__1.r = q__2.r * .05f, q__1.i = q__2.i * .05f;
    *rain = q__1.r;
    *eff = -1.7f;
    goto L615;
/* .....INVERTED L ANTENNA, KOP=8......................................... */
L405:
    sph = sb;
    cph = cb;
    sb = q;
    cb = t;
    xl = el;
    xh = h__;
    eps = er;
    sig = sigma;
    f = *freq;
    wk = con_1.pi2 / wave;
    psig = sig * -1.8e4f / f;
    q__3.r = eps, q__3.i = psig;
    c_sqrt(&q__2, &q__3);
    q__1.r = wk * q__2.r, q__1.i = wk * q__2.i;
    wk2.r = q__1.r, wk2.i = q__1.i;
    q__2.r = wk, q__2.i = 0.f;
    c_div(&q__1, &q__2, &wk2);
    wkok2.r = q__1.r, wkok2.i = q__1.i;
    q__1.r = wk2.r / wk, q__1.i = wk2.i / wk;
    wk2ok.r = q__1.r, wk2ok.i = q__1.i;
    wl = wk * xl;
    if (xl < 0.f) {
	wl = con_1.pi2 * dabs(xl);
    }
    wh = wk * xh;
    if (xh < 0.f) {
	wh = con_1.pi2 * dabs(xh);
    }
    wlh = wl + wh;
    swl = sin(wl);
    cwl = cos(wl);
    swlh = sin(wlh);
    swlh2 = swlh * swlh;
    cwlh = cos(wlh);
    q__4.r = cb * wkok2.r, q__4.i = cb * wkok2.i;
    pow_ci(&q__3, &q__4, &c__2);
    q__2.r = 1.f - q__3.r, q__2.i = -q__3.i;
    c_sqrt(&q__1, &q__2);
    rc.r = q__1.r, rc.i = q__1.i;
    q__3.r = wkok2.r * rc.r - wkok2.i * rc.i, q__3.i = wkok2.r * rc.i + 
	    wkok2.i * rc.r;
    q__2.r = sb - q__3.r, q__2.i = -q__3.i;
    q__5.r = wkok2.r * rc.r - wkok2.i * rc.i, q__5.i = wkok2.r * rc.i + 
	    wkok2.i * rc.r;
    q__4.r = sb + q__5.r, q__4.i = q__5.i;
    c_div(&q__1, &q__2, &q__4);
    rv.r = q__1.r, rv.i = q__1.i;
    q__3.r = wk2ok.r * rc.r - wk2ok.i * rc.i, q__3.i = wk2ok.r * rc.i + 
	    wk2ok.i * rc.r;
    q__2.r = sb - q__3.r, q__2.i = -q__3.i;
    q__5.r = wk2ok.r * rc.r - wk2ok.i * rc.i, q__5.i = wk2ok.r * rc.i + 
	    wk2ok.i * rc.r;
    q__4.r = sb + q__5.r, q__4.i = q__5.i;
    c_div(&q__1, &q__2, &q__4);
    rh.r = q__1.r, rh.i = q__1.i;
    rvab = c_abs(&rv);
    rhab = c_abs(&rh);
    psiv = cang_(&rv);
    psih = cang_(&rh);
    cpsiph = cb * sph;
    psiph = acos(cpsiph);
    spsiph = sin(psiph);
/* Computing 2nd power */
    r__1 = spsiph;
    spsiph2 = r__1 * r__1;
    wb = wh * sb;
    swb = sin(wb);
    cwb = cos(wb);
    a4 = cwl * cwb - sb * swl * swb - cwlh;
    b4 = sb * swl * cwb + cwl * swb - sb * swlh;
    ab4 = sqrt(a4 * a4 + b4 * b4);
    if (ab4 != 0.f) {
	goto L14;
    }
    bp = 0.f;
    goto L15;
L14:
    bp = atan2(b4, a4);
L15:
    wc = wl * cpsiph;
    swc = sin(wc);
    cwc = cos(wc);
    a5 = cwc - cwl;
    b5 = swc - cpsiph * swl;
    ab5 = sqrt(a5 * a5 + b5 * b5);
    if (ab5 != 0.f) {
	goto L16;
    }
    bpp = 0.f;
    goto L17;
L16:
    bpp = atan2(b5, a5);
L17:
    parv = bpp + psiv - wh * 2.f * sb;
    parh = bpp + psih - wh * 2.f * sb;
    if (spsiph2 != 0.f) {
	goto L18;
    }
    f2 = 0.f;
    f11 = 0.f;
    g2 = 0.f;
    g11 = 0.f;
    goto L19;
L18:
    dab5 = ab5 * sph * sb / spsiph2;
    f11 = dab5 * (cos(bpp) - rvab * cos(parv));
    g11 = dab5 * (sin(bpp) - rvab * sin(parv));
    hab5 = ab5 * cph / spsiph2;
    f2 = hab5 * (cos(bpp) + rhab * cos(parh));
    g2 = hab5 * (sin(bpp) + rhab * sin(parh));
L19:
    if (cb != 0.f) {
	goto L20;
    }
    f12 = 0.f;
    g12 = 0.f;
    goto L21;
L20:
    dab4 = ab4 / cb;
    f12 = -dab4 * (cos(bp) + rvab * cos(psiv - bp));
    g12 = -dab4 * (sin(bp) + rvab * sin(psiv - bp));
L21:
    f1 = f11 + f12;
    g1 = g11 + g12;
/* Computing 2nd power */
    r__1 = f1;
/* Computing 2nd power */
    r__2 = g1;
/* Computing 2nd power */
    r__3 = f2;
/* Computing 2nd power */
    r__4 = g2;
    g = (r__1 * r__1 + r__2 * r__2 + r__3 * r__3 + r__4 * r__4) * 30.f;
    w2h = wh * 2.f;
    w4h = w2h * 2.f;
    csz1_(&q__1, &w2h);
    ci2 = q__1.r;
    csz1_(&q__1, &w4h);
    ci4 = q__1.r;
    cin2 = con_1.gama + log(w2h) - ci2;
    cin4 = con_1.gama + log(w4h) - ci4;
    csz1_(&q__1, &w2h);
    si2 = -r_imag(&q__1);
    csz1_(&q__1, &w4h);
    si4 = -r_imag(&q__1);
    cw2h = cos(w2h);
    sw2h = sin(w2h);
    vrt = ((cw2h + 1) * cin2 - cw2h * .5f * cin4 - sw2h * (si2 - si4 * .5f)) *
	     30.f;
    rin = vrt;
    if (x >= .2f) {
	goto L430;
    }
    rin = x * 400.f * x * rintw / 16.f;
L430:
    fmult = 4.f - (sigma - 1e-4f) * 3.f / 4.9999000000000002f;
    rin = fmult * 16.f * rin / rintw;
/* . . .CALCULATE GAIN FROM ABOVE AND EQN.(4), P. 4 */
    *rain = g / rin;
    if (x > .2f) {
	goto L615;
    }
    r__1 = x * (x * (67.95f - x * (693.f - x * 1600.f)) + 6.335f);
    *eff = r_lg10(&r__1) * 20.f;
    goto L615;
/* .....TERMINATED SLOPING RHOMBIC ANTENNA, KOP=9......................... */
L435:
    ht = ex[0] / wave;
    if (ex[0] < 0.f) {
	ht = dabs(ex[0]);
    }
    deltap = asin((ht - x) / (el1 * 2.f));
    cdelp = cos(deltap);
    goto L385;
L440:
    r__1 = z1 * z2 + 1.f - v1 * v2 - z1 - z2;
    a1.r = r__1, a1.i = 0.f;
    r__1 = -v1 * z2 - z1 * v2 + v1 + v2;
    b1.r = r__1, b1.i = 0.f;
    a2 = z3 * z4 + 1.f - v3 * v4 - z3 - z4;
    b2 = -v3 * z4 - z3 * v4 + v3 + v4;
    cm = cp8 / u2 - cp7 / u1;
    cn = (cp5 / u3 - cp6 / u4) * cv;
    cmp = sd / u1 - ss / u2;
    cnp = (sd / u3 - ss / u4) * ch;
    q__2.r = cm * a1.r, q__2.i = cm * a1.i;
    r__1 = cn * (a2 * w3 - b2 * w4);
    q__1.r = q__2.r + r__1, q__1.i = q__2.i;
    am = q__1.r;
    q__2.r = cm * b1.r, q__2.i = cm * b1.i;
    r__1 = cn * (a2 * w4 + b2 * w3);
    q__1.r = q__2.r + r__1, q__1.i = q__2.i;
    an = q__1.r;
    q__2.r = cmp * a1.r, q__2.i = cmp * a1.i;
    r__1 = cnp * (a2 * w1 - b2 * w2);
    q__1.r = q__2.r + r__1, q__1.i = q__2.i;
    pam = q__1.r;
    q__2.r = cmp * b1.r, q__2.i = cmp * b1.i;
    r__1 = cnp * (a2 * w2 + b2 * w1);
    q__1.r = q__2.r + r__1, q__1.i = q__2.i;
    pan = q__1.r;
/* Computing 2nd power */
    r__1 = am;
/* Computing 2nd power */
    r__2 = an;
/* Computing 2nd power */
    r__3 = cdelp;
/* Computing 2nd power */
    r__4 = pam;
/* Computing 2nd power */
    r__5 = pan;
    *rain = (r__1 * r__1 + r__2 * r__2 + r__3 * r__3 * (r__4 * r__4 + r__5 * 
	    r__5)) * .05f;
    *eff = -1.7f;
    goto L615;
/* .....ANTENNA ALREADY IN THE ARRAY, KOP=10.............................. */
L445:
    s_wsfe(&io___317);
    e_wsfe();
    goto L640;
/* .....SLOPING LONG WIRE, KOP = 11....................................... */
L450:
    cfac2 = cos(fac2);
    sfac2 = sin(fac2);
    w1 = cos(psih - hqwave);
    w2 = sin(psih - hqwave);
    w3 = cos(psiv - hqwave);
    w4 = sin(psiv - hqwave);
    crb = cr * cb * q;
    srt = sr * t;
    cbs = cr * sb;
    srq = q * sr;
    cphi = srq + t * cr * cb;
/* Computing 2nd power */
    r__1 = cphi;
    sphi2 = 1.f - r__1 * r__1;
    cphip = -srq + t * cr * cb;
/* Computing 2nd power */
    r__1 = cphip;
    sphip2 = 1.f - r__1 * r__1;
    *rain = 0.f;
    if (sphi2 == 0.f && sphip2 == 0.f) {
	goto L615;
    }
    if (sphi2 == 0.f) {
	goto L455;
    }
    cig = (cos(fac2 * cphi) - cfac2) / sphi2;
    ephi1 = -cbs * cig;
    ethet1 = (crb - srt) * cig;
    sig = (sin(fac2 * cphi) - cphi * sfac2) / sphi2;
    ethet2 = (crb - srt) * sig;
    ephi2 = -cbs * sig;
    goto L460;
L455:
    ethet1 = 0.f;
    ethet2 = 0.f;
    ephi1 = 0.f;
    ephi2 = 0.f;
L460:
    if (sphip2 == 0.f) {
	goto L465;
    }
    cigp = (cos(fac2 * cphip) - cfac2) / sphip2;
    sigp = (sin(fac2 * cphip) - cphip * sfac2) / sphip2;
    ethet1 -= (crb + srt) * cv * (w3 * cigp - w4 * sigp);
    ethet2 -= (crb + srt) * cv * (w4 * cigp + w3 * sigp);
    ephi1 -= cbs * ch * (w1 * cigp - w2 * sigp);
    ephi2 -= cbs * ch * (w2 * cigp + w1 * sigp);
L465:
    if (*kas <= 1) {
	r__1 = fac4 * 2.f;
	csz1_(&q__1, &r__1);
	azh.r = q__1.r, azh.i = q__1.i;
	w5 = azh.r;
	w6 = r_imag(&azh);
	csz1_(&q__1, &fac4);
	azh.r = q__1.r, azh.i = q__1.i;
	w33 = azh.r;
	w4 = r_imag(&azh);
	flog = log(fac2) + con_1.gama;
	rin = ((flog - w5) * .5f + .6931471806f + cfac2 * (cfac2 * (flog - 
		w33 * 2.f + w5) - sfac2 * (w6 - w4 * 2.f))) * 30.f;
    }
/* Computing 2nd power */
    r__1 = ethet1;
/* Computing 2nd power */
    r__2 = ethet2;
/* Computing 2nd power */
    r__3 = ephi1;
/* Computing 2nd power */
    r__4 = ephi2;
    *rain = (r__1 * r__1 + r__2 * r__2 + r__3 * r__3 + r__4 * r__4) * 30.f / 
	    rin;
    goto L615;
/* .....CONSTANT GAIN KOP=12.............................................. */
L475:
    *rain = h__;
    *eff = 0.f;
    goto L630;
/* .....GENERAL HORIZONTAL LOG-PERIODIC ANTENNA  KOP=13................... */
L480:
    if (*kas > 1) {
	goto L550;
    }
/*     CALL TO CIN ELIMINATED - CODE INCORPORATED BELOW */
    yz = 1.f / ex[0];
    n = ex[3];
    hfmufes_one__1.ell[n - 1] = fac;
    xk[n - 1] = hfmufes_one__1.ell[n - 1] * (1.f / tan(ex[1] * con_1.d2r));
    hfmufes_one__1.nmx = n - 1;
    i__2 = hfmufes_one__1.nmx;
    for (ii = 1; ii <= i__2; ++ii) {
	nii = n - ii;
	nip = nii + 1;
	hfmufes_one__1.ell[nii - 1] = hfmufes_one__1.ell[nip - 1] * ex[2];
	xk[nii - 1] = xk[nip - 1] * ex[2];
/* L485: */
    }
/*     DO 490 J = 1, 400 */
    for (j = 1; j <= 20; ++j) {
	for (jj = 1; jj <= 20; ++jj) {
	    tx[j + jj * 20 - 21] = 0.f;
	    ty[j + jj * 20 - 21] = 0.f;
	    yr[j + jj * 20 - 21] = 0.f;
/* L490: */
	    yi[j + jj * 20 - 21] = 0.f;
	}
    }
    i__2 = hfmufes_one__1.nmx;
    for (i__ = 1; i__ <= i__2; ++i__) {
	mid = i__ + 1;
	if (i__ == 1) {
	    goto L495;
	}
	yi[i__ + i__ * 20 - 21] = -yz * (1.f / tan(xk[mid - 1] - xk[i__ - 1]) 
		+ 1.f / tan(xk[i__ - 1] - xk[i__ - 2]));
L495:
	yi[i__ + mid * 20 - 21] = -yz / sin(xk[mid - 1] - xk[i__ - 1]);
	yi[mid + i__ * 20 - 21] = yi[i__ + mid * 20 - 21];
/* L500: */
    }
    yi[0] = -yz * (1.f / tan(xk[1] - xk[0]));
    cot = 1.f / (yz * (1.f / tan(hfmufes_one__1.ell[n - 1] / 2.f)));
    zts = 0.f;
/* Computing 2nd power */
    r__1 = zts;
/* Computing 2nd power */
    r__2 = cot;
    ta = r__1 * r__1 + r__2 * r__2;
    yrn = zts / ta;
    yi[n + n * 20 - 21] = -(cot / ta + yz * (1.f / tan(xk[n - 1] - xk[
	    hfmufes_one__1.nmx - 1])));
    const__ = sqrtwo / 177.f;
    i__2 = n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	jend = i__;
	hfmufes_one__1.no = jend;
	hfmufes_one__1.nmx = jend;
	hfmufes_one__1.d1d[jend - 1] = hfmufes_one__1.ell[jend - 1] * const__;
	jen = jend - 1;
	i__4 = jen;
	for (jl = 1; jl <= i__4; ++jl) {
/* L505: */
	    hfmufes_one__1.d1d[jl - 1] = (r__1 = xk[jend - 1] - xk[jl - 1], 
		    dabs(r__1));
	}
	sim_();
	i__4 = jend;
	for (jk = 1; jk <= i__4; ++jk) {
	    i__3 = jk + jend * 20 - 21;
	    i__1 = jk - 1;
	    z__[i__3].r = hfmufes_one__1.zs[i__1].r, z__[i__3].i = 
		    hfmufes_one__1.zs[i__1].i;
	    if (jk != jend) {
		i__3 = jend + jk * 20 - 21;
		i__1 = jk - 1;
		z__[i__3].r = hfmufes_one__1.zs[i__1].r, z__[i__3].i = 
			hfmufes_one__1.zs[i__1].i;
	    }
/* L515: */
	}
/* L520: */
    }
    i__2 = n;
    for (j = 1; j <= i__2; ++j) {
	i__4 = n;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    i__3 = n;
	    for (k = 1; k <= i__3; ++k) {
		tx[i__ + j * 20 - 21] -= yi[k + i__ * 20 - 21] * r_imag(&z__[
			k + j * 20 - 21]);
		i__1 = k + j * 20 - 21;
		ty[i__ + j * 20 - 21] += yi[k + i__ * 20 - 21] * z__[i__1].r;
		if (i__ != n || k != n) {
		    goto L525;
		}
		i__1 = n + j * 20 - 21;
		tx[n + j * 20 - 21] += yrn * z__[i__1].r;
		ty[n + j * 20 - 21] += yrn * r_imag(&z__[n + j * 20 - 21]);
L525:
		;
	    }
	}
    }
    i__3 = n;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* L530: */
	tx[i__ + i__ * 20 - 21] += 1.f;
    }
    cmpinv_(tx, ty, yr, yi, &n);
    sum0 = 0.f;
    i__3 = n;
    for (i__ = 1; i__ <= i__3; ++i__) {
	cix[i__ - 1] = yr[i__ - 1];
	ciy[i__ - 1] = yi[i__ - 1];
/* L535: */
	i__4 = i__ - 1;
	sum0 = sum0 + yr[i__ - 1] * z__[i__4].r - yi[i__ - 1] * r_imag(&z__[
		i__ - 1]);
    }
    sumd = 0.f;
    hfmufes_one__1.d1d[0] = hwave * 2.f;
/* Computing 2nd power */
    r__1 = hfmufes_one__1.d1d[0];
    th = r__1 * r__1;
    txs = hwave * 4.f * cr;
    i__4 = n;
    for (nj = 2; nj <= i__4; ++nj) {
	sumd = sumd + xk[nj - 1] - xk[nj - 2];
/* L540: */
/* Computing 2nd power */
	r__1 = sumd;
	hfmufes_one__1.d1d[nj - 1] = sqrt(th + r__1 * r__1 + txs * sumd);
    }
    hfmufes_one__1.nmx = 1;
    hfmufes_one__1.no = n;
    sim_();
    v.r = 0.f, v.i = 0.f;
    i__4 = n;
    for (j = 1; j <= i__4; ++j) {
/* L545: */
	i__3 = i__ - 1;
	i__2 = i__ - 1;
	q__3.r = yr[i__3], q__3.i = yi[i__2];
	i__1 = i__ - 1;
	q__2.r = q__3.r * hfmufes_one__1.zs[i__1].r - q__3.i * 
		hfmufes_one__1.zs[i__1].i, q__2.i = q__3.r * 
		hfmufes_one__1.zs[i__1].i + q__3.i * hfmufes_one__1.zs[i__1]
		.r;
	q__1.r = v.r + q__2.r, q__1.i = v.i + q__2.i;
	v.r = q__1.r, v.i = q__1.i;
    }
    c_sqrt(&q__1, &dif);
    sqrd.r = q__1.r, sqrd.i = q__1.i;
    q__3.r = 1.f - sqrd.r, q__3.i = -sqrd.i;
    q__2.r = v.r * q__3.r - v.i * q__3.i, q__2.i = v.r * q__3.i + v.i * 
	    q__3.r;
    q__4.r = sqrd.r + 1.f, q__4.i = sqrd.i;
    c_div(&q__1, &q__2, &q__4);
    sum2 = q__1.r;
    rin = sum0 + sum2;
L550:
    cpsi = t * sb;
/* Computing 2nd power */
    r__1 = cpsi;
    spsi2 = 1.f - r__1 * r__1;
    *rain = 0.f;
    if (spsi2 == 0.f) {
	goto L615;
    }
    etr = 0.f;
    eti = 0.f;
    epr = 0.f;
    epi = 0.f;
    cq2 = cr * q;
    cbeta = cq2 - t * cb * sr;
    cq2 *= 2.f;
    i__3 = n;
    for (j = 1; j <= i__3; ++j) {
	arg5 = cq2 * xk[j - 1];
	cr5 = cos(arg5);
	sr5 = sin(arg5);
	ccb = cos(xk[j - 1] * cbeta) / sin(hfmufes_one__1.ell[j - 1]);
	scb = sin(xk[j - 1] * cbeta) / sin(hfmufes_one__1.ell[j - 1]);
	tt = cos(hfmufes_one__1.ell[j - 1] * cpsi) - cos(hfmufes_one__1.ell[j 
		- 1]);
	a = (cix[j - 1] * ccb - ciy[j - 1] * scb) * tt;
	bb = (ciy[j - 1] * ccb + cix[j - 1] * scb) * tt;
	w1 = ch * cos(psih - hqwave);
	w2 = ch * sin(psih - hqwave);
	w3 = cv * cos(psiv - hqwave);
	w4 = cv * sin(psiv - hqwave);
	c__ = 1.f - (w3 * cr5 + w4 * sr5);
	dd = w4 * cr5 - w3 * sr5;
	etr = etr + a * c__ + bb * dd;
	eti = eti + bb * c__ - a * dd;
	cc = w1 * cr5 + w2 * sr5 + 1.f;
	dc = w2 * cr5 - w1 * sr5;
	epr = epr + a * cc - bb * dc;
/* L555: */
	epi = epi + bb * cc + a * dc;
    }
/* Computing 2nd power */
    r__1 = etr;
/* Computing 2nd power */
    r__2 = eti;
/* Computing 2nd power */
    r__3 = q * sb / spsi2;
    etmag = (r__1 * r__1 + r__2 * r__2) * (r__3 * r__3);
/* Computing 2nd power */
    r__1 = epr;
/* Computing 2nd power */
    r__2 = epi;
/* Computing 2nd power */
    r__3 = cb / spsi2;
    epmag = (r__1 * r__1 + r__2 * r__2) * (r__3 * r__3);
    *rain = (etmag + epmag) * 120.f / rin;
    goto L615;
/* .....ARBITARY TILTED DIPOLE ANTENNA, KOP=14............................ */
L560:
    mut_1.cfac = cos(fac);
    w1 = cos(psih - hqwave);
    w2 = sin(psih - hqwave);
    w3 = cos(psiv - hqwave);
    w4 = sin(psiv - hqwave);
    tip = el1 * .5f * sr;
    if (tip > x) {
	goto L635;
    }
    csb = cr * sb;
    cphi = q * sr + t * csb;
/* Computing 2nd power */
    r__1 = cphi;
    sphi2 = 1.f - r__1 * r__1;
    cphip = -q * sr + t * csb;
/* Computing 2nd power */
    r__1 = cphip;
    sphip2 = 1.f - r__1 * r__1;
    if (sphi2 == 0.f) {
	goto L565;
    }
    gi = (cos(fac * cphi) - mut_1.cfac) / sphi2;
    r__1 = (csb * q - sr * t) * gi;
    etheta1.r = r__1, etheta1.i = 0.f;
    ephi1 = cr * cb * gi;
    goto L570;
L565:
    etheta1.r = 0.f, etheta1.i = 0.f;
    ephi1 = 0.f;
L570:
    if (sphip2 == 0.f) {
	goto L575;
    }
    di = (cos(fac * cphip) - mut_1.cfac) / sphip2;
    r__1 = (csb * q + sr * t) * di * cv * w3;
    q__1.r = etheta1.r - r__1, q__1.i = etheta1.i;
    etheta1.r = q__1.r, etheta1.i = q__1.i;
    ephi1 += di * ch * w1 * cr * cb;
    r__1 = -(csb * q + sr * t) * di * cv * w4;
    etheta2.r = r__1, etheta2.i = 0.f;
    ephi2 = cr * cb * di * ch * w2;
    goto L580;
L575:
    etheta2.r = 0.f, etheta2.i = 0.f;
    ephi2 = 0.f;
L580:
    if (*kas > 1) {
	goto L585;
    }
    mut_1.y0 = ratio * el1;
    mut_1.h2 = el1 * .5f;
    mut_1.rhi2 = 0.f;
    mut_1.z0 = 0.f;
    mutual_();
    r11 = mut_1.r21;
    mut_1.y0 = x * 2.f * cr;
    mut_1.z0 = x * 2.f * sr;
    mut_1.rhi2 = rhi * 2.f;
    mutual_();
    q__1.r = mut_1.r21, q__1.i = mut_1.x21;
    zm.r = q__1.r, zm.i = q__1.i;
    if (mut_1.rhi2 > con_1.pio2) {
	q__1.r = -zm.r, q__1.i = -zm.i;
	zm.r = q__1.r, zm.i = q__1.i;
    }
    c_sqrt(&q__1, &dif);
    sqrd.r = q__1.r, sqrd.i = q__1.i;
    q__6.r = 1.f - sqrd.r, q__6.i = -sqrd.i;
    q__7.r = sqrd.r + 1.f, q__7.i = sqrd.i;
    c_div(&q__5, &q__6, &q__7);
    q__4.r = cr * q__5.r, q__4.i = cr * q__5.i;
    q__11.r = dif.r - sqrd.r, q__11.i = dif.i - sqrd.i;
    q__12.r = dif.r + sqrd.r, q__12.i = dif.i + sqrd.i;
    c_div(&q__10, &q__11, &q__12);
    q__9.r = q__10.r * 0.f - q__10.i * 1.f, q__9.i = q__10.r * 1.f + q__10.i *
	     0.f;
    q__8.r = sr * q__9.r, q__8.i = sr * q__9.i;
    q__3.r = q__4.r + q__8.r, q__3.i = q__4.i + q__8.i;
    q__2.r = zm.r * q__3.r - zm.i * q__3.i, q__2.i = zm.r * q__3.i + zm.i * 
	    q__3.r;
    r__1 = -sr;
    q__13.r = cr, q__13.i = r__1;
    q__1.r = q__2.r * q__13.r - q__2.i * q__13.i, q__1.i = q__2.r * q__13.i + 
	    q__2.i * q__13.r;
    cxc = q__1.r;
    rin = r11 + cxc;
L585:
    pow_ci(&q__6, &etheta1, &c__2);
    pow_ci(&q__7, &etheta2, &c__2);
    q__5.r = q__6.r + q__7.r, q__5.i = q__6.i + q__7.i;
/* Computing 2nd power */
    r__2 = ephi1;
    r__1 = r__2 * r__2;
    q__4.r = q__5.r + r__1, q__4.i = q__5.i;
/* Computing 2nd power */
    r__4 = ephi2;
    r__3 = r__4 * r__4;
    q__3.r = q__4.r + r__3, q__3.i = q__4.i;
    q__2.r = q__3.r * 120.f, q__2.i = q__3.i * 120.f;
    q__1.r = q__2.r / rin, q__1.i = q__2.i / rin;
    *rain = q__1.r;
    goto L615;
/* .....HALF RHOMBIC ANTENNA, KOP=15...................................... */
L590:
    w1 = cos(psih);
    w2 = sin(psih);
    w3 = cos(psiv);
    w4 = sin(psiv);
    tt = q * sr;
    ts = 1.f - t * cr * cb;
    tt2 = ts + tt;
    ts2 = fac2 * tt2;
    sts4 = sin(ts2) / tt2;
    cts4 = (1.f - cos(ts2)) / tt2;
    tt1 = ts - tt;
    ts1 = fac2 * tt1;
    sts1 = sin(ts1);
    cts1 = cos(ts1);
    r1 = (1.f - cts1) / tt1;
    fi1 = sts1 / tt1;
    r4 = (1.f - cts1) * cos(fac4 * sr * q) + sts1 * sin(fac4 * sr * q);
    fi4 = sts1 * cos(fac4 * sr * q) - sin(fac4 * sr * q) * (1.f - cts1);
    r2 = cts4 * cts1 + sts4 * sts1;
    fi2 = cts1 * sts4 - cts4 * sts1;
    f4c = (fi4 * cts1 - r4 * sts1) / tt1;
    r4c = (r4 * cts1 + fi4 * sts1) / tt1;
    rb = r1 + r2 - ((cts4 + r4c) * w3 - (sts4 + f4c) * w4) * cv;
    bi = fi1 + fi2 - ((cts4 + r4c) * w4 + (sts4 + f4c) * w3) * cv;
    r__1 = -r1 + r2 + ((-cts4 + r4c) * w3 - (-sts4 + f4c) * w4) * cv;
    rc.r = r__1, rc.i = 0.f;
    cc = -fi1 + fi2 + ((-cts4 + r4c) * w4 + (-sts4 + f4c) * w3) * cv;
    ra = r1 + r2 + ((cts4 + r4c) * w1 - (sts4 + f4c) * w2) * ch;
    ai = fi1 + fi2 + ((cts4 + r4c) * w2 + (sts4 + f4c) * w1) * ch;
    r__1 = cr * cb * q * rb;
    r__2 = sr * t;
    q__4.r = r__2 * rc.r, q__4.i = r__2 * rc.i;
    q__3.r = r__1 + q__4.r, q__3.i = q__4.i;
    pow_ci(&q__2, &q__3, &c__2);
/* Computing 2nd power */
    r__4 = cr * cb * q * bi + sr * t * cc;
    r__3 = r__4 * r__4;
    q__1.r = q__2.r + r__3, q__1.i = q__2.i;
    em1 = q__1.r;
/* Computing 2nd power */
    r__1 = cr * sb * ra;
/* Computing 2nd power */
    r__2 = cr * sb * ai;
    enn1 = r__1 * r__1 + r__2 * r__2;
    *rain = (enn1 + em1) * .1f;
    rin = 300.f;
    *eff = -1.7f;
    goto L615;
/* .....SLOPING DOUBLE RHOMBOID, KOP=16................................... */
L595:
    el2 = ex[2] / wave;
    if (ex[2] < 0.f) {
	el2 = dabs(ex[2]);
    }
    fak = con_1.pi2 * el2;
    ht = ex[3] / wave;
    if (ex[3] < 0.f) {
	ht = dabs(ex[3]);
    }
    del = asin((ht - x) / (el1 + el2));
    w1 = ch * cos(psih - hqwave);
    w2 = ch * sin(psih - hqwave);
    w3 = cv * cos(psiv - hqwave);
    w4 = cv * sin(psiv - hqwave);
    cdel = cos(del);
    sdel = sin(del);
    sx1 = sin(ex[0] * con_1.d2r);
    bp1 = asin(sx1 / cdel);
    cp1 = cos(bp1);
    sp1 = sin(bp1);
    sx2 = sin(ex[1] * con_1.d2r);
    bp2 = asin(sx2 / cdel);
    cp2 = cos(bp2);
    sp2 = sin(bp2);
    rp1m = ((cb * cp1 - sb * sp1) * cr + (sb * cp1 + cb * sp1) * sr) * cdel;
    rp2p = ((cb * cp2 - sb * sp2) * cr - (sb * cp2 + cb * sp2) * sr) * cdel;
    rm2m = ((cb * cp2 + sb * sp2) * cr + (sb * cp2 - cb * sp2) * sr) * cdel;
    rm1p = ((cb * cp1 + sb * sp1) * cr - (sb * cp1 - cb * sp1) * sr) * cdel;
    argl1 = fac4 * sdel * q;
    sl1 = sin(argl1);
/* Computing 2nd power */
    r__1 = sl1;
    cl1 = sqrt(1.f - r__1 * r__1);
    w1h1 = w1 * cl1 + w2 * sl1;
    w2h1 = w2 * cl1 - w1 * sl1;
    w3h1 = w3 * cl1 + w4 * sl1;
    w4h1 = w4 * cl1 - w3 * sl1;
    argl2 = fak * 2.f * sdel * q;
    sl2 = sin(argl2);
/* Computing 2nd power */
    r__1 = sl2;
    cl2 = sqrt(1.f - r__1 * r__1);
    w1h2 = w1 * cl2 + w2 * sl2;
    w2h2 = w2 * cl2 - w1 * sl2;
    w3h2 = w3 * cl2 + w4 * sl2;
    w4h2 = w4 * cl2 - w3 * sl2;
    u1 = 1.f - (q * sdel + t * rp1m);
    u2 = 1.f - (q * sdel + t * rp2p);
    u3 = 1.f - (q * sdel + t * rm2m);
    u4 = 1.f - (q * sdel + t * rm1p);
    c11 = cos(fac2 * u1);
    s11 = sin(fac2 * u1);
    c22 = cos(fak * u2);
    s22 = sin(fak * u2);
    c23 = cos(fak * u3);
    s23 = sin(fak * u3);
    c14 = cos(fac2 * u4);
    s14 = sin(fac2 * u4);
    u1g = 1.f / (q * sdel + 1.f - t * rp1m);
    u2g = 1.f / (q * sdel + 1.f - t * rp2p);
    u3g = 1.f / (q * sdel + 1.f - t * rm2m);
    u4g = 1.f / (q * sdel + 1.f - t * rm1p);
    vr1 = (1.f - c11) / u1;
    vi1 = s11 / u1;
    vr2 = (1.f - c22) / u2;
    vi2 = s22 / u2;
    vr3 = (1.f - c23) / u3;
    vi3 = s23 / u3;
    vr4 = (1.f - c14) / u4;
    vi4 = s14 / u4;
    vr1g = (w3 * (1.f - c11) - w4 * s11) * u1g;
    vr2g = (w3 * (1.f - c22) - w4 * s22) * u2g;
    vr3g = (w3 * (1.f - c23) - w4 * s23) * u3g;
    vr4g = (w3 * (1.f - c14) - w4 * s14) * u4g;
    vr5g = (w3h2 * (1.f - c11) - w4h2 * s11) * u1g;
    vr6g = (w3h1 * (1.f - c22) - w4h1 * s22) * u2g;
    vr7g = (w3h1 * (1.f - c23) - w4h1 * s23) * u3g;
    vr8g = (w3h2 * (1.f - c14) - w4h2 * s14) * u4g;
    vi1g = (w3 * s11 + w4 * (1.f - c11)) * u1g;
    vi2g = (w3 * s22 + w4 * (1.f - c22)) * u2g;
    vi3g = (w3 * s23 + w4 * (1.f - c23)) * u3g;
    vi4g = (w3 * s14 + w4 * (1.f - c14)) * u4g;
    vi5g = (w3h2 * s11 + w4h2 * (1.f - c11)) * u1g;
    vi6g = (w3h1 * s22 + w4h1 * (1.f - c22)) * u2g;
    vi7g = (w3h1 * s23 + w4h1 * (1.f - c23)) * u3g;
    vi8g = (w3h2 * s14 + w4h2 * (1.f - c14)) * u4g;
    vr1h = (w1 * (1.f - c11) - w2 * s11) * u1g;
    vr2h = (w1 * (1.f - c22) - w2 * s22) * u2g;
    vr3h = (w1 * (1.f - c23) - w2 * s23) * u3g;
    vr4h = (w1 * (1.f - c14) - w2 * s14) * u4g;
    vr5h = (w1h2 * (1.f - c11) - w2h2 * s11) * u1g;
    vr6h = (w1h1 * (1.f - c22) - w2h1 * s22) * u2g;
    vr7h = (w1h1 * (1.f - c23) - w2h1 * s23) * u3g;
    vr8h = (w1h2 * (1.f - c14) - w2h2 * s14) * u4g;
    vi1h = (w1 * s11 + w2 * (1.f - c11)) * u1g;
    vi2h = (w1 * s22 + w2 * (1.f - c22)) * u2g;
    vi3h = (w1 * s23 + w2 * (1.f - c23)) * u3g;
    vi4h = (w1 * s14 + w2 * (1.f - c14)) * u4g;
    vi5h = (w1h2 * s11 + w2h2 * (1.f - c11)) * u1g;
    vi6h = (w1h1 * s22 + w2h1 * (1.f - c22)) * u2g;
    vi7h = (w1h1 * s23 + w2h1 * (1.f - c23)) * u3g;
    vi8h = (w1h2 * s14 + w2h2 * (1.f - c14)) * u4g;
    e1r = (vr1 - vr1g) * q * rp1m - (vr1 + vr1g) * sdel * t;
    e1i = (vi1 - vi1g) * q * rp1m - (vi1 + vi1g) * sdel * t;
    e2r = (vr2 - vr2g) * q * rp2p - (vr2 + vr2g) * sdel * t;
    e2i = (vi2 - vi2g) * q * rp2p - (vi2 + vi2g) * sdel * t;
    e3r = -(vr3 - vr3g) * q * rm2m + (vr3 + vr3g) * sdel * t;
    e3i = -(vi3 - vi3g) * q * rm2m + (vi3 + vi3g) * sdel * t;
    e4r = -(vr4 - vr4g) * q * rm1p + (vr4 + vr4g) * sdel * t;
    e4i = -(vi4 - vi4g) * q * rm1p + (vi4 + vi4g) * sdel * t;
    e5r = -c23 * ((vr1 - vr5g) * q * rp1m - (vr1 + vr5g) * sdel * t);
    e5r -= s23 * ((vi1 - vi5g) * q * rp1m - (vi1 + vi5g) * sdel * t);
    e5i = -c23 * ((vi1 - vi5g) * q * rp1m - (vi1 + vi5g) * sdel * t);
    e5i += s23 * ((vr1 - vr5g) * q * rp1m - (vr1 + vr5g) * sdel * t);
    e6r = -c14 * ((vr2 - vr6g) * q * rp2p - (vr2 + vr6g) * sdel * t);
    e6r -= s14 * ((vi2 - vi6g) * q * rp2p - (vi2 + vi6g) * sdel * t);
    e6i = -c14 * ((vi2 - vi6g) * q * rp2p - (vi2 + vi6g) * sdel * t);
    e6i += s14 * ((vr2 - vr6g) * q * rp2p - (vr2 + vr6g) * sdel * t);
    e7r = c11 * ((vr3 - vr7g) * q * rm2m - (vr3 + vr7g) * sdel * t);
    e7r += s11 * ((vi3 - vi7g) * q * rm2m - (vi3 + vi7g) * sdel * t);
    e7i = c11 * ((vi3 - vi7g) * q * rm2m - (vi3 + vi7g) * sdel * t);
    e7i -= s11 * ((vr3 - vr7g) * q * rm2m - (vr3 + vr7g) * sdel * t);
    e8r = c22 * ((vr4 - vr8g) * q * rm1p - (vr4 + vr8g) * sdel * t);
    e8r += s22 * ((vi4 - vi8g) * q * rm1p - (vi4 + vi8g) * sdel * t);
    e8i = c22 * ((vi4 - vi8g) * q * rm1p - (vi4 + vi8g) * sdel * t);
    e8i -= s22 * ((vr4 - vr8g) * q * rm1p - (vr4 + vr8g) * sdel * t);
    ethr = e1r + e2r + e3r + e4r + e5r + e6r + e7r + e8r;
    ethi = e1i + e2i + e3i + e4i + e5i + e6i + e7i + e8i;
    sp1m = (sb * cp1 + cb * sp1) * cr - (cb * cp1 - sb * sp1) * sr;
    sp2p = (sb * cp2 + cb * sp2) * cr + (cb * cp2 - sb * sp2) * sr;
    sm2m = (sb * cp2 - cb * sp2) * cr - (cb * cp2 + sb * sp2) * sr;
    sm1p = (sb * cp1 - cb * sp1) * cr + (cb * cp1 + sb * sp1) * sr;
    p1r = -(vr1 + vr1h) * sp1m;
    p1i = -(vi1 + vi1h) * sp1m;
    p2r = -(vr2 + vr2h) * sp2p;
    p2i = -(vi2 + vi2h) * sp2p;
    p3r = (vr3 + vr3h) * sm2m;
    p3i = (vi3 + vi3h) * sm2m;
    p4r = (vr4 + vr4h) * sm1p;
    p4i = (vi4 + vi4h) * sm1p;
    p5r = ((vr1 + vr5h) * c23 + (vi1 + vi5h) * s23) * sp1m;
    p5i = ((vi1 + vi5h) * c23 - (vr1 + vr5h) * s23) * sp1m;
    p6r = ((vr2 + vr6h) * c14 + (vi2 + vi6h) * s14) * sp2p;
    p6i = ((vi2 + vi6h) * c14 - (vr2 + vr6h) * s14) * sp2p;
    p7r = -((vr3 + vr7h) * c11 + (vi3 + vi7h) * s11) * sm2m;
    p7i = -((vi3 + vi7h) * c11 - (vr3 + vr7h) * s11) * sm2m;
    p8r = -((vr4 + vr8h) * c22 + (vi4 + vi8h) * s22) * sm1p;
    p8i = -((vi4 + vi8h) * c22 - (vr4 + vr8h) * s22) * sm1p;
    ephr = (p1r + p2r + p3r + p4r + p5r + p6r + p7r + p8r) * cdel;
    r__1 = (p1i + p2i + p3i + p4i + p5i + p6i + p7i + p8i) * cdel;
    ephi.r = r__1, ephi.i = 0.f;
    r__1 = ethr * ethr + ethi * ethi + ephr * ephr;
    q__3.r = ephi.r * ephi.r - ephi.i * ephi.i, q__3.i = ephi.r * ephi.i + 
	    ephi.i * ephi.r;
    q__2.r = r__1 + q__3.r, q__2.i = q__3.i;
    q__1.r = q__2.r * .0296f, q__1.i = q__2.i * .0296f;
    *rain = q__1.r;
    *eff = -1.7f;
/* .....CALCULATES DECIBELS............................................... */
L615:
    if (*rain <= rain_min__) {
	*rain = rain_min__;
    }
    *rain = r_lg10(rain) * 10.f;
/* . . .ADD ADDITIONAL GAIN FOR ANTENNA TYPES 2(VERTICAL), 3(1/2 WAVE */
/*     DIPOLE), AND 5(VERTICAL DIPOLE). . . . . . . . . . . . . . . . . . */
    if (*kop == 2) {
	*rain += h__;
    }
    if (*kop == 3 || *kop == 5) {
	*rain += phi;
    }
    if (*rain < floor) {
	*rain = floor;
    }
/* L620: */
    raine = *rain + *eff;
    if (raine >= floor) {
	goto L625;
    }
    raine = floor;
/* cc      EFF = RAINE - RAIN */
L625:
    *rain = raine;
/* .....NORMAL EXIT....................................................... */
L630:
    return 0;
/* .....ERROR EXIT........................................................ */
L635:
    s_wsfe(&io___513);
    e_wsfe();
L640:
    s_stop("", (ftnlen)0);



    return 0;
} /* mufesgan_ */

