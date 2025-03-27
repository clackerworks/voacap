/* SETMAXGA.f -- translated by f2c (version 20240504).
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
    real freqdesign;
} designfreq_;

#define designfreq_1 designfreq_

struct {
    real parm[20], z6, umax, vmax, giso;
    integer modegain;
    real gainmax[6]	/* was [3][2] */, gainmaxb[30];
} ccirparm_;

#define ccirparm_1 ccirparm_

/* Subroutine */ int setmaxgain_(real *freqoper)
{
    /* Builtin functions */
    integer i_nint(real *);

    /* Local variables */
    extern doublereal gainterb_(real *, real *), gainterp_(real *, real *, 
	    real *, integer *);
    static integer iant;
    static real foper, fdesign;

/* ******************************************************************* */
/*       PURPOSE: */
/*          set maximum gain parameter (giso) for use by ANTCAL */
/*       INPUT  PARAMETERS: */
/*          freqoper  = Operating Frequency */
/*          freqdesign= Design Frequency (=0=use Operating Frequency) */
/*                    = in range .7 to 1.4  use as FreqRatio */
/*                        thus   fdesign=foper/FreqRatio */
/*       OUTPUT PARAMETERS: */
/* ******************************************************************* */
    iant = i_nint(&ccirparm_1.parm[1]);
/*  type [1,2,...12] */
    if (ccirparm_1.modegain == 0) {
	ccirparm_1.giso = ccirparm_1.parm[0];
/*  maximum gain */
    } else if (ccirparm_1.modegain == 1) {
/*          interpolate on Frequency ratio and Operating frequency */
	foper = *freqoper;
/*  set operating frequency */
	if (foper < 2.f || foper > 30.f) {
	    foper = 10.f;
	}
	fdesign = designfreq_1.freqdesign;
/*          was this Frequency Ratio (.7 to 1.4) */
/*  set design frequency */
	if (fdesign >= .7f && fdesign <= 1.4f) {
	    fdesign = foper / designfreq_1.freqdesign;
	}
	if (fdesign < 2.f || fdesign > 30.f) {
	    fdesign = foper;
	}
	ccirparm_1.parm[4] = foper;
	ccirparm_1.parm[7] = fdesign;
	if (iant == 8) {
	    ccirparm_1.parm[5] = fdesign;
	}
/*  quadrant antenna */
	ccirparm_1.giso = gainterp_(ccirparm_1.gainmax, &foper, &fdesign, &
		iant);
    } else if (ccirparm_1.modegain == 2) {
	ccirparm_1.parm[4] = *freqoper;
	ccirparm_1.giso = gainterb_(ccirparm_1.gainmaxb, freqoper);
/*  types 5,6,7,10 */
    }
    return 0;
} /* setmaxgain_ */

