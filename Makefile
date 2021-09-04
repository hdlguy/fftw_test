CXX=g++

# LIB_FLAGS = -larmadillo
LIB_FLAGS = -lfftw3
INCLUDES= -I. -I/usr/local/include/
DEPS = Makefile

OPT = -O0

CXXFLAGS = $(DEBUG) $(FINAL) $(OPT) $(EXTRA_OPT)

all: main

main: main.o 
	$(CXX) $(CXXFLAGS)  -o $@  $^  $(LIB_FLAGS)


%.o: %.c $(DEPS)
# $@: target file name, $^: all prerequisites
	$(CXX) -g -c -o $@ $< $(CFLAGS)


.PHONY: clean

clean:
	rm -f main *.o

