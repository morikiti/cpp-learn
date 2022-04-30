#include<iostream>
#include<string>
using namespace std;

#define N 4

class Calc {
    double a[N][N+1];

    //各種変数
    double d;//ダミー

    public:
        //連日方程式を解く
        void calcGaussElimination();
};

void Calc::calcGaussElimination() { 
    static double a[N][N+1] = {
        { 1.0, -2.0,  3.0, -4.0,  5.0},
        {-2.0,  5.0,  8.0, -3.0,  9.0},
        { 5.0,  4.0,  7.0,  1.0, -1.0},
        { 9.0,  7.0,  3.0,  5.0,  4.0}
    };

    //元の連日方程式を出力
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { 
           printf("%+fx%d ", a[i][j], j + 1);
        }
        printf("= %+f\n", a[i][N]);
    }

    //前進消去
    for(int k = 0; k < N-1; ++k) { 
        for(int i = k+1; i < N; ++i) { 
            d = a[i][k]/a[k][k];
            for(int j = k+1; j <= N; ++j) { 
                a[i][j] -= a[k][j]*d;
            }
        }
    }
     // 後退代入
    for (int i = N - 1; i >= 0; i--) {
        d = a[i][N];
        for (int j = i + 1; j < N; j++) { 
            d -= a[i][j] * a[j][N];
        }
        a[i][N] = d / a[i][i];
    }

    //結果出力
    for(int i = 0; i < N; ++i) { 
        printf("x%d = %f\n", i + 1, a[i][N]);
    }
}

int main() {
    try {
        // 計算クラスインスタンス化
        Calc objCalc;

        // 連立方程式を解く（ガウスの消去法）
        objCalc.calcGaussElimination();
    } catch (...) {
        cout << "例外発生！" << endl;
        return -1;
    }

    // 正常終了
    return 0;
}
