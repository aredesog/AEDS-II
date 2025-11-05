
# Compilador
CC = gcc

# Flags de compilação 
CFLAGS = -Wall -O2

# Arquivos 
MAIN = main.c
HEADER = ordenacao.h
OUTPUT = ordenar

# Regra padrão: compilar o programa
all: $(OUTPUT)

# Como gerar o executável
$(OUTPUT): $(MAIN) $(HEADER)
	$(CC) $(CFLAGS) $(MAIN) -o $(OUTPUT)

# Limpar arquivos 
clean:
	rm -f $(OUTPUT)
	rm -f bloco_*.txt
	rm -f saida_ordenada.txt

# Executar 
run: all
	./$(OUTPUT)
