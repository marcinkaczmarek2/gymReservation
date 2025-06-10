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
			std::cout << "userController pointer: " << userController << "\n";
			UserController* uc = dynamic_cast<UserController*>(userController);
			std::cout << "UserController pointer after dynamic_cast: " << uc << "\n";
			if (!uc) {
				std::cerr << "Error: userController is not a UserController.\n";
				continue;
}

			User* user = nullptr;
			try {
				user = uc->loginUser(loginDTO);
			} catch(const std::exception& e) {
				std::cerr << "Wrong user credentials.\n";
			}

			if (user != nullptr) {
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