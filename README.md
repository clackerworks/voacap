This is a port of the VOACAP Fortran Program to Plan9.
This was originally tracked under the version control kn2.
The port is bieng cleaned up and moved to git
for now
steps to build
1. Build libraries first by doing cd <library>; mk 
2. Build voacap by doing cd VOACAPW; mk
3. Build Coefficients by cd itshfbcFiles/itshfbc/ ; build

to run
make a work directory  by copying itshfbc 
cp the dat file in itshfbc/run
voacap <workdir>/itshfbc <datfile> <outputfile>
