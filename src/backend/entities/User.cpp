//
// Created by Marcin Kaczmarek on 1/25/25.
//


#include "User.h"

#include <iostream>

User::User(std::string name, std::string password, std::string phoneNumber, std::string emailAddress): name(std::move(name)), password(std::move(password)), phoneNumber(std::move(phoneNumber)), emailAddress(std::move(emailAddress)) {
    UUID uuid;
    uuid_generate(uuid);
    char uuid_str[37];
    uuid_unparse(uuid, uuid_str);
    this->uuid = std::string(uuid_str);
}

User::User(): name(""), password(""), phoneNumber(""), emailAddress("")  {
    UUID uuid;
    uuid_generate(uuid);
    char uuid_str[37];
    uuid_unparse(uuid, uuid_str);
    this->uuid = std::string(uuid_str);
}

std::string User::getName() const {
    return name;
}

void User::setName(std::string name) {
    this->name = std::move(name);
}

std::string User::getEmailAddress() const {
    return emailAddress;
}

std::string User::getPhoneNumber() const {
    return phoneNumber;
}

void User::setEmailAddress(std::string emailAddress) {
    this->emailAddress = std::move(emailAddress);
}

void User::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = std::move(phoneNumber);
}

bool User::validatePassword(std::string input) {
    return std::equal(password.begin(), password.end(), input.begin());
}

void User::setPassword(std::string password) {
    this->password = std::move(password);
}

std::string User::getUUID() {
    return uuid;
}


Json User::toJsonFormat() {
    return {
            {"uuid", uuid},
            {"name", name},
            {"password", password},
            {"phoneNumber", phoneNumber},
            {"emailAddress", emailAddress},
    };
}

void User::fromJsonFormat(Json json) {

    if (json.contains("uuid")) uuid = json["uuid"].get<std::string>();
    if (json.contains("name")) name = json["name"].get<std::string>();
    if (json.contains("password")) password = json["password"].get<std::string>();
    if (json.contains("phoneNumber")) phoneNumber = json["phoneNumber"].get<std::string>();
    if (json.contains("emailAddress")) emailAddress = json["emailAddress"].get<std::string>();

}
