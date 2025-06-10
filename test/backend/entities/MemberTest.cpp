#include <boost/test/unit_test.hpp>
#include "../../../src/backend/entities/Member.h"
#include "../../../src/backend/entities/User.h"
BOOST_AUTO_TEST_SUITE(MemberTestSuite)
BOOST_AUTO_TEST_CASE(MemberConstructorTest) {
    Member member("test", "123456789", "test@example.com", "31-12-2026 00:00", "password");
    BOOST_REQUIRE_EQUAL(member.getName(), "test");
    BOOST_REQUIRE_EQUAL(member.getPhoneNumber(), "123456789");
    BOOST_REQUIRE_EQUAL(member.getEmailAddress(), "test@example.com");
    BOOST_REQUIRE_EQUAL(member.getGymMembershipEndDate(), "31-12-2026 00:00");
}
BOOST_AUTO_TEST_CASE(MemberDefaultConstructorTest) {
    Member member;
    BOOST_REQUIRE_EQUAL(member.getName(), "");
    BOOST_REQUIRE_EQUAL(member.getPhoneNumber(), "");
    BOOST_REQUIRE_EQUAL(member.getEmailAddress(), "");
    BOOST_REQUIRE_EQUAL(member.getGymMembershipEndDate(), "");
}
BOOST_AUTO_TEST_CASE(MemberSetGymMembershipEndDateTest) {
    Member member;
    member.setGymMembershipEndDate("31-12-2026 00:00");
    BOOST_REQUIRE_EQUAL(member.getGymMembershipEndDate(), "31-12-2026 00:00");
}
BOOST_AUTO_TEST_CASE(MemberIsMembershipValidTest) {
    Member validMember("test", "123456789", "test@example.com", "31-12-2096 00:00", "password");
    Member expiredMember("test", "123456789", "test@example.com", "31-12-2001 00:00", "password");
    BOOST_REQUIRE(validMember.isMembershipValid());
    BOOST_REQUIRE(!expiredMember.isMembershipValid());
}
BOOST_AUTO_TEST_CASE(MemberJsonConversionTest) {
    Member member("test", "123456789", "test@example.com", "31-12-2026 00:00", "password");
    Json json = member.toJsonFormat();
    Member newMember;
    newMember.fromJsonFormat(json);
    BOOST_REQUIRE_EQUAL(newMember.getName(), "test");
    BOOST_REQUIRE_EQUAL(newMember.getPhoneNumber(), "123456789");
    BOOST_REQUIRE_EQUAL(newMember.getEmailAddress(), "test@example.com");
    BOOST_REQUIRE_EQUAL(newMember.getGymMembershipEndDate(), "31-12-2026 00:00");
}
BOOST_AUTO_TEST_CASE(MemberSetNameTest) {
    Member member;
    member.setName("John Doe");
    BOOST_REQUIRE_EQUAL(member.getName(), "John Doe");
}
BOOST_AUTO_TEST_CASE(MemberSetPhoneNumberTest) {
    Member member;
    member.setPhoneNumber("987654321");
    BOOST_REQUIRE_EQUAL(member.getPhoneNumber(), "987654321");
}
BOOST_AUTO_TEST_CASE(MemberSetEmailAddressTest) {
    Member member;
    member.setEmailAddress("john.doe@example.com");
    BOOST_REQUIRE_EQUAL(member.getEmailAddress(), "john.doe@example.com");
}
BOOST_AUTO_TEST_CASE(MemberInvalidMembershipDateTest) {
    Member member("test", "123456789", "test@example.com", "invalid-date", "password");
    BOOST_REQUIRE(!member.isMembershipValid());
}
BOOST_AUTO_TEST_CASE(MemberEdgeCaseMembershipDateTest) {
    Member member("test", "123456789", "test@example.com", "31-12-2026 00:00", "password");
    BOOST_REQUIRE(member.isMembershipValid());
}
BOOST_AUTO_TEST_CASE(MemberModifyJsonTest) {
    Member member("test", "123456789", "test@example.com", "31-12-2026 00:00", "password");
    Json json = member.toJsonFormat();
    json["name"] = "Updated Name";
    member.fromJsonFormat(json);
    BOOST_REQUIRE_EQUAL(member.getName(), "Updated Name");
}
BOOST_AUTO_TEST_SUITE_END()