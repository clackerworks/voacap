/* CCIRGAIN.f -- translated by f2c (version 20240504).
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
    real floor;
} floorc_;

#define floorc_1 floorc_

struct {
    real gain_type11__[91];
} ctype11g_;

#define ctype11g_1 ctype11g_

struct {
    real parm[20];
} ccirparm_;

#define ccirparm_1 ccirparm_

/* Subroutine */ int ccirgain_(integer *iant, real *u, real *v, real *z6, 
	real *giso, real *gain)
{
    /* Builtin functions */
    integer i_nint(real *);
    double r_lg10(real *);

    /* Local variables */
    static real g9, z9, dgs;
    static integer ielev;
    extern /* Subroutine */ int gainrel_(integer *, real *, real *, real *), 
	    curtain_(real *, real *, real *, real *, real *);

/* ****************************************************************** */
/*    GAIN CALCULATION  SUBROUTINE */
/*      INPUT  PARAMETERS: */
/*          iant = antenna type index number [0-10] */
/*          u    = elevation angle [0-90] */
/*          v    = off main beam azimuth angle [0-360] */
/*          z6   = gain normalizing factor from antinit */
/*          giso = maximum gain of antenna relative to isotrope (user input) */
/*      OUTPUT PARAMETERS: */
/*          gain    = calculated gain returned */
/* ****************************************************************** */
/*       Written by Greg Hand NTIA/ITS Boulder, Colorado   Aug 1991 */
/*       Please call (303)497-3375 with any questions. */
/* ******************************************************************* */
/*                                antenna floor value */

    *gain = *giso;
/*                                     iant=0=isotrope */
    if (*iant == 0) {
	return 0;
    }
    if (*iant == 11) {
/* gain table */
	ielev = i_nint(u);
	if (ielev < 0) {
	    ielev = 0;
	}
	if (ielev > 90) {
	    ielev = 90;
	}
	*gain = *giso + ctype11g_1.gain_type11__[ielev];
	return 0;
    } else if (*iant == 12) {
	curtain_(ccirparm_1.parm, v, u, gain, z6);
	*gain += *giso;
	return 0;
    }
/*                                     calculate relative gain */
    gainrel_(iant, u, v, &z9);
/*                                     convert relative to maximum */
    if (*z6 == 0.f) {
	*gain = -floorc_1.floor;
	return 0;
    }
    dgs = z9 / *z6;
    if (dgs <= .03162278f) {
	g9 = -30.f;
    } else {
	g9 = r_lg10(&dgs) * 20.f;
    }
/*                                     floor value limit */
    if (g9 < -floorc_1.floor) {
	g9 = -floorc_1.floor;
    }
    *gain = g9 + *gain;
    if (*gain < -floorc_1.floor) {
	*gain = -floorc_1.floor;
    }
    return 0;
} /* ccirgain_ */

