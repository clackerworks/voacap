      subroutine antcal(bmain,bazim,del,gain)
c******************************************************************
c          bmain- is main beam azmuthal bearing (degrees)
c          bazim- is azimuthal bearing (degrees) to calculate
c          del  - is elevation angle (degrees)
c          gain - is returned
c*****************************************************************
c   calculates gain of antenna for azimuthal offset and elevation angle
c
      common /gain_10/ gain10(90,29)
      common /ccirparm/ parm(20),z6,umax,vmax,giso,
     +                  modegain,gainmax(3,2),gnorm(30)
      common /ctype11g/ gain_type11(91)
      jant=nint(parm(2))         !  ccir antenna type
      gain=giso
      if(jant.eq.10) then        !  vertical monopole
         ielev=nint(del)
         if(ielev.lt.0) ielev=0
         if(ielev.gt.90) ielev=90
         if(ielev.eq.0) then
            gain=-30.
         else
            freq=parm(5)          !  operating freq
            ifreq=freq
            if(ifreq.lt.30) then
               gain=gain10(ielev,ifreq-1)+(freq-float(ifreq))*
     +                     (gain10(ielev,ifreq)-gain10(ielev,ifreq-1))
            else
               gain=gain10(ielev,29)
            end if
         end if
      else if(jant.eq.11) then        !  gain table
         ielev=nint(del)
         if(ielev.lt.0) ielev=0
         if(ielev.gt.90) ielev=90
         gain=gain + gain_type11(ielev+1)
      else if(jant.eq.12) then   !  NTIA Report 87-215 Curtain arrays
         ofaz=bazim-bmain
         if(ofaz.lt.0.) ofaz=ofaz+360.
         freq=parm(5)          !  operating freq
         ifreq=freq
         if(ifreq.lt.30) then
            gn=gnorm(ifreq)+(freq-float(ifreq))*
     +                      (gnorm(ifreq+1)-gnorm(ifreq))
         else
            gn=gnorm(30)
         end if
         call curtain(parm,ofaz,del,gain,gn)
         if(gain.lt.-30.) gain=-30.
      else if(jant.gt.0) then    !  not Isotrope
         ofaz=bazim-bmain
         if(ofaz.lt.0.) ofaz=ofaz+360.
         call ccirgain(jant,del,ofaz,z6,giso,gain)
      end if
      return
      end
c------------------------------------------------------------------
C--------------------------------
      SUBROUTINE Curtain(parm,AZIMD,ELEVD,XMGN,GNORM)
c          AZIMD= Degrees from Boresight
c          ELEVD= Elevation angle Degrees
c***************************************************************
c          parm( 1)= gain above isotrope (not used)
c              ( 2)= antenna type [should be 12]
c              ( 3)= Dielectric
c              ( 4)= Conductivity
c              ( 5)= Operating freq
c              ( 6)= # of bays
c              ( 7)= # elements per bay (# of stacks)
c              ( 8)= Design Frequency
c              ( 9)= Antenna element length (>0=meters  <0=wavelengths)
c              (10)= Height above ground (>0  <0)
c              (11)= Horiz Dist between dipole centers (>0  <0)
c              (12)= Vertical displacement (>0  <0)
c              (13)= Distance from Screen (>0  <0)
c              (14)= Vertical Excitation (mode number)
c              (15)= Horizontal Slew Angle
c***************************************************************
      dimension parm(15)
      COMMON/ANTDAT/nostak,STKSPM,NUMBAY,BAYSPM,DIPLNM,RRSPM,STKHTM,
     +STKRAT(8),bayphs(14),DFMHZ,OFMHZ
C*******************************************************
      CHARACTER ICHR*1,IVMA(15)*4
      INTEGER*4 IPHASE(14,8)
      DATA IPHASE/0,  0,  0,  0, 0,  0,  0,  0,  0, 0,  0,  0,  0,  0,
     2            0,  0, 31, 31, 0, 77, 77,109,109, 0,155,155,186,186,
     3            0, 47, 56,103, 0,139,185,195,242, 0,278,324,334,381,
     4            0, 47, 81,128, 0,200,246,281,327, 0,399,446,480,527,
     5            0, 47,105,152, 0,260,306,365,411, 0,519,566,624,671,
     6            0, 47,129,176, 0,318,365,447,494, 0,636,683,765,812,
     7            0, 90,152,242, 0,375,465,527,617, 0,750,840,903,993,
     8            0, 90,180,270, 0,444,534,624,714, 0,888,978,1068,1158/
      data IVMA/'+000','0+00','00+0','++00','+0+0','0++0','+-00',
     +          '+0-0','0+-0','+++0','++-0','+-+0','+--0','++++','++--'/
