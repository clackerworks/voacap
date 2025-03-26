c###gethp.for
      SUBROUTINE GETHP(FXX,HPX,HTX)
C--------------------------------
C
C     THIS ROUTINE PERFORMS GAUSSIAN INTEGRATION FOR THE VIRTUAL HEIGHTS
C     (SEE SUBROUTINE IONMUF FOR SETTING OF DATA)
C
      COMMON / DATR / WT(20), XT(20), NT, NPL, XNPL, TWDIV
      COMMON /RON /CLAT(5), CLONG(5), GLAT(5), RD(5), FI(3,5), YI(3,5),
     1HI(3,5), HPRIM(30,5), HTRUE(30,5), FVERT(30,5),KM,KFX, AFAC(30,5),
     2HTR(50,3), FNSQ(50,3)
      FR = FXX * FXX
C.....FIRST FIND THE TRUE HEIGHT BY INTERPOLATION
      IF (FR - FNSQ (1,1))435, 435, 445
  435 HTX = HTR(1,1)
      HPX = HTX
      RETURN
  445 CONTINUE
      DO 490 IH = 1, 49
      IF (FNSQ (IH,1) - FNSQ (IH + 1,1))465, 455, 480
  455 IF (FR - FNSQ (IH,1))490, 460, 490
  460 HT = HTR (IH,1)
      GO TO 495
  465 IF (FNSQ (IH,1) - FR)470, 470, 475
  470 IF (FR - FNSQ (IH + 1,1))475, 490, 490
  475 HT = HTR (IH,1) + (FR - FNSQ (IH,1)) * (HTR(IH + 1,1) - HTR(IH,1))
     1 / (FNSQ (IH + 1,1) - FNSQ (IH,1))
      GO TO 495
  480 IF (FNSQ (IH,1) - FR)490, 485, 485
  485 IF (FR - FNSQ (IH + 1,1))490, 490, 475
  490 CONTINUE
      HT = HTR (50,1)
  495 CONTINUE
C.....END OF TRUE HEIGHT CALCULATION
      HP = 0
      HT = HT - HTR (1,1)
      HRMZ = HT * TWDIV * XNPL
      IF (NT .LT. 1) GO TO 665
C.....BEGINNING OF GAUSSIAN INTEGRATION
      DO 635 IG = 1, NT
      ZG = 1.0 - XT(IG)
C.....TRANSLATION TO (-1,1) FROM (0,HT) NEED NOT BE LINEAR
      ZI = HT * (1. - TWDIV * (ZG * * NPL)) + HTR (1,1)
      IB = - 1
      GO TO 535
  500 YSQ = YSQ / FR
      YSQ = AMIN1 (YSQ, 0.9999)
      YMUP = 1. / SQRT (1. - YSQ)
      YMUP = YMUP * (ZG * * (NPL - 1))
      ZG = 1. + XT (IG)
      ZI = HT * (1. - TWDIV * (ZG * * NPL)) + HTR (1,1)
      IB = 1
      GO TO 535
  505 YSQ = YSQ / FR
      YSQ = AMIN1 (YSQ, 0.9999)
      ZMUP = 1. / SQRT (1. - YSQ)
      ZMUP = ZMUP * (ZG * * (NPL - 1))
      GO TO 635
C.....BEGIN INTERPOLATION FOR PLASMA FREQUENCY SQUARED
  535 CONTINUE
      IF (ZI - HTR (1,1))545, 545, 555
  545 YSQ = FNSQ (1,1)
      GO TO 625
  555 CONTINUE
      DO 615 IH = 1, 49
      IF (HTR (IH,1) - HTR (IH + 1,1))585, 565, 605
  565 IF (ZI - HTR (IH,1))615, 575, 615
  575 YSQ = FNSQ (IH,1)
      GO TO 625
  585 IF (HTR (IH,1) - ZI)595, 595, 600
  595 IF (ZI - HTR (IH + 1,1))600, 615, 615
  600 YSQ = FNSQ (IH,1) + (ZI - HTR (IH,1)) * (FNSQ(IH+1,1)-FNSQ(IH,1))
     1 /(HTR (IH + 1,1) - HTR (IH,1))
      GO TO 625
  605 IF (HTR (IH,1) - ZI)615, 610, 610
  610 IF (ZI - HTR (IH + 1,1))615, 615, 600
  615 CONTINUE
      YSQ = FNSQ (50,1)
C.....END OF INTERPOLATION FOR PLASMA FREQUENCY SQUARED
  625 IF (IB)500, 500, 505
  635 HP = HP + WT (IG) * (YMUP + ZMUP)
C.....END OF GAUSSIAN INTEGRATION FOR VIRTUAL HEIGHTS
  665 CONTINUE
C.....HPX IS THE VIRTUAL HEIGHT
C.....HTX IS THE TRUE HEIGHT
      HPX = HTR(1,1) + HRMZ * HP
      HTX = HTR(1,1) + HT
      RETURN
      END
C--------------------------------
