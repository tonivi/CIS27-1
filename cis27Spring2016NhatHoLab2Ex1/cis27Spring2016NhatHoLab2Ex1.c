/**
 * Program Name: cis27Spring2016NhatHoLab2Ex1.c
 * Discussion:   Lab #2 - Excercise #1
 * Written by:   Nhat Ho
 */
#include <stdlib.h>
#include <stdio.h>

struct FractionNhatHo {
	int num;
	int denom;
};

typedef struct FractionNhatHo Fraction;

Fraction* initFractionNhatHo(int, int);
Fraction* addFractionNhatHo(Fraction**, Fraction**);
Fraction* subtractFractionNhatHo(Fraction**, Fraction**);
Fraction* multiplyFractionNhatHo(Fraction**, Fraction**);
Fraction* divideFractionNhatHo(Fraction**, Fraction**);
void reduce(Fraction**);
int getGCD(int, int);

void menu01NhatHo(void);
void displayInitMenu(Fraction**, Fraction**);
void createOperand(Fraction**, int, int);
void displayOperandInfo(Fraction**, Fraction**, Fraction**);

int main() {
	menu01NhatHo();

	return 0;
}

Fraction* initFractionNhatHo(int num, int denom) {
	Fraction* frac = (Fraction*)malloc(sizeof(Fraction));

	(frac)->num = num;
	(frac)->denom = denom;
	reduce(&frac);

	return frac;
}

Fraction* addFractionNhatHo(Fraction** leftOp, Fraction** rightOp) {
	Fraction* result = (Fraction*)malloc(sizeof(Fraction));

	(result)->num = ((*leftOp)->num * (*rightOp)->denom) + ((*rightOp)->num * (*leftOp)->denom);
	(result)->denom = (*leftOp)->denom * (*rightOp)->denom;
	reduce(&result);

	return result;
}

Fraction* subtractFractionNhatHo(Fraction** leftOp, Fraction** rightOp) {
	Fraction* result = (Fraction*)malloc(sizeof(Fraction));

	result->num = ((*leftOp)->num * (*rightOp)->denom) - ((*rightOp)->num * (*leftOp)->denom);
	result->denom = (*leftOp)->denom * (*rightOp)->denom;
	reduce(&result);

	return result;
}

Fraction* multiplyFractionNhatHo(Fraction** leftOp, Fraction** rightOp) {
	Fraction* result = (Fraction*)malloc(sizeof(Fraction));

	result->num = (*leftOp)->num * (*rightOp)->num;
	result->denom = (*leftOp)->denom * (*rightOp)->denom;
	reduce(&result);

	return result;
}

Fraction* divideFractionNhatHo(Fraction** leftOp, Fraction** rightOp) {
	Fraction* result = (Fraction*)malloc(sizeof(Fraction));

	result->num = (*leftOp)->num * (*rightOp)->denom;
	result->denom = (*leftOp)->denom * (*rightOp)->num;
	reduce(&result);

	return result;
}

void reduce(Fraction** arg) {
	int gcd;

	if ((*arg)->denom < 0) {
		((*arg)->num) = -(*arg)->num;
		((*arg)->denom) = -(*arg)->denom;
	}

	if ((*arg)->num == 0) {
		(*arg)->denom = 1;
	} else {
		gcd = getGCD((*arg)->num, (*arg)->denom);
		(*arg)->num /= gcd;
		(*arg)->denom /= gcd;
	}

	return;
}

int getGCD(int num, int denom) {
	return (denom != 0) ? getGCD(denom, num % denom) : num;
}

