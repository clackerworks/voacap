/* GETFILES.f -- translated by f2c (version 20240504).
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

static integer c__8 = 8;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__16 = 16;

/* Subroutine */ int getfiles_(char *directory, char *list, integer *nmax, 
	integer *num, ftnlen directory_len, ftnlen list_len)
{
    /* Format strings */
    static char fmt_911[] = "(\002 Could not OPEN file=\002,a)";

    /* System generated locals */
    address a__1[3], a__2[4];
    integer i__1[3], i__2, i__3[4];
    char ch__1[52], ch__2[33];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), f_rew(alist *), s_rsfe(cilist *), do_fio(integer 
	    *, char *, ftnlen), e_rsfe(void), s_cmp(char *, char *, ftnlen, 
	    ftnlen), f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_paus(char *, ftnlen);

    /* Local variables */
    static char filename[12];
    static integer ier;
    static char description[63];
    static integer nchdir;
    extern integer lcount_(char *, integer *, ftnlen), isystem_(char *, 
	    integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 31, 1, "(a)", 0 };
    static cilist io___5 = { 0, 32, 0, "(a)", 0 };
    static cilist io___7 = { 0, 6, 0, fmt_911, 0 };


/* ******************************************************************* */
/*         get list of antenna file names */
/*         from the directory ..\ANTENNAS\directory */
/* ******************************************************************* */
    /* Parameter adjustments */
    list -= 77;

    /* Function Body */
    nchdir = lcount_(directory, &c__8, (ftnlen)8);
/* Writing concatenation */
    i__1[0] = 16, a__1[0] = "dir ../antennas/";
    i__1[1] = nchdir, a__1[1] = directory;
    i__1[2] = 28, a__1[2] = "*.* /one /b /-p>antfiles.lst";
    s_cat(ch__1, a__1, i__1, &c__3, (ftnlen)52);
    i__2 = nchdir + 45;
    ier = isystem_(ch__1, &i__2, nchdir + 44);
    o__1.oerr = 1;
    o__1.ounit = 31;
    o__1.ofnmlen = 12;
    o__1.ofnm = "antfiles.lst";
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
    i__2 = s_rsfe(&io___3);
    if (i__2 != 0) {
	goto L100;
    }
    i__2 = do_fio(&c__1, filename, (ftnlen)12);
    if (i__2 != 0) {
	goto L100;
    }
    i__2 = e_rsfe();
    if (i__2 != 0) {
	goto L100;
    }
    if (s_cmp(filename, "Path not", (ftnlen)8, (ftnlen)8) == 0) {
	goto L920;
    }
/*  directory does no */
    o__1.oerr = 1;
    o__1.ounit = 32;
    o__1.ofnmlen = nchdir + 25;
/* Writing concatenation */
    i__3[0] = 12, a__2[0] = "../antennas/";
    i__3[1] = nchdir, a__2[1] = directory;
    i__3[2] = 1, a__2[2] = "/";
    i__3[3] = 12, a__2[3] = filename;
    s_cat(ch__2, a__2, i__3, &c__4, (ftnlen)33);
    o__1.ofnm = ch__2;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__2 = f_open(&o__1);
    if (i__2 != 0) {
	goto L910;
    }
    al__1.aerr = 0;
    al__1.aunit = 32;
    f_rew(&al__1);
    s_rsfe(&io___5);
    do_fio(&c__1, description, (ftnlen)63);
    e_rsfe();
    cl__1.cerr = 0;
    cl__1.cunit = 32;
    cl__1.csta = 0;
    f_clos(&cl__1);
    ++(*num);
/* Writing concatenation */
    i__3[0] = 1, a__2[0] = " ";
    i__3[1] = 12, a__2[1] = filename;
    i__3[2] = 1, a__2[2] = " ";
    i__3[3] = 63, a__2[3] = description;
    s_cat(list + *num * 77, a__2, i__3, &c__4, (ftnlen)77);
    if (*num < *nmax) {
	goto L10;
    }
L100:
    cl__1.cerr = 0;
    cl__1.cunit = 31;
    cl__1.csta = 0;
    f_clos(&cl__1);
    ier = isystem_("del antfiles.lst", &c__16, (ftnlen)16);
    return 0;
L900:
    s_stop("In GETFILES Could not OPEN file=antfiles.lst", (ftnlen)44);
L910:
    s_wsfe(&io___7);
/* Writing concatenation */
    i__3[0] = 12, a__2[0] = "../antennas/";
    i__3[1] = nchdir, a__2[1] = directory;
    i__3[2] = 1, a__2[2] = "/";
    i__3[3] = 12, a__2[3] = filename;
    s_cat(ch__2, a__2, i__3, &c__4, (ftnlen)33);
    do_fio(&c__1, ch__2, nchdir + 25);
    e_wsfe();
    s_paus("OPEN error in getfiles", (ftnlen)22);
    return 0;
L920:
    cl__1.cerr = 0;
    cl__1.cunit = 31;
    cl__1.csta = 0;
    f_clos(&cl__1);
/*  directory does not exist */
    return 1;
} /* getfiles_ */

