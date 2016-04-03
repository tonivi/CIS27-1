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

/* My logic approaching the addition of polynomials were to first sort each
list in acending order based on their degrees before sending it. To accomplish this,
I created a function called sortByDegree(), which sorts a list in acending order
based on the exponent in each term. Once I had both lists sorted, I sent both
list into addPoly(), which uses a nested while loop to traverse the list. While traversing,
I made comparisons on each exponent and once a condition was met, I created a new node and
inserted it into the resulting list. I repeated this process until all lists were exhausted.

Functions used:
sortByDegreeNhatH() - Sorts a list of polynomials in acending order based on their degree
insertPolyNodeNhatH - Inserts a Polynode at the end of a list
addPolyNhatH() - Adds two PolyLists and returns the address of a new list
*/

/*My logic approaching the mu*/

int main() {
	/*
	PolyListNhat list1 = 0;
	PolyListNhat list2 = 0;
	PolyListNhat* result = 0;
	int terms;

	printf("# of terms: ");
	scanf_s("%d", &terms);

	for (int i = 0; i < terms; i++) {
		insertPolyNode(&list1, createNode());
	}

	printf("# of terms: ");
	scanf_s("%d", &terms);

	for (int i = 0; i < terms; i++) {
		insertPolyNode(&list2, createNode());
	}

	
	result = addPoly(list1, list2);

	display(*result);
	freeList(&list1);
	freeList(&list2);
	freeList(result);
	printf("\n");
	return 0;
	*/

	menu01NhatH();

	return 0;
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
			creationMenuNhatH(&poly1, &poly2);
			break;
		case 2:
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
