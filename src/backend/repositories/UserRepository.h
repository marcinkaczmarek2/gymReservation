//
// Created by Jakub Grad on 25/01/2025.
//

#ifndef OOP24_WW_MON_0830_07_USERREPOSITORY_H
#define OOP24_WW_MON_0830_07_USERREPOSITORY_H


#include "../fileManagers/FileManager.h"
#include "Repository.h"

class UserRepository : Repository<User, std::string> {

    private:
        FileManager<Trainer, std::string>* trainerFileManager;
        FileManager<Member, std::string>* memberFileManager;

    public:

        UserRepository(FileManager<Trainer, std::string>* trainerFileManager, FileManager<Member, std::string>* memberFileManager);

        User* removeEntity(User* entity) override;

        User* removeEntityById(std::string id) override;

        User* addEntity(User* entity) override;

        std::vector<User*> getAllEntities() override;

        User* getEntityById(std::string id) override;

        std::vector<User*> getEntitiesByEmail(std::string email);
        std::vector<Trainer*> getAllTrainers();
        std::vector<Trainer*> getTrainersByEmail(std::string email);

        void createOrUpdateEntity(User* entity) override;
};


#endif //OOP24_WW_MON_0830_07_USERREPOSITORY_H
