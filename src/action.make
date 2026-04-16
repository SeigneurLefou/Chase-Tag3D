CPP := g++
SHELL := /bin/bash

LDFLAGS := -lSDL3

BIN = bin/

ifndef DEBUG
	CFLAGS := -Wall -Wextra -Werror -MD -MP
else
	CFLAGS := -Wall -Wextra -Werror -MD -MP -g
endif

CL_OBJ = $(CL_SRC:%.c=$(OUTPUT_DIR)/%.o)

SV_OBJ = $(SV_SRC:%.c=$(OUTPUT_DIR)/%.o)

WD_OBJ = $(WD_SRC:%.c=$(OUTPUT_DIR)/%.o)

all: mserver mclient

mwindow: $(WD_NAME)

mclient: $(CL_NAME)

mserver: $(SV_NAME)

$(CL_NAME): $(OUT_DIRS) $(CL_OBJ)
	mkdir -p $(BIN)
	$(CPP) $(CL_OBJ) $(LDFLAGS) -I$(INCLUDES) $(CFLAGS) -o $(BIN)$@

$(SV_NAME): $(OUT_DIRS) $(SV_OBJ)
	mkdir -p $(BIN)
	$(CPP) $(SV_OBJ) $(LDFLAGS) -I$(INCLUDES) $(CFLAGS) -o $(BIN)$@

$(WD_NAME): $(OUT_DIRS) $(WD_OBJ)
	mkdir -p $(BIN)
	$(CPP) $(WD_OBJ) $(LDFLAGS) -I$(INCLUDES) $(CFLAGS) -o $(BIN)$@

$(OUT_DIRS):
	mkdir -p $(OUT_DIRS)

$(OUTPUT_DIR)/%.o: %.c
	$(CPP) $(LDFLAGS) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OUTPUT_DIR)

fclean: clean
	rm -rf $(BIN)

re: fclean all

.PHONY: clean all re fclean
