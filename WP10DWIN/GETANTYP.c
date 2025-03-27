/* GETANTYP.f -- translated by f2c (version 20240504).
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

static integer c__1 = 1;

/* Subroutine */ int getantyp_(integer *iant, char *antyp, ftnlen antyp_len)
{
    /* Initialized data */

    static char antyps[48*49] = "ITS addition   ISOTROPE                    "
	    "     " "ITU-R Rec705   MULTIBAND APER.REF. ARRAY        " "ITU-R"
	    " Rec705   DUAL-BAND CNT.FED TUN.REF. AR.   " "ITU-R Rec705   DUA"
	    "L-BAND END.FED TUN.REF. AR.   " "ITU-R Rec705   DUAL-BAND CNT.FE"
	    "D TROPIC ARR.    " "ITU-R Rec705   HORIZONTAL LOG-PERIODIC ARRAY"
	    "    " "ITU-R Rec705   VERTICAL LOG-PERIODIC ARRAY      " "ITU-R "
	    "Rec705   HORIZONTAL RHOMBIC               " "ITU-R Rec705   QUAD"
	    "RANT ANTENNA                 " "ITU-R Rec705   CROSSED-DIPOLE AN"
	    "TENNA           " "ITU-R Rec705   VERTICAL MONOPOLE             "
	    "   " "ITS addition   GAIN TABLE vs ELEVATION ANGLE    " "ITS add"
	    "ition   CURTAIN ARRAY NTIA Rep 87-215    " "ITS addition   GAIN "
	    "TABLE vs AZIMUTH & ELEVATION" "ITS addition   Point-to-Point GAI"
	    "N TABLE        " "Unknown antenna type                          "
	    "  " "Unknown antenna type                            " "Unknown "
	    "antenna type                            " "Unknown antenna type "
	    "                           " "Unknown antenna type              "
	    "              " "Unknown antenna type                            "
	     "IONCAP ITSA-1  Terminated Horizontal Rhombic    " "IONCAP ITSA"
	    "-1  Vertical Monopole                " "IONCAP ITSA-1  Horizonta"
	    "l Dipole                " "IONCAP ITSA-1  Horizontal Yagi       "
	    "           " "IONCAP ITSA-1  Vertical Log Periodic            " 
	    "IONCAP ITSA-1  Curtain                          " "IONCAP ITSA-"
	    "1  Sloping Vee                      " "IONCAP ITSA-1  Inverted L"
	    "                       " "IONCAP ITSA-1  Sloping Rhombic        "
	    "          " "IONCAP ITSA-1  Interlaced Rhombic               " 
	    "HFMUFES ITS-78 Terminated Horizontal Rhombic    " "HFMUFES ITS-"
	    "78 Vertical Monopole                " "HFMUFES ITS-78 Horizontal"
	    " Half-Wave Dipole      " "HFMUFES ITS-78 Horizontal Yagi        "
	    "          " "HFMUFES ITS-78 Vertical Dipole                  " 
	    "HFMUFES ITS-78 Curtain                          " "HFMUFES ITS-"
	    "78 Terminated Sloping Vee           " "HFMUFES ITS-78 Inverted L"
	    "                       " "HFMUFES ITS-78 Terminated Sloping Rhom"
	    "bic       " "HFMUFES ITS-78 #10 - Not Used                   " 
	    "HFMUFES ITS-78 Sloping Long Wire                " "HFMUFES ITS-"
	    "78 #12 - Not Used                   " "HFMUFES ITS-78 Horiz Xed-"
	    "Dipole Log-Periodic    " "HFMUFES ITS-78 Arbitrary Tilted Dipole"
	    "          " "HFMUFES ITS-78 Side-Loaded Vert Half-Rhombic    " 
	    "HFMUFES ITS-78 Sloping Double Rhomboid          " "HFMUFES ITS-"
	    "78 Vertical Monopole w/Ground Scrn  " "NOSC-95        Inverted C"
	    "one Antenna            ";

    /* Format strings */
    static char fmt_1[] = "(\002External Antenna Type #\002,i2.2)";

    /* System generated locals */
    icilist ici__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

/*  get antenna type generic desc */
/* ============================================================================ */
/* ========================================================================= */
    if (*iant <= 48) {
	s_copy(antyp, antyps + *iant * 48, (ftnlen)48, (ftnlen)48);
    } else if (*iant >= 90 && *iant <= 99) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 48;
	ici__1.iciunit = antyp;
	ici__1.icifmt = fmt_1;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*iant), (ftnlen)sizeof(integer));
	e_wsfi();
    } else {
	s_copy(antyp, "Unknown antenna type", (ftnlen)48, (ftnlen)20);
    }
    return 0;
} /* getantyp_ */

