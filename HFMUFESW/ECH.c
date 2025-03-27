/* ECH.f -- translated by f2c (version 20240504).
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

/* SUBROUTINE ECH               (NEXT) */
/* Subroutine */ int ech_(complex *zsum)
{
    /* System generated locals */
    real r__1, r__2;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8, q__9, q__10, 
	    q__11;

    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal), sin(doublereal);
    void r_cnjg(complex *, complex *);

    /* Local variables */
    static real t, d2, u1, v1, u2, v2, u4, v4;
    static complex ze;
    static real ts, uz, vz, hml, hpl, uzp, vzp;
    static complex csu1, csu2, csv1, csv2;
    extern /* Complex */ VOID csz1_(complex *, real *);
    static complex csuzp, csvzp;


/*     ECH - CALCULATES THE MUTUAL IMPEDANCE BETWEEN LINEAR DIPOLE */
/*        ELEMENTS IN ECHELON OF EQUAL LENGTHS. */
/*     SEE THE REFERENCES IN SUBROUTINES GAIN AND COLL. */




/* ....................................................................... */
/* Computing 2nd power */
    r__1 = cur_1.dij;
    d2 = r__1 * r__1;
    hml = cur_1.hij - cur_1.eil;
    hpl = cur_1.hij + cur_1.eil;
/* Computing 2nd power */
    r__1 = hml;
    t = sqrt(d2 + r__1 * r__1);
    uz = con_1.pi2 * (t + hml);
    vz = con_1.pi2 * (t - hml);
/* Computing 2nd power */
    r__1 = hpl;
    t = sqrt(d2 + r__1 * r__1);
    uzp = con_1.pi2 * (t - hpl);
    vzp = con_1.pi2 * (t + hpl);
    ts = cur_1.hij;
/* Computing 2nd power */
    r__1 = ts;
    t = sqrt(d2 + r__1 * r__1);
    u1 = con_1.pi2 * (t + ts);
    v1 = con_1.pi2 * (t - ts);
    ts = cur_1.hij + cur_1.eil * 2.f;
/* Computing 2nd power */
    r__1 = ts;
    t = sqrt(d2 + r__1 * r__1);
    u2 = con_1.pi2 * (t - ts);
    v2 = con_1.pi2 * (t + ts);
    ts = cur_1.hij + cur_1.eil * 3.f;
