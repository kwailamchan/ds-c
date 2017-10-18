#include <stdio.h>
#include <stdlib.h>

#include "unity.h"
#include "list.h"


void test_list (void)
{
  struct node * head = NULL;
  struct node * second = NULL;
  struct node * third = NULL;

  // allocate 3 nodes in the heap
  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = NULL;

  list_print (head);

  free (head);
  free (second);
  free (third);
}


int main (void)
{
  UNITY_BEGIN ();
  RUN_TEST (test_list);
  return UNITY_END ();
}