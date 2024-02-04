NAME= libstrings.a

CC = gcc
AR = ar
ARFLAGS = -rc
RM = rm -rf 
OBJDIR = build
SRCDIR = src
INCDIR = include


# CFLAGS = -Wall -Wextra -Werror  -I $(INCDIR) -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR)

SRCS =	\
		io.c \
		cp.c \
		split.c \
		strings.c 



OBJS := $(addprefix $(OBJDIR)/,$(SRCS:%.c=%.o))

all: $(NAME)

sanitize: CFLAGS += -fsanitize=address -g3 
sanitize: $(OBJS) 
	@echo "[libstrings]->>\033[34m [◊] SANITIZE MODE ON [◊]\033[0m"
	$(AR) $(ARFLAGS) $(NAME) $^
	
debug: CFLAGS += -g3
debug: $(OBJS)
	@echo "[libstrings]->> \033[33m [∆] DEBUG MODE ON [∆]\033[0m"
	$(AR) $(ARFLAGS) $(NAME) $^

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR): 
	mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

red: fclean debug

res: fclean sanitize

.PHONY: sanitize debug res red re clean fclean all
