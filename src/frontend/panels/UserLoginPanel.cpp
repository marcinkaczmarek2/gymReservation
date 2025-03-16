//
// Created by Marcin Kaczmarek on 1/28/25.
//

#include "UserLoginPanel.h"
#include "AdminPanel.h"

UserLoginPanel::UserLoginPanel(Controller* userController, Controller* reservationController, User* user) : UserPanel(userController, reservationController, user) {}

void UserLoginPanel::handleUserAction() {
    displayMenu();
    auto userMainPanel = std::make_unique<UserMainPanel>(userController, reservationController, getLoggedInUser());
    auto adminPanel = std::make_unique<AdminPanel>(userController, reservationController, getLoggedInUser());

    while (true) {
        std::string choice = getUserInput("Choose an option");
        if (choice == "1") {
            std::string email = getUserInput("Enter your email");
            std::string password = getUserInput("Enter your password");

            LoginDTO loginDTO = {email, password};
            User* user = dynamic_cast<UserController*>(userController)->loginUser(loginDTO);

            if (user!=nullptr) {
                std::cout << "Login successful!\n";
                setLoggedInUser(user);
                auto userReservationPanel = std::make_unique<UserReservationPanel>(userController, reservationController, getLoggedInUser());
                userReservationPanel->handleUserAction();
            } else {
                std::cerr << "Invalid email or password for User. Please try again.\n";
            }
        } else if (choice == "2") {
            std::cout << "Login as admin...\n";

            std::string email = getUserInput("Enter admin login");
            std::string password = getUserInput("Enter admin password");
            if(email == "admin" && password == "admin") {
                std::cout << "Login successful!\n";
                adminPanel->handleUserAction();
            } else {
                std::cerr << "Invalid email or password for Admin. Please try again.\n";
            }

        }else if (choice == "3") {
            std::cout << "Exiting login panel...\n";
            userMainPanel->handleUserAction();
        } else {
            std::cerr << "Invalid choice. Please try again.\n";
        }

    }
}


void UserLoginPanel::displayMenu() {
    clearConsole();
    std::cout << "\n=== User Login Panel ===\n";
    std::cout << "1. Log in\n";
    std::cout << "2. Log in as Admin\n";
    std::cout << "3. Exit\n";
}