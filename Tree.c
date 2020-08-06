#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter any number(-1 for no node):");
    scanf("%d",&x);

    if(x==-1)
return NULL;

    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

void preorder(node *t)   //preorder traversal
{
  if(t!=NULL)
  {
    printf("  %d",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}
void inorder(node *t)   // inorder traversal
{  
  if(t!=NULL)
  {
    inorder(t->left);
    printf("  %d",t->data);
    inorder(t->right);
  }
}
void postorder(node *t)   //postorder traversal
{
  if(t!=NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("  %d",t->data);
  }
}
int main()     
{
  node *root;
  root=create();
  printf("\npreorder traversal: ");
  preorder(root);
  printf("\ninorder traversal:  ");
  inorder(root);
  printf("\npostorder traversal:");
  postorder(root);
  return 0;
}

