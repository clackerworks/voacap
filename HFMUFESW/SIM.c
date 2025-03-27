/* SIM.f -- translated by f2c (version 20240504).
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
    real d1d[20], ell[20];
    integer nmx, no;
    complex zs[20];
} hfmufes_one__;

#define hfmufes_one__1 hfmufes_one__

/* SUBROUTINE SIM              (NEXT) */
/* Subroutine */ int sim_(void)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2, r__3;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8, q__9, q__10, 
	    q__11, q__12, q__13, q__14, q__15, q__16, q__17, q__18, q__19, 
	    q__20, q__21, q__22, q__23, q__24, q__25, q__26, q__27, q__28, 
	    q__29, q__30, q__31, q__32, q__33, q__34, q__35;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal), sqrt(doublereal);

    /* Local variables */
    static integer j;
    static real u1, v1, u2, v2, hd, hs, tt, uz, vz, cw1, cw2, sw1, sw2, djj, 
	    djs, uzp, vzp;
    extern /* Complex */ VOID csz1_(complex *, real *);


/*     SIM - CALCULATES THE MUTUAL IMPEDANCE BETWEEN LINEAR PARALLEL */
/*        DIPOLE ELEMENTS OF UNEQUAL LENGTHS. */
/*     SEE THE REFERENCES IN SUBROUTINE GAIN. */



/* ....................................................................... */
    if (hfmufes_one__1.no < 1) {
	goto L105;
    }
    i__1 = hfmufes_one__1.no;
    for (j = 1; j <= i__1; ++j) {
	djj = hfmufes_one__1.d1d[j - 1];
/* Computing 2nd power */
	r__1 = djj;
	djs = r__1 * r__1;
	hs = hfmufes_one__1.ell[hfmufes_one__1.nmx - 1] + hfmufes_one__1.ell[
		j - 1];
	hd = hfmufes_one__1.ell[hfmufes_one__1.nmx - 1] - hfmufes_one__1.ell[
		j - 1];
	cw1 = cos(hs);
	cw2 = cos(hd);
	sw1 = sin(hs);
	sw2 = sin(hd);
/* Computing 2nd power */
	r__1 = hs;
	tt = sqrt(djs + r__1 * r__1);
	uz = tt - hs;
	vz = tt + hs;
/* Computing 2nd power */
	r__1 = hd;
	tt = sqrt(djs + r__1 * r__1);
	uzp = tt - hd;
	vzp = tt + hd;
/* Computing 2nd power */
	r__1 = hfmufes_one__1.ell[hfmufes_one__1.nmx - 1];
	tt = sqrt(djs + r__1 * r__1);
	u1 = tt - hfmufes_one__1.ell[hfmufes_one__1.nmx - 1];
	v1 = tt + hfmufes_one__1.ell[hfmufes_one__1.nmx - 1];
/* Computing 2nd power */
	r__1 = hfmufes_one__1.ell[j - 1];
	tt = sqrt(djs + r__1 * r__1);
	u2 = tt - hfmufes_one__1.ell[j - 1];
	v2 = tt + hfmufes_one__1.ell[j - 1];
	i__2 = j - 1;
	csz1_(&q__8, &uz);
	csz1_(&q__9, &u1);
	q__7.r = q__8.r - q__9.r, q__7.i = q__8.i - q__9.i;
	csz1_(&q__10, &u2);
	q__6.r = q__7.r - q__10.r, q__6.i = q__7.i - q__10.i;
	r__1 = -sw1;
	q__11.r = cw1, q__11.i = r__1;
	q__5.r = q__6.r * q__11.r - q__6.i * q__11.i, q__5.i = q__6.r * 
		q__11.i + q__6.i * q__11.r;
	csz1_(&q__15, &vz);
	csz1_(&q__16, &v1);
	q__14.r = q__15.r - q__16.r, q__14.i = q__15.i - q__16.i;
	csz1_(&q__17, &v2);
	q__13.r = q__14.r - q__17.r, q__13.i = q__14.i - q__17.i;
	q__18.r = cw1, q__18.i = sw1;
	q__12.r = q__13.r * q__18.r - q__13.i * q__18.i, q__12.i = q__13.r * 
		q__18.i + q__13.i * q__18.r;
	q__4.r = q__5.r + q__12.r, q__4.i = q__5.i + q__12.i;
	csz1_(&q__22, &uzp);
	csz1_(&q__23, &u1);
	q__21.r = q__22.r - q__23.r, q__21.i = q__22.i - q__23.i;
	csz1_(&q__24, &v2);
	q__20.r = q__21.r - q__24.r, q__20.i = q__21.i - q__24.i;
	r__2 = -sw2;
	q__25.r = cw2, q__25.i = r__2;
	q__19.r = q__20.r * q__25.r - q__20.i * q__25.i, q__19.i = q__20.r * 
		q__25.i + q__20.i * q__25.r;
	q__3.r = q__4.r + q__19.r, q__3.i = q__4.i + q__19.i;
	csz1_(&q__29, &vzp);
	csz1_(&q__30, &v1);
	q__28.r = q__29.r - q__30.r, q__28.i = q__29.i - q__30.i;
	csz1_(&q__31, &u2);
	q__27.r = q__28.r - q__31.r, q__27.i = q__28.i - q__31.i;
	q__32.r = cw2, q__32.i = sw2;
	q__26.r = q__27.r * q__32.r - q__27.i * q__32.i, q__26.i = q__27.r * 
		q__32.i + q__27.i * q__32.r;
	q__2.r = q__3.r + q__26.r, q__2.i = q__3.i + q__26.i;
	csz1_(&q__35, &djj);
	q__34.r = q__35.r * 2.f, q__34.i = q__35.i * 2.f;
	r__3 = cw1 + cw2;
	q__33.r = r__3 * q__34.r, q__33.i = r__3 * q__34.i;
	q__1.r = q__2.r + q__33.r, q__1.i = q__2.i + q__33.i;
	hfmufes_one__1.zs[i__2].r = q__1.r, hfmufes_one__1.zs[i__2].i = 
		q__1.i;
/* L100: */
	i__2 = j - 1;
	i__3 = j - 1;
	q__2.r = hfmufes_one__1.zs[i__3].r * 60.f, q__2.i = hfmufes_one__1.zs[
		i__3].i * 60.f;
	r__1 = cw2 - cw1;
	q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
	hfmufes_one__1.zs[i__2].r = q__1.r, hfmufes_one__1.zs[i__2].i = 
		q__1.i;
    }
L105:
    return 0;
} /* sim_ */

