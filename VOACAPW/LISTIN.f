c# listin.f
      SUBROUTINE LISTIN
      common /clisting/ listing,formfeed
      character listing*1,formfeed*1
C--------------------------------
C.....THIS ROUTINE CREATES THE PROCEDURE FILE AND THEN
C.....CHECKS THE NAME IDENTIFIERS ON THE INPUT FILE
      COMMON / CONTRL / IELECT(3), KTOUT(12), MONTHS(12), SUNSP(12),
     A IANTOU, ICARD, INTEG, IRED, ISOUT, ISPROC, ISSN, ITYPE, JDASH,
     B JFREQ, JLONG, KCARD, KRUN, MAPIN, MAXNAM, MONOLD, MOREM, MORES,
     C NUMNAM, NUPROC, MAXMET, MSPEC, M100
      COMMON / METSET / ITRUN, ITOUT, JTRUN(40), JTOUT(40)
      common /CVERSN/ VERSN
         character VERSN*8
      COMMON / FILES / LUI, LUO, LU2, LU5, LU6, LU15, LU16, LU20, LU25,
     A LU26, LU35
      COMMON / NAMEX / NAMES(100), INPUTX
      CHARACTER NAMES*10, INPUT*85, INPUTX*85,list*1
      EQUIVALENCE(INPUTX,INPUT)
      CHARACTER ITEMP*10, IOFF*10
      DATA NCARD/0/, IOFF/'OFF       '/
      list=listing
      if(list.eq.' ') list='Y'     !  blank    , do listing
      if(list.eq.'B') list='Y'     !  for Batch, do listing
      if(list.eq.'Y') WRITE(LUO,1500) formfeed,VERSN
      if(list.eq.'Y') WRITE(LUO,1502) (I,I=1,7)
      ITRUN = 1
C.....CREATE THE PROCEDURE FILE FROM THE STANDARD AND AUXILLARY INPUT
      LU = LUI
100   ICARD = MONITR(LU,MAXNAM)
C.....QUIT CARD ENCOUNTERED ON INPUT - BRANCH TO EXAMINE NAME IDENTIFIER
      IF(ICARD.eq.26) go to 300
C.....AUXIN CARD ENCOUNTERED ON INPUT FILE - INTERCHANGE LOGICAL UNITS
      IF(ICARD.ne.17) go to 140
      IF(LU - LUI) 120, 130, 120
  120 LU = LUI
      GO TO 100
  130 LU = LU15
      GO TO 100
C.....PROCEDURE CARD ENCOUNTERED ON INPUT FILE
  140 IF(ICARD - 23) 100, 150, 100
  150 ITEMP=INPUT(11:20)
      IFLAG = 0
      NUPROC = NUPROC + 1
      INDEX = NUMNAM + NUPROC
C.....THERE IS NO ROOM IN THE NAME LIST FOR THE PROCEDURE NAME
C.....ONLY 9 USER DEFINED INPUT PROCEDURES ARE ALLOWED
      IF(INDEX - MAXNAM) 170, 170, 160
  160 WRITE(LUO,1506)
      ITRUN = 0
      GO TO 300
C.....IGNORE THE PROCEDURE DEFINITION IF THE PROCEDURE NAME IS THE SAME
C.....AS A RESERVED INPUT CARD NAME. USE THE FIRST DEFINITION OF THE
C.....PROCEDURE IF A PROCEDURE WITH THE SAME NAME IS ALREADY DEFINED.
  170 DO 190 I = 1,INDEX
      IF(NAMES(I) .NE. ITEMP) GO TO 190
      IFLAG = 1
      WRITE(LUO,1508) ITEMP
  190 CONTINUE
      IF(IFLAG) 250, 250, 200
C.....IGNORE THE PROCEDURE DEFINITION
  200 NUPROC = NUPROC - 1
  210 JCARD = MONITR(LU,MAXNAM)
      IF(JCARD - 24) 210, 100, 210
C.....STORE THE PROCEDURE NAME IN THE NAME LIST AND WRITE THE PROCEDURE
  250 NAMES(INDEX) = ITEMP
      nch=lcount(inputx,85)
      if(nch.lt.11) nch=11
      WRITE(LU35,'(a)') ITEMP//INPUTX(11:nch)
  260 JCARD = MONITR(LU,MAXNAM)
      nch=lcount(inputx,85)
      WRITE(LU35,'(a)') INPUTX(1:nch)
      IF(JCARD - 24) 260, 100, 260
