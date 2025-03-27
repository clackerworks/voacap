      program foF2bin
c          convert foF2CCIR.asc to direct access file:foF2CCIR.da
c          convert foF2URSI.asc to direct access file:foF2URSI.da
c          convert foF2dail.asc to binary        file:foF2dail.bin
c**********************************************************************
      dimension XF2COF(13,76,2)
      character coeff(2)*4,title*80,filein*12,fileout*12
      data coeff/'CCIR','URSI'/
c**********************************************************************
      do 200 icoeff=1,2
      filein='fof2'//coeff(icoeff)//'.asc'
      fileout='fof2'//coeff(icoeff)//'.da'
      open(19,file=filein,status='old')
      rewind(19)
      read(19,'(a)') title
      open(20,file=fileout,form='unformatted',access='direct',recl=7904)
      write(*,101) fileout,filein,title
101   format(' Creating:',a,' from:',a,' title=',a)
      do 100 month=1,12
      read(19,1) mon
1     format(6x,i2)
      if(mon.ne.month) stop 'month record does not match'
      read(19,3) XF2COF
3     format(6e15.8)
      write(20,rec=month) XF2COF
100   continue
      close(20)
200   close(19)
c********************************************************************
c          now create the daily foF2 binary coefficient file
      write(*,'('' Creating:fof2daly.bin  from:fof2daly.asc'')')
      OPEN (21,FILE='fof2daly.asc',STATUS='OLD')
      REWIND(21)
      OPEN (22,FILE='fof2daly.bin',form='unformatted')
      REWIND(22)
      read(21,'(a)') title
      write(*,'(1x,a)') title(1:70)
      DO 10 KFOF2R=1,9
      read(21,'(a)') title
      write(*,'(1x,a)') title(1:70)
      READ (21,11) XF2COF
10    write(22) xf2cof
11    format(6(e12.6,1x))
      close(22)
      close(21)
c********************************************************************
      STOP 'foF2 BINARY COEFFICIENTS created'
      END

