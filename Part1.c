#include <stdio.h>
#include <stdlib.h>

int arrayPD[5] = {1,2,3,4,5};

struct Node 
{
	int data;
	struct Node* left;
	struct Node* right;
	int height;
};

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalence(struct Node* node){
	if (node == NULL){
		return 0;
	} return height(node->left) - height (node->right);
}

struct Node* insert(struct Node* node, int data){
	if (node == NULL){
		return newNode(data);
	} else if (data > node->data){
		node->right = insert(node->right, data);
	} else return node;
}




int main(){
	
	
	for (int i = 0; i < 5; i++){
		printf("%d", arrayPD[i]);
	}
	
	
	
}