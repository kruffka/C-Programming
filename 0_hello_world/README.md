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
Source file: hello_asm.c

Preprocessor (*.i)
-----------
$ gcc -E hello_asm.c -o hello_asm.i  

Assembly (*.s)
-----------
$ gcc -S hello_asm.i -o hello_asm.s

Machine Code (object file, *.o)
-----------
$ gcc -c hello_asm.s -o hello_asm.o

#### ELF Header  
$ readelf -h hello_asm.o  

#### Machine code (disassemble)
$ objdump -s hello_asm.o  
$ objdump -d hello_asm.o  

Binary executable
-----------
$ gcc hello_asm.o -o hello_asm


Output:  
binary executable program  
$ ./hello_asm

