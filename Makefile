##
## Makefile for Arcade in /home/ikirame/Documents/Projects/cpp_arcade/lib/Ncurses
##
## Made by Valentin Gérard
## Login   <valentin.gerard@epitech.eu>
##
## Started on  Wed Mar 29 20:50:56 2017 Valentin Gérard
## Last update Sat Apr  8 21:13:25 2017 Nicolas Nicolas
##

DEBUG		= no

SRCSDIR		= srcs
OBJSDIR		= objs

ifeq ($(DEBUG), yes)
CXX		= g++ -g
else
CXX		= g++
endif

RM		= rm -f

NAME		= plazza

CXXFLAGS	= -I./includes
CXXFLAGS	+= -I../../Core/includes
CXXFLAGS	+= -W -Wall -Wextra
CXXFLAGS	+= -std=c++11

SRCS		= $(SRCSDIR)/main.cpp \
		  $(SRCSDIR)/PlazzaCore.cpp \
		  $(SRCSDIR)/Data.cpp

OBJS		= $(patsubst $(SRCSDIR)/%.cpp,$(OBJSDIR)/%.o,$(SRCS))

$(NAME):	build-objsdir $(OBJS)
		$(CXX) $(OBJS) -o $(NAME) -lncurses

$(OBJSDIR)/%.o:	$(SRCSDIR)/%.cpp
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
