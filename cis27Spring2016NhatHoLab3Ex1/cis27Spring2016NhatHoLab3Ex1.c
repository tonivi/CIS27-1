/**
 * Program Name: cis27Spring2016NhatHoLab3Ex1.c
 * Discussion:   Lab 3 - Excercise #1
 * Written by:   Nhat Ho
 */
#include <stdio.h>
#include <stdlib.h>

struct FractionNhatHo {
	int num;
	int denom;
};

struct FractionNodeNhatHo {
	struct FractionNhatHo* data;
	struct FractionNodeNhatHo* next;
};

typedef struct FractionNhatHo FractionNhat;
typedef struct FractionNodeNhatHo FractionNodeNhat;
typedef FractionNodeNhat* FractionNodePtrNhat;
typedef FractionNodeNhat* FractionListNhat;
typedef FractionNodeNhat* FractionListPtrNhat;
typedef FractionNhat* FractionPtrNhat;

void insertFirstNhatH(FractionListPtrNhat*, FractionNodePtrNhat);
void insertAtNhatH(FractionListPtrNhat*, FractionNodePtrNhat, int);
void appendNhatH(FractionListPtrNhat*, FractionNodePtrNhat);

void removeFirstNhatH(FractionListPtrNhat*);
void removeAtNhatH(FractionListPtrNhat*, int);
void removeLastNhatH(FractionListPtrNhat*);

int isEmptyNhatH(FractionListPtrNhat*);
int getLengthNhatH(FractionListPtrNhat);
void displayListNhatH(FractionListPtrNhat);

void displayFractionLinkNhatH(FractionNodePtrNhat);
void displayNodeNhatH(FractionNodePtrNhat);

void freeNodeNhatH(FractionNodePtrNhat);
void freeListNhatH(FractionListPtrNhat*);

void menu01NhatH(void);
void insertMenuNhatH(FractionListPtrNhat*);
void removeMenuNhatH(FractionListPtrNhat*);

FractionPtrNhat createFractionNhatH(void);
FractionNodePtrNhat createNodeNhatH(void);
int getGCDNhatH(int, int);
void reduceNhatH(FractionPtrNhat*);

int main() {
	menu01NhatH();

	return 0;
}

void insertFirstNhatH(FractionListPtrNhat* list, FractionNodePtrNhat node) {
	if (*list != NULL)
		node->next = *list;
	*list = node;

	return;
}

void insertAtNhatH(FractionListPtrNhat* list, FractionNodePtrNhat node, int n) {
	FractionNodePtrNhat curr;
	int i;

	if (n <= 1) {
		insertFirstNhatH(list, node);
	} else if (n >= getLengthNhatH((*list))) {
		appendNhatH(list, node);
	} else {
		curr = *list;
		for (i = 1; i < n - 1; i++) {
			curr = curr->next;
		}
		insertFirstNhatH(&(curr->next), node);
	}

	return;
}

void appendNhatH(FractionListPtrNhat* list, FractionNodePtrNhat node) {
	FractionNodePtrNhat tmpPtr = *list;

	if (tmpPtr == 0) {
		*list = node;
	} else {
		while (tmpPtr->next != 0) {
			tmpPtr = tmpPtr->next;
		}
		tmpPtr->next = node;
	}

	return;
}

void removeFirstNhatH(FractionListPtrNhat* list) {
	FractionNodePtrNhat tmpPtr;

	if (*list != 0) {
		tmpPtr = *list;
		*list = (*list)->next;
		free(tmpPtr->data);
		free(tmpPtr);
	}

	return;
}

