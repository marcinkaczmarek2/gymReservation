//
// Created by Marcin Kaczmarek on 1/28/25.
//

#include "UserPanel.h"

#include <thread>

UserPanel::UserPanel(Controller* userController, Controller* reservationController, User* user) {
    this->userController = userController;
    this->reservationController = reservationController;
    this->loggedInUser = user;
}

std::string UserPanel::getUserInput(std::string prompt) {
    std::string input;
    while (true) {
        std::cout << prompt << ": ";
        std::getline(std::cin, input);

        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);

        if (input.empty()) {
            std::cerr << "Input cannot be empty. Try again.\n";
            continue;
        }

        return input;
    }
}

void UserPanel::setLoggedInUser(User* user) {
    loggedInUser = user;
}

void UserPanel::clearConsole() {
    std::this_thread::sleep_for(std::chrono::seconds(0.5));
#ifdef _WIN32
    system("cls");
#elif defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
    system("clear");
#else
    std::cerr << "Unsupported platform. Cannot clear console.\n";
#endif
}

User* UserPanel::getLoggedInUser() const {
    return loggedInUser;
}

void UserPanel::userLogout() {
    loggedInUser = nullptr;
}


