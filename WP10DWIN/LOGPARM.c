/* LOGPARM.f -- translated by f2c (version 20240504).
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
    real fi[35], rim[35], x[35], y[35];
    integer iek[35];
    real rl[35], h__[30];
} logp_;

#define logp_1 logp_

struct {
    real uust;
    integer nat;
    real ah1, bh1;
} ccparm_;

#define ccparm_1 ccparm_

struct {
    real ro, costh, sinth, rnumb, gamma, epq;
} surf_;

#define surf_1 surf_

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;

/* Subroutine */ int logparm_(integer *iant, integer *nel, real *rlnel, real *
	rl1, real *hnel, real *h1, real *dc, real *z0)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3;
    doublereal d__1, d__2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal), atan(
	    doublereal), sin(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    static real d__[30];
    static integer i__, k;
    static real h0, af, bf, aa1, aa2, aa3, da1, db1, dc1, aa4, aa5, bb1, bb2, 
	    bb3, bb4, dl1, bb5, cc1, cc2, cc3, cc4, cc5, tg3, rl0, z0m, bar, 
	    ria[30], tg23, shf, rld, rlc, exl, tau, rlr, alfa;
    static integer kmax;
    static real rinm, rlup, alfa2, alfa3, alfa23, sigma, fimin, theta, rllow, 
	    alftan;
    extern /* Subroutine */ int curcal_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *);
    static real riamax, thetan;

    /* Fortran I/O blocks */
    static cilist io___46 = { 0, 6, 0, 0, 0 };



/*       LOG-PERIODIC ANTENNA PARAMETERS CALCULATION */



/* cc        write(*,100)nel,rlnel,rl1,hnel,h1,dc,z0 */
/* cc  100   format(' nel,rlnel,rl1,hnel,h1,dc,z0 = ',I2,6f6.1) */

    logp_1.rl[*nel - 1] = *rlnel;
    logp_1.rl[0] = *rl1;
    logp_1.h__[*nel - 1] = *hnel;
    logp_1.h__[0] = *h1;
    rlr = *rl1 / *rlnel;
    exl = 1.f / (*nel - 1.f);
    d__1 = (doublereal) rlr;
    d__2 = (doublereal) exl;
    tau = pow_dd(&d__1, &d__2);
    rld = *rlnel - *rl1;
    surf_1.sinth = (*hnel - *h1) / *dc;
/* Computing 2nd power */
    r__1 = surf_1.sinth;
    surf_1.costh = sqrt(1 - r__1 * r__1);
/* cc        write(*,110)rlr,exl,tau,rld,sinth,costh */
/* cc  110   format(' rlr,exl,tau,rld,sinth,costh = ',6f6.1) */

    if (*iant != 5) {
/* =========================================================================== */
/*  CALC. ELEM. LENGTH L(I), HEIGHT H(I), DISTANCES D(I) - VERT.LOG-PERIODIC */
/* =========================================================================== */
	dl1 = *dc * *rl1 / rld;
	da1 = dl1 * surf_1.costh;
	db1 = dl1 * surf_1.sinth;
	dc1 = db1 - *rl1;
	tg23 = surf_1.sinth / surf_1.costh;
	alfa23 = atan(tg23);
	tg3 = dc1 / da1;
	alfa3 = atan(tg3);
	alfa2 = alfa23 - alfa3;
	sigma = (1 - tau) / ((surf_1.sinth - tg3 * surf_1.costh) * 4);
	theta = sin(alfa3) * surf_1.costh / sin(alfa2);
	logp_1.h__[*nel - 1] = logp_1.rl[*nel - 1] * (theta + 1);
	h0 = *h1 - *rl1 * (theta + 1);
	for (i__ = *nel - 1; i__ >= 1; --i__) {
	    logp_1.rl[i__ - 1] = logp_1.rl[i__] * tau;
	    d__[i__ - 1] = logp_1.rl[i__] * 4 * sigma;
	    logp_1.h__[i__ - 1] = logp_1.rl[i__ - 1] * (theta + 1) + h0;
/* L600: */
	}
	logp_1.y[0] = logp_1.rl[0] / (tg23 * (1 - tg3 / tg23));
	i__1 = *nel;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    logp_1.y[i__ - 1] = logp_1.y[i__ - 2] + d__[i__ - 2] * 
		    surf_1.costh;
/* L610: */
	}
    } else {
/* ============================================================================ */
/* CALC. ELEM. LENGTH L(I), HEIGHT H(I), DISTANCES D(I) - HORIZ.LOG-PERIODIC */
/* ============================================================================ */
	alftan = rld / *dc;
	thetan = surf_1.sinth / surf_1.costh;
	theta = atan(thetan);
	alfa = atan(alftan);
	sigma = (1 - tau) / (alftan * 4);
	d__[*nel - 1] = logp_1.rl[*nel - 1] * 4 * sigma;
	for (i__ = *nel - 1; i__ >= 1; --i__) {
	    logp_1.rl[i__ - 1] = logp_1.rl[i__] * tau;
	    d__[i__ - 1] = logp_1.rl[i__] * 4 * sigma;
/* L620: */
	}
	logp_1.x[0] = logp_1.rl[0] / alftan * surf_1.costh;
	i__1 = *nel;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    logp_1.x[i__ - 1] = logp_1.x[i__ - 2] + d__[i__ - 2] * 
		    surf_1.costh;
	    logp_1.h__[i__ - 1] = logp_1.h__[i__ - 2] + d__[i__ - 2] * 
		    surf_1.sinth;
/* L630: */
	}
    }
/* ============================================================================ */
/*       CALCULATION OF LC, LLOW, LUP AND L0 ( l/a = 500 is assumed ) */
/* ============================================================================ */
    z0m = *z0 / 1000;
