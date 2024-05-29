#
#	---{[############}-CPPUTEST-{############]}---
#
MAKEFILE_DIR=.
PROJECT_DIR=.
TEST_DIR=test

CPPUTEST_HOME=$(TEST_DIR)/cpputest
CPPUTEST_PEDANTIC_ERRORS=N
CPPUTEST_OBJS_DIR=$(TEST_DIR)/objs
CPPUTEST_LIB_DIR=$(TEST_DIR)/lib
CPPFLAGS += -I$(CPPUTEST_HOME)/include
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest
SRC_DIRS=$(PROJECT_DIR)/src
INCLUDE_DIRS=$(PROJECT_DIR)/include
INCLUDE_DIRS+=$(CPPUTEST_HOME)/include
COMPONENT_NAME=strings
TEST_SRC_DIRS=$(TEST_DIR)/test_srcs

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
unitest: $(TEST_TARGET) 
	./$(TEST_TARGET) -c

#
# 	---{[####################################]}---
#

NAME= strings
FILENAME= lib$(NAME).a

CC = gcc
AR = ar
ARFLAGS = -rc
RM = rm -rf 
OBJDIR = build
SRCDIR = src
INCDIR = include


# CFLAGS = -Wall -Wextra -Werror  -I $(INCDIR) -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR) 

SRCS =	\
		io.c \
		cp.c \
		cmp.c \
		join.c \
		sub.c \
		utils.c \
		split.c \
		p_split.c \
		nsplit.c \
		rm.c \
		strings.c 

MAIN = main.c
LSTRINGSPATH = .
LDFLAGS = -L . -l$(NAME)

OBJS := $(addprefix $(OBJDIR)/,$(SRCS:%.c=%.o))

all: 

sanitize: CFLAGS += -fsanitize=address -g3 
sanitize: $(OBJS) 
	@echo "[libstrings]->>\033[34m [◊] SANITIZE MODE ON [◊]\033[0m"
	$(AR) $(ARFLAGS) $(FILENAME) $^

libdebug: $(OBJS)
	@echo "[libstrings]->> \033[33m [∆] DEBUG MODE ON [∆]\033[0m"
	$(AR) $(ARFLAGS) $(FILENAME) $^

$(NAME): $(FILENAME)
$(FILENAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR): 
	mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

main: $(MAIN) $(NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o main




 
libclean:
	$(RM) $(OBJDIR)
fclean: libclean
	$(RM) $(NAME)

re: fclean all

red: fclean debug

res: fclean sanitize

.PHONY: sanitize debug res red re clean fclean all
