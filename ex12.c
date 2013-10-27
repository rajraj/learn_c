#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;
  if(argc <= 2) {
    printf("You only have one argument. You suck.\n");
  } else if(argc > 2 && argc < 4) {
    printf("Here is your arguments.\n");
    
    for(i = 0; i < argc; i++) {
      printf("Argc %d: %s.\n", i, argv[i]);
    }
    printf("\n");
  } else {
    printf("you have too many arguments.\n");
  }

  return 0;
}
