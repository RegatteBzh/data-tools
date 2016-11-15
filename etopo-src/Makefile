BIN=etopo
CC=gcc
DEL=rm -rf


$(BIN): $(BIN).o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	$(DEL) *.o

dist-clean: clean
	$(DEL) $(BIN)
