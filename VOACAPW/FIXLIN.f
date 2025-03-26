c###fixlin.for
      SUBROUTINE FIXLIN(jfmt,IVAR,LIN)
C--------------------------------
C.....THIS SUBROUTINE WRITES A VECTOR FORMATTED LINE
C     FOR A FIXED POINT (INTEGER) VARIABLE
      COMMON / CONTRL / IELECT(3), KTOUT(12), MONTHS(12), SUNSP(12),
     A IANTOU, ICARD, INTEG, IRED, ISOUT, ISPROC, ISSN, ITYPE, JDASH,
     B JFREQ, JLONG, KCARD, KRUN, MAPIN, MAXNAM, MONOLD, MOREM, MORES,
     C NUMNAM, NUPROC, MAXMET, MSPEC, M100
      COMMON / FILES / LUI, LUO, LU2, LU5, LU6, LU15, LU16, LU20, LU25,
     A LU26, LU35
      COMMON / OUTFMT / KLINE(26)
      DIMENSION IVAR(13)
      character jfmt*(*)
      CHARACTER NDASH*4
      CHARACTER KLINE*6
      DATA IMUF/12/, NDASH/'  - '/
      IF(LIN.le.0 .or.LIN.gt.30) return
      jfmt(8:15)='i5      '
      WRITE(LUO,jfmt) IVAR(IMUF), (IVAR(I),I=1,JFREQ),
     A (NDASH,J=1,JDASH), KLINE(LIN)
      RETURN
      END
C--------------------------------
