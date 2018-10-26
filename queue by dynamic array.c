#include<stdio.h>
struct queueadt
{
int front;
int rear;
int capacity;
int* array;
};
struct queueadt* createqueue(int);
int isfullqueue(struct queueadt*);
int isemptyqueue(struct queueadt*);
int queuecapacity(struct queueadt*);
void doublequeue(struct queueadt*);
void halfqueue(struct queueadt*);
void enqueue(struct queueadt*,int);
void dequeue(struct queueadt*);
int queuesize(struct queueadt*);
int main()
{
       int capacity;
    printf("enter capacity");
    scanf("%d",&capacity);
    struct queueadt *q;
    q=createqueue(capacity);
    enqueue(q,10);
    printf("\ncapacity=%d,front=%d,rear=%d",queuecapacity(q),q->front,q->rear);
     enqueue(q,4);
    printf("\ncapacity=%d,front=%d,rear=%d",queuecapacity(q),q->front,q->rear);
     enqueue(q,8);
    printf("\ncapacity=%d,front=%d,rear=%d",queuecapacity(q),q->front,q->rear);
     enqueue(q,7);
    printf("\ncapacity=%d,front=%d,rear=%d",queuecapacity(q),q->front,q->rear);
     enqueue(q,5);
    printf("\ncapacity=%d,front=%d,rear=%d",queuecapacity(q),q->front,q->rear);
       enqueue(q,5);
    printf("\ncapacity=%d,front=%d,rear=%d",queuecapacity(q),q->front,q->rear);
    dequeue(q);
    printf("\ncapacity=%d,front=%d,rear=%d",queuecapacity(q),q->front,q->rear);
    dequeue(q);
    printf("\ncapacity=%d,front=%d,rear=%d",queuecapacity(q),q->front,q->rear);
    return 0;
}
struct queueadt* createqueue(int capacity)
{
struct queueadt *q;
q=(struct queueadt*)malloc(sizeof(struct queueadt));
q->front=-1;
q->rear=-1;
q->capacity=capacity;
q->array=(int*)malloc(sizeof(int)*(capacity));
return(q);
}
int isemptyqueue(struct queueadt *q)
{
if(q->front==-1)
return(1);
else
return(0);
}
int isfullqueue(struct queueadt *q)
{
if((q->rear+1)%q->capacity==q->front)
return(1);
else
return(0);
}
int queuecapacity(struct queueadt *q)
{
int cap;
cap=q->capacity;
return(cap);
}
void doublequeue(struct queueadt *q)
{
int *temp;
int i=0,p=0;
q->capacity=q->capacity*2;
temp=(int*)malloc(sizeof(int)*q->capacity);
for(i=0;i<q->capacity/2;i++)
{
if(q->front<q->capacity/2)
{
temp[i]=q->array[q->front];
q->front=q->front+1;
}
else
{
    if(q->front==q->capacity/2)
        temp[i]=q->array[q->front];
    else{
    q->front=(p++==0?0:q->front);
temp[i]=q->array[q->front];
q->front=q->front+1;}
}
}
free(q->array);
q->array=temp;
q->front=0;
q->rear=i;
free(q->array);
q->array=temp;
printf("\n capacity=%d",q->capacity);}
void halfqueue(struct queueadt* q)
{
  int* temp;
  int i,p=0;
  if(q->capacity!=1){
  q->capacity=q->capacity/2;
  temp=(int*)malloc(sizeof(int)*q->capacity);
  for(i=0;i<q->capacity;i++)
    {
        if(q->front<q->capacity){
  temp[i]=q->array[q->front];
  q->front++;}
  else
  {
      q->front=(p++==0?0:q->front);
      temp[i]=q->array[q->front];
      q->front=q->front+1;
  }
  free(q->array);
  q->array=temp;
  q->front=0;
  q->rear=i+1;
    }
  }
}
void enqueue(struct queueadt* q,int data)
{
    if(q->front==-1&&q->rear==-1)
    {
        q->front=0;
        q->rear=0;
        q->array[q->rear]=data;
    }
    else
    {
        if(q->rear<q->capacity-1)
        {
                q->rear=q->rear+1;
                q->array[q->rear]=data;
        }
                else
                {
                 //if(isfullqueue(q)){
                   // doublequeue(q);
                    //q->rear++;
                    //q->rear=data;}

                  doublequeue(q);
                   q->array[q->rear]=data;
                  printf("0");
                }
    }
}
void dequeue(struct queueadt* q)
{
    int k=0;
    if(isemptyqueue(q))
    {
    printf("underflow\n");
    }
    else
        {
        if(q->front<q->capacity-1)
        q->front=q->front+1;
        else
        {
            if(q->front==q->capacity-1)
            q->front=0;
        }
        }
        k=queuesize(q);
if(k==q->capacity/2)
    halfqueue(q);
}
int queuesize(struct queueadt* q)
{
    int k=0;
    k=((q->capacity-q->front+q->rear+1)%q->capacity);
    return(k);
}
