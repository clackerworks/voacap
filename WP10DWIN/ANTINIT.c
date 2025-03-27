/* ANTINIT.f -- translated by f2c (version 20240504).
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
    real floor;
} floorc_;

#define floorc_1 floorc_

struct {
    real d1, e1, f1, p1, q1, s1, beta, rlambda;
} general_;

#define general_1 general_

struct {
    real cpfr, cp11, fr1, h1, pfr, p11, p11s, q2, r2, r3, sl;
} cros_;

#define cros_1 cros_

struct {
    real ro, costh, sinth, rnumb, gamma, epq;
} surf_;

#define surf_1 surf_

struct {
    real uust;
    integer nat;
    real ah1, bh1;
} ccparm_;

#define ccparm_1 ccparm_

struct {
    real a[362], b[362];
} trig_;

#define trig_1 trig_

struct {
    real gain_type11__[91];
} ctype11g_;

#define ctype11g_1 ctype11g_

struct {
    char antname_11__[20];
} ctype11n_;

#define ctype11n_1 ctype11n_

struct {
    char antname12[10];
} cantname12_;

#define cantname12_1 cantname12_

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b94 = .25;
static integer c__2 = 2;

/* Subroutine */ int antinit_(integer *iant, real *parm, char *antde, real *
	z6, real *umax, real *vmax, ftnlen antde_len)
{
    /* Initialized data */

    static integer ionce = 0;

    /* Format strings */
    static char fmt_1[] = "(a10,2x,\002HR\002,i2,\002/\002,i2,\002/\002,f5.2)"
	    ;
    static char fmt_2[] = "(a10,2x,\002HRS\002,i2,\002/\002,i2,\002/\002,f5."
	    "2,\002(\002,i3,\002)\002)";
    static char fmt_101[] = "(\002HR\002,i2,\002/\002,i2,\002/\002,f4.1)";
    static char fmt_102[] = "(\002HRS\002,i2,\002/\002,i2,\002/\002,f4.1,"
	    "\002(\002,i3,\002)\002)";
    static char fmt_201[] = "(\002HR\002,i2,\002/\002,i2,\002/\002,f4.1)";
    static char fmt_202[] = "(\002HRS\002,i2,\002/\002,i2,\002/\002,f4.1,"
	    "\002(\002,i3,\002)\002)";
    static char fmt_301[] = "(\002TR\002,i2,\002/\002,i2,\002/\002,f4.1)";
    static char fmt_302[] = "(\002TRS\002,i2,\002/\002,i2,\002/\002,f4.1,"
	    "\002(\002,i3,\002)\002)";
    static char fmt_501[] = "(\002LPH \002,i2,\002/\002,f4.1,\002/\002,f4.1"
	    ",\002/\002,f5.1,\002/\002,i2,\002/\002,f5.2,\002/\002,f5.1)";
    static char fmt_701[] = "(\002RH \002,i3,\002/\002,f4.1,\002/\002,i3)";
    static char fmt_801[] = "(\002HQ 1/\002,f4.1)";
    static char fmt_901[] = "(\002HX\002,f4.1)";
    static char fmt_1001[] = "(\002/\002,f4.1,\002/\002,i3,\002/\002,i2)";
    static char fmt_1002[] = "(\002VM\002,i2,a12)";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];
    real r__1, r__2, r__3, r__4;
    doublereal d__1;
    icilist ici__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), i_nint(real 
	    *), e_wsfi(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double cos(doublereal), sin(doublereal), log(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double atan(doublereal), sqrt(doublereal), pow_dd(doublereal *, 
	    doublereal *);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int parmprec_(integer *, integer *);
    static real g;
    static integer i__;
    static real z0, dc, fd;
    static char cl[12];
    static real sd, fr, wd, ws, rl1;
    static integer nel;
    static real phi;
    static integer ifs;
    static real fdx, fdx1, fdx2, diam, hnel, gmax, giso, epsr, vvst;
    static integer ielev, iperf;
    static real rlnel;
    static char antmp[48];
    extern /* Subroutine */ int gainorm_(real *, real *, real *, integer *, 
	    integer *, integer *), logparm_(integer *, integer *, real *, 
	    real *, real *, real *, real *, real *), trigfun_(real *, real *, 
	    real *), curnorm_(real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static icilist io___22 = { 0, cl, 0, fmt_1001, 12, 1 };


/* ******************************************************************* */
/*       PURPOSE: */
/*          initialize CCIR antenna calculations */
/*       INPUT  PARAMETERS: */
/*          iant  = antenna index number [0-11] */
/*          parm(1-n) = parameters that define the antenna characteristics */
/*       OUTPUT PARAMETERS: */
/*          antde = [character*48] antenna descriptive name (e.g. HR 4/4/.5) */
/*          z6 = gain normalizing factor (used by ccirgain) */
/*          umax = elevation angle at z6 */
/*          vmax = azimuthal angle at z6 */
/* ******************************************************************* */
/*       Written by Greg Hand NTIA/ITS Boulder, Colorado   Aug 1991 */
/*       Please call (303)497-3375 with any questions. */
/* ******************************************************************* */
/*       Calls following routines: */
/*          trigfun */
/*          logparm */
/*          parmprec */
/*          gainorm */
/* ******************************************************************* */
/*                                  antenna floor value  [25dbi] */

    /* Parameter adjustments */
    --parm;

    /* Function Body */

    if (ionce == 0) {
	ionce = 1;
/*                                      antenna floor value [30dbi] */
	floorc_1.floor = 30.f;
	general_1.p1 = 3.1415927f;
	general_1.q1 = general_1.p1 / 180;
	ccparm_1.uust = 1.f;
	vvst = 1.f;
	trigfun_(trig_1.a, trig_1.b, &ccparm_1.uust);
    }
/* ========================================================================= */
    if (*iant == 0) {
	goto L10;
    }
    if (*iant == 11) {
	goto L1100;
    }
    if (*iant == 12) {
/*  NTIA Report 83-215 Curtain Arrays */
	if (*z6 < -1e3f || *z6 == 0.f) {
	    *z6 = 1.f;
	}
	curnorm_(&parm[1], z6, umax, vmax, &gmax);
	ifs = parm[15];
/*  slew angle */
	if (parm[10] < 0.f) {
	    cros_1.h1 = -parm[10];
	} else {
	    cros_1.h1 = parm[10] * parm[8] / 299.79246f;
	}
	if (ifs == 0) {
	    ici__1.icierr = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = antde_len;
	    ici__1.iciunit = antde;
	    ici__1.icifmt = fmt_1;
	    s_wsfi(&ici__1);
	    do_fio(&c__1, cantname12_1.antname12, (ftnlen)10);
	    i__1 = i_nint(&parm[6]);
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    i__2 = i_nint(&parm[7]);
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	    e_wsfi();
	} else {
	    ici__1.icierr = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = antde_len;
	    ici__1.iciunit = antde;
	    ici__1.icifmt = fmt_2;
	    s_wsfi(&ici__1);
	    do_fio(&c__1, cantname12_1.antname12, (ftnlen)10);
	    i__1 = i_nint(&parm[6]);
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    i__2 = i_nint(&parm[7]);
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&ifs, (ftnlen)sizeof(integer));
	    e_wsfi();
	}
	goto L2015;
    }
    general_1.e1 = parm[3];
    general_1.s1 = parm[4];
    general_1.f1 = parm[5];
    general_1.d1 = general_1.s1 * 18000 / general_1.f1;
    general_1.rlambda = 299.8f / general_1.f1;
    general_1.beta = general_1.p1 * 2 / general_1.rlambda;
/* ========================================================================= */
    if (*iant < 0 || *iant > 10) {
	s_stop("In antinit: iant out of range", (ftnlen)29);
    }
    switch (*iant + 1) {
	case 1:  goto L10;
	case 2:  goto L100;
	case 3:  goto L200;
	case 4:  goto L200;
	case 5:  goto L400;
	case 6:  goto L500;
	case 7:  goto L500;
	case 8:  goto L700;
	case 9:  goto L800;
	case 10:  goto L800;
	case 11:  goto L1000;
    }
/* ***************************************************************** */
/*          iant = 0 */
/*          Isotrope */
/* ***************************************************************** */
L10:
    *umax = 0.f;
    *vmax = 0.f;
    giso = parm[1];
    *z6 = 1.f;
    ifs = 0;
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = antde_len;
    ici__1.iciunit = antde;
    ici__1.icifmt = "('ISO ',f5.1)";
    s_wsfi(&ici__1);
    do_fio(&c__1, (char *)&giso, (ftnlen)sizeof(real));
    e_wsfi();
    goto L2010;
/* ***************************************************************** */
/*          iant = 1 */
/*          Multi-band Center-Fed Half-Wave Dipole Array */
/* ***************************************************************** */
L100:
    cros_1.r2 = parm[6];
    cros_1.r3 = parm[7];
    fd = parm[8];
    cros_1.h1 = parm[9];
    ifs = parm[10];
    sd = parm[11];
    ws = parm[12];
    wd = parm[13];
    *umax = parm[14];
    *vmax = parm[15];
    giso = parm[16];
    *z6 = parm[17];
    if (ifs == 0) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = antde_len;
	ici__1.iciunit = antde;
	ici__1.icifmt = fmt_101;
	s_wsfi(&ici__1);
	i__1 = (integer) cros_1.r2;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	i__2 = (integer) cros_1.r3;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	e_wsfi();
    } else {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = antde_len;
	ici__1.iciunit = antde;
	ici__1.icifmt = fmt_102;
	s_wsfi(&ici__1);
	i__1 = (integer) cros_1.r2;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	i__2 = (integer) cros_1.r3;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&ifs, (ftnlen)sizeof(integer));
	e_wsfi();
    }
    fr = general_1.f1 / fd;
    cros_1.pfr = general_1.p1 * fr;
    cros_1.p11 = cros_1.pfr / 2.f;
    cros_1.p11s = cros_1.p11 * 8 * sd;
    cros_1.cpfr = cos(cros_1.pfr);
    cros_1.cp11 = cos(cros_1.p11);
    cros_1.sl = sin(ifs * general_1.q1);
    fdx = ws / (wd * general_1.p1 * .001f);
    fdx1 = log(fdx);
    fdx2 = ws * .048f;
    cros_1.fr1 = fdx1 * fdx2 * fr;
    goto L2000;
