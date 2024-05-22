#include<stdio.h>
#include<unistd.h>
int customer=0;
int barber=0;
int seat=1;
int freeseat;

int waits(int v)
{
  v--;
  return v;
}
int signals(int v)
{
  v++;
  return v;
}
void barbers()
{
  while(customer)
  {
    printf("no of customer %d\n",customer);
    customer=waits(customer);
    if(customer>=0)
    {
      seat=waits(seat);
      freeseat++;
      printf("cut the hair\n");
      barber=signals(barber);
      seat=signals(seat);
    }
  }
}

void customers()
{ 
  seat=waits(seat);
  if(freeseat>0)
  {
    freeseat--;
    customer=signals(customer);
    seat=signals(seat);
    barber=waits(barber);
    printf("customer added\n");
    printf("no of customer %d\n",customer);
  }
  else
  {
    printf("customer declined\n");
    seat=signals(seat);
  }
}
int main()
{
  printf("Enter the number of seats:");
  scanf("%d",&freeseat);
  int choice=1;
  while(choice)
  {
    printf("do u wanna cut the hair(0/1):");
    scanf("%d",&choice);
    if(choice==1)
    {
      customers();
    }
  }
  barbers();
}
