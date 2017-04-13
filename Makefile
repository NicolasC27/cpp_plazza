##
## Makefile for cpp_plazza in /home/ikirame/Documents/Projects/cpp_plazza
## 
## Made by Valentin Gérard
## Login   <valentin.gerard@epitech.eu>
## 
## Started on  Thu Apr 13 17:32:21 2017 Valentin Gérard
## Last update Thu Apr 13 17:32:22 2017 Valentin Gérard
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
