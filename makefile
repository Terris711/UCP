CC=gcc
OBJ=main.o linkedList.o processing.o log.o 
CFlAGS=Wall
EXEC=final

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) 


main.o: main.c linkedList.h processing.h log.h
	$(CC) $(CFLAGS) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

processing.o: processing.c processing.h log.h linkedList.h
	$(CC) $(CFLAGS) -c processing.c


log.o: log.c log.h linkedList.h
	$(CC) $(CFLAGS) -c log.c

clean:
	rm -i $(EXEC) $(OBJ)

