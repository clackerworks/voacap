#
# Makefile to install the itshfbc files in the users
# home directory and build the coefficients. 
#

FORTRAN  = gfortran
OPTS     = -O2 -w
INSTALL = /usr/bin/install
INSTALL_ARGS = -d

# The GUI currently expects to see the itshfbc files in 
# the users home directory.  This may change later but leave
# the line below as it is for now.

INSTDIR = ~

install: coeffs
	cp -vr itshfbc/ $(INSTDIR)

coeffs: 
	(cd itshfbc/coeffs; $(MAKE) )

clean:
	( cd itshfbc/coeffs; $(MAKE) clean) 

