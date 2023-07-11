#include <iostream>
#include "Date.hpp"

using namespace std;

unsigned int Date::DefaultYear = 1900;
unsigned int Date::DefaultMonth = 1;
unsigned int Date::DefaultDay = 1;

unsigned int Date::MaxYear = 9999;
unsigned int Date::MaxMonth = 12;
unsigned int Date::MaxDay = 31;

Date::Date(const Date& Source) : p_Year(m_Year),p_Month(m_Month),p_Day(m_Day){
    m_Year   = Source.m_Year;
    m_Month = Source.m_Month;
    m_Day = Source.m_Day;
}

Date::Date(unsigned int Year,
         unsigned int Month,
         unsigned int Day):p_Year(Year),p_Month(Month),p_Day(Day){
            Set(Year, Month, Day);
         }

bool Date::Set(unsigned int Year,
               unsigned int Month,
               unsigned int Day){
    if (Year > MaxYear ||Year < DefaultYear) {
        return false;
    }
    if (Month > MaxMonth || Month < DefaultMonth) {
        return false;
    }
    if (Day > MaxDay || Day < DefaultDay) {
        return false;
    }
    this->m_Year = Year;
    this->m_Month = Month;
    this->m_Day = Day;
    return true;
}

Date::~Date(){
}

Date& Date::operator=(const Date& Source){
    if(this != &Source){
        m_Year   = Source.m_Year;
        m_Month = Source.m_Month;
        m_Day = Source.m_Day;
    }
    return *this;
}

void Date::Show() const{
    if(IsValidDate()){
    cout << m_Year << "年"
    << m_Month << "月"
    << m_Day << "日";
    }
    else{
        cout << "Not Valid Date" << endl;
    }
}

unsigned int Date::GetYear() const{
    return m_Year;
};
unsigned int Date::GetMonth() const{
    return m_Month;
};
unsigned int Date::GetDay() const{
    return m_Day;
};

bool Date::SetYear(unsigned int Year){
    this->m_Year = (Year > MaxYear||Year < DefaultYear)? this->m_Year : Year;
    return (Year <= MaxYear && Year >= DefaultYear);
};
bool Date::SetMonth(unsigned int Month){
    this->m_Month = (Month > MaxMonth || Month < DefaultMonth)? this->m_Month : Month;
    return (Month <= MaxMonth && Month >= DefaultMonth);
};
bool Date::SetDay(unsigned int Day){
    this->m_Day = (Day > MaxDay || Day < DefaultDay)? this->m_Day : Day;
    return (Day <= MaxDay && Day >= DefaultDay);
};

bool Date::IsValidDate() const{
    if (m_Year < DefaultYear || m_Year > MaxYear)
            return false;

        if (m_Month < 1 || m_Month > 12)
            return false;

        if (m_Day < 1)
            return false;

        if (IsLeapYear(m_Year)) {
            if (m_Month == 2 && m_Day > 29)
                return false;
        } 
        else {
            if (m_Month == 2 && m_Day > 28)
                return false;
        }

        if (m_Day > GetDaysInMonth(m_Month) && m_Month != 2)
            return false;

        return true;
};

bool Date::IsLeapYear(unsigned int year) const{
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

unsigned int Date::GetDaysInMonth(unsigned int month) const{
        static const unsigned int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month >= 1 && month <= 12) {
        return daysInMonth[month];
    }
}
