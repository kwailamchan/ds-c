#ifndef LIST_H
#define LIST_H

#include <stdio.h>

struct node
{
  int data;
  struct node * next;
};

/* --------------------------------------------------------------------------- */
/*
 * create:
 * - push
 * - insert
 * - append
 */

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


/* --------------------------------------------------------------------------- */
/*
 * delete:
 * - head
 * - node
 * - tail
 */


void list_delete (struct node ** head_ref, int data)
{
  struct node * tmp = * head_ref;
  struct node * prev;

  if (tmp != NULL && tmp->data == data)
  {
    * head_ref = tmp->next;  // change head
    free (tmp);              // free old head
    return;
  }

  while (tmp != NULL && tmp->data != data)
  {
    prev = tmp;
    tmp = tmp->next;
  }

  if (tmp == NULL) return;
  prev->next = tmp->next;

  free(tmp);
}


void list_delete_by_position (struct node ** head_ref, int position)
{
  if (*head_ref == NULL)
  {
    return;
  }

  struct node * tmp = * head_ref;
  if (position == 0)
  {
    * head_ref = tmp->next;
    free (tmp);
    return;
  }

  int i;
  for (i = 0; tmp != NULL && i < position-1; ++i)
  {
    tmp = tmp->next;
  }

  if (tmp == NULL || tmp->next == NULL)
  {
    return;
  }

  struct node * next = tmp->next->next;
  free (tmp->next);
  tmp->next = next;
}

/* --------------------------------------------------------------------------- */

int list_count (struct node * head)
{
/*
  int counter = 0;
  struct node * current = head;
  while (current != NULL)
  {
    counter++;
    current = current->next;
  }
  return counter;
*/

  if (head == NULL)
    return 0;
  return 1 + list_count(head->next);
}

/* --------------------------------------------------------------------------- */

void list_print (struct node * n)
{
  while (n != NULL)
  {
    printf(" %d ", n->data);
    n = n->next;
  }
}

#endif
