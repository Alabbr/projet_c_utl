prog:utl.o main.o
	gcc utl.o utl_main.o -o prog -g
main.o:utl_main.c
	gcc -c utl_main.c -g
fonctions.o:utl.c
	gcc -c utl.c -g
