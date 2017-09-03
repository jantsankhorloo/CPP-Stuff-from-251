# Define what compiler to use and the flags.
# This is the way you define and assign variables
# in a Makefile
CC=gcc -g
CXX=g++ -g
CCFLAGS= -g

# A rule in Makefile has the form:
#
# target: dependencies
#	command
#
# where "target" and "dependencies" are files (most of the time).
# These means that if "target" does not exist or the modification
# date of the dependencies are older than the modification time of
# "target" then "command" is executed.
#
# For example, the rule
#
# mystring.o : mystring.c
#	$(CC) -c $(CXXFLAGS) mystring.c
#
# means that if mystring.o does not exist, or if mystring.c is older
# than mystring.o, then execute "$(CC) -c $(CXXFLAGS) mystring.c".
#
# The goal of make is to execute the minimum set of commands that
# are necessary to build the target files.
#
# Usually, the first target in a Makefile is called "all".
# The dependencies of "all" are the files that we want to build.
#

all: TestMyString

# Build TestMyString
TestMyString: TestMyString.cpp MyString.cpp
	$(CXX) -o TestMyString TestMyString.cpp MyString.cpp


clean:
	rm -f core *.o TestMyString
