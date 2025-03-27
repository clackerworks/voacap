/* ANTMODEL.f -- translated by f2c (version 20240504).
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

/* Subroutine */ int antmodel_(integer *iant, real *gain, char *ant_model__, 
	ftnlen ant_model_len)
{
    /* Format strings */
    static char fmt_99[] = "(\002+\002,f5.1,\002 dBi\002)";

    /* System generated locals */
    icilist ici__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/* --------------------------------------------------------------------- * */
    if (*iant == 0) {
/*  add gain above ISOTROPE */
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 10;
	ici__1.iciunit = ant_model__;
	ici__1.icifmt = fmt_99;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*gain), (ftnlen)sizeof(real));
	e_wsfi();
    } else if (*iant >= 1 && *iant <= 10) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 10;
	ici__1.iciunit = ant_model__;
	ici__1.icifmt = "(8hREC705 #,i2.2)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*iant), (ftnlen)sizeof(integer));
	e_wsfi();
    } else if (*iant == 11) {
	s_copy(ant_model__, "2-D Table ", (ftnlen)10, (ftnlen)10);
    } else if (*iant == 12) {
	s_copy(ant_model__, "NTIA87-215", (ftnlen)10, (ftnlen)10);
    } else if (*iant == 13) {
	s_copy(ant_model__, "3-D Table ", (ftnlen)10, (ftnlen)10);
    } else if (*iant == 14) {
	s_copy(ant_model__, "2-D P-to-P", (ftnlen)10, (ftnlen)10);
    } else if (*iant >= 21 && *iant <= 30) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 10;
	ici__1.iciunit = ant_model__;
	ici__1.icifmt = "(8hIONCAP #,i2.2)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*iant), (ftnlen)sizeof(integer));
	e_wsfi();
    } else if (*iant >= 31 && *iant <= 47) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 10;
	ici__1.iciunit = ant_model__;
	ici__1.icifmt = "(8hHFMUFES#,i2.2)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*iant), (ftnlen)sizeof(integer));
	e_wsfi();
    } else if (*iant >= 48 && *iant <= 48) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 10;
	ici__1.iciunit = ant_model__;
	ici__1.icifmt = "(8hNOSC-95#,i2.2)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*iant), (ftnlen)sizeof(integer));
	e_wsfi();
    } else if (*iant >= 90 && *iant <= 99) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 10;
	ici__1.iciunit = ant_model__;
	ici__1.icifmt = "(8hExtern #,i2.2)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*iant), (ftnlen)sizeof(integer));
	e_wsfi();
    } else {
	s_copy(ant_model__, "Unknown???", (ftnlen)10, (ftnlen)10);
    }
    return 0;
} /* antmodel_ */

