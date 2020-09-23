#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  puts("");
  puts("*************************************************");
  puts("*************************************************");
  puts("**   __   __   __   __         __   __   __    **");
  puts("**  |__| |__| |__  |__  | _ | |  | |__| |  \\   **");
  puts("**  |    |  |  __|  __| |/ \\| |__| |  \\ |__/   **");
  puts("**                                             **");
  puts("**  __   __        __   __   __  ___  __   __  **");
  puts("** | _  |__  |\\ | |__  |__| |__|  |  |  | |__| **");
  puts("** |__| |__  | \\| |__  |  \\ |  |  |  |__| |  \\ **");
  puts("**                                             **");
  puts("*************************************************");
  puts("*************************************************");
  puts("**                                             **");
  puts("** Options:                                    **");
  puts("**                                             **");
  puts("** 1. Single password                          **");
  puts("** 2. Multiple passwords                       **");
  puts("**                                             **");
  puts("*************************************************");
  puts("*************************************************");
  puts("");

  int op;
  scanf("%d", &op);
  while (op != 1 && op != 2) {
    puts("Not a valid option.");
    scanf("%d", &op);
  }

  puts("");
  int amount = 1;
  if (op == 2) {
    printf("Type the number of passwords: ");
    scanf("%d", &amount);
  }

  puts("");
  printf("Type the password's length: ");
  int length;
  scanf("%d", &length);

  puts("");
  puts("***************************************");
  puts("***************************************");
  puts("**                                   **");
  puts("** Character options:                **");
  puts("**                                   **");
  puts("** 1. Special characters             **");
  puts("** 2. Numbers                        **");
  puts("**                                   **");
  puts("** Sum the desired options' numbers. **");
  puts("** It's possible to choose none.     **");
  puts("**                                   **");
  puts("***************************************");
  puts("***************************************");
  puts("");

  int **ranges = malloc(3 * sizeof(int *));
  ranges[0] = malloc(2 * sizeof(int));
  ranges[1] = malloc(2 * sizeof(int));
  ranges[2] = malloc(2 * sizeof(int));
  
  int ranges_amount = 0;
  int sum;
  scanf("%d", &sum);
  while (sum < 0 && sum > 3) {
    puts("Not a valid sum.");
    scanf("%d", &sum);
  }

  switch (sum) {
    case 0:
      ranges_amount = 2;
      ranges[0][0] = 65;
      ranges[0][1] = 90;
      ranges[1][0] = 97;
      ranges[1][1] = 122;
      break;

    case 1:
      ranges_amount = 2;
      ranges[0][0] = 32;
      ranges[0][1] = 47;
      ranges[1][0] = 58;
      ranges[1][1] = 126;
      break;

    case 2:
      ranges_amount = 3;
      ranges[0][0] = 48;
      ranges[0][1] = 57;
      ranges[1][0] = 65;
      ranges[1][1] = 90;
      ranges[2][0] = 97;
      ranges[2][1] = 122;
      break;

    case 3:
      ranges_amount = 1;
      ranges[0][0] = 32;
      ranges[0][1] = 126;
      break;
  }

  puts("");
  int k = 0;
  char *characters = malloc(95);
  for (int i = 0; i < ranges_amount; i++) {
    for (int j = ranges[i][0]; j <= ranges[i][1]; j++) {
      characters[k++] = j;
    }
  }

  char *password = malloc(length + 1);
  if (op == 1)
    puts("Final password:");
  else
    puts("Final passwords:");

  for (int i = 0; i < amount; i++) {
    time_t t;
    srand((unsigned) time(&t) + i);
    for (int j = 0; j < length; j++) {
      int index = rand() % k;
      password[j] = characters[index];
    }

    password[length] = '\0';
    printf("%s\n", password);
  }
  
  puts("");
  return 0;
}
