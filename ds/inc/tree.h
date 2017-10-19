#ifndef TREE_H
#define TREE_H

struct node
{
  int data;
  struct node * left;
  struct node * right;
};


struct node * treenode_create (int data)
{
  struct node * n = (struct node *)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;

  return n;
}

#endif