/* **************************************************************** */
/*          iant = 2 */
/*          Dual-Band Center-Fed Half-Wave Dipole Array */
/*       &  iant = 3 */
/*          Dual-Band End-Fed Half-Wave Dipole Array */
/* **************************************************************** */
L200:
    cros_1.r2 = parm[6];
    cros_1.r3 = parm[7];
    fd = parm[8];
    cros_1.h1 = parm[9];
    ifs = parm[10];
    cros_1.q2 = parm[11];
    *umax = parm[12];
    *vmax = parm[13];
    giso = parm[14];
    if (ifs == 0) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = antde_len;
	ici__1.iciunit = antde;
	ici__1.icifmt = fmt_201;
	s_wsfi(&ici__1);
	i__1 = (integer) cros_1.r2;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	i__2 = (integer) cros_1.r3;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	e_wsfi();
    } else {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = antde_len;
	ici__1.iciunit = antde;
	ici__1.icifmt = fmt_202;
	s_wsfi(&ici__1);
	i__1 = (integer) cros_1.r2;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	i__2 = (integer) cros_1.r3;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&ifs, (ftnlen)sizeof(integer));
	e_wsfi();
    }
    fr = general_1.f1 / fd;
    cros_1.pfr = general_1.p1 * fr;
    cros_1.p11 = cros_1.pfr / 2.f;
    cros_1.cpfr = cos(cros_1.pfr);
    cros_1.cp11 = cos(cros_1.p11);
    cros_1.sl = sin(ifs * general_1.q1);
    goto L2000;
