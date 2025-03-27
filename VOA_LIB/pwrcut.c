/* pwrcut.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int pwrcut_(real *snr50, real *snr_lw__, real *snr_up__, 
	real *snr88, real *snr91, real *power_cut__)
{
    /* Initialized data */

    static real fact[4] = { 1.28f,.84f,.525f,.255f };

    extern doublereal dayinterp_(real *, real *);
    static real snr[11], day3db, day6db, std_lw__, std_up__;

/*          calculte Percent Power Cut possible based on George Lane Algorithm */
/*          An estimate of the number of days on which a power reduction can be */
/*          used during a given hour and month can be made by computing the */
/*          area under the assumed normal distribution of Signal-to-Noise */
/*          ratios over the days of the month. */

/*          SNR50 = SNR from IONCAP, the median S/N ratio */
/*          SNR_LW = lower decile deviation of SNR */
/*          SNR_UP = upper decile deviation of SNR */
/*          SNR88  = 3 dB (half power) SNR limit (nominally 88 dB) */
/*          SNR91  = 6 dB (quarter power) SNR limit (nominally 91 dB) */
/*          power_cut = [0 to .75], the calculated fraction power cut available */
    std_lw__ = *snr_lw__ / 1.28f;
/*  convert to standard deviation */
    snr[10] = *snr50 - fact[0] * std_lw__ * 2.f;
    snr[9] = *snr50 - fact[0] * std_lw__;
    snr[8] = *snr50 - fact[1] * std_lw__;
    snr[7] = *snr50 - fact[2] * std_lw__;
    snr[6] = *snr50 - fact[3] * std_lw__;
    snr[5] = *snr50;
    std_up__ = *snr_up__ / 1.28f;
/*  convert to standard deviation */
    snr[4] = *snr50 + fact[3] * std_up__;
    snr[3] = *snr50 + fact[2] * std_up__;
    snr[2] = *snr50 + fact[1] * std_up__;
    snr[1] = *snr50 + fact[0] * std_up__;
    snr[0] = *snr50 + fact[0] * std_up__ * 2.f;
/* cc      write(72,'('' snr='',11f8.3)') snr */
    day3db = dayinterp_(snr, snr88);
/*  fract days that exceed SNR88 */
    day6db = dayinterp_(snr, snr91);
/*  fract days that exceed SNR91 */
    *power_cut__ = 1.f - (1.f - day3db) - (day3db - day6db) / 2.f - day6db / 
	    4.f;
/* cc      write(72,1) power_cut,day3dB,day6dB */
/* cc1     format(' power_cut=',f8.3,5x,'day3dB=',f8.3,5x,'day6dB=',f8.3) */
    return 0;
} /* pwrcut_ */

/* --------------------------------------------------------------- */
doublereal dayinterp_(real *snr, real *snrx)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    static integer i__;

/*  fract days that exceed SNR88 */
    /* Parameter adjustments */
    --snr;

    /* Function Body */
    ret_val = 0.f;
    if (*snrx > snr[1]) {
	return ret_val;
    }
    for (i__ = 1; i__ <= 10; ++i__) {
	if (*snrx <= snr[i__] && *snrx >= snr[i__ + 1]) {
	    ret_val = ((real) (i__ - 1) + (snr[i__] - *snrx) / (snr[i__] - 
		    snr[i__ + 1])) / 10.f;
	    return ret_val;
	}
/* L10: */
    }
    ret_val = 1.f;
    return ret_val;
} /* dayinterp_ */

