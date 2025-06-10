#include <boost/test/unit_test.hpp>
#include "../../../src/backend/entities/Trainer.h"
#include "../../../src/backend/entities/User.h"
BOOST_AUTO_TEST_SUITE(TrainerTestSuite)
BOOST_AUTO_TEST_CASE(TrainerConstructorTest) {
    Trainer trainer("John Smith", "987654321", "john.smith@example.com", 5000.0f, "password");
    BOOST_REQUIRE_EQUAL(trainer.getName(), "John Smith");
    BOOST_REQUIRE_EQUAL(trainer.getPhoneNumber(), "987654321");
    BOOST_REQUIRE_EQUAL(trainer.getEmailAddress(), "john.smith@example.com");
    BOOST_REQUIRE_EQUAL(trainer.getSalary(), 5000.0f);
}
BOOST_AUTO_TEST_CASE(TrainerDefaultConstructorTest) {
    Trainer trainer;
    BOOST_REQUIRE_EQUAL(trainer.getName(), "");
    BOOST_REQUIRE_EQUAL(trainer.getPhoneNumber(), "");
    BOOST_REQUIRE_EQUAL(trainer.getEmailAddress(), "");
    BOOST_REQUIRE_EQUAL(trainer.getSalary(), 0.0f);
}
BOOST_AUTO_TEST_CASE(TrainerSetSalaryTest) {
    Trainer trainer;
    trainer.setSalary(6000.0f);
    BOOST_REQUIRE_EQUAL(trainer.getSalary(), 6000.0f);
}
BOOST_AUTO_TEST_CASE(TrainerJsonConversionTest) {
    Trainer trainer("John Smith", "987654321", "john.smith@example.com", 5000.0f, "password");
    Json json = trainer.toJsonFormat();
    Trainer newTrainer;
    newTrainer.fromJsonFormat(json);
    BOOST_REQUIRE_EQUAL(newTrainer.getName(), "John Smith");
    BOOST_REQUIRE_EQUAL(newTrainer.getPhoneNumber(), "987654321");
    BOOST_REQUIRE_EQUAL(newTrainer.getEmailAddress(), "john.smith@example.com");
    BOOST_REQUIRE_EQUAL(newTrainer.getSalary(), 5000.0f);
}
BOOST_AUTO_TEST_CASE(TrainerSetNameTest) {
    Trainer trainer;
    trainer.setName("Jane Doe");
    BOOST_REQUIRE_EQUAL(trainer.getName(), "Jane Doe");
}
BOOST_AUTO_TEST_CASE(TrainerSetPhoneNumberTest) {
    Trainer trainer;
    trainer.setPhoneNumber("123456789");
    BOOST_REQUIRE_EQUAL(trainer.getPhoneNumber(), "123456789");
}
BOOST_AUTO_TEST_CASE(TrainerSetEmailAddressTest) {
    Trainer trainer;
    trainer.setEmailAddress("jane.doe@example.com");
    BOOST_REQUIRE_EQUAL(trainer.getEmailAddress(), "jane.doe@example.com");
}
BOOST_AUTO_TEST_CASE(TrainerInvalidSalaryTest) {
    Trainer trainer("John Smith", "987654321", "john.smith@example.com", -5000.0f, "password");
    BOOST_REQUIRE_EQUAL(trainer.getSalary(), -5000.0f);
}
BOOST_AUTO_TEST_CASE(TrainerEdgeCaseSalaryTest) {
    Trainer trainer("John Smith", "987654321", "john.smith@example.com", 0.0f, "password");
    BOOST_REQUIRE_EQUAL(trainer.getSalary(), 0.0f);
}
BOOST_AUTO_TEST_CASE(TrainerModifyJsonTest) {
    Trainer trainer("John Smith", "987654321", "john.smith@example.com", 5000.0f, "password");
    Json json = trainer.toJsonFormat();
    json["salary"] = 5500.0f;
    trainer.fromJsonFormat(json);
    BOOST_REQUIRE_EQUAL(trainer.getSalary(), 5500.0f);
}
BOOST_AUTO_TEST_SUITE_END()
