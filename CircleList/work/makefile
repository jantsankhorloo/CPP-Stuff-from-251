CFLAGS = -g
COMPILE = g++ $(CFLAGS) -c
LINK = g++ $(CFLAGS)
LIBS = -lGL -lGLU -lglut


all:	lab2	mytests
lab2	: plot.o clist.o
	$(LINK) plot.o clist.o $(LIBS) -o lab2

mytests:	mytests.o  clist.o
		$(LINK) mytests.o  clist.o $(LIBS) -o mytests

mytests.o: mytests.cpp clist.h
	$(COMPILE)  mytests.cpp
        
plot.o: plot.cpp plot.h
	$(COMPILE) plot.cpp
	
clist.o: clist.cpp clist.h
	$(COMPILE) clist.cpp
	
clean:
	rm -f *.o lab2 mytests

.PHONY: all mytests clean

