#include <iostream>
using namespace std;
#define MAX 100005
#define Nil -1

struct Node {int  p,l,r;};

Node T[MAX];
int N,D[MAX];

void print(int u) { 
    cout << "node" << u << " ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";

    if(T[u].p == Nil) cout << "root, ";
    else if(T[u].l == Nil) cout << "leaf, ";
    else cout << "internal node, ";
    cout << "[";

    for(int i = 0,c = T[u].l; c != Nil; i++,c = T[c].r) { 
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

//再帰的に深さを求める
int rec(int u,int p) { 
    D[u] = p;//深さを入れている
    if(T[u].r != Nil) rec(T[u].r,p);//右の兄弟に同じ深さを設定
    if(T[u].l != Nil) rec(T[u].l,p+1); //最も左の子に自分の深さ＋１を設定
}

int main() { 
    int i,j,d,v,c,l,r;
    cin >> N;
    for(i = 0; i < N; ++i) T[i].p = T[i].l = T[i].r = Nil;

    for(int i = 0; i < N; ++i) { 
        cin >> v >> d;
        for(int j = 0; j < N; ++j) { 
            cin >> c;
            if(j == 0) T[v].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }
    for(int i = 0; i < N; ++i) { 
        if(T[i].p == Nil) r = i;
    }
    rec(r,0);
    for(int i = 0; i < N; ++i) print(i);

    return 0;
}