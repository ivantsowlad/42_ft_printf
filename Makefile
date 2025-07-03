CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
MY_SOURCES = ft_printf.c ft_funcs_printf.c
MY_OBJECTS = $(MY_SOURCES:.c=.o)
AR = ar rcs

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(AR) $(NAME) $(MY_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
