# Makefile

# Directorios
BIN_DIR := bin
INCLUDE_DIR := include
SRC_DIR := src
OBJ_DIR := Temp

# Compilador y opciones
CC := g++
CFLAGS := -std=c++11 -Wall -I$(INCLUDE_DIR)
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
RM := rm -rf

# Archivos fuente y objetivos
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
EXECUTABLE := $(BIN_DIR)/mi_juego

# Regla principal para construir el ejecutable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Regla para construir los objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	$(RM) $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean
