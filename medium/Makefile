########################################################################
# General Makefile
#
# This is a general makefile for a c project. You need to fill in the
# program name, the source files, and the dependency (header or
# resource) files. It should work with very minor changes in the
# pattern substitution for c++ and fortran files.
########################################################################
# Name of the program
PROGRAM = medium
# A list of the source files
SRCS = medium.c \
       function.c
# A list of the dependencies
DEPS = function_test.h 

# Directory names for sources, objects, ect.
ODIR = obj
SDIR = src
TDIR = test
DDIR = doc

# Use pattern substitution for created filenames
OBJS = $(patsubst %.c, %.o, $(SRCS))
TESTS = $(patsubst %.c, %_test, $(SRCS))

# Choose the C, C++, and Fortran compiler
CC=gcc
CXX=g++
FC=gfortran

# Options for finding external libraries
LDFLAGS += -L/opt/local/lib
CFLAGS += -I/opt/local/include
#LDFLAGS += -L/usr/local/lib
#LDFLAGS += -L/usr/lib
#CFLAGS += -I/usr/local/include
#CFLAGS += -I/usr/include
CFLAGS += -I.

# Additional options
CFLAGS += -Wall
CFLAGS += -ggdb
CFLAGS += -O0
#CFLAGS += -O3

# Libraries
#LIBS += -lgsl
#LIBS += -lgslcblas
#LIBS += -llapack -lptcblas -latlas
#LIBS += -lnlopt
LIBS += -lm

.PHONEY: all clean test docs

$(PROGRAM): $(patsubst %, $(ODIR)/%, $(OBJS))
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c $(patsubst %, $(SDIR)/%, $(DEPS))
	$(CC) -c $(CFLAGS) $< -o $@

$(TDIR)/%_test: $(SDIR)/%_test.c %(SDIR)/%.c \
                $(patsubst %, $(SDIR)/%, $(DEPS))
	$(CC) -c $(CFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@
	$@

all: test docs $(PROGRAM)

clean:
	rm $(ODIR)/*.o $(PROGRAM)

test: $(patsubstr %, $(TDIR)/%, $(TESTS⁄))

docs: $(patsubst %, $(SDIR)/%, $(SRCS)) \
      $(patsubst %, $(SDIR)/%, $(DEPS))
    doxygen