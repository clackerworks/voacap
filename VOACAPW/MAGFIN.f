c###magfin.for
      SUBROUTINE MAGFIN (POS, UNE)
C--------------------------------
C
C     THIS ROUTINE EVALUATES THE MAGNETIC FIELD VECTORS
C
C     POS IS THE GEOGRAPHIC POSITION VECTOR OF WHERE THE MAGNETIC
C     FIELD IS TO BE EVALUATED WHERE
C     POS(1) IS THE GEOGRAPHIC LATITUDE (RADIANS) "+" IS NORTH
C     POS(2) IS THE GEOGRAPHIC LONGITUDE (RADIANS) 0 TO 2PI EAST
C     POS(3) IS HEIGHT (IN METERS)
C
C     UNE IS THE MAGNETIC FIELD VECTOR WHERE
C     UNE(1) IS THE VERTICAL (UP) COMPONENT
C     UNE(2) IS THE NORTH COMPONENT
C     UNE(3) IS THE EAST COMPONENT
C     NOTE THAT THIS IS A LEFT-HANDED COORDINATE SYSTEM
C
C     FOR FURTHER INFORMATION SEE
C     NASA REPORT NO. TMX-55105 (OCT. 1964) BY J. C. CAIN, S. HENDRICKS,
C        W. E. DANIELS, D. C. JENSEN FOR THEORETICAL DETAILS.
C     JOURNAL OF GEOPHYSICAL RESEARCH, VOL. 67, NO. 9, PP. 3568-3569,
C        AUGUST, 1962, FOR THE JENSEN AND CAIN GAUSSIAN NORMALIZED
C        MAGNETIC FIELD COEFFICIENTS FOR EPOCH 1960.
C
      DIMENSION P (7, 7), DP (7, 7), CP (7), AOR (7), SP (7), POS (3), U
     1NE (3), CT (7, 7), G (7, 7), H (7, 7)
      DATA P/1.0,48*0.0/, DP/49*0.0/, SP(1)/0.0/, CP(1)/1.0/,
     1 CT/ 0.0,0.0,.33333333,.26666667,.25714286,.25396825,.25252525,
     2 3*0.0,.2,.22857142,.23809523,.24242424,4*0.0,.14285714,
     3 .19047619,.21212121,5*0.0,.11111111,.16161616,6*0.0,
     4   .09090909, 14*0.0/, G/0.0, .304112, .024035, -.031518,  -.04179
     54, .016256, - .019523, 0., .021474, - .051253, .062130, - .045298,
     6 -.034407,-.004853,2*0.0,-.013381,-.024898,-.021795,
     7 -.019447,.003212,3*0.0,-.006496,.007008,-.000608,.021413,
     8 4*0.0,-.002044,.002775,.001051,5*0.0,.000697,.000227,6*0.0,
     9 .001115/, H/8*0.0,-.057989,.033124,.014870,-.011825
     A, -.000796,-.005758,2*0.0,-.001579,-.004075,.010006,
     B -.002,-.008735,3*0.0,.00021,.00043,.004597,-.003406,4*0.0
     C, .001385,.002421,-.000118,5*0.0,-.001218,-.001116,6*0.0
     D ,-.000325/, RD/1.56905124/, HC/6371200./
      P2 = POS (2)
      P1 = POS (1)
      IF (P1 - RD)105, 115, 100
  100 P1 = RD
      P2 = 0
      GO TO 115
  105 IF (P1 + RD)110, 115, 115
  110 P1 = - RD
      P2 = 0
  115 PHI = P2
      AR = HC / (HC + POS (3))
      C = SIN (P1)
      S = SQRT (CP (1) - C * C)
      SP (2) = SIN (PHI)
      CP (2) = COS (PHI)
      AOR (1) = AR * AR
      AOR (2) = AOR (1) * AR
      DO 120 M = 3, 7
      SP (M) = SP (2) * CP (M - 1) + CP (2) * SP (M - 1)
      CP (M) = CP (2) * CP (M - 1) - SP (2) * SP (M - 1)
  120 AOR (M) = AR * AOR (M - 1)
      BV = 0.
      BN = BV
      BPHI = BV
      DO 145 N = 2, 7
      FN = N
      SUMR = 0.
      SUMT = SUMR
      SUMP = SUMT
      IF (N .LT. 1) GO TO 150
      DO 140 M = 1, N
      IF (N - M)130, 125, 130
  125 P (N, N) = S * P (N - 1, N - 1)
      DP (N, N) = S * DP (N - 1, N - 1) + C * P (N - 1, N - 1)
      GO TO 135
  130  IF(N-2) 134,132,134
  132 P(2,1)=C
      DP(2,1)=-S
      GO TO 135
  134 P(N,M)=C*P(N-1,M)-CT(N,M)*P(N-2,M)
      DP (N, M) = C * DP (N - 1, M) - S * P (N - 1, M) - CT (N, M) * DP
     1(N - 2, M)
  135 FM = M - 1
      TS = G (N, M) * CP (M) + H (N, M) * SP (M)
      SUMR = SUMR + P (N, M) * TS
      SUMT = SUMT + DP (N, M) * TS
  140 SUMP = SUMP + FM * P (N, M) * ( - G (N, M) * SP (M) + H (N, M) * C
     1P (M))
  150 CONTINUE
      BV = BV + AOR (N) * FN * SUMR
      BN = BN - AOR (N) * SUMT
  145 BPHI = BPHI - AOR (N) * SUMP
      UNE (1) = - BV
      UNE (2) = BN
      UNE (3) = - BPHI / S
      RETURN
      END
C--------------------------------