/* Computing 2nd power */
    r__1 = z0m;
/* Computing 3rd power */
    r__2 = z0m;
/* Computing 4th power */
    r__3 = z0m, r__3 *= r__3;
    shf = 1.098790227f - z0m * 1.055146365f + r__1 * r__1 * 3.208544524f - 
	    r__2 * (r__2 * r__2) * 5.766460847f + r__3 * r__3 * 4.054233788f;
    rlc = general_1.rlambda * shf / 4.f;
    bar = sigma * 30.7f * (1 - tau) + 1.1f;
    rllow = rlc / bar;
    rlup = rlc * 1.1f;
/* cc        write(*,200)rllow,rlup */
/* cc  200   format(' rllow,rlup = ',2f6.1) */
    rl0 = rllow + (rlc - rllow) * .7166f;
/* ============================================================================ */
/*       DETERMINATION OF INDEX EK(I) OF ELEMENTS FALLING IN LLOW - LUP RANGE */
/* ============================================================================ */
    k = 0;
    i__1 = *nel;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (logp_1.rl[i__ - 1] >= rllow && logp_1.rl[i__ - 1] <= rlup) {
	    ++k;
	    logp_1.iek[k - 1] = i__;
	}
/* L650: */
    }
    ccparm_1.nat = k;
/* cc        write(*,220)nat */
/* cc  220   format(' nat = ',i2) */
/* cc        read(*,230)iii */
/* cc  230   format(i1) */
/* ============================================================================ */
/*       CALCULATION OF CURRENT IA(I) AND PHASE FI(I) OF ACTIVE ELEMENTS */
/* ============================================================================ */
    curcal_(&rl0, &rllow, &rlc, &rlup, &aa1, &aa2, &aa3, &aa4, &aa5, &bb1, &
	    bb2, &bb3, &bb4, &bb5, &cc1, &cc2, &cc3, &cc4, &cc5);
    i__1 = ccparm_1.nat;
    for (k = 1; k <= i__1; ++k) {
	i__ = logp_1.iek[k - 1];
	if (logp_1.rl[i__ - 1] >= rllow && logp_1.rl[i__ - 1] < rllow + (rl0 
		- rllow) / 2.f) {
/* Computing 2nd power */
	    r__1 = logp_1.rl[i__ - 1];
	    ria[i__ - 1] = aa1 * (r__1 * r__1) + bb1 * logp_1.rl[i__ - 1] + 
		    cc1;
	} else if (logp_1.rl[i__ - 1] >= rllow + (rl0 - rllow) / 2.f && 
		logp_1.rl[i__ - 1] < rllow + (rl0 - rllow) * 3.f / 4.f) {
/* Computing 2nd power */
	    r__1 = logp_1.rl[i__ - 1];
	    ria[i__ - 1] = aa2 * (r__1 * r__1) + bb2 * logp_1.rl[i__ - 1] + 
		    cc2;
	} else if (logp_1.rl[i__ - 1] >= rllow + (rl0 - rllow) * 3 / 4.f && 
		logp_1.rl[i__ - 1] <= rl0) {
/* Computing 2nd power */
	    r__1 = logp_1.rl[i__ - 1];
	    ria[i__ - 1] = aa3 * (r__1 * r__1) + bb3 * logp_1.rl[i__ - 1] + 
		    cc3;
	} else if (logp_1.rl[i__ - 1] >= rl0 && logp_1.rl[i__ - 1] <= rlc) {
/* Computing 2nd power */
	    r__1 = logp_1.rl[i__ - 1];
	    ria[i__ - 1] = aa4 * (r__1 * r__1) + bb4 * logp_1.rl[i__ - 1] + 
		    cc4;
	} else if (logp_1.rl[i__ - 1] >= rlc && logp_1.rl[i__ - 1] <= rlup) {
/* Computing 2nd power */
	    r__1 = logp_1.rl[i__ - 1];
	    ria[i__ - 1] = aa5 * (r__1 * r__1) + bb5 * logp_1.rl[i__ - 1] + 
		    cc5;
	} else {
	    s_wsle(&io___46);
	    do_lio(&c__9, &c__1, "current calculation error!", (ftnlen)26);
	    e_wsle();
	}
	if (logp_1.rl[i__ - 1] >= rllow && logp_1.rl[i__ - 1] <= rl0) {
	    af = 150 / (rl0 - rllow);
	} else {
	    af = 142 / (rlup - rl0);
	}
	bf = -af * rl0;
	logp_1.fi[i__ - 1] = af * logp_1.rl[i__ - 1] + bf;
/* L900: */
    }
/* ============================================================================ */
/*       CALCULATION OF NORMALIZED CURRENT IM(I) TO IMAX=1 AND PHASES FI(I) */
/* ============================================================================ */
    kmax = 0;
    riamax = 0.f;
    i__1 = ccparm_1.nat;
    for (k = 1; k <= i__1; ++k) {
	i__ = logp_1.iek[k - 1];
	if (ria[i__ - 1] >= riamax) {
	    kmax = i__;
	    riamax = ria[i__ - 1];
	    fimin = logp_1.fi[i__ - 1];
	}
/* L960: */
    }
    i__1 = ccparm_1.nat;
    for (k = 1; k <= i__1; ++k) {
	i__ = logp_1.iek[k - 1];
	rinm = ria[i__ - 1] / riamax;
	logp_1.fi[i__ - 1] -= fimin;
	logp_1.rim[i__ - 1] = rinm / sin(general_1.beta * logp_1.rl[i__ - 1]);
/* L980: */
    }
    return 0;
} /* logparm_ */

