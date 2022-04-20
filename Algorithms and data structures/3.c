#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
//Push Pop
struct Lista;
typedef struct Lista* pozicija;
typedef struct Lista {
	int el;
	pozicija next;
}lista;

void menu();
void pushStack(pozicija);
pozicija stvaranjeListe();
void pop(pozicija);
void ispis(pozicija);
void pushRed(pozicija);
pozicija FindLast(pozicija);

int main() 
{
	lista stackHead = { 0 };
	lista redHead = { 0 };
	time_t t;
	int userChoice = 0;

	stackHead.next = NULL;
	redHead.next = NULL;

	srand((unsigned)time(&t));
	
	
	while (userChoice != 5)
	{
		menu();
		scanf("%d", &userChoice);
		switch (userChoice)
		{
		case 1: { pushStack(&stackHead); ispis(stackHead.next); break; }
		case 2: { pop(&stackHead); ispis(stackHead.next); break; }
		case 3: { pushRed(&redHead); ispis(redHead.next); break; }
		case 4: { pop(&redHead); ispis(redHead.next); break; }
		case 5: break;
		default:
			printf("pogresan odabir !\n");
			break;
		}
	}

	return 0;
}
void menu() {
	printf("\nDobrodosli u izbornik___izaberite opciju:\n\t1) push stack\n\t2) pop stack\n\t3) push red\n\t4) pop red\n\t5) izlaz iz programa");
	printf("\n");
	printf("\nOdabir: ");
}
void pushStack(pozicija headStack) {
	pozicija novaLista;

	novaLista = stvaranjeListe();
	novaLista->next = headStack->next;
	headStack->next = novaLista;
}
pozicija stvaranjeListe() {
	pozicija novaLista;
	
	novaLista = (pozicija)malloc(sizeof(lista));
	novaLista->el = (rand() % (91-1)+10);
	return novaLista;
}
void pop(pozicija headStack) {
	pozicija prvi;
	if (headStack->next == NULL) {
		printf("\nStack prazan!!\n\n");
		return;
	}
	else {
		prvi = headStack->next;
		headStack->next = prvi->next;
		free(prvi);
	}
}
void ispis(pozicija prvi) {
	printf("Lista: ");
	while (prvi) {
		printf("--%d", prvi->el);
		prvi = prvi->next;
	}
}
void pushRed(pozicija head)
{
	pozicija last = FindLast(head);
	pozicija newNode = stvaranjeListe();

	newNode->next = last->next;
	last->next = newNode;
}
pozicija FindLast(pozicija head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	return head;
}