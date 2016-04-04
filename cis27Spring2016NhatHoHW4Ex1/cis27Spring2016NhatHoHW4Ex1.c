/**
 * Program Name: cis27Spring2016NhatHoHW4Ex1.c
 * Discussion:   HW 4 - Excercise #1
 * Written by:   Nhat Ho
 * Due Date:     2015/04/05
 */
#include <stdio.h>
#include <stdlib.h>

struct FractionNhatH {
	int num;
	int denom;
};

struct PolyTermNhatH {
	int exp;
	struct FractionNhatH* coePtr;
};

struct PolyNodeNhatH {
	struct PolyTermNhatH* ptPtr;
	struct PolyNodeNhatH* next;
};

typedef struct FractionNhatH FractionNhat;
typedef struct PolyTermNhatH PolyTermNhat;
typedef struct PolyNodeNhatH PolyNodeNhat;
typedef FractionNhat* FractionPtrNhat;
typedef PolyNodeNhat* PolyListNhat;
typedef PolyListNhat* PolyListPtrNhat;

PolyNodeNhat* createPolyNodeNhatH(void);
PolyNodeNhat* createPolyNode02NhatH(FractionNhat*, int);
PolyTermNhat* createPolyTermNhatH(void);
PolyTermNhat* createPolyTerm02NhatH(FractionNhat*, int);
PolyListNhat* addPolyNhatH(PolyListNhat, PolyListNhat);
PolyListNhat* multiplyPolyNhatH(PolyListNhat, PolyListNhat);
PolyListNhat combineLikeTermsNhatH(PolyListNhat);
int insertPolyNodeNhatH(PolyListNhat*, PolyNodeNhat*);
int removePolyNodeNhatH(PolyListNhat*, int);
int isEmptyNhatH(PolyListNhat*);
int getLengthNhatH(PolyListNhat);
int createExponentNhatH(void);
int getGCDNhatH(int, int);
void removeFirstPolyNodeNhatH(PolyListNhat*);
void removeLastPolyNodeNhatH(PolyListNhat*);
void displayPolyListNhatH(PolyListNhat);
void sortByDegreeNhatH(PolyListNhat);
void reduceNhatH(FractionNhat*);
void freePolyNodeNhatH(PolyNodeNhat*);
void freePolyListNhatH(PolyListNhat*);
FractionNhat* createFractionNhatH(void);
FractionNhat* addFractionNhatHo(FractionNhat*, FractionNhat*);
FractionNhat* multiplyFractionNhatHo(FractionNhat*, FractionNhat*);
void menu01NhatH();
void creationMenuNhatH(PolyListNhat*, PolyListNhat*);
void deletionMenuNhatH(PolyListNhat*, PolyListNhat*, PolyListNhat*);
void displayClassInfoNhatH(void);

int main() {
	displayClassInfoNhatH();
	menu01NhatH();

	return 0;
}

void displayClassInfoNhatH() {
	printf("CIS 27 - C Programming\n"
		"Laney College\n"
		"Nhat Ho\n"
		"\nAssignment Information --\n"
		"  Assignment Number:  Homework 04,\n"
		"\t\t      Coding Assignment -- Exercise #1\n"
		"  Written by: \t      Nhat Ho\n"
		"  Submitted Date:     2015/04/05\n\n");

	return;
}

