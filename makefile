CC=g++
CFLAGS=
LDFLAGS=
EXEC=donjon

all: $(EXEC)

donjon: donj.o salle.o levelmap.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o core
