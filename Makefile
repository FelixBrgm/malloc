SO_FLAGS := -shared -fPIC
CFLAGS := -I. -fPIC # -Wall -Werror -Wextra

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = build/libft_malloc_$(HOSTTYPE).so
NAME_SL = libft_malloc.so

# LIBS
OBJDIR := ./build
CFILES := malloc.c free.c helper.c zone.c realloc.c
CFILES := $(addprefix source/, $(CFILES))
OFILES := $(CFILES:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OFILES)
	@gcc $(SO_FLAGS) -o $(NAME) $(OFILES) # create shared library
	@rm -f $(NAME_SL) # remove old symlink
	@ln -sf $(NAME) $(NAME_SL) # create new symlink
	@echo "Compiled!"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@

clean: 
	@rm -rf $(OBJDIR)
	@echo "Cleaned!"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_SL)
	@rm -f ./tester
	@echo "FCleaned!"

re: fclean all

tests_main: all
	@gcc -o tests/test tests/main.c
	@echo "Test compiled!"
	@LD_PRELOAD=$(shell pwd)/libft_malloc.so ./tests/test
	@rm -f ./tests/test