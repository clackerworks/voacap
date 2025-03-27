/* READANT.f -- translated by f2c (version 20240504).
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
    real freqdesign;
} designfreq_;

#define designfreq_1 designfreq_

struct {
    real gain_type11__[91];
} ctype11g_;

#define ctype11g_1 ctype11g_

struct {
    real gain10[2610]	/* was [90][29] */;
} gain_10__;

#define gain_10__1 gain_10__

struct {
    real parm[20], z6, umax, vmax, giso;
    integer modegain;
    real gainmax[6]	/* was [3][2] */, gainmaxb[30];
} ccirparm_;

#define ccirparm_1 ccirparm_

/* Table of constant values */

static integer c__50 = 50;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__91 = 91;
static integer c__2 = 2;

/* Subroutine */ int readant_(integer *lu, char *filename, char *description, 
	ftnlen filename_len, ftnlen description_len)
{
    /* Format strings */
    static char fmt_11[] = "(10x,10f6.2)";
    static char fmt_16[] = "(10x,f6.2,(t19,10f6.2))";
    static char fmt_17[] = "(10x,5f10.3)";
    static char fmt_901[] = "(\002 Error=\002,i5,\002 OPENing antenna file"
	    "=\002,a,\002.\002)";
    static char fmt_911[] = "(\002 Error reading antenna file=\002,a)";

    /* System generated locals */
    address a__1[3], a__2[2];
    integer i__1[3], i__2, i__3, i__4[2];
    char ch__1[139], ch__2[61];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer f_open(olist *), f_rew(alist *), s_rsfe(cilist *), do_fio(integer 
	    *, char *, ftnlen), e_rsfe(void), s_rsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_rsle(void), i_nint(real *
	    ), s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue(
	    void), f_clos(cllist *), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_paus(char *, ftnlen), s_stop(char *, ftnlen);

    /* Local variables */
    extern integer len_trim__(char *, ftnlen);
    static integer i__, n, nc1;
    static real eff;
    static char alf[80];
    static integer nch, ios, iang, jant;
#define gains ((real *)&ctype11g_1)
    static integer ielev, ifreq;
    extern integer lcount_(char *, integer *, ftnlen);
    extern /* Subroutine */ int rblankc_(char *, integer *, ftnlen);
    static integer nch_run__;

    /* Fortran I/O blocks */
    static cilist io___8 = { 1, 0, 0, "(a)", 0 };
    static cilist io___9 = { 1, 0, 0, 0, 0 };
    static cilist io___11 = { 1, 0, 0, 0, 0 };
    static cilist io___13 = { 1, 0, 0, 0, 0 };
    static cilist io___14 = { 1, 0, 0, 0, 0 };
    static cilist io___15 = { 1, 0, 0, fmt_11, 0 };
    static cilist io___17 = { 1, 0, 0, fmt_16, 0 };
    static cilist io___19 = { 0, 0, 0, 0, 0 };
    static cilist io___20 = { 1, 0, 1, fmt_17, 0 };
    static cilist io___22 = { 0, 0, 0, "(9x,10f7.3)", 0 };
    static cilist io___23 = { 0, 13, 0, 0, 0 };
    static cilist io___24 = { 0, 0, 0, "(2x,f6.1,(t10,10f7.3))", 0 };
    static cilist io___26 = { 0, 14, 0, 0, 0 };
    static cilist io___27 = { 0, 6, 0, fmt_901, 0 };
    static cilist io___28 = { 0, 6, 0, "(' nch=',i5)", 0 };
    static cilist io___29 = { 0, 6, 0, "(' nc1=',i5,'  filename=',a)", 0 };
    static cilist io___30 = { 0, 6, 0, fmt_911, 0 };


    nc1 = len_trim__(filename, filename_len);
    s_copy(alf, filename, (ftnlen)80, filename_len);
    nch = 80;
    rblankc_(alf, &nch, (ftnlen)80);
/* cc      nch=len_trim(alf) */
    if (nch <= 2 || *(unsigned char *)&alf[nch - 1] == '/') {
/* no file name = 0 dB */
	s_copy(description, "0 dB gain", (ftnlen)70, (ftnlen)9);
	n = 2;
	ccirparm_1.parm[0] = 0.f;
	ccirparm_1.parm[1] = 0.f;
	ccirparm_1.modegain = 0;
/*  use giso as max gain */
	designfreq_1.freqdesign = 0.f;
/*  default design freq=operating freq */
	return 0;
    }
    nch_run__ = lcount_(crun_directory__1.run_directory__, &c__50, (ftnlen)50)
	    ;
    o__1.oerr = 1;
    o__1.ounit = *lu;
    o__1.ofnmlen = nch_run__ + 6 + nch;
/* Writing concatenation */
    i__1[0] = nch_run__ - 3, a__1[0] = crun_directory__1.run_directory__;
    i__1[1] = 9, a__1[1] = "antennas/";
    i__1[2] = nch, a__1[2] = alf;
    s_cat(ch__1, a__1, i__1, &c__3, (ftnlen)139);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    ios = f_open(&o__1);
    if (ios != 0) {
	goto L900;
    }
    al__1.aerr = 0;
    al__1.aunit = *lu;
    f_rew(&al__1);
    io___8.ciunit = *lu;
    i__2 = s_rsfe(&io___8);
    if (i__2 != 0) {
	goto L910;
    }
    i__2 = do_fio(&c__1, description, (ftnlen)70);
    if (i__2 != 0) {
	goto L910;
    }
    i__2 = e_rsfe();
    if (i__2 != 0) {
	goto L910;
    }
    io___9.ciunit = *lu;
    i__2 = s_rsle(&io___9);
    if (i__2 != 0) {
	goto L910;
    }
    i__2 = do_lio(&c__3, &c__1, (char *)&n, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L910;
    }
    i__2 = e_rsle();
    if (i__2 != 0) {
	goto L910;
    }
    i__2 = n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	io___11.ciunit = *lu;
	i__3 = s_rsle(&io___11);
	if (i__3 != 0) {
	    goto L910;
	}
	i__3 = do_lio(&c__4, &c__1, (char *)&ccirparm_1.parm[i__ - 1], (
		ftnlen)sizeof(real));
	if (i__3 != 0) {
	    goto L910;
	}
	i__3 = e_rsle();
	if (i__3 != 0) {
	    goto L910;
	}
/* L10: */
    }
    for (i__ = n + 1; i__ <= 20; ++i__) {
/* L110: */
	ccirparm_1.parm[i__ - 1] = 0.f;
    }
    jant = i_nint(&ccirparm_1.parm[1]);
