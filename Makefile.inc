mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS +=\
Watch.o\

SRCLANG := c++

APPL_LIBS += -lm

APPL_DIRS += $(mkfile_path)Watch

INCLUDES += \
	-I$(mkfile_path)Watch\
