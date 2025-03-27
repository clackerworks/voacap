/* BESSEL.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int bessel_(real *xx, real *bj1)
{
    /* System generated locals */
    real r__1, r__2, r__3, r__4;

    /* Builtin functions */
    double cos(doublereal), sqrt(doublereal);

    /* Local variables */
    static real aa, bb, cc, dd, ff, qq, tt, zz, xx3, x3x;


/*            bessel function calculation subroutine */

    if (*xx <= 3.f) {
	xx3 = *xx / 3.f;
/* Computing 2nd power */
	r__1 = xx3;
/* Computing 4th power */
	r__2 = xx3, r__2 *= r__2;
/* Computing 6th power */
	r__3 = xx3, r__3 *= r__3;
	aa = .5f - r__1 * r__1 * .56249f + r__2 * r__2 * .21093f - r__3 * (
		r__3 * r__3) * .03954f;
/* Computing 8th power */
	r__1 = xx3, r__1 *= r__1, r__1 *= r__1;
/* Computing 10th power */
	r__2 = xx3, r__2 *= r__2, r__3 = r__2, r__2 *= r__2;
/* Computing 12th power */
	r__4 = xx3, r__4 *= r__4, r__4 *= r__4;
	bb = r__1 * r__1 * .00443f - r__3 * (r__2 * r__2) * 3.1e-4f + r__4 * (
		r__4 * r__4) * 1e-5f;
	*bj1 = *xx * (aa + bb);
    } else {
	x3x = 3.f / *xx;
/* Computing 2nd power */
	r__1 = x3x;
/* Computing 3rd power */
	r__2 = x3x;
	cc = x3x * 1.56e-6f + .79788f + r__1 * r__1 * .01659f + r__2 * (r__2 *
		 r__2) * 1.7e-4f;
/* Computing 4th power */
	r__1 = x3x, r__1 *= r__1;
/* Computing 5th power */
	r__2 = x3x, r__3 = r__2, r__2 *= r__2;
/* Computing 6th power */
	r__4 = x3x, r__4 *= r__4;
	dd = r__1 * r__1 * -.00249f + r__3 * (r__2 * r__2) * .00113f - r__4 * 
		(r__4 * r__4) * 2e-4f;
	ff = cc + dd;
/* Computing 2nd power */
	r__1 = x3x;
/* Computing 3rd power */
	r__2 = x3x;
	qq = *xx - 2.35619f + x3x * .12499f + r__1 * r__1 * 5e-5f - r__2 * (
		r__2 * r__2) * .00637f;
/* Computing 4th power */
	r__1 = x3x, r__1 *= r__1;
/* Computing 5th power */
	r__2 = x3x, r__3 = r__2, r__2 *= r__2;
/* Computing 6th power */
	r__4 = x3x, r__4 *= r__4;
	zz = r__1 * r__1 * 7.4e-4f + r__3 * (r__2 * r__2) * 7.9e-4f - r__4 * (
		r__4 * r__4) * 2.9e-4f;
	tt = qq + zz;
	*bj1 = ff * cos(tt) / sqrt(*xx);
    }
    return 0;
} /* bessel_ */

