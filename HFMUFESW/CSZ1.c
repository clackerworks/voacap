/* CSZ1.f -- translated by f2c (version 20240504).
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

/* COMPLEX FUNCTION CSZ1       (NEXT) */
/* Complex */ VOID csz1_(complex * ret_val, real *x)
{
    /* Initialized data */

    static doublereal testq = 4e-9;

    /* System generated locals */
    real r__1, r__2;
    doublereal d__1;
    complex q__1, q__2, q__3, q__4, q__5, q__6;

    /* Builtin functions */
    double log(doublereal);
    void c_div(complex *, complex *, complex *);
    double c_abs(complex *), cos(doublereal), sin(doublereal);
    void r_cnjg(complex *, complex *);

    /* Local variables */
    static complex a, b;
    static integer k;
    static real p;
    static doublereal t;
    static real x2, ci, en;
    static complex sa;
    static real si, tn;
    static complex am1, am2, bm1, bm2;
    static doublereal tm1;


/*     CSZ1 - EVALUATES THE COSINE-INTEGRAL AND SINE-INTEGRAL FUNCTIONS. */
/*     SEE THE REFERENCES IN SUBROUTINE GAIN AND THOSE GIVEN BELOW. */




/* .....TEST ARGUMENT RANGE............................................... */
/* cc      DATA TESTQ / 4.0E-10/ */
/*  the above values cause floating point errors */
    if (*x > 6.f) {
	goto L120;
    }
/* .....FOR X .LE. 6 USE THE SERIES EXPANSION............................. */
/* . . .SEE THE HANDBOOK OF MATHEMATICAL FUNCTIONS, ABRAMOWITZ AND STEGUN, */
/* . . .P 232, EQU 5.2.14 AND 5.2.16 . . . . . . . . . . . . . . . . . . . */
    en = 0.f;
/* Computing 2nd power */
    r__1 = *x;
    x2 = r__1 * r__1;
    tn = *x;
    si = *x;
L100:
    en += 1.f;
/* Computing 2nd power */
    r__1 = en * 2.f + 1.f;
    tn = -tn * x2 * (en * 2.f - 1.f) / (en * 2.f * (r__1 * r__1));
    if ((r__1 = tn / si, dabs(r__1)) <= testq) {
	goto L105;
    }
    si += tn;
    goto L100;
L105:
    en = 1.f;
    tn = -x2 / 4.f;
    ci = tn + con_1.gama + log(*x);
L110:
    en += 1.f;
/* Computing 2nd power */
    r__1 = en * 2.f;
    tn = -tn * x2 * (en * 2.f - 2.f) / ((en * 2.f - 1.f) * (r__1 * r__1));
    if ((r__1 = tn / ci, dabs(r__1)) <= testq) {
	goto L115;
    }
    ci += tn;
    goto L110;
L115:
    r__1 = -si;
    q__1.r = ci, q__1.i = r__1;
     ret_val->r = q__1.r,  ret_val->i = q__1.i;
    goto L145;
/* .....FOR X .GT. 6 USE THE CONTINUED FRACTION EXPANSION................. */
/* . . .SEE  ANALYSIS AND DESIGN OF THE LOG PERIODIC DIPOLE ANTENNA. . . . */
/* . . .BY ROBERT L. CARREL, UNIV. OF ILL. ANTENNA LAB. TECH. REPORT . . . */
/* . . .NUMBER 52 (NTIS NO. AD264558), PAGE 177 (APPENDIX A) . . . . . . . */
L120:
    am1.r = 1.f, am1.i = 0.f;
    am2.r = 1.f, am2.i = 0.f;
    bm1.r = 1.f, bm1.i = 0.f;
    bm2.r = 0.f, bm2.i = 0.f;
    p = 0.f;
    k = 0;
    tm1 = 0.f;
L125:
    p += 1.f;
    ++k;
    if (k % 2 == 0) {
	goto L130;
    }
    r__1 = (p + 1.f) / (*x * 2.f);
    q__1.r = 0.f, q__1.i = r__1;
    sa.r = q__1.r, sa.i = q__1.i;
    goto L135;
L130:
    r__1 = p / (*x * 2.f);
    q__1.r = 0.f, q__1.i = r__1;
    sa.r = q__1.r, sa.i = q__1.i;
L135:
    q__2.r = sa.r * am2.r - sa.i * am2.i, q__2.i = sa.r * am2.i + sa.i * 
	    am2.r;
    q__1.r = am1.r + q__2.r, q__1.i = am1.i + q__2.i;
    a.r = q__1.r, a.i = q__1.i;
    q__2.r = sa.r * bm2.r - sa.i * bm2.i, q__2.i = sa.r * bm2.i + sa.i * 
	    bm2.r;
    q__1.r = bm1.r + q__2.r, q__1.i = bm1.i + q__2.i;
    b.r = q__1.r, b.i = q__1.i;
    c_div(&q__1, &a, &b);
     ret_val->r = q__1.r,  ret_val->i = q__1.i;
    t = c_abs( ret_val);
    if ((d__1 = (t - tm1) / t, abs(d__1)) <= testq) {
	goto L140;
    }
    am2.r = am1.r, am2.i = am1.i;
    am1.r = a.r, am1.i = a.i;
    bm2.r = bm1.r, bm2.i = bm1.i;
    bm1.r = b.r, bm1.i = b.i;
    tm1 = t;
    goto L125;
L140:
    q__2.r = 0.f, q__2.i = con_1.pio2;
    r__1 = cos(*x);
    r__2 = sin(*x);
    q__4.r = r__1, q__4.i = r__2;
    q__6.r = 0.f, q__6.i = *x;
    q__5.r = q__6.r *  ret_val->r - q__6.i *  ret_val->i, q__5.i = q__6.r *  
	    ret_val->i + q__6.i *  ret_val->r;
    c_div(&q__3, &q__4, &q__5);
    q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
     ret_val->r = q__1.r,  ret_val->i = q__1.i;
    r_cnjg(&q__1,  ret_val);
     ret_val->r = q__1.r,  ret_val->i = q__1.i;
L145:
    return ;
} /* csz1_ */

