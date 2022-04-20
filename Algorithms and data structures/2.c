#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define fileName1 "Lista1.txt"
#define fileName2 "Lista2.txt"
//Union and intersection
struct Lista;
typedef struct Lista* pozicija;
typedef struct Lista {
	int el;
	pozicija next;
}lista;

int ucitavanjeDatoteke(pozicija ,char *);
void prvaLista(pozicija,int);
void ispisListe(pozicija);
void unionIntersection(pozicija,pozicija,pozicija,pozicija);
pozicija stvaranjeListe(int);
void sortiranjeListe(pozicija);
void intersection(pozicija, int);

int main(int argc,char *argv[])
{
	
	lista head1 = { 0 };
	lista head2 = { 0 };
	lista unionHead = { 0 };
	lista intersectionHead = { 0 };

	head1.next = NULL;
	head2.next = NULL;
	unionHead.next = NULL;
	intersectionHead.next = NULL;
	
	ucitavanjeDatoteke(&head1,fileName1);
	ucitavanjeDatoteke(&head2, fileName2);
	unionIntersection(head1.next, head2.next, &unionHead,&intersectionHead);
	
	return 0;
}
int ucitavanjeDatoteke(pozicija head1,char *fileName) {

	FILE *f1;
	int tmp = 0;
	f1 = NULL;
	f1 = fopen(fileName, "r");
	if (f1 == NULL) {
		printf("Greška u otvaranju datoteke\n");
		return -1;
	}
	while(!feof(f1))
	{
		fscanf(f1,"%d",&tmp);
		prvaLista(head1, tmp);
	}

}
void prvaLista(pozicija head1, int el)
{
	pozicija novaLista;
	novaLista = stvaranjeListe(el);
	
	while (head1->next) {
		head1 = head1->next;
	}
	novaLista->next = head1->next;
	head1->next = novaLista;
}
void ispisListe(pozicija prvi) {
	while (prvi) {
		printf(" %d\t", prvi->el);
		prvi = prvi->next;
	}
	printf("\n");
}
void unionIntersection(pozicija prvi_lista1, pozicija prvi_lista2, pozicija head,pozicija head2) {
	pozicija lista;
	pozicija prvi;
	int cnt = 0;
	while (prvi_lista1) {
		lista = stvaranjeListe(prvi_lista1->el);
		
		lista->next = head->next;
		head->next = lista;

		prvi_lista1 = prvi_lista1->next;
	}
	prvi = head->next;
	
	while (prvi_lista2) {
		while (prvi != NULL) {
			if (prvi->el == prvi_lista2->el) {
				cnt++;
			}
			prvi = prvi->next;
		}
		if (cnt == 0) {
			lista = stvaranjeListe(prvi_lista2->el);

			lista->next = head->next;
			head->next = lista;
		}
		if (cnt > 0) {
			intersection(head2, prvi_lista2->el);
		}
		prvi = head->next;
		prvi_lista2 = prvi_lista2->next;
		cnt = 0;
	}
	sortiranjeListe(head);
	printf("Union lista:");
	ispisListe(head->next);
	printf("\n");
	printf("\nIntersection lista:");
	ispisListe(head2->next);
	
}
pozicija stvaranjeListe(int el) {
	pozicija lista;
	lista=(pozicija)malloc(sizeof(lista));
	lista->el = el;
	
	return lista;
}
void sortiranjeListe(pozicija head) {
	pozicija trenutni, p, kraj, tmp;
	kraj = tmp = p = trenutni = NULL;

	while (head->next != kraj) {

		trenutni = head->next;
		p = head;
		while (trenutni->next != kraj)
		{
			if ((trenutni->el>trenutni->next->el) ) {
				tmp = trenutni->next;
				trenutni->next = tmp->next;
				tmp->next = trenutni;
				p->next = tmp;

				trenutni = tmp;
			}
			p = trenutni;
			trenutni = trenutni->next;
		}
		kraj = trenutni;
	}
}
void intersection(pozicija head, int el) {
	pozicija lista;
	lista = stvaranjeListe(el);

	lista->next = head->next;
	head->next = lista;
	sortiranjeListe(head);

}