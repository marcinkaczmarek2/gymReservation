//
// Created by Marcin Kaczmarek on 1/31/25.
//

#include <boost/test/unit_test.hpp>
#include "../../../src/backend/dtos/ReservationDTO.h"
#include "../../../src/backend/entities/User.h"
#include "../../../src/backend/entities/Trainer.h"
#include "../../../src/backend/entities/fields/ReservationType.h"

BOOST_AUTO_TEST_SUITE(ReservationDTOTestSuite)

BOOST_AUTO_TEST_CASE(ReservationDTOConstructorTest) {
    User user("user123", "John", "Doe", "john.doe@example.com");

    ReservationDTO reservationDTO;
    reservationDTO.setUser(&user);
    reservationDTO.setStartTime("01-02-2025 09:00");
    reservationDTO.setEndTime("01-02-2025 10:00");
    reservationDTO.setReservationType(ReservationType::Yoga);

    BOOST_REQUIRE_EQUAL(reservationDTO.getUser(), &user);
    BOOST_REQUIRE_EQUAL(reservationDTO.getStartTime(), "01-02-2025 09:00");
    BOOST_REQUIRE_EQUAL(reservationDTO.getEndTime(), "01-02-2025 10:00");
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().name, "Yoga");
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().roomNumber, ReservationType::Yoga.roomNumber);
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().maxOccupancy, ReservationType::Yoga.maxOccupancy);
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().description, ReservationType::Yoga.description);
    BOOST_REQUIRE(!reservationDTO.getOptionalTrainer().has_value());
}

BOOST_AUTO_TEST_CASE(ReservationDTOConstructorWithTrainerTest) {
    User user("user123", "John", "Doe", "john.doe@example.com");

    Trainer trainer("Marian", "53252312", "marian@gmail.com", 100.0f, "test");

    ReservationDTO reservationDTO;
    reservationDTO.setUser(&user);
    reservationDTO.setStartTime("01-02-2025 09:00");
    reservationDTO.setEndTime("01-02-2025 10:00");
    reservationDTO.setReservationType(ReservationType::Yoga);
    reservationDTO.setOptionalTrainer(std::make_optional(&trainer));

    BOOST_REQUIRE_EQUAL(reservationDTO.getUser(), &user);
    BOOST_REQUIRE_EQUAL(reservationDTO.getStartTime(), "01-02-2025 09:00");
    BOOST_REQUIRE_EQUAL(reservationDTO.getEndTime(), "01-02-2025 10:00");
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().name, "Yoga");
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().roomNumber, ReservationType::Yoga.roomNumber);
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().maxOccupancy, ReservationType::Yoga.maxOccupancy);
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().description, ReservationType::Yoga.description);
    BOOST_REQUIRE(reservationDTO.getOptionalTrainer().has_value());
    BOOST_REQUIRE_EQUAL(reservationDTO.getOptionalTrainer().value(), &trainer);
}

BOOST_AUTO_TEST_CASE(ReservationDTOSettersTest) {
    User user("user123", "John", "Doe", "john.doe@example.com");

    Trainer trainer("Marian", "53252312", "marian@gmail.com", 100.0f, "test");

    ReservationDTO reservationDTO;
    reservationDTO.setUser(&user);
    reservationDTO.setStartTime("01-02-2025 09:00");
    reservationDTO.setEndTime("01-02-2025 10:00");
    reservationDTO.setReservationType(ReservationType::Pilates);
    reservationDTO.setOptionalTrainer(std::make_optional(&trainer));

    BOOST_REQUIRE_EQUAL(reservationDTO.getUser(), &user);
    BOOST_REQUIRE_EQUAL(reservationDTO.getStartTime(), "01-02-2025 09:00");
    BOOST_REQUIRE_EQUAL(reservationDTO.getEndTime(), "01-02-2025 10:00");
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().name, "Pilates");
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().roomNumber, ReservationType::Pilates.roomNumber);
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().maxOccupancy, ReservationType::Pilates.maxOccupancy);
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().description, ReservationType::Pilates.description);
    BOOST_REQUIRE(reservationDTO.getOptionalTrainer().has_value());
    BOOST_REQUIRE_EQUAL(reservationDTO.getOptionalTrainer().value(), &trainer);
}

BOOST_AUTO_TEST_CASE(ReservationDTOOptionalTrainerTest) {
    User user("user123", "John", "Doe", "john.doe@example.com");

    ReservationDTO reservationDTO;
    reservationDTO.setUser(&user);
    reservationDTO.setStartTime("01-02-2025 09:00");
    reservationDTO.setEndTime("01-02-2025 10:00");
    reservationDTO.setReservationType(ReservationType::Cardio);
    reservationDTO.setOptionalTrainer(std::nullopt);

    BOOST_REQUIRE_EQUAL(reservationDTO.getUser(), &user);
    BOOST_REQUIRE_EQUAL(reservationDTO.getStartTime(), "01-02-2025 09:00");
    BOOST_REQUIRE_EQUAL(reservationDTO.getEndTime(), "01-02-2025 10:00");
    BOOST_REQUIRE_EQUAL(reservationDTO.getReservationType().name, "Cardio");
    BOOST_REQUIRE(reservationDTO.getOptionalTrainer().has_value() == false);
}

BOOST_AUTO_TEST_SUITE_END()
