######################################################################
# General Makefile
#
# This is a general makefile for a medium sized c project. The source
# files, object files, test cases, and documentation are all in
# separate files.
######################################################################
# Name of the program
PROGRAM = medium

# Directory names for sources, objects, ect.
SDIR = src
ODIR = obj
TDIR = test
DDIR = doc

# Use wild cards to get a list of sources
SRCS = $(wildcard $(SDIR)/*.c)
TEST_SRCS = $(wildcard $(TDIR)/*_test.c)
# Use pattern substitution to get list of objects and dependencies
OBJS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
DEPS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.d, $(SRCS))
TESTS = $(patsubst %.c, %, $(TEST_SRCS)) 
TEST_OBJS = $(patsubst %.c, %.o, $(TEST_SRCS))
TEST_DEPS = $(patsubst %.c, %.d, $(TEST_SRCS))

# Choose the C, C++, and Fortran compiler
CC=gcc
CXX=g++
FC=gfortran

# Options for finding external libraries
# For the Mac OSX macports default location
LDFLAGS += -L/opt/local/lib
CFLAGS += -I/opt/local/include
# For the default Linux locations
#LDFLAGS += -L/usr/local/lib
#LDFLAGS += -L/usr/lib
#CFLAGS += -I/usr/local/include
#CFLAGS += -I/usr/include

# Additional options
# Give all warnings
CFLAGS += -Wall
# Options for debugging
CFLAGS += -ggdb
CFLAGS += -O0
# Options for optimized code
#CFLAGS += -O3

# Libraries
# The GNU Scientific Library
#LIBS += -lgsl -lgslcblas
# Altas flavored lapack and BLAS
#LIBS += -llapack -lptcblas -latlas
# In c we alwasy need the default math library
LIBS += -lm

# Default rule compiles the program from all object files
$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

# Include the dependencies
include $(DEPS)
include $(TEST_DEPS)

# Implicit rule for automatic dependency generation
$(ODIR)/%.d: $(SDIR)/%.c
	@set -e; rm -f $@; \
	 $(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	 sed 's,\($*\)\.o[ :]*,$(ODIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	 rm -f $@.$$$$

# Implicit rule for object generation
$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

# Implicit rule for test dependency generation
$(TDIR)/%_test.d: $(TDIR)/%_test.c
	@set -e; rm -f $@; \
	 $(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	 sed 's,\($*\)_test\.o[ :]*,$(TDIR)/\1_test.o $@ : ,g' < $@.$$$$ > $@; \
	 rm -f $@.$$$$

# Implicit rule for test generation and running
$(TDIR)/%_test: $(TDIR)/%_test.o
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $< -o $@
	@./$@

# Implicit rule for test object generation
$(TDIR)/%_test.o: $(TDIR)/%_test.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

.PHONY: all clean test docs

# Run the test, build the program, make the docs

# 
clean:
	rm -f $(ODIR)/* $(PROGRAM)
	rm -f $(TDIR)/*_test $(TDIR)/*.o $(TDIR)/*.d

test: $(TESTS)

#docs: 
#    doxygen
