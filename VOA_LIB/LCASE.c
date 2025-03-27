/* LCASE.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int lcase_(char *ialf, integer *nch, ftnlen ialf_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, ich;

/*          Convert all UPPER case letters in IALF to lower case */
    i__1 = *nch;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ich = *(unsigned char *)&ialf[i__ - 1];
	if (ich >= 65 && ich <= 90) {
	    *(unsigned char *)&ialf[i__ - 1] = (char) (ich + 32);
	}
/* L10: */
    }
    return 0;
} /* lcase_ */

