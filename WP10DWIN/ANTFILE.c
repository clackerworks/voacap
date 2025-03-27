/* ANTFILE.f -- translated by f2c (version 20240504).
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

/* # antfile.f */
/* Subroutine */ int antfile_(char *dir, char *file, char *antname, ftnlen 
	dir_len, ftnlen file_len, ftnlen antname_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, n;

/*          concatenate dir\file into antname */
    s_copy(antname, "                     ", (ftnlen)21, (ftnlen)21);
    n = 0;
    for (i__ = 1; i__ <= 8; ++i__) {
	if (*(unsigned char *)&dir[i__ - 1] == ' ') {
	    goto L15;
	}
	++n;
	*(unsigned char *)&antname[n - 1] = *(unsigned char *)&dir[i__ - 1];
/* L10: */
    }
L15:
    ++n;
    *(unsigned char *)&antname[n - 1] = '/';
    for (i__ = 1; i__ <= 12; ++i__) {
	if (*(unsigned char *)&file[i__ - 1] == ' ') {
	    goto L25;
	}
	++n;
	*(unsigned char *)&antname[n - 1] = *(unsigned char *)&file[i__ - 1];
/* L20: */
    }
L25:
    return 0;
} /* antfile_ */

