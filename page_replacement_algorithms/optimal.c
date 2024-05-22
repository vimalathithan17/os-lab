#include<stdio.h>
#include<stdlib.h>
int predictPage(int *page, int * frames, int pageNumber, int pageIndex,int frame_size) {
  int result = -1, farthestPage = pageIndex;
  for (int i = 0; i < frame_size; i++) {
    int j;
    for (j = pageIndex; j < pageNumber; j++) {
      if (frames[i] == page[j]) {
        if (j > farthestPage) {
          farthestPage = j;
          result = i;
        }
        break;
      }
    }
    if (j == pageNumber){
      return i;
    }
  }
  if (result == -1){
    return 0;
  }
  else{
    return result;
  }
}
int searchPage(int key, int * frames,int size) {
  for (int i = 0; i <size; i++) {
// if the frame is found, return true
    if (frames[i] == key){
      return 1;
    }
  }
  return 0;
}
void find(int *pages, int pageNumber, int frameNumber) {
  int* frames = (int *)calloc(frameNumber, sizeof(int));
  int i=0;
  for(i;i<frameNumber;i++){
    frames[i]=-1;
  }
  int frame_size=0;
  int hit = 0;
  for (int i = 0; i < pageNumber; i++) {
    int page=pages[i];
    if (searchPage(page, frames,frameNumber)) {
    // if found, increment the hit counter
      hit++;
      continue;
    }
    if (frame_size < frameNumber){
      frames[frame_size++]=page;
    }
    else {
      int j = predictPage(pages, frames, pageNumber, i + 1,frameNumber);
      frames[j]=page;
    }
  }
  printf("Page hits: %d\n", hit);
  printf("Page misses:%d ", (pageNumber - hit));
}
void main() {
   int total_pages,capacity;
  printf("Enter the total number of pages:");
  scanf("%d",&total_pages);
  printf("Enter page frame size:");
  scanf("%d",&capacity);
  int * pages=(int *)malloc(sizeof(int)*total_pages);
  printf("Enter the sequence\n");//{1, 7, 8, 3, 0, 2, 0, 3, 5, 4, 0, 6, 1}
  int i=0;
  for(i;i<total_pages;i++){
    printf("Enter page %d:",i);
    scanf("%d",&pages[i]);
  }
  find(pages,total_pages,capacity);
}
