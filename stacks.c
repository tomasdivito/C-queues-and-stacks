#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* next;
    int value;
};

void Add(struct Node**, int);
void Remove(struct Node**);
int print_stack(struct Node**);

int main(){
    struct Node* stack = NULL;
    int stackLength, i;

    for(i = 0; i < 2024; i += 64){
        Add(&stack, i);
    }
    printf("\n\nloop test\n\n");
    stackLength = print_stack(&stack);
    printf("(Current length of the stack: %d)", stackLength);
    printf("\n\nend of loop test\n\n");

    for(i = 0; i < 36; i++){
        Remove(&stack);
    }
    return 0;
}

void Add(struct Node** stack, int val){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = *stack;
    *stack = newNode;

    //print current stack
    printf("New value inserted in stack: %d\n", (**stack).value);
}

void Remove(struct Node** stack){
    if(*stack != NULL){
        if((*stack)->next != NULL){
            struct Node* deleted = *stack;
            *stack = (*stack)->next;
            free(deleted);
        }
        else{
            struct Node* deleted = *stack;
            free(deleted);
            *stack = NULL;
        }
    }

    //print current stack
    if(*stack!=NULL){
        printf("Value deleted from stack. current stack last value: %d\n", (**stack).value);
    }
    else{
        printf("Last value deleted or empty stack\n");
    }
}

int print_stack(struct Node** stack){
    int null_incoming = 0;
    int time = 0;
    struct Node* current;

    while(null_incoming != 1){
        if(*stack != NULL && time == 0){
            current = *stack;
            printf("%d\n", current->value);
        }
        else{
            if(current->next!=NULL){
                current = current->next;
                printf("%d\n", current->value);
            }
            else{
                null_incoming = 1;
            }
        }
        time++;
    }

    return time-1;
}
