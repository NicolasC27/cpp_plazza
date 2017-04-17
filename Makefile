##
## Makefile for Makefile in /home/nicolas/rendu/cpp_plazza
## 
## Made by Nicolas
## Login   <nicolas1.chevalier@epitech.eu>
## 
## Started on  Mon Apr 17 20:48:57 2017 Nicolas
## Last update Mon Apr 17 20:48:57 2017 Nicolas
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
