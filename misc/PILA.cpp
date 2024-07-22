#include<bits/stdc++.h>
#define myNegativeInfinite -2147483647
#define myPositiveInfinite 2147483647
#define TRUE 1
#define FALSE 0

struct node {
    int key;
    struct node *next;
};

struct node *push(struct node *top, int element) {
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode->key = element;
    newNode->next = top;
    top = newNode;
    return top;
}

int pop(struct node **top) {
    struct node *actualNode;
    int element;
    actualNode = *top;
    element = actualNode->key;
    *top = actualNode->next;
    free(actualNode);
    return element;
}
/*
void printStack(struct node *top) {
    struct node *actualNode;
    actualNode = top;
    while (actualNode != NULL) {
        printf("%d ", actualNode->key);
        actualNode = actualNode->next;
    }
    printf("\n");
}
*/
int stackEmpty(struct node *top) {
    return top == NULL ? TRUE : FALSE;
}

int getMin(struct node *minStack) {
    if (stackEmpty(minStack)) {
        printf("EMPTY\n");
        return myPositiveInfinite; // or another appropriate value
    } else {
        return minStack->key;
    }
}

int main() {
    struct node *top = NULL;
    struct node *minStack = NULL;
    int n, element;
    char str[6];
	scanf("%d", &n);
    while (n--) {
    	scanf("%s", str);
        if (strcmp(str,"PUSH")==0) { /* Push */
            scanf("%d", &element);
            top = push(top, element);

            if (stackEmpty(minStack) || element <= minStack->key) {
                minStack = push(minStack, element);
            }

            //printStack(top);
        } else if (strcmp(str,"POP")==0) { /* Pop */
            if (stackEmpty(top) != TRUE) {
                element = pop(&top);

                if (!stackEmpty(minStack) && element == minStack->key) {
                    pop(&minStack);
                }

                //printf("Element: %d\n", element);
                //printStack(top);
            } else {
                printf("EMPTY\n");
            }
        } else if (strcmp(str,"MIN")==0) { /* Get Min */
            int min = getMin(minStack);
            if (min != myPositiveInfinite) {
                printf("%d\n", min);
            }
        } /*else {
            //printf("Bad use. \n1. Push \n2. Pop \n3. Get Min\n");
        }*/
    }

    return 0;
}
