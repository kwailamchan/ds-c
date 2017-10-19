#include <stdio.h>
#include <stdlib.h>

#include "unity.h"
#include "tree.h"


void test_tree (void)
{
  struct node * root = treenode_create(1);
  root->left = treenode_create(2);
  root->right = treenode_create(3);
  root->left->left = treenode_create(4);

  return 0;
}


int main (void)
{
  UNITY_BEGIN ();
  RUN_TEST (test_tree);
  return UNITY_END ();
}
