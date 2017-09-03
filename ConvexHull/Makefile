
# The name of the test file
NAME:=lab4

# The compiler to use
CC:=gcc
CXX:=g++

#Enable warnings and include directories here
CFLAGS:=-Wall
#Linker line - add libraries that need to be referenced here
LDFLAGS:=-g -O0 -lGL -lGLU -lglut # -lrt -lm
#Uses the c++11 stdlib
STDLIB:=-std=c++11

#Get the list of source files
SRC=$(wildcard *.c) $(wildcard *.cpp)
#Get list of header files
HEADER=$(wildcard *.h)

#Get the list of objects from the sorucefile list
OBJ=$(patsubst %,bin/%.o,$(SRC))

#Add the chosen standard library to the CFLAGS
CFLAGS:= $(CFLAGS) $(STDLIB)

.PHONY: clean all

all: $(NAME)

#Combine the object files into the executable
$(NAME): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

#Generate object files from source files, using headers as dependencies
bin/%.o: % bin $(HEADER)
	$(CXX) -c $< -o $@ $(CFLAGS)

#The object (.o) files are kept in bin directory
bin:
	mkdir bin

clean:
	rm -rf bin $(NAME)
