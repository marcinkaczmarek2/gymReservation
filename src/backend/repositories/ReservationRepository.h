//
// Created by Jakub Grad on 27/01/2025.
//

#ifndef OOP24_WW_MON_0830_07_RESERVATIONREPOSITORY_H
#define OOP24_WW_MON_0830_07_RESERVATIONREPOSITORY_H

#include "../fileManagers/FileManager.h"
#include "../repositories/Repository.h"

class ReservationRepository : Repository<Reservation, std::string> {

    private:
        FileManager<Reservation, std::string>* reservationFileManager;

    public:

        ReservationRepository(FileManager<Reservation, std::string>* reservationFileManager);

        Reservation* removeEntity(Reservation* entity) override;

        Reservation* removeEntityById(std::string id) override;

        Reservation* addEntity(Reservation* entity) override;

        std::vector<Reservation*> getAllEntities() override;

        std::vector<Reservation*> getAllEntitiesByUser(User* user);

        Reservation* getEntityById(std::string id) override;

        void createOrUpdateEntity(Reservation *entity) override;

        std::vector<Reservation*> getAllEntitiesByReservationType(ReservationType reservationType);


};


#endif //OOP24_WW_MON_0830_07_RESERVATIONREPOSITORY_H
