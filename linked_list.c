/**
 *  1. Initialize Linked list from file
 *  2. Print all elements in the linked list
 *  3. Insert 1 element
 *  4. Find whether one value exists in the list or not.
 *  4. Delete all element that equals 5
 *  5. Print all elements in the linked list
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
}

typedef struct LinkedListNode LinkedListNode;

void print_linked_list(LinkedListNode *head) {
}

void linked_list_insert(LinkedListNode *node, LinkedListNode *new_node) {

}

bool linked_list_find(LinkedListNode *head, int value) {

}

void linked_list_delete_next(LinkedListNode *node) {

}

LinkedListNode* initialize_linked_list() {
    LinkedListNode *head = calloc(1, sizeof(LinkedListNode));
    head->next = NULL;

    return head;
}

void free_linked_list(LinkedListNode* head) {

}

int main() {

}