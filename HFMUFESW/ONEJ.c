/* ONEJ.f -- translated by f2c (version 20240504).
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

/* FUNCTION ONEJ                   (NEXT) */
doublereal onej_(real *x)
{
    /* System generated locals */
    real ret_val, r__1;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal), sqrt(doublereal);

    /* Local variables */
    static real t, y, ts, tx, ty, r135, psum, qsum;


/*     ONEJ - EVALUATES THE BESSEL FUNCTION OF FIRST KIND, J1(X). */
/*     SEE MATH TABLES AND OTHER AIDS TO COMPUTATION, VOL. 11, NO. 58, */
/*     PAGE 86. */


/* .....COMPUTE J1(X)..................................................... */
    r135 = con_1.pi * 3.f / 4.f;
    if (*x > 4.f) {
	goto L100;
    }
    t = *x / 4.f;
/* Computing 2nd power */
    r__1 = t;
    y = r__1 * r__1;
    ret_val = (((((((y * -1.289769e-4f + .0022069155f) * y - .0236616773f) * 
	    y + .1777582922f) * y - .8888839649f) * y + 2.666666054f) * y - 
	    3.999999971f) * y + 2.f) * t;
    goto L105;
L100:
    t = 4.f / *x;
/* Computing 2nd power */
    r__1 = t;
    y = r__1 * r__1;
    psum = (((((y * 4.2414e-6f - 2.0092e-5f) * y + 5.80759e-5f) * y - 
	    2.23203e-4f) * y + .0029218256f) * y + .3989422819f) * 
	    2.50662827f;
    qsum = (((((y * -3.6594e-6f + 1.622e-5f) * y - 3.98708e-5f) * y + 
	    1.064741e-4f) * y - 6.3904e-4f) * y + .0374008364f) * 2.50662827f 
	    * t;
    tx = cos(*x - r135);
    ty = sin(*x - r135);
    ts = sqrt(2.f / (con_1.pi * *x));
    ret_val = ts * (psum * tx - qsum * ty);
L105:
    return ret_val;
} /* onej_ */

