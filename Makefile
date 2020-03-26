# Makefile criado por Gustavo Bacagine <gustavo.bacagine@protonmail.com>
#
# Data de criação: 25/12/2019
#
# fatec.h é uma Biblioteca criada pelos
# alunos da FATEC de Carapicuíba do curso de ADSM.
#
# Esta biblioteca contem o prototipo das
# funções e estruturas que foram usadas no
# primeiro ano do curso
#
# Git Hub: https://github.com/Bacagine/fatec


#TARGET = fatec
#SRCDIR = ./src
#OBJDIR = ./obj
#INCDIR = ./src
#BINDIR = ./bin
#OBJ = $(wildcard $(SRCDIR)/*.o)
#SRC = $(wildcard $(SRCDIR)/*.c)
#INC = $(wildcard $(INCDIR)/*.h)
#CC = gcc
#CFLAGS = -lm

fatec: main.o menu.o aulas.o Trab02.o basic_math.o clear_buffer.o developers.o
	gcc -o fatec main.o menu.o aulas.o Trab02.o basic_math.o clear_buffer.o developers.o -lm
main.o: main.c fatec.h
	gcc -c main.c
menu.o: menu.c fatec.h
	gcc -c menu.c
aulas.o: aulas.c fatec.h
	gcc -c aulas.c
Trab02.o: Trab02.c fatec.h
	gcc -c Trab02.c
basic_math.o: basic_math.c fatec.h
	gcc -c basic_math.c
clear_buffer.o: clear_buffer.c fatec.h
	gcc -c clear_buffer.c
developers.o: developers.c fatec.h
	gcc -c developers.c
#install:
#	cp fatec.h /usr/include/
clean:
	rm -f *.o
realclean: clean
	rm -f fatec

#$(TARGET): $(OBJ)
#	gcc -o fatec $(wildcard ./obj/*.o) -lm
#	$(CC) -o $(BINDIR)/$(TARGET) $(OBJ) $(CFLAGS)
#main.o: $(SRCDIR)/main.c $(INCDIR)/fatec.h
#	$(CC) -c main.c
#menu.o: $(SRCDIR)/menu.c $(INCDIR)/fatec.h
#	$(CC) -c menu.c
#aulas.o: $(SRCDIR)/aulas.c $(INCDIR)/fatec.h
#	$(CC) -c aulas.c
#Trab02.o: $(SRCDIR)/Trab02.c $(INCDIR)/fatec.h
#	$(CC) -c Trab02.c
#clear_buffer.o: $(SRCDIR)/clear_buffer.c $(INCDIR)/fatec.h
#	$(CC) -c clear_buffer.c
#developers.o: $(SRCDIR)/developers.c $(INCDIR)/fatec.h
#	$(CC) -c developers.c
#clean:
#	rm -f $(OBJ)
#realclean: clean
#	rm -f $(TARGET)
