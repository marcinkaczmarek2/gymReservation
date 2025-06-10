#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#include <../src//backend/services/UserService.h>
#include <../src//backend/entities/Trainer.h>
#include "Controller.h"
class UserController : public Controller{
    private:
        UserService* userService;
    public:
        UserController(UserService* userService);
        std::vector<Trainer*> getAllTrainers();
        ~UserController() override = default;
        User* registerUser(RegisterDTO registerDTO, bool isTrainer);
        User* deleteUser(User& user);
        User* deleteUserByID(std::string userID);
        User* loginUser(LoginDTO loginDTO);
        Trainer* getTrainerByEmail(std::string trainerEmail);
        User* getUserByID(std::string userID);
        User* getUserByEmail(std::string email);
        bool setSalaryToTrainer(Trainer* trainer, float salary);
        bool extendGymMembership(Member* member, int day, int month, int year);
        void createOrUpdateUser(User *pUser);
};
#endif //USERCONTROLLER_H
