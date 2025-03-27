/* PATTRN0.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int pattrn0_(real *azim, real *elev, real *xgn, real *factor)
{
    /* Initialized data */

    static real pi = 3.1415926f;
    static real vofl = 299.79246f;
    static real pi2 = 6.283185307f;
    static real d2r = .01745329251f;

    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
    double cos(doublereal), r_lg10(real *);

    /* Local variables */
    extern doublereal f2_(real *, real *);
    static integer ib;
    static real el;
    static integer is, nbs;
    static real xgain, odrat, dintgl;
    extern /* Subroutine */ int dbltrap_(real *);

/* -------------------------------------------------------------------- */
/*                        SUBPROGRAM USAGE */

/*  SGAIN - computes power gain dBi */
/* ********************************************************************* */
/*  COMMON BLOCKS: */
/* ANTDAT */
/*       nostak - NUMBER OF VERTICAL STACKS */
/*       STKSPM - SPACING BETWEEN STACKS */
/*       NUMBAY - NUMBER OF BAYS */
/*       BAYSPM - SPACING BETWEEN BAYS */
/*       DIPLNM - LENGTH OF DIPOLE RADIATOR */
/*       RRSPM - SPACING BETWEEN RADIATORS AND REFLECTING SCREEN */
/*       STKHTM - HEIGHT OF LOWEST STACK ABOVE GROUND */
/*       STKRAT - CURRENT RATIO FOR STACKS */
/*       BAYPHS - RELATIVE PHASE FOR THE BAYS */
/*       BAYRAT - CURRENT RATIO FOR THE BAYS (ALWAYS = 1) */
/*       OFMHZ - ANTENNA OPERATING FREQUENCY */
/*       DFMHZ - ANTENNA DESIGN FREQUENCY */

/* CONST */
/*       PI      -  MATHEMATICAL SYMBOL PI = 3.14159 */
/*       VOFL    -  VELOCITY OF LIGHT  FOR FREQUENCY IN MEGAHERTZ = 3.0E- */
/*       PI2     -  2 * PI */
/*       PIO2    -  PI / 2 */
/*       D2R     -  CONVERSION FACTOR FOR DEGREES TO RADIANS CONVERSION */
/*                   = PI / 180. */
/*       R2D     -  CONVERSION FACTOR FOR RADIANS TO DEGREES CONVERSION */
/*                   = 180 / PI */
/* FWAVE */
/*       EIL     -  0.5 * LENGTH OF DIPOLE IN radianS */
/*       XB      -  SPACING BETWEEN BAYS IN radiansS */
/*       XS      -  SPACING BETWEEN STACKS IN radianS */
/*       XH      -  HEIGHT OF LOWEST STACK ABOVE GROUND IN radianS */
/*       XR      -  REFLECTOR TO DIPOLE SPACING IN radianS */
/*       C(8)    -  ARRAY OF RELATIVE STACK CURRENT MAGNITUDE RATIOS */
/*       R(14)   -  ARRAY OF RELATIVE BAY CURRENT MAGNITUDE RATIOS */
/*       PS(14)  -  ARRAY OF BAY CURRENT PHASE RATIOS IN RADIANS INCLUDIN */
/*                     FREQUENCY ADJUSTMENT FOR OPERATING FREQUENCY NOT */
/*                     EQUAL TO DESIGN FREQUENCY */
/*       A(8)    -  ARRAY OF STACK CURRENT PHASE RATIOS IN RADIANS, */
/*                    CURRENTLY DEFAULTED TO ZERO */
/*       Y(14)   -  ARRAY CONTAINING THE SPACINGS BETWEEN THE BAY DIPOLES */
/*                     IN radianS (RELATIVE TO BAY 1) */
/*       Z(8)    -  ARRAY CONTAINING THE SPACINGS BETWEEN THE STACK DIPOL */
/*                     IN radianS (RELATIVE TO STACK 1) */
/*       WAVE    -  OPERATING FREQUENCY WAVELENGTH */
/*       BETA    -  OPERATING FREQUENCY WAVE NUMBER (K=2*PI/WAVE) */


/*  DUMMY ARGUMENTS: */
/*       AZIM  - an azimuth counter-clockwise from Boresight RADIANS */
/*       ELEV  - an elevation angle above the horizon  RADIANS */
/*       XGN  - antenna gain (dB) for AZIM, ELEV */
/*       FACTOR  - integral result for antenna gain normalization */

/* ********************************************************************* */
/*  SET DEFAULT VALUES FOR GAIN */
    fwave_1.wave = vofl / antdat_1.ofmhz;
    fwave_1.beta = pi2 / fwave_1.wave;
    fwave_1.xh = antdat_1.stkhtm * fwave_1.beta;
    fwave_1.xb = fwave_1.beta * antdat_1.bayspm;
    el = antdat_1.diplnm * fwave_1.beta;
    fwave_1.eil = el / 2.f;
    fwave_1.ceil = cos(fwave_1.eil);
    fwave_1.xr = antdat_1.rrspm * fwave_1.beta;
    fwave_1.xs = antdat_1.stkspm * fwave_1.beta;

/*  CONSTANTS FUNCTIONS OF FREQUENCY ONLY */
    i__1 = antdat_1.nostak;
    for (is = 1; is <= i__1; ++is) {
	fwave_1.z__[is - 1] = fwave_1.xs * (real) (is - 1) + fwave_1.xh;
	fwave_1.c__[is - 1] = antdat_1.stkrat[is - 1];
/* L30: */
    }
    odrat = d2r * antdat_1.ofmhz / antdat_1.dfmhz;
    nbs = abs(antdat_1.numbay);
    i__1 = nbs;
    for (ib = 1; ib <= i__1; ++ib) {
	fwave_1.ps[ib - 1] = odrat * antdat_1.bayphs[ib - 1];
	fwave_1.r__[ib - 1] = 1.f;
	fwave_1.y[ib - 1] = (real) (ib - 1) * fwave_1.xb;
/* L40: */
    }
    fwave_1.y[0] = 0.f;
    if (*factor == -99999.f) {
	dbltrap_(&dintgl);
	*factor = pi * 4.f / dintgl;
    }
    *xgn = -1e3f;
    xgain = f2_(elev, azim);
    if (xgain != 0.f) {
	r__2 = (r__1 = xgain * *factor, dabs(r__1));
	*xgn = r_lg10(&r__2) * 10.f;
    }
    return 0;
} /* pattrn0_ */