C.....CHECK THE NAME IDENTIFIER OF THE INPUT CARD IMAGES
  300 CONTINUE
      LU = LUI
      REWIND LU5
      REWIND LU15
      REWIND LU35
  305 ICARD = MONITR(LU,MAXNAM)
C.....CHECK FOR "EDP" CONTROL CARD AND SKIP ELECTRON DENSITY PROFILES
      IF(ICARD.ne.16) go to 311
      IF(LU.eq.LU15) go to 309
      nch=lcount(input,85)
      WRITE(LUO,'(1x,a)') INPUT(1:nch)
ccc      READ(INPUT,1522) ITEMP
      ITEMP=INPUT(16:)
      IF(ITEMP .EQ. IOFF) GO TO 305
      DO 308 I = 1,8
      READ(LU,'(a)') INPUT
      nch=lcount(input,85)
      WRITE(LUO,'(1x,a)') INPUT(1:nch)
  308 CONTINUE
      GO TO 305
  309 WRITE(LUO,1518) INPUT(1:80)
      READ(LUO,1522) ITEMP
      IF(ITEMP .EQ. IOFF) GO TO 305
      DO 310 I = 1,8
      READ(LU,'(a)') INPUT
      WRITE(LUO,1518) INPUT(1:80)
  310 CONTINUE
      GO TO 305
  311 IF(ICARD.le.MAXNAM) go to 315
C.....E R R O R - NAME IDENTIFIER ISN'T IN THE NAME LIST
      WRITE(LUO,1512) INPUT
      NCARD = NCARD + 1
      GO TO 305
  315 IF(LU.eq.LU15) then
         WRITE(LUO,1518) INPUT(1:80)
      else
         nch=lcount(input,85)
c          do not put this comment in the output file here
         if(input(1:15).ne.'COMMENT   GROUP') then
            if(list.eq.'Y') WRITE(LUO,'(1x,a)') INPUT(1:nch)
         end if
      end if
C.....QUIT CARD ENCOUNTERED ON INPUT FILE - BRANCH TO SUMMARY
      IF(ICARD.eq.26) go to 400
C.....AUXIN CARD ENCOUNTERED ON INPUT FILE - INTERCHANGE LOGICAL UNITS
      IF(ICARD.ne.17) go to 305
      IF(LU.eq.LUI) go to 370
      LU = LUI
      GO TO 305
  370 LU = LU15
      GO TO 305
C.....SUMMARY OF NAME IDENTIFIER ERRORS
  400 REWIND LUI
      REWIND LU15
      IF(NCARD.gt.0) then
         WRITE(LUO,1516) NCARD
         ITRUN = 0
      end if
      RETURN
C.....FORMAT SPECIFICATIONS
 1500 FORMAT(a1,' IONOSPHERIC COMMUNICATIONS ANALYSIS AND PREDICTI',
     A 'ON PROGRAM',/,20x,' VOACAP   VERSION ',a8,//)
 1502 FORMAT(' ',7(9X,I1),/,' ',7('1234567890'),'12345',/)
 1506 FORMAT(' THERE IS NO ROOM IN THE CARD NAME LIST FOR THE ',
     A 'PROCEDURE NAME',/,'THE USER MAY DEFINE NO MORE THAN  9 ',
     B 'PROCEDURES',//)
 1508 FORMAT(' ATTEMPT TO DEFINE A PROCEDURE CALLED - ',A10,/,
     A ' WHICH IS (1) A RESERVED INPUT CARD NAME (IGNORE DEFINITION)',
     B /,7X,'OR (2) ALREADY STORED IN THE PROCEDURE FILE (FIRST',
     C ' DEFINITION TAKES PRECEDENCE)',///)
 1512 FORMAT(' ',A80,'****NAME IDENTIFIER ERROR****')
 1516 FORMAT(///,' ',I5,' NAME IDENTIFIER ERRORS',//,' CAUSED BY ',
     A '(1) A SPELLING ERROR IN THE IDENTIFIER NAME',/,8X,
     B 'OR (2) A REFERENCE TO AN UNDEFINED PROCEDURE')
 1518 FORMAT(' ',A80,'AUXIN')
 1522 FORMAT(15X,A3)
      END
C--------------------------------
