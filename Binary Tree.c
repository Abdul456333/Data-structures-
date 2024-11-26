#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* createNode(int val){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct Node* insert(struct Node* node,int val){
	if(node==NULL){
		return createNode(val);
	}
	if(val<node->data){
		node->left=insert(node->left,val);
	}
	else if(val>node->data){
		node->right=insert(node->right,val);
	
	}
	return node;
}
void preorder(struct Node* root){
	if(root!=NULL){
		preorder(root->left);
		printf("%d ",root->data);
		preorder(root->right);
	}
}
void inorder(struct Node* root){
	if(root!=NULL){
		printf("%d ",root->data);
		inorder(root->left);
		inorder(root->right);
	}	
}
void postorder(struct Node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int main(){
	int method,num;
	struct Node* root=NULL;
	while(1){
		printf("Print 1 for insert\n2 for preorder traversal\n3 for inorder traversal\n4 for postorder traversal\n");
		scanf("%d",&method);
		switch(method){
			case 1: printf("Enter the number you want to add in tree");
				scanf("%d",&num);
				root=insert(root,num);
				printf("\n");
				break;
			case 2: printf("Preorder:\n");
				preorder(root);
				printf("\n");
				break;
			case 3: printf("Inorder:\n");
				inorder(root);
				printf("\n");
				break;
			case 4: printf("Postorder:\n");
				postorder(root);
				printf("\n");
				break;
		}
	}

}			