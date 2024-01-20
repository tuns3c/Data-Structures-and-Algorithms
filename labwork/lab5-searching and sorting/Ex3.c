#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* create_stack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int is_full(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (is_full(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (is_empty(stack))
        return -1;
    return stack->array[stack->top--];
}

void sort_insert(struct Stack* stack, int item) {
    if (is_empty(stack) || item > stack->array[stack->top]) {
        push(stack, item);
        return;
    }

    int temp = pop(stack);
    sort_insert(stack, item);

    push(stack, temp);
}

void sort_stack(struct Stack* stack) {
    if (!is_empty(stack)) {
        int temp = pop(stack);
        sort_stack(stack);
        sort_insert(stack, temp);
    }
}

void print_stack(struct Stack* stack) {
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->array[i]);
    printf("\n");
}

int main() {
    struct Stack* stack = create_stack(100);
    push(stack, 30);
    push(stack, 15);
    push(stack, 28);
    push(stack, 4);
    push(stack, 63);
    push(stack, 48);
    push(stack, 56);
    push(stack, 89);

    printf("Stack elements before sorting:\n");
    print_stack(stack);

    sort_stack(stack);

    printf("\nStack elements after sorting:\n");
    print_stack(stack);

    return 0;
}
