#define _CRT_SECURE_NO_WARNINGS

#define test100 100
#define test1k 1000
#define test10k 10000
#define test100k 100000


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void fillArray(int*,int);
void exchangeSort(int *, int);
void selectionSort(int*, int);
void insertionSort(int*, int);
void bubbleSort(int[], int);
void arrayCopy(int*, int*, int);
void timeMeasure(int [],int[]);

int main() {
	//mjerenje za 100 primjera
	int array[test100] = { 0 };
	int copyArray[test100] = { 0 };
	printf("Time to sort 100 integers\n\n");
	timeMeasure(array,copyArray,test100);
	
	//mjerenje za 1k primjera
	int array1k[test1k] = { 0 };
	int copyArray2[test1k] = { 0 };
	printf("\nTime to sort 1000 integers\n\n");
	timeMeasure(array1k, copyArray2, test1k);
	
	//mjerenje za 10k primjera
	int array10k[test10k] = { 0 };
	int copyArray3[test10k] = { 0 };
	printf("\nTime to sort 10 000 integers\n\n");
	timeMeasure(array10k, copyArray3, test10k);
	
	//mjerenje za 100k primjera
	int array100k[test100k] = { 0 };
	int copyArray4[test100k] = { 0 };
	printf("\nTime to sort 100 000 integers\n\n");
	timeMeasure(array100k, copyArray4, test100k);
	
	return 0;
}
void fillArray(int* array,int N ) {
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0;i < N;i++) {
		*array = (rand() % 100);
		array++;
	}
}

void exchangeSort(int* array, int N) {
	int* i, * j;
	int tmp;
	int* end;
	end = array + N;
	for (i = array;i < end;i++) {
		for (j = i + 1;j < end;j++) {
			if (*i > * j) {
				tmp = *i;
				*i = *j;
				*j = tmp;
			}
		}
	}
}
void selectionSort(int* array, int N) {
	int* min, * end;
	int tmp;
	int* pok2;
	min = array;
	end = array + N;
	while (min != end) {
		pok2 = min + 1;
		while (pok2 != end) {
			if (*min > * pok2) {
				tmp = *min;
				*min = *pok2;
				*pok2 = tmp;
			}
			pok2++;
		}
		min++;
	}
}

void insertionSort(int* array, int N) {
	int* pok1, * pok2, * end;
	int tmp = 0;
	pok1 = array;
	pok2 = pok1 + 1;
	end = array + N;
	while (pok2 != end) {
		while (pok1 != pok2) {
			if (*pok2 < *pok1) {
				tmp = *pok1;
				*pok1 = *pok2;
				*pok2 = tmp;
			}
			pok1++;
		}
		pok1 = array;
		pok2++;
	}
}
void bubbleSort(int array[], int N) {
	int i, j;
	int tmp;
	for (i = 0;i < N - 1;i++) {
		for (j = 0;j < N - i - 1;j++) {
			if (array[j] > array[j + 1]) {
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
void arrayCopy(int *array1, int *array2, int size) {
	while (size != 0) {
		*array2 = *array1;
		array1++;array2++;size--;
	}
}
void timeMeasure(int array[],int copyArray[],int size) {
	
	clock_t start, end;
	double cpu_time_used;

	fillArray(array, size);
	
	arrayCopy(array, copyArray, size);
	start = clock();
	exchangeSort(copyArray, size);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("exchange sort: %lf sec\n",cpu_time_used);
	
	
	arrayCopy(array, copyArray, size);
	start = clock();
	selectionSort(copyArray, size);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("selection sort: %lf sec\n", cpu_time_used);
	
	
	arrayCopy(array, copyArray, size);
	start = clock();
	insertionSort(copyArray, size);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("insertion sort: %lf sec\n", cpu_time_used);
	
	arrayCopy(array, copyArray, size);
	start = clock();
	bubbleSort(copyArray, size);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Bubble sort: %lf sec\n", cpu_time_used);	
}
