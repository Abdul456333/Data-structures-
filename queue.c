#include<stdio.h>
void insertion(int queue[],int *front,int *rear,int max,int val){
    if(*rear==max-1){
        printf("Queue overflow");
    }
    else if(*front==-1 && *rear==-1){
        *front=0;
        *rear=0;
    }
    else{
        (*rear)++;
    }
    queue[*rear]=val;
}
void deletion(int queue[],int *front,int *rear){
    if(*front>*rear || *rear==-1){
        printf("Queue underflow");
    }
    else{
    (*front)++;
    }
}
void display(int queue[],int *front,int *rear){
    for(int i=*front;i<=*rear;i++){
        printf("%d",queue[i]);
    }
}
int main(){
    int max,num,val;
    int front=-1;
    int rear=-1;
    printf("enter the size of queue:");
    scanf("%d",&max);
    int queue[max];
    while(1){
        printf("enter 1 for insertion,2 for deletion and 3 for display");
        scanf("%d",&num);
        if(num==1){
            printf("enter the value you want to insert:");
            scanf("%d",&val);
            insertion(queue,&front,&rear,max,val);
        }
        if(num==2){
            deletion(queue,&front,&rear);
        }
        if(num==3){
            display(queue,&front,&rear);
        }
    }
}