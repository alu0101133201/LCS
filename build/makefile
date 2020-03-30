IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

ODIR=../src

.PHONY: all

_OBJ = LCS.o table.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: LCS

$(ODIR)/LCS.o: $(ODIR)/LCS.cpp $(IDIR)/LCS.hpp
		$(CC) -c -o $@ $< $(CFLAGS)
$(ODIR)/table.o: $(ODIR)/table.cpp $(IDIR)/table.hpp
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp
		$(CC) -c -o $@ $< $(CFLAGS)


LCS: $(OBJ)
		$(CC)  -o $@ $^ $(CFLAGS)


.PHONY: clean
clean:
		rm -f $(ODIR)/*.o ./LCS