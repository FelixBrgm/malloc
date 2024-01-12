AR := ar rcs
CFLAGS := -Wall -Werror -Wextra


ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

LINKED_LIST := linked_list

# LINKED_LIST
LINKED_LISTCFILES := ft_lstadd_back.c ft_lstadd_front.c   \
		    ft_lstclear.c ft_lstdelone.c ft_lstiter.c 				\
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c 
LINKED_LISTCFILES := $(addprefix $(LINKED_LIST)/, $(LINKED_LISTCFILES))

# LIBS
CFILES := $(LINKED_LISTCFILES)
OFILES := $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@$(AR) $(NAME) $(OFILES)
	@echo "Compiled!"

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean: 
	@rm -f $(OFILES)
	@echo "Cleaned!"

fclean: clean
	@rm -f $(NAME)
	@rm -f ./tester
	@echo "FCleaned!"

re: fclean all

main: $(NAME)
	$(CC) $(CFLAGS) main.c -o tester $(NAME)