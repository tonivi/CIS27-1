#include <stdio.h>
#include <stdlib.h>

int menu(void);

/* For adding polynomials, I free'd pointers if required,
and proceeded to call addPolyNhat which takes two lists of
polynomials and returns the pointer to a resulting polynomial. 
Inside the add() function, combine() function
is called, which combines likes terms, and then
a sort() function which sorts the exponents.*/


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
typedef PolyNodeNhat PolyListNhat;

PolyTermNhat* createTermNhat(void);
PolyNodeNhat* createNodeNhat(void);

int insertPolyNode(PolyNodeNhat**, PolyNodeNhat*);
void displayPolyList(PolyListNhat*);
FractionNhat* addFractionNhatHo(FractionNhat**, FractionNhat**);
FractionNhat* createFraction(void);
int createExponent(void);
int getGCD(int, int);
void reduce(FractionNhat**);
int getLengthNhatH(PolyNodeNhat*);
void freeNodeNhatH(PolyNodeNhat*);
void removeFirstNhatH(PolyNodeNhat**);
void removeLastNhatH(PolyNodeNhat**);
int isEmptyNhatH(PolyListNhat**);
int removePolyNode(PolyNodeNhat**, int);
PolyListNhat* addPoly(PolyListNhat**, PolyListNhat**);

void sortPoly(PolyListNhat* list);
void swap(PolyNodeNhat* n1, PolyNodeNhat* n2);
/*
PolyListPtrNhat addPolyNhatH(PolyListNhat, PolyListNhat);
PolyListPtrNhat multiplyPolyNhatH(PolyListNhat, PolyListNhat);
*/

int main() {
	PolyNodeNhat* list1 = 0;

	printf("Creating first Polynomial --\n");
	printf("How many terms? ");
	int terms;
	scanf_s("%d", &terms);

	for (int i = 0; i < terms; i++) {
		printf("\nCreating term %d\n\n", i + 1);
		insertPolyNode(&list1, createNodeNhat());
	}

	printf("\nThe Polynomial before sort: ");
	displayPolyList(list1);

	sortPoly(list1);
	printf("\nThe Polynomial after sort: ");
	displayPolyList(list1);

	

	return 0;
}

void sortPoly(PolyListNhat* list) {
	int swapped = 1;
	PolyListNhat* temp = list;

	if (list) {
		while (swapped) {
			swapped = 0;
			while (temp->next) {
				if (temp->ptPtr->exp < temp->next->ptPtr->exp) {
					swap(temp, temp->next);
					swapped = 1;
				}
				temp = temp->next;
			}
			temp = list;
		}
	}
}

void swap(PolyNodeNhat* n1, PolyNodeNhat* n2) {
	PolyTermNhat* temp;

	temp = n1->ptPtr;
	n1->ptPtr = n2->ptPtr;
	n2->ptPtr = temp;

	return;
}

FractionNhat* addFractionNhatHo(FractionNhat** leftOp, FractionNhat** rightOp) {
	FractionNhat* result = (FractionNhat*)malloc(sizeof(FractionNhat));

	(result)->num = ((*leftOp)->num * (*rightOp)->denom) + ((*rightOp)->num * (*leftOp)->denom);
	(result)->denom = (*leftOp)->denom * (*rightOp)->denom;
	reduce(&result);

	return result;
}
int isEmptyNhatH(PolyListNhat** list) {
	return (*list) == NULL ? 1 : 0;
}

void removeFirstNhatH(PolyListNhat** list) {
	PolyNodeNhat* tmpPtr;

	if (*list != 0) {
		tmpPtr = *list;
		*list = (*list)->next;
		free(tmpPtr->ptPtr);
		free(tmpPtr);
	}

	return;
}

void removeLastNhatH(PolyNodeNhat** list) {
	PolyNodeNhat* curr = *list;
	PolyNodeNhat* prev = NULL;

	if ((*list)->next == 0) {
		free((*(list))->ptPtr);
		free(*list);
		*list = NULL;
	}
	else {
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		free(prev->next);
		prev->next = NULL;
	}

	return;
}

