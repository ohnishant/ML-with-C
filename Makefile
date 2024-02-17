CFLAGS=-Wall -Wextra
cc = gcc

run: single_braincell 
	./.build/single_braincell

single_braincell: single_braincell.c build
	$(cc) $(CFLAGS) -o ./.build/single_braincell single_braincell.c

build:
	mkdir -p .build

clean:
	rm -rf ./.build/single_braincell
