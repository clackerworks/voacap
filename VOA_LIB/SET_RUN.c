/* SET_RUN.f -- translated by f2c (version 20240504).
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

/* Table of constant values */

static integer c__50 = 50;
static integer c__10 = 10;
static integer c__2 = 2;
static integer c__3 = 3;

/* Subroutine */ int set_run__(void)
{
    /* Initialized data */

    static char subs[10*12] = "/ANTENNAS/" "/AREADATA/" "/BIN_WIN/ " "/COEFF"
	    "S/  " "/DATABASE/" "/GEOCITY/ " "/GEONATIO/" "/GEOSTATE/" "/HELP"
	    "_WIN/" "/NEWS_WIN/" "/SAVED/   " "/USERDB/  ";

    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__, nch, idx;
    static char tmp[50];
    extern /* Subroutine */ int ucase_(char *, integer *, ftnlen);
    extern integer lcount_(char *, integer *, ftnlen);

/*  set current directory to ..\RUN */
    nch = lcount_(crun_directory__1.run_directory__, &c__50, (ftnlen)50);
/*      if(run_directory(nch-3:nch).eq.'\RUN') go to 900    !  ok */
/*      if(run_directory(nch-3:nch).eq.'\run') go to 900    !  ok */
/*          force this to be the RUN sub-directory */
    s_copy(tmp, crun_directory__1.run_directory__, (ftnlen)50, (ftnlen)50);
    ucase_(tmp, &nch, (ftnlen)50);
/*  convert to UPPER case */
    for (i__ = 1; i__ <= 12; ++i__) {
	nch = lcount_(subs + (i__ - 1) * 10, &c__10, (ftnlen)10);
	idx = i_indx(tmp, subs + (i__ - 1) * 10, (ftnlen)50, nch);
	if (idx <= 0) {
	    goto L10;
	}
/* Writing concatenation */
	i__1[0] = idx, a__1[0] = tmp;
	i__1[1] = 3, a__1[1] = "RUN";
	s_cat(crun_directory__1.run_directory__, a__1, i__1, &c__2, (ftnlen)
		50);
/*         go to 900 */
L10:
	;
    }
/* 900   call attach@(run_directory,error_code)    !  reset to the RUN directory */
    return 0;
} /* set_run__ */

/* -------------------------------------------------------------------- */
/* Subroutine */ int get_run__(void)
{
    /* System generated locals */
    address a__1[3];
    integer i__1, i__2, i__3[3];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer nch;
    static char tmp[50];
    extern /* Subroutine */ int ucase_(char *, integer *, ftnlen);
    extern integer lcount_(char *, integer *, ftnlen), lenchar_(char *, 
	    ftnlen);
    static integer nch_run__;

/*  get current directory */
/*      character curdir@*80,tmp*50 */
/*      run_directory=curdir@()      !  get the current directory */
    nch = lenchar_(crun_directory__1.run_directory__, (ftnlen)50);
    ucase_(crun_directory__1.run_directory__, &nch, (ftnlen)50);
    i__1 = nch - 8;
    if (s_cmp(crun_directory__1.run_directory__ + i__1, "BIN_WIN", nch - i__1,
	     (ftnlen)7) == 0) {
	i__2 = nch - 7;
	s_copy(crun_directory__1.run_directory__ + i__2, "RUN", 50 - i__2, (
		ftnlen)3);
    }
    if (s_cmp(crun_directory__1.run_directory__, "//", (ftnlen)2, (ftnlen)2) 
	    != 0) {
	return 0;
    }
    if (*(unsigned char *)&crun_directory__1.run_directory__[3] == '/') {
	nch_run__ = lcount_(crun_directory__1.run_directory__, &c__50, (
		ftnlen)50);
/* Writing concatenation */
	i__3[0] = 1, a__1[0] = crun_directory__1.run_directory__ + 2;
	i__3[1] = 1, a__1[1] = ":";
	i__3[2] = nch_run__ - 3, a__1[2] = crun_directory__1.run_directory__ 
		+ 3;
	s_cat(tmp, a__1, i__3, &c__3, (ftnlen)50);
	s_copy(crun_directory__1.run_directory__, tmp, (ftnlen)50, (ftnlen)50)
		;
    }
    nch = lenchar_(crun_directory__1.run_directory__, (ftnlen)50);
    ucase_(crun_directory__1.run_directory__, &nch, (ftnlen)50);
    return 0;
} /* get_run__ */

