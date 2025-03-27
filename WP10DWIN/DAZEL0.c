/* DAZEL0.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int dazel0_(real *ztlat, real *ztlon, real *zrlat, real *
	zrlon, real *ztaz, real *zdgc)
{
    /* Initialized data */

    static doublereal rerth = 6370.;
    static doublereal dtor = .01745329252;
    static doublereal rtod = 57.29577951;
    static real ztht = 0.f;
    static real zrht = 0.f;

    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sin(doublereal), sqrt(doublereal), cos(doublereal), atan2(
	    doublereal, doublereal);

    /* Local variables */
    static doublereal d__, p, gc;
    static real zd;
    static doublereal cgc, sgc, eaz, waz, ceaz, elat, seaz, cwaz, wlat, rhts, 
	    thts, swaz;
    static real zraz;
    static doublereal adlat, celat, delat, adlon, delht, delon, sadln, sdlat, 
	    cwlat, sdlon, rlats, tlats, rlons, tlons;
    static real zrelv, ztelv;

/* #  SUB DAZEL0             Great circle calculations. (same as DAZEL(0)) */

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

/*                          RERTH changed (from 6368.) 2/26/93 by Greg hand */
    tlats = *ztlat;
    tlons = *ztlon;
    thts = ztht * .001f;
    rlats = *zrlat;
    rlons = *zrlon;
    rhts = zrht * .001f;
    if (tlats <= -90.f) {
	tlats = -89.999f;
    }
    if (tlats >= 90.f) {
	tlats = 89.999f;
    }
    if (rlats <= -90.f) {
	rlats = -89.999f;
    }
    if (rlats >= 90.f) {
	rlats = 89.999f;
    }
/*          bad things happen when points are directly opposite */
/*          the angle is undefined!!!  (move receiver a little) */
    if ((d__2 = (d__1 = tlons - rlons, abs(d__1)) - 180.f, abs(d__2)) <= 
	    .001f && (d__3 = tlats + rlats, abs(d__3)) <= .002f) {
	rlats += .1f;
	if (rlats >= 90.f) {
	    rlats = 89.9f;
	}
    }
    delat = rlats - tlats;
    adlat = abs(delat);
    delon = rlons - tlons;
    if (delon + 180.f >= 0.) {
	goto L16;
    } else {
	goto L12;
    }
L12:
    delon += 360.f;
    if (delon + 180.f >= 0.) {
	goto L20;
    } else {
	goto L12;
    }
L16:
    if (delon - 180.f <= 0.) {
	goto L20;
    } else {
	goto L18;
    }
L18:
    delon += -360.f;
    if (delon - 180.f <= 0.) {
	goto L20;
    } else {
	goto L18;
    }
L20:
    adlon = abs(delon);
    delht = rhts - thts;
    if (adlon - 1e-5f <= 0.) {
	goto L22;
    } else {
	goto L55;
    }
L22:
    if (adlat - 1e-5f <= 0.) {
	goto L24;
    } else {
	goto L40;
    }

/*   POINTS T AND R HAVE THE SAME COORDINATES */

L24:
    *ztaz = 0.f;
    zraz = 0.f;
    if (delht < 0.) {
	goto L25;
    } else if (delht == 0) {
	goto L30;
    } else {
	goto L35;
    }
L25:
    ztelv = -90.f;
    zrelv = 90.f;
    zd = -delht;
    *zdgc = 0.f;
    return 0;
L30:
    ztelv = 0.f;
    zrelv = 0.f;
    zd = 0.f;
    *zdgc = 0.f;
    return 0;
L35:
    ztelv = 90.f;
    zrelv = -90.f;
    zd = delht;
    *zdgc = 0.f;
    return 0;

/*   POINTS T AND R HAVE SAME LONGITUDE, DISTINCT LATITUDES */

L40:
    if (delat - 0.f <= 0.) {
	goto L42;
    } else {
	goto L45;
    }
L42:
    *ztaz = 180.f;
    zraz = 0.f;
    goto L50;
L45:
    *ztaz = 0.f;
    zraz = 180.f;
L50:
    gc = adlat * dtor;
    sgc = sin(gc * .5f);
    d__ = sqrt(delht * delht + (rerth + thts) * 4.f * (rerth + rhts) * sgc * 
	    sgc);
    zd = d__;
    goto L140;

/*   POINTS TAND R HAVE DISTINCT LONGITUDES */

L55:
    if (delon - 0.f <= 0.) {
	goto L56;
    } else {
	goto L60;
    }
L56:
    wlat = rlats * dtor;
    elat = tlats * dtor;
    goto L65;
L60:
    wlat = tlats * dtor;
    elat = rlats * dtor;

/*   CALCULATE AZIMUTHS AT POINTS W AND E */

L65:
    sdlat = sin(adlat * .5f * dtor);
    sdlon = sin(adlon * .5f * dtor);
    sadln = sin(adlon * dtor);
    cwlat = cos(wlat);
    celat = cos(elat);
    p = (sdlat * sdlat + sdlon * sdlon * cwlat * celat) * 2.f;
    sgc = sqrt(p * (2.f - p));
    sdlat = sin(elat - wlat);
    cwaz = (celat * 2.f * sin(wlat) * sdlon * sdlon + sdlat) / sgc;
    swaz = sadln * celat / sgc;
    waz = atan2(swaz, cwaz) * rtod;
    ceaz = (cwlat * 2.f * sin(elat) * sdlon * sdlon - sdlat) / sgc;
    seaz = sadln * cwlat / sgc;
    eaz = atan2(seaz, ceaz) * rtod;
/* L110: */
    eaz = 360.f - eaz;
    if (delon - 0.f <= 0.) {
	goto L111;
    } else {
	goto L115;
    }
L111:
    *ztaz = eaz;
    zraz = waz;
    goto L120;
L115:
    *ztaz = waz;
    zraz = eaz;


/*   COMPUTE THE STRAIGHT LINE DISTANCE AND GREAT CIRCLE ANGLE BETWEEN T AND R */

L120:
    d__ = sqrt(delht * delht + (rerth + thts) * 2.f * (rerth + rhts) * p);
    zd = d__;
    cgc = 1.f - p;
    gc = atan2(sgc, cgc);

/*   COMPUTE GREAT CIRCLE DISTANCE AND ELEVATION ANGLES */

L140:
    *zdgc = gc * rerth;
    return 0;
} /* dazel0_ */

