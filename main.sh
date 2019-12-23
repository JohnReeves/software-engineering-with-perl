./shout dumptree output and 
./shout how to make your own gcc plugins
# http://starynkevitch.net/basile/gcc-melt/GCC-MELT-HiPEAC2012.pdf
# https://gcc.gnu.org/onlinedocs/gccint/Plugins.html
# https://www.fsl.cs.sunysb.edu/ssw/files/Download/gccplugins.pdf
gcc -fdump-tree-gimple -o shout shout.c
gcc -o qsort qsort.c
 
