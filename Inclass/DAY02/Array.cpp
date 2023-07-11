#include <iostream>
#include <stdexcept>
#include "Array.hpp"

    
Array::Array(unsigned int Size){
    if (Size == 0) {
        throw std::invalid_argument("Size can't be zero");
    }
    pData = new int[Size];
    this->Size = Size;
}

Array::Array(const Array& Source){
        Size = Source.Size;
        pData = new int[Size];
        for (unsigned i = 0; i < Size; i++){
            pData[i] = Source.pData[i];
        }
    }

Array& Array::operator=(const Array& Source){
        if (this != &Source)//深拷贝时需要判断
        {
            Size = Source.Size;
            pData = new int[Size];
            for (unsigned i = 0; i < Size; i++){
                pData[i] = Source.pData[i];
            }
        }
    }

Array::~Array(){
    delete[] pData;
}
void Array::Set(unsigned int Index, int Value){
    if (Index >= Size){
        throw std::invalid_argument("Index is out of range");
    }
}