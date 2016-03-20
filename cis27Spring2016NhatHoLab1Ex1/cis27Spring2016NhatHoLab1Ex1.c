/**
 * Program Name: cis27Spring2016NhatHoLab1Ex1.c
 * Discussion:   Lab 1 - Excercise #1
 * Written by:   Nhat Ho
 */
#include <stdlib.h>
#include <stdio.h>
#define MAX_NUM_DIGITS 10

void displayClassInfo(void);
void menu01NhatHo(void);
int* extractUncommonDigitNhatHo(int*, int);

int main() {
	menu01NhatHo();

	return 0;
}

void menu01NhatHo() {
	int* userAry = NULL;
	int* returnedAry = NULL;
	int menuOption;
	int numOfInts;
	int i;

	do {
		printf("\n\n*********************************************\n"
			"*                     MENU                  *\n"
			"* 1. Calling extractUncommonDigitNhatHo()   *\n"
			"* 2. Quit                                   *\n"
			"*********************************************\n"
			"Select an option (1 or 2): ");
		scanf_s("%d", &menuOption);

		switch (menuOption) {
		case 1:
			printf("\n  How many integers? ");
			scanf_s("%d", &numOfInts);
			userAry = (int*)malloc(numOfInts * sizeof(int));

			for (i = 0; i < numOfInts; i++) {
				printf("    Enter integer #%d: ", i + 1);
				scanf_s("%d", &userAry[i]);
			}

			printf("\n  The original array: \n");
			for (i = 0; i < numOfInts; i++) {
				printf("    %d\n", userAry[i]);
			}

			printf("\n  Calling extractUncommonDigitNhatHo() -\n");
			returnedAry = extractUncommonDigitNhatHo(userAry, numOfInts);
			printf("\n  Displaying after returning the array"
				" -- The uncommon digits: ");

			if (*returnedAry != 0) {
				printf("\n    There is/are %d uncommon digit(s)", *(returnedAry + 0));
				for (i = 1; i < *(returnedAry + 0) + 1; i++) {
					printf("\n      %d", *(returnedAry + i));
				}
			} else {
				printf("\n   There is/are no uncommon digit(s)");
			}
			break;
		case 2:
			printf("\n  Fun Excercise ...\n\n");
			break;
		default:
			printf("\n  WRONG OPTION!");
		}
	} while (menuOption != 2);

	free(userAry);
	free(returnedAry);

	return;
}

int* extractUncommonDigitNhatHo(int* userAry, int userSize) {
	int digitCount[MAX_NUM_DIGITS] = { 0 };
	int uncommonCount = 0;
	int* assembledAry = 0;
	int** digitInfo;
	int tmp;
	int i, j;

	digitInfo = (int**)malloc(userSize * sizeof(int*));
	for (i = 0; i < userSize; i++) {
		*(digitInfo + i) = (int*)calloc(MAX_NUM_DIGITS, sizeof(int));
	}

	for (i = 0; i < userSize; i++) {
		tmp = *(userAry + i) < 0 ? -(*(userAry + i)) : *(userAry + i);

		do {
			*(*(digitInfo + i) + tmp % 10) = 1;
			tmp /= 10;
		} while (tmp != 0);
	}

	for (i = 0; i < MAX_NUM_DIGITS; i++) {
		for (j = 0; j < userSize; j++) {
			digitCount[i] += *(*(digitInfo + j) + i);
		}
		if (digitCount[i] == 1) {
			uncommonCount++;
		} 
	}

	assembledAry = (int*)malloc((uncommonCount + 1) * sizeof(int));
	*assembledAry = uncommonCount;

	if (uncommonCount != 0) {
		for (i = 0, j = 1; i < MAX_NUM_DIGITS; i+=2) {
			if (digitCount[i] == 1) {
				*(assembledAry + j) = i;
				j++;
			}
		}
		for (i = 1; i < MAX_NUM_DIGITS; i+=2) {
			if (digitCount[i] == 1) {
				*(assembledAry + j) = i;
				j++;
			}
		}
	} 

	for (i = 0; i < userSize; i++) {
		free(*(digitInfo + i));
	}
	free(digitInfo);

	return assembledAry;
}

/*PROGRAM OUTPUT

*********************************************
*                     MENU                  *
* 1. Calling extractUncommonDigitNhatHo()   *
* 2. Quit                                   *
*********************************************
Select an option (1 or 2): 3

  WRONG OPTION!

*********************************************
*                     MENU                  *
* 1. Calling extractUncommonDigitNhatHo()   *
* 2. Quit                                   *
*********************************************
Select an option (1 or 2): 1

  How many integers? 3
    Enter integer #1: 32965
    Enter integer #2: -275721
    Enter integer #3: 3028063

  The original array:
    32965
    -275721
    3028063

  Calling extractUncommonDigitNhatHo() -

  Displaying after returning the array -- The uncommon digits:
    There is/are 5 uncommon digit(s)
      0
      8
      1
      7
      9

*********************************************
*                     MENU                  *
* 1. Calling extractUncommonDigitNhatHo()   *
* 2. Quit                                   *
*********************************************
Select an option (1 or 2): 1

  How many integers? 4
    Enter integer #1: 32965
    Enter integer #2: -275721
    Enter integer #3: 3028063
    Enter integer #4: 10789

  The original array:
    32965
    -275721
    3028063
    10789

  Calling extractUncommonDigitNhatHo() -

  Displaying after returning the array -- The uncommon digits:
   There is/are no uncommon digit(s)

*********************************************
*                     MENU                  *
* 1. Calling extractUncommonDigitNhatHo()   *
* 2. Quit                                   *
*********************************************
Select an option (1 or 2): 1

  How many integers? 5
    Enter integer #1: 1001
    Enter integer #2: 2002
    Enter integer #3: 3003
    Enter integer #4: 4004
    Enter integer #5: 5555

  The original array:
    1001
    2002
    3003
    4004
    5555

  Calling extractUncommonDigitNhatHo() -

  Displaying after returning the array -- The uncommon digits:
    There is/are 5 uncommon digit(s)
      2
      4
      1
      3
      5

*********************************************
*                     MENU                  *
* 1. Calling extractUncommonDigitNhatHo()   *
* 2. Quit                                   *
*********************************************
Select an option (1 or 2): 2

  Fun Excercise ...

*/
