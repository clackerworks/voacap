/* PARMPREC.f -- translated by f2c (version 20240504).
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
    real w3[91], w4[91], w5[91], w6[91], w9[91], w10[91];
} warr_;

#define warr_1 warr_

struct {
    real ww1[2821]	/* was [91][31] */, ww2[2821]	/* was [91][31] */, 
	    ww3[2821]	/* was [91][31] */, ww4[2821]	/* was [91][31] */;
} wwar_;

#define wwar_1 wwar_

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
    real fi[35], rim[35], x[35], y[35];
    integer iek[35];
    real rl[35], h__[30];
} logp_;

#define logp_1 logp_

struct {
    real ro, costh, sinth, rnumb, gamma, epq;
} surf_;

#define surf_1 surf_

struct {
    real a[362], b[362];
} trig_;

#define trig_1 trig_

/* Subroutine */ int parmprec_(integer *iant, integer *iperf)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);
    integer i_nint(real *);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, k;
    static real u, a0, b0, f4, t1, w1[91], w2[91], t2, t3, t4, x0, y0, s4, 
	    h11, am, bm, hh, sa;
    static integer il;
    static real au[31], bu[31], sb;
    static integer jj;
    static real w31, w32, w33, w34, qx, qy, sx, sy, xx, yy, a1h, b1h, bj1, 
	    dx0, dy0, q0x, w0y, alf, bta, q0j1, w0j1, rik, psi, pfra, pfrh, 
	    delta, theti, thetr, fteta0;
    extern /* Subroutine */ int refcof_(real *, real *, real *, real *, real *
	    , real *, real *, real *);
    static real dlteta;
    extern /* Subroutine */ int bessel_(real *, real *), surfim_(real *, real 
	    *, real *);





    for (u = 0.f; u <= 90.f; u += 1.f) {
/*      ,uust */

	b0 = trig_1.b[(integer) u];
	a0 = trig_1.a[(integer) u];

	if (*iant <= 4 || *iant == 8 || *iant == 9) {
	    pfra = cros_1.pfr * a0 * 2;
	    w1[(integer) u] = 0.f;
	    w2[(integer) u] = 0.f;
	    if (*iant >= 4) {
		pfrh = pfra * cros_1.h1;
		w1[(integer) u] = cos(pfrh);
		w2[(integer) u] = sin(pfrh);
	    } else {
		r__1 = cros_1.r3 - 1;
		i__1 = i_nint(&r__1);
		for (il = 0; il <= i__1; ++il) {
		    rik = il / 2.f;
		    h11 = (cros_1.h1 + rik) * pfra;
		    am = sin(h11);
		    w2[(integer) u] += am;
		    bm = cos(h11);
		    w1[(integer) u] += bm;
/* L4004: */
		}
	    }
/* =========================================================================== */
/*       CALCUL. ON PERFECT GROUND (PERF%=1) (Rv = T1+jT2 = 1, Rh = T3+jT4= -1) */
/* =========================================================================== */
	    if (*iperf != 0) {
		warr_1.w3[(integer) u] = 0.f;
		warr_1.w4[(integer) u] = w2[(integer) u] * 2;
		warr_1.w5[(integer) u] = 0.f;
		warr_1.w6[(integer) u] = w2[(integer) u] * 2;
		warr_1.w9[(integer) u] = w1[(integer) u] * 2;
		warr_1.w10[(integer) u] = 0.f;
	    } else {
/* =========================================================================== */
/*       CALCULATION ON IMPERFECT GROUND (PERF%=0) */
/* =========================================================================== */
		refcof_(&a0, &b0, &general_1.d1, &general_1.e1, &t1, &t2, &t3,
			 &t4);
		w31 = 1 - t1;
		w32 = t1 + 1;
		w33 = t3 + 1;
		w34 = 1 - t3;
		warr_1.w3[(integer) u] = w31 * w1[(integer) u] - t2 * w2[(
			integer) u];
		warr_1.w4[(integer) u] = w32 * w2[(integer) u] - t2 * w1[(
			integer) u];
		warr_1.w5[(integer) u] = w33 * w1[(integer) u] + t4 * w2[(
			integer) u];
		warr_1.w6[(integer) u] = w34 * w2[(integer) u] + t4 * w1[(
			integer) u];

		warr_1.w9[(integer) u] = w32 * w1[(integer) u] + t2 * w2[(
			integer) u];
		warr_1.w10[(integer) u] = w31 * w2[(integer) u] + t2 * w1[(
			integer) u];
	    }
	} else if (*iant == 5 || *iant == 6) {
/* ========================================================================== */
/*       LOG-PERIODIC ANT. PARAM. */
/* ========================================================================== */
	    delta = general_1.beta * 2 * a0;
	    if (*iant == 6) {
		delta /= 2.f;
	    }
	    i__1 = ccparm_1.nat;
	    for (k = 1; k <= i__1; ++k) {
		i__ = logp_1.iek[k - 1];
		au[i__] = sin(delta * logp_1.h__[i__ - 1]);
		bu[i__] = cos(delta * logp_1.h__[i__ - 1]);
		if (*iperf != 0) {
		    if (*iant == 6) {
			wwar_1.ww1[(integer) u + i__ * 91] = bu[i__] * 2;
			wwar_1.ww2[(integer) u + i__ * 91] = 0.f;
		    } else {
			wwar_1.ww1[(integer) u + i__ * 91] = 1.f - bu[i__];
/*  changed 11/8/91 from Rossi */
			wwar_1.ww3[(integer) u + i__ * 91] = 1.f - bu[i__];
/*  changed 11/8/91 */
			wwar_1.ww2[(integer) u + i__ * 91] = au[i__];
			wwar_1.ww4[(integer) u + i__ * 91] = au[i__];
		    }
		} else {
		    refcof_(&a0, &b0, &general_1.d1, &general_1.e1, &t1, &t2, 
			    &t3, &t4);
		    if (*iant == 6) {
			wwar_1.ww1[(integer) u + i__ * 91] = (t1 + 1) * bu[
				i__] + t2 * au[i__];
			wwar_1.ww2[(integer) u + i__ * 91] = (1 - t1) * au[
				i__] + t2 * bu[i__];
		    } else {
			wwar_1.ww1[(integer) u + i__ * 91] = 1 - t1 * bu[i__] 
				- t2 * au[i__];
			wwar_1.ww2[(integer) u + i__ * 91] = t1 * au[i__] - 
				t2 * bu[i__];
			wwar_1.ww3[(integer) u + i__ * 91] = t3 * bu[i__] + 1 
				+ t4 * au[i__];
			wwar_1.ww4[(integer) u + i__ * 91] = t4 * bu[i__] - 
				t3 * au[i__];
		    }
		}
/* L4012: */
	    }
	} else if (*iant == 7) {
/* ========================================================================== */
/*       RHOMBIC ANTENNAS */
/* ========================================================================== */
	    if (*iperf != 0) {
		warr_1.w3[(integer) u] = 1.f;
		warr_1.w4[(integer) u] = 0.f;
		warr_1.w5[(integer) u] = -1.f;
		warr_1.w6[(integer) u] = 0.f;
	    } else {
		refcof_(&a0, &b0, &general_1.d1, &general_1.e1, &t1, &t2, &t3,
			 &t4);
		warr_1.w3[(integer) u] = t1;
		warr_1.w4[(integer) u] = t2;
		warr_1.w5[(integer) u] = t3;
		warr_1.w6[(integer) u] = t4;
	    }
	} else if (*iant == 10) {
/* ========================================================================== */
/*       VERTICAL MONOPOLE */
/* ========================================================================== */
	    a1h = sin(cros_1.h1 * a0);
	    b1h = cos(cros_1.h1 * a0);
	    if (*iperf != 0) {
		warr_1.w9[(integer) u] = (r__1 = (b1h - ccparm_1.bh1) / b0, 
			dabs(r__1));
		warr_1.w10[(integer) u] = 1.f;
	    } else {
		refcof_(&a0, &b0, &general_1.d1, &general_1.e1, &t1, &t2, &t3,
			 &t4);
		thetr = -ccparm_1.ah1 * t2 * a0 + (b1h - ccparm_1.bh1) * (t1 
			+ 1) + a1h * t2;
		theti = (1 - t1) * (a1h - ccparm_1.ah1 * a0) + t2 * (b1h - 
			ccparm_1.bh1);
		warr_1.w9[(integer) u] = sqrt(thetr * thetr + theti * theti) /
			 (b0 * 2);
		if (dabs(surf_1.ro) <= .001f) {
		    warr_1.w10[(integer) u] = 1.f;
		} else {
		    fteta0 = (r__1 = (b1h - ccparm_1.bh1) / b0, dabs(r__1));
		    hh = surf_1.ro / 60;
		    sa = 0.f;
		    sb = 0.f;
		    for (jj = 1; jj <= 30; ++jj) {
			x0 = ((jj << 1) - 1) * hh;
			y0 = (jj << 1) * hh;
			yy = x0;
			surfim_(&yy, &dlteta, &psi);
			dx0 = dlteta;
			alf = psi;
			yy = y0;
			surfim_(&yy, &dlteta, &psi);
			dy0 = dlteta;
			bta = psi;
			qx = x0 * b0;
			qy = y0 * b0;
/* Computing 2nd power */
			r__1 = cros_1.h1;
/* Computing 2nd power */
			r__2 = x0;
			sx = sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
			r__1 = cros_1.h1;
/* Computing 2nd power */
			r__2 = y0;
			sy = sqrt(r__1 * r__1 + r__2 * r__2);
			xx = qx;
			bessel_(&xx, &bj1);
			q0j1 = bj1;
			xx = qy;
			bessel_(&xx, &bj1);
			w0j1 = bj1;
			q0x = q0j1 * dx0;
			w0y = w0j1 * dy0;
			f4 = (ccparm_1.bh1 * cos(alf - x0) - cos(alf - sx)) * 
				4 * q0x;
			s4 = (ccparm_1.bh1 * sin(alf - x0) - sin(alf - sx)) * 
				4 * q0x;
			if (jj != 30) {
			    sa = sa + f4 + (ccparm_1.bh1 * cos(bta - y0) - 
				    cos(bta - sy)) * 2 * w0y;
			    sb = sb + s4 + (ccparm_1.bh1 * sin(bta - y0) - 
				    sin(bta - sy)) * 2 * w0y;
			} else {
			    sa = hh / 3.f * (sa + f4 + (ccparm_1.bh1 * cos(
				    bta - y0) - cos(bta - sy)) * w0y);
			    sb = hh / 3.f * (sb + s4 + (ccparm_1.bh1 * sin(
				    bta - y0) - sin(bta - sy)) * w0y);
			}
/* L4024: */
		    }
		    if (fteta0 != 0.f) {
/* Computing 2nd power */
			r__1 = sa / fteta0 + 1;
/* Computing 2nd power */
			r__2 = sb / fteta0;
			warr_1.w10[(integer) u] = sqrt(r__1 * r__1 + r__2 * 
				r__2);
		    } else {
			warr_1.w10[(integer) u] = 0.f;
		    }
		}
	    }
	}
/* L4030: */
    }
    return 0;
} /* parmprec_ */

