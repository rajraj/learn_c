#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	
	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: \t%s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n\n", who->weight);
}

int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *rajesh = Person_create(
		"Rajesh Rajappan", 34, 178,	81);
			
	struct Person *saritha = Person_create(
		"Saritha Rajesh", 32, 165,	64);
	
	struct Person *athul = Person_create(
		"Athul Rajesh", 4, 100,	17);
	
	// print them out and where they are in memory
	printf("Rajesh is at memory location %p:\n", rajesh);
	Person_print(rajesh);
	
	printf("Saritha is at memory location %p:\n", saritha);
	Person_print(saritha);
	
	printf("Athul is at memory location %p:\n", athul);
	Person_print(athul);
	
	// make everyones age 20 years and print them out agaign
	rajesh->age += 20;
	rajesh->weight += 2;
	Person_print(rajesh);
	
	saritha->age += 20;
	saritha->weight += 4;
	Person_print(saritha);
	
	athul->age +=20;
	athul->height += 80;
	athul->weight += 20;
	Person_print(athul);
	
	// destroy them all so we clean up
	Person_destroy(rajesh);
	Person_destroy(saritha);
	Person_destroy(athul);
	
	return 0;
}
