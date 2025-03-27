/* INVCON.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int invcon_(integer *kop, real *fmc, real *deltd, real *gain)
{
    /* Initialized data */

    static real dfreq[22] = { 2.f,4.f,5.f,6.f,7.f,8.f,9.f,10.f,11.f,12.f,13.f,
	    14.f,15.f,16.f,17.f,18.f,20.f,22.f,24.f,26.f,28.f,30.f };
    static real ddeg[13] = { 0.f,5.f,10.f,15.f,20.f,25.f,30.f,35.f,40.f,45.f,
	    50.f,55.f,90.f };
    static real cone[286]	/* was [22][13] */ = { -20.f,-20.f,-20.f,
	    -20.f,-20.f,-20.f,-20.f,-20.f,-20.f,-20.f,-20.f,-20.f,-20.f,-20.f,
	    -20.f,-20.f,-20.f,-20.f,-20.f,-20.f,-20.f,-20.f,-9.f,-7.f,-8.2f,
	    -8.6f,-8.8f,-8.3f,-7.7f,-7.7f,-8.3f,-8.3f,-8.f,-8.f,-8.8f,-10.f,
	    -10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-5.f,-3.f,-3.5f,
	    -3.8f,-3.9f,-4.f,-4.1f,-3.9f,-4.7f,-5.1f,-4.9f,-4.7f,-6.4f,-7.f,
	    -6.5f,-6.f,-6.4f,-7.6f,-8.9f,-10.f,-10.f,-10.f,-2.1f,-.1f,-.7f,
	    -1.f,-1.3f,-1.4f,-1.5f,-1.7f,-2.f,-2.6f,-2.6f,-2.9f,-4.7f,-4.7f,
	    -4.f,-3.9f,-4.7f,-5.6f,-6.7f,-8.f,-10.f,-10.f,-.7f,1.3f,.8f,.4f,
	    .1f,-.7f,-2.2f,-2.3f,-1.7f,-2.4f,-5.1f,-6.7f,-5.f,-3.8f,-3.5f,
	    -3.7f,-4.3f,-5.1f,-5.7f,-6.7f,-8.3f,-10.f,-.5f,1.5f,1.4f,1.2f,.3f,
	    -1.f,-4.2f,-4.7f,-3.1f,-2.9f,-6.6f,-6.9f,-4.f,-3.2f,-3.7f,-4.2f,
	    -4.8f,-5.3f,-5.6f,-6.1f,-7.6f,-9.f,-.3f,1.7f,1.6f,1.5f,1.2f,-1.6f,
	    -5.5f,-7.2f,-6.f,-5.f,-8.f,-8.5f,-3.5f,-2.7f,-4.f,-4.7f,-5.3f,
	    -5.7f,-6.f,-6.9f,-8.1f,-10.f,-.4f,1.5f,1.5f,1.5f,1.5f,-2.2f,-7.f,
	    -11.5f,-7.5f,-5.8f,-10.4f,-12.f,-2.5f,-2.f,-4.3f,-5.3f,-6.3f,
	    -6.9f,-7.4f,-8.f,-9.f,-10.f,-.5f,1.5f,1.5f,1.5f,1.3f,-3.f,-8.4f,
	    -10.6f,-6.7f,-5.2f,-9.8f,-14.f,-2.4f,-2.4f,-5.f,-6.2f,-7.f,-7.8f,
	    -8.3f,-10.f,-10.f,-10.f,-.8f,1.2f,1.3f,1.2f,.3f,-4.1f,-10.5f,
	    -11.3f,-5.9f,-5.f,-8.5f,-17.f,-7.5f,-6.f,-6.4f,-6.9f,-7.6f,-8.3f,
	    -10.f,-10.f,-10.f,-10.f,-1.5f,.5f,.4f,.1f,-1.f,-5.4f,-12.1f,
	    -10.3f,-6.1f,-5.2f,-8.5f,-17.f,-15.f,-10.3f,-8.5f,-8.f,-8.1f,
	    -8.8f,-10.f,-10.f,-10.f,-10.f,-2.2f,-.2f,-.5f,-1.f,-2.2f,-7.3f,
	    -12.f,-8.5f,-5.6f,-5.2f,-7.5f,-15.5f,-20.f,-15.f,-10.5f,-8.9f,
	    -8.9f,-10.f,-10.f,-10.f,-10.f,-10.f,-40.f,-40.f,-40.f,-40.f,-40.f,
	    -40.f,-40.f,-40.f,-40.f,-40.f,-40.f,-40.f,-40.f,-40.f,-40.f,-40.f,
	    -40.f,-40.f,-40.f,-40.f,-40.f,-40.f };

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static real g1, g2;
    static integer ian, ifr;
    static real awt, fwt;
    static integer iang;
    static real freq;
    static integer ifrq;
    static real delta;

/* *********************************************************************** */
/*          I had to break apart the data statement for MS FORTRAN to compile */
/* *********************************************************************** */
    if (*kop != 30) {
	s_stop(" check kop ", (ftnlen)11);
    }
/*     kop=30,  inverted cone antenna */
    freq = *fmc;
    delta = *deltd;
    for (iang = 2; iang <= 13; ++iang) {
	if (delta > ddeg[iang - 1]) {
	    goto L10;
	}
	ian = iang;
	goto L20;
L10:
	;
    }
L20:
    for (ifrq = 2; ifrq <= 22; ++ifrq) {
	if (freq > dfreq[ifrq - 1]) {
	    goto L30;
	}
	ifr = ifrq;
	goto L40;
L30:
	;
    }
L40:
    fwt = (freq - dfreq[ifr - 1]) / (dfreq[ifr - 2] - dfreq[ifr - 1]);
    awt = (delta - ddeg[ian - 1]) / (ddeg[ian - 2] - ddeg[ian - 1]);
    g1 = cone[ifr + ian * 22 - 23] * (1.f - awt) + cone[ifr + (ian - 1) * 22 
	    - 23] * awt;
    g2 = cone[ifr - 1 + ian * 22 - 23] * (1.f - awt) + cone[ifr - 1 + (ian - 
	    1) * 22 - 23] * awt;
    *gain = g1 * (1.f - fwt) + g2 * fwt;
    return 0;
} /* invcon_ */

