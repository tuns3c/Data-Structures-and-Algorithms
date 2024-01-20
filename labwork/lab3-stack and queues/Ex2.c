#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Website {
    char url[100];
    char title[100];
} website;

typedef struct Stack {
    int top;
    unsigned capacity;
    website* array;
} Stack;

Stack* init(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (website*) malloc(stack->capacity * sizeof(website));
    return stack;
}

int is_full(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, website website) {
    if (is_full(stack))
        return;
    stack->array[++stack->top] = website;
}

website pop(Stack* stack) {
    if (is_empty(stack)) {
        website website;
        strcpy(website.url, "");
        strcpy(website.title, "");
        return website;
    }
    return stack->array[stack->top--];
}

void display(Stack* stack, char* stackName) {
    printf("\n%s:\n", stackName);
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%s - %s\n", stack->array[i].url, stack->array[i].title);
    }
}

int main() {
    Stack* backward = init(100);
    Stack* forward = init(100);

    website website1;
    strcpy(website1.url, "https://usth.edu.vn");
    strcpy(website1.title, "University of Science and Technology of Ha Noi");
    push(backward, website1);

    website website2;
    strcpy(website2.url, "https://moodle.usth.edu.vn");
    strcpy(website2.title, "USTH Moodle");
    push(backward, website2);

    website website3;
    strcpy(website3.url, "https://calendar.google.com");
    strcpy(website3.title, "Time Table");
    push(backward, website3);

    printf("After pushing 3 websites to the Backward stack:\n");
    display(backward, "Backward");

    push(forward, pop(backward));

    printf("\nAfter popping website from the Backward stack and pushing it to the Forward stack:\n");
    display(forward, "Forward");
    display(backward, "Backward");
    

    return 0;
}
