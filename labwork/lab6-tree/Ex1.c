#include <stdio.h>
#include <stdlib.h>

void init(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }
}

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node* new_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

struct Node* tree(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct Node *root = new_node(arr[mid]);
    root->left = tree(arr, start, mid - 1);
    root->right = tree(arr, mid + 1, end);
    return root;
}
void display(struct Node* node) {
    if (node == NULL)
        return;
    display(node->left);
    printf("%d ", node->data);
    display(node->right);
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
       return root;

    if (root->data < value)
       return search(root->right, value);

    return search(root->left, value);
}
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return new_node(data);

    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}
struct Node * min_node(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
struct Node* remove_node(struct Node* root, int data) {
    if (root == NULL) 
    return root;

    if (data < root->data)
        root->left = remove_node(root->left, data);
    else if (data > root->data)
        root->right = remove_node(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = min_node(root->right);
        root->data = temp->data;
        root->right = remove_node(root->right, temp->data);
    }
    return root;
}
int main() {
    int n = 10;
    int arr[n];
    init(arr, n);

    struct Node* root = tree(arr, 0, n-1);

    display(root);
    printf("\n");

    int value = 23;
    printf("\nwhen input the value 15 to found in this tree\n");
    struct Node* found = search(root, value);
    if (found != NULL) {
        printf("Found value: %d\n", found->data);
    } else {
        printf("Value not found in tree.\n");
    }

    value = 15;
    root = insert(root, value);
    printf("\nAfter inserting %d:\n", value);
    display(root);
    printf("\n");

    value = 41;
    root = remove_node(root, value);
    printf("\nAfter deleting %d:\n", value);
    display(root);
    printf("\n");

    return 0;
}