/* **************************************************************** */
/*          iant = 4 */
/*          Tropical Array */
/* **************************************************************** */
L400:
    cros_1.r2 = parm[6];
    cros_1.r3 = parm[7];
    fd = parm[8];
    cros_1.h1 = parm[9];
    ifs = parm[10];
    *umax = parm[11];
    *vmax = parm[12];
    giso = parm[13];
    if (ifs == 0) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = antde_len;
	ici__1.iciunit = antde;
	ici__1.icifmt = fmt_301;
	s_wsfi(&ici__1);
	i__1 = (integer) cros_1.r2;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	i__2 = (integer) cros_1.r3;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	e_wsfi();
    } else {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = antde_len;
	ici__1.iciunit = antde;
	ici__1.icifmt = fmt_302;
	s_wsfi(&ici__1);
	i__1 = (integer) cros_1.r2;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	i__2 = (integer) cros_1.r3;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&ifs, (ftnlen)sizeof(integer));
	e_wsfi();
    }
    fr = general_1.f1 / fd;
    cros_1.pfr = general_1.p1 * fr;
    cros_1.p11 = cros_1.pfr / 2.f;
    cros_1.cpfr = cos(cros_1.pfr);
    cros_1.cp11 = cos(cros_1.p11);
    cros_1.sl = sin(ifs * general_1.q1);
    goto L2000;
