#include <iostream>
#include <vector>
//using namespace std;
using ld = long double;

std::vector<ld> operator*(std::vector<ld> &a, std::vector<ld> &b) { 
    std::vector<ld> res(a.size());
    for(int i = 0; i < a.size(); ++i) res[i] = a[i]*b[i];
    return res;
}
/* 
vector<vector<int>> dot(vector<vector<int> a, vector<vector<int>> b) { 
    vector<vector<int>> res;
}
 */

std::vector<std::vector<ld>> dot(std::vector<std::vector<ld>> &a , std::vector<std::vector<ld>> &b) { 
    std::vector<std::vector<ld>> res(a.size(),std::vector<ld>(b.size()));
    ld num = 0;
    for(int i = 0; i < a.size(); ++i) { 
        for(int j = 0; j < b.size(); ++j) { 
            num += (a[i][j]*b[j][i]);
        }
        res[i].push_back(num);
        num = 0;
    }

    return res;
}

int  main() {  
    std::vector<std::vector<ld>> a = {{0,1,2},{1,2,3}};
    std::vector<std::vector<ld>> b = {{2,1},{2,1},{2,1}};
    std::vector<std::vector<ld>> c = dot(a,b);
    for(int i = 0; i < c.size(); ++i) {
        for(auto aa: c[i]) std::cout << aa << " ";
        std::cout << std::endl;
    }
}