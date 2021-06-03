#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct product {
	char name[100];
	char description[100];
	char department[100];
	double price;
	int quantity;
	int date;
	int time;
	int key;
};

int hashCode(char * str, int size) {
	int key;
	int p = 1;
	for (int i = strlen(str); i > 0 ; i--) {
		key = (str[i] - 'a') * p;
			p *= 10;
	}
	return key % size;
}
struct product* search(char* key, int size, struct product** hashArray) {
	//get the hash 

	int hashIndex = hashCode(key, size);

	//move in array until an empty 
	while (hashArray[hashIndex] != NULL) {

		if (hashArray[hashIndex]->key == hashIndex)
			return hashArray[hashIndex];

		//go to next cell
		++hashIndex;

		//wrap around the table
		hashIndex %= size;
	}

	return NULL;
}


int main(int argc, char* argv[])
{
	struct product hashArray[100];
	FILE* fptr;
	printf("%s\n", argv[1]);
	if ((fptr = fopen(argv[1], "r")) == NULL) {
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	for (int i = 0; i < 150; i++) {
		char temp[1000];
		fgets(temp, 1000, fptr);
		printf("%s\n", temp);
		if (temp[0]!=';') {
			struct product item;

		}
	}
}