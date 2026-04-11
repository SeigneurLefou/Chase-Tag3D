CL_NAME = client
SV_NAME = server

BIN_DIR = bin/

OUTPUT_DIR = build

SRC_DIR = src

OUT_DIRS := $(OUTPUT_DIR)/$(SRC_DIR)

SV_SRC =
CL_SRC =

INCLUDES = includes

include src/server/server.make
include src/client/client.make

include src/action.make
