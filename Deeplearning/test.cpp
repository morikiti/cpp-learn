#include <bits/stdc++.h>
using namespace std;
using ld = long double;


class Activation {
   std::vector<std::vector<ld>> sigmod(std::vector<std::vector<ld>> &x) { 
       std::vector<std::vector<ld>> res;
       for(auto batch : x) { 
           std::vector<ld> t;
           for(auto i : batch) { 
               t.push_back(1.0/ (1.0+exp(-i)));
           }
           res.push_back(t);
       }
       return res;
   }
};


int main() {
    
    return 0;
}
