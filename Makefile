# Makefile criado por Gustavo Bacagine <gustavo.bacagine@protonmail.com>
#
# Data de criação: 25/12/2019
# Data da última modificação: 18/05/2020
#
# fatec.h é uma Biblioteca criada pelos
# alunos da FATEC de Carapicuíba do curso de ADSM.
#
# Esta biblioteca contem o prototipo das
# funções e estruturas que foram usadas no
# primeiro ano do curso
#
# Git Hub: https://github.com/Bacagine/fatec

TARGET = libfatec.so
SRCDIR = ./src
INCDIR = ./include/fatec
OBJDIR = ./obj
LIBDIR = ./lib
SRC    = $(wildcard $(SRCDIR)/*.c)
INC    = -I $(INCDIR)
OBJ    = $(addprefix $(OBJDIR)/, fatec.o str.o date.o my_math.o physics.o)
LIB    = $(LIBDIR)/$(TARGET)
RM     = rm -rf
CC     = gcc
CFLAGS = -lm

# gcc -fPIC -c fatec.c
# gcc -shared -o libfatec.so fatec.o
# Usando a flag sem instalar
# gcc -o ola ola.o -L -lfatec

all: $(OBJDIR) $(LIBDIR) $(LIB)

$(OBJDIR):
	mkdir $@
$(LIBDIR):
	mkdir $@
$(LIB): $(OBJ)
	$(CC) -shared -o $@ $< $(CFLAGS)
$(OBJDIR)/fatec.o: $(SRCDIR)/fatec.c $(INCDIR)/fatec.h
	$(CC) -fPIC -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/str.o: $(SRCDIR)/str.c $(INCDIR)/str.h
	$(CC) -fPIC -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/date.o: $(SRCDIR)/date.c $(INCDIR)/date.h
	$(CC) -fPIC -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/my_math.o: $(SRCDIR)/my_math.c $(INCDIR)/my_math.h
	$(CC) -fPIC -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/physics.o: $(SRCDIR)/physics.c $(INCDIR)/physics.h
	$(CC) -fPIC -c $< $(INC) -o $@ $(CFLAGS)
install:
	cp -r ./fatec/ /usr/include/
	cp $(LIB) /usr/lib/
uninstall:
	$(RM) /usr/include/fatec
clean:
	$(RM) $(OBJ)
mrproper: clean
	$(RM) $(OBJDIR)
	$(RM) $(LIBDIR)
.PHONY: all clean mrproper install uninstall
