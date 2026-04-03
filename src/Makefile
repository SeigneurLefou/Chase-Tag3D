CC := cc
SHELL := /bin/bash

ifdef DEBUG
	CFLAGS += -g
else
	CFLAGS := -Wall -Wextra -Werror -g
endif

CL_OBJ = $(CL_SRC:%.c=$(OUTPUT_DIR)/%.o)

SV_OBJ = $(SV_SRC:%.c=$(OUTPUT_DIR)/%.o)

$(CL_NAME): $(OUT_DIRS) $(CL_OBJ)
	@$(CC) $(CL_OBJ) $(CFLAGS) $(LDFLAGS) -o $@

$(SV_NAME): $(OUT_DIRS) $(SV_OBJ)
	@$(CC) $(SV_OBJ) $(CFLAGS) $(LDFLAGS) -o $@

$(OUT_DIRS):
	@mkdir -p $(OUT_DIRS)

$(OUTPUT_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

all: $(CL_NAME) $(SV_NAME)

clean:
	@rm -rf $(OUTPUT_DIR)

fclean: clean
	@rm -f $(CL_NAME)
	@rm -f $(SV_NAME)

re: fclean all

.PHONY: clean all re fclean
