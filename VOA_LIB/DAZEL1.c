/* DAZEL1.f -- translated by f2c (version 20240504).
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
    real ztlat, ztlon, ztht, zrlat, zrlon, zrht, ztaz, zraz, ztelv, zrelv, zd,
	     zdgc, ztakof, zrakof;
} azel_;

#define azel_1 azel_

/* Subroutine */ int dazel1_(void)
{
    /* Initialized data */

    static doublereal pi = 3.141592653589793238462643;
    static doublereal rerth = 6370.;
    static doublereal dtor = .01745329252;
    static doublereal rtod = 57.29577951;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal), sqrt(doublereal), atan2(
	    doublereal, doublereal), d_sign(doublereal *, doublereal *), atan(
	    doublereal);

    /* Local variables */
    static doublereal b, d__, p, da, gc, arc, arg, sgc, aht, bht, aalt, balt, 
	    cosb, aelv, belv, tazr, rhts, thts, r4thd, cosgc, delht, colat, 
	    singc, cosco, drlat, saelv, sinco, rdlon, tlatr, tlonr, atakof, 
	    btakof;

/* #  SUB DAZEL1                 Same as CALL DAZEL(1) */

/*     TWO MODES--   0   INPUT LAT AND LON OF END POINT */
/*                       RETURN DISTANCE AND AZIMUTH TO END PT WITH ELEVATIONS */
/*                   1   INPUT BEARING (AZIMUTH) OF END POINT */
/*                       RETURN LAT AND LON OF END POINT WITH ELEVATIONS */

/*   MODE 0 */
/*   INPUT PARAMETERS (THESE DEFINE LOCATION OF POINTS T (TRANSMITTER) */
/*     AND R (RECEIVER) RELATIVE TO A SPHERICAL EARTH. */
/*     ZTLAT - LATITUDE (DECIMAL DEGREES NORTH OF EQUATOR) OF POINT T */
/*     ZTLON - LONGITUDE (DECIMAL DEGREES EAST OF PRIME (GREENWICH) */
/*            MERIDIAN) OF POINT T */
/*     ZTHT  - HEIGHT (METERS ABOVE MEAN SEA LEVEL) OF POINT T */
/*     ZRLAT - LATITUDE (DECIMAL DEGREES NORTH OF EQUATOR) OF POINT R */
/*     ZRLON - LONGITUDE (DECIMAL DEGREES EAST OF PRIME MERIDIAN OF POINT R */
/*     ZRHT  - HEIGHT (METERS ABOVE MEAN SEA LEVEL) OF POINT R */

/*   OUTPUT PARAMETERS */
/*     ZTAZ  - AZUMUTH (DECIMAL DEGREES CLOCKWISE FROM NORTH) AT T OF R */
/*     ZRAZ  - AZIMUTH (DECIMAL DEGREES CLOCKWISE FROM NORTH) AT R OF T */
/*     ZTELV - ELEVATION ANGLE (DECIMAL DEGREES ABOVE HORIZONTAL AT T */
/*            OF STRAIGHT LINE BETWEEN T AND R */
/*     ZRELV - ELEVATION ANGLE (DECIMAL DEGREES ABOVE HORIZONTAL AT R) */
/*            OF STRAIGHT LINE BETWEEN T AND R */
/*     ZTAKOF - TAKE-OFF ANGLE (DECIMAL DEGREES ABOVE HORIZONTAL AT T) */
/*            OF REFRACTED RAY BETWEEN T AND R (ASSUMED 4/3 EARTH RADIUS) */
/*     ZRAKOF - TAKE-OFF ANGLE (DECIMAL DEGREES ABOVE HORIZONTAL AT R) */
/*            OF REFRACTED RAY BETWEEN T AND R (ASSUMED 4/3 EARTH RADIUS) */
/*     ZD    - STRAIGHT LINE DISTANCE (KILOMETERS) BETWEEN T AND R */
/*     ZDGC  - GREAT CIRCLE DISTANCE (KILOMETERS) BETWEEN T AND R */

/*   MODE 1 */
/*   INPUT PARAMETERS                    OUTPUT PARAMETERS */
/*     ZTLAT                                ZRLAT */
/*     ZTLON                                ZRLON */
/*     ZTAZ                                 RELEV,ZRAKOF */
/*     ZDGC                                 TELEV,ZTAKOF */


