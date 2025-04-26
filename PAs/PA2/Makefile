CC = g++
CFLAGS = -Iinclude -g
OBJDIR = obj
SRCDIR = src
BINDIR = bin
INCLUDEDIR = include

TARGET = $(BINDIR)/pa2.out

DIRS:
	mkdir -p $(OBJDIR) $(BINDIR)

all: DIRS $(TARGET)

${OBJDIR}/graph.o: ${INCLUDEDIR}/graph.hpp ${SRCDIR}/graph.cpp
	$(CC) $(CFLAGS) -c ${SRCDIR}/graph.cpp -I$(INCLUDEDIR) -o ${OBJDIR}/graph.o

${OBJDIR}/lista_adjacencia.o: ${INCLUDEDIR}/lista_adjacencia.hpp ${SRCDIR}/lista_adjacencia.cpp
	$(CC) $(CFLAGS) -c ${SRCDIR}/lista_adjacencia.cpp -I$(INCLUDEDIR) -o ${OBJDIR}/lista_adjacencia.o

${OBJDIR}/main.o: ${INCLUDEDIR}/lista_adjacencia.hpp ${INCLUDEDIR}/graph.hpp ${SRCDIR}/main.cpp
	$(CC) $(CFLAGS) -c ${SRCDIR}/main.cpp -I$(INCLUDEDIR) -o ${OBJDIR}/main.o

${TARGET}: ${OBJDIR}/main.o ${OBJDIR}/graph.o ${OBJDIR}/lista_adjacencia.o 
	$(CC) $(CFLAGS) ${OBJDIR}/main.o ${OBJDIR}/graph.o ${OBJDIR}/lista_adjacencia.o -o ${TARGET}

clean:
	@rm -f ${OBJDIR}/*.o
	@rm -f ${BINDIR}/*