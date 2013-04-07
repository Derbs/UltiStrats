CPP = g++
CFLAGS = -Wall -Wextra -Werror
LIBS = -lglut

exa1: example1_1.cpp
	$(CPP) $(CFLAGS) -o $@ $^ $(LIBS)

exa2: example1_2.cpp
	$(CPP) $(CFLAGS) -o $@ $^ $(LIBS)

fieldDraw: field.cpp
	$(CPP) $(CFLAGS) -o $@ $^ $(LIBS)
