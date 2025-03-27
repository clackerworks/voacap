/* MUTUAL.f -- translated by f2c (version 20240504).
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
    real d2r, dcl, gama, pi, pi2, pio2, r2d, ro, vofl;
} con_;

#define con_1 con_

struct {
    real cfac, ct, h2, prod1, rhi2, r21, x21, y0, z0;
} mut_;

#define mut_1 mut_

/* SUBROUTINE MUTUAL           (NEXT) */
/* Subroutine */ int mutual_(void)
{
    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static real xcon;
    extern /* Subroutine */ int react_();
    extern doublereal agauss_(U_fp, real *);
    extern /* Subroutine */ int resist_();


/*     MUTUAL - CALCULATES THE MUTUAL IMPEDANCE BETWEEN ARBITRARY */
/*        ORIENTED LINEAR DIPOLE ELEMENTS BY GAUSSIAN INTEGRATION. */
/*     SEE THE REFERENCES IN SUBROUTINE GAIN FOR DETAILS */




/* ....................................................................... */
    xcon = con_1.vofl * -.1f;
    mut_1.ct = cos(mut_1.rhi2);
    mut_1.prod1 = -sin(mut_1.rhi2);
/* . . .NOTE ERROR OF NEXT CARD MISSING IN EARLIER VERSIONS. . . . . . . . */
    mut_1.x21 = 0.f;
    if (mut_1.y0 <= .005f) {
	goto L100;
    }
    mut_1.x21 = xcon * agauss_((U_fp)react_, &mut_1.h2);
L100:
    mut_1.r21 = xcon * agauss_((U_fp)resist_, &mut_1.h2);
    return 0;
} /* mutual_ */

