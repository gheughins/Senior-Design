#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 100;
struct product {
	char name[100];
	char description[100];
	char department[100];
	double price;
	int quantity
	int date;
	int time;
};
struct product* hashArray[SIZE];
int hashCode(int key) {
	return key % SIZE;
}
struct product* search(int key) {
	//get the hash 
	int hashIndex = hashCode(key);

	//move in array until an empty 
	while (hashArray[hashIndex] != NULL) {

		if (hashArray[hashIndex]->key == key)
			return hashArray[hashIndex];

		//go to next cell
		++hashIndex;

		//wrap around the table
		hashIndex %= SIZE;
	}

	return NULL;
}


int main(int argc, char* argv[])
{

}