c###nommuf.for
      SUBROUTINE NOMMUF
C--------------------------------
C
C     THIS ROUTINE CALCULATES MUF FOR ALL LAYERS AND CIRCUIT MUF (NO ES)
C     BY THE MANUAL METHOD PROGRAMMED FOR COMPUTER USE
C
      COMMON/MUFS/EMUF(24),F1MUF(24),F2MUF(24),ESMUF(24),ALLMUF(24)
     1,FOT(24),XLUF(24),HPF(24),ANGMUF(24),MODMUF,SIGL(4),SIGU(4),DELMU
     2F(4),HPMUF(4),HTMUF(4),FVMUF(4),AFMUF(4),NHOPMF(4),YFOT(4),YHPF(4)
     3 ,YMUF(4)
      COMMON/ES/FS(3,5),HS(5)
      COMMON /RON /CLAT(5), CLONG(5), GLAT(5), RD(5), FI(3,5), YI(3,5),
     1HI(3,5), HPRIM(30,5), HTRUE(30,5), FVERT(30,5),KM,KFX, AFAC(30,5),
     2HTR(50,3), FNSQ(50,3)
      COMMON / TIME / IT, GMT, UTIME(24), GMTR, XLMT(24), ITIM, JTX
      COMMON /DON /ALATD, AMIN, AMIND, BTR, BTRD, DLONG, DMP, ERTR, GCD,
     1 GCDKM, PMP, PWR, TLAT, TLATD, TLONG, TLONGD, RSN, SIGTR, RLAT,
     2 RLATD,RLONG,RLONGD,BRTD,FLUX,ULAT,ULATD,ULONG,ULONGD,SSN,D90R,
     3 D50R,D10R,D90S,D50S,D10S
      COMMON / MFAC / F2M3(5),HPF2(5),ZENANG(5),ZENMAX(5),IEDP,FSECV(3)
      COMMON / CON / D2R, DCL, GAMA, PI, PI2, PIO2, R2D, RZ, VOFL
      DIMENSION AE(7),AF(7)
      DATA AE /-1.133200756E-2, 3.761385053E-2, -5.038476266E-3,
     1 2.624808315E-4, -5.976618436E-6, 1.334494261E-7, -4.368460907E-9/
      DATA AF / 4.699243101E-3, 2.264634341E-3, 9.202437332E-5,
     1 6.865259817E-5, -9.985831104E-6, 4.49151441E-7, -6.712654756E-9/
      ARC= GCDKM* 0.0062137
C
C THIS IS THE MANUAL METHOD PROGRAMMED FOR COMPUTER USE. SEE NBS REPORT
C 7619. MAXIMUM USABLE FREQUENCY FACTORS USING A COMPLETE ELECTRON
C DENSITY PROFILES ARE IN SUBROUTINE CURMUF
C
C
C  E-F1 LAYER DISTANCE FACTOR
C
      IF(ARC.lt.16.) then
         ELFC=((((((AE(7)*ARC+AE(6))*ARC+AE(5))*ARC+AE(4))*ARC
     A         + AE(3) )*ARC + AE(2))* ARC + AE(1) ) *ARC +  0.2085
      else
         ELFC = 1.02
      end if
C
C  F2  LAYER DISTANCE FACTOR
C
      IF(24..le.ARC) then
         FLFC = 1.0
      else
         FLFC=((((((AF(7)*ARC +AF(6))*ARC +AF(5) )*ARC + AF(4) )*ARC +
     A        AF(3) )*ARC + AF(2) )* ARC + AF(1) )*ARC
      end if
      EC = 1000.
      DO 135 K=1,KM
C E LAYER MUF
      IF(EC.gt.FI(1,K)) EC=FI(1,K)
  135 CONTINUE
      EMUF(IT) = 4.871 * EC * ELFC
      F2MUF(IT)= 1000.
C F LAYER MUF
      DO 145 K=1,KM
      FOUR= F2M3(K)*FI(3,K) * 1.1
      FMUF= FI(3,K) + FLFC*(FOUR - FI(3,K))
      IF(FMUF.lt.F2MUF(IT) ) F2MUF(IT)=FMUF
  145 CONTINUE
C  NO SEPERATE F1
      F1MUF(IT)= -1.
C  CIRCUIT MUF
      IF(EMUF(IT).ge.F2MUF(IT)) then
         ALLMUF(IT) =EMUF(IT)
      else
         ALLMUF(IT) =F2MUF(IT)
      end if
      FOTFY= 0.85* F2MUF(IT)
      FOT(IT) =AMAX1 (FOTFY,EMUF(IT))
      HPFFY = 1.15 * F2MUF(IT)
      HPF(IT) = AMAX1(HPFFY, EMUF(IT))
      ESMUF(IT)= 1000.
C
C SPORADIC E  MUF, PROBABILITY  OF REFLECTION IS 0.5
C
      DO 170 K=1,KM
      IF(FS(2,K).le.0.) go to 170
      DMAX= 225.*SQRT(HS(K) )
      HOP = GCDKM/DMAX +1.
      PSI = 0.5* GCD/HOP
      TDEL = (COS(PSI) - RZ / (RZ + HS(K))) / SIN(PSI)
      CDEL = 1. / SQRT(1. + TDEL * TDEL)
      SPHE = RZ * CDEL / (RZ + HS(K))
      SECP = 1. / SQRT(1. - SPHE * SPHE)
      ESD = FS(2,K) * SECP
      IF(ESMUF(IT).gt.ESD) ESMUF(IT)=ESD
  170 CONTINUE
      RETURN
      END
C--------------------------------
