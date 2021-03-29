#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

int append(node* head, int val);
int push(node* head, int val);
void print_llist(node* head);

int main()
{
    node* head = NULL;
    head = (node*) malloc(sizeof(node));

    head->value = 2;
    head->next = NULL;

    append(head, 3);
    append(head, 5);

    print_llist(head);
}

void print_llist(node* head)
{
    node* curr = head;
    while (curr != NULL) {
        printf("%d->", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

int append(node* head, int val)
{
    node* curr = head;
    while (curr->next)
        curr = curr->next;

    // add new node
    node* new_node;
    new_node = (node*) malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    curr->next = new_node;

    return 0;
}

int push(node* head, int val)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = val;
    new_node->next = head;
    head = new_node;

    return 0;
}