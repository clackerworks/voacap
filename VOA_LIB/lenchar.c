/* lenchar.f -- translated by f2c (version 20240504).
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

integer lenchar_(char *label, ftnlen label_len)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer i_len(char *, ftnlen);

    /* Local variables */
    static integer i__, max__;

    max__ = i_len(label, label_len);
    for (i__ = max__; i__ >= 1; --i__) {
	if (*(unsigned char *)&label[i__ - 1] == '\0') {
	    goto L10;
	}
	if (*(unsigned char *)&label[i__ - 1] != ' ') {
	    goto L20;
	}
L10:
	;
    }
L20:
    ret_val = i__;
    return ret_val;
} /* lenchar_ */

