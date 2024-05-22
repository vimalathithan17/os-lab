#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int * chopsticks;
int num_phil;
void wait(int *sem){
  while(*sem<=0);
  (*sem)--;
}

void signal(int *sem){
  (*sem)++;
}

void thinking(int id){
  printf("Philosopher %d is thinking\n",id);
}

void eating(int id){
  printf("Philosopher %d is eating\n",id);
}

void Philosopher(int id){
  wait(&chopsticks[id]);
  wait(&chopsticks[(id+1)%num_phil]);
  eating(id);
  signal(&chopsticks[id]);
  signal(&chopsticks[(id+1)%num_phil]);
}

int main(){
  printf("Enter the number of philosophers:");
  scanf("%d",&num_phil);
  chopsticks=(int *)calloc(num_phil,sizeof(int));
  for(int i=0;i<num_phil;i++){
    chopsticks[i]=1;
    thinking(i);
  }
  for(int i=0;i<num_phil;i++){
    int id;
    printf("Enter the philosopher number who is hungry:");
    scanf("%d",&id);
    Philosopher(id);
  }
  printf("All philosophers have ate!");
  return 1;
}

