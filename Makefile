SRC = cliMain.c verification.c io.c list.c
OBJ = $(SRC:%.c=%.o)


all:	empdb 

empdb:	cliMain.o verification.o io.o list.o
	gcc -o empdb $(OBJ)

clean:
	rm $(OBJ) empdb
	
