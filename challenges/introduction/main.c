#include <stdio.h>
#include <malloc.h>

typedef struct node *node_ptr;

typedef struct node {
	node_ptr next;
	node_ptr prev;
	char *cont;
};

typedef struct list *list_ptr;

typedef struct list {
	node_ptr first;
	node_ptr last;
};

list_ptr create_list() {
	return malloc(sizeof(struct list));
}

void destroy_list(list_ptr l) {
	free(l);
}


int main() {
	destroy_list(create_list());
	return 0;
}

