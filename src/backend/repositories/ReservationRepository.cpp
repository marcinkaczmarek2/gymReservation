//
// Created by Jakub Grad on 27/01/2025.
//

#include "ReservationRepository.h"

#include <utility>


ReservationRepository::ReservationRepository(FileManager<Reservation, std::string>* reservationFileManager) {
    this->reservationFileManager = reservationFileManager;
}

Reservation* ReservationRepository::removeEntity(Reservation *entity) {
    return removeEntityById(entity->getUUID());
}

Reservation* ReservationRepository::removeEntityById(std::string id) {

    Reservation* removedMember = reservationFileManager->removeEntityById(id);

    if(removedMember != nullptr) return removedMember;

    return nullptr;
}

Reservation* ReservationRepository::addEntity(Reservation *entity) {
    reservationFileManager->writeFile(entity);
    return entity;
}

std::vector<Reservation*> ReservationRepository::getAllEntities() {

    return reservationFileManager->readFile();
}

Reservation* ReservationRepository::getEntityById(std::string id) {

    return reservationFileManager->getEntityById(id);

}

void ReservationRepository::createOrUpdateEntity(Reservation *entity) {

    removeEntityById(entity->getUUID());
    reservationFileManager->writeFile(entity);

}


std::vector<Reservation*> ReservationRepository::getAllEntitiesByUser(User* user) {

    return reservationFileManager->getEntityByField("traineeID", user->getUUID());

}


std::vector<Reservation*> ReservationRepository::getAllEntitiesByReservationType(ReservationType reservationType) {

    return reservationFileManager->getEntityByField("reservationType", reservationType.name);

}
