LIBS=
CXX := g++
CFLAGS = -Wall --std=c++11

SOURCEDIR := src
OBJECTDIR := obj
BUILDDIR := build


UNAME := $(shell uname -s)
ifeq ($(UNAME),Darwin)
	# MACPORTS PATHS - not handling Homebrew or other weird systems
	# (intentionally).
	#CFLAGS += -L/opt/local/lib
	#CFLAGS += -I/opt/local/include
	LIBS += -framework OpenCL
endif


# Get all .cpp files
SRC := $(shell find $(SOURCEDIR) -name '*.cpp')

# Get all the .o files
OBJECTS := $(addprefix $(OBJECTDIR)/,$(notdir $(SRC:%.cpp=%.o)))

# Name of application
NAME = clank

all: $(NAME)

$(OBJECTDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f $(NAME) *.o
