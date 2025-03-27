/* COLL.f -- translated by f2c (version 20240504).
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

/* SUBROUTINE COLL             (NEXT) */
/* Subroutine */ int coll_(complex *sum)
{
    /* System generated locals */
    real r__1, r__2;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8, q__9;

    /* Builtin functions */
    double log(doublereal), cos(doublereal), sin(doublereal);
    void r_cnjg(complex *, complex *);

    /* Local variables */
    static real t, u1, v2, u3, v4;
    static complex ze;
    static real ts, uz;
    static complex csu1, csu3, csv2;
    extern /* Complex */ VOID csz1_(complex *, real *);
    static real hlog, h2log;


/*     COLL - CALCULATES THE MUTUAL IMPEDANCE BETWEEN COLINEAR DIPOLE */
/*        ELEMENTS OF EQUAL LENGTHS. */
/*     SEE REFERENCES IN SUBROUTINE GAIN AND ALSO THE ARTICLE BY */
/*     H.E. KING, IRE TRANS. ANT. AND PROP., JULY 1957, P 306. */




/* ....................................................................... */
    uz = con_1.pi2 * 2.f * (cur_1.hij - cur_1.eil);
    u1 = con_1.pi2 * 2.f * cur_1.hij;
    v2 = con_1.pi2 * 2.f * (cur_1.hij + cur_1.eil * 2.f);
    u3 = con_1.pi2 * 2.f * (cur_1.hij + cur_1.eil);
    v4 = con_1.pi2 * 2.f * (cur_1.hij + cur_1.eil * 3.f);
    csz1_(&q__1, &u1);
    csu1.r = q__1.r, csu1.i = q__1.i;
    csz1_(&q__1, &v2);
    csv2.r = q__1.r, csv2.i = q__1.i;
    csz1_(&q__1, &u3);
    csu3.r = q__1.r, csu3.i = q__1.i;
    hlog = log(cur_1.hij / (cur_1.hij + cur_1.eil));
    h2log = log((cur_1.hij + cur_1.eil * 2.f) / (cur_1.hij + cur_1.eil));
    t = con_1.pi2 * (cur_1.hij - cur_1.eil);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    csz1_(&q__4, &uz);
    q__3.r = q__4.r - csu1.r, q__3.i = q__4.i - csu1.i;
    q__2.r = ze.r * q__3.r - ze.i * q__3.i, q__2.i = ze.r * q__3.i + ze.i * 
	    q__3.r;
    r_cnjg(&q__6, &ze);
    r__1 = log(cur_1.hij / (cur_1.hij - cur_1.eil));
    q__5.r = r__1 * q__6.r, q__5.i = r__1 * q__6.i;
    q__1.r = q__2.r + q__5.r, q__1.i = q__2.i + q__5.i;
    sum->r = q__1.r, sum->i = q__1.i;
    t = con_1.pi2 * (cur_1.hij + cur_1.eil);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    q__4.r = csu3.r - csv2.r, q__4.i = csu3.i - csv2.i;
    q__3.r = ze.r * q__4.r - ze.i * q__4.i, q__3.i = ze.r * q__4.i + ze.i * 
	    q__4.r;
    q__2.r = sum->r + q__3.r, q__2.i = sum->i + q__3.i;
    r_cnjg(&q__6, &ze);
    q__5.r = h2log * q__6.r, q__5.i = h2log * q__6.i;
    q__1.r = q__2.r + q__5.r, q__1.i = q__2.i + q__5.i;
    sum->r = q__1.r, sum->i = q__1.i;
    q__5.r = -csu1.r, q__5.i = -csu1.i;
    q__4.r = q__5.r + csu3.r, q__4.i = q__5.i + csu3.i;
    q__3.r = ze.r * q__4.r - ze.i * q__4.i, q__3.i = ze.r * q__4.i + ze.i * 
	    q__4.r;
    q__2.r = sum->r + q__3.r, q__2.i = sum->i + q__3.i;
    r_cnjg(&q__7, &ze);
    q__6.r = hlog * q__7.r, q__6.i = hlog * q__7.i;
    q__1.r = q__2.r + q__6.r, q__1.i = q__2.i + q__6.i;
    sum->r = q__1.r, sum->i = q__1.i;
    t = con_1.pi2 * (cur_1.hij + cur_1.eil * 3.f);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    q__5.r = -csv2.r, q__5.i = -csv2.i;
    csz1_(&q__6, &v4);
    q__4.r = q__5.r + q__6.r, q__4.i = q__5.i + q__6.i;
    q__3.r = ze.r * q__4.r - ze.i * q__4.i, q__3.i = ze.r * q__4.i + ze.i * 
	    q__4.r;
    q__2.r = sum->r + q__3.r, q__2.i = sum->i + q__3.i;
    r_cnjg(&q__8, &ze);
    r__1 = log((cur_1.hij + cur_1.eil * 2.f) / (cur_1.hij + cur_1.eil * 3.f));
    q__7.r = r__1 * q__8.r, q__7.i = r__1 * q__8.i;
    q__1.r = q__2.r + q__7.r, q__1.i = q__2.i + q__7.i;
    sum->r = q__1.r, sum->i = q__1.i;
    ts = cos(con_1.pi2 * cur_1.eil) * 2.f;
    t = con_1.pi2 * cur_1.hij;
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    q__4.r = ts * ze.r, q__4.i = ts * ze.i;
    q__6.r = -csu1.r, q__6.i = -csu1.i;
    q__5.r = q__6.r + csu3.r, q__5.i = q__6.i + csu3.i;
    q__3.r = q__4.r * q__5.r - q__4.i * q__5.i, q__3.i = q__4.r * q__5.i + 
	    q__4.i * q__5.r;
    q__2.r = sum->r + q__3.r, q__2.i = sum->i + q__3.i;
    r_cnjg(&q__9, &ze);
    q__8.r = ts * q__9.r, q__8.i = ts * q__9.i;
    q__7.r = hlog * q__8.r, q__7.i = hlog * q__8.i;
    q__1.r = q__2.r + q__7.r, q__1.i = q__2.i + q__7.i;
    sum->r = q__1.r, sum->i = q__1.i;
    t = con_1.pi2 * (cur_1.hij + cur_1.eil * 2.f);
    r__1 = cos(t);
    r__2 = sin(t);
    q__1.r = r__1, q__1.i = r__2;
    ze.r = q__1.r, ze.i = q__1.i;
    q__4.r = ts * ze.r, q__4.i = ts * ze.i;
    q__5.r = csu3.r - csv2.r, q__5.i = csu3.i - csv2.i;
    q__3.r = q__4.r * q__5.r - q__4.i * q__5.i, q__3.i = q__4.r * q__5.i + 
	    q__4.i * q__5.r;
    q__2.r = sum->r + q__3.r, q__2.i = sum->i + q__3.i;
    r_cnjg(&q__8, &ze);
    q__7.r = ts * q__8.r, q__7.i = ts * q__8.i;
    q__6.r = h2log * q__7.r, q__6.i = h2log * q__7.i;
    q__1.r = q__2.r + q__6.r, q__1.i = q__2.i + q__6.i;
    sum->r = q__1.r, sum->i = q__1.i;
    if (cur_1.kode > 0) {
	goto L100;
    }
    q__1.r = sum->r * 15.f, q__1.i = sum->i * 15.f;
    sum->r = q__1.r, sum->i = q__1.i;
    goto L105;
L100:
    q__2.r = sum->r * 30.f, q__2.i = sum->i * 30.f;
    r__1 = 1.f - cos(con_1.pi2 * 2.f * cur_1.eil);
    q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
    sum->r = q__1.r, sum->i = q__1.i;
L105:
    return 0;
} /* coll_ */

