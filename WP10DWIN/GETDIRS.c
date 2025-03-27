/* GETDIRS.f -- translated by f2c (version 20240504).
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

static integer c__20 = 20;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__12 = 12;

/* Subroutine */ int getdirs_(char *basedir, char *list, integer *nmax, 
	integer *num, ftnlen basedir_len, ftnlen list_len)
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3], i__2;
    char ch__1[50];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer f_open(olist *), f_rew(alist *), s_rsfe(cilist *), do_fio(integer 
	    *, char *, ftnlen), e_rsfe(void), f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer nch, ier;
    static char based[20];
    extern integer lcount_(char *, integer *, ftnlen);
    static char dirname[12];
    extern integer isystem_(char *, integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 31, 1, "(a)", 0 };


/* ******************************************************************* */
/*         get list of antenna file directories */
/*         under the directory "basedir" */
/* ******************************************************************* */
    /* Parameter adjustments */
    list -= 14;

    /* Function Body */
    s_copy(based, basedir, (ftnlen)20, basedir_len);
    nch = lcount_(based, &c__20, (ftnlen)20);
/* Writing concatenation */
    i__1[0] = 4, a__1[0] = "dir ";
    i__1[1] = nch, a__1[1] = based;
    i__1[2] = 26, a__1[2] = " /one /A:D /b /-p>dirs.lst";
    s_cat(ch__1, a__1, i__1, &c__3, (ftnlen)50);
    i__2 = nch + 30;
    ier = isystem_(ch__1, &i__2, nch + 30);
    o__1.oerr = 1;
    o__1.ounit = 31;
    o__1.ofnmlen = 8;
    o__1.ofnm = "dirs.lst";
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__2 = f_open(&o__1);
    if (i__2 != 0) {
	goto L900;
    }
    al__1.aerr = 0;
    al__1.aunit = 31;
    f_rew(&al__1);
    *num = 0;
L10:
    i__2 = s_rsfe(&io___4);
    if (i__2 != 0) {
	goto L100;
    }
    i__2 = do_fio(&c__1, dirname, (ftnlen)12);
    if (i__2 != 0) {
	goto L100;
    }
    i__2 = e_rsfe();
    if (i__2 != 0) {
	goto L100;
    }
    ++(*num);
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = 12, a__1[1] = dirname;
    i__1[2] = 1, a__1[2] = " ";
    s_cat(list + *num * 14, a__1, i__1, &c__3, (ftnlen)14);
    if (*num < *nmax) {
	goto L10;
    }
L100:
    cl__1.cerr = 0;
    cl__1.cunit = 31;
    cl__1.csta = 0;
    f_clos(&cl__1);
    ier = isystem_("del dirs.lst", &c__12, (ftnlen)12);
    return 0;
L900:
    s_stop("In GETDIRS Could not OPEN file=dirs.lst", (ftnlen)39);
    return 0;
} /* getdirs_ */

