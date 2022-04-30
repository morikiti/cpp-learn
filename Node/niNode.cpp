#include <iostream>
using namespace std;
#define MAX 100005
#define nil -1

struct Node {int  p,l,r;};

Node T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int u, int d) { 
    if(u == nil ) return;
    D[u] = d;
    setDepth(T[u].l,d+1);
    setDepth(T[u].r, d+1);
}

int setHeight(int u) { 
    int h1 = 0,h2 = 0;
    if(T[u].l != nil) h1 = setHeight(T[u].l) + 1;
    if(T[u].r != nil) h2 = setHeight(T[u].r)+1;
    return H[u] = (h1 > h2 ? h1 : h2);
}

//節点Uの兄弟を返す
int getSibling(int u) { 
    if(T[u].p == nil) return nil;
    if(T[T[u].p].l != u && T[T[u].p].l != nil) return T[T[u].p].l;
    if(T[T[u].p].r != u && T[T[u].p].r != nil) return T[T[u].p].r;
    return nil;
}

void print(int u) { 
    printf("node %d: ", u);
    printf("parent = %d, ",T[u].p);
    printf("sibling = %d,",getSibling(u));

    int deg = 0;
    if(T[u].l != nil) deg++;
    if(T[u].r != nil) deg++;
    printf("degreee= %d ,",deg);
    printf("depth = %d, ",D[u]);
    printf("height = %d ,",H[u]);

    if(T[u].p == nil) { 
        printf("root\n");
    } else if( T[u].l == nil && T[u].r == nil) { 
        printf("leaf\n");
    } else { 
        printf("internal node\n");
    }
}


int main() { 
    int v,l,r,root = 0;
    cin >> n;
    for(int i = 0; i < n; ++i ) T[i].p = nil;

    for(int i = 0; i < n; ++i) { 
        cin >> v >> l >> r;
        T[v].l = l;
        T[v].r = r;
        if(l != nil) T[l].p = v;
        if(r != nil) T[r].p = v;
    }

    for(int i = 0; i < n; ++i) if(T[i].p == nil) root = i;

    setDepth(root,0);
    setHeight(root);

    for(int i = 0; i < n; ++i) print(i);

    return 0;
}