c......
      data VofL/299.79246/     !  speed of light
      DATA PI/3.1415926/
      DATA PIO2/1.570796326/
      DATA D2R/.01745329251/

      DFMHZ=parm(8)            !  design frequency
      wave=VofL/DFMHZ          !  wavelength in meters
      nostak=nint(parm(7))
      STKSPM=parm(12)
      if(STKSPM.lt.0.) STKSPM=-STKSPM*wave    !  convert to meters
      NUMBAY=nint(parm(6))
      BAYSPM=parm(11)
      if(BAYSPM.lt.0.) BAYSPM=-BAYSPM*wave    !  convert to meters
      DIPLNM=parm(9)
      if(DIPLNM.lt.0.) diplnm=-diplnm*wave    !  convert to meters
      RRSPM=parm(13)
      if(RRSPM.lt.0.) RRSPM=-RRSPM*wave       !  convert to meters
      STKHTM=parm(10)
      if(STKHTM.lt.0.) STKHTM=-STKHTM*wave    !  convert to meters
      mode=nint(parm(14))      !  vertical excitation mode
      DO 100 I=1,4
      ICHR=IVMA(mode)(I:I)
      K=2*I-1
      IF(ICHR.EQ.'+')THEN
        STKRAT(K)=1.
        STKRAT(K+1)=1.
      ELSE IF(ICHR.EQ.'-')THEN
        STKRAT(K)=-1.
        STKRAT(K+1)=-1.
      ELSE
        STKRAT(K)=0.
        STKRAT(K+1)=0.
      ENDIF
  100 CONTINUE
      IF(nostak.LT.8)THEN
        DO 101 I=nostak+1,8
  101   STKRAT(I)=0.
      ENDIF
      ISLEW=nint(parm(15))      !  Horizontal Slew angle
      KSLEW = (ABS(ISLEW)/4)+1
      DO 200 I=1,14
      IF(ISLEW.LT.0)THEN
        bayphs(I) = IPHASE(I,KSLEW)
      ELSE
        bayphs(I) = -IPHASE(I,KSLEW)
      ENDIF
  200 CONTINUE
      OFMHZ=parm(5)        !  operating freq
      IAZ=0
      AZIM=AZIMD*D2R
      IF(ABS(AZIM).GT.PIO2 .and. ABS(AZIM).lt.3.*PIO2) THEN
        AZIM=AZIM-SIGN(PI,AZIM)
        IAZ=1
      ENDIF

      CALL PATTRN0(AZIM,ELEVD*D2R,XMGN,GNORM)
      IF(IAZ.EQ.1) XMGN=XMGN-20.     !  backward radiation
      RETURN
      END
C------------------------
      SUBROUTINE PATTRN0(AZIM,ELEV,XGN,FACTOR)
