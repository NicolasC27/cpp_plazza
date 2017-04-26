##
## Makefile for Makefile in /home/nicolas/rendu/cpp_plazza
## 
## Made by Nicolas
## Login   <nicolas1.chevalier@epitech.eu>
## 
## Started on  Thu Apr 13 17:32:21 2017 Valentin Gérard
## Last update Thu Apr 27 00:14:57 2017 Valentin Gérard
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

LDFLAGS		= -pthread

SRCS		= $(SRCSDIR)/main.cpp \
		  $(SRCSDIR)/IOfd.cpp \
		  $(SRCSDIR)/Exception.cpp \
		  $(SRCSDIR)/NamedPipe.cpp \
		  $(SRCSDIR)/ThreadPool.cpp \
		  $(SRCSDIR)/SemaphoreRessources.cpp \
		  $(SRCSDIR)/Semaphore.cpp \
		  $(SRCSDIR)/Regex.cpp \
		  $(SRCSDIR)/Fork.cpp \
		  $(SRCSDIR)/Data.cpp \
		  $(SRCSDIR)/PlazzaCore.cpp \
		  $(SRCSDIR)/Parser.cpp \
		  $(SRCSDIR)/PlazzaProcess.cpp

OBJS		= $(patsubst $(SRCSDIR)/%.cpp,$(OBJSDIR)/%.o,$(SRCS))

$(NAME):	build-objsdir $(OBJS)
		$(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)

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
