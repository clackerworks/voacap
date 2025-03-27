/* AGAUSS.f -- translated by f2c (version 20240504).
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
    real hh[48], xi[48];
} waits_;

#define waits_1 waits_

/* FUNCTION AGAUSS             (NEXT) */
doublereal agauss_(E_fp xfunct, real *h2)
{
    /* Initialized data */

    static real testd = 5e-8f;

    /* System generated locals */
    integer i__1;
    real ret_val, r__1;

    /* Local variables */
    static integer i__, l, m;
    static real s, fl, fm, ans, sum, test, check, bolim, uplim;


/*     AGAUSS - GAUSSIAN INTEGRATION IN WHICH 48 ABSCISSAS AND WEIGHT */
/*        FACTORS ARE USED.  XFUNCT IS THE FUNCTION TO BE INTEGRATED AND */
/*        H2 IS THE ELEMENT LENGTH WHICH DETERMINES THE INTEGRATION */
/*        LIMITS. */
/*     SEE ABRAMOWITZ AND STEGUN, HANDBOOK OF MATHEMATICAL FUNCTIONS, */
/*     P 887 (EQU 25.4.30), P917 (WEIGHT AND ABSCISSA VALUES). */
/*     THE WEIGHTS AND ABSCISSAS ARE IN COMMON /WEIGHT/ AND ARE SET */
/*     IN SUBROUTINE GAIN IN A DATA STATEMENT. */




/* .....INITIALIZE, INTEGRATE, AND TEST................................... */
    m = 1;
    ans = 0.f;
    check = 1e3f;
    if (*h2 == 0.f) {
	goto L125;
    }
L100:
    ret_val = 0.f;
    if (m < 1) {
	goto L130;
    }
    i__1 = m;
    for (l = 1; l <= i__1; ++l) {
	fl = (real) l;
	fm = (real) m;
	bolim = -(*h2) + *h2 * 2.f * (fl - 1.f) / fm;
	uplim = -(*h2) + *h2 * 2.f * fl / fm;
	sum = 0.f;
	for (i__ = 1; i__ <= 48; ++i__) {
	    s = ((uplim - bolim) * waits_1.xi[i__ - 1] + uplim + bolim) * .5f;
/* L105: */
	    sum += waits_1.hh[i__ - 1] * (*xfunct)(&s);
	}
	sum = (uplim - bolim) * .5f * sum;
/* L110: */
	ret_val += sum;
    }
L130:
    test = (r__1 = (ret_val - ans) / ret_val, dabs(r__1));
    if (test > 5e-4f) {
	goto L115;
    }
    if (test <= testd) {
	goto L125;
    }
L115:
    if (m >= 10) {
	goto L120;
    }
    check = test - testd;
    ++m;
    ans = ret_val;
    goto L100;
L120:
    if (check >= test) {
	goto L125;
    }
    ret_val = ans;
L125:
    return ret_val;
} /* agauss_ */