/*  CCIR antenna type */
    ccirparm_1.modegain = 0;
/*  use giso as max gain */
    if (jant >= 1 && jant <= 4 || jant == 8 || jant == 9) {
	ccirparm_1.modegain = 1;
/*  interpolate on operating & design freq */
	io___13.ciunit = *lu;
	i__2 = s_rsle(&io___13);
	if (i__2 != 0) {
	    goto L910;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
	    i__2 = do_lio(&c__4, &c__1, (char *)&ccirparm_1.gainmax[i__ - 1], 
		    (ftnlen)sizeof(real));
	    if (i__2 != 0) {
		goto L910;
	    }
	}
	i__2 = e_rsle();
	if (i__2 != 0) {
	    goto L910;
	}
	io___14.ciunit = *lu;
	i__2 = s_rsle(&io___14);
	if (i__2 != 0) {
	    goto L910;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
	    i__2 = do_lio(&c__4, &c__1, (char *)&ccirparm_1.gainmax[i__ + 2], 
		    (ftnlen)sizeof(real));
	    if (i__2 != 0) {
		goto L910;
	    }
	}
	i__2 = e_rsle();
	if (i__2 != 0) {
	    goto L910;
	}
    } else if (jant >= 5 && jant <= 7) {
	ccirparm_1.modegain = 2;
/*  interpolate on operating freq */
	io___15.ciunit = *lu;
	i__2 = s_rsfe(&io___15);
	if (i__2 != 0) {
	    goto L910;
	}
	for (i__ = 1; i__ <= 30; ++i__) {
	    i__2 = do_fio(&c__1, (char *)&ccirparm_1.gainmaxb[i__ - 1], (
		    ftnlen)sizeof(real));
	    if (i__2 != 0) {
		goto L910;
	    }
	}
	i__2 = e_rsfe();
	if (i__2 != 0) {
	    goto L910;
	}
    } else if (jant == 10) {
/*  vertical monopole */
	ccirparm_1.modegain = 2;
/*  interpolate on operating freq */
	for (ifreq = 2; ifreq <= 30; ++ifreq) {
/* L15: */
	    io___17.ciunit = *lu;
	    i__2 = s_rsfe(&io___17);
	    if (i__2 != 0) {
		goto L910;
	    }
	    i__2 = do_fio(&c__1, (char *)&ccirparm_1.gainmaxb[ifreq - 1], (
		    ftnlen)sizeof(real));
	    if (i__2 != 0) {
		goto L910;
	    }
	    for (ielev = 1; ielev <= 90; ++ielev) {
		i__2 = do_fio(&c__1, (char *)&gain_10__1.gain10[ielev + (
			ifreq - 1) * 90 - 91], (ftnlen)sizeof(real));
		if (i__2 != 0) {
		    goto L910;
		}
	    }
	    i__2 = e_rsfe();
	    if (i__2 != 0) {
		goto L910;
	    }
	}
    } else if (jant == 11) {
/*  type 11 = gain table at 91 elevatio */
	io___19.ciunit = *lu;
	s_rsle(&io___19);
	do_lio(&c__4, &c__91, (char *)&ctype11g_1.gain_type11__[0], (ftnlen)
		sizeof(real));
	e_rsle();
    } else if (jant == 12) {
/*  read gain normalizing for Non-stand */
	ccirparm_1.modegain = 3;
/*  gain normalizing factor */
	io___20.ciunit = *lu;
	i__2 = s_rsfe(&io___20);
	if (i__2 != 0) {
	    goto L920;
	}
	for (i__ = 1; i__ <= 30; ++i__) {
	    i__2 = do_fio(&c__1, (char *)&ccirparm_1.gainmaxb[i__ - 1], (
		    ftnlen)sizeof(real));
	    if (i__2 != 0) {
		goto L920;
	    }
	}
	i__2 = e_rsfe();
	if (i__2 != 0) {
	    goto L920;
	}
    } else if (jant == 13) {
/* cc         open(13,status='scratch',access='direct',form='unformatted', */
/* cc     +                recl=91*4) */
/*          Windows-95 cannot open SCRATCH files */
/*  type 13 = gain table at 360x91 valu */
	o__1.oerr = 0;
	o__1.ounit = 13;
	o__1.ofnmlen = nch_run__ + 11;
/* Writing concatenation */
	i__4[0] = nch_run__, a__2[0] = crun_directory__1.run_directory__;
	i__4[1] = 11, a__2[1] = "/type13.tmp";
	s_cat(ch__2, a__2, i__4, &c__2, (ftnlen)61);
	o__1.ofnm = ch__2;
	o__1.orl = 364;
	o__1.osta = 0;
	o__1.oacc = "direct";
	o__1.ofm = "unformatted";
	o__1.oblnk = 0;
	f_open(&o__1);
	for (iang = 0; iang <= 359; ++iang) {
	    io___22.ciunit = *lu;
	    s_rsfe(&io___22);
	    do_fio(&c__91, (char *)&gains[0], (ftnlen)sizeof(real));
	    e_rsfe();
/* L170: */
	    io___23.cirec = iang + 1;
	    s_wdue(&io___23);
	    do_uio(&c__91, (char *)&gains[0], (ftnlen)sizeof(real));
	    e_wdue();
	}
    } else if (jant == 14) {
/* cc         open(14,status='scratch', */
/* cc     +        access='direct',form='unformatted',recl=92*4) */
/*          Windows-95 cannot open SCRATCH files */
/*  type 14 = gain table at 30x91 value */
	o__1.oerr = 0;
	o__1.ounit = 14;
	o__1.ofnmlen = nch_run__ + 11;
/* Writing concatenation */
	i__4[0] = nch_run__, a__2[0] = crun_directory__1.run_directory__;
	i__4[1] = 11, a__2[1] = "/type14.tmp";
	s_cat(ch__2, a__2, i__4, &c__2, (ftnlen)61);
	o__1.ofnm = ch__2;
	o__1.orl = 368;
	o__1.osta = 0;
	o__1.oacc = "direct";
	o__1.ofm = "unformatted";
	o__1.oblnk = 0;
	f_open(&o__1);
	for (ifreq = 1; ifreq <= 30; ++ifreq) {
	    io___24.ciunit = *lu;
	    s_rsfe(&io___24);
	    do_fio(&c__1, (char *)&eff, (ftnlen)sizeof(real));
	    do_fio(&c__91, (char *)&gains[0], (ftnlen)sizeof(real));
	    e_rsfe();
/* L180: */
	    io___26.cirec = ifreq;
	    s_wdue(&io___26);
	    do_uio(&c__1, (char *)&eff, (ftnlen)sizeof(real));
	    do_uio(&c__91, (char *)&gains[0], (ftnlen)sizeof(real));
	    e_wdue();
	}
    }
