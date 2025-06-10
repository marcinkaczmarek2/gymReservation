#include <boost/test/unit_test.hpp>
#include "../../../src/backend/dtos/LoginDTO.h"
BOOST_AUTO_TEST_SUITE(LoginDTOTestSuite)
BOOST_AUTO_TEST_CASE(LoginDTOConstructorTest) {
    LoginDTO loginDTO;
    loginDTO.emailAddress = "user@example.com";
    loginDTO.password = "password123";
    BOOST_REQUIRE_EQUAL(loginDTO.emailAddress, "user@example.com");
    BOOST_REQUIRE_EQUAL(loginDTO.password, "password123");
}
BOOST_AUTO_TEST_CASE(LoginDTOSettersTest) {
    LoginDTO loginDTO;
    loginDTO.emailAddress = "newuser@example.com";
    loginDTO.password = "newpassword456";
    BOOST_REQUIRE_EQUAL(loginDTO.emailAddress, "newuser@example.com");
    BOOST_REQUIRE_EQUAL(loginDTO.password, "newpassword456");
}
BOOST_AUTO_TEST_CASE(LoginDTOEmptyFieldsTest) {
    LoginDTO loginDTO;
    BOOST_REQUIRE_EQUAL(loginDTO.emailAddress, "");
    BOOST_REQUIRE_EQUAL(loginDTO.password, "");
}
BOOST_AUTO_TEST_CASE(LoginDTOSetEmailTest) {
    LoginDTO loginDTO;
    loginDTO.emailAddress = "testuser@example.com";
    BOOST_REQUIRE_EQUAL(loginDTO.emailAddress, "testuser@example.com");
    BOOST_REQUIRE_EQUAL(loginDTO.password, "");
}
BOOST_AUTO_TEST_CASE(LoginDTOSetPasswordTest) {
    LoginDTO loginDTO;
    loginDTO.password = "password789";
    BOOST_REQUIRE_EQUAL(loginDTO.password, "password789");
    BOOST_REQUIRE_EQUAL(loginDTO.emailAddress, "");
}
BOOST_AUTO_TEST_SUITE_END()
