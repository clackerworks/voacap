/* GAINTERP.f -- translated by f2c (version 20240504).
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

doublereal gainterp_(real *gainaa, real *freqoper, real *freqdesign, integer *
	iant)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    extern doublereal gainterp1_(real *, real *, integer *);
    static real g1, g2, fr;

/*          interpolate directivity gain given: */
/*              gainaa(1-3,1) = gain @  2MHz Fr=.70,1.0,1.4  iant=1 */
/*              gainaa(1-3,2) = gain @ 30MHz Fr=.70,1.0,1.4  iant=1 */
/*              gainaa(1-3,1) = gain @  2MHz Fr=.85,1.0,1.2  iant=2,3,4,8,9 */
/*              gainaa(1-3,2) = gain @ 30MHz Fr=.85,1.0,1.2  iant=2,3,4,8,9 */
/*              freqoper      = operating frequency */
/*              freqdesign    = design    frequency */
    /* Parameter adjustments */
    gainaa -= 4;

    /* Function Body */
    fr = *freqoper / *freqdesign;
/* cc      if(Fr.lt. .7) Fr= .7        !  lower limit */
/* cc      if(Fr.gt.1.4) Fr=1.4        !  upper limit */
/*  Frequency ratio */
    if (*iant == 1 && (fr < .7f || fr > 1.4f)) {
	ret_val = -30.f;
/*  outside limits */
    } else if (*iant != 1 && (fr < .85f || fr > 1.2f)) {
	ret_val = -30.f;
/*  outside limits */
    } else {
	g1 = gainterp1_(&gainaa[4], &fr, iant);
/*   2 MHz Operating */
	g2 = gainterp1_(&gainaa[7], &fr, iant);
/*  30 MHz Operating */
	ret_val = g1 + (g2 - g1) * (*freqoper - 2.f) / 28.f;
    }
    return ret_val;
} /* gainterp_ */

/* ---------------------------------------------------- */
doublereal gainterp1_(real *gainaa, real *fr, integer *iant)
{
    /* Initialized data */

    static real frs[6]	/* was [3][2] */ = { .7f,1.f,1.4f,.85f,1.f,1.2f };

    /* System generated locals */
    real ret_val;

    /* Local variables */
    static integer idx, jant;

    /* Parameter adjustments */
    --gainaa;

    /* Function Body */
    jant = *iant;
    if (jant != 1) {
	jant = 2;
    }
    idx = 2;
/*  between 1.0 & 1.4 (or 1.2) */
    if (*fr < 1.f) {
	idx = 1;
    }
/*  between  .7 (or .85) & 1.0 */
    ret_val = gainaa[idx] + (gainaa[idx + 1] - gainaa[idx]) * (*fr - frs[idx 
	    + jant * 3 - 4]) / (frs[idx + 1 + jant * 3 - 4] - frs[idx + jant *
	     3 - 4]);
    return ret_val;
} /* gainterp1_ */

