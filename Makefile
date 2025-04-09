all: 
	gcc *.c -Wall -Wextra -Werror -g -o string.out

test:
	for i in test*.c; do gcc String.c $$i -Wall -Wextra -Werror -g -o $$i.out; done
	for i in test*.c; do echo "\nTesting $$i\n"; ./$$i.out; done

grind:
	for i in test*.c; do gcc String.c $$i -Wall -Wextra -Werror -g -o $$i.out; done
	for i in test*.c; do echo "\n -> Valgrinding $$i\n"; valgrind --leak-check=full -s ./$$i.out 2> $$i.valgrind.report; echo "\n -> Put Valgrind Report in '$$i.valgrind.report'\n\n----------"; done