void menu01NhatH() {
	PolyListNhat* result = (PolyListNhat*)calloc(1, sizeof(PolyListNhat));
	PolyListNhat poly1 = NULL;
	PolyListNhat poly2 = NULL;
	int option;

	do {
		printf(
			"******************************\n"
			"*    POLYNOMIAL OPERATIONS   *\n"
			"* 1. Creating polynomials    *\n"
			"* 2. Adding polynomials      *\n"
			"* 3. Multiplying polynomials *\n"
			"* 4. Displaying polynomials  *\n"
			"* 5. Clearing polynomials    *\n"
			"* 6. Quit                    *\n"
			"******************************\n"
			"Select the option(1 through 6): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			printf(
				"\n  My logic for the creation of two polynomials were to first\n  gather the number of"
				" terms the user wanted. After, I went on\n  to use a simple for loop to"
				"iterate through the number of terms,\n  allowing the user to enter in values, creating a node,"
				" and then\n  inserting each node at the end of the list. Once creation was finished,"
				"\n  I simply sorted the list so that it will be sorted in acending order\n"
				"  based on the degrees of each term in the polynomial.\n\n"
				"  Functions used:\n"
				"    createPolyNodeNhatH() - Allows the user to create a node\n"
				"    sortByDegreeNhatH() - Sorts a list in acending order\n"
				"    insertPolyNodeNhatH() - To insert a node to the end of the list\n");
			creationMenuNhatH(&poly1, &poly2);
			break;
		case 2:
			printf(
				"\n  My logic for the addition of the polynomial were to first\n  sort each list in acending order"
				" based on their degrees. \n  To accomplish this, I created a function called sortByDegree(),\n"
				"  using a modified bubble sort, I traversed the list comparing\n  each term to the next term,"
				" and swapping these terms if one\n  exponent was greater than the other. I then sent both lists\n"
				"  into addPoly(), which uses a nested while loop to traverse\n  the list, making comparisons"
				" on each exponent. Once a condition\n  was met, I created a new node, and inserted it into"
				" the resulting list.\n  I repeated this same process until both lists were exhaused.\n\n"

				"  Functions used:\n"
				"    addFractionNhatHo() - Adds two coefficients of Fractions\n"
				"    sortByDegreeNhatH() - Sorts a list in acending order\n"
				"    createPolyNode02NhatH() - To create a new polynode with two arguments\n"
				"    insertPolyNodeNhatH() - To insert a node to the end of the list\n"
				"    addPolyNhatH() - Adds two polylists and returns the address\n");
			if (poly1 && poly2 != NULL) {
				if (result != NULL) {
					freePolyListNhatH(result);
				}
				result = addPolyNhatH(poly1, poly2);
				printf("\n  Left Poly Pointer: %p\n    ", poly1);
				displayPolyListNhatH(poly1);
				printf("\n  Right Poly Pointer %p\n    ", poly2);
				displayPolyListNhatH(poly2);
				printf("\n  Resulting Poly Pointer: %p\n    ", *result);
				displayPolyListNhatH(*result);
				printf("\n\n");
			} else {
				printf("\n  Please create BOTH Polynomials first!\n\n");
			}
			break;
		case 3:
			printf(
				"\n  My logic for the multiplication of polynomials were to first\n  sort"
				" both lists. After the lists were sorted, I used a nested\n  while"
				" loop to traverse both lists, multiplying each term,\n  creating a new"
				" node, and inserting the newly created node into\n  the end of the"
				" resulting list. I did this until both lists were\n  exhausted. This left me"
				" with a resulting polynomial that still\n  included like terms. I then created"
				"a function called combineLikeTerms,\n  which traverses the resulting list,"
				" checking if each terms' exponents\n  were the same, and adding them together if they were."
				" I went on to\n  sort the resulting polynomial and then returning the address.\n\n"
				"  Functions used:\n"
				"    multiplyFractionNhatHo() - Multiply two coeffients of Fractions\n"
				"    addFractionNhatHo() - Adds two coefficients of Fractions\n"
				"    sortByDegreeNhatH() - Sorts a list in acending order\n"
				"    createNode02NhatH() - To create a new polynode with two arguments\n"
				"    insertPolyNodeNhatH() - To insert a node to the end of the list\n"
				"    combineLikeTermsNhatH() - Traverses a list to combine the like terms\n"
				"    multiplyPolyNhatH() - Multiplys two polylists and returns the address\n");
			if (poly1 && poly2 != NULL) {
				if (result != NULL) {
					freePolyListNhatH(result);
				}
				result = multiplyPolyNhatH(poly1, poly2);
				printf("\n  Left Poly Pointer: %p\n    ", poly1);
				displayPolyListNhatH(poly1);
				printf("\n  Right Poly Pointer %p\n    ", poly2);
				displayPolyListNhatH(poly2);
				printf("\n  Resulting Poly Pointer: %p\n    ", *result);
				displayPolyListNhatH(*result);
				printf("\n\n");
			} else {
				printf("\n  Please create BOTH Polynomials first!\n\n");
			}
			break;
		case 4:
			printf("\n  Left Poly Pointer: %p\n    ", poly1);
			displayPolyListNhatH(poly1);
			printf("\n  Right Poly Pointer: %p\n    ", poly2);
			displayPolyListNhatH(poly2);
			printf("\n  Resulting Poly Pointer: %p\n    ", *result);
			displayPolyListNhatH(*result);
			printf("\n\n");
			break;
		case 5:
			deletionMenuNhatH(&poly1, &poly2, result);
			break;
		case 6:
			printf("\n  Having Fun!\n\n");
			break;
		default:
			printf("\n  You should not be in this class!\n\n");
		}
	} while (option != 6);

	freePolyListNhatH(&poly1);
	freePolyListNhatH(&poly2);
	freePolyListNhatH(result);

	return;
}

