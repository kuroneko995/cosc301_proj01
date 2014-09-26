#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* your list function definitions */

void list_clear(struct node *list) {
    while (list != NULL) {
        struct node *tmp = list;
        list = list->next;
        free(tmp);
    }
}

void list_append(int value, struct node **head) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node -> value = value;
    new_node -> next = *head;
    *head = new_node;
}

void list_insert(int value, struct node **head) { // Insert new value into sorted ascending list
    struct node *new_node = malloc(sizeof(struct node));
    new_node -> value = value;
    int temp = 0;
    struct node fake_head = {0, *head}; // faciliatate inserting at the beginning
    struct node *curr_node = *head;
    struct node *prev_node = &fake_head;
    while (curr_node != NULL) {
        temp = curr_node -> value;   
        if (value <= temp) { // insert before first bigger value
            new_node -> next = curr_node;
            prev_node -> next = new_node;
            *head = fake_head.next;
            return; 
        }
        prev_node = curr_node;
        curr_node = prev_node -> next;
    }    
    // value is bigger than everything in list. insert at the end
    new_node -> next = NULL;
    prev_node -> next = new_node;
    *head = fake_head.next;
}

void free_list(struct node **head) {
    struct node *next = NULL;
    struct node *temp = *head;
    while (temp != NULL) {
        next = temp -> next;
        free(temp);
        temp = next;
    }
    free(head);
}

void print_list(struct node **head) {
    printf("** List Contents Begin **\n");
    struct node *temp = *head;
    while (temp != NULL) {
        printf("%d\n", temp -> value);
        temp = temp -> next;
    }
    printf("** List Contents End **\n");
}