void menu01NhatHo() {
	Fraction* left = NULL;
	Fraction* right = NULL;
	Fraction* result = NULL;
	int option;

	do {
		printf("************************************\n"
			"*   MENU : Fraction -- Nhat Ho     *\n"
			"* 1. Creating / Updating           *\n"
			"* 2. Adding                        *\n"
			"* 3. Subtracting                   *\n"
			"* 4. Multiplying                   *\n"
			"* 5. Dividing                      *\n"
			"* 6. Displaying                    *\n"
			"* 7. Quit                          *\n"
			"************************************\n"
			"Select the option (1 through 7): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			displayInitMenu(&left, &right);
			break;
		case 2:
			if (!left || !right) {
				printf("\n  Not Allowed Yet - No Proper Data!\n\n");
			} else {
				printf("\n  Calling addFractionNhatHo() -\n");
				result = addFractionNhatHo(&left, &right);
				displayOperandInfo(&left, &right, &result);
			}
			break;
		case 3:
			if (!left || !right) {
				printf("\n  Not Allowed Yet - No Proper Data!\n\n");
			} else {
				printf("\n  Calling subtractFractionNhatHo() -\n");
				result = subtractFractionNhatHo(&left, &right);
				displayOperandInfo(&left, &right, &result);
			}
			break;
		case 4:
			if (!left || !right) {
				printf("\n  Not Allowed Yet - No Proper Data!\n\n");
			} else {
				printf("\n  Calling multiplyFractionNhatHo() -\n");
				result = multiplyFractionNhatHo(&left, &right);
				displayOperandInfo(&left, &right, &result);
			}
			break;
		case 5:
			if (!left || !right) {
				printf("\n  Not Allowed Yet - No Proper Data!\n\n");
			} else {
				printf("\n  Calling divideFractionNhatHo() -\n");
				result = divideFractionNhatHo(&left, &right);
				displayOperandInfo(&left, &right, &result);
			}
			break;
		case 6:
			printf("\n  Left Operand:");
			if (!left) {
				printf("\n    Address/Location: NULL\n");
			} else {
				printf("\n    Address/Location: %p", &left);
				printf("\n    Numerator: %d", left->num);
				printf("\n    Denominator: %d\n", left->denom);
			}

			printf("\n  Right Operand:");
			if (!right) {
				printf("\n    Address/Location: NULL");
			} else {
				printf("\n    Address/Location: %p", &right);
				printf("\n    Numerator: %d", right->num);
				printf("\n    Denominator: %d", right->denom);
			}
			printf("\n\n");
			break;
		case 7:
			printf("\n  Feel Nice!\n\n");
			break;
		default:
			printf("\n  UH!\n\n");
		}
	} while (option != 7);

	free(left);
	free(right);
	free(result);

	return;
}

void displayInitMenu(Fraction** left, Fraction** right) {
	int num = 0;
	int denom = 0;
	int option;

	do {
		printf(
			"\n     **********************************\n"
			"     * MENU : Creating / Updating     *\n"
			"     * 1. Left Operand                *\n"
			"     * 2. Right Operand               *\n"
			"     * 3. Both Operand                *\n"
			"     * 4. Displaying Current Operands *\n"
			"     * 5. Return                      *\n"
			"     **********************************\n"
			"     Select the option (1 through 5): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			if (*left == NULL) {
				printf("\n       Creating the left-operand -\n\n");
				createOperand(left, num, denom);
			} else {
				printf("\n       Updating the left-operand -\n\n");
				createOperand(left, num, denom);
			}
			printf("\n       Left Operand:");
			printf("\n         Address/Location: %p", &left);
			printf("\n         Numerator: %d", (*left)->num);
			printf("\n         Denominator: %d\n", (*left)->denom);
			break;
		case 2:
			if (*right == NULL) {
				printf("\n       Creating the right-operand -\n\n");
				createOperand(right, num, denom);
			} else {
				printf("\n       Updating the right-operand -\n\n");
				createOperand(right, num, denom);
			}
			printf("\n       Right Operand:");
			printf("\n         Address/Location: %p", &right);
			printf("\n         Numerator: %d", (*right)->num);
			printf("\n         Denominator: %d\n", (*right)->denom);
			break;
		case 3:
			if (*left == NULL) {
				printf("\n       Creating the left-operand -\n\n");
				createOperand(left, num, denom);
			} else {
				printf("\n       Updating the left-operand -\n\n");
				createOperand(left, num, denom);
			}

			if (*right == NULL) {
				printf("\n       Creating the right-operand -\n\n");
				createOperand(right, num, denom);
			} else {
				printf("\n       Updating the right-operand -\n\n");
				createOperand(right, num, denom);
			}
			printf("\n       Left Operand:");
			printf("\n         Address/Location: %p", &left);
			printf("\n         Numerator: %d", (*left)->num);
			printf("\n         Denominator: %d\n", (*left)->denom);
			printf("\n       Right Operand:");
			printf("\n         Address/Location: %p", &right);
			printf("\n         Numerator: %d", (*right)->num);
			printf("\n         Denominator: %d\n", (*right)->denom);
			break;
		case 4:
			printf("\n       Left Operand:");
			if (*left == NULL) {
				printf("\n         Address/Location: NULL\n");
			} else {
				printf("\n         Address/Location: %p", &left);
				printf("\n         Numerator: %d", (*left)->num);
				printf("\n         Denominator: %d\n", (*left)->denom);
			}
			printf("\n       Right Operand:");
			if (*right == NULL) {
				printf("\n         Address/Location: NULL\n");
			} else {
				printf("\n         Address/Location: %p", &right);
				printf("\n         Numerator: %d", (*right)->num);
				printf("\n         Denominator: %d\n", (*right)->denom);
			}
			break;
		case 5:
			printf("\n");
			break;
		default:
			printf("\n       UH!\n");
		}
	} while (option != 5);

	return;
}

