/*
* Kaylee Pierce
* CPSC 2311-002
* kayleej@clemson.edu
* Instructor: Dr. Yvon Feaster
*/

#include "functions.h"
#define NUM_BORDER 80

node_t* createList(FILE* input, node_t** head) {
    node_t* newNode = NULL;
    while ((newNode = readNodeInfo(input)) != NULL) {
        add(&newNode, head);
    }
    return *head;
}

void add(node_t** node, node_t** head) {
    if (*head == NULL) {
        *head = *node;
    } else {
        node_t* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *node;
    }
    (*node)->next = NULL;
}

node_t* readNodeInfo(FILE* input) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    
    if (fscanf(input, " %49[^,\n], %49[^,\n], %d, %d, %d, %9[^,\n], %14[^,\n]",
               newNode->nameLast,
               newNode->nameFirst,
               &newNode->birthday.month,
               &newNode->birthday.day,
               &newNode->birthday.year,
               newNode->major,
               newNode->classStanding) != 7) {
        free(newNode);
        return NULL;
    }
    return newNode;
}

void printList(FILE* output, node_t* head) {
    printBorder(output);
    fprintf(output, "List Info:\n");
    node_t* current = head;
    while (current != NULL) {
        fprintf(output, "Name:\t%s %s\n", current->nameFirst, current->nameLast);
        fprintf(output, "Date of Birth:\t%d %d, %d\n", current->birthday.month, current->birthday.day, current->birthday.year);
        fprintf(output, "Major:\t%s\n", current->major);
        fprintf(output, "Year:\t%s\n\n", current->classStanding);
        current = current->next;
    }
    printBorder(output);
}

void printBorder(FILE* output) {
    for (int i = 0; i < NUM_BORDER; i++) {
        fprintf(output, "*");
    }
    fprintf(output, "\n");
}

void deleteList(node_t** head) {
    node_t* current = *head;
    node_t* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