void creationMenuNhatH(PolyListNhat* poly1, PolyListNhat* poly2) {
	int option;
	int terms;

	do {
		printf("\n  ******************************\n"
			"  *    POLYNOMIAL CREATION     *\n"
			"  * 1. Create Left Polynomial  *\n"
			"  * 2. Create Right Polynomial *\n"
			"  * 3. Return to previous menu *\n"
			"  ******************************\n"
			"  Select the option(1 through 3): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			if (*poly1 != NULL)
				freePolyListNhatH(poly1);

			printf("\n    Creating Left Polynomial --\n");
			printf("      How many terms? ");
			scanf_s("%d", &terms);

			for (int i = 0; i < terms; i++) {
				printf("\n    Term #%d", i + 1);
				insertPolyNodeNhatH(poly1, createPolyNodeNhatH());
			}

			sortByDegreeNhatH(*poly1);
			printf("\n    Left-Polynomial: ");
			displayPolyListNhatH(*poly1);
			printf("\n");
			break;
		case 2:
			if (*poly2 != NULL)
				freePolyListNhatH(poly2);

			printf("\n    Creating Right Polynomial --\n");
			printf("      How many terms? ");
			scanf_s("%d", &terms);

			for (int i = 0; i < terms; i++) {
				printf("\n    Term #%d", i + 1);
				insertPolyNodeNhatH(poly2, createPolyNodeNhatH());
			}

			sortByDegreeNhatH(*poly2);
			printf("\n    Right-Polynomial: ");
			displayPolyListNhatH(*poly2);
			printf("\n");
			break;
		case 3:
			printf("\n");
			break;
		default:
			printf("\n    You should not be in this class!\n");
		}
	} while (option != 3);

	return;
}

void deletionMenuNhatH(PolyListNhat* poly1, PolyListNhat* poly2, PolyListNhat* result) {
	int option;

	do {
		printf("\n  ******************************\n"
			"  *    POLYNOMIAL DELETION     *\n"
			"  * 1. Release Left Poly       *\n"
			"  * 2. Release Right Poly      *\n"
			"  * 3. Release Resulting Poly  *\n"
			"  * 4. Return to previous menu *\n"
			"  ******************************\n"
			"  Select the option(1 through 3): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			if (*poly1 != NULL) {
				printf("\n    Releasing Left Polynomial -\n");
				freePolyListNhatH(poly1);
				printf("      Sucessfully released Right Polynomial.\n");
			} else {
				printf("\n    There are no Polynomials to release!\n");
			}
			break;
		case 2:
			if (*poly2 != NULL) {
				printf("\n    Releasing Right Polynomial -\n");
				freePolyListNhatH(poly2);
				printf("      Sucessfully released Right Polynomial.\n");
			} else {
				printf("\n    There are no Polynomials to release!\n");
			}
			break;
		case 3:
			if (*result != NULL) {
				printf("\n    Releasing Resulting Polynomial -\n");
				freePolyListNhatH(result);
				printf("      Sucessfully released Resulting Polynomial.\n");
			} else {
				printf("\n    There are no Polynomials to release!\n");
			}
			break;
		case 4:
			printf("\n");
			break;
		default:
			printf("\n    You should not be in this class!\n");
		}
	} while (option != 4);

	return;
}

