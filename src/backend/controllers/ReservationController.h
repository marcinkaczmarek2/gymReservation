#ifndef RESERVATIONCONTROLLER_H
#define RESERVATIONCONTROLLER_H
#include "../entities/Reservation.h"
#include "Controller.h"
#include "../services/ReservationService.h"
class ReservationController: public Controller {
    private:
        ReservationService* reservationService;
    public:
        ReservationController(ReservationService* reservationService);
        ~ReservationController() override = default;
        Reservation* registerReservation(ReservationDTO reservationDTO);
        bool cancelReservation(Reservation* reservation);
        bool cancelReservationByID(std::string reservationID);
        std::vector<Reservation*> getReservationsByDateAndUser(std::string startDate, std::string endDate, User* user);
        std::vector<Reservation*> getUserReservations(User* user);
};
#endif //RESERVATIONCONTROLLER_H
