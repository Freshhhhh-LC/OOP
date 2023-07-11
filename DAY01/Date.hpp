#ifndef Date_hpp
#define Date_hpp

class Date{
public:
    Date(const Date& Source);
    Date(unsigned int Year = DefaultYear,
         unsigned int Month = DefaultMonth,
         unsigned int Day = DefaultDay);
    Date& operator=(const Date& Source);
    ~Date();

    bool Set(unsigned int Year,
             unsigned int Month,
             unsigned int Day);

    bool IsValidDate() const;
    bool IsValidDate(unsigned int Year,
                     unsigned int Month,
                     unsigned int Day) const;

    void Show() const;
    unsigned int GetYear() const;
    unsigned int GetMonth() const;
    unsigned int GetDay() const;
    //unsigned int GetDaysFromZero() const;

    bool SetYear(unsigned int Year);
    bool SetMonth(unsigned int Month);
    bool SetDay(unsigned int Day);

    const unsigned int& Year;
    const unsigned int& Month;
    const unsigned int& Day;

private:
    unsigned int m_Year;
    unsigned int m_Month;
    unsigned int m_Day;
    
    static unsigned int DefaultYear;
    static unsigned int DefaultMonth;
    static unsigned int DefaultDay;
    
    static unsigned int MaxYear;
    static unsigned int MaxMonth;
    static unsigned int MaxDay;
    static const unsigned int daysInMonth[2][13];
    //int* pData;

    bool IsLeapYear(unsigned int year) const;

    unsigned int GetDaysInMonth(unsigned int month) const;
};

#endif