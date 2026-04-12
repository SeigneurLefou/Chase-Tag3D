CPP := g++
SHELL := /bin/bash

LDFLAGS := -L src/lib

ifndef DEBUG
	CFLAGS := -Wall -Wextra -Werror -MD -MP
else
	CFLAGS := -Wall -Wextra -Werror -MD -MP -g
endif

CL_OBJ = $(CL_SRC:%.c=$(OUTPUT_DIR)/%.o)

SV_OBJ = $(SV_SRC:%.c=$(OUTPUT_DIR)/%.o)

WD_OBJ = $(WD_SRC:%.c=$(OUTPUT_DIR)/%.o)

all: mclient mserver

mwindow: $(WD_NAME)

mclient: $(CL_NAME)

mserver: $(SV_NAME)

$(CL_NAME): $(OUT_DIRS) $(CL_OBJ)
	$(CPP) $(CL_OBJ) $(LDFLAGS) -I$(INCLUDES) $(CFLAGS) -o $@

$(SV_NAME): $(OUT_DIRS) $(SV_OBJ)
	$(CPP) $(SV_OBJ) $(LDFLAGS) -I$(INCLUDES) $(CFLAGS) -o $@

$(WD_NAME): $(OUT_DIRS) $(WD_OBJ)
	$(CPP) $(WD_OBJ) $(LDFLAGS) -I$(INCLUDES) $(CFLAGS) -o $@

$(OUT_DIRS):
	mkdir -p $(OUT_DIRS)

$(OUTPUT_DIR)/%.o: %.c
	$(CPP) $(LDFLAGS) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OUTPUT_DIR)

fclean: clean
	rm -f $(CL_NAME)
	rm -f $(SV_NAME)
	rm -f $(WD_NAME)

re: fclean all

.PHONY: clean all re fclean
