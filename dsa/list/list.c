#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	Node* next;
} Node;

Node* makeNewList(){
	Node* list = (Node*) malloc(sizeof(Node));
	list->next = NULL;
	return list;
}

void insert(Node* t, int value){
	while(t->next!=NULL){
		t = t->next;
	}
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;

	t->next = newNode;
}

int find(Node* t, int value){
	while(t->next!=NULL){
		if(t->next->value==value) return 1;
		t = t->next;
	}
	return 0;
}

void update(Node* t, int oldValue, int newValue){
	while(t->next!=NULL){
		if(t->next->value==oldValue){
			t->next->value = newValue;
			break;
		}
		t = t->next;
	}
}

void deleteNode(Node* t, int value){
	Node* prev;
	while(t->next!=NULL){
		prev = t->next;
		if(t->next->value==value){
			t->next = t->next->next;
			free(prev);
			break;
		}
		t = t->next;
	}
}

void display(Node* t){
	while(t->next!=NULL){
		printf("%d -> ", t->next->value);
		t = t->next;
	}
	printf("end\n");
}

int main(){
	Node* list = makeNewList();
	int i=0;
	for(i=1;i<10;i++){
		insert(list,i);
	}
	display(list);
	for(i=1;i<5;i++){
		update(list, i, i*100);
	}
	display(list);
	for(i=9;i>=5;i--){
		deleteNode(list, i);
		display(list);
	}
	printf("%d\n", find(list, 100));
}
