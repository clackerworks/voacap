/* ANTINIT2.f -- translated by f2c (version 20240504).
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
    real parm[20], z6, umax, vmax, giso;
    integer modegain;
    real gainmax[6]	/* was [3][2] */;
} ccirparm_;

#define ccirparm_1 ccirparm_

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

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b15 = .25;

/* Subroutine */ int antinit2_(void)
{
    /* Initialized data */

    static integer ionce = 0;

    /* System generated locals */
    real r__1, r__2, r__3, r__4;
    doublereal d__1;

    /* Builtin functions */
    integer i_nint(real *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double cos(doublereal), sin(doublereal), log(doublereal), atan(doublereal)
	    , sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    extern /* Subroutine */ int parmprec_(integer *, integer *);
    static real z0, dc, fd, sd, fr, wd, ws;
    extern /* Subroutine */ int setmaxgain_(real *);
    static real rl1;
    static integer nel;
    static real phi;
    static integer ifs;
    static real fdx, fdx1, fdx2, diam, hnel;
    static integer iant;
    static real epsr, vvst;
    static integer iperf;
    static real rlnel;
    extern /* Subroutine */ int gainorm_(real *, real *, real *, integer *, 
	    integer *, integer *), logparm_(integer *, integer *, real *, 
	    real *, real *, real *, real *, real *), trigfun_(real *, real *, 
	    real *);

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, "(' iant=',i5)", 0 };


/* ******************************************************************* */
/*       PURPOSE: */
/*          initialize CCIR antenna calculations in propagation programs */
/*       INPUT  PARAMETERS: */
/*          in COMMON /CCIRPARM/ */
/*       OUTPUT PARAMETERS: */
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
/*                                  antenna floor value  [30dBi] */


    iant = i_nint(&ccirparm_1.parm[1]);
/*  CCIR antenna type [0,10] */
    setmaxgain_(&ccirparm_1.parm[4]);
/*  parm(5)=operating freq */
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
    if (iant == 0) {
	goto L10;
    }
    if (iant == 11) {
	return 0;
    }
/*  gain table at elevation angles */
    if (iant == 12) {
	return 0;
    }
/*  NTIA Report 87-215 Curtain Arrays */
    general_1.e1 = ccirparm_1.parm[2];
    general_1.s1 = ccirparm_1.parm[3];
    general_1.f1 = ccirparm_1.parm[4];
    general_1.d1 = general_1.s1 * 18000 / general_1.f1;
    general_1.rlambda = 299.8f / general_1.f1;
    general_1.beta = general_1.p1 * 2 / general_1.rlambda;
/* ========================================================================= */
    if (iant < 0 || iant > 10) {
	s_wsfe(&io___4);
	do_fio(&c__1, (char *)&iant, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("In antinit2: iant out of range", (ftnlen)30);
    }
    switch (iant + 1) {
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
    ccirparm_1.umax = 0.f;
    ccirparm_1.vmax = 0.f;
    ccirparm_1.z6 = 1.f;
    ifs = 0;
    goto L2010;
/* ***************************************************************** */
/*          iant = 1 */
/*          Multi-band Center-Fed Half-Wave Dipole Array */
/* ***************************************************************** */
L100:
    cros_1.r2 = ccirparm_1.parm[5];
    cros_1.r3 = ccirparm_1.parm[6];
    fd = ccirparm_1.parm[7];
    cros_1.h1 = ccirparm_1.parm[8];
    ifs = ccirparm_1.parm[9];
    sd = ccirparm_1.parm[10];
    ws = ccirparm_1.parm[11];
    wd = ccirparm_1.parm[12];
    ccirparm_1.umax = ccirparm_1.parm[13];
    ccirparm_1.vmax = ccirparm_1.parm[14];
    ccirparm_1.z6 = ccirparm_1.parm[16];
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
    cros_1.r2 = ccirparm_1.parm[5];
    cros_1.r3 = ccirparm_1.parm[6];
    fd = ccirparm_1.parm[7];
    cros_1.h1 = ccirparm_1.parm[8];
    ifs = ccirparm_1.parm[9];
    cros_1.q2 = ccirparm_1.parm[10];
    ccirparm_1.umax = ccirparm_1.parm[11];
    ccirparm_1.vmax = ccirparm_1.parm[12];
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
    cros_1.r2 = ccirparm_1.parm[5];
    cros_1.r3 = ccirparm_1.parm[6];
    fd = ccirparm_1.parm[7];
    cros_1.h1 = ccirparm_1.parm[8];
    ifs = ccirparm_1.parm[9];
    ccirparm_1.umax = ccirparm_1.parm[10];
    ccirparm_1.vmax = ccirparm_1.parm[11];
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
    nel = ccirparm_1.parm[5];
    rl1 = ccirparm_1.parm[6] / 2.f;
    rlnel = ccirparm_1.parm[7] / 2.f;
    dc = ccirparm_1.parm[8];
    cros_1.h1 = ccirparm_1.parm[9];
    hnel = ccirparm_1.parm[10];
    z0 = ccirparm_1.parm[11];
/*          iant=6=vertical */
    logparm_(&iant, &nel, &rlnel, &rl1, &hnel, &cros_1.h1, &dc, &z0);
    ifs = 0;
    goto L2000;
/* ****************************************************************** */
/*          iant = 7 */
/*          Horizontal Rhombic */
/* ****************************************************************** */
L700:
    cros_1.sl = ccirparm_1.parm[5] * general_1.beta;
    cros_1.h1 = ccirparm_1.parm[6] * general_1.beta * 2;
    surf_1.gamma = ccirparm_1.parm[7] * general_1.q1;
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
    fd = ccirparm_1.parm[5];
    cros_1.h1 = ccirparm_1.parm[6];
    ccirparm_1.umax = ccirparm_1.parm[10];
    ccirparm_1.vmax = ccirparm_1.parm[11];
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
    cros_1.h1 = ccirparm_1.parm[5] * general_1.beta;
    surf_1.ro = ccirparm_1.parm[6] * general_1.beta;
    if (surf_1.ro > 0.f) {
	diam = ccirparm_1.parm[7];
	surf_1.rnumb = ccirparm_1.parm[8];
    } else {
	diam = 0.f;
	surf_1.rnumb = 0.f;
    }
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
    epsr = pow_dd(&d__1, &c_b15) / sqrt(r__3 * r__3 + r__4 * r__4);
/* Computing 2nd power */
    r__1 = epsr;
    surf_1.epq = r__1 * r__1;
    surf_1.sinth = epsr * sin(phi);
    surf_1.costh = epsr * cos(phi);
    ifs = 0;
/* *************************************************************** */
L2000:
    iperf = 0;
    if (iant == 10) {
	return 0;
    }
/*  vertical monopole is a table */
    parmprec_(&iant, &iperf);
L2010:
    gainorm_(&ccirparm_1.z6, &ccirparm_1.umax, &ccirparm_1.vmax, &iperf, &
	    iant, &ifs);
/* *************************************************************** */
    return 0;
} /* antinit2_ */