/* ***************************************************************** */
/*          iant = 5 */
/*          Horizontal Log-Periodic Array */
/*       &  iant = 6 */
/*          Vertical Log-Periodic Array */
/* ***************************************************************** */
L500:
    nel = parm[6];
    rl1 = parm[7] / 2.f;
    rlnel = parm[8] / 2.f;
    dc = parm[9];
    cros_1.h1 = parm[10];
    hnel = parm[11];
    z0 = parm[12];
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = antde_len;
    ici__1.iciunit = antde;
    ici__1.icifmt = fmt_501;
    s_wsfi(&ici__1);
    do_fio(&c__1, (char *)&nel, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&parm[7], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&parm[8], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&dc, (ftnlen)sizeof(real));
    i__1 = (integer) cros_1.h1;
    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&hnel, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&z0, (ftnlen)sizeof(real));
    e_wsfi();
/*          iant=6=vertical */
    if (*iant == 6) {
	s_copy(antde, "LPV", (ftnlen)3, (ftnlen)3);
    }
    logparm_(iant, &nel, &rlnel, &rl1, &hnel, &cros_1.h1, &dc, &z0);
    ifs = 0;
    goto L2000;
/* ****************************************************************** */
/*          iant = 7 */
/*          Horizontal Rhombic */
/* ****************************************************************** */
L700:
    cros_1.sl = parm[6] * general_1.beta;
    cros_1.h1 = parm[7] * general_1.beta * 2;
    surf_1.gamma = parm[8] * general_1.q1;
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = antde_len;
    ici__1.iciunit = antde;
    ici__1.icifmt = fmt_701;
    s_wsfi(&ici__1);
    i__1 = i_nint(&parm[6]);
    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&parm[7], (ftnlen)sizeof(real));
    i__2 = i_nint(&parm[8]);
    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
    e_wsfi();
    surf_1.sinth = sin(surf_1.gamma);
    surf_1.costh = cos(surf_1.gamma);
    ifs = 0;
    goto L2000;
