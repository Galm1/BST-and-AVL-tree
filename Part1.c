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
	node->height = 0;
	return (node);
}





int main(){
	
	
	for (int i = 0; i < 5; i++){
		printf("%d", arrayPD[i]);
	}
	
	
	
}