/* Computing 2nd power */
    r__1 = ts;
    t = sqrt(d2 + r__1 * r__1);
    u4 = con_1.pi2 * (t - ts);
    v4 = con_1.pi2 * (t + ts);
    csz1_(&q__1, &u1);
    csu1.r = q__1.r, csu1.i = q__1.i;
    csz1_(&q__1, &v1);
    csv1.r = q__1.r, csv1.i = q__1.i;
    csz1_(&q__1, &u2);
    csu2.r = q__1.r, csu2.i = q__1.i;
    csz1_(&q__1, &v2);
    csv2.r = q__1.r, csv2.i = q__1.i;
    csz1_(&q__1, &uzp);
    csuzp.r = q__1.r, csuzp.i = q__1.i;
    csz1_(&q__1, &vzp);
    csvzp.r = q__1.r, csvzp.i = q__1.i;
    zsum->r = 0.f, zsum->i = 0.f;
    t = con_1.pi2 * (cur_1.eil - cur_1.hij);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    r_cnjg(&q__4, &ze);
    csz1_(&q__6, &uz);
    q__5.r = q__6.r - csu1.r, q__5.i = q__6.i - csu1.i;
    q__3.r = q__4.r * q__5.r - q__4.i * q__5.i, q__3.i = q__4.r * q__5.i + 
	    q__4.i * q__5.r;
    q__2.r = zsum->r + q__3.r, q__2.i = zsum->i + q__3.i;
    csz1_(&q__9, &vz);
    q__8.r = q__9.r - csv1.r, q__8.i = q__9.i - csv1.i;
    q__7.r = ze.r * q__8.r - ze.i * q__8.i, q__7.i = ze.r * q__8.i + ze.i * 
	    q__8.r;
    q__1.r = q__2.r + q__7.r, q__1.i = q__2.i + q__7.i;
    zsum->r = q__1.r, zsum->i = q__1.i;
    t = con_1.pi2 * (cur_1.eil + cur_1.hij);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    r_cnjg(&q__4, &ze);
    q__5.r = csuzp.r - csu2.r, q__5.i = csuzp.i - csu2.i;
    q__3.r = q__4.r * q__5.r - q__4.i * q__5.i, q__3.i = q__4.r * q__5.i + 
	    q__4.i * q__5.r;
    q__2.r = zsum->r + q__3.r, q__2.i = zsum->i + q__3.i;
    q__7.r = csvzp.r - csv2.r, q__7.i = csvzp.i - csv2.i;
    q__6.r = ze.r * q__7.r - ze.i * q__7.i, q__6.i = ze.r * q__7.i + ze.i * 
	    q__7.r;
    q__1.r = q__2.r + q__6.r, q__1.i = q__2.i + q__6.i;
    zsum->r = q__1.r, zsum->i = q__1.i;
    t = con_1.pi2 * (-cur_1.eil - cur_1.hij);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    r_cnjg(&q__4, &ze);
    q__6.r = -csu1.r, q__6.i = -csu1.i;
    q__5.r = q__6.r + csvzp.r, q__5.i = q__6.i + csvzp.i;
    q__3.r = q__4.r * q__5.r - q__4.i * q__5.i, q__3.i = q__4.r * q__5.i + 
	    q__4.i * q__5.r;
    q__2.r = zsum->r + q__3.r, q__2.i = zsum->i + q__3.i;
    q__9.r = -csv1.r, q__9.i = -csv1.i;
    q__8.r = q__9.r + csuzp.r, q__8.i = q__9.i + csuzp.i;
    q__7.r = ze.r * q__8.r - ze.i * q__8.i, q__7.i = ze.r * q__8.i + ze.i * 
	    q__8.r;
    q__1.r = q__2.r + q__7.r, q__1.i = q__2.i + q__7.i;
    zsum->r = q__1.r, zsum->i = q__1.i;
    t = con_1.pi2 * (cur_1.eil * 3.f + cur_1.hij);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    r_cnjg(&q__4, &ze);
    q__6.r = -csu2.r, q__6.i = -csu2.i;
    csz1_(&q__7, &u4);
    q__5.r = q__6.r + q__7.r, q__5.i = q__6.i + q__7.i;
    q__3.r = q__4.r * q__5.r - q__4.i * q__5.i, q__3.i = q__4.r * q__5.i + 
	    q__4.i * q__5.r;
    q__2.r = zsum->r + q__3.r, q__2.i = zsum->i + q__3.i;
    q__10.r = -csv2.r, q__10.i = -csv2.i;
    csz1_(&q__11, &v4);
    q__9.r = q__10.r + q__11.r, q__9.i = q__10.i + q__11.i;
    q__8.r = ze.r * q__9.r - ze.i * q__9.i, q__8.i = ze.r * q__9.i + ze.i * 
	    q__9.r;
    q__1.r = q__2.r + q__8.r, q__1.i = q__2.i + q__8.i;
    zsum->r = q__1.r, zsum->i = q__1.i;
    ts = cos(con_1.pi2 * cur_1.eil) * 2.f;
    t = con_1.pi2 * cur_1.hij;
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    r_cnjg(&q__5, &ze);
    q__4.r = ts * q__5.r, q__4.i = ts * q__5.i;
    q__7.r = -csv1.r, q__7.i = -csv1.i;
    q__6.r = q__7.r + csuzp.r, q__6.i = q__7.i + csuzp.i;
    q__3.r = q__4.r * q__6.r - q__4.i * q__6.i, q__3.i = q__4.r * q__6.i + 
	    q__4.i * q__6.r;
    q__2.r = zsum->r + q__3.r, q__2.i = zsum->i + q__3.i;
    q__9.r = ts * ze.r, q__9.i = ts * ze.i;
    q__11.r = -csu1.r, q__11.i = -csu1.i;
    q__10.r = q__11.r + csvzp.r, q__10.i = q__11.i + csvzp.i;
    q__8.r = q__9.r * q__10.r - q__9.i * q__10.i, q__8.i = q__9.r * q__10.i + 
	    q__9.i * q__10.r;
    q__1.r = q__2.r + q__8.r, q__1.i = q__2.i + q__8.i;
    zsum->r = q__1.r, zsum->i = q__1.i;
    t = con_1.pi2 * (cur_1.eil * 2.f + cur_1.hij);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    r_cnjg(&q__5, &ze);
    q__4.r = ts * q__5.r, q__4.i = ts * q__5.i;
    q__6.r = csuzp.r - csu2.r, q__6.i = csuzp.i - csu2.i;
    q__3.r = q__4.r * q__6.r - q__4.i * q__6.i, q__3.i = q__4.r * q__6.i + 
	    q__4.i * q__6.r;
    q__2.r = zsum->r + q__3.r, q__2.i = zsum->i + q__3.i;
    q__8.r = ts * ze.r, q__8.i = ts * ze.i;
    q__9.r = csvzp.r - csv2.r, q__9.i = csvzp.i - csv2.i;
    q__7.r = q__8.r * q__9.r - q__8.i * q__9.i, q__7.i = q__8.r * q__9.i + 
	    q__8.i * q__9.r;
    q__1.r = q__2.r + q__7.r, q__1.i = q__2.i + q__7.i;
    zsum->r = q__1.r, zsum->i = q__1.i;
    if (cur_1.kode > 0) {
	goto L100;
    }
    q__1.r = zsum->r * 15.f, q__1.i = zsum->i * 15.f;
    zsum->r = q__1.r, zsum->i = q__1.i;
    goto L105;
L100:
    q__2.r = zsum->r * 30.f, q__2.i = zsum->i * 30.f;
    r__1 = 1.f - cos(con_1.pi2 * 2.f * cur_1.eil);
    q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
    zsum->r = q__1.r, zsum->i = q__1.i;
L105:
    return 0;
} /* ech_ */

