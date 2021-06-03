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
struct product* search(int key, int size, struct product** hashArray) {
	//get the hash 

	int hashIndex = hashCode(key, size);

	//move in array until an empty 
	while (hashArray[hashIndex] != NULL) {

		if (hashArray[hashIndex]->key == key)
			return hashArray[hashIndex];

		//go to next cell
		++hashIndex;

		//wrap around the table
		hashIndex %= size;
	}

	return hashArray;
}


int main(int argc, char* argv[])
{
	struct product hashArray[100];
	FILE* fptr;
	fptr = fopen(argv[1], "r");
	char* temp;
	fscanf(fptr, "%s", &temp);
	printf("%s", temp);
}