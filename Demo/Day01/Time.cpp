//
//  Time.cpp
//  TimeDemo
//
//  Created by 范静涛 on 2023/7/10.
//

#include "Time.hpp"
#include <iostream>
using namespace std;

unsigned int Time::DefaultHour   = 0;
unsigned int Time::DefaultMinute = 0;
unsigned int Time::DefaultSecond = 0;

unsigned int Time::MaxHour   = 23;
unsigned int Time::MaxMinute = 59;
unsigned int Time::MaxSecond = 59;

bool Time::Is24Format = true;

Time::Time(const Time& Source) : Hour(m_Hour),Minute(m_Hour),Second(m_Second){
    m_Hour   = Source.m_Hour;
    m_Minute = Source.m_Minute;
    m_Second = Source.m_Second;
    
}

Time& Time::operator=(const Time& Source){
    if(this != &Source){
        m_Hour   = Source.m_Hour;
        m_Minute = Source.m_Minute;
        m_Second = Source.m_Second;
    }
    return *this;
}

Time::~Time(){
    delete[] pData;
}

Time::Time(unsigned int Hour,
           unsigned int Minute ,
           unsigned int Second): Hour(m_Hour),Minute(m_Hour),Second(m_Second){
    Set(Hour, Minute, Second);
    pData = new int[10];
}

bool Time::Set(unsigned int Hour,
               unsigned int Minute,
               unsigned int Second){
    if (Hour > MaxHour) {
        return false;
    }
    if (Minute > MaxMinute) {
        return false;
    }
    if (Second > MaxSecond) {
        return false;
    }
    this->m_Hour = Hour;
    this->m_Minute = Minute;
    this->m_Second = Second;
    return true;
}

void Time::show() const{
    if(Is24Format) {
        cout << m_Hour << " : "
        << m_Minute << " : "
        << m_Second;}
    else {
    }
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
    this->m_Hour = (Hour > MaxHour)? this->m_Hour : Hour;
    return Hour <= MaxHour;
}

bool Time::SetMinute(unsigned int Minute){
    this->m_Minute = (Minute > MaxMinute)? this->m_Minute : Minute;
    return Minute <= MaxMinute;

}
bool Time::SetSecond(unsigned int Second){
    this->m_Second = (Second > MaxSecond)? this->m_Second : Second;
    return Second <= MaxSecond;

}
