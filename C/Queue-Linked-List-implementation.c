////////////////////////////////////
// I am using a mixture between a queue and a linked list that way I can 
// add as many eliments in a linked list fashion but still have the first 
// in first out ordering

#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

//adds a Node to the end of the linked list
void push(struct Node *head, struct NBReturn *obj){
	//create node
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	struct Node* current = head;
	bool done = false;
	//traverse through to the end
	while(!done){
		//reached end
		if(current->next == NULL){
			//initalize the node
			new->next = NULL;
			new->nbr = obj;
			current->next = new;
			done = true;
		}else{
			current = current->next;
		}
	}
}

//remove the node that contains remove as an NBReturn and 
//return the new head
struct Node* pop(struct Node *head, struct NBReturn *remove){
	struct Node *current = head;
	struct Node *newHead = head;
	bool done = false;
	//the npde was the first one
	if(current->nbr == remove){
		newHead = current->next;
		free(current);
		done = true;
	}
	//search the linked list
	while(!done){
		if(current->next->nbr == remove){
			done = true;
			struct Node *next = current->next;
			current->next = current->next->next;
			free(next);
		}else if(current == NULL){
			done = true;		
		}else{
			current = current->next;
		}
	}
	return newHead;
}
