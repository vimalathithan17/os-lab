#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int read_count=0;
int resource=1;
int rmutex=1;

void wait(int *sem){
  while(*sem<=0);
  (*sem)--;
}

void signal(int *sem){
  (*sem)++;
}

void reader(int id){
  wait(&rmutex);
  read_count++;
  if(read_count==1){
    wait(&resource);
  }
  signal(&rmutex);

  printf("Reader %d is reading\n",id);
  sleep(1);
  wait(&rmutex);
  read_count--;
  if(read_count==0){
    signal(&resource);
  }
  signal(&rmutex);
}

void writer(int id){
  wait(&resource);
  printf("Writer %d is wiriting\n",id);
  sleep(2);
  signal(&resource);
}

int main(){
  int rid;
  int wid;
  printf("Enter reader id:");
  scanf("%d",&rid);
  printf("Enter writed id:");
  scanf("%d",&wid);
  while(1){
    int choice;
    printf("Enter 1 for Reader,2 for Writer,3 to exit:");
    scanf("%d",&choice);
    int exit=0;
    switch(choice){
      case 1:
        reader(rid++);
        break;
      case 2:
        writer(wid++);
        break;
      case 3:
        exit=1;
        break;
      default:
        break;
    }
    if(exit){
      break;
    }
  }
}
