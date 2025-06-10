#ifndef OOP24_WW_MON_0830_07_USERSERVICE_H
#define OOP24_WW_MON_0830_07_USERSERVICE_H
#include "../repositories/UserRepository.h"
#include "../dtos/RegisterDTO.h"
#include "../dtos/LoginDTO.h"
#include "Service.h"
class UserService : Service {
    private:
        UserRepository* userRepository;
    public:
        UserService(UserRepository* userRepository);
        User* registerUser(RegisterDTO registerDTO, bool isTrainer);
        User* loginUser(LoginDTO loginDTO);
        bool setSalaryToTrainer(Trainer* trainer, float salary);
        bool extendGymMembership(Member* member, int day, int month, int year);
        User* deleteUser(User* user);
        User* deleteUserByID(std::string id);
        std::vector<Trainer*> getAllTrainers();
        User * getUserById(std::string id);
        std::vector<Trainer*> getTrainersByEmail(std::string email);
        User* getUserByEmail(std::string email);
    void createOrUpdateUser(User *pUser);
};
#endif //OOP24_WW_MON_0830_07_USERSERVICE_H
