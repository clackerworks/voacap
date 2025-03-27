/* ANTCAL.f -- translated by f2c (version 20240504).
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
    real gain10[2610]	/* was [90][29] */;
} gain_10__;

#define gain_10__1 gain_10__

struct {
    real parm[20], z6, umax, vmax, giso;
    integer modegain;
    real gainmax[6]	/* was [3][2] */, gnorm[30];
} ccirparm_;

#define ccirparm_1 ccirparm_

struct {
    real gain_type11__[91];
} ctype11g_;

#define ctype11g_1 ctype11g_

/* Subroutine */ int antcal_(real *bmain, real *bazim, real *del, real *gain)
{
    /* Builtin functions */
    integer i_nint(real *);

    /* Local variables */
    extern /* Subroutine */ int ccirgain_(integer *, real *, real *, real *, 
	    real *, real *);
    static real gn;
    static integer jant;
    static real freq, ofaz;
    static integer ielev, ifreq;
    extern /* Subroutine */ int curtain_(real *, real *, real *, real *, real 
	    *);

/* ****************************************************************** */
/*          bmain- is main beam azmuthal bearing (degrees) */
/*          bazim- is azimuthal bearing (degrees) to calculate */
/*          del  - is elevation angle (degrees) */
/*          gain - is returned */
/* ***************************************************************** */
/*   calculates gain of antenna for azimuthal offset and elevation angle */

    jant = i_nint(&ccirparm_1.parm[1]);
/*  ccir antenna type */
    *gain = ccirparm_1.giso;
    if (jant == 10) {
/*  vertical monopole */
	ielev = i_nint(del);
	if (ielev < 0) {
	    ielev = 0;
	}
	if (ielev > 90) {
	    ielev = 90;
	}
	if (ielev == 0) {
	    *gain = -30.f;
	} else {
	    freq = ccirparm_1.parm[4];
/*  operating freq */
	    ifreq = freq;
	    if (ifreq < 30) {
		*gain = gain_10__1.gain10[ielev + (ifreq - 1) * 90 - 91] + (
			freq - (real) ifreq) * (gain_10__1.gain10[ielev + 
			ifreq * 90 - 91] - gain_10__1.gain10[ielev + (ifreq - 
			1) * 90 - 91]);
	    } else {
		*gain = gain_10__1.gain10[ielev + 2519];
	    }
	}
    } else if (jant == 11) {
/*  gain table */
	ielev = i_nint(del);
	if (ielev < 0) {
	    ielev = 0;
	}
	if (ielev > 90) {
	    ielev = 90;
	}
	*gain += ctype11g_1.gain_type11__[ielev];
    } else if (jant == 12) {
/*  NTIA Report 87-215 Curtain arrays */
	ofaz = *bazim - *bmain;
	if (ofaz < 0.f) {
	    ofaz += 360.f;
	}
	freq = ccirparm_1.parm[4];
/*  operating freq */
	ifreq = freq;
	if (ifreq < 30) {
	    gn = ccirparm_1.gnorm[ifreq - 1] + (freq - (real) ifreq) * (
		    ccirparm_1.gnorm[ifreq] - ccirparm_1.gnorm[ifreq - 1]);
	} else {
	    gn = ccirparm_1.gnorm[29];
	}
	curtain_(ccirparm_1.parm, &ofaz, del, gain, &gn);
	if (*gain < -30.f) {
	    *gain = -30.f;
	}
    } else if (jant > 0) {
/*  not Isotrope */
	ofaz = *bazim - *bmain;
	if (ofaz < 0.f) {
	    ofaz += 360.f;
	}
	ccirgain_(&jant, del, &ofaz, &ccirparm_1.z6, &ccirparm_1.giso, gain);
    }
    return 0;
} /* antcal_ */

