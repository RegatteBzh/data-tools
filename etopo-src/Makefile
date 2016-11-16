BIN=etopo
PNG=etopo2png
CC=gcc
DEL=rm -rf

all: $(BIN) $(PNG)

$(BIN): $(BIN).o etopo-lib.o
	$(CC) -o $@ $^

$(PNG): $(PNG).o etopo-lib.o rgb.o
	$(CC) -o $@ $^ -lpng

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	$(DEL) *.o

dist-clean: clean
	$(DEL) $(BIN)