/* ******************************************************************* */
/*          iant = 8 */
/*          Quadrant Antenna */
/*       &  iant = 9 */
/*          Crossed-Dipole Antenna */
/* ******************************************************************* */
L800:
    fd = parm[6];
    cros_1.h1 = parm[7];
    *umax = parm[11];
    *vmax = parm[12];
    giso = parm[13];
    if (*iant == 8) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = antde_len;
	ici__1.iciunit = antde;
	ici__1.icifmt = fmt_801;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	e_wsfi();
    }
    if (*iant == 9) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = antde_len;
	ici__1.iciunit = antde;
	ici__1.icifmt = fmt_901;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&cros_1.h1, (ftnlen)sizeof(real));
	e_wsfi();
    }
    fr = general_1.f1 / fd;
    cros_1.pfr = general_1.p1 * fr;
    cros_1.p11 = cros_1.pfr / 2.f;
    cros_1.cp11 = cos(cros_1.p11);
/*          modified per 18/8/92 : ifs=0 : added */
    ifs = 0;
    goto L2000;
/* *************************************************************** */
/*          iant = 10 */
/*          Vertical Monopole */
/* *************************************************************** */
L1000:
    cros_1.h1 = parm[6] * general_1.beta;
    surf_1.ro = parm[7] * general_1.beta;
    if (surf_1.ro > 0.f) {
	diam = parm[8];
	surf_1.rnumb = parm[9];
	s_wsfi(&io___22);
	do_fio(&c__1, (char *)&parm[7], (ftnlen)sizeof(real));
	i__1 = (integer) surf_1.rnumb;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	i__2 = (integer) diam;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	e_wsfi();
    } else {
	diam = 0.f;
	surf_1.rnumb = 0.f;
	s_copy(cl, " ", (ftnlen)12, (ftnlen)1);
    }
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = antde_len;
    ici__1.iciunit = antde;
    ici__1.icifmt = fmt_1002;
    s_wsfi(&ici__1);
    i__1 = (integer) parm[6];
    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
    do_fio(&c__1, cl, (ftnlen)12);
    e_wsfi();
    ccparm_1.ah1 = sin(cros_1.h1);
    ccparm_1.bh1 = cos(cros_1.h1);
    surf_1.gamma = general_1.beta * surf_1.rnumb * diam * .001f;
    phi = atan(general_1.d1 / general_1.e1) - atan(general_1.d1 / (
	    general_1.e1 - 1)) * .5f;
/* Computing 2nd power */
    r__1 = general_1.e1 - 1;
