##
## Makefile for plazza in /home/codeine/Projects/B4/CPP/cpp_plazza
## 
## Made by Lucas Debouté
## Login   <lucas.deboute@epitech.eu>
## 
## Started on  Thu Apr 13 10:15:21 2017 Lucas Debouté
## Last update Thu Apr 13 10:28:52 2017 Lucas Debouté
##

CC	= g++
RM	= rm -f

SRCS	= srcs/main.cpp

GUISRCS	= srcs/main.cpp

OBJS	= $(SRCS:.cpp=.o)

GUIOBJS	= $(GUISRCS:.cpp=.o)

NAME	= plazza

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

GUI: $(GUIOBJS)
	$(CC) -o $(NAME) $(GUIOBJS)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJS)
	$(RM) $(GUIOBJS)

re: fclean all

.PHONY: all clean fclean re
