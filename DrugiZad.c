#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _Person;
typedef struct _Person

Position findLast(Position head) {
	Position current = head;

	while (current->next != NULL) {
		current = current->next;
	}
	return current; //
}

int addToEndOfTheList(Position head) {

	Position newPerson = NULL;
	Position last = NULL;

	newPerson = createPerson();

	if (newPerson) {
		last = findLast(head);				//nemoj zaminit ove dvi linije koda bi stvoria loop
		newPerson->next = newPerson;		// u kojem element ima pokaziva? na samog sebe
	}

	return EXIT_SUCCESS;

}
int printList(Position firstElement) {
	Position current = firstElement;
	if (!firstElement)
	{
		printf("Empty list!\n");
	}
	for (; current != NUll; current = current->next)
	{
		printPerson();
	}
}
int main()
{
	Person head = {}



}
Position createPerson

int menu(Position head) {

	Position person = NULL;
	while (1) {
		printf("Enter A(Add to the front of the list), )");
		scanf°(% c, c);
	}




}