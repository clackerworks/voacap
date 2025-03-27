FORTRAN  = gfortran
#FORTRAN  = /opt/intel/fc/10.0.023/bin/ifort
OPTS     = -O2 -w
DRVOPTS  = $(OPTS)
NOOPT    = -O0
LOADER   = gfortran
LOADOPTS = -O2

ARCH     = ar
ARCHFLAGS= cr
RANLIB   = ranlib

OBJ = anttyp90.o ant90.o \
	lenchar.o ucase.o

anttyp90: $(OBJ)
	$(FORTRAN) $(OPTS) $(OBJ) -o anttyp90

clean:
	rm -f *.o
	rm -f anttyp90
	rm -f *~

.f.o: 
	$(FORTRAN) $(OPTS) -c $< -o $@

