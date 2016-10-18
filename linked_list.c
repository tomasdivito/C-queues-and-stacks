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
void returnEmptyListException();
void show_current_list(struct Linked_List*);

int main() {
  struct Linked_List l_list;
  l_list.first = NULL;

  add(&l_list, 0, 5);
  add(&l_list, 1, 3);
  add(&l_list, 1, 2);
  show_current_list(&l_list);

  delete(&l_list, 1);
  show_current_list(&l_list);

  delete(&l_list, 0);
  show_current_list(&l_list);


  delete(&l_list, 20);
  show_current_list(&l_list);

  delete(&l_list, 0);
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
    currentNode = l_list->first;

    while(i <= position && nextIsNull < 1) {
      if(i == position) {
        if(pastNode != NULL) {
          pastNode->next = newnode;
        }
        else {
          l_list->first = newnode;
        }
        if(currentNode != NULL) {
          newnode->next = currentNode;
        }
        else {
          break;
        }
      }

      if(currentNode != NULL) {
        pastNode = currentNode;
        currentNode = currentNode->next;
      }
      else {
        nextIsNull = 1;

        returnOutOfIndexException();
      }
      ++i;
    }
  }
}

void delete(struct Linked_List* l_list, int position) {
  struct Node *currentNode = NULL;
  struct Node *pastNode = NULL;
  int i = 0;
  int nextIsNull = 0;

  if(l_list->first != NULL) {
    currentNode = l_list->first;
    while(i <= position && nextIsNull < 1) {
      if(i == position) {
        if(pastNode == NULL) {
          if(currentNode->next != NULL){
            l_list->first = currentNode->next;
            free(currentNode);
          }
          else {
            l_list->first = NULL;
            free(currentNode);
          }
        }
        else {
          if(currentNode->next != NULL) {
            pastNode->next = currentNode->next;
            free(currentNode);
          }
          else {
            pastNode->next = NULL;
            free(currentNode);
          }
        }
      }

      if(currentNode != NULL) {
        pastNode = currentNode;
        currentNode = currentNode->next;
      }
      else {
        nextIsNull = 1;
        returnOutOfIndexException();
      }
      ++i;
    }
  }
  else {
    returnEmptyListException();
  }
}

void returnOutOfIndexException() {
  printf("Out of index exception\n");
}

void returnEmptyListException() {
  printf("Empty list exception\n[*]\n");
}

void show_current_list(struct Linked_List* l_list) {
  struct Node* currentNode;
  int nextIsNull = 0;
  int times = 0;
  if(l_list->first != NULL) {
    while(nextIsNull != 1) {
      if(times == 0) {
        currentNode = l_list->first;
        printf("[%d] ", currentNode->value);
        times = 1;
      }
      else {
        printf(" [%d] ", currentNode->value);
      }
      if(currentNode->next != NULL) {
        currentNode = currentNode->next;
      }
      else {
        nextIsNull = 1;
      }
    }
    printf("\n\n");
  }
  else {
    returnEmptyListException();
  }
}
