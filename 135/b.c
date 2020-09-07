#include <stdio.h>

void bubbleSort(int numbers[], int array_size)
{
  int i, j, temp;

  for (i = 0; i < (array_size - 1); i++) {
    for (j = (array_size - 1); j > i; j--) {
      if (numbers[j-1] > numbers[j]) {
        temp = numbers[j-1];
        numbers[j-1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}



int main(){
    int N;
    int data[52];
    scanf("%d",&N);
    int i,j;
    int count = 0;
    int data2[52];
    for(i=0;i<N;i++){
        scanf("%d",&data[i]);
        data2[i] = data[i];
        
    }
    
    bubbleSort(data,N);

    for(int i=0;i<N;i++){
        
        if(data[i]!=data2[i])count++;
    }
    
       if(count==0 || count==2){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}