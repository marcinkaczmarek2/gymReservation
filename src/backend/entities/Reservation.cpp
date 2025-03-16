//
// Created by Marcin Kaczmarek on 1/25/25.
//
#include "Reservation.h"

#include <optional>
#include <utility>

std::string Reservation::getUUID() {
    return this->uuid;
}

Json Reservation::toJsonFormat() {
    return {
            {"uuid", uuid},
            {"startTime", startTime},
            {"endTime", endTime},
            {"traineeID", traineeID},
            {"reservationType", reservationType.name},
            {"canceled", canceled},
            {"trainer", optionalTrainerID.has_value() ? optionalTrainerID : "null"}
    };
}

void Reservation::fromJsonFormat(Json json) {
    if (json.contains("uuid")) uuid = json["uuid"].get<std::string>();
    if (json.contains("startTime")) startTime = json["startTime"].get<std::string>();
    if (json.contains("endTime")) endTime = json["endTime"].get<std::string>();
    if (json.contains("traineeID")) traineeID = json["traineeID"].get<std::string>();
    if (json.contains("canceled")) canceled = json["canceled"].get<bool>();
    if (json.contains("reservationType")) reservationType = ReservationType::getByName(json["reservationType"].get<std::string>());
    if (json.contains("trainer")) {
        std::string value = json["trainer"].get<std::string>();
        optionalTrainerID =std::optional<std::string>(value);
    }
}


Reservation::Reservation(std::string startTime, std::string endTime, std::string traineeID, ReservationType reservationType): startTime(std::move(startTime)), endTime(std::move(endTime)), traineeID(std::move(traineeID)), reservationType(std::move(reservationType)) {

    uuid_t uuid;
    uuid_generate(uuid);
    char uuid_str[37];
    uuid_unparse(uuid, uuid_str);

    this->uuid = std::string(uuid_str);

    this->canceled = false;
}

Reservation::Reservation(std::string startTime, std::string endTime, std::string traineeID, ReservationType reservationType, std::optional<std::string> optionalTrainerID): startTime(std::move(startTime)), endTime(std::move(endTime)), traineeID(std::move(traineeID)), reservationType(std::move(reservationType)), optionalTrainerID(std::move(optionalTrainerID)) {

    uuid_t uuid;
    uuid_generate(uuid);
    char uuid_str[37];
    uuid_unparse(uuid, uuid_str);

    this->uuid = std::string(uuid_str);
    this->canceled = false;

}


Reservation::Reservation() {

}

std::string Reservation::getTraineeID() {
    return traineeID;
}

std::string Reservation::getEndTime() {
    return endTime;
}

std::optional<std::string> Reservation::getOptionalTrainerID() {
    return optionalTrainerID;
}

ReservationType Reservation::getReservationType() {
    return reservationType;
}

std::string Reservation::getStartTime() {
    return startTime;
}

void Reservation::setTraineeID(std::string traineeID) {
    this->traineeID = std::move(traineeID);
}

void Reservation::setEndTime(std::string endTime) {
    this->endTime = std::move(endTime);
}

void Reservation::setStartTime(std::string startTime) {
    this->startTime = std::move(startTime);
}

void Reservation::setOptionalTrainerID(std::optional<std::string> optionalTrainerID) {
    this->optionalTrainerID = std::move(optionalTrainerID);
}

void Reservation::setReservationType(ReservationType reservationType) {
    this->reservationType = std::move(reservationType);
}

void Reservation::setCanceled(bool canceled) {
    this->canceled = canceled;
}

bool Reservation::isCanceled() {
    return canceled;
}







