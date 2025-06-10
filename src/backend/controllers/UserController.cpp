#include "UserController.h"
#include <utility>
UserController::UserController(UserService *userService) {
    this->userService = userService;
}
User* UserController::deleteUser(User &user) {
    return userService->deleteUser(&user);
}
User* UserController::deleteUserByID(std::string userID) {
    return userService->deleteUserByID(std::move(userID));
}
User* UserController::loginUser(LoginDTO loginDTO) {
    return userService->loginUser(std::move(loginDTO));
}
User* UserController::registerUser(RegisterDTO registerDTO, bool isTrainer) {
    return userService->registerUser(std::move(registerDTO), isTrainer);
}
Trainer *UserController::getTrainerByEmail(std::string trainerEmail) {
    if(!userService->getTrainersByEmail(trainerEmail).empty()) return userService->getTrainersByEmail(trainerEmail).front();
    return nullptr;
}
User *UserController::getUserByID(std::string id) {
    return userService->getUserById(id);
}
std::vector<Trainer *> UserController::getAllTrainers() {
    return userService->getAllTrainers();
}
User *UserController::getUserByEmail(std::string email) {
    return userService->getUserByEmail(email);
}
void UserController::createOrUpdateUser(User *user) {
    userService->createOrUpdateUser(user);
}
bool UserController::setSalaryToTrainer(Trainer* trainer, float salary){
    return userService->setSalaryToTrainer(trainer, salary);
}
bool UserController::extendGymMembership(Member* member, int day, int month, int year) {
    return userService->extendGymMembership(member, day, month, year);
}
