/* GAINREL.f -- translated by f2c (version 20240504).
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
    real d1, e1, f1, p1, q1, s1, beta, rlambda;
} general_;

#define general_1 general_

struct {
    real cpfr, cp11, fr1, h1, pfr, p11, p11s, q2, r2, r3, sl;
} cros_;

#define cros_1 cros_

struct {
    real uust;
    integer nat;
    real ah1, bh1;
} ccparm_;

#define ccparm_1 ccparm_

struct {
    real w3[91], w4[91], w5[91], w6[91], w9[91], w10[91];
} warr_;

#define warr_1 warr_

struct {
    real ww1[2821]	/* was [91][31] */, ww2[2821]	/* was [91][31] */, 
	    ww3[2821]	/* was [91][31] */, ww4[2821]	/* was [91][31] */;
} wwar_;

#define wwar_1 wwar_

struct {
    real fi[35], rim[35], x[35], y[35];
    integer iek[35];
    real rl[35], h__[30];
} logp_;

#define logp_1 logp_

struct {
    real a[362], b[362];
} trig_;

#define trig_1 trig_

struct {
    real ro, costh, sinth, rnumb, gamma, epq;
} surf_;

#define surf_1 surf_

/* Table of constant values */

static real c_b2 = 360.f;

/* Subroutine */ int gainrel_(integer *iant, real *u, real *v, real *z9)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3, r__4;

    /* Builtin functions */
    double r_mod(real *, real *), cos(doublereal), sqrt(doublereal), sin(
	    doublereal);

    /* Local variables */
    static integer i__, k;
    static real a0, b0, a1, b1, b2, b3, a2, a3, a4, b4, a5, b5, w0, u1, u2, 
	    z1, z2, z3, w7, w8, z4, u3, u4, t5, t6, a6, b6, t7, c2, d2, c3, 
	    d3, c4, d4, a11, a12, r1, a7, b7, r4, h4, df, h5, r5, fg, am, an, 
	    bn, bm, r6;
    static integer il;
    static real w1, w2, u12, u13, ft, aw, bw;
    static integer jv, kv;
    static real fx, fy, wi, tr, ti, ur, wr, ui, h6, w00, aa1, bb1, w3x, w4x, 
	    w3y, w4y, w8x, w8y, w9x, w9y, efi, pfb, fij, asl, sfi, fir, sfr, 
	    fti, sti, w31x, w41x, w71x, w71y, str, w72y, w72x, w81x, w91x, 
	    w711x, w721x, pfra, pfrb, delta, etheta;


