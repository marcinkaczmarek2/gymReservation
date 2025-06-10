#include "ReservationDTO.h"
User *const ReservationDTO::getUser() const {
    return user;
}
void ReservationDTO::setUser(User* user) {
    this->user = user;
}
const std::string ReservationDTO::getStartTime() const {
    return startTime;
}
void ReservationDTO::setStartTime(std::string startTime) {
    ReservationDTO::startTime = startTime;
}
const std::string ReservationDTO::getEndTime() const {
    return endTime;
}
void ReservationDTO::setEndTime(std::string endTime) {
    ReservationDTO::endTime = endTime;
}
const ReservationType ReservationDTO::getReservationType() const {
    return reservationType;
}
void ReservationDTO::setReservationType(ReservationType reservationType) {
    ReservationDTO::reservationType = reservationType;
}
const std::optional<Trainer *> ReservationDTO::getOptionalTrainer() const {
    return optionalTrainer;
}
void ReservationDTO::setOptionalTrainer(std::optional<Trainer *> optionalTrainer) {
    ReservationDTO::optionalTrainer = optionalTrainer;
}
