#include "DateUtill.h"
#include <sstream>
#include <regex>
bool DateUtill::isDateTimeValid(int day, int month, int year, int hour, int minutes) {
    if(month > 12 || month < 1) return false;
    if(day < 1) return false;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            if(day > 31) return false;
        }
            break;
        case 2: {
            if(day > 29) return false;
            if(year%4 != 0) if(day > 28) return false;
        }
            break;
        default: {
            if(day > 30) return false;
        }
    }
    if(hour < 0) return false;
    if(hour > 23) return false;
    if(minutes < 0) return false;
    if(minutes > 59) return false;
    return true;
}
std::string DateUtill::getLocalDateTimeOf(int day, int month, int year, int hour, int minutes){
    std::stringstream ss;
    ss<<(day < 10 ? "0" : "")<<day<<"-"<<(month < 10 ? "0" : "")<<month<<"-"<<year<<" "<<(hour < 10 ? "0" : "")<<hour<<":"<<(minutes < 10 ? "0" : "")<<minutes;
    return ss.str();
}
std::string DateUtill::getLocalDateTimeNow() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);
    int currDay = local_time->tm_mday;
    int currMonth = local_time->tm_mon + 1;
    int currYear = local_time->tm_year + 1900;
    int currHour = local_time->tm_hour;
    int currMinutes = local_time->tm_min;
    return getLocalDateTimeOf(currDay, currMonth, currYear, currHour, currMinutes);
}
bool DateUtill::isDateTimeValid(std::string dateTime){
    if(!isValidDate(dateTime)) return false;
    int day = getDayOfDate(dateTime);
    int month = getMonthOfDate(dateTime);
    int year = getYearOfDate(dateTime);
    int hour = getHourOfDate(dateTime);
    int minutes = getMinuteOfDate(dateTime);
    return isDateTimeValid(day, month, year, hour, minutes);
}
int DateUtill::getDayOfDate(std::string dateTime) {
    return std::stoi(dateTime.substr(0, 2));
}
int DateUtill::getMonthOfDate(std::string dateTime) {
    return std::stoi(dateTime.substr(3, 2));
}
int DateUtill::getYearOfDate(std::string dateTime) {
    return std::stoi(dateTime.substr(6, 4));
}
int DateUtill::getMinuteOfDate(std::string dateTime) {
    try {
        return std::stoi(dateTime.substr(14, 2));
    } catch (std::exception ex) {
        return 0;
    }
}
int DateUtill::getHourOfDate(std::string dateTime) {
    try {
        return std::stoi(dateTime.substr(11, 2));
    } catch (std::exception ex) {
        return 0;
    }
}
bool DateUtill::isPrevious(std::string isBefore, std::string than) {
    try {
        if(getYearOfDate(isBefore) < getYearOfDate(than)) return true;
        if(getYearOfDate(isBefore) > getYearOfDate(than)) return false;
        if(getMonthOfDate(isBefore) < getMonthOfDate(than)) return true;
        if(getMonthOfDate(isBefore) > getMonthOfDate(than)) return false;
        if(getDayOfDate(isBefore) < getDayOfDate(than)) return true;
        if(getDayOfDate(isBefore) > getDayOfDate(than)) return false;
        if(getHourOfDate(isBefore) < getHourOfDate(than)) return true;
        if(getHourOfDate(isBefore) > getHourOfDate(than)) return false;
        if(getMinuteOfDate(isBefore) < getMinuteOfDate(than)) return true;
    }catch (const std::exception ex) {
        return false;
    }
    return false;
}
bool DateUtill::isValidDate(const std::string& date) {
    std::regex dateRegex("^([0-2][0-9]|3[0-1])-(0[1-9]|1[0-2])-[0-9]{4} (0[0-9]|1[0-9]|2[0-3]):([0-5][0-9])$");
    return std::regex_match(date, dateRegex);
}