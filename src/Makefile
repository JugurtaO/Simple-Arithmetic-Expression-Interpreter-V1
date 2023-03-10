# CC=gcc
# CFLAGS=-g -Wall -c
# LDFLAGS=-g -Wall -o

# exe=calculette test_lexeme

# all:$(exe)

# analyse_lexicale.o: analyse_lexicale.c analyse_lexicale.h lecture_caracteres.h

# lecture_caracteres.o: lecture_caracteres.h lecture_caracteres.c

# test_lexeme.o: analyse_lexicale.h

# analyse_syntaxique.o:analyse_syntaxique.c  analyse_syntaxique.h analyse_lexicale.h lecture_caracteres.h 

# calculette.o: calculette.c analyse_lexicale.h analyse_syntaxique.h lecture_caracteres.h

# %.o:%.c
# 	$(CC) $(CFLAGS) $<

# test_lexeme: analyse_lexicale.o  lecture_caracteres.o  test_lexeme.o
# 	gcc -g -Wall -o test_lexeme analyse_lexicale.o  lecture_caracteres.o  test_lexeme.o

# calculette: calculette.o analyse_syntaxique.o analyse_lexicale.o  lecture_caracteres.o 
# 	gcc -g -Wall -o calculette analyse_syntaxique.o  analyse_lexicale.o  lecture_caracteres.o  calculette.o

# %:%.o
# 	$(CC) $(LDFLAGS) $@ $^
# clean:
# 	rm -f  *.o $(exe)


##########
# liste des fichiers source
SRC = calculette.c analyse_lexicale.c analyse_syntaxique.c lecture_caracteres.c 
#SRC = $(wildcard *.c)

# liste des fichiers .o et des dependances (mis dans le repertoire build/)
OBJ = $(addprefix build/,$(SRC:.c=.o))
DEP = $(addprefix build/,$(SRC:.c=.d))

# nom du compilateur
CC = gcc

# nom de l'executable
EXE = calculette 

# flags de compilation (CFLAGS) et d'edition de liens (LDFLAGS)
CFLAGS +=   -MMD -g -O2
LDFLAGS= #-lm

# regle principale: generer l'executable
all: $(OBJ)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

# regle generique pour produire un fichier .o a partir d'un fichier .c
build/%.o: %.c
	@mkdir -p build
	$(CC) $(CFLAGS) -o $@ -c $<

# regle generique pour faire du nettoyage
clean:
	rm -rf build core *.gch

# inclusion automatique du fichier de dependances
-include $(DEP)


















