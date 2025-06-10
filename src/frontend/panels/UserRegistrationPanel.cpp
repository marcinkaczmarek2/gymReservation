#include "UserRegistrationPanel.h"
UserRegistrationPanel::UserRegistrationPanel(Controller* userController, Controller* reservationController, User* user) : UserPanel(userController, reservationController, user) {}
void UserRegistrationPanel::handleUserAction() {
    auto userMainPanel = std::make_unique<UserMainPanel>(userController, reservationController, getLoggedInUser());
    while (true) {
        displayMenu();
        std::string choice = getUserInput("Choose an option");
        if (choice == "1") {
            std::string name = getUserInput("Enter name");
            std::string password = getUserInput("Enter password");
            std::string confirmPassword = getUserInput("Confirm your password");
            if (password != confirmPassword) {
                std::cerr << "Passwords are not the same. Try again.\n";
                break;
            }
            std::string phone = getPhoneNumber("Enter phone number");
            std::string email = getEmail("Enter email");
            RegisterDTO registerDTO = {name, password, confirmPassword, phone, email};
            User* user = dynamic_cast<UserController*>(userController)->registerUser(registerDTO, false);
            if (user != nullptr) {
                std::cout << "Registration successful! You can now log in.\n";
                userMainPanel->handleUserAction();
            } else {
                std::cerr << "Email is already in use. Try a different one.\n";
            }
        } else if (choice == "2") {
            std::string name = getUserInput("Enter name");
            std::string password = getUserInput("Enter password");
            std::string confirmPassword = getUserInput("Confirm your password");
            std::string phone = getPhoneNumber("Enter phone number");
            std::string email = getEmail("Enter email");
            RegisterDTO registerDTO = {name, password, confirmPassword, phone, email};
            User* user = dynamic_cast<UserController*>(userController)->registerUser(registerDTO, true);
            if (user!=nullptr) {
                std::cout << "Registration successful! You can now log in.\n";
                userMainPanel->handleUserAction();
            } else {
                std::cerr << "Registration failed. Try again.\n";
            }
        } else if (choice == "3") {
            std::cout << "Exiting registration panel...\n";
            userMainPanel->handleUserAction();
        }
        else {
            std::cerr << "Invalid choice. Try again.\n";
        }
    }
}
void UserRegistrationPanel::displayMenu() {
    clearConsole();
    std::cout << "\n=== User Registration Panel ===\n";
    std::cout << "1. Register as an Member\n";
    std::cout << "2. Register as an Trainer\n";
    std::cout << "3. Exit\n";
}
bool isValidPhoneNumber(const std::string& phoneNumber) {
    std::regex phoneRegex("^[0-9 ]+$");
    return std::regex_match(phoneNumber, phoneRegex);
}
std::string UserRegistrationPanel::getPhoneNumber(std::string prompt) {
    std::string phone;
    while (true) {
        phone = getUserInput(prompt);
        if(isValidPhoneNumber(phone)) {
            return phone;
        } else {
            std::cerr << "Invalid phone number. Use digits only.\n";
        }
    }
}
std::string UserRegistrationPanel::getEmail(std::string prompt) {
    std::string email;
    while (true) {
        email = getUserInput(prompt);
        if (email.find('@') != std::string::npos && email.find('.') != std::string::npos) {
            return email;
        } else {
            std::cerr << "Invalid email format. Try again.\n";
        }
    }
}
