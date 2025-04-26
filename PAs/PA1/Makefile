CC = gcc
CFLAGS = -Wall -Iinclude -g
OBJDIR = obj
SRCDIR = src
BINDIR = bin

TARGET = $(BINDIR)/pa1.out

all: $(TARGET)

${OBJDIR}/pa1.o: ${SRCDIR}/pa1.c
	$(CC) $(CFLAGS) -c ${SRCDIR}/pa1.c -o ${OBJDIR}/pa1.o

${TARGET}: ${OBJDIR}/pa1.o
	$(CC) $(CFLAGS) ${OBJDIR}/pa1.o -o ${TARGET}

clean:
	@rm -f ${OBJDIR}/*.o
	@rm -f ${BINDIR}/*