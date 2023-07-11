//
//  main.cpp
//  TimeDemo
//
//  Created by 范静涛 on 2023/7/10.
//

#include <iostream>
#include "Time.hpp"
#include "Time.hpp"

using namespace std;

void Swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

Time func(){
    return Time(23, 50, 45);
}

int main(int argc, const char * argv[]) {
    
    Time t1 = {23, 50, 45}; //1
    Time t2(t1);
    Time t3 = t2;
    
    t3 = t2;
    t3.operator=(t2);
    
    (t3 = t2) = t1;
    
    return 0;
}
