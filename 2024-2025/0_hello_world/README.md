# Compile and run
Find out the compiler version and make sure it is installed
-----------
gcc --version

Compile and run program
-----------
$ gcc hello_world.c -o hello_world  
$ ./hello_world

or  

$ gcc hello_world.c  
$ ./a.out


# Compilation steps

Input:  
Source file: hello_gcc.c

Preprocessor (*.i)
-----------
$ gcc -E hello_gcc.c -o hello_gcc.i  

Assembly (*.s)
-----------
$ gcc -S hello_gcc.i -o hello_gcc.s

Machine Code (object file, *.o)
-----------
$ gcc -c hello_gcc.s -o hello_gcc.o

#### ELF Header  
$ readelf -h hello_gcc.o  

#### Machine code (disassemble)
$ objdump -s hello_gcc.o  
$ objdump -d hello_gcc.o  

Binary executable
-----------
$ gcc hello_gcc.o -o hello_gcc


Output:  
binary executable program  
$ ./hello_gcc

