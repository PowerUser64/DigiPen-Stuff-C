/******************************
 * Filename: LinkedListLab.c
 * Author: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief Description: A demonstration of a few things you can do with malloc and pointers
   gcc -Wall -Wextra -O -ansi -pedantic -o LinkedListLab LinkedListLab.c
 ******************************/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Given a list, add a new node to the front of the list that contains value */
void add_front(struct Node **list, int value)
{
    /* allocate  mem and create new node
     * set num of new node to the value
     * set next of the new node to the old front/head ptr
     * set head ptr to new node ptr
     */
    struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
    pNode->number = value;
    pNode->next = *list;
    *list = pNode;
    return;
}

/* Given a list, free all of the nodes on the list */
void free_list(struct Node *list)
{
    while (list)
    {
        struct Node *temp = list->next;
        free(list);
        list = temp;
    }

    return;
}

/* Given a list, print the value of each node. The format specifier for the printf function is "%3i" */
void print_list(const struct Node *list)
{
    while (list)
    {
        printf("%3i", list->number);
        list = list->next;
    }
    putchar('\n');
    return;
}

/* Given a list, count the number of nodes in the list and return that value */
int size_list(const struct Node *list)
{
    int i;
    while (list)
    {
        printf("%3i", list->number);
        ++i;
        list = list->next;
    }
    putchar('\n');
    return i;
}

/* Given a list, add up all of the values in the nodes and return that value */
int sum_list(const struct Node *list)
{
    return 0;
}

/* Given a list, add a new node to the back of the list that contains value */
void add_back(struct Node **list, int value)
{
    return;
}

/* Given a list, remove the node that contains value. If there are multiple nodes that contain the same value, you will only remove the first one that you encounter */
void remove_item(struct Node **list, int value)
{
    return;
}