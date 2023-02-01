IDIR =..\inc
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=bin
LDIR =..\lib

LIBS=-lm

_DEPS = mnistReader.h
DEPS = $(patsubst %,$(IDIR)\%,$(_DEPS))

_OBJ = mnistReader.o main.o 
OBJ = $(patsubst %,$(ODIR)\%,$(_OBJ))

#trainNN.exe: main.o mnistReader.o Network.o Layer.o Node.o Connection.o NodeBase.o Entity.o
trainNN.exe: main.o mnistReader.o Node.o NodeBase.o Entity.o Connection.o
	g++ -o trainNN.exe main.o mnistReader.o Node.o NodeBase.o Entity.o Connection.o

main.o: main.cpp
	g++ -o main.o -c main.cpp

mnistReader.o: mnistReader.cpp
	g++ -o mnistReader.o -c mnistReader.cpp

Network.o: Network.cpp
	g++ -o Network.o -c Network.cpp

Layer.o: Layer.cpp
	g++ -o Layer.o -c Layer.cpp

Node.o: Node.cpp Connection.o NodeBase.o
	g++ -o Node.o -c Node.cpp

Connection.o: Connection.cpp NodeBase.o Entity.o
	g++ -o Connection.o -c Connection.cpp

NodeBase.o: NodeBase.cpp Entity.o
	g++ -o NodeBase.o -c NodeBase.cpp

Entity.o: Entity.cpp
	g++ -o Entity.o -c Entity.cpp

.PHONY: clean

clean:
	del trainNN.exe main.o mnistReader.o Network.o Layer.o Node.o Connection.o NodeBase.o Entity.o