#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//Push pop with priority

	struct Lista;
	typedef struct Lista* pozicija;
	typedef struct Lista {
		int el;
		int prioritet;
		pozicija next;
	}lista;

	void menu();
	void pushStack(pozicija,const int);


	void pop(pozicija);
	void dropOldestFromStack();

	void ispis(pozicija);
	void pushRed(pozicija);
	
	pozicija stvaranjeListe();
	pozicija FindLast(pozicija);

	int main()
	{
		lista stackHead = { 0 };
		lista redHead = { 0 };
		time_t t;
		int userChoice = 0;
		int maxStackCapacity = 0;
		int currentStackCapacity = 0;
		int isStackFull = 0;

		stackHead.next = NULL;
		redHead.next = NULL;

		srand((unsigned)time(&t));
		printf("type max stack capacity__");
		scanf("%d", &maxStackCapacity);

		while (userChoice != 5)
		{
			menu();
			scanf("%d", &userChoice);
			switch (userChoice)
			{
			case 1: if(currentStackCapacity==maxStackCapacity){
				isStackFull = 1;

			}else {
				isStackFull = 0;
				++currentStackCapacity;
			} { pushStack(&stackHead, isStackFull);ispis(stackHead.next); break; }
			case 2:if (currentStackCapacity>0)
			{
				--currentStackCapacity;
			}
			{ pop(&stackHead);  break; }
			
			case 3:{ pushRed(&redHead); ispis(redHead.next); break; }
			case 4: { pop(&redHead); ispis(redHead.next); break; }
			case 5: break;
			default: printf("pogresan odabir !\n");
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
	void pushStack(pozicija headStack,int flag) {
		pozicija novaLista;

		novaLista = stvaranjeListe();
		novaLista->next = headStack->next;
		headStack->next = novaLista;
		if (flag == 1) {
			dropOldestFromStack(headStack);
		}
	}
	pozicija stvaranjeListe() {
		pozicija novaLista;

		novaLista = (pozicija)malloc(sizeof(lista));
		novaLista->el = (rand() % (90 - 0) + 10);
		
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
			printf("-%d", prvi->el);
			prvi = prvi->next;
		}
	}
	void pushRed(pozicija head)
	{
		pozicija last = FindLast(head);
		pozicija newNode = stvaranjeListe();
		newNode->prioritet = (rand() % (5 - 1) + 1);

		while (head->next != NULL && head->next->prioritet < newNode->prioritet) {
			head = head->next;
		}
		newNode->next = head->next;
		head->next=newNode;
		printf("add: %d\nprio: %d\n", newNode->el, newNode->prioritet);
	}
	pozicija FindLast(pozicija head)
	{
		while (head->next != NULL)
		{
			head = head->next;
		}
		return head;
	}

	void dropOldestFromStack(pozicija previous) {
		pozicija target = NULL;

		if (previous->next == NULL) {
			return;
		}
		while (previous->next->next != NULL) {
			previous = previous->next;
		}
		target = previous->next;
		previous->next = target->next;
		free(target);
	}
