/* PARABOL.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int parabol_(real *x1, real *x2, real *x3, real *y1, real *
	y2, real *y3, real *aa, real *bb, real *cc)
{
    static real da, db, dd, dc;

/* ============================================================================ */
/*       PARABOLIC PARAMETRIZED CURVE FITTING SUBROUTINE */
/* ============================================================================ */
    dd = *x1 * *x1 * (*x2 - *x3) - *x1 * (*x2 * *x2 - *x3 * *x3) + (*x2 * *x2 
	    * *x3 - *x3 * *x3 * *x2);
    da = *y1 * (*x2 - *x3) - *x1 * (*y2 - *y3) + (*y2 * *x3 - *x2 * *y3);
    db = *x1 * *x1 * (*y2 - *y3) - *y1 * (*x2 * *x2 - *x3 * *x3) + (*x2 * *x2 
	    * *y3 - *x3 * *x3 * *y2);
    dc = *x1 * *x1 * (*x2 * *y3 - *y2 * *x3) - *x1 * (*x2 * *x2 * *y3 - *y2 * 
	    *x3 * *x3) + *y1 * (*x2 * *x2 * *x3 - *x3 * *x3 * *x2);
    *aa = da / dd;
    *bb = db / dd;
    *cc = dc / dd;
    return 0;
} /* parabol_ */

