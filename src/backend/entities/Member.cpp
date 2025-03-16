//
// Created by Marcin Kaczmarek on 1/25/25.
//

#include "Member.h"
#include "../utills/DateUtill.h"

#include <sstream>

std::string Member::getGymMembershipEndDate() const {
    return gymMembershipEndDate;
}

void Member::setGymMembershipEndDate(std::string gymMembershipEndDate) {
    this->gymMembershipEndDate = std::move(gymMembershipEndDate);
}
Member::Member(std::string name, std::string phoneNumber, std::string emailAddress, std::string gymMembershipEndDate, std::string password)

: User(std::move(name), std::move(password), std::move(phoneNumber), std::move(emailAddress)) {

    this->gymMembershipEndDate = std::move(gymMembershipEndDate);
}

Member::Member() : User() {
}


bool Member::isMembershipValid() {


    return DateUtill::isPrevious(DateUtill::getLocalDateTimeNow(), gymMembershipEndDate);

}


Json Member::toJsonFormat() {
    return {
        {"uuid", uuid},
        {"name", name},
        {"phoneNumber", phoneNumber},
        {"emailAddress", emailAddress},
        {"password", password},

        {"gymMembershipEndDate", gymMembershipEndDate}
    };
}

void Member::fromJsonFormat(Json json) {
    if (json.contains("uuid")) uuid = json["uuid"].get<std::string>();
    if (json.contains("name")) name = json["name"].get<std::string>();
    if (json.contains("phoneNumber")) phoneNumber = json["phoneNumber"].get<std::string>();
    if (json.contains("emailAddress")) emailAddress = json["emailAddress"].get<std::string>();
    if (json.contains("password")) password = json["password"].get<std::string>();
    if (json.contains("gymMembershipEndDate")) gymMembershipEndDate = json["gymMembershipEndDate"].get<std::string>();
}

