/* CHARDEG.f -- translated by f2c (version 20240504).
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

/* Table of constant values */

static real c_b22 = 10.f;

/* Subroutine */ int chardeg_(char *card, integer *latlon, real *deg, integer 
	*ierr, ftnlen card_len)
{
    /* Initialized data */

    static real dmax__[2] = { 90.f,360.f };

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double pow_ri(real *, integer *);

    /* Local variables */
    static integer i__, n, ii;
    static char ich[1];
    static integer min__, idec, idel, isec, ionce, isign;

/* ****************************************************************** */
/* #  SUB CHARDEG(CARD,LATLON,DEG,IERR)  CHAR string to LAT LON degrees */
/*          Convert a CHARACTER string to degrees of LAT or LONG. */
/*          Input may be of the form: */
/*               dddXmm'ss"   dddXmm    dddX   ddd.dddX */
/*               ddd.ddd     -ddd.ddd */
/*          where  X=N or S for latitude */
/*                  =E or W for longitude */
/*                 W longitude is negative */
/*                 E latitude  is negative */
/* ****************************************************************** */
/*          LATLON = 0 = LATITUDE */
/*                 = 1 = LONGITUDE */
/*          *      = ERROR RETURN */
/* ****************************************************************** */
/*  MAX VALUES ALLOWED FOR LAT/LON */
    *ierr = 0;
    *deg = 0.f;
    min__ = 0;
    isec = 0;
    isign = 1;
    idec = 0;
    idel = 0;
/*  COUNTS # OF DELIMITERS */
    ionce = 0;
    ii = 0;
    for (i__ = 1; i__ <= 20; ++i__) {
	*(unsigned char *)ich = *(unsigned char *)&card[i__ - 1];
	if (ionce == 0 && *(unsigned char *)ich == ' ') {
	    goto L100;
	}
/*  skip leading blanks */
	ionce = 1;
	if (*(unsigned char *)ich == ' ' || *(unsigned char *)ich == ',') {
	    goto L150;
	}
/*  END OF STRING */
	if (idel == 3) {
	    goto L80;
	}
/*  SOMETHING AFTER SECONDS */
	if (*(unsigned char *)ich == '-') {
	    goto L10;
	}
/*  - SIGN */
	if (*(unsigned char *)ich == '.') {
	    goto L20;
	}
/*  . decimal point */
	if (*(unsigned char *)ich >= '0' && *(unsigned char *)ich <= '9') {
	    goto L30;
	}
/*  0-9 number */
	++idel;
	if (idel == 1) {
	    goto L70;
	}
/*  1st DELIMITER--CHECK DIRECTION */
	goto L99;
L10:
	if (ii != 0) {
	    *ierr = -3;
	}
/*  - MUST be 1st character */
	isign = -1;
	goto L99;
L20:
	if (idec != 0) {
	    *ierr = -4;
	}
/*  Only 1 decimal point allowed */
	if (idel != 0) {
	    *ierr = -5;
	}
/*  Must be before any delimiters */
	idec = 1;
	goto L99;
L30:
	n = *(unsigned char *)ich - '0';
/*  Convert to a number */
	if ((i__1 = idel - 1) < 0) {
	    goto L40;
	} else if (i__1 == 0) {
	    goto L50;
	} else {
	    goto L60;
	}
L40:
	if (idec != 0) {
	    goto L45;
	}
/*  Fractions */
	*deg = *deg * 10.f + (real) n;
	goto L99;
L45:
	*deg += (real) n / pow_ri(&c_b22, &idec);
	++idec;
	goto L99;
L50:
	min__ = min__ * 10 + n;
	if (min__ >= 60) {
	    *ierr = -6;
	}
/*  BAD minutes */
	goto L99;
L60:
	isec = isec * 10 + n;
	if (isec >= 60) {
	    *ierr = -7;
	}
/*  BAD seconds */
	goto L99;
L70:
	if (*latlon != 0) {
	    goto L75;
	}
/*  LONGITUDE */
	if (*(unsigned char *)ich == 'n') {
	    *(unsigned char *)ich = 'N';
	}
	if (*(unsigned char *)ich == 's') {
	    *(unsigned char *)ich = 'S';
	}
	if (*(unsigned char *)ich != 'N' && *(unsigned char *)ich != 'S') {
	    *ierr = -10;
	}
/*  BAD DIRECTION */
	if (*(unsigned char *)ich == 'S') {
	    isign = -isign;
	}
	goto L99;
L75:
	if (*(unsigned char *)ich == 'e') {
	    *(unsigned char *)ich = 'E';
	}
	if (*(unsigned char *)ich == 'w') {
	    *(unsigned char *)ich = 'W';
	}
	if (*(unsigned char *)ich != 'E' && *(unsigned char *)ich != 'W') {
	    *ierr = -11;
	}
/*  BAD DIRECTION */
	if (*(unsigned char *)ich == 'W') {
	    isign = -isign;
	}
	goto L99;
L80:
	*ierr = -2;
/*  SOMETHING AFTER SECONDS DELIMITER */
L99:
	if (*ierr < 0) {
	    return 0;
	}
	++ii;
L100:
	;
    }
    *ierr = -8;
/*  Can't be this long of a character string */
    return 0;
L150:
    *deg = *deg + (real) min__ / 60.f + (real) isec / 3600.f;
    if (*deg > dmax__[*latlon]) {
	*ierr = -9;
    }
/*  BAD VALUE */
    if (*latlon == 1 && *deg > 180.f) {
	*deg += -360.f;
    }
    *deg *= isign;
    return 0;
} /* chardeg_ */

