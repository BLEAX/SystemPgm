CC=gcc
CFLAGS= -g -Wall
OBJS=hello.o world.o main.o
TARGET=app.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

hello.o: hello.h hello.c
world.o: world.h world.c
main.o: hello.h world.h main.c

clean:
	rm -f *.o
	rm -f $(TARGET)


