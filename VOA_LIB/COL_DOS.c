/* COL_DOS.f -- translated by f2c (version 20240504).
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
    integer ncolors;
    char colors[120];
    integer index_dos__[20];
    char doscol[120];
} dos_col__;

#define dos_col__1 dos_col__

/* # col_DOS.for */
/* Character */ VOID col_dos__(char *ret_val, ftnlen ret_val_len, integer *
	index, integer *icode)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;

/* convert color index t */
    i__1 = dos_col__1.ncolors;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*index == dos_col__1.index_dos__[i__ - 1]) {
	    if (*icode == 0) {
		s_copy(ret_val, dos_col__1.colors + (i__ - 1) * 6, (ftnlen)6, 
			(ftnlen)6);
	    }
	    if (*icode != 0) {
		s_copy(ret_val, dos_col__1.doscol + (i__ - 1) * 6, (ftnlen)6, 
			(ftnlen)6);
	    }
	    return ;
	}
/* L10: */
    }
    s_copy(ret_val, "Ignore", (ftnlen)6, (ftnlen)6);
/*  Ignore if not found */
    return ;
} /* col_dos__ */

