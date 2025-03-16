//
// Created by Jakub Grad on 28/01/2025.
//

#ifndef OOP24_WW_MON_0830_07_DATEUTILL_H
#define OOP24_WW_MON_0830_07_DATEUTILL_H
#include <chrono>
#include <iostream>

class DateUtill {

    public:

        static std::string getLocalDateTimeOf(int day, int month, int year, int hour, int minutes);
        static std::string getLocalDateTimeNow();

        static bool isDateTimeValid(std::string dateTime);

        static int getDayOfDate(std::string dateTime);
        static int getMonthOfDate(std::string dateTime);
        static int getYearOfDate(std::string dateTime);
        static int getMinuteOfDate(std::string dateTime);
        static int getHourOfDate(std::string dateTime);

        static bool isDateTimeValid(int day, int month, int year, int hour, int minutes);

        static bool isPrevious(std::string isBefore, std::string than);

        static bool isValidDate(const std::string& date);
};


#endif //OOP24_WW_MON_0830_07_DATEUTILL_H