/* Computing 2nd power */
    r__2 = general_1.d1;
    d__1 = (doublereal) (r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
    r__3 = general_1.e1;
/* Computing 2nd power */
    r__4 = general_1.d1;
    epsr = pow_dd(&d__1, &c_b94) / sqrt(r__3 * r__3 + r__4 * r__4);
/* Computing 2nd power */
    r__1 = epsr;
    surf_1.epq = r__1 * r__1;
    surf_1.sinth = epsr * sin(phi);
    surf_1.costh = epsr * cos(phi);
    ifs = 0;
    goto L2000;
/* ***************************************************************** */
/*          iant = 11 */
/*          Gain Table (91 elevation angles only) */
/* ***************************************************************** */
L1100:
    *umax = 0.f;
/*  elevation angle */
    *vmax = 0.f;
/*  azimuthal angle */
    giso = parm[1];
    *z6 = 1.f;
    gmax = -100.f;
    for (ielev = 1; ielev <= 91; ++ielev) {
	g = giso + ctype11g_1.gain_type11__[ielev - 1];
	if (g <= gmax) {
	    goto L1105;
	}
	gmax = g;
	*umax = (real) ielev;
L1105:
	;
    }
    giso = gmax;
    s_copy(antde, ctype11n_1.antname_11__, antde_len, (ftnlen)20);
    goto L2030;
/* *************************************************************** */
L2000:
    iperf = 0;
    parmprec_(iant, &iperf);
L2010:
    gainorm_(z6, umax, vmax, &iperf, iant, &ifs);
/* *************************************************************** */
/*          get rid of trailing '.', '.0', & '.00' in antenna description */
/*          Some FORTRANs do not handle this well, so I used 'antmp' */
L2015:
    for (i__ = 45; i__ >= 1; --i__) {
	if (s_cmp(antde + (i__ - 1), ".00", (ftnlen)3, (ftnlen)3) == 0) {
	    i__1 = i__ + 2;
/* Writing concatenation */
	    i__3[0] = 48 - i__1, a__1[0] = antde + i__1;
	    i__3[1] = 3, a__1[1] = "   ";
	    s_cat(antmp + (i__ - 1), a__1, i__3, &c__2, 48 - (i__ - 1));
	    s_copy(antde + (i__ - 1), antmp + (i__ - 1), 48 - (i__ - 1), 48 - 
		    (i__ - 1));
	} else if (s_cmp(antde + (i__ - 1), ".0", (ftnlen)2, (ftnlen)2) == 0) 
		{
	    i__1 = i__ + 1;
/* Writing concatenation */
	    i__3[0] = 48 - i__1, a__1[0] = antde + i__1;
	    i__3[1] = 2, a__1[1] = "  ";
	    s_cat(antmp + (i__ - 1), a__1, i__3, &c__2, 48 - (i__ - 1));
	    s_copy(antde + (i__ - 1), antmp + (i__ - 1), 48 - (i__ - 1), 48 - 
		    (i__ - 1));
	} else if (s_cmp(antde + (i__ - 1), "./", (ftnlen)2, (ftnlen)2) == 0) 
		{
	    i__1 = i__;
/* Writing concatenation */
	    i__3[0] = 48 - i__1, a__1[0] = antde + i__1;
	    i__3[1] = 1, a__1[1] = " ";
	    s_cat(antmp + (i__ - 1), a__1, i__3, &c__2, 48 - (i__ - 1));
	    s_copy(antde + (i__ - 1), antmp + (i__ - 1), 48 - (i__ - 1), 48 - 
		    (i__ - 1));
	} else if (s_cmp(antde + (i__ - 1), "/  ", (ftnlen)3, (ftnlen)3) == 0)
		 {
	    i__1 = i__;
	    i__2 = i__ + 2;
/* Writing concatenation */
	    i__3[0] = 48 - i__2, a__1[0] = antde + i__2;
	    i__3[1] = 2, a__1[1] = "  ";
	    s_cat(antmp + i__1, a__1, i__3, &c__2, 48 - i__1);
	    i__1 = i__;
	    i__2 = i__;
	    s_copy(antde + i__1, antmp + i__2, 48 - i__1, 48 - i__2);
	} else if (s_cmp(antde + (i__ - 1), "/ ", (ftnlen)2, (ftnlen)2) == 0) 
		{
	    i__1 = i__;
	    i__2 = i__ + 1;
/* Writing concatenation */
	    i__3[0] = 48 - i__2, a__1[0] = antde + i__2;
	    i__3[1] = 1, a__1[1] = " ";
	    s_cat(antmp + i__1, a__1, i__3, &c__2, 48 - i__1);
	    i__1 = i__;
	    i__2 = i__;
	    s_copy(antde + i__1, antmp + i__2, 48 - i__1, 48 - i__2);
	} else if (s_cmp(antde + (i__ - 1), "  ", (ftnlen)2, (ftnlen)2) == 0) 
		{
	    i__1 = i__;
	    i__2 = i__ + 1;
/* Writing concatenation */
	    i__3[0] = 48 - i__2, a__1[0] = antde + i__2;
	    i__3[1] = 1, a__1[1] = " ";
	    s_cat(antmp + i__1, a__1, i__3, &c__2, 48 - i__1);
	    i__1 = i__;
	    i__2 = i__;
	    s_copy(antde + i__1, antmp + i__2, 48 - i__1, 48 - i__2);
	}
/* L2020: */
    }
L2030:
    return 0;
} /* antinit_ */

