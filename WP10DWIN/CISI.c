/* CISI.f -- translated by f2c (version 20240504).
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

/* # cisi.f */
/* Subroutine */ int cisi_(real *x, real *ci, real *si)
{
    /* Builtin functions */
    double log(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    static real f, g, s, t, x2, sq, term;

/* -------------------------------- */

/* X */
/* CI IS COSINE INTEGRAL OF X */
/* SI IS SINE   INTEGRAL OF X */

    if (*x - 1.f >= 0.f) {
	goto L120;
    } else {
	goto L100;
    }
L100:
    sq = *x * *x;
    *ci = log(*x) + .5772156649f;
    term = sq * -1.f / 4.f;
    g = 4.f;
L105:
    *ci += term;
    term = term * -1.f * sq * (g - 2.f) / ((g - 1.f) * g * g);
    g += 2.f;
    if (dabs(term) - 5e-5f <= 0.f) {
	goto L110;
    } else {
	goto L105;
    }
L110:
    *si = 0.f;
    term = *x;
    g = 3.f;
L115:
    *si += term;
    term = term * -1.f * sq * (g - 2.f) / ((g - 1.f) * g * g);
    g += 2.f;
    if (dabs(term) - 5e-5f <= 0.f) {
	goto L125;
    } else {
	goto L115;
    }
L120:
    x2 = *x * *x;
    t = cos(*x);
    s = sin(*x);
    g = ((((x2 + 48.196927f) * x2 + 482.485984f) * x2 + 1114.978885f) * x2 + 
	    449.690326f) * x2;
    g = ((((x2 + 42.252855f) * x2 + 302.757865f) * x2 + 352.018498f) * x2 + 
	    21.821899f) / g;
    f = ((((x2 + 40.021433f) * x2 + 322.624911f) * x2 + 570.23628f) * x2 + 
	    157.105423f) * *x;
    f = ((((x2 + 38.027264f) * x2 + 265.187033f) * x2 + 335.67732f) * x2 + 
	    38.102495f) / f;
    *si = 1.5708f - f * t - g * s;
    *ci = f * s - g * t;
L125:
    return 0;
} /* cisi_ */

