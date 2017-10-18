#ifndef LIST_H
#define LIST_H

#include <stdio.h>

struct node
{
  int data;
  struct node * next;
};


void list_push (struct node ** head_ref, int data)
{
  struct node * new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}


void list_insert (struct node * prev_node, int data)
{
  if (prev_node == NULL)
  {
    printf("the given previous node cannot be NULL\n");
    return;
  }

  struct node * new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}


void list_append (struct node ** head_ref, int data)
{
  struct node * new_node = (struct node *)malloc(sizeof(struct node));
  struct node * last = * head_ref;
  new_node->data = data;
  new_node->next = NULL;
  
  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }
  
  while (last->next != NULL)
  {
    last = last->next;
  }
  last->next = new_node;

  return;
}


void list_print (struct node * n)
{
  while (n != NULL)
  {
    printf(" %d ", n->data);
    n = n->next;
  }
}

#endif
