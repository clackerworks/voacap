/* DEG2CHR.f -- translated by f2c (version 20240504).
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

static integer c__1 = 1;

/* Subroutine */ int deg2chr_(real *degs, integer *latlon, char *char__, 
	ftnlen char_len)
{
    /* Format strings */
    static char fmt_11[] = "(i3,a1,i2,\002'\002,i2,\002\"\002)";

    /* System generated locals */
    real r__1;
    icilist ici__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static real d__, deg;
    static integer min__, ideg, modd, isec;
    static char nsew[1];

/* ****************************************************************** */
/* #  SUB DEG2CHR(DEGS,LATLON,CHAR)   Degrees to CHARACTER (xxxNxx'xx") */
/*          Convert degrees to characters for output. */
/*          DEGS = input degrees (may be -180 to 180  or  0 to 360) */
/*          LATLON=0= latitude   format xxxNxx'xx" */
/*                =1= longitude  format xxxExx'xx" */
/*                =2= latitude   format  xx.xxN */
/*                =3= longitude  format xxx.xxE */
/*          CHAR  = CHARACTER*10 output */
/* ****************************************************************** */
    deg = *degs;
    if (deg > 180.f) {
	deg += -360.f;
    }
    modd = *latlon % 2;
    if (modd == 0 && deg >= 0.f) {
	*(unsigned char *)nsew = 'N';
    }
    if (modd == 0 && deg < 0.f) {
	*(unsigned char *)nsew = 'S';
    }
    if (modd != 0 && deg >= 0.f) {
	*(unsigned char *)nsew = 'E';
    }
    if (modd != 0 && deg < 0.f) {
	*(unsigned char *)nsew = 'W';
    }
    d__ = dabs(deg);
    ideg = d__;
    d__ = (d__ - ideg) * 60.f;
    min__ = d__;
    isec = (d__ - min__) * 60.f + .5f;
    if (isec < 60) {
	goto L10;
    }
    isec = 0;
    ++min__;
    if (min__ < 60) {
	goto L10;
    }
    min__ += -60;
    ++ideg;
L10:
    if (*latlon <= 1) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = char_len;
	ici__1.iciunit = char__;
	ici__1.icifmt = fmt_11;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&ideg, (ftnlen)sizeof(integer));
	do_fio(&c__1, nsew, (ftnlen)1);
	do_fio(&c__1, (char *)&min__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&isec, (ftnlen)sizeof(integer));
	e_wsfi();
    } else {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = char_len;
	ici__1.iciunit = char__;
	ici__1.icifmt = "(f6.2,a1)";
	s_wsfi(&ici__1);
	r__1 = dabs(deg);
	do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	do_fio(&c__1, nsew, (ftnlen)1);
	e_wsfi();
    }
    return 0;
} /* deg2chr_ */

