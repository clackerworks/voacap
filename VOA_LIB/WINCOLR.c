/* WINCOLR.f -- translated by f2c (version 20240504).
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
    char dos_colors__[120], colors[200];
    integer ncities_colors__;
    char dos_cities__[42], cities_colors__[140], dos_contours__[48], 
	    contours_colors__[160];
} win_col__;

#define win_col__1 win_col__

struct {
    char run_directory__[50];
} crun_directory__;

#define crun_directory__1 crun_directory__

/* Table of constant values */

static integer c__50 = 50;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__3 = 3;

/* # WINcolr.for */
/* Subroutine */ int wincolr_(void)
{
    /* Format strings */
    static char fmt_11[] = "(a6,1x,a)";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    char ch__1[69], ch__2[68];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), f_rew(alist *), s_rsfe(cilist *), do_fio(integer 
	    *, char *, ftnlen), e_rsfe(void), s_rsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_rsle(void), f_clos(
	    cllist *), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, ncontours_colors__;
    static char skip[1];
    extern integer lcount_(char *, integer *, ftnlen);
    static integer nch_run__;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 17, 0, "(a)", 0 };
    static cilist io___4 = { 0, 17, 0, 0, 0 };
    static cilist io___7 = { 0, 17, 0, fmt_11, 0 };
    static cilist io___8 = { 0, 17, 0, fmt_11, 0 };
    static cilist io___9 = { 0, 17, 0, fmt_11, 0 };
    static cilist io___10 = { 0, 6, 0, "(' Could not OPEN file=',a,1h;)", 0 };


/*  read DOS color table */
/*     +            ncontours_colors,DOS_contours(8),contours_colors(8) */
    nch_run__ = lcount_(crun_directory__1.run_directory__, &c__50, (ftnlen)50)
	    ;
    o__1.oerr = 1;
    o__1.ounit = 17;
    o__1.ofnmlen = nch_run__ + 16;
/* Writing concatenation */
    i__2[0] = nch_run__ - 3, a__1[0] = crun_directory__1.run_directory__;
    i__2[1] = 19, a__1[1] = "database/colors.win";
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
    s_rsfe(&io___2);
    do_fio(&c__1, skip, (ftnlen)1);
    e_rsfe();
/*  skip header card */
    s_rsle(&io___4);
    do_lio(&c__3, &c__1, (char *)&win_col__1.ncolors, (ftnlen)sizeof(integer))
	    ;
    do_lio(&c__3, &c__1, (char *)&win_col__1.ncities_colors__, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&ncontours_colors__, (ftnlen)sizeof(integer))
	    ;
    e_rsle();
    i__1 = win_col__1.ncolors;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	s_rsfe(&io___7);
	do_fio(&c__1, win_col__1.dos_colors__ + (i__ - 1) * 6, (ftnlen)6);
	do_fio(&c__1, win_col__1.colors + (i__ - 1) * 10, (ftnlen)10);
	e_rsfe();
    }
    i__1 = win_col__1.ncities_colors__;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	s_rsfe(&io___8);
	do_fio(&c__1, win_col__1.dos_cities__ + (i__ - 1) * 6, (ftnlen)6);
	do_fio(&c__1, win_col__1.cities_colors__ + (i__ - 1) * 20, (ftnlen)20)
		;
	e_rsfe();
    }
    i__1 = ncontours_colors__;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	s_rsfe(&io___9);
	do_fio(&c__1, win_col__1.dos_contours__ + (i__ - 1) * 6, (ftnlen)6);
	do_fio(&c__1, win_col__1.contours_colors__ + (i__ - 1) * 20, (ftnlen)
		20);
	e_rsfe();
    }
    cl__1.cerr = 0;
    cl__1.cunit = 17;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
L900:
    s_wsfe(&io___10);
/* Writing concatenation */
    i__2[0] = nch_run__ - 3, a__1[0] = crun_directory__1.run_directory__;
    i__2[1] = 18, a__1[1] = "databasecolors.win";
    s_cat(ch__2, a__1, i__2, &c__2, (ftnlen)68);
    do_fio(&c__1, ch__2, nch_run__ + 15);
    e_wsfe();
    s_stop("Missing file ..databasecolors.win in WINcolr", (ftnlen)44);
    return 0;
} /* wincolr_ */

