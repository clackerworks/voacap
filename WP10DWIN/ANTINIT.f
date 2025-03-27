      subroutine antinit(iant,parm,antde,z6,umax,vmax)
c*******************************************************************
c       PURPOSE:
c          initialize CCIR antenna calculations
c       INPUT  PARAMETERS:
c          iant  = antenna index number [0-11]
c          parm(1-n) = parameters that define the antenna characteristics
c       OUTPUT PARAMETERS:
c          antde = [character*48] antenna descriptive name (e.g. HR 4/4/.5)
c          z6 = gain normalizing factor (used by ccirgain)
c          umax = elevation angle at z6
c          vmax = azimuthal angle at z6
c*******************************************************************
c       Written by Greg Hand NTIA/ITS Boulder, Colorado   Aug 1991
c       Please call (303)497-3375 with any questions.
c*******************************************************************
c       Calls following routines:
c          trigfun
c          logparm
c          parmprec
c          gainorm
c*******************************************************************
c                                  antenna floor value  [25dbi]
      common /floorc/ floor
      common/general/d1,e1,f1,p1,q1,s1,beta,rlambda
      common/cros/cpfr,cp11,fr1,h1,pfr,p11,p11s,q2,r2,r3,sl
      common/surf/ro,costh,sinth,rnumb,gamma,epq
      common/ccparm/uust,nat,ah1,bh1
      common/trig/a(0:361),b(0:361)
      common /ctype11g/ gain_type11(91)
      common /ctype11n/ antname_11
      character*20 antname_11
      common /cantname12/ antname12
      character antname12*10
c
      character cl*12
      character antde*(*),antmp*48
      dimension parm(20),gains(91)
      save ionce
      data ionce/0/
c
      if(ionce.eq.0) then
         ionce=1
c                                      antenna floor value [30dbi]
         floor=30.
         p1 = 3.1415927
         q1 = p1 / 180
         uust = 1.0
         vvst = 1.0
         call trigfun(a, b, uust)
      end if
c=========================================================================
      if(iant.eq.0) go to 10
      if(iant.eq.11) go to 1100
      if(iant.eq.12) then           !  NTIA Report 83-215 Curtain Arrays
         if(z6.lt.-1000. .or. z6.eq.0.) z6=1.
         call curnorm(parm,z6,umax,vmax,gmax)
         ifs=parm(15)               !  slew angle
         if(parm(10).lt.0.) then
            h1=-parm(10)
         else
            h1=parm(10)*parm(8)/299.79246
         end if
         if (ifs.eq.0) then
           write(antde,1) antname12,nint(parm(6)),nint(parm(7)),h1
1          format(a10,2x,'HR',i2,'/',i2,'/',f5.2)        
         else
           write(antde,2) antname12,nint(parm(6)),nint(parm(7)),h1,ifs
2          format(a10,2x,'HRS',i2,'/',i2,'/',f5.2,'(',i3,')')
         endif
         go to 2015
      end if
      e1 = parm(3)
      s1 = parm(4)
      f1 = parm(5)
      d1 = 18000 * s1 / f1
      rlambda = 299.8 / f1
      beta = 2 * p1 / rlambda
c=========================================================================
      if(iant.lt.0 .or. iant.gt.10) stop 'In antinit: iant out of range'
      go to (10,100,200,200,400,500,500,700,800,800,1000),iant+1
c*****************************************************************
c          iant = 0
c          Isotrope
c*****************************************************************
10    umax=0
      vmax=0
      giso=parm(1)
      z6=1.
      ifs=0
      write(antde,'(''ISO '',f5.1)') giso
      go to 2010
c*****************************************************************
c          iant = 1
c          Multi-band Center-Fed Half-Wave Dipole Array
c*****************************************************************
100     r2 = parm(6)
        r3 = parm(7)
        fd = parm(8)
        h1 = parm(9)
        ifs = parm(10)
        sd = parm(11)
        ws = parm(12)
        wd = parm(13)
        umax = parm(14)
        vmax = parm(15)
        giso = parm(16)
        z6 = parm(17)
        if (ifs.eq.0) then
           write(antde,101) ifix(r2),ifix(r3),h1
