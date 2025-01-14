#include <stdio.h>
#include <stdlib.h>
 
// Data structure to store a binary tree node
struct Node
{
    char key;
    struct Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
struct Node* newNode(char key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
 
    return node;
}
 
// Recursive function to perform inorder traversal on a given binary tree
void inorderTraversal(struct Node* root)
{
    if (root == NULL) {
        return;
    }
 
    inorderTraversal(root->left);
    printf("%c ", root->key);
    inorderTraversal(root->right);
}
 
// Recursive function to perform preorder traversal on a given binary tree
void preorderTraversal(struct Node* root)
{
    if (root == NULL) {
        return;
    }
 
    printf("%c ", root->key);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
 
// Recursive function to construct a binary tree from a given
// inorder and preorder sequence
struct Node* construct(int inorder[], int start, int end,
                int preorder[], int *pIndex)
{
    // base case
    if (start > end) {
        return NULL;
    }
 
    // The next element in `preorder[]` will be the root node of
    // subtree formed by sequence represented by `inorder[start, end]`
    struct Node* node = newNode(preorder[(*pIndex)++]);
 
    // search the root node index in sequence `inorder[]` to determine the
    // left and right subtree boundary
    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == node->key) {
            break;
        }
    }
 
    // recursively construct the left subtree
    node->left = construct(inorder, start, i - 1, preorder, pIndex);
 
    // recursively construct the right subtree
    node->right = construct(inorder, i + 1, end, preorder, pIndex);
 
    // return current node
    return node;
}
 
// Construct a binary tree from inorder and preorder traversals.
// This function assumes that the input is valid, i.e., given
// inorder and preorder sequence forms a binary tree.
struct Node* constructTree(int inorder[], int preorder[], int n)
{
    // `pIndex` stores the index of the next unprocessed node in a preorder sequence;
    // root node is present at index 0 in a preorder sequence
    int pIndex = 0;
 
    return construct(inorder, 0, n - 1, preorder, &pIndex);
}


void imprimir_pos_ordem(struct Node* no){
    if (no != NULL){
        imprimir_pos_ordem(no->left);
        imprimir_pos_ordem(no->right);
        printf("%d ", no->key);
    }
}


void le_entrada (char lista[] , int n) {
	for (int i = 0; i < n ; i++)
		scanf(" %c", &lista[i]);
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /       / \
         /       /   \
        4       5     6
               / \
              /   \
             7     8
    */
 
    int inorder[] = { 4, 2, 1, 7, 5, 8, 3, 6 };
    int preorder[] = { 1, 2, 4, 3, 5, 7, 8, 6 };
    int n = sizeof(inorder)/sizeof(inorder[0]);
 
    struct Node* root = constructTree(inorder, preorder, n);

    imprimir_pos_ordem(root);
    // traverse the constructed tree
    printf("The inorder traversal is "); inorderTraversal(root);
    printf("\nThe preorder traversal is "); preorderTraversal(root);
 
    return 0;
}