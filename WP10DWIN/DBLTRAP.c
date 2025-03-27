/* DBLTRAP.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int dbltrap_(real *dintgl)
{
    /* Initialized data */

    static real d2r = .01745329251f;

    /* Builtin functions */
    double cos(doublereal);

    /* Local variables */
    static integer j;
    static real p, t;
    extern doublereal f2_(real *, real *);
    static integer ip1;
    static real phif, phiz, pint, tint;

/* ********************************************************************* */
/*  PARAMETERS: */
/*     DINTGL  -  INTEGRATION RESULT CALCULATED IN DBLTRAP */
/*     THETA STEP SIZE = 1  DEGREE */
/*     PHI   STEP SIZE = 1  DEGREE */
/*     THETA LOWER LIMIT OF INTEGRATION = 0. DEGREES */
/*     PHI   LOWER LIMIT OF INTEGRATION = -90. DEGREES */
/*     THETA UPPER LIMIT OF INTEGRATION = 90. DEGREES */
/*     PHI   UPPER LIMIT OF INTEGRATION = 90. DEGREES */
/* ********************************************************************* */
    phiz = -90.f * d2r;
    phif = d2r * 90.f;
    tint = 0.f;
    t = 0.f;
    for (ip1 = 1; ip1 <= 91; ++ip1) {
	p = phiz + d2r;
	pint = 0.f;
	for (j = 1; j <= 179; ++j) {
	    pint += f2_(&t, &p);
	    p += d2r;
/* L90: */
	}
	pint *= d2r;
	pint += d2r / 2.f * (f2_(&t, &phif) + f2_(&t, &phiz));
	if (ip1 == 1 || ip1 == 91) {
	    goto L91;
	}
	tint += d2r * pint * cos(t);
	goto L92;
L91:
	tint += d2r * pint * cos(t) / 2.f;
L92:
	t += d2r;
/* L80: */
    }
    *dintgl = tint;
    return 0;
} /* dbltrap_ */

