#ifndef Time_hpp
#define Time_hpp
/*
Struct Time{
Public:
Bool Set(Unsigned int Hour;
Unsigned int Minute;
Unsigned int Second);
Private:
Unsigned int Hour;
Unsigned int Minute;
Unsigned int Second;
};
*/

class Time{
public:
    Time(const Time& Source) {};
    Time(unsigned int m_Hour = 0,
         unsigned int m_Minute = 0,
         unsigned int m_Second = 0) {};

    bool Set(unsigned int Hour,
             unsigned int Minute,
             unsigned int Second);

    void Show() const;
    unsigned int GetHour() const;
    unsigned int GetMinute() const;
    unsigned int GetSecond() const;

    bool SetHour(unsigned int Hour);
    bool SetMinute(unsigned int Minute);
    bool SetSecond(unsigned int Second);

    const unsigned int& Hour;
    const unsigned int& Minute;
    const unsigned int& Second;

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
};



#endif /* Time_hpp */