PolyNodeNhat* createPolyNodeNhatH() {
	PolyNodeNhat* node;

	node = (PolyNodeNhat*)malloc(sizeof(PolyNodeNhat));
	node->ptPtr = createPolyTermNhatH();
	node->next = NULL;

	return node;
}

PolyNodeNhat* createPolyNode02NhatH(FractionNhat* coe, int exp) {
	PolyNodeNhat* node;

	node = (PolyNodeNhat*)malloc(sizeof(PolyNodeNhat));
	node->ptPtr = createPolyTerm02NhatH(coe, exp);
	node->next = NULL;

	return node;
}

PolyTermNhat* createPolyTermNhatH() {
	PolyTermNhat* term;

	term = (PolyTermNhat*)malloc(sizeof(PolyTermNhat));
	term->exp = createExponentNhatH();
	term->coePtr = createFractionNhatH();

	return term;
}

PolyTermNhat* createPolyTerm02NhatH(FractionNhat* c, int e) {
	PolyTermNhat* term;

	term = (PolyTermNhat*)malloc(sizeof(PolyTermNhat));
	term->exp = e;
	term->coePtr = c;

	return term;
}

PolyListNhat* addPolyNhatH(PolyListNhat poly1, PolyListNhat poly2) {
	PolyListNhat* result = (PolyListNhat*)calloc(1, sizeof(PolyListNhat));
	PolyListNhat tempPoly1 = poly1;
	PolyListNhat tempPoly2 = poly2;
	PolyNodeNhat* node = NULL;

	while ((tempPoly1 != NULL) && (tempPoly2 != NULL)) {
		if ((tempPoly1->ptPtr->exp) > (tempPoly2->ptPtr->exp)) {
			node = createPolyNode02NhatH(tempPoly1->ptPtr->coePtr, tempPoly1->ptPtr->exp);
			insertPolyNodeNhatH(result, node);
			tempPoly1 = tempPoly1->next;
		} else if ((tempPoly1->ptPtr->exp) < (tempPoly2->ptPtr->exp)) {
			node = createPolyNode02NhatH(tempPoly2->ptPtr->coePtr, tempPoly2->ptPtr->exp);
			insertPolyNodeNhatH(result, node);
			tempPoly2 = tempPoly2->next;
		} else {
			node = createPolyNode02NhatH(addFractionNhatHo(tempPoly1->ptPtr->coePtr, tempPoly2->ptPtr->coePtr), tempPoly2->ptPtr->exp);
			insertPolyNodeNhatH(result, node);
			tempPoly1 = tempPoly1->next;
			tempPoly2 = tempPoly2->next;
		}
	}

	if (tempPoly1 == NULL) {
		while (tempPoly2 != NULL) {
			node = createPolyNode02NhatH(tempPoly2->ptPtr->coePtr, tempPoly2->ptPtr->exp);
			insertPolyNodeNhatH(result, node);
			tempPoly2 = tempPoly2->next;
		}
	} else {
		while (tempPoly1 != NULL) {
			node = createPolyNode02NhatH(tempPoly1->ptPtr->coePtr, tempPoly1->ptPtr->exp);
			insertPolyNodeNhatH(result, node);
			tempPoly1 = tempPoly1->next;
		}
	}

	return result;

}