void displayOperandInfo(Fraction** left, Fraction** right,
						Fraction** result) {
	printf("\n    Left Operand:");
	printf("\n      Address/Location: %p", &left);
	printf("\n      Numerator: %d", (*left)->num);
	printf("\n      Denominator: %d", (*left)->denom);

	printf("\n\n    Right Operand:");
	printf("\n      Address/Location: %p", &right);
	printf("\n      Numerator: %d", (*right)->num);
	printf("\n      Denominator: %d", (*right)->denom);

	printf("\n\n    Result:");
	printf("\n      Address/Location: %p", &result);
	printf("\n      Numerator: %d", (*result)->num);
	printf("\n      Denominator: %d", (*result)->denom);
	printf("\n\n  (%d/%d - %d/%d = %d/%d)\n\n", (*left)->num,
		(*left)->denom, (*right)->num, (*right)->denom,
		(*result)->num, (*result)->denom);
}

void createOperand(Fraction** frac, int num, int denom) {
	printf("         Enter the numerator: ");
	scanf_s("%d", &num);
	printf("         Enter the denominator: ");
	scanf_s("%d", &denom);
	
	while (denom == 0) {
		printf("\n    Denom can't be zero! Enter another denominator: ");
		scanf_s("%d", &denom);
	}

	if (*frac == NULL) {
		*frac = initFractionNhatHo(num, denom);
	} else {
		(*frac)->num = num;
		(*frac)->denom = denom;
		reduce(frac);
	}

	return;
}