/*    RELATIVE GAIN CALCULATION  SUBROUTINE */
/*          iant = antenna type index number [1-10] */
/*          u    = elevation angle [0-90] */
/*          v    = off azimuth angle [0-360] */
/*          z9   = returned relative gain */



    *z9 = 0.f;
    if (*iant == 0) {
	return 0;
    }
    a0 = trig_1.a[(integer) (*u)];
    b0 = trig_1.b[(integer) (*u)];
    if (*v >= 0.f && *v <= 90.f || *v >= 360.f && *v <= 450.f) {
	kv = r_mod(v, &c_b2);
	jv = kv;
	a1 = trig_1.a[jv];
	b1 = trig_1.b[jv];
    } else if (*v > 90.f && *v <= 180.f || *v > 450.f && *v <= 540.f) {
	kv = r_mod(v, &c_b2);
	jv = 180 - kv;
	a1 = trig_1.a[jv];
	b1 = -trig_1.b[jv];
    } else if (*v > 180.f && *v <= 270.f) {
	jv = *v - 180;
	a1 = -trig_1.a[jv];
	b1 = -trig_1.b[jv];
    } else {
	jv = 360 - *v;
	a1 = -trig_1.a[jv];
	b1 = trig_1.b[jv];
    }
    a11 = a1 * b0;
    a12 = b1 * b0;


    if (*iant == 1) {
/* =========================================================================== */
/*       MULTIBAND APERIODIC REFL. DIPOLE ARRAY */
/* ========================================================================== */
	b2 = cos(cros_1.p11 * a11) - cros_1.cp11;
	w0 = (r__1 = 1 - a11 * a11, dabs(r__1));
	z1 = b2 / w0;
	fx = cros_1.fr1 * b0;
	fy = 1 / (fx * fx) + 1;
	cros_1.q2 = 1 - 1 / sqrt(fy);
	kv = r_mod(v, &c_b2);
	if (kv < 90 || kv > 270) {
/* Computing 2nd power */
	    r__2 = cros_1.q2;
	    z2 = sqrt((r__1 = r__2 * r__2 + 1 - cros_1.q2 * 2 * cos(
		    cros_1.p11s * b0 * b1), dabs(r__1)));
	} else {
	    z2 = 1 - cros_1.q2;
	}
	pfb = cros_1.pfr * b0;
	asl = a1 - cros_1.sl;
	pfrb = pfb * asl;
	u1 = 0.f;
	u2 = 0.f;
	i__1 = cros_1.r2 - 1;
	for (il = 0; il <= i__1; ++il) {
	    u12 = pfrb * il;
	    an = sin(u12);
	    u2 += an;
	    bn = cos(u12);
	    u1 += bn;
/* L6100: */
	}
	z3 = sqrt(u1 * u1 + u2 * u2);
	w7 = a1 * a0;
	w7 = w7 * w7 * (warr_1.w4[(integer) (*u)] * warr_1.w4[(integer) (*u)] 
		+ warr_1.w3[(integer) (*u)] * warr_1.w3[(integer) (*u)]);
	w8 = b1 * b1 * (warr_1.w5[(integer) (*u)] * warr_1.w5[(integer) (*u)] 
		+ warr_1.w6[(integer) (*u)] * warr_1.w6[(integer) (*u)]);
	z4 = sqrt((r__1 = w7 + w8, dabs(r__1)));
	*z9 = z1 * z2 * z3 * z4;


    } else if (*iant == 2) {
/* ========================================================================= */
/*       DUAL-BAND CENTRE-FED TUNED REFL. DIPOLE ARRAY */
/* ========================================================================= */
	pfb = cros_1.pfr * b0;
	b2 = cos(cros_1.p11 * a11) - cros_1.cp11;
	w0 = (r__1 = 1 - a11 * a11, dabs(r__1));
	z1 = b2 / w0;
/* Computing 2nd power */
	r__2 = cros_1.q2;
	z2 = sqrt((r__1 = r__2 * r__2 + 1 + cros_1.q2 * 2 * cos(cros_1.p11 - 
		cros_1.p11 * b0 * b1), dabs(r__1)));
	asl = a1 - cros_1.sl;
	pfrb = pfb * asl;
	u1 = 0.f;
	u2 = 0.f;
	i__1 = cros_1.r2 - 1;
	for (il = 0; il <= i__1; ++il) {
	    u12 = pfrb * il;
	    an = sin(u12);
	    u2 += an;
	    bn = cos(u12);
	    u1 += bn;
/* L6200: */
	}
	z3 = sqrt(u1 * u1 + u2 * u2);
	w7 = a1 * a0;
	w7 = w7 * w7 * (warr_1.w4[(integer) (*u)] * warr_1.w4[(integer) (*u)] 
		+ warr_1.w3[(integer) (*u)] * warr_1.w3[(integer) (*u)]);
	w8 = b1 * b1 * (warr_1.w5[(integer) (*u)] * warr_1.w5[(integer) (*u)] 
		+ warr_1.w6[(integer) (*u)] * warr_1.w6[(integer) (*u)]);
	z4 = sqrt((r__1 = w7 + w8, dabs(r__1)));
	*z9 = z1 * z2 * z3 * z4;


    } else if (*iant == 3) {
/* ========================================================================= */
/*       DUAL-BAND END-FED TUNED REFL. DIPOLE ARRAY */
/* ========================================================================= */
	b2 = cos(cros_1.pfr * a11) - cros_1.cpfr;
	w0 = (r__1 = 1 - a11 * a11, dabs(r__1));
	z1 = b2 / w0;
/* Computing 2nd power */
	r__2 = cros_1.q2;
	z2 = sqrt((r__1 = r__2 * r__2 + 1 + cros_1.q2 * 2 * cos(cros_1.p11 - 
		cros_1.p11 * b0 * b1), dabs(r__1)));
	pfb = cros_1.pfr * b0 * 2;
	asl = a1 - cros_1.sl;
	pfrb = pfb * asl;
	u1 = 0.f;
	u2 = 0.f;
	i__1 = cros_1.r2 / 2.f - 1;
	for (il = 0; il <= i__1; ++il) {
	    u12 = pfrb * il;
	    an = sin(u12);
	    u2 += an;
	    bn = cos(u12);
	    u1 += bn;
/* L6300: */
	}
	z3 = sqrt(u1 * u1 + u2 * u2);
	w7 = a1 * a0;
	w7 = w7 * w7 * (warr_1.w4[(integer) (*u)] * warr_1.w4[(integer) (*u)] 
		+ warr_1.w3[(integer) (*u)] * warr_1.w3[(integer) (*u)]);
	w8 = b1 * b1 * (warr_1.w5[(integer) (*u)] * warr_1.w5[(integer) (*u)] 
		+ warr_1.w6[(integer) (*u)] * warr_1.w6[(integer) (*u)]);
	z4 = sqrt((r__1 = w7 + w8, dabs(r__1)));
	*z9 = z1 * z2 * z3 * z4;

    } else if (*iant == 4) {
/* ============================================================================ */
/*       TROPICAL ANTENNAS */
/* ============================================================================ */
	pfb = cros_1.pfr * b0;
	b2 = cos(cros_1.p11 * a11) - cros_1.cp11;
	w0 = (r__1 = 1 - a11 * a11, dabs(r__1));
	z1 = b2 / w0;
	pfra = pfb * b1;
	u3 = 0.f;
	u4 = 0.f;
	i__1 = cros_1.r3 - 1;
	for (il = 0; il <= i__1; ++il) {
	    u13 = pfra * il;
	    am = sin(u13);
	    u4 += am;
	    bm = cos(u13);
	    u3 += bm;
/* L6400: */
	}
	z2 = sqrt(u3 * u3 + u4 * u4);
	asl = a1 - cros_1.sl;
	pfrb = pfb * asl;
	u1 = 0.f;
	u2 = 0.f;
	i__1 = cros_1.r2 - 1;
	for (il = 0; il <= i__1; ++il) {
	    u12 = pfrb * il;
	    an = sin(u12);
	    u2 += an;
	    bn = cos(u12);
	    u1 += bn;
/* L6420: */
	}
	z3 = sqrt(u1 * u1 + u2 * u2);
	w7 = a1 * a0;
	w7 = w7 * w7 * (warr_1.w4[(integer) (*u)] * warr_1.w4[(integer) (*u)] 
		+ warr_1.w3[(integer) (*u)] * warr_1.w3[(integer) (*u)]);
	w8 = b1 * b1 * (warr_1.w5[(integer) (*u)] * warr_1.w5[(integer) (*u)] 
		+ warr_1.w6[(integer) (*u)] * warr_1.w6[(integer) (*u)]);
	z4 = sqrt((r__1 = w7 + w8, dabs(r__1)));
	*z9 = z1 * z2 * z3 * z4;


    } else if (*iant == 5) {
/* ========================================================================= */
/*       LOG-PERIODIC */
/* ========================================================================= */
	b3 = -a12 * surf_1.costh + a0 * surf_1.sinth;
	surf_1.gamma = general_1.beta * b3 / surf_1.costh;
/* =========================================================================== */
/*       HORIZONTAL LOG-PERIODIC */
/* =========================================================================== */
	df = 1 - b0 * b0 * a1 * a1;
	str = 0.f;
	sti = 0.f;
	sfr = 0.f;
	sfi = 0.f;
/*        write(*,6450)nat */
/* 6450   format(' nat = ',i4) */
/*        write(*,6460)(iek(jj),jj=1,nat) */
/* 6460   format(' iek = ',25i3) */
/*        write(*,6470)'rl',rl */
/* 6470   format(' ',a2,' = ',25f4.1) */
/*        write(*,6470)'x',x */
/*        write(*,6470)'fi',fi */
/*        write(*,6470)'ri',rim */
	i__1 = ccparm_1.nat;
	for (k = 1; k <= i__1; ++k) {
	    i__ = logp_1.iek[k - 1];
	    fg = general_1.beta * logp_1.rl[i__ - 1];
	    ft = (cos(fg * b0 * a1) - cos(fg)) / df;
	    aw = sin(surf_1.gamma * logp_1.x[i__ - 1] + logp_1.fi[i__ - 1] * 
		    general_1.q1);
	    bw = cos(surf_1.gamma * logp_1.x[i__ - 1] + logp_1.fi[i__ - 1] * 
		    general_1.q1);
	    wr = aw * wwar_1.ww1[(integer) (*u) + i__ * 91] - bw * wwar_1.ww2[
		    (integer) (*u) + i__ * 91];
	    wi = bw * wwar_1.ww1[(integer) (*u) + i__ * 91] + aw * wwar_1.ww2[
		    (integer) (*u) + i__ * 91];
	    tr = logp_1.rim[i__ - 1] * ft * wr;
	    ti = logp_1.rim[i__ - 1] * ft * wi;
	    str += tr;
	    sti += ti;
	    ur = bw * wwar_1.ww3[(integer) (*u) + i__ * 91] - aw * wwar_1.ww4[
		    (integer) (*u) + i__ * 91];
	    ui = aw * wwar_1.ww3[(integer) (*u) + i__ * 91] + bw * wwar_1.ww4[
		    (integer) (*u) + i__ * 91];
	    fir = logp_1.rim[i__ - 1] * ft * ur;
	    fij = logp_1.rim[i__ - 1] * ft * ui;
	    sfr += fir;
	    sfi += fij;
/* L6500: */
	}
/* Computing 2nd power */
	r__1 = str;
/* Computing 2nd power */
	r__2 = sti;
	etheta = sqrt(r__1 * r__1 + r__2 * r__2) * a1 * a0;
/* Computing 2nd power */
	r__1 = sfr;
/* Computing 2nd power */
	r__2 = sfi;
	efi = -sqrt(r__1 * r__1 + r__2 * r__2) * b1;
/* Computing 2nd power */
	r__1 = etheta;
/* Computing 2nd power */
	r__2 = efi;
	*z9 = sqrt(r__1 * r__1 + r__2 * r__2);


    } else if (*iant == 6) {
/* ========================================================================= */
/*       LOG-PERIODIC */
/* ========================================================================= */
	b3 = -a12 * surf_1.costh + a0 * surf_1.sinth;
	surf_1.gamma = general_1.beta * b3 / surf_1.costh;
/* =========================================================================== */
/*       VERTICAL LOG-PERIODIC */
/* =========================================================================== */
	delta = general_1.beta * a0;
	sfr = 0.f;
	sfi = 0.f;
	i__1 = ccparm_1.nat;
	for (k = 1; k <= i__1; ++k) {
	    i__ = logp_1.iek[k - 1];
	    fg = general_1.beta * logp_1.rl[i__ - 1];
	    ft = (cos(fg * a0) - cos(fg)) / b0;
	    aw = sin(surf_1.gamma * logp_1.y[i__ - 1] + logp_1.fi[i__ - 1] * 
		    general_1.q1);
	    bw = cos(surf_1.gamma * logp_1.y[i__ - 1] + logp_1.fi[i__ - 1] * 
		    general_1.q1);
	    ur = bw * wwar_1.ww1[(integer) (*u) + i__ * 91] - aw * wwar_1.ww2[
		    (integer) (*u) + i__ * 91];
	    ui = bw * wwar_1.ww2[(integer) (*u) + i__ * 91] + aw * wwar_1.ww1[
		    (integer) (*u) + i__ * 91];
	    fti = logp_1.rim[i__ - 1] * ft;
	    fir = fti * ur;
	    fij = fti * ui;
	    sfr += fir;
	    sfi += fij;
/* L6600: */
	}
/* Computing 2nd power */
	r__1 = sfr;
/* Computing 2nd power */
	r__2 = sfi;
	*z9 = sqrt(r__1 * r__1 + r__2 * r__2);


    } else if (*iant == 7) {
/* =========================================================================== */
/*       HORIZONTAL RHOMBIC */
/* =========================================================================== */
	a2 = surf_1.sinth * b1 + surf_1.costh * a1;
	b2 = surf_1.costh * b1 - surf_1.sinth * a1;
	a3 = surf_1.sinth * b1 - surf_1.costh * a1;
	b3 = surf_1.costh * b1 + surf_1.sinth * a1;
	t5 = a2 * b0 - 1;
	t6 = a3 * b0 - 1;
	a4 = a2 / t5;
	b4 = b2 / t5;
	a5 = a3 / t6;
	b5 = b3 / t6;
	a6 = a4 - a5;
	b6 = b4 + b5;
	t7 = t5 + t6;
	c2 = sin(cros_1.sl * t5);
	d2 = cos(cros_1.sl * t5);
	c3 = sin(cros_1.sl * t6);
	d3 = cos(cros_1.sl * t6);
	c4 = sin(cros_1.sl * t7);
	d4 = cos(cros_1.sl * t7);
	r1 = 1 - d3 - d2 + d4;
	cros_1.r2 = c4 - c3 - c2;
	a7 = sin(cros_1.h1 * a0);
	b7 = cos(cros_1.h1 * a0);
	cros_1.r3 = warr_1.w5[(integer) (*u)] * b7 + 1 + warr_1.w6[(integer) (
		*u)] * a7;
	r4 = warr_1.w5[(integer) (*u)] * a7 - warr_1.w6[(integer) (*u)] * b7;
	h4 = r1 * cros_1.r3 - cros_1.r2 * r4;
	h5 = r1 * r4 + cros_1.r2 * cros_1.r3;
	r5 = 1 - warr_1.w3[(integer) (*u)] * b7 - warr_1.w4[(integer) (*u)] * 
		a7;
	r6 = warr_1.w3[(integer) (*u)] * a7 - warr_1.w4[(integer) (*u)] * b7;
	w1 = r1 * r5 - cros_1.r2 * r6;
	w2 = r1 * r6 + cros_1.r2 * r5;
/* Computing 2nd power */
	r__1 = h4;
/* Computing 2nd power */
	r__2 = h5;
	h6 = b6 * 30 * sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
	r__1 = w1;
/* Computing 2nd power */
	r__2 = w2;
	w3x = a0 * 30 * a6 * sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
	r__1 = h6;
/* Computing 2nd power */
	r__2 = w3x;
	*z9 = sqrt(r__1 * r__1 + r__2 * r__2);


    } else if (*iant == 8 || *iant == 9) {
/* ========================================================================== */
/*       QUADRANT & CROSS-DIPOLE ANTENNAS */
/* ========================================================================== */
	aa1 = (b1 - a1) * .707f;
	bb1 = (b1 + a1) * .707f;
	a11 = aa1 * b0;
	a12 = bb1 * b0;
	b2 = cos(cros_1.p11 * a11) - cros_1.cp11;
	w0 = (r__1 = 1 - a11 * a11, dabs(r__1));
	z1 = b2 / w0;
	b3 = cos(cros_1.p11 * a12) - cros_1.cp11;
	b4 = cros_1.p11 * (bb1 - aa1) * b0;
	if (*iant == 8) {
	    b5 = sin(b4);
	    b4 = cos(b4);
	} else {
	    b5 = 0.f;
	    b4 = 1.f;
	}
	w0 = 1 - a11 * a11;
	w00 = 1 - a12 * a12;
	z2 = b3 / w00;
	w7 = aa1 * a0 * b0 * z1;
	w71y = w7 * warr_1.w9[(integer) (*u)];
	w72y = w7 * warr_1.w10[(integer) (*u)];
/* ******    modified 18/8/92 : b1 changed to bb1 ****** */
	w7 = -bb1 * a0 * b0 * z2;
	w711x = w7 * warr_1.w9[(integer) (*u)];
	w721x = w7 * warr_1.w10[(integer) (*u)];
	w71x = w711x * b4 - w721x * b5;
	w72x = w711x * b5 + w721x * b4;
	w7 = -bb1 * a0 * a0 * z2;
	w31x = w7 * warr_1.w3[(integer) (*u)];
	w41x = w7 * warr_1.w4[(integer) (*u)];
	w3x = w31x * b4 - w41x * b5;
	w4x = w31x * b5 + w41x * b4;
	w7 = aa1 * a0 * a0 * z1;
	w3y = w7 * warr_1.w3[(integer) (*u)];
	w4y = w7 * warr_1.w4[(integer) (*u)];
/* Computing 2nd power */
	r__1 = w3x + w3y;
/* Computing 2nd power */
	r__2 = w4x + w4y;
/* Computing 2nd power */
	r__3 = w71x + w71y;
/* Computing 2nd power */
	r__4 = w72x + w72y;
	w7 = r__1 * r__1 + r__2 * r__2 + r__3 * r__3 + r__4 * r__4;
	w81x = -aa1 * warr_1.w5[(integer) (*u)] * z2;
	w8y = -bb1 * warr_1.w5[(integer) (*u)] * z1;
	w91x = -aa1 * warr_1.w6[(integer) (*u)] * z2;
	w8x = w81x * b4 - w91x * b5;
	w9x = w81x * b5 + w91x * b4;
	w9y = -bb1 * warr_1.w6[(integer) (*u)] * z1;
/* Computing 2nd power */
	r__1 = w8x + w8y;
/* Computing 2nd power */
	r__2 = w9x + w9y;
	w8 = r__1 * r__1 + r__2 * r__2;
	*z9 = sqrt(w7 + w8);

    } else if (*iant == 10) {
/* ============================================================================ */
/*       VERTICAL MONOPOLE */
/* =========================================================================== */
	*z9 = warr_1.w9[(integer) (*u)] * warr_1.w10[(integer) (*u)];
    }
    return 0;
} /* gainrel_ */

