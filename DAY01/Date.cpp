#include <iostream>
#include "Date.hpp"

using namespace std;

unsigned int Date::DefaultYear = 1900;
unsigned int Date::DefaultMonth = 1;
unsigned int Date::DefaultDay = 1;

unsigned int Date::MaxYear = 9999;
unsigned int Date::MaxMonth = 12;
unsigned int Date::MaxDay = 31;
const unsigned int Date::daysInMonth[2][13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
                                          0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(const Date& Source) : Year(m_Year),Month(m_Month),Day(m_Day){
    m_Year   = Source.m_Year;
    m_Month = Source.m_Month;
    m_Day = Source.m_Day;
}

Date::Date(unsigned int Year,
         unsigned int Month,
         unsigned int Day):Year(m_Year),Month(m_Month),Day(m_Day){
            Set(Year, Month, Day);
         }

bool Date::Set(unsigned int Year,
               unsigned int Month,
               unsigned int Day){
    unsigned int TempY = m_Year;
    unsigned int TempM = m_Month;
    unsigned int TempD = m_Day;

    bool IsValid = (SetYear(Year) && SetMonth(Month) && SetDay(Day));

    string messageA = "";

    if(!IsValid){
        
        if(!SetYear(Year)){
            messageA += "\nThe Year is out of range.";
        }
        if(!SetMonth(Month)){
            messageA += "\nThe Month is out of range.";
        }
        if(!SetDay(Day)){
            messageA += "\nThe Day is out of range.";
        }
        m_Year = TempY;
        m_Month = TempM;
        m_Day = TempD;
        throw out_of_range(messageA);

    }
    
    return IsValid;
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
    // if (Year > MaxYear||Year < DefaultYear) {
    //     throw invalid_argument("The year is out of range");
    // }
    this->m_Year = (Year > MaxYear||Year < DefaultYear)? this->m_Year : Year;
    return (Year <= MaxYear && Year >= DefaultYear);
};
bool Date::SetMonth(unsigned int Month){
    // if (Month > MaxMonth || Month < DefaultMonth) {
    //     throw invalid_argument("The month is out of range");
    // }
    this->m_Month = (Month > MaxMonth || Month < DefaultMonth)? this->m_Month : Month;
    return (Month <= MaxMonth && Month >= DefaultMonth);
};
bool Date::SetDay(unsigned int Day){
    // if (Day > GetDaysInMonth(m_Month) || Day < DefaultDay) {
    //     throw invalid_argument("The day is out of range");
    // }
    this->m_Day = (Day > GetDaysInMonth(m_Month) || Day < DefaultDay)? this->m_Day : Day;
    return (Day <= GetDaysInMonth(m_Month) && Day >= DefaultDay);
};

bool Date::IsValidDate() const{
    if (m_Year < DefaultYear || m_Year > MaxYear){
            return false;
    }
    if (m_Month < DefaultMonth || m_Month > MaxMonth)
            return false;

    if (m_Day > GetDaysInMonth(m_Month) || m_Day < DefaultDay)
            return false;

        return true;
};

bool Date::IsValidDate(unsigned int Year,
                     unsigned int Month,
                     unsigned int Day) const{
    if (Year < DefaultYear || Year > MaxYear)
            return false;
    if (Month < DefaultMonth || Month > MaxMonth)
            return false;

    if (Day > GetDaysInMonth(m_Month) || Day < DefaultDay)
            return false;
            
        return true;
};

bool Date::IsLeapYear(unsigned int year) const{
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

unsigned int Date::GetDaysInMonth(unsigned int month) const{
        if (month >= DefaultDay && month <= MaxMonth) {
        return daysInMonth[IsLeapYear(m_Year)][month];
    }
}