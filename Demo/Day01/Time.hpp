//
//  Time.hpp
//  TimeDemo
//
//  Created by 范静涛 on 2023/7/10.
//

#ifndef Time_hpp
#define Time_hpp

class Time{
public:
    Time(const Time& Source);//拷贝构造
    Time(unsigned int Hour = DefaultHour,
         unsigned int Minute = DefaultMinute,
         unsigned int Second = DefaultSecond);//构造
    Time& operator=(const Time& Source);
    ~Time();
    bool Set(unsigned int Hour,
             unsigned int Minute,
             unsigned int Second);
    void show() const;
    unsigned int GetHour() const;
    unsigned int GetMinute() const;
    unsigned int GetSecond() const;
    unsigned int GetSecondsFromZero() const;

    bool SetHour(unsigned int Hour);
    bool SetMinute(unsigned int Minute);
    bool SetSecond(unsigned int Second);
    
    const unsigned int& Hour;
    const unsigned int& Minute;
    const unsigned int& Second;
    static bool Is24Format;

private:
    unsigned int m_Hour;
    unsigned int m_Minute;
    unsigned int m_Second;
    
    static unsigned int DefaultHour;
    static unsigned int DefaultMinute;
    static unsigned int DefaultSecond;
    
    static unsigned int MaxHour;
    static unsigned int MaxMinute;
    static unsigned int MaxSecond;
    int* pData;
};

#endif /* Time_hpp */
