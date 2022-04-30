#include<iostream>
#include<random>
#include<map>
#include<vector>

void Ruret() { 
    //非決定的な乱数生成器を生成
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand(0,1);
    std::map<int,std::string> company;
    company[0] = "Racon holdings";
    company[1] = "Landnet";

    int R = 0,L = 0;
    for(int i = 0; i < 101; ++i) { 
        int r = rand(mt);
        if(r == 0) R++;
        if(r == 1) L++; 
    }

    std::cout << R << " " << L << std::endl;
    if(R > L) std::cout << company[0] << std::endl;
    else std::cout << company[1] << std::endl;
}

int main() { 
    
    for(int i = 0;i < 3; ++i) { 
        Ruret();
    }

    
    return 0;
}