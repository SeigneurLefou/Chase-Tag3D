CC := cc
SHELL := /bin/bash

ifndef DEBUG
	CFLAGS := -Wall -Wextra -Werror -MD -MP
else
	CFLAGS := -Wall -Wextra -Werror -MD -MP -g
endif

CL_OBJ = $(CL_SRC:%.c=$(OUTPUT_DIR)/%.o)

SV_OBJ = $(SV_SRC:%.c=$(OUTPUT_DIR)/%.o)

all: $(CL_NAME) $(SV_NAME)

$(CL_NAME): $(OUT_DIRS) $(CL_OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CL_OBJ) $(CFLAGS) -o $(BIN_DIR)$@

$(SV_NAME): $(OUT_DIRS) $(SV_OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(SV_OBJ) $(CFLAGS) -o $(BIN_DIR)$@

$(OUT_DIRS):
	mkdir -p $(OUT_DIRS)

$(OUTPUT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OUTPUT_DIR)

fclean: clean
	rm -f $(CL_NAME)
	rm -f $(SV_NAME)

re: fclean all

.PHONY: clean all re fclean