PolyListNhat* multiplyPolyNhatH(PolyListNhat poly1, PolyListNhat poly2) {
	PolyListNhat* result = (PolyListNhat*)calloc(1, sizeof(PolyListNhat));
	PolyListNhat tempList = poly2;
	PolyNodeNhat* tempNode = NULL;

	while (poly1 != NULL) {
		poly2 = tempList;
		while (poly2 != NULL) {
			tempNode = createPolyNode02NhatH(multiplyFractionNhatHo(poly1->ptPtr->coePtr, poly2->ptPtr->coePtr), poly1->ptPtr->exp + poly2->ptPtr->exp);
			insertPolyNodeNhatH(result, tempNode);
			poly2 = poly2->next;
		}
		poly1 = poly1->next;
	}

	*result = combineLikeTermsNhatH(*result);
	sortByDegreeNhatH(*result);

	return result;
}

PolyListNhat combineLikeTermsNhatH(PolyListNhat polyList) {
	PolyNodeNhat* temp1 = polyList;
	PolyNodeNhat* temp3;
	PolyNodeNhat* temp2;

	while (temp1 != NULL) {
		temp3 = temp1;
		temp2 = temp3->next;
		while (temp2 != NULL) {
			if (temp1->ptPtr->exp == temp2->ptPtr->exp) {
				temp1->ptPtr->coePtr = addFractionNhatHo(temp1->ptPtr->coePtr, temp2->ptPtr->coePtr);
				temp3->next = temp2->next;
			}
			temp3 = temp3->next;
			temp2 = temp3->next;
		}
		temp1 = temp1->next;
	}

	return polyList;
}

int insertPolyNodeNhatH(PolyListNhat* list, PolyNodeNhat* node) {
	PolyNodeNhat* tempNode = *list;

	if (tempNode == NULL) {
		*list = node;
	} else {
		while (tempNode->next != NULL) {
			tempNode = tempNode->next;
		}
		tempNode->next = node;
	}

	return 1;
}

