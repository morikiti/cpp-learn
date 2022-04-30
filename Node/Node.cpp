#include <iostream>
#include <string>
using namespace std;

/* ・それぞれのノードは、そのノードの親、左の子、右の子を指すポインタを
持つとします。これによって木の親子関係を保持します。そこで、Node構造体を
定義します。
・根をNode型ポインタroot、ノードが存在しないことを値を持たないNode型
のポインタNILによって表現します。
・与えられたキーを持つ要素を適切な位置に挿入するinsert関数を定義します。
新しい要素を保持するポインタzの位置を、xを使って根からノードをたどって
探していきます。xがNILに到達すると探索を終了します。yはxの親となって
おり、探索終了の後zの親をさし示すことになります。 
*/

struct Node { 
    int key;
    Node *parent,*left,*right;
};

Node *NIL,*root;

void insert(int key) { 
    Node *x,*y,*z;
    //初期化
    z = new Node;
    z->key = key;
    z->left = NIL;
    z->right = NIL;
    y = NIL;
    x = root;
    //rootから適切なⅠまで二分木までたどる
    while(x != NIL) { 
        y = x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    //新しい要素を配置する場所を決定
    z->parent = y;
    if(y == NIL) root = z; //もともと木が存在しなかった場合
    else if(z->key < y->key) y->left = z;
    else y->right = z;
}

//先行順巡回
void preorder(Node* node) { 
    if(node == NIL) return;
    cout << " " << node->key;
    if(node->left != NIL) preorder(node->left);
    if(node->right != NIL) preorder(node->right);
}
void print() {
  /* inorder(root);
  cout << endl;
   */preorder(root);
  cout << endl;
}

int main() { 
    int m,key;
    string cm;
    cin >> m;
    for(int i = 0; i < m; ++i) { 
        cin >> cm;
        if(cm[0] == 'i') { 
            cin >> key;
            insert(key);
        } else { 
            print();
        }
    }
    return 0;
}