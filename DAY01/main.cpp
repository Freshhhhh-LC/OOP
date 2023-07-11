#include <iostream>
#include "Date.hpp"
#include "Date.cpp"

using namespace std;

void Judge(Date& date){
    if(date.IsValidDate()){
        cout << "Valid Date!" << endl;
    }
    else{
        cout << "InValid Date!" << endl;
    }
}
int main(){
    Date D1;
    unsigned int y1;
    unsigned int m1;
    unsigned int d1;
    cout << "请输入日期：xxxx xx xx" << endl;
    cin >> y1 >> m1 >> d1;
    D1 = {y1, m1, d1};
    D1.SetDay(d1);
    Judge(D1);
    cin.clear();
    cin.sync();
    cin.get();
    return 0;
}

