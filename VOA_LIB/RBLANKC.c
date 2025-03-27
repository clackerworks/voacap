/* RBLANKC.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int rblankc_(char *ialf, integer *nch, ftnlen ialf_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j;
    static char ich[1];
    static integer nchold;

/*  remove ALL blanks */
    j = 0;
    nchold = *nch;
    i__1 = *nch;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*(unsigned char *)ich = *(unsigned char *)&ialf[i__ - 1];
	if (*(unsigned char *)ich == ' ') {
	    goto L10;
	}
	++j;
	*(unsigned char *)&ialf[j - 1] = *(unsigned char *)ich;
L10:
	;
    }
    *nch = j;
    if (*nch < nchold) {
	i__1 = *nch;
	s_copy(ialf + i__1, " ", nchold - i__1, (ftnlen)1);
    }
    return 0;
} /* rblankc_ */

