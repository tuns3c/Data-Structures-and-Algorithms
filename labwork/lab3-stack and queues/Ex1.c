#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[20];
    int quantity;
    int price;
} Item;

typedef struct node {
    Item data;
    struct node *next;
} Node;

typedef struct {
    Node *first, *last;
} Queue;

void init(Queue *q) {
    q->first = q->last = NULL;
}

int is_empty(Queue *q) {
    return (q->first == NULL);
}

void enqueue(Queue *q, Item x) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (is_empty(q)) {
        q->first = q->last = temp;
    } else {
        q->last->next = temp;
        q->last = temp;
    }
}

Node *dequeue(Queue *q) {
    if (is_empty(q))
        return NULL;
    Node *temp = q->first;
    q->first = q->first->next;
    if (q->first == NULL)
        q->last = NULL;
    return temp;
}

void display(Queue *q) {
    Node *temp = q->first;
    printf("%-10s%-10s%-10s\n", "Item", "Quantity", "Price");
    while (temp != NULL) {
        printf("%-10s%-10d%-10d\n", temp->data.name, temp->data.quantity, temp->data.price);
        temp = temp->next;
    }
}

void purchase(Queue *q, char *name, int quantity) {
    Node *temp = q->first;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            if (temp->data.quantity >= quantity) {
                temp->data.quantity -= quantity;
                printf("Purchase successful! Remaining quantity of %s: %d\n", name, temp->data.quantity);
            } else {
                printf("Warning! The number of %s in stock is not enough.\n", name);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Item not found.\n");
}

int main() {
    Queue q;
    init(&q);
    Item item1 = {"camera", 10, 20};
    Item item2 = {"laptop", 5, 30};
    Item item3 = {"book", 100, 5};
    enqueue(&q, item1);
    enqueue(&q, item2);
    enqueue(&q, item3);

    display(&q);

    purchase(&q, "camera", 6);
    purchase(&q, "laptop", 2);
    purchase(&q, "book", 101);

    printf("\nAfter purchase:\n");
    display(&q);
    return 0;
}