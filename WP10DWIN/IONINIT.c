/* IONINIT.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int ioninit_(integer *index, real *parm, real *asig, real *
	aeps, real *and, real *anl, real *anh, real *aex)
{
    static integer i__;

/*            initialize IONCAP antennas */
    /* Parameter adjustments */
    --aex;
    --parm;

    /* Function Body */
    *asig = parm[4];
/*  conductivity */
    *aeps = parm[3];
/*  dielectric */
    for (i__ = 1; i__ <= 4; ++i__) {
/* L111: */
	aex[i__] = 0.f;
    }
    switch (*index) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L3;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
    }
/*                                          !  Terminated Horizontal Rhombic */
L1:
    *and = parm[6];
/*  tilt angle */
    *anl = parm[7];
/*  leg length */
    *anh = parm[8];
/*  height */
    return 0;
/*                                          !  Vertical Monopole */
L2:
    *anl = parm[6];
/*  height */
    *anh = parm[7];
/*  gain above dipole */
    *and = 0.f;
    return 0;
/*                                          !  Horizontal Dipole & Yagi */
L3:
    *anl = parm[6];
/*  antenna length */
    *anh = parm[7];
/*  antenna height */
    *and = 0.f;
    aex[1] = parm[8];
/*  gain above 1/2 wavelength horizontal d */
    return 0;
/*                                          !  Vertical Lop-Periodic */
L5:
    *anl = -.25f;
/*  antenna height (MUST be 1/4 wavelength */
    *and = 0.f;
    *anh = 0.f;
    aex[1] = parm[6];
/*  gain above 1/4 wavelength vertical */
    return 0;
/*                                          !  Curtain */
L6:
    *and = parm[6];
/*  # of bays */
    *anl = parm[7];
/*  antenna element length */
    *anh = parm[8];
/*  antenna height to 1st element */
    aex[1] = parm[9];
/*  # of elements per bay */
    aex[2] = parm[10];
/*  distance between element centers */
    aex[3] = parm[11];
/*  vertical spacing of elements */
    aex[4] = parm[12];
/*  distance from screen */
    return 0;
/*                                          !  Sloping Vee */
L7:
    *and = parm[6];
/*  1/2 apex angle in plane of wires */
    *anl = parm[7];
/*  antenna leg length */
    *anh = parm[8];
/*  antenna height */
    aex[1] = parm[9];
/*  terminated height */
    return 0;
/*                                          !  Inverted L */
L8:
    *anl = parm[6];
/*  antenna length */
    *anh = parm[7];
/*  antenna height */
    *and = 0.f;
    return 0;
/*                                          !  Sloping Rhombic */
L9:
    *and = parm[6];
/*  1/2 large interior angle in plane of w */
    *anl = parm[7];
/*  antenna leg length */
    *anh = parm[8];
/*  antenna height */
    aex[1] = parm[9];
/*  terminated height */
    return 0;
/*                                          !  Interlaced Rhombic */
L10:
    *and = parm[6];
/*  1/2 large interior angle in plane of w */
    *anl = parm[7];
/*  antenna leg length */
    *anh = parm[8];
/*  lower antenna height */
    aex[1] = parm[9];
/*  vertical displacement */
    aex[2] = parm[10];
/*  horizontal feed point displacement */
    return 0;
} /* ioninit_ */