/*PROGRAM OUTPUT

CIS 27 - C Programming
Laney College
Nhat Ho

Assignment Information --
  Assignment Number:  Lab 02,
                      Coding Assignment -- Exercise
  Written by:         Nhat Ho
  Submitted Date:     2016/02/25

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 9

  UH!

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 2

  Not Allowed Yet - No Proper Data!

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 3

  Not Allowed Yet - No Proper Data!

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 6

  Left Operand:
    Address/Location: NULL

  Right Operand:
    Address/Location: NULL

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 1

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 4

       Left Operand:
         Address/Location: NULL

       Right Operand:
         Address/Location: NULL

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 1

       Creating the left-operand -

         Enter the numerator: 3
         Enter the denominator: 4

       Left Operand:
         Address/Location: 001CF9F8
         Numerator: 3
         Denominator: 4

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 4

       Left Operand:
         Address/Location: 001CF9F8
         Numerator: 3
         Denominator: 4

       Right Operand:
         Address/Location: NULL

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 5

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 2

  Not Allowed Yet - No Proper Data!

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 6

  Left Operand:
    Address/Location: 001CFAF8
    Numerator: 3
    Denominator: 4

  Right Operand:
    Address/Location: NULL

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 1

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 4

       Left Operand:
         Address/Location: 001CF9F8
         Numerator: 3
         Denominator: 4

       Right Operand:
         Address/Location: NULL

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 2

       Creating the right-operand -

         Enter the numerator: 5
         Enter the denominator: 12

       Right Operand:
         Address/Location: 001CF9FC
         Numerator: 5
         Denominator: 12

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 4

       Left Operand:
         Address/Location: 001CF9F8
         Numerator: 3
         Denominator: 4

       Right Operand:
         Address/Location: 001CF9FC
         Numerator: 5
         Denominator: 12

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 5

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 6

  Left Operand:
    Address/Location: 001CFAF8
    Numerator: 3
    Denominator: 4

  Right Operand:
    Address/Location: 001CFAEC
    Numerator: 5
    Denominator: 12

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 2

  Calling addFractionNhatHo() -

    Left Operand:
      Address/Location: 001CFAF8
      Numerator: 3
      Denominator: 4

    Right Operand:
      Address/Location: 001CFAEC
      Numerator: 5
      Denominator: 12

    Result:
      Address/Location: 001CFAE0
      Numerator: 7
      Denominator: 6

  (3/4 + 5/12 = 7/6)

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 1

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 3

       Updating the left-operand -

         Enter the numerator: -3
         Enter the denominator: 7

       Updating the right-operand -

         Enter the numerator: 4
         Enter the denominator: 9

       Left Operand:
         Address/Location: 001CF9F8
         Numerator: -3
         Denominator: 7

       Right Operand:
         Address/Location: 001CF9FC
         Numerator: 4
         Denominator: 9

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 5

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 3

  Calling subtractFractionNhatHo() -

    Left Operand:
      Address/Location: 001CFAF8
      Numerator: -3
      Denominator: 7

    Right Operand:
      Address/Location: 001CFAEC
      Numerator: 4
      Denominator: 9

    Result:
      Address/Location: 001CFAE0
      Numerator: -55
      Denominator: 63

  (-3/7 - 4/9 = -55/63)

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 1

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 3

       Updating the left-operand -

         Enter the numerator: 2
         Enter the denominator: 11

       Updating the right-operand -

         Enter the numerator: 5
         Enter the denominator: 101

       Left Operand:
         Address/Location: 001CF9F8
         Numerator: 2
         Denominator: 11

       Right Operand:
         Address/Location: 001CF9FC
         Numerator: 5
         Denominator: 101

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 5

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 4

  Calling multiplyFractionNhatHo() -

    Left Operand:
      Address/Location: 001CFAF8
      Numerator: 2
      Denominator: 11

    Right Operand:
      Address/Location: 001CFAEC
      Numerator: 5
      Denominator: 101

    Result:
      Address/Location: 001CFAE0
      Numerator: 10
      Denominator: 1111

  (2/11 * 5/101 = 10/1111)

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 1

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 3

       Updating the left-operand -

         Enter the numerator: 6
         Enter the denominator: 17

       Updating the right-operand -

         Enter the numerator: -8
         Enter the denominator: 15

       Left Operand:
         Address/Location: 001CF9F8
         Numerator: 6
         Denominator: 17

       Right Operand:
         Address/Location: 001CF9FC
         Numerator: -8
         Denominator: 15

     **********************************
     * MENU : Creating / Updating     *
     * 1. Left Operand                *
     * 2. Right Operand               *
     * 3. Both Operand                *
     * 4. Displaying Current Operands *
     * 5. Return                      *
     **********************************
     Select the option (1 through 5): 5

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 5

  Calling divideFractionNhatHo() -

    Left Operand:
      Address/Location: 001CFAF8
      Numerator: 6
      Denominator: 17

    Right Operand:
      Address/Location: 001CFAEC
      Numerator: -8
      Denominator: 15

    Result:
      Address/Location: 001CFAE0
      Numerator: -45
      Denominator: 68

  (6/17 / -8/15 = -45/68)

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 6

  Left Operand:
    Address/Location: 001CFAF8
    Numerator: 6
    Denominator: 17

  Right Operand:
    Address/Location: 001CFAEC
    Numerator: -8
    Denominator: 15

************************************
*   MENU : Fraction -- Nhat Ho     *
* 1. Creating / Updating           *
* 2. Adding                        *
* 3. Subtracting                   *
* 4. Multiplying                   *
* 5. Dividing                      *
* 6. Displaying                    *
* 7. Quit                          *
************************************
Select the option (1 through 7): 7

  Feel Nice!

*/

/*PROGRAM COMMENTS

I ran into some problems with the
data not being updated during user input
and realized I had to set up arguments
so that it accepted a pointer to a pointer
and calling the function by passing the
address.

Overall, fun and easy lab. I can't wait to
learn about linked lists and binary search
trees.

*/