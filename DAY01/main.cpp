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
    try{
        D1.Set(y1, m1, d1);
        Judge(D1);
    } catch(exception& e) {
        cout << "Invalid Date" << endl;
        cout << "Error : " << e.what() << endl;
    }
    
    D1.Show();
    cin.clear();
    cin.sync();
    cin.get();
    return 0;
}

