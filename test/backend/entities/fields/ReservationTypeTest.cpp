#include <boost/test/unit_test.hpp>
#include "../../../../src/backend/entities/fields/ReservationType.h"
BOOST_AUTO_TEST_SUITE(ReservationTypeTestSuite)
BOOST_AUTO_TEST_CASE(ReservationTypeGetByNameTest) {
    ReservationType reservationType = ReservationType::getByName("Yoga");
    BOOST_REQUIRE_EQUAL(reservationType.name, "Yoga");
    BOOST_REQUIRE_EQUAL(reservationType.roomNumber, 102);
    BOOST_REQUIRE_EQUAL(reservationType.maxOccupancy, 15);
    BOOST_REQUIRE_EQUAL(reservationType.description, "Quiet and serene room for yoga practice.");
    ReservationType invalidType = ReservationType::getByName("NonExistent");
    BOOST_REQUIRE_EQUAL(invalidType.name, "");
}
BOOST_AUTO_TEST_CASE(ReservationTypeGetAllTest) {
    std::vector<ReservationType> allTypes = ReservationType::getAllReservationTypes();
    BOOST_REQUIRE_EQUAL(allTypes.size(), 14);
    bool foundYoga = false;
    bool foundBoxing = false;
    for (const auto& type : allTypes) {
        if (type.name == "Yoga") {
            foundYoga = true;
        }
        if (type.name == "Boxing") {
            foundBoxing = true;
        }
    }
    BOOST_REQUIRE(foundYoga);
    BOOST_REQUIRE(foundBoxing);
}
BOOST_AUTO_TEST_CASE(ReservationTypePredefinedConstantsTest) {
    BOOST_REQUIRE_EQUAL(ReservationType::Weightlifting.name, "Weightlifting");
    BOOST_REQUIRE_EQUAL(ReservationType::Weightlifting.roomNumber, 101);
    BOOST_REQUIRE_EQUAL(ReservationType::Weightlifting.maxOccupancy, 20);
    BOOST_REQUIRE_EQUAL(ReservationType::Weightlifting.description, "Weightlifting room with all necessary equipment.");
    BOOST_REQUIRE_EQUAL(ReservationType::Yoga.name, "Yoga");
    BOOST_REQUIRE_EQUAL(ReservationType::Yoga.roomNumber, 102);
    BOOST_REQUIRE_EQUAL(ReservationType::Yoga.maxOccupancy, 15);
    BOOST_REQUIRE_EQUAL(ReservationType::Yoga.description, "Quiet and serene room for yoga practice.");
    BOOST_REQUIRE_EQUAL(ReservationType::Crossfit.name, "Crossfit");
    BOOST_REQUIRE_EQUAL(ReservationType::Crossfit.roomNumber, 107);
    BOOST_REQUIRE_EQUAL(ReservationType::Crossfit.maxOccupancy, 25);
    BOOST_REQUIRE_EQUAL(ReservationType::Crossfit.description, "Room equipped for CrossFit training with weights and rigs.");
}
BOOST_AUTO_TEST_SUITE_END()
