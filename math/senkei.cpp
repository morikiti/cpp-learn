#include <stdio.h>
 
int main(void){
 
  int i, j, k, term;
 
  /* 行列 */
  int a[2][2], b[2][3], c[2][3];
 
  printf("\n1つ目の行列 A を入力\n");
  for(i=0;i<2;++i){
    for(j=0;j<2;++j){
      printf("A[%d][%d] = ", i+1, j+1);
      scanf("%d", &a[i][j]);
    }
  }
 
  printf("\n2つ目の行列 B を入力\n");
  for(i=0;i<2;++i){
    for(j=0;j<3;++j){
      printf("B[%d][%d] = ", i+1, j+1);
      scanf("%d", &b[i][j]);
    }
  }
 
  /* 行列の積（掛け算） */
  for(i=0;i<2;++i){
    for(j=0;j<3;++j){
      c[i][j] = a[i][j] * b[i][j];
 
      // 行列の項を計算
      for(i=0;i<2;i++){
        for(j=0;j<3;j++){
          term = 0;
          for(k=0;k<2;k++)
            term = term + a[i][k]*b[k][j];
          c[i][j] = term;
        }
      }
 
    }
  }
 
  printf("\n行列 C = A x B\n");
  for(i=0;i<2;++i){
    for(j=0;j<3;++j){
      printf("C[%d][%d] = %d\n", i+1, j+1, c[i][j]);
    }
  }
 
  return 0;
}
