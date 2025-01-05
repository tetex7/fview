default: all

STATIC ?= 0
GCC_FLAGS =
VER ?= d.e.v
DEBUG ?= 1

ifeq ($(OS),Windows_NT)
  FNAME = fview.exe
  RVER = $(VER)-win
else
  FNAME = fview
  RVER = $(VER)
endif

ifeq ($(STATIC),1)
  GCC_FLAGS += -static
endif

ifeq ($(DEBUG),1)
  GCC_FLAGS += -g -O0
else
  GCC_FLAGS += -O2
endif

all:
	g++ -std=gnu++2a $(GCC_FLAGS) -DFV_VER="\"$(RVER)\"" fview.cpp -o $(FNAME)
#strip -s -o fview.exe fview.exe

clean:
	rm -f $(FNAME)