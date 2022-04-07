#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

std::vector<std::string> split(std::string& input, char delimiter)
{
    std::istringstream stream(input);
    std::string field;
    std::vector<std::string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

class regression { 
    public:
        std::vector<std::vector<double>> data;
    private:
        void show();
             
};



int main() {
    std::string file;
    int H;
    cout << "何行？？" << endl;
    cin >> H;
    cout << "ファイル名は？" << endl;
    cin >> file;
    std::ifstream ifs(file);

    std::string line;
    std::vector<std::string> strvec;
    std::vector<int> d;
    std::vector<std::vector<double>> data(H);
    int i = 0;
    
    double x_ave = 0,y_ave = 0,sx=0,sxy =0,a=0,b=0;

    while (getline(ifs, line)) {
        
        strvec = split(line, ',');
        for (int j = 0; j < strvec.size(); ++j) { 
            data.at(i).push_back(stod(strvec.at(j)));
            //cout << data[i][j] << endl;
        }
       // data.at(i).push_back(d);
        ++i;
    }
    
    for(int i = 0; i < data.size(); ++i) { 
      //      cout << data[i][0] << " " ;
        x_ave += data[i][0];
        y_ave += data[i][1];
    }
    cout << "x_ave" << x_ave << " " << "y_ave: " << y_ave << endl;
    x_ave /= data.size();
    y_ave /= data.size();

    cout << "x_ave" << x_ave << " " << "y_ave: " << y_ave << endl;
    for(int i = 0; i < data.size(); ++i) { 
        cout << data[i][0] - x_ave << " " << data[i][1] - y_ave << endl;
        sx += pow((x_ave - data[i][0]),2);
        sxy += (y_ave - data[i][1])*(x_ave - data[i][0]);
    }
    sx /= data.size();
    sxy /= data.size();

    cout << "sx :" << sx << "sxy : " << sxy << endl;

    a = sxy/sx;

    b = y_ave - a*x_ave;

    double r1=0,r2=0,rr1=0,rr2=0;
    if(b < 0) { 
        cout << "回帰式： y =" << a << "x " << b << endl;
    }else { 
        cout << "回帰式： y =" << a << "x +" << b << endl;
    } 
    
    for(int i = 0; i < data.size(); ++i) { 
        r1 +=pow((data[i][1] - (a*data[i][0]+b)), 2);
        r2 += pow( (data[i][1] - y_ave) ,2);
    }

    for(int i = 0; i < data.size(); ++i) { 
        rr1 +=(data[i][1] - (a*data[i][0]+b))*(data[i][1] - (a*data[i][0]+b));
        rr2 += (data[i][1] - y_ave)*(data[i][1] - y_ave);
    }

    cout << "決定係数： " << 1 - r1/r2 << endl;
    cout << "相関係数： " << sqrt(1-r1/r2) << endl;

    //cout << 1 - rr1/rr2 << endl;
/* 
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
     cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
     cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl; cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl; */
}