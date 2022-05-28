#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct node *node_ptr;

typedef char *char_ptr;

typedef struct node {
	node_ptr next;
	node_ptr prev;
	char_ptr cont;
};

typedef struct list *list_ptr;

typedef struct list {
	node_ptr first;
	node_ptr last;
};

list_ptr create_list() {
	list_ptr new_list = (list_ptr)malloc(sizeof(struct list));
	new_list->first = NULL;
	new_list->last = NULL;
	return new_list;
}

void destroy_nodes(list_ptr l) {
	node_ptr node = l->first;

	while (node != NULL) {
		node_ptr aux = node;
		node = node->next;
		destroy_node(aux);
	}
}

void destroy_list(list_ptr l) {
	destroy_nodes(l);
	free(l);
}

node_ptr create_node(char_ptr str) {
	node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
	new_node->cont = (char_ptr)malloc(sizeof(char) * strlen(str) + 1);
	strcpy(new_node->cont, str);
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void destroy_node(node_ptr node) {
	free(node->cont);
	free(node);
}

void add_node(list_ptr l, char_ptr str) {
	node_ptr new_node = create_node(str);
	
	if (l->first == NULL) {
		l->first = new_node;
		l->last = new_node;
	} else if (l->first == l->last) { 
		l->last = new_node;
		l->first->next = new_node;
		new_node->prev = l->first;
	} else {
		new_node->prev = l->last;
		l->last->next = new_node;
		l->last = new_node;
	}
}

int is_empty(list_ptr l) {
	return l->first == NULL;
}

void show(list_ptr l) {
	if (is_empty(l)) {
		printf("List is empty!\n");
	} else if (l->first == l->last) {
		printf("List has only one element: %s\n", l->first->cont);
	} else {
		node_ptr node = l->first;
		printf("%s (FIRST)\n", node->cont);
		while (node->next != NULL && node->next != l->last) {
			printf("%s\n", node->next->cont);
			node = node->next;
		}
		printf("%s (LAST)\n", l->last->cont);
	}
}

int main() {
	list_ptr my_list = create_list();
	add_node(my_list, "Hey!");
	add_node(my_list, "Ho!");
	add_node(my_list, "Lets...");
	add_node(my_list, "Go!");
	show(my_list);
	destroy_list(my_list);
	return 0;
}

