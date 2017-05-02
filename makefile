
CC = g++
CFLAGS = -g -I

RM = rm 
RMFLAGS = -r -f

LIBS = -lm

SRCS_UG = ./src/undirected.cpp
SRCS_DG = ./src/directed.cpp

INCLUDES = ./include/

all:   clean undirGraph dirGraph

clean:	
	$(RM) $(RMFLAGS) ./bin/*
undirGraph:	$(SRCS_UG)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_UG) -o ./bin/undirGraph $(LIBS)
dirGraph:	$(SRCS_DG)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_DG) -o ./bin/dirGraph $(LIBS)
