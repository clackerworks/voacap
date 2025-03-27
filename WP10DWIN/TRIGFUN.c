/* TRIGFUN.f -- translated by f2c (version 20240504).
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
    real d1, e1, f1, p1, q1, s1, beta, rlambda;
} general_;

#define general_1 general_

/* Subroutine */ int trigfun_(real *a, real *b, real *uust)
{
    /* System generated locals */
    real r__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    static real z__;


/*  pre-sets arrays of trig values */
/*  if uust=1, 91 values are set */
/*  if uust=1/3, 271 values are set    -- WHAT??? This won't work!!! */



    r__1 = *uust;
    for (z__ = 0.f; r__1 < 0 ? z__ >= 90.f : z__ <= 90.f; z__ += r__1) {
	a[(integer) z__] = sin(z__ * general_1.q1);
	b[(integer) z__] = cos(z__ * general_1.q1);
/* L100: */
    }
    a[90] = sin(general_1.q1 * 90.05f);
    b[90] = cos(general_1.q1 * 90.105f);
    b[0] = cos(.005f);
    return 0;
} /* trigfun_ */

