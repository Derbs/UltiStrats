CC = g++
CFLAGS = -Wall -Wextra -Werror
LIBS = -lglut

FieldDraw: field.cpp Player.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f FieldDraw
