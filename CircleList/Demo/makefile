CFLAGS = -g
COMPILE = g++ $(CFLAGS) -c
LINK = g++ $(CFLAGS)
LIBS = -framework GLUT -framework OpenGL -framework Cocoa

demo	: plot.o
	$(LINK) plot.o $(LIBS) -o demo

plot.o: plot.cpp plot.h
	$(COMPILE) plot.cpp

clean:
	rm *.o demo
