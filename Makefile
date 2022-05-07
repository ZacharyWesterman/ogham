
ARCH = $(shell g++ -dumpmachine)

ifeq ($(findstring x86_64,$(ARCH)),x86_64)
CCTARGET = -m64
else
ifeq ($(findstring i686,$(ARCH)),i686)
CCTARGET = -m32
else
CCTARGET =
endif
endif

CCFLAGS = -std=c++11 -g -W -Wall -Wextra -pedantic -fexceptions -O4 $(CCTARGET)

STATIC_LIB = $(LIBNAME).a
DLL = $(LIBNAME).dll

LFLAGS = -s -shared

ifeq ($(OS),Windows_NT)
CFLAGS = $(CCFLAGS) -shared
LFLAGS += -fPIC
RMOBJS = $(subst /,\,$(OBJS))
RM = del
DEFAULT=ogham.exe
else
CFLAGS = $(CCFLAGS) -fPIC
LFLAGS += -ldl
RM = rm -f
DEFAULT=ogham
endif

DLFLAGS_WIN = -L. -lzed
DLFLAGS_NIX = -lzed

default: $(DEFAULT)

ogham: ogham.o
	g++ -o $@ $^ $(DLFLAGS_NIX)

ogham.exe: ogham.o
	g++ -o $@ $^ $(DLFLAGS_WIN)

ogham.o: ogham.cpp
	g++ $(CCFLAGS) -o $@ -c $^

clean:
	$(RM) $(DEFAULT) *.o

.PHONY: default clean
