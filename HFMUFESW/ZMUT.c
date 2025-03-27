/* ZMUT.f -- translated by f2c (version 20240504).
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
    real d2r, dcl, gama, pi, pi2, pio2, r2d, ro, vofl;
} con_;

#define con_1 con_

struct {
    real dij, eil, hij;
    integer kode;
} cur_;

#define cur_1 cur_

/* SUBROUTINE ZMUT             (NEXT) */
/* Subroutine */ int zmut_(complex *zsum)
{
    /* System generated locals */
    real r__1, r__2;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8, q__9, q__10, 
	    q__11, q__12, q__13, q__14, q__15, q__16, q__17, q__18;

    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    static real t, d2, u1, v1, w1, uz, vz, el2, cw1, sw1, uzp;
    static complex csu1, csv1;
    extern /* Complex */ VOID csz1_(complex *, real *);
    static complex csuzp;


/*     ZMUT - CALCULATES THE SELF-IMPEDANCE AND MUTUAL-IMPEDANCE */
/*        BETWEEN LINEAR PARALLEL DIPOLE ELEMENTS OF EQUAL LENGTHS. */
/*     SEE THE REFERENCES IN SUBROUTINE GAIN. */




/* ....................................................................... */
/* Computing 2nd power */
    r__1 = cur_1.dij;
    d2 = r__1 * r__1;
/* Computing 2nd power */
    r__1 = cur_1.eil;
    el2 = r__1 * r__1;
    t = sqrt(d2 + el2 * 4.f);
    uz = con_1.pi2 * (t - cur_1.eil * 2.f);
    vz = con_1.pi2 * (t + cur_1.eil * 2.f);
    uzp = con_1.pi2 * cur_1.dij;
    t = sqrt(d2 + el2);
    u1 = con_1.pi2 * (t - cur_1.eil);
    v1 = con_1.pi2 * (t + cur_1.eil);
    w1 = con_1.pi2 * 2.f * cur_1.eil;
    cw1 = cos(w1);
    sw1 = sin(w1);
    csz1_(&q__1, &u1);
    csu1.r = q__1.r, csu1.i = q__1.i;
    csz1_(&q__1, &v1);
    csv1.r = q__1.r, csv1.i = q__1.i;
    csz1_(&q__1, &uzp);
    csuzp.r = q__1.r, csuzp.i = q__1.i;
    csz1_(&q__6, &uz);
    q__7.r = csu1.r * 2.f, q__7.i = csu1.i * 2.f;
    q__5.r = q__6.r - q__7.r, q__5.i = q__6.i - q__7.i;
    r__1 = -sw1;
    q__8.r = cw1, q__8.i = r__1;
    q__4.r = q__5.r * q__8.r - q__5.i * q__8.i, q__4.i = q__5.r * q__8.i + 
	    q__5.i * q__8.r;
    csz1_(&q__11, &vz);
    q__12.r = csv1.r * 2.f, q__12.i = csv1.i * 2.f;
    q__10.r = q__11.r - q__12.r, q__10.i = q__11.i - q__12.i;
    q__13.r = cw1, q__13.i = sw1;
    q__9.r = q__10.r * q__13.r - q__10.i * q__13.i, q__9.i = q__10.r * 
	    q__13.i + q__10.i * q__13.r;
    q__3.r = q__4.r + q__9.r, q__3.i = q__4.i + q__9.i;
    q__16.r = csuzp.r - csu1.r, q__16.i = csuzp.i - csu1.i;
    q__15.r = q__16.r - csv1.r, q__15.i = q__16.i - csv1.i;
    q__14.r = q__15.r * 2.f, q__14.i = q__15.i * 2.f;
    q__2.r = q__3.r + q__14.r, q__2.i = q__3.i + q__14.i;
    q__18.r = csuzp.r * 2.f, q__18.i = csuzp.i * 2.f;
    r__2 = cw1 + 1.f;
    q__17.r = r__2 * q__18.r, q__17.i = r__2 * q__18.i;
    q__1.r = q__2.r + q__17.r, q__1.i = q__2.i + q__17.i;
    zsum->r = q__1.r, zsum->i = q__1.i;
    if (cur_1.kode > 0) {
	goto L100;
    }
    q__1.r = zsum->r * 30.f, q__1.i = zsum->i * 30.f;
    zsum->r = q__1.r, zsum->i = q__1.i;
    goto L105;
L100:
    q__2.r = zsum->r * 60.f, q__2.i = zsum->i * 60.f;
    r__1 = 1.f - cw1;
    q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
    zsum->r = q__1.r, zsum->i = q__1.i;
L105:
    return 0;
} /* zmut_ */

