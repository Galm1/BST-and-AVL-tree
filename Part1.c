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

struct Node* leftRotate(struct Node* x){
	struct Node* y=x->right;
	struct Node* z=y->left;
	y->left=x;
	x->right=z;
	
	x->height = max(height(x->left), height(x->right) + 1);
	x->height = max(height(y->left), height(y->right) + 1);
	return y;

}

struct Node* rightRotate(struct Node* y){
	struct Node* x=y->left;
	struct Node* z=x->right;
	x->right=y;
	y->left=z;
	
	y->height = max(height(y->left), height(y->right)) +1;
	x->height = max(height(x->left), height(x->right)) +1;
	return x;
}


struct Node* insert(struct Node* node, int data){
	if (node == NULL){
		return newNode(data);
	} else if (data > node->data){
		node->right = insert(node->right, data);
	} else return node;
	
	node->height = 1+max(height(node->left), height(node->right));
	
	int balance = getBalence(node);
	
	if (balance > 1 && data < node->left->data){ //left left
		return rightRotate(node);
	} 
	
	if (balance < -1 && data > node->right->data){ //right right
		return leftRotate(node);
	}
	
	if (balance > 1 && data > node->left->data){ //left right
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	
	if (balance < -1 && data < node->right->data){ //right left
		node->right - rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

void preOrder (struct Node* root){
	if (root != NULL){
		printf("%d", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}


int main(){
	
	
	for (int i = 0; i < 5; i++){
		printf("%d", arrayPD[i]);
	}
	
	
	
}