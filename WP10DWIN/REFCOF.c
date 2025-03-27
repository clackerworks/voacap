/* REFCOF.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int refcof_(real *a0, real *b0, real *d1, real *e1, real *t1,
	 real *t2, real *t3, real *t4)
{
    /* System generated locals */
    real r__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static real c1, e2, f2, g1, h2, c11, hn, rk1, rl1, rm1, rn1, rl1n;


    c1 = *e1 - *b0 * *b0;
    c11 = sqrt(c1 * c1 + *d1 * *d1);
    e2 = sqrt((r__1 = c1 + c11, dabs(r__1)) / 2.f);
    f2 = sqrt((r__1 = -c1 + c11, dabs(r__1)) / 2.f);
    rk1 = *e1 * *a0 - e2;
    rl1 = rk1 + e2 * 2;
    rm1 = *d1 * *a0 - f2;
    rn1 = rm1 + f2 * 2;
    rl1n = rl1 * rl1 + rn1 * rn1;
    *t1 = (rk1 * rl1 + rm1 * rn1) / rl1n;
    *t2 = (rk1 * rn1 - rm1 * rl1) / rl1n;
    g1 = *a0 - e2;
    h2 = *a0 + e2;
    hn = h2 * h2 + f2 * f2;
    *t3 = (g1 * h2 - f2 * f2) / hn;
    *t4 = (h2 * f2 + g1 * f2) / hn;
    return 0;
} /* refcof_ */

