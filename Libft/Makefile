NAME := libft.a
HEADERFILE := libft.h
SRCFILES := ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_printf.c \
handle_char.c \
handle_string.c \
handle_pointer.c \
handle_signed.c \
handle_unsigned.c \
handle_hexa_low.c \
handle_hexa_up.c

OBJFILES := $(SRCFILES:.c=.o)
CFLAGS ?= -Wall -Wextra -Werror -c

all : $(NAME)

$(NAME): $(OBJFILES)
	ar -rcs $(NAME) $(OBJFILES)

%.o: %.c 
	cc $(CFLAGS) $^

clean:
	rm -f $(OBJFILES)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
