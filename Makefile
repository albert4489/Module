CC=clang
CFLAGS=-Wall -std=c99 -I/usr/local/include -I src
LDFLAGS=-L/usr/local/lib -lcheck -lm -lsubunit -fsanitize=address
OBJECT=lib.bin test.bin main.bin
TARGET=dist/test

$(shell mkdir -p dist)

all: test main

test: lib.bin test.bin
	$(CC) -o dist/$@ $^ $(LDFLAGS)

main: lib.bin main.bin
	$(CC) -o dist/$@ $^ -lm

lib.bin: src/lib.c
	$(CC) $(CFLAGS) -c -o $@ $<

test.bin: test/test.c
	$(CC) $(CFLAGS) -c -o $@ $<

main.bin: src/main.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
leak-check: all
	ASAN_OPTIONS=detect_leaks=1 dist/main
	ASAN_OPTIONS=detect_leaks=1 LLVM_PROFILE_FILE="dist/test.profraw" dist/test

clean:
	rm -f $(OBJECT)

doxygen:
	doxygen
