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

TARGET = fatec
SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj
BINDIR = ./bin
SRC    = $(wildcard $(SRCDIR)/*.c)
INC    = -I $(INCDIR)
OBJ    = $(addprefix $(OBJDIR)/, main.o menu.o aulas.o Trab02.o basic_math.o clear_buffer.o developers.o)
BIN    = $(BINDIR)/$(TARGET)
RM     = rm -rf
CC     = gcc
CFLAGS = -lm

all: $(OBJDIR) $(BINDIR) $(BIN)

$(OBJDIR):
	mkdir $(OBJDIR)
$(BINDIR):
	mkdir $(BINDIR)
$(BIN): $(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(CFLAGS)
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/fatec.h
	$(CC) -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/menu.o: $(SRCDIR)/menu.c $(INCDIR)/fatec.h
	$(CC) -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/aulas.o: $(SRCDIR)/aulas.c $(INCDIR)/fatec.h
	$(CC) -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/Trab02.o: $(SRCDIR)/Trab02.c $(INCDIR)/fatec.h
	$(CC) -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/basic_math.o: $(SRCDIR)/basic_math.c $(INCDIR)/fatec.h
	$(CC) -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/clear_buffer.o: $(SRCDIR)/clear_buffer.c $(INCDIR)/fatec.h
	$(CC) -c $< $(INC) -o $@ $(CFLAGS)
$(OBJDIR)/developers.o: $(SRCDIR)/developers.c $(INCDIR)/fatec.h
	$(CC) -c $< $(INC) -o $@ $(CFLAGS)
run:
	$(BIN)
install:
	cp usr/include/fatec.h /usr/include/
uninstall:
	$(RM) /usr/include/fatec.h
clean:
	$(RM) $(OBJ)
mrproper: clean
	$(RM) $(OBJDIR)
	$(RM) $(BINDIR)
.PHONY: all run clean mrproper install uninstall
