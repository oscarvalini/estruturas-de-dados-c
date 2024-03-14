DEBUG = 1

C = gcc
CFLAGS = -Wall -std=c11
# LDFLAGS = -lmath

ifeq ($(DEBUG), 1)
CFLAGS += -g -O0
else
CFLAGS += -O3
endif

COMPILER_CALL = $(C) $(CFLAGS) $(LDFLAGS)

# @ - Execução silenciosa
build: main.o pilha.o
	@$(COMPILER_CALL) main.o pilha.o -o dist/main
	@make clean

main.o:
	gcc main.c -c

pilha.o:
	gcc pilha.c -c

execute:
	./dist/main

clean:
	rm -f ./*.o