void removeAtNhatH(FractionListNhat* myListAddr, int n) {
	FractionNodePtrNhat previous;
	FractionNodePtrNhat current;
	int count;

	if (n >= getLengthNhatH(*myListAddr)) {
		removeLastNhatH(myListAddr);
	} else if (n <= 1) {
		removeFirstNhatH(myListAddr);
	} else {
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
}


void removeLastNhatH(FractionListPtrNhat* list) {
	FractionNodePtrNhat curr = *list;
	FractionNodePtrNhat prev = NULL;

	if ((*list)->next == 0) {
		free((*(list))->data);
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

int isEmptyNhatH(FractionListPtrNhat* list) {
	return (*list) == NULL ? 1 : 0;
}

int getLengthNhatH(FractionListPtrNhat list) {
	int length = 0;

	while (list != NULL) {
		length++;
		list = (list)->next;
	}

	return length;
}

void displayFractionLinkNhatH(FractionListPtrNhat list) {
	if (list != NULL) {
		while ((list) != NULL) {
			printf("%d/%d -> ", list->data->num, list->data->denom);
			list = (list)->next;
		}
		printf("NULL\n");
	}

	return;
}

void displayListNhatH(FractionListPtrNhat list) {
	if (isEmptyNhatH(&list)) {
		printf("\n  EMPTY LIST ...\n");
	} else {
		int count = 1;
		while ((list) != NULL) {
			printf("\n  [Index %d] -\n", count);
			displayNodeNhatH(list);
			list = (list)->next;
			count++;
		}
	}

	return;
}

void displayNodeNhatH(FractionNodePtrNhat node) {
	printf("    Address of FractionNode: %p\n", node);
	printf("    Address of Data: %p\n", node->data);
	printf("    Address of Next: %p\n", node->next);
	printf("    Numerator: %d\n", node->data->num);
	printf("    Denominator: %d\n", node->data->denom);

	return;
}

void freeNodeNhatH(FractionNodePtrNhat node) {
	free(node->data);
	free(node);

	return;
}

void freeListNhatH(FractionListPtrNhat* list) {
	FractionNodePtrNhat tmpPtr;

	while ((*list) != NULL) {
		tmpPtr = *list;
		*list = (*list)->next;
		free(tmpPtr);
	}

	return;
}

void menu01NhatH() {
	FractionListPtrNhat list = NULL;
	int option;
	
	do {
		printf("\n******************************\n"\
			"* LINKED LIST MENU: Fraction *\n"\
			"* 1. Displaying current list *\n"\
			"* 2. Inserting               *\n"\
			"* 3. Removing                *\n"\
			"* 4. Quit                    *\n"\
			"******************************\n"\
			"Select the option(1, 2, 3, or 4): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			displayListNhatH(list);
			printf("\n  ");
			displayFractionLinkNhatH(list);
			break;
		case 2:
			insertMenuNhatH(&list);
			break;
		case 3:
			removeMenuNhatH(&list);
			break;
		case 4:
			printf("\n  Fractions and Linked Lists!\n\n");
			break;
		default:
			printf("\n  You should not be in this class!\n");
		}
	} while (option != 4);

	freeListNhatH(&list);

	return;
}

void insertMenuNhatH(FractionListPtrNhat* list) {
	int option;
	int index;

	do {
		printf("\n  **********************\n"\
			"  *   Inserting Menu   *\n"\
			"  * 1. As first node   *\n"\
			"  * 2. After n-th node *\n"\
			"  * 3. As last node    *\n"\
			"  * 4. Displaying      *\n"\
			"  * 5. Quit            *\n"\
			"  **********************\n"\
			"  Select the option (1, 2, 3, or 4): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			printf("\n  Calling insertFirstNhatHo() -\n");
			insertFirstNhatH(list, createNodeNhatH());
			printf("\n  Node inserted at first position.\n\n  ");
			displayFractionLinkNhatH(*list);
			break;
		case 2:
			printf("\n  Calling insertAtNhatHo() -\n");
			printf("\n  Enter the index to insert after: ");
			scanf_s("%d", &index);
			insertAtNhatH(list, createNodeNhatH(), index + 1);
			printf("\n  Node has been inserted at the selected index.\n\n  ");
			displayFractionLinkNhatH(*list);
			break;
		case 3:
			printf("\n  Calling appendNhatHo() -\n");
			appendNhatH(list, createNodeNhatH());
			printf("\n  Node inserted at last position.\n\n  ");
			displayFractionLinkNhatH(*list);
			break;
		case 4:
			displayListNhatH(*list);
			printf("\n  ");
			displayFractionLinkNhatH(*list);
			break;
		case 5:
			break;
		default:
			printf("\n  You should not be in this class!\n");
		}
	} while (option != 5);

	return;
}

void removeMenuNhatH(FractionListPtrNhat* list) {
	int option;
	int index;

	do {
		printf("\n  *******************\n"\
			"  *  Removing Menu  *\n"\
			"  * 1. First node   *\n"\
			"  * 2. n - th node  *\n"\
			"  * 3. Last node    *\n"\
			"  * 4. Displaying   *\n"\
			"  * 5. Quit         *\n"\
			"  *******************\n"\
			"  Select the option(1, 2, 3, or 4): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			if (!isEmptyNhatH(list)) {
				printf("\n  Calling removeFirstNhatH() -\n");
				removeFirstNhatH(list);
				printf("\n  Node removed at first position.\n\n  ");
				displayFractionLinkNhatH(*list);
			} else {
				printf("\n  Can't remove from an empty list!\n");
			}
			break;
		case 2:
			if (!isEmptyNhatH(list)) {
				printf("\n  Calling removeAtNhatH() -\n");
				printf("\n  Enter the index to be removed: ");
				scanf_s("%d", &index);
				removeAtNhatH(list, index);
				printf("\n  Node removed at index %d.\n\n  ", index);
				displayFractionLinkNhatH(*list);
			} else {
				printf("\n  Can't remove from an empty list!\n");
			}
			break;
		case 3:
			if (!isEmptyNhatH(list)) {
				printf("\n  Calling removeLastNhatH() -\n");
				removeLastNhatH(list);
				printf("\n  Node removed at first position.\n\n  ");
				displayFractionLinkNhatH(*list);
			} else {
				printf("\n  Can't remove from an empty list!\n");
			}
			break;
		case 4:
			displayListNhatH(*list);
			printf("\n  ");
			displayFractionLinkNhatH(*list);
		case 5:
			break;
		default:
			printf("\n  You should not be in this class!\n");
		}
	} while (option != 5);

	return;
}

FractionNodePtrNhat createNodeNhatH() {
	FractionNodePtrNhat node;

	node = (FractionNodePtrNhat)malloc(sizeof(FractionNodeNhat));
	node->data = createFractionNhatH();
	node->next = NULL;

	return node;
}

FractionPtrNhat createFractionNhatH() {
	FractionPtrNhat fraction = NULL;
	int tmp;

	fraction = (FractionPtrNhat)malloc(sizeof(FractionNhat));

	printf("\n  Enter the numberator: ");
	scanf_s("%d", &tmp);
	fraction->num = tmp;

	printf("  Enter the denominator: ");
	scanf_s("%d", &tmp);
	fraction->denom = tmp;

	while (tmp == 0) {
		printf("Can't set to zero! Enter a new denominator: ");
		scanf_s("%d", &tmp);
		fraction->denom = tmp;
	}

	reduceNhatH(&fraction);

	return fraction;
}

int getGCDNhatH(int num, int denom) {
	return (denom != 0) ? getGCDNhatH(denom, num % denom) : num;
}

void reduceNhatH(FractionPtrNhat* arg) {
	int gcd;

	if ((*arg)->denom < 0) {
		((*arg)->num) = -(*arg)->num;
		((*arg)->denom) = -(*arg)->denom;
	}

	if ((*arg)->num == 0) {
		(*arg)->denom = 1;
	} else {
		gcd = getGCDNhatH((*arg)->num, (*arg)->denom);
		if (gcd < 0) {
			gcd = -gcd;
		}
		(*arg)->num /= gcd;
		(*arg)->denom /= gcd;
	}

	return;

}
/*PROGRAM OUTPUT

******************************
* LINKED LIST MENU: Fraction *
* 1. Displaying current list *
* 2. Inserting               *
* 3. Removing                *
* 4. Quit                    *
******************************
Select the option(1, 2, 3, or 4): 5

  You should not be in this class!

******************************
* LINKED LIST MENU: Fraction *
* 1. Displaying current list *
* 2. Inserting               *
* 3. Removing                *
* 4. Quit                    *
******************************
Select the option(1, 2, 3, or 4): 1

  EMPTY LIST ...


******************************
* LINKED LIST MENU: Fraction *
* 1. Displaying current list *
* 2. Inserting               *
* 3. Removing                *
* 4. Quit                    *
******************************
Select the option(1, 2, 3, or 4): 2

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 1

  Calling insertFirstNhatHo() -

  Enter the numberator: 3
  Enter the denominator: 4

  Node inserted at first position.

  3/4 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 2

  Calling insertAtNhatHo() -

  Enter the index to insert after: 1

  Enter the numberator: 5
  Enter the denominator: 12

  Node has been inserted at the selected index.

  3/4 -> 5/12 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 3

  Calling appendNhatHo() -

  Enter the numberator: -3
  Enter the denominator: 7

  Node inserted at last position.

  3/4 -> 5/12 -> -3/7 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 2

  Calling insertAtNhatHo() -

  Enter the index to insert after: 3

  Enter the numberator: 4
  Enter the denominator: 9

  Node has been inserted at the selected index.

  3/4 -> 5/12 -> -3/7 -> 4/9 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 2

  Calling insertAtNhatHo() -

  Enter the index to insert after: 4

  Enter the numberator: 2
  Enter the denominator: 11

  Node has been inserted at the selected index.

  3/4 -> 5/12 -> -3/7 -> 4/9 -> 2/11 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 2

  Calling insertAtNhatHo() -

  Enter the index to insert after: 5

  Enter the numberator: 5
  Enter the denominator: 101

  Node has been inserted at the selected index.

  3/4 -> 5/12 -> -3/7 -> 4/9 -> 2/11 -> 5/101 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 2

  Calling insertAtNhatHo() -

  Enter the index to insert after: 6

  Enter the numberator: 6
  Enter the denominator: 17

  Node has been inserted at the selected index.

  3/4 -> 5/12 -> -3/7 -> 4/9 -> 2/11 -> 5/101 -> 6/17 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 3

  Calling appendNhatHo() -

  Enter the numberator: -8
  Enter the denominator: 15

  Node inserted at last position.

  3/4 -> 5/12 -> -3/7 -> 4/9 -> 2/11 -> 5/101 -> 6/17 -> -8/15 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 4

  [Index 1] -
    Address of FractionNode: 0056E140
    Address of Data: 005725C8
    Address of Next: 00572600
    Numerator: 3
    Denominator: 4

  [Index 2] -
    Address of FractionNode: 00572600
    Address of Data: 00572638
    Address of Next: 00572670
    Numerator: 5
    Denominator: 12

  [Index 3] -
    Address of FractionNode: 00572670
    Address of Data: 005726A8
    Address of Next: 005726E0
    Numerator: -3
    Denominator: 7

  [Index 4] -
    Address of FractionNode: 005726E0
    Address of Data: 00572718
    Address of Next: 00572750
    Numerator: 4
    Denominator: 9

  [Index 5] -
    Address of FractionNode: 00572750
    Address of Data: 00572788
    Address of Next: 005727C0
    Numerator: 2
    Denominator: 11

  [Index 6] -
    Address of FractionNode: 005727C0
    Address of Data: 005727F8
    Address of Next: 00572830
    Numerator: 5
    Denominator: 101

  [Index 7] -
    Address of FractionNode: 00572830
    Address of Data: 00572880
    Address of Next: 005728B8
    Numerator: 6
    Denominator: 17

  [Index 8] -
    Address of FractionNode: 005728B8
    Address of Data: 005728F0
    Address of Next: 00000000
    Numerator: -8
    Denominator: 15

  3/4 -> 5/12 -> -3/7 -> 4/9 -> 2/11 -> 5/101 -> 6/17 -> -8/15 -> NULL

  **********************
  *   Inserting Menu   *
  * 1. As first node   *
  * 2. After n-th node *
  * 3. As last node    *
  * 4. Displaying      *
  * 5. Quit            *
  **********************
  Select the option (1, 2, 3, or 4): 5

******************************
* LINKED LIST MENU: Fraction *
* 1. Displaying current list *
* 2. Inserting               *
* 3. Removing                *
* 4. Quit                    *
******************************
Select the option(1, 2, 3, or 4): 3

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 1

  Calling removeFirstNhatH() -

  Node removed at first position.

  5/12 -> -3/7 -> 4/9 -> 2/11 -> 5/101 -> 6/17 -> -8/15 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 2

  Calling removeAtNhatH() -

  Enter the index to be removed: -1

  Node removed at index -1.

  -3/7 -> 4/9 -> 2/11 -> 5/101 -> 6/17 -> -8/15 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 2

  Calling removeAtNhatH() -

  Enter the index to be removed: 99999

  Node removed at index 99999.

  -3/7 -> 4/9 -> 2/11 -> 5/101 -> 6/17 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 2

  Calling removeAtNhatH() -

  Enter the index to be removed: 4

  Node removed at index 4.

  -3/7 -> 4/9 -> 2/11 -> 6/17 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 3

  Calling removeLastNhatH() -

  Node removed at first position.

  -3/7 -> 4/9 -> 2/11 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 2

  Calling removeAtNhatH() -

  Enter the index to be removed: 2

  Node removed at index 2.

  -3/7 -> 2/11 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 4

  [Index 1] -
    Address of FractionNode: 00572670
    Address of Data: 005726A8
    Address of Next: 00572750
    Numerator: -3
    Denominator: 7

  [Index 2] -
    Address of FractionNode: 00572750
    Address of Data: 00572788
    Address of Next: 00000000
    Numerator: 2
    Denominator: 11

  -3/7 -> 2/11 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 1

  Calling removeFirstNhatH() -

  Node removed at first position.

  2/11 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 4

  [Index 1] -
    Address of FractionNode: 00572750
    Address of Data: 00572788
    Address of Next: 00000000
    Numerator: 2
    Denominator: 11

  2/11 -> NULL

  *******************
  *  Removing Menu  *
  * 1. First node   *
  * 2. n - th node  *
  * 3. Last node    *
  * 4. Displaying   *
  * 5. Quit         *
  *******************
  Select the option(1, 2, 3, or 4): 5

******************************
* LINKED LIST MENU: Fraction *
* 1. Displaying current list *
* 2. Inserting               *
* 3. Removing                *
* 4. Quit                    *
******************************
Select the option(1, 2, 3, or 4): 4

  Fractions and Linked Lists!

*/
