#include <stdio.h>
#include <stdlib.h>

struct Node{
  struct Node* nodeBefore;
  int value;
};

struct Queue{
  struct Node* firstElement;
  struct Node* lastElement;
};

//prototypes
void enqueue(struct Queue, int);
void dequeue(struct Queue);
void showCurrentQueue(struct Queue, char[]);

int main(){
  struct Queue queue;
  queue.firstElement = NULL;
  queue.lastElement = NULL;

  enqueue(queue, 25);
  enqueue(queue, 30);
  dequeue(queue);

  return 0;
}

void enqueue(struct Queue queue, int value){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->value = value;

  //if there's no first value yet
  if(queue.firstElement == NULL){
    queue.firstElement = newNode;           //now he's the first value
  }
  if(queue.lastElement == NULL){
    newNode->nodeBefore = queue.lastElement;
  }
  else{
    newNode->nodeBefore = queue.lastElement->nodeBefore;
    queue.lastElement->nodeBefore = newNode;
    queue.lastElement = newNode;
  }


  showCurrentQueue(queue, "The queue after enqueue");
}

void dequeue(struct Queue queue){
  if(queue.firstElement!=NULL){
    if(queue.firstElement->nodeBefore!=NULL){
      struct Node* toDequeue = queue.firstElement;  //we get the direction of the value we are about to dequeue
      queue.firstElement = queue.firstElement->nodeBefore;
      free(toDequeue);
    }
    else{
      struct Node* toDequeue = queue.firstElement;  //we get the direction of the value we are about to dequeue
      free(toDequeue);
      queue.firstElement = NULL;
      queue.lastElement = NULL;
    }
  }

  showCurrentQueue(queue, "The queue after dequeue");
}

void showCurrentQueue(struct Queue queue, char message[81]){
    int nullIncoming = 0;
    int times = 0;
    struct Node* currentNode = malloc(sizeof(struct Node));

    printf("%s\n", message);

    while(nullIncoming == 0 && (queue.firstElement != NULL)){
      if(times == 0){
        currentNode = queue.firstElement;
        printf("%d\n", currentNode->value);
      }
      else{
        if(currentNode->nodeBefore != NULL){
          currentNode = currentNode->nodeBefore;
          printf("%d\n", currentNode->value);
        }
        else{
          nullIncoming = 1;
        }
      }
      ++times;
    }

    printf("\n\n");
}
