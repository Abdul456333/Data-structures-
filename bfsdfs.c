#include<stdio.h>
void bfstraversal(int adj[][5],int visited[],int start,int max){
	int front=-1;
	int rear=-1;
	int queue[max];
	for(int k=0;k<max;k++){
		visited[k]=0;
	}
	queue[++rear]=start;
	++front;
	visited[start]=1;
	while(rear>=front){
		start=queue[front++];
		printf("%d->",start);
		for(int i=0;i<max;i++){
			if(adj[start][i]==1 && visited[i]==0){
				queue[++rear]=i;
				visited[i]=1;
			}
		}
	}	
}
void dfstraversal(int adj[][5],int visited[],int start,int max){
	int top=-1;
	int stack[max];
	for(int k=0;k<max;k++){
		visited[k]=0;
	}
	stack[++top]=start;
	visited[start]=1;
	while(top!=-1){
		start=stack[top--];
		printf("%d->",start);
		for(int i=0;i<max;i++){
			if(adj[start][i]==1 && visited[i]==0){
				stack[++top]=i;
				visited[i]=1;
			}
		}
	}
}
int main(){
	int method,max,num;
	printf("Enter the size:");
	scanf("%d",&max);
	int visited[max];
	int adj[max][max];
	do{
		printf("Enter 1 for entering the adjacency matrix\nEnter 2 for BFS Travel\nEnter 3 for DFS Travel");
		scanf("%d",&method);
		switch(method){
			case 1: printf("Enter the adjacency matrix values");
				for(int i=0;i<max;i++){
					for(int j=0;j<max;j++){
						scanf("%d",&adj[i][j]);
					}
				}
				break;
			case 2: printf("BFS Traversal:");
				bfstraversal(adj,visited,0,max);
				break;
			case 3: printf("DFS Traversal:");
				dfstraversal(adj,visited,0,max);
				break;
		}
	}while(method!=4);
}















