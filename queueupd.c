#include <stdio.h>
#include <stdlib.h>

// struct for the values in the queue
struct Node {
  struct Node *next;
  int value;
};

// struct for the queues with pointers to the first and last
// element in the queue
struct Queue {
  struct Node *first;
  struct Node *last;
};

// prototypes
void enqueue(struct Queue*, int);
void dequeue(struct Queue*);

int main() {
  struct Queue queue;
  queue.first = NULL;
  queue.last = NULL;

  enqueue(&queue, 5);
  printf("first %d\n", queue.first->value);
  printf("last %d\n", queue.last->value);
  enqueue(&queue, 10);
  printf("first %d\n", queue.first->value);
  printf("last %d\n", queue.last->value);
  dequeue(&queue);
  printf("first %d\n", queue.first->value);
  printf("last %d\n", queue.last->value);

  return 0;
}

void enqueue(struct Queue *queue, int value) {
  struct Node *newnode = malloc(sizeof(struct Node));
  newnode->value = value;

  if(queue->first == NULL) {
    queue->first = newnode;
  }

  if(queue->last != NULL) {
    newnode->next = queue->last->next;
    queue->last->next = newnode;
  }

  queue->last = newnode;
}

void dequeue(struct Queue *queue) {
  if(queue->first != NULL) {
    struct Node *toFree = queue->first;

    if(queue->first->next != NULL) {
      queue->first = queue->first->next;
      free(toFree);
    }
    else {
      free(toFree);
      queue->first = NULL;
    }
  }
}
