/* CANG.f -- translated by f2c (version 20240504).
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

/* FUNCTION CANG               (NEXT) */
doublereal cang_(complex *z__)
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
    double r_imag(complex *), atan(doublereal);

    /* Local variables */
    static real x, y;



/*      FOR USE WITH HFMUFES3 IN SYSTEMS WHERE FUNCTION CANG IS MISSING. */



/*     CANG - COMPUTES CANG=ARG(Z), Z=X + I*Y=COMPLEX NUMBER, SUCH THAT */
/*        -PI .LT. CANG .LE. +PI.  SEE CONTROL DATA CORP. 3600/3800 */
/*        COMPUTER SYSTEMS LIBRARY FUNCTIONS MANUAL, PUBLICATION NO. */
/*        60056400, JULY 1, 1966. */




/* .....INITIALIZE CANG FOR QUADRANT CORRECTION, GET RE(Z) AND IM(Z), TEST */
/* .....X FOR + OR - TO FIND CORRECT HALF-PLANE........................... */
    ret_val = 0.f;
    x = z__->r;
    y = r_imag(z__);
    if (x < 0.f) {
	goto L100;
    } else if (x == 0) {
	goto L120;
    } else {
	goto L140;
    }
/* .....X .LT. 0.0........................................................ */
L100:
    if (y < 0.f) {
	goto L105;
    } else if (y == 0) {
	goto L110;
    } else {
	goto L115;
    }
L105:
    ret_val = -con_1.pi;
    goto L140;
L110:
    ret_val = con_1.pi;
    return ret_val;
L115:
    ret_val = con_1.pi;
    goto L140;
/* .....X .EQ. 0.0........................................................ */
L120:
    if (y < 0.f) {
	goto L125;
    } else if (y == 0) {
	goto L130;
    } else {
	goto L135;
    }
L125:
    ret_val = -con_1.pio2;
    return ret_val;
/* . . .X=0 AND Y=0 IS REALLY UNDEFINED, BUT IN AGREEMENT WITH CDC WE. . . */
/* . . .RETURN A VALUE OF CANG=0.0 . . . . . . . . . . . . . . . . . . . . */
L130:
    ret_val = 0.f;
    return ret_val;
L135:
    ret_val = con_1.pio2;
    return ret_val;
/* .....X .GT. 0.0 AND X .6T. 0.0 ADJUSTED FOR CORRECT QUADRANT........... */
L140:
    ret_val = atan(y / x) + ret_val;
    return ret_val;
} /* cang_ */

