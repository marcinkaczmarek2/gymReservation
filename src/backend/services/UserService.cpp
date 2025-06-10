//
// Created by Jakub Grad on 27/01/2025.
//

#include "UserService.h"
#include "../utills/DateUtill.h"

#include <utility>

bool UserService::setSalaryToTrainer(Trainer *trainer, float salary) {

    trainer->setSalary(salary);
    userRepository->createOrUpdateEntity(trainer);

    return true;
}

UserService::UserService(UserRepository* userRepository) {
    this->userRepository = std::move(userRepository);
}

User* UserService::registerUser(RegisterDTO registerDTO, bool isTrainer) {

    bool isMailRegistered = false;

    if(userRepository->getEntitiesByEmail(registerDTO.emailAddress).size() > 0) isMailRegistered = true;

    if(isMailRegistered) {
        return nullptr;
    }

    if(registerDTO.password != registerDTO.confirmPassword) {
        return nullptr;
    }

    User* user;

    if(isTrainer) {
        user = new Trainer(registerDTO.name, registerDTO.phoneNumber, registerDTO.emailAddress, 0, registerDTO.password);
    } else {
        user = new Member(registerDTO.name, registerDTO.phoneNumber, registerDTO.emailAddress, DateUtill::getLocalDateTimeNow(), registerDTO.password);
    }

    return userRepository->addEntity(user);

}

User* UserService::loginUser(LoginDTO loginDTO) {
    User* user = getUserByEmail(loginDTO.emailAddress);

    if (!user) {
        std::cerr << "User not found for email: " << loginDTO.emailAddress << "\n";
        return nullptr;
    }

    if (!user->validatePassword(loginDTO.password)) {
        return nullptr;
    }

    return user;
}

bool UserService::extendGymMembership(Member* member, int day, int month, int year) {

    std::string date = DateUtill::getLocalDateTimeOf(day, month, year, 0, 0);

    member->setGymMembershipEndDate(date);
    userRepository->createOrUpdateEntity(member);
    return true;
}

User *UserService::deleteUser(User* user) {

    return userRepository->removeEntity(user);
}

User *UserService::deleteUserByID(std::string id) {
    return userRepository->removeEntityById(id);
}

std::vector<Trainer *> UserService::getAllTrainers() {
    return userRepository->getAllTrainers();
}

User* UserService::getUserById(std::string id) {

    return userRepository->getEntityById(id);

}
std::vector<Trainer *> UserService::getTrainersByEmail(std::string email) {
    return userRepository->getTrainersByEmail(email);
}

User *UserService::getUserByEmail(std::string email) {


    std::vector<User*> usersWithEmail = userRepository->getEntitiesByEmail(email);

    if(usersWithEmail.size() > 1) {
        std::cerr << "Powqazny blad! Wiecej niz jeden uzytkownik z emailem - to sie nigdy nie powinno wydazyc" << std::endl;
        return nullptr;
    }

    if(usersWithEmail.size() != 1) {
        return nullptr;
    }

    User* user = usersWithEmail.front();

    return user;
}

void UserService::createOrUpdateUser(User *pUser) {
    userRepository->createOrUpdateEntity(pUser);
}

