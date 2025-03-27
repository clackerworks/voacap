/* SUFFIX.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int suffix_(char *ifile, integer *nchm, char *isufx, integer 
	*nchs, ftnlen ifile_len, ftnlen isufx_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static char ich[1];

/*          Append a suffix to the file name */
/*          Search for 1st blank or '.' */
    i__1 = *nchm - *nchs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*(unsigned char *)ich = *(unsigned char *)&ifile[i__ - 1];
	if (*(unsigned char *)ich == ' ' || *(unsigned char *)ich == '.') {
	    goto L20;
	}
/* L10: */
    }
    i__ = *nchm - *nchs + 1;
L20:
    s_copy(ifile + (i__ - 1), isufx, i__ + *nchs - 1 - (i__ - 1), (*nchs));
    return 0;
} /* suffix_ */

