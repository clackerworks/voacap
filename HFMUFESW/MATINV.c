/* MATINV.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int matinv_(real *a, integer *n)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    real r__1;

    /* Local variables */
    static integer i__, j, k, l, i1, j1, i2, l1, l2, k1, ll;
    static real temp;
    static integer irow;
    static real determ;
    static integer icolum;


/*     MATINV - INVERTS A REAL SQUARE (N BY N) MATRIX A AND STORES */
/*        THE RESULTANT INVERSE BACK IN A.  THE METHOD USED IS GAUSS- */
/*        JORDAN ELIMINATION WITH COMPLETE PIVOTING (SEE, FOR EXAMPLE, */
/*        A.RALSTON AND H.S.WILF (1967), MATHEMATICAL METHODS FOR */
/*        DIGITAL COMPUTERS, VOL. 2,  ARTICLE BY J.H.WILKINSON.) */
/*     THIS ROUTINE IS SHARE NO. ANL F402 BY B.S.GARBOW OF ARGONNE */
/*     NATIONAL LABORATORY, ARGONNE, ILLINOIS */



/* .....INITIALIZE........................................................ */
    /* Parameter adjustments */
    a -= 21;

    /* Function Body */
    determ = 1.f;
    if (*n < 1) {
	goto L160;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
/* L100: */
	pon_1.ipivot[j - 1] = 0;
    }
L160:
    if (*n < 1) {
	goto L165;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* .....SEARCH FOR PIVOTAL ELEMENT........................................ */
	temp = 0.f;
	if (*n < 1) {
	    goto L170;
	}
	i__2 = *n;
	for (j1 = 1; j1 <= i__2; ++j1) {
	    if (pon_1.ipivot[j1 - 1] == 1) {
		goto L115;
	    }
	    if (*n < 1) {
		goto L175;
	    }
	    i__3 = *n;
	    for (k = 1; k <= i__3; ++k) {
		if ((i__4 = pon_1.ipivot[k - 1] - 1) < 0) {
		    goto L105;
		} else if (i__4 == 0) {
		    goto L110;
		} else {
		    goto L155;
		}
L105:
		if (dabs(temp) > (r__1 = a[j1 + k * 20], dabs(r__1))) {
		    goto L110;
		}
		irow = j1;
		icolum = k;
		temp = a[j1 + k * 20];
L110:
		;
	    }
L175:
L115:
	    ;
	}
L170:
	++pon_1.ipivot[icolum - 1];
/* .....INTERCHANGE ROWS TO PUT PIVOTAL ELEMENT ON DIAGONAL............... */
	if (irow == icolum) {
	    goto L125;
	}
	determ = -determ;
	if (*n < 1) {
	    goto L180;
	}
	i__2 = *n;
	for (l = 1; l <= i__2; ++l) {
	    temp = a[irow + l * 20];
	    a[irow + l * 20] = a[icolum + l * 20];
/* L120: */
	    a[icolum + l * 20] = temp;
	}
L180:
L125:
	pon_1.index[i__ - 1] = irow;
	pon_1.index[i__ + 19] = icolum;
	pon_1.pivot[i__ - 1] = a[icolum + icolum * 20];
	determ *= pon_1.pivot[i__ - 1];
	if (determ == 0.f) {
	    goto L155;
	}
/* .....DIVIDE PIVOTAL ROW BY PIVOTAL ELEMENT............................. */
	a[icolum + icolum * 20] = 1.f;
	if (*n < 1) {
	    goto L185;
	}
	i__2 = *n;
	for (l1 = 1; l1 <= i__2; ++l1) {
/* L130: */
	    a[icolum + l1 * 20] /= pon_1.pivot[i__ - 1];
	}
L185:
/* .....REDUCE NON-PIVOTAL ROWS........................................... */
	if (*n < 1) {
	    goto L190;
	}
	i__2 = *n;
	for (i1 = 1; i1 <= i__2; ++i1) {
	    if (i1 == icolum) {
		goto L140;
	    }
	    temp = a[i1 + icolum * 20];
	    a[i1 + icolum * 20] = 0.f;
	    if (*n < 1) {
		goto L195;
	    }
	    i__3 = *n;
	    for (l2 = 1; l2 <= i__3; ++l2) {
/* L135: */
		a[i1 + l2 * 20] -= a[icolum + l2 * 20] * temp;
	    }
L195:
L140:
	    ;
	}
    }
L190:
L165:
/* .....INTERCHANGE COLUMNS (TO UNDO THE SWAP TO GET MAX PIVOT ON DIAG)... */
    if (*n < 1) {
	goto L200;
    }
    i__2 = *n;
    for (i2 = 1; i2 <= i__2; ++i2) {
	ll = *n + 1 - i2;
	if (pon_1.index[ll - 1] == pon_1.index[ll + 19]) {
	    goto L150;
	}
	irow = pon_1.index[ll - 1];
	icolum = pon_1.index[ll + 19];
	if (*n < 1) {
	    goto L205;
	}
	i__1 = *n;
	for (k1 = 1; k1 <= i__1; ++k1) {
	    temp = a[k1 + irow * 20];
	    a[k1 + irow * 20] = a[k1 + icolum * 20];
/* L145: */
	    a[k1 + icolum * 20] = temp;
	}
L205:
L150:
	;
    }
L200:
L155:
    return 0;
} /* matinv_ */

