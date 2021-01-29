# Welcomre to Mamat, 044101
#
# This is the project's Makefile. It contains the instructions for compiling
# the projects C files, and then link the generated objects into an executable.
# This simple file will compile "main.c" to "main.o" and then link it (with C
# runtime library) to the executable "prog.exe".
#
# To compile, open the terminal in the folder that contains
# this file and run "make".
#
# To clean, open the terminal in the folder that contains
# this file and run "make clean".
#
# All eclipse projects in this machine are under /home/mamat/Documents/


CXX     = g++

CXXFLAGS = -Wall -Wextra -L. -g 
LDFLAGS = -fpic -shared

LIB_SRC = string.cpp field.cpp ip.cpp port.cpp
APP_SRC = main.cpp
DST_APP = firewall.exe
DST_LIB = firewall
OTHER = input

all:${DST_APP}

$(DST_LIB):
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LIB_SRC) -o lib$(DST_LIB).so

$(DST_APP) : $(DST_LIB)
	$(CXX) $(CXXFLAGS) $(APP_SRC) -o $(DST_APP) -l$(DST_LIB) -l$(OTHER)

