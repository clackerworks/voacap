/* AZMAX.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int azmax_(integer *iant, real *u, real *vmin1, real *vmax1, 
	real *vm, real *rmax, real *vmax)
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
    static integer i__, j;
    static real v, w[363], z9;
    extern /* Subroutine */ int gainrel_(integer *, real *, real *, real *);

/*          given: */
/*               u = elevation angle */
/*               azimuth from vmin1 to vmax1, step vm */
/*          find: */
/*               rmax = maximum relative gain */
/*               vmax = azimuth angle at vmax */


    i__ = 0;
    j = 0;
    w[0] = *rmax;
    r__1 = *vmax1;
    r__2 = *vm;
    for (v = *vmin1; r__2 < 0 ? v >= r__1 : v <= r__1; v += r__2) {
	gainrel_(iant, u, &v, &z9);
	++i__;
	w[i__] = z9;
/* cc        if (w(i).lt.w(i - 1)) then */
	if (w[i__] < *rmax) {
	    j = 0;
/* cc        elseif (w(i).gt.w(i - 1)) then */
	} else if (w[i__] > *rmax) {
	    *rmax = w[i__];
	    *vmax = v;
	} else {
	    ++j;
	    *rmax = w[i__];
	    if (v != *vmax) {
		*vmax = v - j / 2.f + 1.f;
	    }
	}
/* L1675: */
    }
    return 0;
} /* azmax_ */

