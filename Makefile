IDIR =..\inc
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=bin
LDIR =..\lib

LIBS=-lm

#_DEPS = mnistReader.h
#DEPS = $(patsubst %,$(IDIR)\%,$(_DEPS))

#_OBJ = mnistReader.o main.o 
#OBJ = $(patsubst %,$(ODIR)\%,$(_OBJ))

trainNN.exe: main.o Entity.o
	g++ -Wall -o trainNN.exe main.o Entity.o -g

main.o: main.cpp
	g++ -Wall -o main.o -c main.cpp -g

#mnistReader.o: mnistReader.cpp
#	g++ -Wall -o mnistReader.o -c mnistReader.cpp -g

#Network.o: Network.cpp
#	g++ -Wall -o Network.o -c Network.cpp -g

#Layer.o: Layer.cpp
#	g++ -Wall -o Layer.o -c Layer.cpp -g

#Node.o: Node.cpp Connection.o NodeBase.o
#	g++ -Wall -o Node.o -c Node.cpp -g

#Connection.o: Connection.cpp NodeBase.o Entity.o
#	g++ -Wall -o Connection.o -c Connection.cpp -g

#NodeBase.o: NodeBase.cpp Entity.o
#	g++ -Wall -o NodeBase.o -c NodeBase.cpp -g

Entity.o: Entity.cpp
	g++ -Wall -o Entity.o -c Entity.cpp -g

.PHONY: clean

clean:
	del trainNN.exe main.o mnistReader.o Network.o Layer.o Node.o Connection.o NodeBase.o Entity.o