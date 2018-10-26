#include<stdio.h>
struct stack
{
int data;
struct stack* next;
};
struct stack* top=NULL;
struct stack* push(struct stack*,int);
void display(struct stack*);
int main()
{
int n;
printf("enter -1 to end the stack\n");
printf("enter no.\n");
scanf("%d",&n);
//struct stack* top;
top=(struct stack*)malloc(sizeof(struct stack));
top->next=NULL;
top->data=n;
while(1){
top=push(top,n);
scanf("%d",&n);
if(n==-1)
break;}

display(top);
return 0;
}
struct stack* push(struct stack* top,int n)
{
struct stack *ptr;
    ptr=top;
top=(struct stack*)malloc(sizeof(struct stack));
top->data=n;
top->next=ptr;
return (top);
//printf("%d",top->data);
}
void display(struct stack* top)
{
    struct stack *ptr;
    while(top->next!=NULL)
        {
    ptr=top;
    printf("%d",ptr->data);
    top=ptr->next;
        }
}
