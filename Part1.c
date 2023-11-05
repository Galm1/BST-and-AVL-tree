// NAME: first last
// INFO1234: info

#include <stdio.h> // libraries 
#include <stdlib.h>

int arrayPredetermined[5] = {1,2,3,4,5}; //numbers given for project

struct Node // building the node for our BST and AVL tree. 
	        // AVl is just an organized BST so node structure is the same.
{
	int data;                 // need left and right for our child nodes to the left and right.
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

int max(int a, int b) {     // gives us the max of two ints
    return (a > b) ? a : b;
}

int height(struct Node* node) {  // gives us the hieght of a node to work with later
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct Node* node){ // calculates balance factor for node
	if (node == NULL){
		return 0;
	} return height(node->left) - height (node->right); // find differnce between height of left subtree and right subtree.
}

struct Node* leftRotate(struct Node* x){ // left rotate on node x for AVL
	struct Node* y=x->right;
	struct Node* z=y->left;
	y->left=x;
	x->right=z;
	
	x->height = max(height(x->left), height(x->right) + 1); // adjust height
	y->height = max(height(y->left), height(y->right) + 1);
	return y;

}

struct Node* rightRotate(struct Node* y){ // right rotate on node x for AVL
	struct Node* x=y->left;
	struct Node* z=x->right;
	x->right=y;
	y->left=z;
	
	y->height = max(height(y->left), height(y->right)) +1; //adjust height
	x->height = max(height(x->left), height(x->right)) +1;
	return x;
}


struct Node* insert(struct Node* node, int data){ // here is where we put the node in the AVL tree
	if (node == NULL){							  // recursive inserting and balancing using ratations
		return newNode(data);
	} else if (data > node->data){
		node->right = insert(node->right, data);
	} else return node;
	
	node->height = 1+max(height(node->left), height(node->right));
	
	int balance = getBalance(node);
	
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

void preOrder (struct Node* root){ // prints our the preorder form of the tree. So a string of numbers in preorder.
	if (root != NULL){
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}


int main(){
	
	printf("Predetermined numbers: "); // show user the numbers used
	for (int i = 0; i < 5; i++){
		printf("%d ", arrayPredetermined[i]);
	}
	
	int n =  sizeof(arrayPredetermined)/sizeof(arrayPredetermined[0]);
	struct Node* root = NULL;
	
	printf("\nBST in pre order: "); // print our BST
	for (int i=0; i<n; i++){
		root = insert(root, arrayPredetermined[i]);
		printf("%d ", arrayPredetermined[i]);
	}
	
	printf("\nAVL in pre order: "); // print our AVL
	preOrder(root);
	
	return 0;
	
	
}