int removePolyNodeNhatH(PolyListNhat* list, int n) {
	PolyNodeNhat* prev;
	PolyNodeNhat* curr;
	int count;

	if (n >= getLengthNhatH(*list)) {
		removeLastPolyNodeNhatH(list);
	} else if (n <= 1) {
		removeFirstPolyNodeNhatH(list);
	} else {
		prev = NULL;
		curr = *list;
		count = 1;
		while (count < n) {
			count++;
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		freePolyNodeNhatH(curr);
	}

	return 1;
}

int isEmptyNhatH(PolyListNhat* list) {
	return (*list) == NULL ? 1 : 0;
}

int getLengthNhatH(PolyListNhat list) {
	int length = 0;

	while (list != NULL) {
		length++;
		list = (list)->next;
	}

	return length;
}

int createExponentNhatH() {
	int exp;

	printf("\n      Enter the exponent: ");
	scanf_s("%d", &exp);

	return exp;
}

int getGCDNhatH(int num, int denom) {
	return (denom != 0) ? getGCDNhatH(denom, num % denom) : num;
}

void removeFirstPolyNodeNhatH(PolyListNhat* list) {
	PolyNodeNhat* tempNode;

	if (*list != 0) {
		tempNode = *list;
		*list = (*list)->next;
		free(tempNode->ptPtr);
		free(tempNode);
	}

	return;
}

void removeLastPolyNodeNhatH(PolyListNhat* list) {
	PolyNodeNhat* curr = *list;
	PolyNodeNhat* prev = NULL;

	if ((*list)->next == 0) {
		free((*(list))->ptPtr);
		free(*list);
		*list = NULL;
	} else {
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		free(prev->next);
		prev->next = NULL;
	}

	return;
}

void displayPolyListNhatH(PolyListNhat list) {
	if (isEmptyNhatH(&list)) {
		printf("0");
	} else {
		while ((list) != NULL) {
			if ((list)->ptPtr->exp == 0) {
				printf("%d/%d",
					(list)->ptPtr->coePtr->num,
					(list)->ptPtr->coePtr->denom);
			} else if ((list)->ptPtr->exp == 1) {
				printf("%d/%dx",
					(list)->ptPtr->coePtr->num,
					(list)->ptPtr->coePtr->denom);
			} else {
				printf("%d/%dx^%d",
					(list)->ptPtr->coePtr->num,
					(list)->ptPtr->coePtr->denom,
					(list)->ptPtr->exp);
			}
			list = (list)->next;
			if (list != NULL) {
				printf(" + ");
			}
		}
	}

	return;
}

void sortByDegreeNhatH(PolyListNhat list) {
	PolyTermNhat* tempTerm = NULL;
	PolyListNhat tempList;
	int sorted;

	if (list != NULL) {
		for (sorted = 0; sorted != 1; tempList = list) {
			sorted = 1;
			for (tempList = list; tempList->next != NULL; tempList = tempList->next) {
				if (tempList->ptPtr->exp < tempList->next->ptPtr->exp) {
					tempTerm = tempList->ptPtr;
					tempList->ptPtr = tempList->next->ptPtr;
					tempList->next->ptPtr = tempTerm;
					sorted = 0;
				}
			}
		}
	}

	return;
}

void reduceNhatH(FractionNhat* fraction) {
	int gcd;

	if (fraction->denom < 0) {
		fraction->num = -(fraction)->num;
		fraction->denom = -(fraction)->denom;
	}

	if (fraction->num == 0) {
		fraction->denom = 1;
	} else {
		gcd = getGCDNhatH(fraction->num, fraction->denom);
		if (gcd < 0) {
			gcd = -gcd;
		}
		fraction->num /= gcd;
		fraction->denom /= gcd;
	}

	return;
}

void freePolyNodeNhatH(PolyNodeNhat* node) {
	free(node->ptPtr);
	free(node);
}

void freePolyListNhatH(PolyListNhat* list) {
	PolyNodeNhat* tempNode;

	while ((*list) != NULL) {
		tempNode = *list;
		*list = (*list)->next;
		free(tempNode);
	}

	return;
}

FractionNhat* createFractionNhatH() {
	FractionNhat* fraction = NULL;
	int tmp;

	fraction = (FractionNhat*)malloc(sizeof(FractionNhat));

	printf("      Enter the numberator: ");
	scanf_s("%d", &tmp);
	fraction->num = tmp;

	printf("      Enter the denominator: ");
	scanf_s("%d", &tmp);
	fraction->denom = tmp;

	while (tmp == 0) {
		printf("      Can't set to zero! Enter a new denominator: ");
		scanf_s("%d", &tmp);
		fraction->denom = tmp;
	}

	reduceNhatH(fraction);

	return fraction;
}

FractionNhat* addFractionNhatHo(FractionNhat* leftOp, FractionNhat* rightOp) {
	FractionNhat* result = (FractionNhat*)malloc(sizeof(FractionNhat));

	(result)->num = ((leftOp)->num * (rightOp)->denom) + ((rightOp)->num * (leftOp)->denom);
	(result)->denom = (leftOp)->denom * (rightOp)->denom;
	reduceNhatH(result);

	return result;
}

FractionNhat* multiplyFractionNhatHo(FractionNhat* leftOp, FractionNhat* rightOp) {
	FractionNhat* result = (FractionNhat*)malloc(sizeof(FractionNhat));

	result->num = (leftOp)->num * (rightOp)->num;
	result->denom = (leftOp)->denom * (rightOp)->denom;
	reduceNhatH(result);

	return result;
}

/*PROGRAM OUTPUT

CIS 27 - C Programming
Laney College
Nhat Ho

Assignment Information --
  Assignment Number:  Homework 04,
                      Coding Assignment -- Exercise #1
  Written by:         Nhat Ho
  Submitted Date:     2015/04/05

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 7

  You should not be in this class!

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 4

  Left Poly Pointer: 00000000
    0
  Right Poly Pointer: 00000000
    0
  Resulting Poly Pointer: 00000000
    0

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 1

  My logic for the creation of two polynomials were to first
  gather the number of terms the user wanted. After, I went on
  to use a simple for loop toiterate through the number of terms,
  allowing the user to enter in values, creating a node, and then
  inserting each node at the end of the list. Once creation was finished,
  I simply sorted the list so that it will be sorted in acending order
  based on the degrees of each term in the polynomial.

  Functions used:
    createPolyNodeNhatH() - Allows the user to create a node
    sortByDegreeNhatH() - Sorts a list in acending order
    insertPolyNodeNhatH() - To insert a node to the end of the list

  ******************************
  *    POLYNOMIAL CREATION     *
  * 1. Create Left Polynomial  *
  * 2. Create Right Polynomial *
  * 3. Return to previous menu *
  ******************************
  Select the option(1 through 3): 1

    Creating Left Polynomial --
      How many terms? 3

    Term #1
      Enter the exponent: 2
      Enter the numberator: 1
      Enter the denominator: 1

    Term #2
      Enter the exponent: 1
      Enter the numberator: 3
      Enter the denominator: 4

    Term #3
      Enter the exponent: 0
      Enter the numberator: 5
      Enter the denominator: 12

    Left-Polynomial: 1/1x^2 + 3/4x + 5/12

  ******************************
  *    POLYNOMIAL CREATION     *
  * 1. Create Left Polynomial  *
  * 2. Create Right Polynomial *
  * 3. Return to previous menu *
  ******************************
  Select the option(1 through 3): 2

    Creating Right Polynomial --
      How many terms? 4

    Term #1
      Enter the exponent: 4
      Enter the numberator: 1
      Enter the denominator: 1

    Term #2
      Enter the exponent: 2
      Enter the numberator: -3
      Enter the denominator: 7

    Term #3
      Enter the exponent: 1
      Enter the numberator: 4
      Enter the denominator: 9

    Term #4
      Enter the exponent: 0
      Enter the numberator: 2
      Enter the denominator: 11

    Right-Polynomial: 1/1x^4 + -3/7x^2 + 4/9x + 2/11

  ******************************
  *    POLYNOMIAL CREATION     *
  * 1. Create Left Polynomial  *
  * 2. Create Right Polynomial *
  * 3. Return to previous menu *
  ******************************
  Select the option(1 through 3): 3

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 4

  Left Poly Pointer: 007125E0
    1/1x^2 + 3/4x + 5/12
  Right Poly Pointer: 007127D8
    1/1x^4 + -3/7x^2 + 4/9x + 2/11
  Resulting Poly Pointer: 00000000
    0

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 2

  My logic for the addition of the polynomial were to first
  sort each list in acending order based on their degrees.
  To accomplish this, I created a function called sortByDegree(),
  using a modified bubble sort, I traversed the list comparing
  each term to the next term, and swapping these terms if one
  exponent was greater than the other. I then sent both lists
  into addPoly(), which uses a nested while loop to traverse
  the list, making comparisons on each exponent. Once a condition
  was met, I created a new node, and inserted it into the resulting list.
  I repeated this same process until both lists were exhaused.

  Functions used:
    addFractionNhatHo() - Adds two coefficients of Fractions
    sortByDegreeNhatH() - Sorts a list in acending order
    createPolyNode02NhatH() - To create a new polynode with two arguments
    insertPolyNodeNhatH() - To insert a node to the end of the list
    addPolyNhatH() - Adds two polylists and returns the address

  Left Poly Pointer: 007125E0
    1/1x^2 + 3/4x + 5/12
  Right Poly Pointer 007127D8
    1/1x^4 + -3/7x^2 + 4/9x + 2/11
  Resulting Poly Pointer: 00712A90
    1/1x^4 + 4/7x^2 + 43/36x + 79/132

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 4

  Left Poly Pointer: 007125E0
    1/1x^2 + 3/4x + 5/12
  Right Poly Pointer: 007127D8
    1/1x^4 + -3/7x^2 + 4/9x + 2/11
  Resulting Poly Pointer: 00712A90
    1/1x^4 + 4/7x^2 + 43/36x + 79/132

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 3

  My logic for the multiplication of polynomials were to first
  sort both lists. After the lists were sorted, I used a nested
  while loop to traverse both lists, multiplying each term,
  creating a new node, and inserting the newly created node into
  the end of the resulting list. I did this until both lists were
  exhausted. This left me with a resulting polynomial that still
  included like terms. I then createda function called combineLikeTerms,
  which traverses the resulting list, checking if each terms' exponents
  were the same, and adding them together if they were. I went on to
  sort the resulting polynomial and then returning the address.

  Functions used:
    multiplyFractionNhatHo() - Multiply two coeffients of Fractions
    addFractionNhatHo() - Adds two coefficients of Fractions
    sortByDegreeNhatH() - Sorts a list in acending order
    createNode02NhatH() - To create a new polynode with two arguments
    insertPolyNodeNhatH() - To insert a node to the end of the list
    combineLikeTermsNhatH() - Traverses a list to combine the like terms
    multiplyPolyNhatH() - Multiplys two polylists and returns the address

  Left Poly Pointer: 007125E0
    1/1x^2 + 3/4x + 5/12
  Right Poly Pointer 007127D8
    1/1x^4 + -3/7x^2 + 4/9x + 2/11
  Resulting Poly Pointer: 00712BE0
    1/1x^6 + 3/4x^5 + -1/84x^4 + 31/252x^3 + 311/924x^2 + 191/594x + 5/66

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 5

  ******************************
  *    POLYNOMIAL DELETION     *
  * 1. Release Left Poly       *
  * 2. Release Right Poly      *
  * 3. Release Resulting Poly  *
  * 4. Return to previous menu *
  ******************************
  Select the option(1 through 3): 1

    Releasing Left Polynomial -
      Sucessfully released Right Polynomial.

  ******************************
  *    POLYNOMIAL DELETION     *
  * 1. Release Left Poly       *
  * 2. Release Right Poly      *
  * 3. Release Resulting Poly  *
  * 4. Return to previous menu *
  ******************************
  Select the option(1 through 3): 4

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 4

  Left Poly Pointer: 00000000
    0
  Right Poly Pointer: 007127D8
    1/1x^4 + -3/7x^2 + 4/9x + 2/11
  Resulting Poly Pointer: 00712BE0
    1/1x^6 + 3/4x^5 + -1/84x^4 + 31/252x^3 + 311/924x^2 + 191/594x + 5/66

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 5

  ******************************
  *    POLYNOMIAL DELETION     *
  * 1. Release Left Poly       *
  * 2. Release Right Poly      *
  * 3. Release Resulting Poly  *
  * 4. Return to previous menu *
  ******************************
  Select the option(1 through 3): 2

    Releasing Right Polynomial -
      Sucessfully released Right Polynomial.

  ******************************
  *    POLYNOMIAL DELETION     *
  * 1. Release Left Poly       *
  * 2. Release Right Poly      *
  * 3. Release Resulting Poly  *
  * 4. Return to previous menu *
  ******************************
  Select the option(1 through 3): 3

    Releasing Resulting Polynomial -
      Sucessfully released Resulting Polynomial.

  ******************************
  *    POLYNOMIAL DELETION     *
  * 1. Release Left Poly       *
  * 2. Release Right Poly      *
  * 3. Release Resulting Poly  *
  * 4. Return to previous menu *
  ******************************
  Select the option(1 through 3): 4

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 4

  Left Poly Pointer: 00000000
    0
  Right Poly Pointer: 00000000
    0
  Resulting Poly Pointer: 00000000
    0

******************************
*    POLYNOMIAL OPERATIONS   *
* 1. Creating polynomials    *
* 2. Adding polynomials      *
* 3. Multiplying polynomials *
* 4. Displaying polynomials  *
* 5. Clearing polynomials    *
* 6. Quit                    *
******************************
Select the option(1 through 6): 6

  Having Fun!

*/

/*PROGRAM COMMENTS

Fun! Looking forward to the Klotski project!

*/