L20:
    designfreq_1.freqdesign = 0.f;
/*  default design freq=operating freq */
    cl__1.cerr = 0;
    cl__1.cunit = *lu;
    cl__1.csta = 0;
    f_clos(&cl__1);
/* cc      call antinit2      !  initialize CCIR antenna routines */
    return 0;
L900:
    s_wsfe(&io___27);
    do_fio(&c__1, (char *)&ios, (ftnlen)sizeof(integer));
/* Writing concatenation */
    i__1[0] = nch_run__ - 3, a__1[0] = crun_directory__1.run_directory__;
    i__1[1] = 9, a__1[1] = "antennas/";
    i__1[2] = nch, a__1[2] = alf;
    s_cat(ch__1, a__1, i__1, &c__3, (ftnlen)139);
    do_fio(&c__1, ch__1, nch_run__ + 6 + nch);
    e_wsfe();
    s_wsfe(&io___28);
    do_fio(&c__1, (char *)&nch, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___29);
    do_fio(&c__1, (char *)&nc1, (ftnlen)sizeof(integer));
    do_fio(&c__1, filename, nc1);
    e_wsfe();
    s_paus("error in readant", (ftnlen)16);
    s_stop("error in readant", (ftnlen)16);
L910:
    s_wsfe(&io___30);
    do_fio(&c__1, filename, filename_len);
    e_wsfe();
    s_paus("error in readant", (ftnlen)16);
    s_stop("error in readant", (ftnlen)16);
L920:
    for (i__ = 1; i__ <= 30; ++i__) {
/*  initailize gain normalizing values */
/* L925: */
	ccirparm_1.gainmaxb[i__ - 1] = -99999.f;
    }
    goto L20;
} /* readant_ */

#undef gains


