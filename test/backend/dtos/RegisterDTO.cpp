#include <boost/test/unit_test.hpp>
#include "../../../src/backend/dtos/RegisterDTO.h"
BOOST_AUTO_TEST_SUITE(RegisterDTOTestSuite)
BOOST_AUTO_TEST_CASE(RegisterDTOConstructorTest) {
    RegisterDTO registerDTO;
    registerDTO.name = "John Doe";
    registerDTO.password = "password123";
    registerDTO.confirmPassword = "password123";
    registerDTO.phoneNumber = "123-456-7890";
    registerDTO.emailAddress = "johndoe@example.com";
    BOOST_REQUIRE_EQUAL(registerDTO.name, "John Doe");
    BOOST_REQUIRE_EQUAL(registerDTO.password, "password123");
    BOOST_REQUIRE_EQUAL(registerDTO.confirmPassword, "password123");
    BOOST_REQUIRE_EQUAL(registerDTO.phoneNumber, "123-456-7890");
    BOOST_REQUIRE_EQUAL(registerDTO.emailAddress, "johndoe@example.com");
}
BOOST_AUTO_TEST_CASE(RegisterDTOSettersTest) {
    RegisterDTO registerDTO;
    registerDTO.name = "Jane Doe";
    registerDTO.password = "password456";
    registerDTO.confirmPassword = "password456";
    registerDTO.phoneNumber = "987-654-3210";
    registerDTO.emailAddress = "janedoe@example.com";
    BOOST_REQUIRE_EQUAL(registerDTO.name, "Jane Doe");
    BOOST_REQUIRE_EQUAL(registerDTO.password, "password456");
    BOOST_REQUIRE_EQUAL(registerDTO.confirmPassword, "password456");
    BOOST_REQUIRE_EQUAL(registerDTO.phoneNumber, "987-654-3210");
    BOOST_REQUIRE_EQUAL(registerDTO.emailAddress, "janedoe@example.com");
}
BOOST_AUTO_TEST_CASE(RegisterDTOEmptyFieldsTest) {
    RegisterDTO registerDTO;
    BOOST_REQUIRE_EQUAL(registerDTO.name, "");
    BOOST_REQUIRE_EQUAL(registerDTO.password, "");
    BOOST_REQUIRE_EQUAL(registerDTO.confirmPassword, "");
    BOOST_REQUIRE_EQUAL(registerDTO.phoneNumber, "");
    BOOST_REQUIRE_EQUAL(registerDTO.emailAddress, "");
}
BOOST_AUTO_TEST_CASE(RegisterDTOSetNameTest) {
    RegisterDTO registerDTO;
    registerDTO.name = "Alice Smith";
    BOOST_REQUIRE_EQUAL(registerDTO.name, "Alice Smith");
    BOOST_REQUIRE_EQUAL(registerDTO.password, "");
    BOOST_REQUIRE_EQUAL(registerDTO.confirmPassword, "");
    BOOST_REQUIRE_EQUAL(registerDTO.phoneNumber, "");
    BOOST_REQUIRE_EQUAL(registerDTO.emailAddress, "");
}
BOOST_AUTO_TEST_CASE(RegisterDTOSetEmailTest) {
    RegisterDTO registerDTO;
    registerDTO.emailAddress = "alice.smith@example.com";
    BOOST_REQUIRE_EQUAL(registerDTO.emailAddress, "alice.smith@example.com");
    BOOST_REQUIRE_EQUAL(registerDTO.name, "");
    BOOST_REQUIRE_EQUAL(registerDTO.password, "");
    BOOST_REQUIRE_EQUAL(registerDTO.confirmPassword, "");
    BOOST_REQUIRE_EQUAL(registerDTO.phoneNumber, "");
}
BOOST_AUTO_TEST_CASE(RegisterDTOSetPasswordAndConfirmPasswordTest) {
    RegisterDTO registerDTO;
    registerDTO.password = "password789";
    registerDTO.confirmPassword = "password789";
    BOOST_REQUIRE_EQUAL(registerDTO.password, "password789");
    BOOST_REQUIRE_EQUAL(registerDTO.confirmPassword, "password789");
}
BOOST_AUTO_TEST_SUITE_END()
