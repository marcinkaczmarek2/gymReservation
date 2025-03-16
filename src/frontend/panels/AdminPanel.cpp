//
// Created by Jakub Grad on 31/01/2025.
//

#include "AdminPanel.h"
#include "../../backend/utills/DateUtill.h"
#include "UserMainPanel.h"


AdminPanel::AdminPanel(Controller *userController, Controller *reservationController, User *user) : UserPanel(
        userController, reservationController, user) {

}

void AdminPanel::handleUserAction() {


    auto userMainPanel = std::make_unique<UserMainPanel>(userController, reservationController, getLoggedInUser());

    while (true) {
        displayMenu();
        std::string choice = getUserInput("Choose an option");
        if (choice == "1") {
            setSalaryToTrainer();
        } else if (choice == "2") {
            setMembershipEndDateToUser();
        } else if (choice == "3") {
            std::cout << "Exiting main panel...\n";
            userMainPanel->handleUserAction();
        } else {
            std::cerr << "Invalid choice. Please try again.\n";
        }

    }
}

void AdminPanel::displayMenu() {
    clearConsole();
    std::cout << "\n=== Admin Panel ===\n";
    std::cout << "1. Set trainer salary\n";
    std::cout << "2. Set membership end date to user\n";
    std::cout << "3. Exit\n";
}

void AdminPanel::setMembershipEndDateToUser() {


    std::string input;

    input = getUserInput("Enter member email to extend gym membership");

    User* member = dynamic_cast<UserController*>(userController)->getUserByEmail(input);

    if (!dynamic_cast<Member*>(member)) {
        std::cerr << "User is not a member\n";
        return;
    }

    std::string startTime = insertDate("Enter new start gym membership end date (DD-MM-YYYY hh:mm)");

    int day = DateUtill::getDayOfDate(startTime),
    month = DateUtill::getMonthOfDate(startTime),
    year = DateUtill::getYearOfDate(startTime);
    std::cout << "Changed successfully!\n";
    dynamic_cast<UserController*>(userController)->extendGymMembership(dynamic_cast<Member*>(member), day, month, year);

}

void AdminPanel::setSalaryToTrainer() {


    std::string input;

    input = getUserInput("Enter trainer mail");

    User* trainer = dynamic_cast<UserController*>(userController)->getUserByEmail(input);

    if (!dynamic_cast<Trainer*>(trainer)) {
        std::cerr << "User is not a trainer\n";
        return;
    }

    std::string salary = getUserInput("Enter new salary for trainer " + trainer->getEmailAddress());

    float salaryFloat = 0;

    try {
        salaryFloat = std::stof(salary);
    } catch (std::exception& e) {
        std::cerr << "Invalid salary format. Please try again.\n";
        return;
    }
    std::cout << "Changed successfully!\n";
    dynamic_cast<UserController*>(userController)->setSalaryToTrainer(dynamic_cast<Trainer*>(trainer), salaryFloat);

}

std::string AdminPanel::insertDate(std::string prompt) {
    std::string date;

    while (true) {
        date = getUserInput(prompt);

        if(DateUtill::isDateTimeValid(date))  return date;

        else {
            std::cerr << "Invalid date format\n";
            std::cerr << "The correct date format is: DD-MM-YYYY hh:mm\n";
        }

    }
}

