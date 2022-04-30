#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
  double matrix1[3][3]={
                        1,2,3,
                        2,3,4,
                        3,4,5,
  };
  double matrix2[3][3]={
                        1,1,1,
                        1,1,1,
                        1,1,1,
  };
  double result[3][3];
  int i,j,k;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      result[i][j]=0.0;
    }
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      for(k=0;k<3;k++){
        result[i][j]+=matrix1[i][k]*matrix2[k][j];
      }
    }
  }

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("%lf ",result[i][j]);
    }
    printf("\n");
  }
  return 0;
}
