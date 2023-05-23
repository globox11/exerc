CC                 := gcc
CXX                := g++
LD                 := g++
AR                 := ar rc
RANLIB := ranlib

DEBUG_CFLAGS     := -Wall -Wno-format -g -DDEBUG
RELEASE_CFLAGS   := -Wall -Wno-unknown-pragmas -Wno-format -O3

CFLAGS   := ${CFLAGS}
CXXFLAGS := ${INC_FLAGS} -std=c++17
INCS :=
LIBS :=
OUTPUT := exercice_01

SRC_DIRS ?= ../exercice_01

SRCS := $(shell find $(SRC_DIRS) -name "*.cpp" -or -name "*.c")
OBJS := $(addsuffix .o,$(basename ${SRCS}))

all : clean application

application : clean ${OBJS}
	g++ -g -O0 -o exercice_01 $(INCS) $(OBJS) $(LIBS_LINUX)

%.o : %.cpp
		${CXX} -c ${CXXFLAGS} ${INCS} $< -o $@

%.o : %.c
		${CC} -c ${CFLAGS} ${INCS} $< -o $@
save :
		sh ../save.sh ${pwd}

clean:
		-rm -f core ${OBJS} ${OUTPUT}
