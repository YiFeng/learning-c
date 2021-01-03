/**
 *  1. Initialize Linked list from file
 *  2. Print all elements in the linked list
 *  3. Insert 1 element
 *  4. Find whether one value exists in the list or not.
 *  4. Delete all element that equals 5
 *  5. Print all elements in the linked list
 */

#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
};

typedef struct LinkedListNode LinkedListNode;

LinkedListNode* creat_node(int data){
    LinkedListNode *node = (LinkedListNode *)calloc(1, sizeof(LinkedListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedListNode* initialize_linked_list(){
    FILE *fpRead=fopen("linklist.txt","r");
	if(fpRead==NULL){
		printf("Open fail");
	}
    int temporary_data;
    fscanf(fpRead,"%d ",&temporary_data);
    LinkedListNode *head = creat_node(temporary_data);
    LinkedListNode *previous_node = head;
    while(fscanf(fpRead,"%d ",&temporary_data) != EOF){
        LinkedListNode *current_node = creat_node(temporary_data);
        previous_node->next = current_node;
        previous_node = current_node;
    }
    fclose(fpRead);
    return head;
}


void print_linked_list(LinkedListNode *head){
    LinkedListNode *current_node = head;
    // while(current_node->next != NULL){
    //     current_node = current_node->next;
    //     printf("%d ", current_node->data);
    // }
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void linked_list_insert(LinkedListNode *node, LinkedListNode *new_node){
    LinkedListNode *next_node = node->next;
    node->next = new_node;
    new_node->next = next_node;
}

LinkedListNode *linked_list_find_first(LinkedListNode *head, int value) {
    LinkedListNode *current_node = head;
    while (current_node != NULL){
        if(current_node->data == value){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// LinkedListNode *linked_list_find_first(LinkedListNode *head, int value) {
//     LinkedListNode *current_node = head;
//     LinkedListNode *result = NULL;
//     while (current_node != NULL){
//         if(current_node->data = value){
//             result = current_node;
//             break;
//         }
//         current_node = current_node->next;
//     }
//     return result;
// }

void linked_list_delete_next(LinkedListNode *node) {
    if(node->next == NULL){
        return;
    }
    LinkedListNode *delete_node = node->next;
    node->next = delete_node->next;
    free(delete_node);
}

void free_linked_list(LinkedListNode* head) {
    LinkedListNode *current_node = head;
    LinkedListNode *next_node;
    while(current_node != NULL){
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

int main(){
    LinkedListNode *head = initialize_linked_list();
    print_linked_list(head);
    // ##############
    LinkedListNode *target_node = linked_list_find_first(head, 5);
    LinkedListNode *inserted_node = creat_node(100);
    linked_list_insert(target_node, inserted_node);
    print_linked_list(head);
    linked_list_delete_next(target_node);
    print_linked_list(head);
    // ##############
    free_linked_list(head);
}