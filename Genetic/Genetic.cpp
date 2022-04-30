#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct { 
    double score;
    vector<int> gen;
}biont;

int ScoreCalc(vector<int>& gen) { //評価関数
    int score = 0;
    for(int i = 0; i < (int)gen.size(); ++i) { 
        score += gen[i];
    }
    return score;
}

bool ComparisonFunc(const biont &a, const biont &b) { //比較関数
    return a.score>b.score;
}

int main() { 
    srand((unsigned)time(NULL));
    //変数初期化
    int len = 100;
    int biont_number = 100;
    int parents_numver = biont_number/2;
    int generation = 1000;

    vector<biont> parents(len);
    vector<biont> children(len);
    
    for(int i = 0; i < biont_number; ++i) { 
        parents[i].gen.resize(len);
        children[i].gen.resize(len);
    }

    //初期遺伝子作成
    for(int i = 0; i < biont_number; ++i) { 
        for(int j = 0; j < len; ++j) { 
            parents[i].gen[i] = 0;
        }
    }
    //メイン
    while(generation--) { 
        //スコア計算
        for(int i = 0; i < biont_number; ++i) { 
            parents[i].score = ScoreCalc(parents[i].gen);
        }
        //ソート
        sort(parents.begin(),parents.end(),ComparisonFunc);
        //優れた親を保存
        for(int i = 0; i < parents_numver; ++i) { 
            children[i].gen = parents[i].gen;
        }
        //優れた親から子を生成
        for(int i = parents_numver; i < biont_number; i += 2) { 
            //二点交叉
            int p_i = i - parents_numver;
            children[i].gen = parents[p_i].gen;
            children[i+1].gen = parents[p_i].gen;

            int left = rand() % len, right = rand()%len;
            if(left > right)swap(left,right);

            for(int j = left; j <= right; ++j) { 
                children[i].gen[j] = parents[p_i+1].gen[j];
                children[i+1].gen[j] = parents[p_i].gen[j];
            } 
        }
        //突然変異
        for(int i = parents_numver; i < biont_number; ++i) { 
            for(int j = 0; j < len; ++j) { 
                if(rand()% len == 0) { 
                    if(children[i].gen[j] == 0) { 
                        children[i].gen[j] = 1;
                    } else { 
                        children[i].gen[j] = 0;
                    }
                }
            }
        }
        //世代交代
        for (int i = 0; i < biont_number; ++i) { 
            parents[i].gen = children[i].gen;
        }

        //最終スコア
        cout << parents[0].score << " ";
        for(int i = 0; i < len; ++i) { 
            cout << parents[0].gen[i];
        }
    }

}

