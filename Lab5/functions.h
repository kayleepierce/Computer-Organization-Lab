/*
* Kaylee Pierce
* CPSC 2311-002
* kayleej@clemson.edu
* Instructor: Dr. Yvon Feaster
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int month;
    int day;
    int year;
} Birthday;

typedef struct node {
    char nameFirst[50];
    char nameLast[50];
    Birthday birthday;
    char major[10];
    char classStanding[15];
    struct node* next;
} node_t;


/* 
* Parameters:
*       input [pointer to input file]
*       head [pointer to head of linked list]
* Return: pointer to head of linked list
* This function reads student info from the input file and
* creates a linked list
*/
node_t* createList(FILE* input, node_t** head);

/* 
* Parameters:
*       node [pointer to node that going to be added]
*       head [pointer to head of linked list]
* Return: N/a
* This function adds the node to the end of linked list
*/
void add(node_t** node, node_t** head);

/* 
* Parameters:
*       input [pointer to the input file]
* Return: pointer to the node created
* This function reads info from input file and creates a node
* with the data
*/
node_t* readNodeInfo(FILE* input);

/* 
* Parameters:
*       output [pointer to output file]
*       head [pointer to head of linked list]
* Return: N/a
* This function prints the linked list to the output file
*/
void printList(FILE* output, node_t* head);

/* 
* Parameters:
*       output [pointer to the output file]
* Return: N/a
* This function prints a border around the info in the output file
*/
void printBorder(FILE* output);

/* 
* Parameters:
*       head [pointer to the head of linked list]
* Return: N/a
* This function deletes the linked list
*/
void deleteList(node_t** head);

#endif /*FUNCTIONS_H*/
