##
## Makefile for plazza in /home/codeine/Projects/B4/CPP/cpp_plazza
## 
## Made by Lucas Debouté
## Login   <lucas.deboute@epitech.eu>
## 
## Started on  Thu Apr 13 10:15:21 2017 Lucas Debouté
## Last update Thu Apr 13 19:03:50 2017 Valentin Gérard
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
CXXFLAGS	+= -W -Wall -Wextra
CXXFLAGS	+= -std=c++11

SRCS		= $(SRCSDIR)/main.cpp

OBJS		= $(patsubst $(SRCSDIR)/%.cpp,$(OBJSDIR)/%.o,$(SRCS))

$(NAME):	build-objsdir $(OBJS)
		$(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJSDIR)/%.o:	$(SRCSDIR)/%.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

build-objsdir:
		@$(call make-objsdir)

all:		$(NAME)

clean:
		$(RM) $(NAME)

fclean:		clean
		$(RM) $(OBJS)

re:		fclean all

.PHONY:		all clean fclean re

define make-objsdir
	mkdir -p $(OBJSDIR)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJSDIR)/$$dir; \
	done
endef
