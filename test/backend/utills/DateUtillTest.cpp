//
// Created by Marcin Kaczmarek on 1/31/25.
//

#include <boost/test/unit_test.hpp>
#include "../../../src/backend/utills/DateUtill.h"

BOOST_AUTO_TEST_SUITE(DateUtillTestSuite)

BOOST_AUTO_TEST_CASE(DateUtillGetLocalDateTimeNowTest) {
    std::string dateTimeNow = DateUtill::getLocalDateTimeNow();

    BOOST_REQUIRE_EQUAL(dateTimeNow.length(), 16);
    BOOST_REQUIRE_EQUAL(dateTimeNow[2], '-');
    BOOST_REQUIRE_EQUAL(dateTimeNow[5], '-');
    BOOST_REQUIRE_EQUAL(dateTimeNow[10], ' ');
    BOOST_REQUIRE_EQUAL(dateTimeNow[13], ':');
}

BOOST_AUTO_TEST_CASE(DateUtillGetLocalDateTimeOfTest) {
    std::string formattedDate = DateUtill::getLocalDateTimeOf(25, 12, 2025, 18, 30);

    BOOST_REQUIRE_EQUAL(formattedDate, "25-12-2025 18:30");
}

BOOST_AUTO_TEST_CASE(DateUtillIsDateTimeValidTestValid) {
    bool valid = DateUtill::isDateTimeValid("25-12-2025 18:30");
    BOOST_REQUIRE_EQUAL(valid, true);
}

BOOST_AUTO_TEST_CASE(DateUtillIsDateTimeValidTestInvalid) {
    bool invalid = DateUtill::isDateTimeValid("31-02-2025 18:30");
    BOOST_REQUIRE_EQUAL(invalid, false);
}

/** IS PREVIOUS TESTS **/

    BOOST_AUTO_TEST_CASE(DateUtillIsPreviousTestSameDate) {
        bool isBefore = DateUtill::isPrevious("25-12-2025 18:30", "25-12-2025 18:30");
        BOOST_REQUIRE_EQUAL(isBefore, false);
    }

    BOOST_AUTO_TEST_CASE(DateUtillIsPreviousTestDifferentYears) {
        bool isBefore = DateUtill::isPrevious("25-12-2024 18:30", "25-12-2025 18:30");
        BOOST_REQUIRE_EQUAL(isBefore, true);
    }

    BOOST_AUTO_TEST_CASE(DateUtillIsPreviousTestDifferentMonths) {
        bool isBefore = DateUtill::isPrevious("25-11-2025 18:30", "25-12-2025 18:30");
        BOOST_REQUIRE_EQUAL(isBefore, true);
    }

    BOOST_AUTO_TEST_CASE(DateUtillIsPreviousTestDifferentDays) {
        bool isBefore = DateUtill::isPrevious("24-12-2025 18:30", "25-12-2025 18:30");
        BOOST_REQUIRE_EQUAL(isBefore, true);
    }

    BOOST_AUTO_TEST_CASE(DateUtillIsPreviousTestDifferentHours) {
        bool isBefore = DateUtill::isPrevious("25-12-2025 17:30", "25-12-2025 18:30");
        BOOST_REQUIRE_EQUAL(isBefore, true);
    }

    BOOST_AUTO_TEST_CASE(DateUtillIsPreviousTestDifferentMinutes) {
        bool isBefore = DateUtill::isPrevious("25-12-2025 18:29", "25-12-2025 18:30");
        BOOST_REQUIRE_EQUAL(isBefore, true);
    }

BOOST_AUTO_TEST_CASE(DateUtillIsPreviousTestBefore) {
    bool isBefore = DateUtill::isPrevious("25-12-2025 18:30", "26-12-2025 18:30");
    BOOST_REQUIRE_EQUAL(isBefore, true);
}

BOOST_AUTO_TEST_CASE(DateUtillIsPreviousTestAfter) {
    bool isBefore = DateUtill::isPrevious("26-12-2025 18:30", "25-12-2025 18:30");
    BOOST_REQUIRE_EQUAL(isBefore, false);
}

/******/

BOOST_AUTO_TEST_CASE(DateUtillGetDayOfDateTest) {
    int day = DateUtill::getDayOfDate("25-12-2025 18:30");
    BOOST_REQUIRE_EQUAL(day, 25);
}

BOOST_AUTO_TEST_CASE(DateUtillGetMonthOfDateTest) {
    int month = DateUtill::getMonthOfDate("25-12-2025 18:30");
    BOOST_REQUIRE_EQUAL(month, 12);
}

BOOST_AUTO_TEST_CASE(DateUtillGetYearOfDateTest) {
    int year = DateUtill::getYearOfDate("25-12-2025 18:30");
    BOOST_REQUIRE_EQUAL(year, 2025);
}

BOOST_AUTO_TEST_CASE(DateUtillGetMinuteOfDateTest) {
    int minute = DateUtill::getMinuteOfDate("25-12-2025 18:30");
    BOOST_REQUIRE_EQUAL(minute, 30);
}

BOOST_AUTO_TEST_CASE(DateUtillGetHourOfDateTest) {
    int hour = DateUtill::getHourOfDate("25-12-2025 18:30");
    BOOST_REQUIRE_EQUAL(hour, 18);
}

BOOST_AUTO_TEST_CASE(DateUtillIsDateTimeValidIntegerTestValid) {
    bool valid = DateUtill::isDateTimeValid(25, 12, 2025, 18, 30);
//    bool valid = DateUtill::isDateTimeValid(31, 1, 2025, 18, 30);
    BOOST_REQUIRE_EQUAL(valid, true);
}

BOOST_AUTO_TEST_CASE(DateUtillIsDateTimeValidIntegerTestInvalid) {
    bool invalid = DateUtill::isDateTimeValid(31, 02, 2025, 18, 30);
    BOOST_REQUIRE_EQUAL(invalid, false);
}

BOOST_AUTO_TEST_SUITE_END()
