/* DOSCOLR.f -- translated by f2c (version 20240504).
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
    char run_directory__[50];
} crun_directory__;

#define crun_directory__1 crun_directory__

struct {
    integer ncolors;
    char colors[120];
    integer index_dos__[20];
    char doscol[120];
} dos_col__;

#define dos_col__1 dos_col__

/* Table of constant values */

static integer c__50 = 50;
static integer c__2 = 2;
static integer c__1 = 1;

/* # DOScolr.for */
/* Subroutine */ int doscolr_(void)
{
    /* Format strings */
    static char fmt_11[] = "(a6,i5,2x,a6)";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    char ch__1[69];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), f_rew(alist *), s_rsfe(cilist *), do_fio(integer 
	    *, char *, ftnlen), e_rsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer nc;
    static char skip[1];
    extern integer lcount_(char *, integer *, ftnlen);
    static integer nch_run__;

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 17, 0, "(a)", 0 };
    static cilist io___5 = { 0, 17, 1, fmt_11, 0 };


/*  read DOS color table */
/* ------------------------------------------------------------------ */
    nc = 0;
    nch_run__ = lcount_(crun_directory__1.run_directory__, &c__50, (ftnlen)50)
	    ;
    o__1.oerr = 1;
    o__1.ounit = 17;
    o__1.ofnmlen = nch_run__ + 16;
/* Writing concatenation */
    i__2[0] = nch_run__ - 3, a__1[0] = crun_directory__1.run_directory__;
    i__2[1] = 19, a__1[1] = "database/colors.dat";
    s_cat(ch__1, a__1, i__2, &c__2, (ftnlen)69);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L900;
    }
    al__1.aerr = 0;
    al__1.aunit = 17;
    f_rew(&al__1);
    s_rsfe(&io___3);
    do_fio(&c__1, skip, (ftnlen)1);
    e_rsfe();
/*  skip header card */
L10:
    i__1 = s_rsfe(&io___5);
    if (i__1 != 0) {
	goto L100;
    }
    i__1 = do_fio(&c__1, dos_col__1.colors + nc * 6, (ftnlen)6);
    if (i__1 != 0) {
	goto L100;
    }
    i__1 = do_fio(&c__1, (char *)&dos_col__1.index_dos__[nc], (ftnlen)sizeof(
	    integer));
    if (i__1 != 0) {
	goto L100;
    }
    i__1 = do_fio(&c__1, dos_col__1.doscol + nc * 6, (ftnlen)6);
    if (i__1 != 0) {
	goto L100;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L100;
    }
    ++nc;
    if (nc < 20) {
	goto L10;
    }
L100:
    cl__1.cerr = 0;
    cl__1.cunit = 17;
    cl__1.csta = 0;
    f_clos(&cl__1);
L900:
    dos_col__1.ncolors = nc;
    return 0;
} /* doscolr_ */