C--------------------------------------------------------------------
C                        SUBPROGRAM USAGE
C
C  SGAIN - computes power gain dBi
C*********************************************************************
C  COMMON BLOCKS:
C ANTDAT
C       nostak - NUMBER OF VERTICAL STACKS
C       STKSPM - SPACING BETWEEN STACKS
C       NUMBAY - NUMBER OF BAYS
C       BAYSPM - SPACING BETWEEN BAYS
C       DIPLNM - LENGTH OF DIPOLE RADIATOR
C       RRSPM - SPACING BETWEEN RADIATORS AND REFLECTING SCREEN
C       STKHTM - HEIGHT OF LOWEST STACK ABOVE GROUND
C       STKRAT - CURRENT RATIO FOR STACKS
C       BAYPHS - RELATIVE PHASE FOR THE BAYS
C       BAYRAT - CURRENT RATIO FOR THE BAYS (ALWAYS = 1)
C       OFMHZ - ANTENNA OPERATING FREQUENCY
C       DFMHZ - ANTENNA DESIGN FREQUENCY
C
C CONST
C       PI      -  MATHEMATICAL SYMBOL PI = 3.14159
C       VOFL    -  VELOCITY OF LIGHT  FOR FREQUENCY IN MEGAHERTZ = 3.0E-
C       PI2     -  2 * PI
C       PIO2    -  PI / 2
C       D2R     -  CONVERSION FACTOR FOR DEGREES TO RADIANS CONVERSION
C                   = PI / 180.
C       R2D     -  CONVERSION FACTOR FOR RADIANS TO DEGREES CONVERSION
C                   = 180 / PI
C FWAVE
C       EIL     -  0.5 * LENGTH OF DIPOLE IN radianS
C       XB      -  SPACING BETWEEN BAYS IN radiansS
C       XS      -  SPACING BETWEEN STACKS IN radianS
C       XH      -  HEIGHT OF LOWEST STACK ABOVE GROUND IN radianS
C       XR      -  REFLECTOR TO DIPOLE SPACING IN radianS
C       C(8)    -  ARRAY OF RELATIVE STACK CURRENT MAGNITUDE RATIOS
C       R(14)   -  ARRAY OF RELATIVE BAY CURRENT MAGNITUDE RATIOS
C       PS(14)  -  ARRAY OF BAY CURRENT PHASE RATIOS IN RADIANS INCLUDIN
C                     FREQUENCY ADJUSTMENT FOR OPERATING FREQUENCY NOT
C                     EQUAL TO DESIGN FREQUENCY
C       A(8)    -  ARRAY OF STACK CURRENT PHASE RATIOS IN RADIANS,
C                    CURRENTLY DEFAULTED TO ZERO
C       Y(14)   -  ARRAY CONTAINING THE SPACINGS BETWEEN THE BAY DIPOLES
C                     IN radianS (RELATIVE TO BAY 1)
C       Z(8)    -  ARRAY CONTAINING THE SPACINGS BETWEEN THE STACK DIPOL
C                     IN radianS (RELATIVE TO STACK 1)
C       WAVE    -  OPERATING FREQUENCY WAVELENGTH
C       BETA    -  OPERATING FREQUENCY WAVE NUMBER (K=2*PI/WAVE)
C
C
C  DUMMY ARGUMENTS:
C       AZIM  - an azimuth counter-clockwise from Boresight RADIANS 
C       ELEV  - an elevation angle above the horizon  RADIANS
C       XGN  - antenna gain (dB) for AZIM, ELEV
C       FACTOR  - integral result for antenna gain normalization
C
C*********************************************************************
      COMMON/ANTDAT/nostak,STKSPM,NUMBAY,BAYSPM,DIPLNM,RRSPM,STKHTM,
     +STKRAT(8),bayphs(14),DFMHZ,OFMHZ
      COMMON/FWAVE/EIL,CEIL,XB,XS,XH,XR,C,R,PS,A,Y,Z,WAVE,BETA
      DIMENSION C(8),R(14),PS(14),A(8),Y(14),Z(8)
      DATA PI/3.1415926/,VOFL/299.79246/
      DATA PI2/6.283185307/
      DATA D2R/.01745329251/
      write(*,1) azim,elev,factor
1     format('in pattrn0, azim,elev,factor=',3f15.5)
C  SET DEFAULT VALUES FOR GAIN
        WAVE = VOFL /OFMHZ
        BETA = PI2 / WAVE
        XH = STKHTM * BETA
        XB = BETA * BAYSPM
        EL = DIPLNM * BETA
        EIL = EL / 2.0
        CEIL = COS(EIL)
        XR = RRSPM * BETA
        XS = STKSPM * BETA
      write(*,'('' nostak='',i5)') nostak
C
C  CONSTANTS FUNCTIONS OF FREQUENCY ONLY
       DO 30 Is = 1,nostak
         Z(Is) = XS * FLOAT(Is-1) + XH
         C(Is) = STKRAT(Is)
   30  CONTINUE
       ODRAT = D2R * OFMHZ / DFMHZ
       NBS=IABS(NUMBAY)
       DO 40 Ib = 1,NBS
          PS(Ib) = ODRAT * bayphs(Ib)
          R(Ib) = 1.
          Y(Ib) = FLOAT(Ib-1) * XB
   40 CONTINUE
        Y(1)=0.
        IF(FACTOR.EQ.-99999.)THEN
          CALL DBLTRAP(DINTGL)
          FACTOR = 4.0 * PI / DINTGL
        ENDIF
        XGN=-1000.
        XGAIN = F2 (ELEV,AZIM)
      write(*,'('' xgain='',e15.7)') xgain
        IF(XGAIN.NE.0.) XGN = 10.* ALOG10(ABS(XGAIN*FACTOR))
      write(*,'('' xgn='',e15.7)') xgn
        RETURN
      END
C------------------------------------------------------------------
