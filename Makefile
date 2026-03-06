CC = gcc
CFLAGS = $(shell pkg-config --cflags gtk4) -Iinclude -I. -MMD -MP
DEBUG_FLAGS = -g
LIBS = $(shell pkg-config --libs gtk4)

BUILD_DIR = build
TARGET = $(BUILD_DIR)/gtk-app
SRC = main.c src/demo_app.c \
	src/widgets/common.c \
	src/widgets/window.c \
	src/widgets/container.c \
	src/widgets/button.c \
	src/widgets/input.c \
	src/widgets/toggle.c \
	src/widgets/display.c \
	src/widgets/date.c \
	src/widgets/separator.c \
	src/widgets/dialog.c \
	src/widgets/menu.c \
	src/widgets/theme.c

OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	$(TARGET)

.PHONY: all clean run debug

-include $(DEP)
