CC=gcc
CFLAGS=-g -Wall -c
LDFLAGS=-g -Wall -o

exe=calculette test_lexeme

all:$(exe)

analyse_lexicale.o: analyse_lexicale.c analyse_lexicale.h lecture_caracteres.h

lecture_caracteres.o: lecture_caracteres.h lecture_caracteres.c

test_lexeme.o: analyse_lexicale.h

analyse_syntaxique.o:analyse_syntaxique.c  analyse_syntaxique.h analyse_lexicale.h lecture_caracteres.h 

calculette.o: calculette.c analyse_lexicale.h analyse_syntaxique.h lecture_caracteres.h

%.o:%.c
	$(CC) $(CFLAGS) $<

test_lexeme: analyse_lexicale.o  lecture_caracteres.o  test_lexeme.o
	gcc -g -Wall -o test_lexeme analyse_lexicale.o  lecture_caracteres.o  test_lexeme.o

calculette: calculette.o analyse_syntaxique.o analyse_lexicale.o  lecture_caracteres.o 
	gcc -g -Wall -o calculette analyse_syntaxique.o  analyse_lexicale.o  lecture_caracteres.o  calculette.o

%:%.o
	$(CC) $(LDFLAGS) $@ $^
clean:
	rm -f  *.o $(exe)


