c###f2var.for
      SUBROUTINE F2VAR
C--------------------------------
C
C     THIS ROUTINE EVALUATES THE F2 LAYER PARAMETERS
C
      COMMON / PSCA / PSC(4), PSCB(4), IPSC
      COMMON /A11 /GAMMA (6)
      COMMON / MFAC / F2M3(5),HPF2(5),ZENANG(5),ZENMAX(5),IEDP,FSECV(3)
      COMMON /RON /CLAT(5), CLONG(5), GLAT(5), RD(5), FI(3,5), YI(3,5),
     1HI(3,5), HPRIM(30,5), HTRUE(30,5), FVERT(30,5),KM,KFX, AFAC(30,5),
     2HTR(50,3), FNSQ(50,3)
      COMMON /GEOG /GYZ (5), RAT (5), GMDIP (5), CLCK (5), ABIY (5), ART
     1IC (5), SIGPAT (5), EPSPAT (5)
      DATA XF1/1.1/,DELZ/2./
      DO 125 II = 1, KM
C.....EVALUATE M(3000) AND CRITICAL FREQUENCY
      CALL VERSY(4, 5, II)
C.....F2M3(II) IS THE F2 LAYER M(3000) FACTOR
C.....HPF2(II) IS THE VIRTUAL HEIGHT AT 0.834 CRITICAL FREQUENCY
      F2M3 (II) = GAMMA (5)
      HPF2(II) = 1490. / GAMMA(5) - 176.
      FI (3, II) = (GAMMA (4) + 0.5 * GYZ (II)) * PSC (3)
      ZMAX = ZENMAX(II)
      Z = ZENANG(II)
C.....F1 MUST BE LESS THAN F2
      FI(2,II) = AMIN1(FI(2,II),FI(3,II)-.2)
      FC=0.834*FI(3,II)
      EC = FI (1, II)
      FCEC = FC / EC
       FCEC = AMAX1(FCEC,1.1)
C.....E LAYER RETARDATION
      RET = FCEC * ALOG ((FCEC + 1.) / (FCEC - 1.))
      RET=(RET-2.)*YI(1,II)
      FC1 = FI (2, II)
      IF (FC1)120, 120, 110
  110 FFEC = FC / FC1
C  FORCE MERGER OF F1 LAYER INTO F2 LAYER.
C.....CHECK IF F1 IS AT TWILIGHT
      IF(ZMAX-DELZ - Z) 215,210,210
C  NO PROBLEM.
  210 FFEC = AMAX1(FFEC,XF1)
      RFT  = FFEC*ALOG((FFEC+1.)/(FFEC-1.))
      RFT  = .5* YI(2, II)*(RFT-2.)
      GO TO 115
C NEAR DAY-NIGHT,CORRECT HI(2,II) AND RETARDATION.
C.....FORCE F1 UP INTO F2 AND RETARDATION TO ZERO FROM ZN TO ZMAX
  215 FFEC = AMAX1(FFEC,XF1)
      ZN = ZMAX - DELZ
      HN = 165. + .6428*ZN
      YN = HN *(YI(2,II)/HI(2,II))
      RFN= FFEC*ALOG((FFEC +1.)/(FFEC -1.))
      RFN= .5*YN*(RFN -2.)
      SZ = (Z-ZN)/DELZ
      RFT= RFN*(1.-SZ)
C  F2 WITHOUT F1.
      HM = HPF2(II) - RET
      YM = HM/RAT(II)
      DHN = (HM-YM) - (HN-YN)
      IF( DHN) 115,115,220
C.....BOTTOM OF F1 GOES TO BOTTOM OF F2
  220 DH = DHN*(1. - SZ)
      HI(2,II) = (HM-YM) - DH +YI(2,II)
      IF(FC1 - FC) 115, 115, 225
C  F1 IS ALSO CLOSE TO F2 IN FREQUENCY, FORCE F1 YM TO F2 YM.
  225 Y1MAX = YN + (YM - YN) * (FC1 / FI(3,II) - 0.834) / 0.166
      YI(2,II) = YN + (Y1MAX - YN) * SZ
      HI(2,II) = (HM - YM) - DH + YI(2,II)
  115 RET = RET + RFT
  120 HI(3,II) = HPF2(II) - RET
      YI(3,II) = HI(3,II) / RAT(II)
  125 CONTINUE
      RETURN
      END
C--------------------------------
