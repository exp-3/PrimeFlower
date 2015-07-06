# Makefile

TARGET		= PrimeFlower

CXX			= clang++
CXXFLAGS	= -std=c++0x -Wall -Wextra -Wconversion -g -O0 -MMD
LDFLAGS		=
LIBS		= -lGL -lGLU -lglut
INCLUDE		= -I./include
OBJDIR		= ./obj

SRCS		= $(wildcard *.c)\
			  $(wildcard *.cpp)\
			  $(wildcard src/*.c)\
			  $(wildcard src/*.cpp)
SRCDIRS		= $(dir $(SRCS))
BINDIRS		= $(addprefix $(OBJDIR)/, $(SRCDIRS))

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DEPS		= $(OBJS:.o=.d)

.PHONY: default
default:
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	@[ -d "$(BINDIRS)" ] || mkdir -p $(BINDIRS)
	@make all --no-print-directory

.PHONY: all
all: $(OBJS) $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CXX) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

-include $(DEPS)

.PHONY: clean
clean:
	@rm -rf $(TARGET) $(OBJDIR)

.PHONY: doc
doc:
	@doxygen Doxyfile
