      SUBROUTINE MATINV (A, N)
C 
C     MATINV - INVERTS A REAL SQUARE (N BY N) MATRIX A AND STORES 
C        THE RESULTANT INVERSE BACK IN A.  THE METHOD USED IS GAUSS-
C        JORDAN ELIMINATION WITH COMPLETE PIVOTING (SEE, FOR EXAMPLE, 
C        A.RALSTON AND H.S.WILF (1967), MATHEMATICAL METHODS FOR
C        DIGITAL COMPUTERS, VOL. 2,  ARTICLE BY J.H.WILKINSON.) 
C     THIS ROUTINE IS SHARE NO. ANL F402 BY B.S.GARBOW OF ARGONNE 
C     NATIONAL LABORATORY, ARGONNE, ILLINOIS
C 
      DIMENSION A (20, 20)
C 
      COMMON /PON /INDEX (20, 2), IPIVOT (20), PIVOT (20) 
C 
C.....INITIALIZE........................................................
      DETERM = 1.0
      IF (N .LT. 1) GO TO 160 
      DO 100 J = 1, N 
 100  IPIVOT (J) = 0
 160  CONTINUE
      IF (N .LT. 1) GO TO 165 
      DO 140 I = 1, N 
C.....SEARCH FOR PIVOTAL ELEMENT........................................
      TEMP = 0.0
      IF (N .LT. 1) GO TO 170 
      DO 115 J1 = 1, N
      IF (IPIVOT (J1) .EQ. 1) GO TO 115 
      IF (N .LT. 1) GO TO 175 
      DO 110 K = 1, N 
      IF (IPIVOT (K) - 1)105, 110, 155
 105  IF (ABS (TEMP) .GT. ABS (A (J1, K))) GO TO 110
      IROW = J1 
      ICOLUM = K
      TEMP = A (J1, K)
 110  CONTINUE
 175  CONTINUE
 115  CONTINUE
 170  CONTINUE
      IPIVOT (ICOLUM) = IPIVOT (ICOLUM) + 1 
C.....INTERCHANGE ROWS TO PUT PIVOTAL ELEMENT ON DIAGONAL...............
      IF (IROW .EQ. ICOLUM) GO TO 125 
      DETERM = - DETERM 
      IF (N .LT. 1) GO TO 180 
      DO 120 L = 1, N 
      TEMP = A (IROW, L)
      A (IROW, L) = A (ICOLUM, L) 
 120  A (ICOLUM, L) = TEMP
 180  CONTINUE
 125  INDEX (I, 1) = IROW 
      INDEX (I, 2) = ICOLUM 
      PIVOT (I) = A (ICOLUM, ICOLUM)
      DETERM = DETERM * PIVOT (I) 
      IF (DETERM .EQ. 0.0) GO TO 155
C.....DIVIDE PIVOTAL ROW BY PIVOTAL ELEMENT.............................
      A (ICOLUM, ICOLUM) = 1.0
      IF (N .LT. 1) GO TO 185 
      DO 130 L1 = 1, N
 130  A (ICOLUM, L1) = A (ICOLUM, L1) / PIVOT (I) 
 185  CONTINUE
C.....REDUCE NON-PIVOTAL ROWS...........................................
      IF (N .LT. 1) GO TO 190 
      DO 140 I1 = 1, N
      IF (I1 .EQ. ICOLUM) GO TO 140 
      TEMP = A (I1, ICOLUM) 
      A (I1, ICOLUM) = 0.0
      IF (N .LT. 1) GO TO 195 
      DO 135 L2 = 1, N
 135  A (I1, L2) = A (I1, L2) - A (ICOLUM, L2) * TEMP 
 195  CONTINUE
 140  CONTINUE
 190  CONTINUE
 165  CONTINUE
C.....INTERCHANGE COLUMNS (TO UNDO THE SWAP TO GET MAX PIVOT ON DIAG)...
      IF (N .LT. 1) GO TO 200 
      DO 150 I2 = 1, N
      LL = N + 1 - I2 
      IF (INDEX (LL, 1) .EQ. INDEX (LL, 2)) GO TO 150 
      IROW = INDEX (LL, 1)
      ICOLUM = INDEX (LL, 2)
      IF (N .LT. 1) GO TO 205 
      DO 145 K1 = 1, N
      TEMP = A (K1, IROW) 
      A (K1, IROW) = A (K1, ICOLUM) 
 145  A (K1, ICOLUM) = TEMP 
 205  CONTINUE
 150  CONTINUE
 200  CONTINUE
 155  RETURN
      END
