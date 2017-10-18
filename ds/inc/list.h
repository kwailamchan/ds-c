#ifndef LIST_H
#define LIST_H

#include <stdio.h>

struct node
{
  int data;
  struct node * next;
};


void list_print (struct node * n)
{
  while (n != NULL)
  {
    printf(" %d ", n->data);
    n = n->next;
  }
}

#endif
