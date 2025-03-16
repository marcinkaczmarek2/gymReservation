//
// Created by Marcin Kaczmarek on 1/31/25.
//

#include <boost/test/unit_test.hpp>
#include "../../../src/backend/entities/Reservation.h"
#include "../../../src/backend/entities/Trainer.h"
#include "../../../src/backend/entities/fields/ReservationType.h"
#include <optional>

BOOST_AUTO_TEST_SUITE(ReservationTestSuite)

BOOST_AUTO_TEST_CASE(ReservationConstructorTest) {
    Reservation reservation("01-02-2025 09:00", "01-02-2025 10:00", "trainee123", ReservationType::Weightlifting);
    BOOST_REQUIRE_EQUAL(reservation.getStartTime(), "01-02-2025 09:00");
    BOOST_REQUIRE_EQUAL(reservation.getEndTime(), "01-02-2025 10:00");
    BOOST_REQUIRE_EQUAL(reservation.getTraineeID(), "trainee123");
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().name, "Weightlifting");
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().roomNumber, ReservationType::Weightlifting.roomNumber);
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().maxOccupancy, ReservationType::Weightlifting.maxOccupancy);
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().description, ReservationType::Weightlifting.description);
    BOOST_REQUIRE(!reservation.getOptionalTrainerID().has_value());
}

BOOST_AUTO_TEST_CASE(ReservationConstructorWithTrainerTest) {
    Reservation reservation("01-02-2025 09:00", "01-02-2025 10:00", "trainee123", ReservationType::Yoga, "trainer123");
    BOOST_REQUIRE_EQUAL(reservation.getStartTime(), "01-02-2025 09:00");
    BOOST_REQUIRE_EQUAL(reservation.getEndTime(), "01-02-2025 10:00");
    BOOST_REQUIRE_EQUAL(reservation.getTraineeID(), "trainee123");
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().name, "Yoga");
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().roomNumber, ReservationType::Yoga.roomNumber);
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().maxOccupancy, ReservationType::Yoga.maxOccupancy);
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().description, ReservationType::Yoga.description);
    BOOST_REQUIRE_EQUAL(reservation.getOptionalTrainerID().value(), "trainer123");
}

BOOST_AUTO_TEST_CASE(ReservationDefaultConstructorTest) {
    Reservation reservation;
    BOOST_REQUIRE_EQUAL(reservation.getStartTime(), "");
    BOOST_REQUIRE_EQUAL(reservation.getEndTime(), "");
    BOOST_REQUIRE_EQUAL(reservation.getTraineeID(), "");
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().name, "");
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().roomNumber, 0);
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().maxOccupancy, 0);
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().description, "");
    BOOST_REQUIRE(!reservation.getOptionalTrainerID().has_value());
}

BOOST_AUTO_TEST_CASE(ReservationSettersTest) {
    Reservation reservation;
    reservation.setStartTime("01-02-2025 09:00");
    reservation.setEndTime("01-02-2025 10:00");
    reservation.setTraineeID("trainee123");
    reservation.setReservationType(ReservationType::Fitness);
    reservation.setOptionalTrainerID("trainer123");
    reservation.setCanceled(true);

    BOOST_REQUIRE_EQUAL(reservation.getStartTime(), "01-02-2025 09:00");
    BOOST_REQUIRE_EQUAL(reservation.getEndTime(), "01-02-2025 10:00");
    BOOST_REQUIRE_EQUAL(reservation.getTraineeID(), "trainee123");
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().name, "Fitness");
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().roomNumber, ReservationType::Fitness.roomNumber);
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().maxOccupancy, ReservationType::Fitness.maxOccupancy);
    BOOST_REQUIRE_EQUAL(reservation.getReservationType().description, ReservationType::Fitness.description);
    BOOST_REQUIRE_EQUAL(reservation.getOptionalTrainerID().value(), "trainer123");
    BOOST_REQUIRE(reservation.isCanceled());
}

BOOST_AUTO_TEST_CASE(ReservationCancelTest) {
    Reservation reservation("01-02-2025 09:00", "01-02-2025 10:00", "trainee123", ReservationType::Cardio);
    reservation.setCanceled(true);
    BOOST_REQUIRE(reservation.isCanceled());

    reservation.setCanceled(false);
    BOOST_REQUIRE(!reservation.isCanceled());
}

BOOST_AUTO_TEST_CASE(ReservationJsonConversionTest) {
    Reservation reservation("01-02-2025 09:00", "01-02-2025 10:00", "trainee123", ReservationType::Yoga);
    Json json = reservation.toJsonFormat();
    Reservation newReservation;
    newReservation.fromJsonFormat(json);

    BOOST_REQUIRE_EQUAL(newReservation.getStartTime(), "01-02-2025 09:00");
    BOOST_REQUIRE_EQUAL(newReservation.getEndTime(), "01-02-2025 10:00");
    BOOST_REQUIRE_EQUAL(newReservation.getTraineeID(), "trainee123");
    BOOST_REQUIRE_EQUAL(newReservation.getReservationType().name, "Yoga");
    BOOST_REQUIRE_EQUAL(newReservation.getReservationType().roomNumber, ReservationType::Yoga.roomNumber);
    BOOST_REQUIRE_EQUAL(newReservation.getReservationType().maxOccupancy, ReservationType::Yoga.maxOccupancy);
    BOOST_REQUIRE_EQUAL(newReservation.getReservationType().description, ReservationType::Yoga.description);
    BOOST_REQUIRE_EQUAL(newReservation.getOptionalTrainerID().value(), "null");
}

BOOST_AUTO_TEST_CASE(ReservationModifyJsonTest) {
    Reservation reservation("01-02-2025 09:00", "01-02-2025 10:00", "trainee123", ReservationType::Spinning);
    Json json = reservation.toJsonFormat();
    json["startTime"] = "01-02-2025 08:00";
    reservation.fromJsonFormat(json);

    BOOST_REQUIRE_EQUAL(reservation.getStartTime(), "01-02-2025 08:00");
}

BOOST_AUTO_TEST_CASE(ReservationUUIDTest) {
    Reservation reservation("01-02-2025 09:00", "01-02-2025 10:00", "trainee123", ReservationType::Boxing);
    BOOST_REQUIRE_EQUAL(reservation.getUUID().size(), 36);
}

BOOST_AUTO_TEST_SUITE_END()
