#include "UserRepository.h"
#include <utility>
UserRepository::UserRepository(FileManager<Trainer, std::string>* trainerFileManager, FileManager<Member, std::string>* memberFileManager) {
    this->trainerFileManager = trainerFileManager;
    this->memberFileManager = memberFileManager;
}
User* UserRepository::removeEntity(User *entity) {
    return removeEntityById(entity->getUUID());
}
User* UserRepository::removeEntityById(std::string id) {
    User* removedMember = memberFileManager->removeEntityById(id);
    User* removedTrainer = trainerFileManager->removeEntityById(id);
    if(removedMember != nullptr) return removedMember;
    if(removedTrainer != nullptr) return removedTrainer;
    return nullptr;
}
User* UserRepository::addEntity(User *entity) {
    if (dynamic_cast<Trainer*>(entity)) {
        trainerFileManager->writeFile(dynamic_cast<Trainer*>(entity));
        return dynamic_cast<Trainer*>(entity);
    } else if (dynamic_cast<Member*>(entity)) {
        memberFileManager->writeFile(dynamic_cast<Member*>(entity));
        return dynamic_cast<Member*>(entity);
    }
}
std::vector<User*> UserRepository::getAllEntities() {
    std::vector<User*> userVec;
    std::vector<Member*> memberVec = memberFileManager->readFile();
    for (Member* member : memberVec) userVec.push_back(member);
    std::vector<Trainer*> trainerVec = trainerFileManager->readFile();
    for (Trainer* trainer : trainerVec) userVec.push_back(trainer);
    return userVec;
}
User* UserRepository::getEntityById(std::string id) {
    User* trainer = trainerFileManager->getEntityById(id);
    if(trainer != nullptr) return trainer;
    User* member = memberFileManager->getEntityById(id);
    if(member != nullptr) return member;
    return nullptr;
}
std::vector<User*> UserRepository::getEntitiesByEmail(std::string email) {
    std::vector<User*> userVec;
    std::vector<Member*> members = memberFileManager->getEntityByField("emailAddress", email);
    std::vector<Trainer*> trainers = trainerFileManager->getEntityByField("emailAddress", email);
    for (Member* member : members) userVec.push_back(member);
    for (Trainer* trainer : trainers) userVec.push_back(trainer);
    return userVec;
}
std::vector<Trainer*> UserRepository::getAllTrainers() {
    return trainerFileManager->readFile();
}
void UserRepository::createOrUpdateEntity(User *entity) {
    if (dynamic_cast<Trainer*>(entity)) {
        removeEntityById(entity->getUUID());
        trainerFileManager->writeFile(dynamic_cast<Trainer*>(entity));
    } else if (dynamic_cast<Member*>(entity)) {
        removeEntityById(entity->getUUID());
        memberFileManager->writeFile(dynamic_cast<Member*>(entity));
    }
}
std::vector<Trainer *> UserRepository::getTrainersByEmail(std::string email) {
    return trainerFileManager->getEntityByField("emailAddress", email);
}
