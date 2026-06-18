CC ?= gcc

SOURCES = main.c \
        index.c demux.c seq.c fasta.c utils.c search.c db.c engine.c \
        rbtree.c vector.c hit.c suffix.c query.c work_queue.c \
        priority_queue.c alignment.c ssw.c ssw_wrapper.c \
        divsufsort.c trsort.c sssort.c seg_wrapper.c \
        seg/seg.c seg/genwin.c

OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = topaz

INCLUDES += -I. -I./seg

# ----------------------------
# OpenMP configuration
# ----------------------------
USE_OPENMP ?= 1

# user override for Homebrew or custom OpenMP install
OMP_PREFIX ?=

CPPFLAGS += $(if $(OMP_PREFIX),-I$(OMP_PREFIX)/include)
LDFLAGS  += $(if $(OMP_PREFIX),-L$(OMP_PREFIX)/lib)

# compiler OpenMP flags
OPENMP_CFLAGS  = -fopenmp
OPENMP_LDFLAGS = -fopenmp

UNAME_S := $(shell uname -s)

# Apple Clang special case
ifeq ($(UNAME_S),Darwin)
    IS_CLANG := $(findstring clang,$(shell $(CC) --version))

    ifneq ($(IS_CLANG),)
        OPENMP_CFLAGS  = -Xpreprocessor -fopenmp
        OPENMP_LDFLAGS = -lomp
    endif
endif

ifeq ($(USE_OPENMP),1)
    CFLAGS  += $(OPENMP_CFLAGS)
    LDFLAGS += $(OPENMP_LDFLAGS)
endif

# ----------------------------
# Flags
# ----------------------------
CFLAGS += -Wall -Wno-unused-variable -O3 -g -c

# ----------------------------
# Build rules
# ----------------------------
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
