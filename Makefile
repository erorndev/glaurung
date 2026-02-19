NXDK_DIR ?= $(HOME)/nxdk

XBE_TITLE = glaurung
TARGET    = glaurung.xbe
GEN_XISO  = $(XBE_TITLE).iso

NXDK_CXX = y

SRCS = $(wildcard src/*.cpp) $(wildcard xbox/*.cpp)

CXXFLAGS += -O3 -march=pentium3 -msse -mmmx -mfpmath=sse -fomit-frame-pointer -DNDEBUG
CXXFLAGS += -Iinclude -Ixbox -Isrc
LDFLAGS += /stack:1048576

include $(NXDK_DIR)/Makefile

$(SRCS:.cpp=.obj): CXXFLAGS += -include xbox/iostream.h -include xbox/timeval.h