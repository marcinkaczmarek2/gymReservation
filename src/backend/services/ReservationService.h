#ifndef OOP24_WW_MON_0830_07_RESERVATIONSERVICE_H
#define OOP24_WW_MON_0830_07_RESERVATIONSERVICE_H
#include "../repositories/ReservationRepository.h"
#include "Service.h"
#include "../dtos/RegisterDTO.h"
#include "../dtos/ReservationDTO.h"
class ReservationService : Service {
private:
    ReservationRepository* reservationRepository;
public:
    ReservationService(ReservationRepository* reservationRepository);
    Reservation* registerReservation(ReservationDTO reservationDTO);
    std::vector<Reservation*> getUserReservations(User* user);
    std::vector<Reservation*> getReservationsByDateAndUser(std::string startDate, std::string endDate, User* user);
    std::vector<Reservation*> getReservationsByDateAndType(std::string startDate, std::string endDate, ReservationType reservationType);
    Reservation* cancelReservation(Reservation* reservation);
};
#endif //OOP24_WW_MON_0830_07_RESERVATIONSERVICE_H
