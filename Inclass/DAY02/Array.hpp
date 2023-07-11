#ifndef Array_hpp
#define Array_hpp

class Array{
public:
    Array(unsigned int Size);
    Array(const Array& Source);
    Array& operator=(const Array& Source);
    ~Array();
    void Set(unsigned int Index, int Value);
private:
    unsigned int Size;
    int* pData;
    std::string Message;
};

#endif