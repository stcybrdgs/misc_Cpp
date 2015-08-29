# the compiler needs to be g++ for this C++ program
CC = g++
CFLAGS  = -g -Wall

default: mipsOps

# identify source files needed to create the object files
mipsOps_main.o:  mipsOps_main.cpp mipsOps_head.h
	$(CC) $(CFLAGS) -c mipsOps_main.cpp

mipsOps_implement.o:  mipsOps_implement.cpp mipsOps_head.h 
	$(CC) $(CFLAGS) -c mipsOps_implement.cpp

# identify object files needed to create the executable
mipsOps:  mipsOps_main.o mipsOps_implement.o 
	$(CC) $(CFLAGS) -o mipsOps mipsOps_main.o mipsOps_implement.o

# To start over from scratch, type 'make clean', which will  
# remove old files of type .exe, .o, ~
clean: 
	$(RM) mipsOps *.o *~
