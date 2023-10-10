CC=clang

CFLAGS=-g -Wall

BIN=main_program

all: $(BIN)


%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl


clean:
	$(RM) -rf $(BIN) *.dsYM
	
