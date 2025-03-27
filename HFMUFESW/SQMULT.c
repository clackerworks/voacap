/* SQMULT.f -- translated by f2c (version 20240504).
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
    integer index[40]	/* was [20][2] */, ipivot[20];
    real pivot[20];
} pon_;

#define pon_1 pon_

/* SUBROUTINE SQMULT           (NEXT) */
/* Subroutine */ int sqmult_(real *a, real *b, real *c__, integer *n)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l;


/*     SQUARE MATRIX MULTIPLICATION (COMPANION TO CMPINV IN ANL F103) */



/* .....C=A*B............................................................. */
    /* Parameter adjustments */
    c__ -= 21;
    b -= 21;
    a -= 21;

    /* Function Body */
    if (*n < 1) {
	goto L110;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	if (*n < 1) {
	    goto L115;
	}
	i__2 = *n;
	for (k = 1; k <= i__2; ++k) {
/* L100: */
	    pon_1.pivot[k - 1] = b[k + j * 20];
	}
L115:
	if (*n < 1) {
	    goto L120;
	}
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    c__[i__ + j * 20] = 0.f;
	    if (*n < 1) {
		goto L125;
	    }
	    i__3 = *n;
	    for (l = 1; l <= i__3; ++l) {
/* L105: */
		c__[i__ + j * 20] += a[i__ + l * 20] * pon_1.pivot[l - 1];
	    }
	}
    }
L125:
L120:
L110:
    return 0;
} /* sqmult_ */

