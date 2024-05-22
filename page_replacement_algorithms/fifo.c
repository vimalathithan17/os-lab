#include<stdio.h>
#include<stdlib.h>

typedef struct hashset{
  int max_len;
  int * arr;
  int size;
}hset;

typedef struct Queue{
  int front,rear;
  int *arr;
  int size;
}Q;

void addQ(Q * q,int data){
  if(q->front==-1){
    q->arr[++(q->front)]=data;
    q->rear++;
  }
  else{
    q->rear=(q->rear+1)%q->size;
    q->arr[q->rear]=data;
  }
}
void printarr(int *arr,int size){
  int i=0;
  printf("[");
  for(i;i<size;i++){
    printf("%d",arr[i]);
    if(i!=size-1){
      printf(",");
    }
  }
  printf("]");
}
int rm_firstQ(Q* q){
  int val =q->arr[q->front];
  q->front=(q->front+1)%q->size;
  return val;
}
void main() {
  int total_pages,capacity;
  printf("Enter the total number of pages:");
  scanf("%d",&total_pages);
  printf("Enter page frame size:");
  scanf("%d",&capacity);
  int * pages=(int *)malloc(sizeof(int)*total_pages);
  int i;
  printf("Enter the sequence\n");//{1, 3, 0, 3, 5, 6, 3}
  for(i=0;i<total_pages;i++){
    printf("Enter page %d:",i);
    scanf("%d",&pages[i]);
  }
  hset set;
  set.max_len=total_pages;
  set.arr=(int *)calloc(total_pages,sizeof(int));
  set.size=0;

  for(i=0;i<total_pages;i++){
    set.arr[i]=-1;
  }

  Q queue;
  queue.front=-1;
  queue.rear=-1;
  queue.arr=(int *)calloc(capacity,sizeof(int));
  queue.size=capacity;
  
  //int* queue=(int*)calloc(capacity,sizeof(int));
  /*for(i=0;i<capacity;i++){
    queue.arr[i]=-1;
  }*/
  int PF = 0;
  for (int i=0; i<total_pages; i++){
    int page=pages[i];
    if (set.size < queue.size){

     if (set.arr[page%set.max_len]==-1){
        set.arr[page%set.max_len]=page;
        set.size+=1;
        PF++;
        addQ(&queue,page);
        //printf("pg:%d,",page);
        //printarr(queue.arr,queue.size);
        //printarr(set.arr,set.max_len);
        printf("fault!");
      }
    }
    else {
      if (set.arr[page%set.max_len]==-1)
      {
        int val = rm_firstQ(&queue);
       // printf("val%d",val);
        set.arr[val%set.max_len]=-1;
        set.arr[page%set.max_len]=page;
        addQ(&queue,page);
        PF++;
        //printf("pg:%d,",page);
        //printarr(queue.arr,queue.size);
        //printarr(set.arr,set.max_len);
        printf("fault!");
      }
      else{
        printf("hit!");
      }
    }
        printf("pg:%d,",page);
        printarr(queue.arr,queue.size);
        //printarr(set.arr,set.max_len);
        printf("\n");
  }
  printf("The total number of page faults are:%d ",PF);
}

