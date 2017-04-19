##
## Makefile for Makefile in /home/nicolas/rendu/cpp_plazza
## 
## Made by Nicolas
## Login   <nicolas1.chevalier@epitech.eu>
## 
## Started on  Thu Apr 13 17:32:21 2017 Valentin Gérard
## Last update Wed Apr 19 17:28:03 2017 Valentin Gérard
##

DEBUG		= no

INCDIR		= includes
SRCSDIR		= srcs
OBJSDIR		= objs

ifeq ($(DEBUG), yes)
CXX		= g++ -g
else
CXX		= g++
endif

RM		= rm -f

NAME		= plazza

CXXFLAGS	= -I./$(INCDIR)
CXXFLAGS	+= -W -Wall -Wextra
CXXFLAGS	+= -std=c++11

SRCS		= $(SRCSDIR)/main.cpp \
		  $(SRCSDIR)/IOfd.cpp \
		  $(SRCSDIR)/Exception.cpp \
		  $(SRCSDIR)/NamedPipe.cpp \
		  $(SRCSDIR)/Fork.cpp \
		  $(SRCSDIR)/Data.cpp \
		  $(SRCSDIR)/PlazzaCore.cpp

OBJS		= $(patsubst $(SRCSDIR)/%.cpp,$(OBJSDIR)/%.o,$(SRCS))

$(NAME):	build-objsdir $(OBJS)
		$(CXX) $(OBJS) -o $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

build-objsdir:
		@$(call make-objsdir)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

define make-objsdir
	mkdir -p $(OBJSDIR)
	for dir in $(SRCDIRS); \
	do \
	  mkdir -p $(OBJSDIR)/$$dir; \
	done
endef
