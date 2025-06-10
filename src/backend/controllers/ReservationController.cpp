#include "ReservationController.h"
#include <utility>
ReservationController::ReservationController(ReservationService *reservationService) {
    this->reservationService = reservationService;
}
bool ReservationController::cancelReservation(Reservation* reservation) {
    auto* cancelledReservation = new Reservation();
    cancelledReservation = reservationService->cancelReservation(reservation);
    bool success = false;
    if (cancelledReservation != nullptr) {
        success = true;
    }
    delete cancelledReservation;
    return success;
}
bool ReservationController::cancelReservationByID(std::string reservationID) {
    Reservation* cancelledReservation = new Reservation();
    bool success = false;
    if (cancelledReservation != nullptr) {
        success = true;
    }
    delete cancelledReservation;
    return success;
}
Reservation* ReservationController::registerReservation(ReservationDTO reservationDTO) {
    return reservationService->registerReservation(std::move(reservationDTO));
}
std::vector<Reservation*> ReservationController::getReservationsByDateAndUser(std::string startDate, std::string endDate, User* user) {
    return reservationService->getReservationsByDateAndUser(startDate, endDate, user);
}
std::vector<Reservation *> ReservationController::getUserReservations(User *user) {
    return reservationService->getUserReservations(user);
}
