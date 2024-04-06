AR := ar rcs
# CFLAGS := -Wall -Werror -Wextra

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif


NAME = libft_malloc_$(HOSTTYPE).so
NAME_SL = libft_malloc.so

# LINKED_LIST
MALLOC_C_FILES := malloc.c free.c helper.c zone.c realloc.c

# LIBS
CFILES := $(MALLOC_C_FILES)
OFILES := $(CFILES:.c=.o)

all: $(NAME)


$(NAME): $(OFILES)
	@$(AR) $(NAME) $(OFILES)
	@ln -sf $(NAME) $(NAME_SL)
	@echo "Compiled!"

%.o : %.c
	@$(CC) -g -c $(CFLAGS) $< -o $@

clean: 
	@rm -f $(OFILES)
	@echo "Cleaned!"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_SL)
	@rm -f ./tester
	@echo "FCleaned!"

re: fclean all

main: $(NAME)
	$(CC) $(CFLAGS) main.c -o tester $(NAME)

test: main
	clear
	@./tester