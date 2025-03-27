FORTRAN  = gfortran
OPTS     = -O
DRVOPTS  = $(OPTS)
NOOPT    = -O0
LOADER   = gfortran
LOADOPTS = -O2


coef: 
	$(FORTRAN) $(OPTS) -o coefbinw coefbinw.for 
	$(FORTRAN) $(OPTS) -o coeffbin coeffbin.for 
	$(FORTRAN) $(OPTS) -o fof2bin fof2bin.for
	$(FORTRAN) $(OPTS) -o fof2binw fof2binw.for
	(./coefbinw)
	(./coeffbin)
	(./fof2bin)
	(./fof2binw)


clean:
	rm -f *.bin
	rm -f *.daw
	rm -f *.da
	rm -f coefbinw
	rm -f coeffbin
	rm -f fof2bin
	rm -f fof2binw

.f.o: 
	$(FORTRAN) $(OPTS) -c $< -o $@

