# Nome do executável
EXECUTABLE = main

# Compilador
CC = g++

# Compilador flags
CFLAGS = -std=c++20 -Wall -Wextra -O3 -MMD

# Diretório onde estão os arquivos-fonte
SRC_DIR = src

# Diretório para os arquivos-objeto
BUILD_DIR = build

# Diretório para o arquivo executável
BIN_DIR = bin

# Lista de pastas contendo arquivos-fonte
SOURCE_DIRS = buscasLocais data estruturas guloso metaheuristicas perturbacoes problema solucao

# Lista de arquivos-fonte em cada pasta
SOURCES = $(foreach dir,$(SOURCE_DIRS),$(wildcard $(SRC_DIR)/$(dir)/*.cpp)) $(SRC_DIR)/main.cpp

# Nome dos arquivos-objeto gerados a partir dos arquivos-fonte
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Compila os objetos e o executável
all: clean_dependencies create_build_dir $(OBJECTS)
	@echo "\nCompilando $(EXECUTABLE)..."
	@$(CC) $(CFLAGS) -o $(BIN_DIR)/$(EXECUTABLE) $(OBJECTS)
	@echo "\033[32mCompilação concluída. O executável está em $(BIN_DIR)/$(EXECUTABLE) \033[0m \n"

# Regra genérica para compilar arquivos-objeto a partir dos arquivos-fonte
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) $(CFLAGS) -MM $< -MT $@ -MF $(BUILD_DIR)/$*.d > /dev/null 2>&1

# Executa o arquivo após a compilação
run:
	@if [ -f "$(BIN_DIR)/$(EXECUTABLE)" ]; then ./$(BIN_DIR)/$(EXECUTABLE); fi

# Cria a pasta build se não existir
# Cria todas as subpastas
create_build_dir:
	@mkdir -p $(BUILD_DIR)
	@$(foreach dir,$(SOURCE_DIRS),mkdir -p $(BUILD_DIR)/$(dir);)

# Limpa os arquivos de dependências
clean_dependencies:
	@echo "\nLimpando arquivos de dependências..."
	@rm -f $(OBJECTS:.o=.d)
	@echo "\033[33mLimpeza de arquivos de dependências concluída. \033[0m \n"

# Limpa tudo (objetos, arquivos de dependências e executável)
clean: clean_dependencies
	@echo "\nLimpando objetos..."
	@rm -f $(OBJECTS)
	@echo "\033[33mLimpeza de objetos concluída. \033[0m \n"
	@echo "\nLimpando o executável..."
	@rm -f $(BIN_DIR)/$(EXECUTABLE)
	@echo "\033[33mLimpeza de executável concluída. \033[0m \n"

# Limpa tudo e compila novamente
rebuild: clean all

# Compila e roda
i run: all run