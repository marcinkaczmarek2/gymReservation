//
// Created by Jakub Grad on 28/01/2025.
//

#include "ReservationService.h"
#include "../utills/DateUtill.h"

Reservation* ReservationService::cancelReservation(Reservation *reservation) {

    reservation->setCanceled(true);
    reservationRepository->createOrUpdateEntity(reservation);
    return reservation;
}


std::vector<Reservation *> ReservationService::getReservationsByDateAndUser(std::string startDate, std::string endDate, User *user) {

    std::vector<Reservation *> reservations;


    for(Reservation* reservation : reservationRepository->getAllEntitiesByUser(user)) {

        bool w1 = !DateUtill::isPrevious(reservation->getStartTime(), endDate);
        bool w2 = DateUtill::isPrevious(reservation->getEndTime(), startDate );



        if (w1 || w2) {
            continue;
        }

        reservations.push_back(reservation);

    }


    return reservations;
}

std::vector<Reservation *> ReservationService::getUserReservations(User *user) {
    return reservationRepository->getAllEntitiesByUser(user);
}


ReservationService::ReservationService(ReservationRepository * reservationRepository) {
    this->reservationRepository = reservationRepository;
}

Reservation* ReservationService::registerReservation(ReservationDTO reservationDTO) {

    if (dynamic_cast<Member*>(reservationDTO.getUser())) {
        Member* member = dynamic_cast<Member*>(reservationDTO.getUser());
        if (!member->isMembershipValid()) {
            return nullptr;
        }
    }

    int ocuppiedSpots = 0;
    for(Reservation* reservation : reservationRepository->getAllEntitiesByReservationType(reservationDTO.getReservationType())) {
        if(reservation->isCanceled()) continue;
        if(!(DateUtill::isPrevious(reservation->getEndTime(), reservationDTO.getStartTime())
        || DateUtill::isPrevious(reservationDTO.getEndTime(), reservation->getStartTime()))) {

            ocuppiedSpots++;
        }
    }



    if(reservationDTO.getReservationType().maxOccupancy < ocuppiedSpots) {
        return nullptr;
    }


    std::string trainerID = "NULL";

    if(reservationDTO.getOptionalTrainer().has_value()) {
        //if(reservationDTO.optionalTrainer.value()==nullptr || reservationDTO.optionalTrainer.value()->getUUID()==std::nullopt)
        trainerID = reservationDTO.getOptionalTrainer().value()->getUUID();
    }
    auto* reservation = new Reservation(reservationDTO.getStartTime(), reservationDTO.getEndTime(), reservationDTO.getUser()->getUUID(), reservationDTO.getReservationType(), trainerID);

    reservationRepository->createOrUpdateEntity(reservation);

    return reservation;
}

std::vector<Reservation*> ReservationService::getReservationsByDateAndType(std::string startDate, std::string endDate, ReservationType reservationType) {

    std::vector<Reservation*> reservations;

    for(Reservation* reservation : reservationRepository->getAllEntities()) {

        if(reservation->getReservationType().name == reservationType.name) continue;

        bool doesStartAfterEnd = !DateUtill::isPrevious(startDate, reservation->getEndTime());
        bool doesEndAfterStart = !DateUtill::isPrevious(endDate, reservation->getStartTime());

        if (doesEndAfterStart || doesStartAfterEnd) {
            reservations.push_back(reservation);
        }

    }

    return reservations;
}
