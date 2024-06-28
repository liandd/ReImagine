#include<bits/stdc++.h>
using namespace std;

struct node{
	int key;
	struct node *sig;
};

struct node *hacerLista(int n){
	struct node *head, *newNode;
	head = NULL;
	while(n >= 1){
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->key = n;
		newNode->sig = head;
		head = newNode;
		n--;
	}
	return head;
}

void mostrarLista(struct node *head){
	struct node *actual;
	actual = head;
	while(actual != NULL){
		printf("%d ", actual->key);
		actual = actual->sig;
	}
	printf("NULL.\n");
}

struct node *borrarLista(struct node *head){
	struct node *actual;
	while(head != NULL){
		actual = head;
		head = head->sig;
		free(actual);
	}
	return head;
}

struct node *insertar(struct node *head, int element){
	struct node *newNode, *actual, *previous;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = element;
	if(head == NULL){
		newNode->sig = head;
		head = newNode;
	}
	else{
		if(element <= head->key){
			newNode->sig = head;
			head = newNode;
		}
		else{
			actual = head;
			previous = NULL;
			while((actual != NULL) && (element > actual->key)){
				previous = actual;
				actual = actual->sig;
			}
			newNode->sig = actual;
			previous->sig = newNode;
		}
	}
	return head;
}

struct node *borrar(struct node *head, int element){
	struct node *previous, *actual;
	if(head == NULL){
		printf("EMPTY.\n");
	}
	else{
		if(element < head->key){
			printf("ELEMENT IS NOT IN THE LIST.\n");
		}
		else{
			if(element == head->key){
				actual = head;
				head = head->sig;
				free(actual);
			}
			else{
				previous = head;
				actual = head->sig;
				while(actual != NULL){
					if(element > actual->key){
						previous = actual;
						actual = actual->sig;
					}
					else
						break;
				}
				if(actual == NULL){
					printf("ELEMENT IS NOT IN THE LIST.\n");
				}
				else{
					if(actual->key != element){
						printf("ELEMENT IS NOT IN THE LIST.\n");
					}
					else{
						previous->sig = actual->sig;
						free(actual);
					}
				}
			}
		}
	}
	return head;
}

int main(){
	int operacion, element;
	struct node *head;
	head = NULL;
	while(scanf("%d %d", &operacion, &element) != EOF){
		if(operacion == 1){ // INSERTAR EN LISTA
			head = insertar(head, element);
			mostrarLista(head); 
		}
		else{
			if(operacion == 2){ // BORRAR ELEMENTO EN LA LISTA
				head = borrar(head, element);
				mostrarLista(head);
			}
		}
	}
	return 0;
}



