/*     ALL OF THE ABOVE PARAMETERS START WITH THE LETTER Z AND ARE SINGLE */
/*     PRECISION.  ALL PROGRAM VARIABLES ARE DOUBLE PRECISION. */
/*     PROGRAM IS UNPREDICTABLE FOR SEPARATIONS LESS THAN 0.00005 DEGREES, */
/*     ABOUT 5 METERS. */

/*   WRITTEN BY KEN SPIES 5/79 */
/*   REFRACTION AND ST. LINE ELEVATIONS BY EJH */


/*     COMPUTE END POINT GIVEN DISTANCE AND BEARING */

/* L200: */
    tlatr = azel_1.ztlat * dtor;
    tlonr = azel_1.ztlon * dtor;
    tazr = azel_1.ztaz * dtor;
    gc = azel_1.zdgc / rerth;
    colat = pi / 2.f - tlatr;
    cosco = cos(colat);
    sinco = sin(colat);
    cosgc = cos(gc);
    singc = sin(gc);
    cosb = cosco * cosgc + sinco * singc * cos(tazr);
/* Computing MAX */
    d__1 = 0., d__2 = 1. - cosb * cosb;
    arg = max(d__1,d__2);
    b = atan2(sqrt(arg), cosb);
    arc = (cosgc - cosco * cosb) / (sinco * sin(b));
/* Computing MAX */
    d__1 = 0., d__2 = 1. - arc * arc;
    arg = max(d__1,d__2);
    rdlon = atan2(sqrt(arg), arc);
    azel_1.zrlat = (pi / 2.f - abs(b)) * rtod;
    drlat = azel_1.zrlat;
    azel_1.zrlat = d_sign(&drlat, &cosb);
    azel_1.zrlon = azel_1.ztlon + abs(rdlon) * rtod;
    if (azel_1.ztaz > 180.f) {
	azel_1.zrlon = azel_1.ztlon - abs(rdlon) * rtod;
    }
    thts = azel_1.ztht * .001f;
    rhts = azel_1.zrht * .001f;
    delht = rhts - thts;
    sgc = sin(gc * .5f);
    d__ = sqrt(delht * delht + (rerth + thts) * 4.f * (rerth + rhts) * sgc * 
	    sgc);

/*   COMPUTE GREAT CIRCLE DISTANCE AND ELEVATION ANGLES */

    if (delht >= 0.) {
	goto L145;
    }
    aht = thts;
    bht = rhts;
    goto L150;
L145:
    aht = rhts;
    bht = thts;
L150:
    saelv = (d__ * d__ + abs(delht) * (rerth + aht + rerth + bht)) * .5f / (
	    d__ * (rerth + aht));
/* Computing MAX */
    d__1 = 1e-4, d__2 = 1. - saelv * saelv;
    arg = max(d__1,d__2);
    aelv = atan2(saelv, sqrt(arg));
    belv = (aelv - gc) * rtod;
    aelv = -aelv * rtod;
/*   COMPUTE TAKE-OFF ANGLES ASSUMING 4/3 EARTH RADIUS */
    r4thd = rerth * 4.f / 3.f;
    gc *= .75f;
    sgc = sin(gc * .5f);
    p = sgc * 2.f * sgc;
    aalt = r4thd + aht;
    balt = r4thd + bht;
    da = sqrt(delht * delht + aalt * 2.f * balt * p);
    saelv = (da * da + abs(delht) * (aalt + balt)) * .5f / (da * aalt);
/* Computing MAX */
    d__1 = 1e-4, d__2 = 1. - saelv * saelv;
    arg = max(d__1,d__2);
    atakof = atan(saelv / sqrt(arg));
    btakof = (atakof - gc) * rtod;
    atakof = -atakof * rtod;
    if (delht - 0.f >= 0.) {
	goto L155;
    } else {
	goto L151;
    }
L151:
    azel_1.ztelv = aelv;
    azel_1.zrelv = belv;
    azel_1.ztakof = atakof;
    azel_1.zrakof = btakof;
    return 0;
L155:
    azel_1.ztelv = belv;
    azel_1.zrelv = aelv;
    azel_1.ztakof = btakof;
    azel_1.zrakof = atakof;
    return 0;
} /* dazel1_ */

