/* F2.f -- translated by f2c (version 20240504).
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

struct {
    real eil, ceil, xb, xs, xh, xr, c__[8], r__[14], ps[14], a[8], y[14], z__[
	    8], wave, beta;
} fwave_;

#define fwave_1 fwave_

doublereal f2_(real *theta, real *phi)
{
    /* System generated locals */
    integer i__1;
    real ret_val;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__;
    static real ef, fx, cof, arg;
    static integer nbs;
    static real fyi, fyr, cphi, cpsi, sphi, spsi2, fzphr, fzthr, ctheta, 
	    stheta;

/* ********************************************************************* */
/*  PARAMETERS: */
/*    THETA - takeoff angle in radians */
/*    PHI - azimuthal angle in radians */
/* ********************************************************************* */
    cphi = cos(*phi);
    sphi = sin(*phi);
    ctheta = cos(*theta);
    stheta = sin(*theta);
    cpsi = ctheta * sphi;
    spsi2 = 1.f - cpsi * cpsi;
    if (spsi2 <= 1e-12f) {
	spsi2 = 1e-12f;
    }
    ef = (cos(fwave_1.eil * cpsi) - fwave_1.ceil) / spsi2;
    fzphr = 0.f;
    fyr = 0.f;
    fyi = 0.f;
    nbs = abs(antdat_1.numbay);
    i__1 = nbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	arg = fwave_1.y[i__ - 1] * cpsi + fwave_1.ps[i__ - 1];
	fyr += fwave_1.r__[i__ - 1] * cos(arg);
/* L50: */
	fyi += fwave_1.r__[i__ - 1] * sin(arg);
    }
    fx = sin(fwave_1.xr * ctheta * cphi);
    i__1 = antdat_1.nostak;
    for (i__ = 1; i__ <= i__1; ++i__) {
	cof = fwave_1.c__[i__ - 1] * sin(fwave_1.z__[i__ - 1] * stheta);
	fzphr += cof;
/* L60: */
    }
    cof = stheta * sphi;
    fzthr = fzphr * cof;
    fzphr *= cphi;
    ret_val = ef * ef * fx * fx * (fyr * fyr + fyi * fyi) * (fzthr * fzthr + 
	    fzphr * fzphr);
    return ret_val;
} /* f2_ */

