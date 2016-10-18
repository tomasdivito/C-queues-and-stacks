#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *next;
  int value;
};

struct Linked_List {
  struct Node *first;
};

void add(struct Linked_List*, int, int);
void delete(struct Linked_List*, int);
void returnOutOfIndexException();
void show_current_list(struct Linked_List*);

int main() {
  struct Linked_List l_list;
  l_list.first = NULL;

  add(&l_list, 0, 4);
  show_current_list(&l_list);
  add(&l_list, 0, 5);
  show_current_list(&l_list);
  add(&l_list, 2, 6);
  show_current_list(&l_list);

  return 0;
}

void add(struct Linked_List* l_list, int position, int value) {
  int i;
  int nextIsNull;
  struct Node *currentNode = NULL;
  struct Node *pastNode = NULL;

  struct Node *newnode = malloc(sizeof(struct Node));
  newnode->value = value;
  newnode->next = NULL;

  //if it the first element we just insert it anyway on the first value
  if(l_list->first == NULL) {
    l_list->first = newnode;
  }
  else {
    i = 0;
    nextIsNull = 0;
    while(i <= position && nextIsNull == 0) {
      if(i == 0) {
        currentNode = l_list->first;
        ++i;
      }

      if(i == position) {
        if(pastNode != NULL) {
          pastNode->next = newnode;
        }
        if(currentNode != NULL) {
          newnode->next = currentNode;
        }
      }

      if(currentNode->next != NULL) {
        pastNode = currentNode;
        currentNode = currentNode->next;
        ++i;
      }
      else {
        if(currentNode->next == NULL && position == i+1) {
          currentNode = NULL;
          ++i;
        }
        else {
          nextIsNull = 1;
          returnOutOfIndexException();
        }
      }
    }
  }
}

void delete(struct Linked_List* l_list, int position) {

}

void returnOutOfIndexException() {
  printf("\n Position value is not valid for the list \n");
}

void show_current_list(struct Linked_List* l_list) {
  struct Node* currentNode;
  int nextIsNull = 0;
  int times = 0;

  while(nextIsNull != 1) {
    if(times == 0) {
      currentNode = l_list->first;
      printf("%d ", currentNode->value);
    }
    else {
      printf(" %d ", currentNode->value);
    }
    if(currentNode->next != NULL) {
      currentNode = currentNode->next;
    }
    else {
      nextIsNull = 1;
    }
    ++times;
  }

  printf("\n");
}
