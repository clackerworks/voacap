/* CURTAIN.f -- translated by f2c (version 20240504).
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
    integer nostak;
    real stkspm;
    integer numbay;
    real bayspm, diplnm, rrspm, stkhtm, stkrat[8], bayphs[14], dfmhz, ofmhz;
} antdat_;

#define antdat_1 antdat_

/* -------------------------------- */
/* Subroutine */ int curtain_(real *parm, real *azimd, real *elevd, real *
	xmgn, real *gnorm)
{
    /* Initialized data */

    static integer iphase[112]	/* was [14][8] */ = { 0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,31,31,0,77,77,109,109,0,155,155,186,186,0,47,56,103,0,139,
	    185,195,242,0,278,324,334,381,0,47,81,128,0,200,246,281,327,0,399,
	    446,480,527,0,47,105,152,0,260,306,365,411,0,519,566,624,671,0,47,
	    129,176,0,318,365,447,494,0,636,683,765,812,0,90,152,242,0,375,
	    465,527,617,0,750,840,903,993,0,90,180,270,0,444,534,624,714,0,
	    888,978,1068,1158 };
    static char ivma[4*15] = "+000" "0+00" "00+0" "++00" "+0+0" "0++0" "+-00" 
	    "+0-0" "0+-0" "+++0" "++-0" "+-+0" "+--0" "++++" "++--";
    static real vofl = 299.79246f;
    static real pi = 3.1415926f;
    static real pio2 = 1.570796326f;
    static real d2r = .01745329251f;

    /* System generated locals */
    real r__1;

    /* Builtin functions */
    integer i_nint(real *);
    double r_sign(real *, real *);

    /* Local variables */
    static integer i__, k, iaz, mode;
    static char ichr[1];
    static real azim, wave;
    static integer islew, kslew;
    extern /* Subroutine */ int pattrn0_(real *, real *, real *, real *);

/*          AZIMD= Degrees from Boresight */
/*          ELEVD= Elevation angle Degrees */
/* *************************************************************** */
/*          parm( 1)= gain above isotrope (not used) */
/*              ( 2)= antenna type [should be 12] */
/*              ( 3)= Dielectric */
/*              ( 4)= Conductivity */
/*              ( 5)= Operating freq */
/*              ( 6)= # of bays */
/*              ( 7)= # elements per bay (# of stacks) */
/*              ( 8)= Design Frequency */
/*              ( 9)= Antenna element length (>0=meters  <0=wavelengths) */
/*              (10)= Height above ground (>0  <0) */
/*              (11)= Horiz Dist between dipole centers (>0  <0) */
/*              (12)= Vertical displacement (>0  <0) */
/*              (13)= Distance from Screen (>0  <0) */
/*              (14)= Vertical Excitation (mode number) */
/*              (15)= Horizontal Slew Angle */
/* *************************************************************** */
/* ******************************************************* */
    /* Parameter adjustments */
    --parm;

    /* Function Body */
/* ...... */
/*  speed of light */
    antdat_1.dfmhz = parm[8];
/*  design frequency */
    wave = vofl / antdat_1.dfmhz;
/*  wavelength in meters */
    antdat_1.nostak = i_nint(&parm[7]);
    antdat_1.stkspm = parm[12];
    if (antdat_1.stkspm < 0.f) {
	antdat_1.stkspm = -antdat_1.stkspm * wave;
    }
/*  convert to meters */
    antdat_1.numbay = i_nint(&parm[6]);
    antdat_1.bayspm = parm[11];
    if (antdat_1.bayspm < 0.f) {
	antdat_1.bayspm = -antdat_1.bayspm * wave;
    }
/*  convert to meters */
    antdat_1.diplnm = parm[9];
    if (antdat_1.diplnm < 0.f) {
	antdat_1.diplnm = -antdat_1.diplnm * wave;
    }
/*  convert to meters */
    antdat_1.rrspm = parm[13];
    if (antdat_1.rrspm < 0.f) {
	antdat_1.rrspm = -antdat_1.rrspm * wave;
    }
/*  convert to meters */
    antdat_1.stkhtm = parm[10];
    if (antdat_1.stkhtm < 0.f) {
	antdat_1.stkhtm = -antdat_1.stkhtm * wave;
    }
/*  convert to meters */
    mode = i_nint(&parm[14]);
/*  vertical excitation mode */
    for (i__ = 1; i__ <= 4; ++i__) {
	*(unsigned char *)ichr = *(unsigned char *)&ivma[(mode - 1 << 2) + (
		i__ - 1)];
	k = (i__ << 1) - 1;
	if (*(unsigned char *)ichr == '+') {
	    antdat_1.stkrat[k - 1] = 1.f;
	    antdat_1.stkrat[k] = 1.f;
	} else if (*(unsigned char *)ichr == '-') {
	    antdat_1.stkrat[k - 1] = -1.f;
	    antdat_1.stkrat[k] = -1.f;
	} else {
	    antdat_1.stkrat[k - 1] = 0.f;
	    antdat_1.stkrat[k] = 0.f;
	}
/* L100: */
    }
    if (antdat_1.nostak < 8) {
	for (i__ = antdat_1.nostak + 1; i__ <= 8; ++i__) {
/* L101: */
	    antdat_1.stkrat[i__ - 1] = 0.f;
	}
    }
    islew = i_nint(&parm[15]);
/*  Horizontal Slew angle */
    kslew = abs(islew) / 4 + 1;
    for (i__ = 1; i__ <= 14; ++i__) {
	if (islew < 0) {
	    antdat_1.bayphs[i__ - 1] = (real) iphase[i__ + kslew * 14 - 15];
	} else {
	    antdat_1.bayphs[i__ - 1] = (real) (-iphase[i__ + kslew * 14 - 15])
		    ;
	}
/* L200: */
    }
    antdat_1.ofmhz = parm[5];
/*  operating freq */
    iaz = 0;
    azim = *azimd * d2r;
    if (dabs(azim) > pio2 && dabs(azim) < pio2 * 3.f) {
	azim -= r_sign(&pi, &azim);
	iaz = 1;
    }
    r__1 = *elevd * d2r;
    pattrn0_(&azim, &r__1, xmgn, gnorm);
    if (iaz == 1) {
	*xmgn += -20.f;
    }
/*  backward radiation */
    return 0;
} /* curtain_ */

