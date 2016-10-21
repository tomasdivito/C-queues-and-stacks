#include <stdio.h>
#include <stdlib.h>

// TODO: Implementation of the search function
// Spanish: Recorrer el vector de forma infija, prefija, y postfija

struct Node {
  int value;
  struct Node *leftchild;
  struct Node *rightchild;
};

struct Btree {
  struct Node *root;
};

void insertvalue(struct Btree*, int);
void searchvalue(struct Btree*, int);
void showtree(struct Btree*);
void emptyTreeException();
void gothrough(struct Node*);

int main() {
  struct Btree btree;
  btree.root = NULL;

  insertvalue(&btree, 7);
  insertvalue(&btree, 3);
  insertvalue(&btree, 8);
  insertvalue(&btree, 4);
  insertvalue(&btree, 2);
  insertvalue(&btree, 7);
  insertvalue(&btree, 12);

  showtree(&btree);

  return 0;
}

void emptyTreeException() {
  printf("This tree is empty!\n\n");
}

void showtree(struct Btree *btree) {
  struct Node *currentnode;

  if(btree->root == NULL) {
    emptyTreeException();
  }
  else {
    currentnode = btree->root;
    printf("[%d]\n", currentnode->value);
    gothrough(currentnode);
  }
}

void gothrough(struct Node* node) {
  struct Node *currentnode = node;
  int finished = 0;
  if(currentnode->leftchild != NULL) {
    printf(" [%d] -> (left child)  -> [%d] \n", currentnode->value, currentnode->leftchild->value);
    finished = 1;
  }
  if(currentnode->rightchild != NULL) {
    printf(" [%d] -> (right child) -> [%d] \n", currentnode->value, currentnode->rightchild->value);
    finished = 1;
  }
  if(finished == 1) {
    if(currentnode->leftchild != NULL) {
      gothrough(currentnode->leftchild);
    }
    if(currentnode->rightchild != NULL) {
      gothrough(currentnode->rightchild);
    }
  }
}

void insertvalue(struct Btree *btree, int value) {
  struct Node* newnode = malloc(sizeof(struct Node));
  int finished = 0;

  newnode->value = value;
  newnode->leftchild = NULL;
  newnode->rightchild = NULL;

  // If this new node is the first it's gonna be the ROOT of the tree
  if(btree->root == NULL) {
    btree->root = newnode;
  }
  else {
    struct Node* currentnode = btree->root;
    while(finished == 0) {
      if(currentnode->value > value) {
        if(currentnode->leftchild == NULL) {
          currentnode->leftchild = newnode;
          finished = 1;
        }
        else {
          currentnode = currentnode->leftchild;
        }
      }
      else {
        if(currentnode->rightchild == NULL) {
          currentnode->rightchild = newnode;
          finished = 1;
        }
        else {
          currentnode = currentnode->rightchild;
        }
      }
    }
  }
}
