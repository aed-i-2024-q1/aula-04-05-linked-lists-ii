build:
	mkdir -p build

element: build
	gcc -c -o build/element.o element.c

linked_list: element
	gcc -c -o build/linked_list.o linked_list.c

main: linked_list
	gcc -o build/main build/element.o build/linked_list.o main.c

run: main
	./build/main

