//
// Created by Marcin Kaczmarek on 1/28/25.
//

#include "UserMainPanel.h"


UserMainPanel::UserMainPanel(Controller* userController, Controller* reservationController, User* user) : UserPanel(userController, reservationController, user) {}

void UserMainPanel::handleUserAction() {


    auto userLoginPanel = std::make_unique<UserLoginPanel>(userController, reservationController, getLoggedInUser());
    auto userRegistrationPanel = std::make_unique<UserRegistrationPanel>(userController, reservationController, getLoggedInUser());

    while (true) {
        displayMenu();
        std::string choice = getUserInput("Choose an option");
        if (choice == "1") {
            userLoginPanel->handleUserAction();
        } else if (choice == "2") {
            userRegistrationPanel->handleUserAction();
        } else if (choice == "3") {
            std::cout << "Exiting main panel...\n";
            exit(0);
        } else {
            std::cerr << "Invalid choice. Please try again.\n";
        }

    }
}

void UserMainPanel::displayMenu() {
    clearConsole();
    std::cout << "\n=== Main Panel ===\n";
    std::cout << "1. Log in\n";
    std::cout << "2. Register\n";
    std::cout << "3. Exit\n";
}


