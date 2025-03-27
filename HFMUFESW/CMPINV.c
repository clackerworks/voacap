/* CMPINV.f -- translated by f2c (version 20240504).
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

/* SUBROUTINE CMPINV           (NEXT) */
/* Subroutine */ int cmpinv_(real *a, real *b, real *c__, real *d__, integer *
	n)
{
    /* Format strings */
    static char fmt_1500[] = "(\0020MATRIX C IN SUBROUTINE CMPINV DOES NOT E"
	    "XIST.\002//)";
    static char fmt_1502[] = "(\0020MATRICES A AND B BOTH SINGULAR IN SUBR C"
	    "MPINV.\002//)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, i1, j1, k1, i2, j2, i3, j3;
    static real temp;
    extern /* Subroutine */ int matinv_(real *, integer *), sqmult_(real *, 
	    real *, real *, integer *);

    /* Fortran I/O blocks */
    static cilist io___14 = { 0, 6, 0, fmt_1500, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_1502, 0 };



/*     CMPINV - COMPLEX MATRIX OPERATION THAT FINDS INVERSE, C+ID, OF */
/*        A+IB WHERE A,B,C, AND D ARE REAL SQUARE MATRICES.  CMPINV */
/*        CALLS MATINV TO INVERT REAL MATRICES AND SQMULT TO MULTIPLY */
/*        SQUARE MATRICES IN ORDER TO COMPUTE THE COMPLEX INVERSE */
/*                      C=INV(A + B*(INV(A))*B) */
/*                      D=-C*B*(INV(A)) */
/*        A, B, C, AND D ARE ALL REAL N BY N MATRICIES. */
/*        IF A IS SINGULAR, EXCHANGE A AND B (FACTOR OUT I) AND TRY AGAIN */
/*     THIS ROUTINE IS SHARE NO. ANL F103 BY B.S.GARBOW OF ARGONNE */
/*     NATIONAL LABORATORY, ARGONNE, ILLINOIS */



/* .....INVERT -A......................................................... */
    /* Parameter adjustments */
    d__ -= 21;
    c__ -= 21;
    b -= 21;
    a -= 21;

    /* Function Body */
    m = *n;
    l = 1;
L100:
    if (m < 1) {
	goto L160;
    }
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (m < 1) {
	    goto L165;
	}
	i__2 = m;
	for (j = 1; j <= i__2; ++j) {
/* L105: */
	    d__[i__ + j * 20] = -a[i__ + j * 20];
	}
    }
L165:
L160:
    matinv_(&d__[21], &m);
/* .....CHECK IF INV(-A) EXISTS (IF NOT GO TO 6).......................... */
    if (m < 1) {
	goto L170;
    }
    i__2 = m;
    for (k = 1; k <= i__2; ++k) {
	if (pon_1.ipivot[k - 1] != 1) {
	    goto L125;
	}
/* L110: */
    }
L170:
/* .....COMPUTE C=INV(A - B*(INV(-A))*B).................................. */
    sqmult_(&b[21], &d__[21], &d__[21], &m);
    sqmult_(&d__[21], &b[21], &c__[21], &m);
    if (m < 1) {
	goto L175;
    }
    i__2 = m;
    for (i1 = 1; i1 <= i__2; ++i1) {
	if (m < 1) {
	    goto L180;
	}
	i__1 = m;
	for (j1 = 1; j1 <= i__1; ++j1) {
/* L115: */
	    c__[i1 + j1 * 20] = a[i1 + j1 * 20] - c__[i1 + j1 * 20];
	}
    }
L180:
L175:
    matinv_(&c__[21], &m);
/* .....CHECK IF C EXISTS (IF NOT GO TO 300).............................. */
    if (m < 1) {
	goto L185;
    }
    i__1 = m;
    for (k1 = 1; k1 <= i__1; ++k1) {
	if (pon_1.ipivot[k1 - 1] != 1) {
	    goto L150;
	}
/* L120: */
    }
L185:
/* .....COMPUTE D=C*B*(INV(-A))........................................... */
    sqmult_(&c__[21], &d__[21], &d__[21], &m);
    if (l != 2) {
	goto L145;
    }
    goto L135;
/* .....A IS SINGULAR, INTERCHANGE A AND B AND TRY AGAIN.................. */
L125:
    if (m < 1) {
	goto L190;
    }
    i__1 = m;
    for (i2 = 1; i2 <= i__1; ++i2) {
	if (m < 1) {
	    goto L195;
	}
	i__2 = m;
	for (j2 = 1; j2 <= i__2; ++j2) {
	    temp = a[i2 + j2 * 20];
	    a[i2 + j2 * 20] = b[i2 + j2 * 20];
/* L130: */
	    b[i2 + j2 * 20] = temp;
	}
    }
L195:
L190:
/* .....IF A AND B BOTH SINGULAR, GO TO 310............................... */
    if (l == 2) {
	goto L155;
    }
    l = 2;
    goto L100;
/* .....RE-INTERCHANGE A AND B, AND INTERCHANGE C AND D WITH SIGNS CHANGED */
/*     DUE TO THE -I FACTORED OUT WHEN A AND B ORIGINALLY INTERCHANGED... */
L135:
    if (m < 1) {
	goto L200;
    }
    i__2 = m;
    for (i3 = 1; i3 <= i__2; ++i3) {
	if (m < 1) {
	    goto L205;
	}
	i__1 = m;
	for (j3 = 1; j3 <= i__1; ++j3) {
	    temp = a[i3 + j3 * 20];
	    a[i3 + j3 * 20] = b[i3 + j3 * 20];
	    b[i3 + j3 * 20] = temp;
	    temp = -c__[i3 + j3 * 20];
	    c__[i3 + j3 * 20] = -d__[i3 + j3 * 20];
/* L140: */
	    d__[i3 + j3 * 20] = temp;
	}
    }
L205:
L200:
L145:
    return 0;

/* .....ERROR STOP - NO INVERSE EXISTS.................................... */
L150:
    s_wsfe(&io___14);
    e_wsfe();
    s_stop("", (ftnlen)0);
/* .....ERROR STOP - INVERSE CANNOT BE FOUND BY THIS METHOD............... */
L155:
    s_wsfe(&io___15);
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* cmpinv_ */