101        format('HR',i2,'/',i2,'/',f4.1)        
        else
           write(antde,102) ifix(r2),ifix(r3),h1,ifs
102        format('HRS',i2,'/',i2,'/',f4.1,'(',i3,')')
        endif
        fr = f1 / fd
        pfr = p1 * fr
        p11 = pfr / 2.0
        p11s = 8 * p11 * sd
        cpfr = cos(pfr)
        cp11 = cos(p11)
        sl = sin(ifs * q1)
        fdx = ws / (wd * p1 * .001)
        fdx1 = alog(fdx)
        fdx2 = .048 * ws
        fr1 = fdx1 * fdx2 * fr
        go to 2000
c****************************************************************
c          iant = 2
c          Dual-Band Center-Fed Half-Wave Dipole Array
c       &  iant = 3
c          Dual-Band End-Fed Half-Wave Dipole Array
c****************************************************************
200     r2 = parm(6)
        r3 = parm(7)
        fd = parm(8)
        h1 = parm(9)
        ifs = parm(10)
        q2 = parm(11)
        umax = parm(12)
        vmax = parm(13)
        giso = parm(14)
        if (ifs.eq.0) then
           write(antde,201) ifix(r2),ifix(r3),h1
201        format('HR',i2,'/',i2,'/',f4.1)        
        else
           write(antde,202) ifix(r2),ifix(r3),h1,ifs
202        format('HRS',i2,'/',i2,'/',f4.1,'(',i3,')')
        endif
        fr = f1 / fd
        pfr = p1 * fr
        p11 = pfr / 2.0
        cpfr = cos(pfr)
        cp11 = cos(p11)
        sl = sin(ifs * q1)
        go to 2000
c****************************************************************
c          iant = 4
c          Tropical Array
c****************************************************************
400     r2 = parm(6)
        r3 = parm(7)
        fd = parm(8)
        h1 = parm(9)
        ifs = parm(10)
        umax = parm(11)
        vmax = parm(12)
        giso = parm(13)
        if (ifs.eq.0) then
           write(antde,301) ifix(r2),ifix(r3),h1
301        format('TR',i2,'/',i2,'/',f4.1)        
        else
           write(antde,302) ifix(r2),ifix(r3),h1,ifs
302        format('TRS',i2,'/',i2,'/',f4.1,'(',i3,')')
        endif
        fr = f1 / fd
        pfr = p1 * fr
        p11 = pfr / 2.0
        cpfr = cos(pfr)
        cp11 = cos(p11)
        sl = sin(ifs * q1)
        go to 2000
c*****************************************************************
c          iant = 5
c          Horizontal Log-Periodic Array
c       &  iant = 6
c          Vertical Log-Periodic Array
c*****************************************************************
500     nel = parm(6)
        rl1 = parm(7) / 2.0
        rlnel = parm(8) / 2.0        
        dc = parm(9)
        h1 = parm(10)
        hnel = parm(11)
        z0 = parm(12)
        write(antde,501)nel,parm(7),parm(8),dc,ifix(h1),hnel,z0
501     format('LPH ',i2,'/',f4.1,'/',f4.1,'/',f5.1,'/',i2,'/',
     +         f5.2,'/',f5.1)
c          iant=6=vertical
        if(iant.eq.6) antde(1:3)='LPV'
        call logparm(iant,nel, rlnel, rl1, hnel, h1, dc, z0)
        ifs = 0
        go to 2000
c******************************************************************
c          iant = 7
c          Horizontal Rhombic
c******************************************************************
700     sl = parm(6) * beta
        h1 = parm(7) * beta * 2
        gamma = parm(8) * q1
        write(antde,701) nint(parm(6)),parm(7),nint(parm(8))