void displayPolyList(PolyNodeNhat* list) {
	if (isEmptyNhatH(&list)) {
		printf("\n  EMPTY LIST ...\n");
	}
	else {
		while ((list) != NULL) {
			if ((list)->ptPtr->exp == 0) {
				printf("%d/%d",
					(list)->ptPtr->coePtr->num,
					(list)->ptPtr->coePtr->denom);
			}
			else if ((list)->ptPtr->exp == 1) {
				printf("%d/%dx",
					(list)->ptPtr->coePtr->num,
					(list)->ptPtr->coePtr->denom);
			}
			else {
				printf("%d/%dx^%d",
					(list)->ptPtr->coePtr->num,
					(list)->ptPtr->coePtr->denom,
					(list)->ptPtr->exp);
			}

			list = (list)->next;
			if ((list) != NULL)
				printf(" + ");
		}
	}

	return;

}

int insertPolyNode(PolyNodeNhat** list, PolyNodeNhat* node) {
	PolyNodeNhat* tmpPtr = *list;

	if (tmpPtr == 0) {
		*list = node;
	} else {
		while (tmpPtr->next != 0) {
			tmpPtr = tmpPtr->next;
		}
		tmpPtr->next = node;
	}

	return 1;
}

int removePolyNode(PolyNodeNhat** myListAddr, int n) {
	PolyNodeNhat* previous;
	PolyNodeNhat* current;
	int count;

	if (n >= getLengthNhatH(*myListAddr)) {
		removeLastNhatH(myListAddr);
	}
	else if (n <= 1) {
		removeFirstNhatH(myListAddr);
	}
	else {
		previous = NULL;
		current = *myListAddr;
		count = 1;

		while (count < n) {
			count++;
			previous = current;
			current = current->next;
		}

		previous->next = current->next;
		freeNodeNhatH(current);
	}

	return 1;
}

int getLengthNhatH(PolyNodeNhat* list) {
	int length = 0;

	while (list != NULL) {
		length++;
		list = (list)->next;
	}

	return length;
}



void freeNodeNhatH(PolyNodeNhat* node) {
	free(node->ptPtr);
	free(node);

	return;
}

PolyTermNhat* createTermNhat() {
	PolyTermNhat* term;
	
	term = (PolyTermNhat*)malloc(sizeof(PolyTermNhat));
	term->exp = createExponent();
	term->coePtr = createFraction();

	return term;
}

PolyNodeNhat* createNodeNhat() {
	PolyNodeNhat* polyNode;

	polyNode = (PolyNodeNhat*)malloc(sizeof(PolyNodeNhat));
	polyNode->ptPtr = createTermNhat();
	polyNode->next = NULL;

	return polyNode;
}

int createExponent() {
	int tmp;

	printf("Enter the exponent: ");
	scanf_s("%d", &tmp);

	return tmp;
}

FractionNhat* createFraction() {
	FractionNhat* fraction = NULL;
	int tmp;

	fraction = (FractionNhat*)malloc(sizeof(FractionNhat));

	printf("Enter the numberator: ");
	scanf_s("%d", &tmp);
	fraction->num = tmp;

	printf("Enter the denominator: ");
	scanf_s("%d", &tmp);
	fraction->denom = tmp;

	while (tmp == 0) {
		printf("Can't set to zero! Enter a new denominator: ");
		scanf_s("%d", &tmp);
		fraction->denom = tmp;
	}

	reduce(&fraction);

	return fraction;
}

int getGCD(int num, int denom) {
	return (denom != 0) ? getGCD(denom, num % denom) : num;
}

void reduce(FractionNhat** arg) {
	int gcd;

	if ((*arg)->denom < 0) {
		((*arg)->num) = -(*arg)->num;
		((*arg)->denom) = -(*arg)->denom;
	}

	if ((*arg)->num == 0) {
		(*arg)->denom = 1;
	}
	else {
		gcd = getGCD((*arg)->num, (*arg)->denom);
		if (gcd < 0) {
			gcd = -gcd;
		}
		(*arg)->num /= gcd;
		(*arg)->denom /= gcd;
	}

	return;

}
