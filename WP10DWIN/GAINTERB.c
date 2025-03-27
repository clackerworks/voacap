/* GAINTERB.f -- translated by f2c (version 20240504).
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

doublereal gainterb_(real *gainab, real *freqoper)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    static integer idx;
    static real fact;

/*          interpolate directivity gain given: */
/*              gainab(2-30) = gain @  2 - 30 MHz */
/*              freqoper      = operating frequency */
    /* Parameter adjustments */
    --gainab;

    /* Function Body */
    idx = *freqoper;
    if (idx == 30) {
	idx = 29;
    }
/*  can't exceed 30 */
    fact = *freqoper - (real) idx;
    ret_val = gainab[idx] + (gainab[idx + 1] - gainab[idx]) * fact;
    return ret_val;
} /* gainterb_ */

