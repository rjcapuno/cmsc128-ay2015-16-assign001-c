#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//num to word databse
char lib[20][20];
char lib2[10][10];

void numToWords (char x[]);
void numberDelimited (char x[], char ch, int point);

main() {
  char input[50];
  char ch;
  int point, choice, i;

  strcpy (lib[1], "one");
  strcpy (lib[2], "two");
  strcpy (lib[3], "three");
  strcpy (lib[4], "four");
  strcpy (lib[5], "five");
  strcpy (lib[6], "six");
  strcpy (lib[7], "seven");
  strcpy (lib[8], "eight");
  strcpy (lib[9], "nine");
  strcpy (lib[10], "ten");
  strcpy (lib[11], "eleven");
  strcpy (lib[12], "twelve");
  strcpy (lib[13], "thirteen");
  strcpy (lib[14], "fourteen");
  strcpy (lib[15], "fifteen");
  strcpy (lib[16], "six");
  strcpy (lib[17], "seventeen");
  strcpy (lib[18], "eighteen");
  strcpy (lib[19], "nineteen");

  strcpy (lib2[2], "twenty");
  strcpy (lib2[3], "thirty");
  strcpy (lib2[4], "forty");
  strcpy (lib2[5], "fifty");
  strcpy (lib2[6], "sixty");
  strcpy (lib2[7], "seventy");
  strcpy (lib2[8], "eighty");
  strcpy (lib2[9], "ninety");

  do{
    printf("[1] Number to Words\n");
    printf("[2] Number Delimiter\n");
    printf("[0] Exit\n");
    printf("  choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: printf("Number: ");
              scanf("%s", input);
              i = atoi(input);
              if (i > 1000000 || i < 0) {
                printf("Please enter a number from 0 to 1000000\n\n");
                break;
              }
              if (i == 0) {
                printf("Word: zero\n\n");
                break;
              }
              printf("Word: ");
              numToWords(input);
              break;

      case 2: printf("Number: ");
              scanf("%s", input);
              getchar();
              i = atoi(input);
              if (i > 1000000 || i < 0) {
                printf("Please enter a number from 0 to 1000000\n\n");
                break;
              }
              printf("Delimiter: ");
              scanf("%c", &ch);
              printf("Jumps: ");
              scanf("%d", &point);
              if (point > strlen(input)){
                printf("The number of jumps must not exceed number length\n\n");
                break;
              }
              printf("Result: ");
              numberDelimited (input, ch, point);
              break;

      case 0: printf("Goodbye!\n\n"); exit; break;

      default: printf("Invalid input\n\n");



    }
  } while (choice != 0);
}

void numToWords (char x[]) {
  int len, i, num, cnt;

  len = strlen(x);
  cnt = len;
  //loop for how long is the string
  for (i = 0; i < cnt ; i++) {
  if (len == 7) {
      num = x[i] - '0';
      len--;
      printf("%s million ", lib[num]);
    } else if (len%3 == 0) {
      num = x[i] - '0';
      if (num == 0) {len--; continue;}
      printf("%s hundred ", lib[num]);
      len--;
    } else if (len%3 == 2) {
      num = x[i] - '0';
      if (num == 0) {len--; continue;}
      if (num == 1) {
        num = x[i+1] - '0';
        num = num +10;
        printf("%s ", lib[num]);
      if (len == 5) printf("thousand ");

      len = len - 2;
      i = i + 1;
      continue;
      }
      printf("%s ", lib2[num]);
      len--;
    } else if (len == 4) {
      num = x[i] - '0';
      if (num == 0) {len--; continue;}
      printf("%s thousand ", lib[num]);
      len--;
    } else if (len == 1) {
      num = x[i] - '0';
      if (num == 0) {len--; continue;}
      printf("%s ", lib[num]);
      len--;
    }

  }
  printf("\n\n");
}

void numberDelimited(char x[], char ch, int point) {
  int len, i, cnt = 0, cnt2 = 0;
  char temp[20];

  len = strlen(x);
  for (i = len - 1; i >= 0; i--){
    if (cnt == point) {
      len = i;
      temp[cnt2] = ch;
      cnt = 0;
      (cnt2)++;
    }

    temp[cnt2] = x[i];
    cnt2++;
    cnt++;
  }

  for (i = 0; i < cnt2; i++) {
    printf("%c", temp[cnt2 - 1 -i]);
  }
  printf("\n\n");
}
