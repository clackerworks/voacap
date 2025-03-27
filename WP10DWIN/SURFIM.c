/* SURFIM.f -- translated by f2c (version 20240504).
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
    real ro, costh, sinth, rnumb, gamma, epq;
} surf_;

#define surf_1 surf_

/* Subroutine */ int surfim_(real *yy, real *dlteta, real *psi)
{
    /* System generated locals */
    real r__1, r__2;

    /* Builtin functions */
    double log(doublereal), sqrt(doublereal), atan(doublereal);

    /* Local variables */
    static real dnm, etai, etar, srag, sraq, srag1, srag2, detai, detar, 
	    etani, etanr;



    if (surf_1.ro <= 0.f) {
	srag = 0.f;
	detar = surf_1.costh;
	detai = surf_1.sinth;
    } else {
	srag1 = *yy / surf_1.rnumb;
	srag2 = log(*yy * 2 / surf_1.gamma);
	srag = srag1 * srag2;
	sraq = srag * srag;
	dnm = surf_1.epq + sraq + srag * 2 * surf_1.sinth;
	etanr = sraq * surf_1.costh;
	etani = surf_1.epq * srag + sraq * surf_1.sinth;
	etar = etanr / dnm;
	etai = etani / dnm;
	detar = surf_1.costh - etar;
	detai = surf_1.sinth - etai;
    }
/* Computing 2nd power */
    r__1 = detar;
/* Computing 2nd power */
    r__2 = detai;
    *dlteta = sqrt(r__1 * r__1 + r__2 * r__2);
    *psi = atan(detai / detar);
    return 0;
} /* surfim_ */

