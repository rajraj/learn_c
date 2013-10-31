#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int age;
  int height;
  int weight;
} Person;

struct Person *Person_create(char *name, int age, int height, int weight)
{
  struct Person *person = malloc(sizeof(struct Person));
  assert(person != NULL);
  
  person.name = strdup(name);
  person.age = age;
  person.height = height;
  person.weight = weight;
  
  return person;
}

void Person_print(struct Person *person)
{
  printf("The memory location is at %p\n", person);
  printf("\tName: %s\n", person->name);
  printf("\tage: %d\n", person->age);
  printf("\theight: %d\n", person->height);
  printf("\tweight: %d\n", person->weight);
}

int main(int argc, char *argv[])
{
  struct Person *rajesh = Person_create("Rajesh", 34, 178, 1);
  Person_print(rajesh);
  return 0;	
}