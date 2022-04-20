#define _CRT_SECURE_NO_WARNINGS

#define rijeci "rijeci.txt"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define n 20
/*  Napisati program koji iz datoteke čita riječi i sprema ih u v.l.tako da se svaka nova
	riječ dodaje na kraj.U v.l.ne smiji biti ponavljanja riječi(čitanje iz datoteke ne smije
	biti "case sensitive").Ispisati v.l.

	Dozvoliti da korisnik unese nekakav podstring i sve riječi kod kojih se taj podstring
	pojavljuje treba prebaciti na početak v.l.Pri tome se ne smije dodatno
	alocirati memorija već se pomiču pokazivači.Ispisati listu. - za 2
*/
typedef struct Word* position;
typedef struct Word {
	char word[n];
	position next;
}word;
position memory();
void readFromFile(position);
void addListOnEnd(head, q);
int checkforDouble(position, position);
void checkForSubString(position, char);
void changePosition(position, position);
position findPrev(position, position);
int main() {
	word head = { 0 };
	head.next = NULL;
	char search[n] = { '\0' };

	readFromFile(&head);
	printf("Input substring: ");
	scanf("%s", search);
	checkForSubString(&head, search);


	return 0;
}
void readFromFile(position head) {
	FILE* f1;
	position q;

	f1 = fopen(rijeci, "r");
	if (f1 == NULL) {
		printf("GRESKA!!!");
		return;
	}
	while (!feof(f1))
	{
		q = memory();
		fscanf(f1, "%s", q->word);
		addListOnEnd(head, q);
	}
	fclose(f1);
}
position memory() {
	position q;
	q = (position)malloc(sizeof(word));

	return q;
}
void addListOnEnd(position head, position q) {
	int check = 0;
	if (head->next == NULL) {
		q->next = head->next;
		head->next = q;
		return;
	}
	while (head->next != NULL) {

		check = checkForDouble(head, q);
		if (check == 1) {
			return;
		}
		head = head->next;
	}
	q->next = head->next;
	head->next = q;
}
int checkForDouble(position head, position q) {
	char var[n] = { '\0' };
	while (head->next) {
		if (strcmp(tolower(head->word), tolower(q->word)) == 1) {
			return 1;
		}
		head = head->next;
	}
	return 0;
}
void checkForSubString(position head, char search[]) {
	position q, z;
	z = NULL;
	q = head;
	while (q->next != NULL)
	{
		z = strstr(q->next->word, search);
		if (z != NULL) {
			changePosition(head, q->next);
		}
		q = q->next;
	}
}
void changePosition(position head, position target) {
	position p;
	p = findPrev(head, target);

	p->next = target->next;
	target->next = head->next;
	head->next = target;
}
position findPrev(position head, position target) {
	while (head->next != target)
		head = head->next;

	return head;
}