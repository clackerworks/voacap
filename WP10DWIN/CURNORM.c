/* CURNORM.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int curnorm_(real *parm, real *z6, real *umax, real *vmax, 
	real *gmax)
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    integer i_nint(real *);

    /* Local variables */
    static real gain, elev, azim;
    static integer ielev, iazim, nazim;
    extern /* Subroutine */ int curtain_(real *, real *, real *, real *, real 
	    *);

/* ******************************************************************* */
/*       PURPOSE: */
/*          initialize NTIA Report 83-215 antenna calculations */
/*       INPUT  PARAMETERS: */
/*          parm(1-n) = parameters that define the antenna characteristics */
/*       OUTPUT PARAMETERS: */
/*          z6 = gain normalizing factor (used by ccirgain) */
/*          umax = elevation angle at z6 */
/*          vmax = azimuthal angle at z6 */
/* ******************************************************************* */
/*       Written by Greg Hand NTIA/ITS Boulder, Colorado   Aug 1991 */
/*       Please call (303)497-3375 with any questions. */
/* ******************************************************************* */
    /* Parameter adjustments */
    --parm;

    /* Function Body */
    *gmax = -99999.f;
    nazim = 0;
    if (parm[15] != 0.f) {
	r__1 = dabs(parm[15]);
	nazim = i_nint(&r__1) + 1;
    }
    nazim <<= 1;
    i__1 = nazim;
    for (iazim = 0; iazim <= i__1; ++iazim) {
	azim = (real) iazim;
	if (nazim != 0) {
	    azim = (real) (iazim - nazim / 2);
	}
	for (ielev = 0; ielev <= 45; ++ielev) {
	    elev = (real) ielev;
	    curtain_(&parm[1], &azim, &elev, &gain, z6);
	    if (gain > *gmax) {
		*gmax = gain;
		*umax = elev;
		*vmax = azim;
	    }
/* L10: */
	}
    }
    return 0;
} /* curnorm_ */

