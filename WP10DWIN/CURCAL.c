/* CURCAL.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int curcal_(real *rl0, real *rllow, real *rlc, real *rlup, 
	real *aa1, real *aa2, real *aa3, real *aa4, real *aa5, real *bb1, 
	real *bb2, real *bb3, real *bb4, real *bb5, real *cc1, real *cc2, 
	real *cc3, real *cc4, real *cc5)
{
    /* System generated locals */
    real r__1;

    /* Local variables */
    static real x1, y1, x2, y2, x3, y3, aa, bb, cc;
    extern /* Subroutine */ int parabol_(real *, real *, real *, real *, real 
	    *, real *, real *, real *, real *);


/*       EMPIRICAL ACTIVE ELEMENT CURVE CALCULATION SUBR. */

/* ============================================================================ */
/*       INTERVAL  LLOW <= L <+(L0-LLOW)/2 */
/* ================================================= */
    x1 = *rllow;
    y1 = .316f;
    x2 = *rllow + (*rl0 - *rllow) / 4.f;
    y2 = .676f;
    x3 = *rllow + (*rl0 - *rllow) / 2.f;
    y3 = .876f;
    parabol_(&x1, &x2, &x3, &y1, &y2, &y3, &aa, &bb, &cc);
    *aa1 = aa;
    *bb1 = bb;
    *cc1 = cc;
/* ============================================================================ */
/*       INTERVAL : LLOW+(L0-LLOW)/2 <= L < 3*(L0-LLOW)/4 */
/* ============================================================================ */
    x1 = *rl0;
    y1 = 1.f;
    x2 = *rllow + (*rl0 - *rllow) * 3 / 4.f;
    y2 = .976f;
    x3 = *rllow + (*rl0 - *rllow) / 2.f;
    y3 = .876f;
    parabol_(&x1, &x2, &x3, &y1, &y2, &y3, &aa, &bb, &cc);
    *aa2 = aa;
    *bb2 = bb;
    *cc2 = cc;
/* ============================================================================ */
/*       INTERVAL : 3*(L0-LLOW)/4 <= L < LLOW */
/* ============================================================================ */
    x1 = *rl0;
    y1 = 1.f;
    x2 = *rllow + (*rl0 - *rllow) * 3 / 4.f;
    y2 = .976f;
/* Computing 2nd power */
    r__1 = x2 - x1;
    *aa3 = (y2 - y1) / (r__1 * r__1);
    *bb3 = *aa3 * -2 * x1;
    *cc3 = y1 + x1 * x1 * *aa3;
    aa = *aa3;
    bb = *bb3;
    cc = *cc3;
/* ============================================================================ */
/*       INTERVAL : L0 <= L < LC */
/* ============================================================================ */
    x1 = *rl0;
    y1 = 1.f;
    x2 = *rl0 + (*rlc - *rl0) / 2.f;
    y2 = .922f;
    x3 = *rlc;
    y3 = .707f;
    parabol_(&x1, &x2, &x3, &y1, &y2, &y3, &aa, &bb, &cc);
    *aa4 = aa;
    *bb4 = bb;
    *cc4 = cc;
/* ============================================================================ */
/*       INTERVAL : LC <= L < LUP */
/* ============================================================================ */
    x1 = *rlc + (*rlup - *rlc) / 2.f;
    y1 = .501f;
    x2 = *rlup;
    y2 = .316f;
    x3 = *rlc;
    y3 = .707f;
    parabol_(&x1, &x2, &x3, &y1, &y2, &y3, &aa, &bb, &cc);
    *aa5 = aa;
    *bb5 = bb;
    *cc5 = cc;
    return 0;
} /* curcal_ */

