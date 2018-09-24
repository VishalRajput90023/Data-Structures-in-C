/* Binary Tree Construction of type:
                     1
                   /   \
                 2       3
               /
             4
*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node* left;
struct Node* right;
};
struct Node* newNode(int);
void printBinaryTree(struct Node*);
int main()
{
    struct  Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = newNode(2);
    root->right=newNode(3);
    root->left->left = newNode(4);
    printBinaryTree(root);
    return 0;
}
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void printBinaryTree(struct Node* root){
     printf("          ");
    printf("%d\n        ",root->data);
    printf("/   \\");
    printf("\n       ");
    printf("%d     ",root->left->data);
    printf("%d\n      ",root->right->data);
     printf("/");
    printf("\n     ");
    printf("%d\n",root->left->left->data);
}





