
#include <iostream>
#include <Time.hpp>

using namespace std;

Time::Time(const Time& Source) : Hour(m_Hour),Minute(m_Minute),Second(m_Second)
{
    m_Hour   = Source.m_Hour;
    m_Minute = Source.m_Minute;
    m_Second = Source.m_Second;
}

Time::Time(unsigned int Hour,
         unsigned int Minute,
         unsigned int Second): Hour(m_Hour),Minute(m_Minute),Second(m_Second)
{

};
         
bool Time::Set(unsigned int Hour,
               unsigned int Minute,
               unsigned int Second){
    if(Hour >= 24){
        return false;
    }
    if(Minute >= 60){
        return false;
    }
    if(Second >= 60){
        return false;
    }
    this->m_Hour = Hour;
    this->m_Minute = Minute;
    this->m_Second = Second;
    return true;
}

void Time::Show() const{
    cout << this->m_Hour   << " : "
         << this->m_Minute << " : "
         << this->m_Second;

}

unsigned int Time::GetHour() const{
    return m_Hour;
}
unsigned int Time::GetMinute() const{
    return m_Minute;
}
unsigned int Time::GetSecond() const{
    return m_Second;
}

bool Time::SetHour(unsigned int Hour){
    this->m_Hour = (Hour >= 24)? this->m_Hour : Hour;
    return Hour < 24;
}
bool Time::SetMinute(unsigned int Minute){
    this->m_Minute = (Minute >= 60)? this->m_Minute : Minute;
    return Minute < 60;
}
bool Time::SetSecond(unsigned int Second){
    this->m_Second = (Second >= 60)? this->m_Second : Second;
    return Second < 60;
}