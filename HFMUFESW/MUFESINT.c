/* MUFESINT.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int mufesint_(integer *index, real *parm, real *asig, real *
	aeps, real *and, real *anl, real *anh, real *aex)
{
    static integer i__;

/*            initialize HFMUFES antennas */
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
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L14;
	case 15:  goto L15;
	case 16:  goto L16;
	case 17:  goto L17;
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
/*                                          !  Horizontal Half-Wave Dipole */
L3:
    *anl = -.5f;
/*  antenna length(Must be -.5) */
    *anh = parm[7];
/*  antenna height */
    *and = parm[8];
/*  gain above 1/2 wavelength horizontal dipole */
    return 0;
/*                                          !  Horizontal Yagi */
L4:
    *anh = parm[6];
/*  antenna height */
    *anl = parm[7];
/*  length of driven element */
    *and = parm[8];
/*  length of reflector element */
    aex[1] = parm[9];
/*  director length */
    aex[2] = parm[12];
/*  number of elements */
    aex[3] = parm[10];
/*  director spacing */
    aex[4] = parm[11];
/*  reflector spacing */
    return 0;
/*                                          !  Vertical Dipole */
L5:
    *anl = parm[6];
/*  antenna length */
    *anh = parm[7];
/*  feed    height */
    *and = parm[8];
/*  additional gain */
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
/*                                          !  Terminated Sloping Vee */
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
/*                                          !  Terminated Sloping Rhombic */
L9:
    *and = parm[6];
/*  1/2 large interior angle in plane of wires */
    *anl = parm[7];
/*  antenna leg length */
    *anh = parm[8];
/*  antenna height */
    aex[1] = parm[9];
/*  terminated height */
    return 0;
/*                                          !  Not used */
L10:
    return 0;
/*                                          !  Sloping Long Wire */
L11:
    *and = parm[6];
/*  Slope from Horizontal */
    *anl = parm[7];
/*  Wire length */
    *anh = parm[8];
/*  Feed height */
    return 0;
/*                                          !  Not used (constant gain) */
L12:
    return 0;
/*                                          !  Horizontal Log Periodic */
L13:
    *anh = parm[6];
/*  Feed height */
    *anl = parm[7];
/*  rear element length */
    *and = parm[8];
/*  array slope mesaured from vertical */
    aex[1] = parm[9];
/*  unloaded transmission line impedance (Ohm) */
    aex[2] = parm[10];
/*  angle between array axis & element tips */
    aex[3] = parm[11];
/*  geometric ratio of element length */
    aex[4] = parm[12];
/*  number of elements */
    return 0;
/*                                          !  Arbitrary Tilted Dipole */
L14:
    *and = parm[6];
/*  Tilt of element from horizontal */
    *anl = parm[7];
/*  length */
    *anh = parm[8];
/*  Feed height */
    return 0;
/*                                          !  Side-Loaded Vertical Half Rhombic */
L15:
    *and = parm[6];
/*  angle between leg and ground */
    *anl = parm[7];
/*  leg length */
    *anh = 0.f;
    return 0;
/*                                          !  Sloping Double Rhomboid */
L16:
    *anh = parm[6];
/*  Feed height */
    *anl = parm[7];
/*  Short leg length */
    *and = parm[8];
/*  Angle bet antenna axis & major rhomboid axis */
    aex[1] = parm[9];
/*  Angle bet major rhomboid axis & short leg */
    aex[2] = parm[10];
/*  Angle bet major rhomboid axis & long  leg */
    aex[3] = parm[11];
/*  Long leg length */
    aex[4] = parm[12];
/*  Termination height */
    return 0;
/*                                          !  Vertical w/ Radial Conductor */
L17:
    *anl = parm[6];
/*  antenna length */
    *and = parm[7];
/*  length of radials */
    *anh = 0.f;
    aex[1] = parm[8];
/*  radius of radials */
    aex[2] = parm[9];
/*  number of radials */
    return 0;
} /* mufesint_ */

