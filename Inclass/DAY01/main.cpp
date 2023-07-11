#include <iostream>
#include "Time.hpp"

int main(int argc, const char * argv[ ]){
    Time t1 = {23, 50, 45};
    Time* p = new Time();
    Time t2;

    Time arr[10];

    t1.Set(23,  15,  50);
    t1.Show();
    t2.Show();
    std::cout << std::endl;

    std::cout << "Hello, world!\n" ;

    return 0;
}