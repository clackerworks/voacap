/* REACT.f -- translated by f2c (version 20240504).
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

/* FUNCTION REACT              (NEXT) */
doublereal react_(real *s)
{
    /* System generated locals */
    real ret_val, r__1;

    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    static real r__, r1, r2, ca, cr, sy, sz, ca1, ca2, cr1, cr2, rho2, facx, 
	    term;


/*     REACT - PARAMETERS FOR THE MUTUAL REACTANCE EVALUATION BY */
/*        GAUSSIAN INTEGRATION. */
/*     CALLED BY AGAUSS (BY DIRECTION OF MUTUAL) TO EVALUATE INTEGRAND */
/*     SEE REFERENCES IN SUBROUTINE GAIN */



/* ....................................................................... */
    sz = *s * mut_1.ct;
    sy = *s * mut_1.prod1;
    term = mut_1.y0 + sy;
/* Computing 2nd power */
    r__1 = term;
    rho2 = r__1 * r__1;
    ca = mut_1.z0 + sz;
    ca1 = ca + mut_1.h2;
    ca2 = ca - mut_1.h2;
/* Computing 2nd power */
    r__1 = ca;
    r__ = sqrt(rho2 + r__1 * r__1);
/* Computing 2nd power */
    r__1 = ca1;
    r1 = sqrt(rho2 + r__1 * r__1);
/* Computing 2nd power */
    r__1 = ca2;
    r2 = sqrt(rho2 + r__1 * r__1);
    cr = cos(con_1.pi2 * r__) / r__;
    facx = mut_1.cfac * 2.f * cr;
    cr1 = cos(con_1.pi2 * r1) / r1;
    cr2 = cos(con_1.pi2 * r2) / r2;
    ret_val = ((cr1 * ca1 + cr2 * ca2 - facx * ca) * sy / term + (facx - cr1 
	    - cr2) * sz) * sin(con_1.pi2 * (mut_1.h2 - dabs(*s))) / *s;
    return ret_val;
} /* react_ */

