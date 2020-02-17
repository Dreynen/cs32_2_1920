#include<stdio.h>
#include<stdlib.h>

#define newline printf("\n")

typedef struct node Node;
struct node{
	int data;
	Node* next;
};

//declare your functions here
void print_linked_list(Node *);
void build_linked_list(Node **);
int count(Node* , int );
int get_nth(Node *, int);
void free_node(Node *);

int main() {

	Node *head = NULL;
	int index, nth;

	// build a linked list
	build_linked_list(&head);

	// optionally, you may want to print the list to make sure data is stored as desired
	// print_linked_list(head);

	// read index, find value at nth index, determine number of copies in the list
	while((scanf("%d",&index)>0) && (index != -1)){
		nth = get_nth(head, index);
		printf("%d %d %d\n", index, nth, count(head,nth));
	}

	// free the nodes
	free_node(head);
	return 0;
}


void print_linked_list(Node *head) {
	Node *current;
	for(current=head; current != NULL; current = current->next){
		printf("%d ", current->data);
	}
	newline;
}

void build_linked_list(Node **head_ptr) {
	int val = 0;
	while (val >= 0) {
	    scanf(" %d", &val);
	    Node *n = malloc(sizeof(Node));
	    n->data = val;
	    n->next = *head_ptr;
	    *head_ptr = n;
	}
}

int count(Node *head, int to_search) {
	int count = 0;
	while (head) {
	    if (head->data == to_search) {
	        count++;
	    }
	    head = head->next;
	}
	return count;
}

int get_nth(Node *head, int index) {
	while (index--) {
	    head = head->next;
	}
	return head->data;
}

void free_node(Node *a_node) {
	if(a_node!=NULL){
		free_node(a_node->next);
		free(a_node);
	}
}