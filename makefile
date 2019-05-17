all: create test

create: list.c ll.c

	gcc list.c ll.c -o list
	
test:
	./list
	
clean:
	rm list phonebook.txt
