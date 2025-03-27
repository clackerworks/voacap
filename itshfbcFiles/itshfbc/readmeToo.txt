READMETOO.TXT for itshfbc (Linux distro) 17 Apr 08

This is a modified version of the standard itshf/voacapw distribution, modified to work on Linux systems.  The distribution is based upon the 13th May Windows build.  

Note: In order of voacap to work correctly, the user must have write privileges to a number of directories within the itshfbc directory structure.  It is recommended that the directory is installed in the users home directory.

Following installation, the binary coefficient files must be built.
1.	cd ~/itshfbc/coeffs
2.	make

It is recommended that the coefficients are rebuilt every-time the main application rebuilt.

Modifications
17 Apr 08
- Updated News_win file
- Added 'north_pole.txt' to itshfbc/database
- removed a few of my scrappy old .dat & .out files

Original Release
- File names have all been changed to lower case.
- The contents of the 'bin' folder have been deleted.
- The contents of the coeffs directory have been replaced by the raw ascii files and a ported version of Greg Hand's code to build the required binary data files.
- Removed the w32 folder and all contents.  This will be ported to gfortran and add in later release.

Jim Watson (M0DNS)