701     format('RH ',i3,'/',f4.1,'/',i3)        
        sinth = sin(gamma)
        costh = cos(gamma)
        ifs = 0
        go to 2000
c*******************************************************************
c          iant = 8
c          Quadrant Antenna
c       &  iant = 9
c          Crossed-Dipole Antenna
c*******************************************************************
800     fd = parm(6)
        h1 = parm(7)
        umax = parm(11)
        vmax = parm(12)
        giso = parm(13)
        if(iant.eq.8) write(antde,801) h1
801     format('HQ 1/',f4.1)
        if(iant.eq.9) write(antde,901) h1
901     format('HX',f4.1)
        fr = f1 / fd
        pfr = p1 * fr
        p11 = pfr / 2.0
        cp11 = cos(p11)
c          modified per 18/8/92 : ifs=0 : added
        ifs=0
        go to 2000
c***************************************************************
c          iant = 10
c          Vertical Monopole
c***************************************************************
1000    h1 = parm(6) * beta
        ro = parm(7) * beta
        if (ro.gt.0) then
          diam = parm(8)
          rnumb = parm(9)
          write(cl,1001) parm(7),ifix(rnumb),ifix(diam)
1001      format('/',f4.1,'/',i3,'/',i2)
        else
          diam = 0
          rnumb = 0
          cl = ' '
        endif
        write(antde,1002) ifix(parm(6)),cl
1002    format('VM',i2,a12)
        ah1 = sin(h1)
        bh1 = cos(h1)
        gamma = beta * rnumb * diam * .001
        phi = atan(d1 / e1) - .5 * atan(d1 / (e1 - 1))
        epsr = (((e1 - 1)**2 + d1**2)**.25) / sqrt(e1**2 + d1**2)
        epq = epsr**2
        sinth = epsr * sin(phi)
        costh = epsr * cos(phi)
        ifs = 0
        go to 2000
c*****************************************************************
c          iant = 11
c          Gain Table (91 elevation angles only)
c*****************************************************************
1100  umax=0           !  elevation angle
      vmax=0           !  azimuthal angle
      giso=parm(1)
      z6=1.
      gmax=-100.
      do 1105 ielev=1,91
      g=giso + gain_type11(ielev)
      if(g.le.gmax) go to 1105
         gmax=g
         umax=ielev
1105  continue
      giso=gmax
      antde=antname_11
      go to 2030
c***************************************************************
2000    iperf = 0
        call parmprec(iant, iperf)
2010    call gainorm( z6, umax, vmax, iperf,iant,ifs)
c***************************************************************
c          get rid of trailing '.', '.0', & '.00' in antenna description
c          Some FORTRANs do not handle this well, so I used 'antmp'
2015  do 2020 i=45,1,-1
      if(antde(i:i+2).eq.'.00') then
         antmp(i:48)=antde(i+3:48)//'   '
         antde(i:48)=antmp(i:48)
      else if(antde(i:i+1).eq.'.0' ) then
         antmp(i:48)=antde(i+2:48)//'  '
         antde(i:48)=antmp(i:48)
      else if(antde(i:i+1).eq.'./' ) then
         antmp(i:48)=antde(i+1:48)//' '
         antde(i:48)=antmp(i:48)
      else if(antde(i:i+2).eq.'/  ') then
         antmp(i+1:48)=antde(i+3:48)//'  '
         antde(i+1:48)=antmp(i+1:48)
      else if(antde(i:i+1).eq.'/ ' ) then
         antmp(i+1:48)=antde(i+2:48)//' '
         antde(i+1:48)=antmp(i+1:48)
      else if(antde(i:i+1).eq.'  ' ) then
         antmp(i+1:48)=antde(i+2:48)//' '
         antde(i+1:48)=antmp(i+1:48)
      end if
2020  continue
2030  return
      end
c----------------------------------------------------------------------
