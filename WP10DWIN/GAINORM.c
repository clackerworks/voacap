/* GAINORM.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int gainorm_(real *z6, real *umax, real *vmax, integer *
	iperf, integer *iant, integer *ifs)
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
    static integer i__;
    static real u, v, z9, vm, wmx, rmax, vmin1, vmax1;
    extern /* Subroutine */ int azmax_(integer *, real *, real *, real *, 
	    real *, real *, real *), gainrel_(integer *, real *, real *, real 
	    *);


/*       calculation of the gain normalizing factor */

/*        dimension w(90) */

/*  pre-set angles of maximum radiation for simple cases */
/*  in the vertical plane */

    if (*iant == 4 || *iant < 4 && *ifs != 0) {
	if (*iperf == 1) {
	    u = 0.f;
	} else {
	    if (*iant == 4) {
		u = 45.f;
	    } else {
		u = 5.f;
	    }
	}

/*  find maximum in horizontal plane */

	vmin1 = 270.f;
	vmax1 = 450.f;
	vm = 10.f;
	rmax = 0.f;
	r__1 = vmax1;
	r__2 = vm;
	for (v = vmin1; r__2 < 0 ? v >= r__1 : v <= r__1; v += r__2) {
	    gainrel_(iant, &u, &v, &z9);
	    if (z9 > rmax) {
		rmax = z9;
		*vmax = v;
	    }
/* L1435: */
	}
	*z6 = z9;
	vmin1 = *vmax - 10;
	vmax1 = *vmax + 10;
	vm = 1.f;
	azmax_(iant, &u, &vmin1, &vmax1, &vm, &rmax, vmax);
	if (*iperf == 1) {
	    return 0;
	}
    } else {
	*vmax = 0.f;
	if (*iperf != 0) {
	    u = 0.f;
	    v = 0.f;
	    gainrel_(iant, &u, &v, &z9);
	    *z6 = z9;
	    return 0;
	}
    }
    v = *vmax;
    wmx = 0.f;
    for (u = 1.f; u <= 90.f; u += 1.f) {
	gainrel_(iant, &u, &v, &z9);
	if (z9 >= wmx) {
	    wmx = z9;
	    *umax = u;
	}
/* L1520: */
    }
    *z6 = wmx;
    if (*ifs != 0 || *iant == 4) {
	u = *umax;
	i__ = 0;
	rmax = *z6;
	vmin1 = *vmax - 5.f;
	vmax1 = *vmax + 5.f;
	vm = 1.f;
	azmax_(iant, &u, &vmin1, &vmax1, &vm, &rmax, vmax);
	*z6 = rmax;
	if (*vmax >= 360.f) {
	    *vmax += -360;
	}
    }
    return 0;
} /* gainorm_ */

