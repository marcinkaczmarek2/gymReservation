#include "UserReservationPanel.h"
#include <thread>
UserReservationPanel::UserReservationPanel(Controller* userController, Controller* reservationController, User* user) : UserPanel(userController, reservationController, user) {}
void clearReservationConsole() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
#ifdef _WIN32
    system("cls");
#elif defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
    system("clear");
#else
    std::cerr << "Unsupported platform. Cannot clear console.\n";
#endif
}
void displayAllReservationTypes() {
    std::cout << "Available Reservation Types:\n";
    const std::vector<ReservationType>  allTypes = ReservationType::getAllReservationTypes();
    for(ReservationType reservationType : allTypes) {
        std::cout << ". " << reservationType.name << std::endl;
    }
}
void UserReservationPanel::handleUserAction() {
    auto userMainPanel = std::make_unique<UserMainPanel>(userController, reservationController, getLoggedInUser());
    while (true) {
        displayMenu();
        std::string choice = getUserInput("Choose an option");
        if (choice == "1") {
            displayAllReservationTypes();
            std::string typeChoice = getUserInput("Choose sport");
            const ReservationType reservationType = ReservationType::getByName(typeChoice);
            if(reservationType.name.empty()) {
                std::cerr << "Invalid sport type. Please try again.\n";
                continue;
            }
            std::string startTime = insertDate("Enter the start date date (DD-MM-YYYY hh:mm)");
            std::string endTime = insertDate("Enter the end date (DD-MM-YYYY hh:mm)");
            std::string trainerChoice = getTrainerChoice("Do you want a personal trainer? (yes/no)");
            ReservationDTO reservationDTO;
            reservationDTO.setUser(getLoggedInUser());
            reservationDTO.setStartTime(startTime);
            reservationDTO.setEndTime(endTime);
            reservationDTO.setReservationType(reservationType);
            reservationDTO.setOptionalTrainer(std::nullopt);
            if (trainerChoice == "yes") {
                displayAllTrainers();
                Trainer* trainer = nullptr;
                while (trainer == nullptr) {
                    trainer = chooseTrainer();
                    if (trainer == nullptr) {
                        std::cerr << "Invalid trainer email. Please try again.\n";
                    }
                }
                reservationDTO.setOptionalTrainer(trainer);
            }
            Reservation* reservation = dynamic_cast<ReservationController*>(reservationController)->registerReservation(reservationDTO);
            if (reservation!=nullptr) {
                std::cout << "Reservation made successfully!\n";
                handleUserAction();
            } else {
                std::cout << "Reservation failed. Try again.\n";
            }
        }
        else if (choice == "2") {
            std::cout << "\nDisplaying your reservations...\n";
            displayReservationsByUser(getLoggedInUser());
        }
        else if (choice == "3") {
            std::string startDate = insertDate("Enter the start date date (DD-MM-YYYY hh:mm)");
            std::string endDate = insertDate("Enter the end date (DD-MM-YYYY hh:mm)");
            std::cout << "Displaying reservations for " << startDate << " - "<< endDate << "...\n";
            displayReservationsByDateAndUser(startDate, endDate, getLoggedInUser());
        }
        else if (choice == "4") {
            Reservation* reservation = selectReservationToCancel();
            if (reservation==nullptr) {
                std::cerr << "Reservation does not exist. Please try again.\n";
                continue;
            }
            bool success = dynamic_cast<ReservationController*>(reservationController)->cancelReservation(reservation);
            if (success) {
                std::cout << "Reservation canceled successfully.\n";
            } else {
                std::cout << "Failed to cancel reservation. Invalid ID.\n";
            }
        }
        else if (choice == "5") {
            userLogout();
            std::cout << "Logging out...\n";
            userMainPanel->handleUserAction();
        }
        else if (choice == "6") {
            std::cout << "Exiting Reservation Panel...\n";
            userMainPanel->handleUserAction();
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
void UserReservationPanel::displayMenu() {
    clearReservationConsole();
    std::cout << "\n=== User Reservation Panel ===\n";
    std::cout << "Logged in as: " << loggedInUser->getEmailAddress();
    if (dynamic_cast<Trainer*>(getLoggedInUser())) {
        std::cout<<"  - Trainer\n";
    } else if (dynamic_cast<Member*>(getLoggedInUser())) {
        std::cout<<"  - Member\n";
    }
    std::cout << "1. Make reservation\n";
    std::cout << "2. Display my reservations\n";
    std::cout << "3. Display reservations for a specific date\n";
    std::cout << "4. Cancel a reservation\n";
    std::cout << "5. Logout\n";
    std::cout << "6. Exit\n";
}
std::string UserReservationPanel::getTrainerChoice(std::string prompt) {
    std::string trainerChoice;
    while (true) {
        trainerChoice = getUserInput(prompt);
        if (trainerChoice == "yes") {
            return trainerChoice;
        }else if(trainerChoice == "no") {
            return trainerChoice;
        } else {
            std::cerr << "Invalid email format. Try again.\n";
        }
    }
}
Trainer* UserReservationPanel::chooseTrainer() {
    while (true) {
        std::string trainerName = getUserInput("Choose the trainer by email");
        Trainer* trainer = dynamic_cast<UserController*>(userController)->getTrainerByEmail(trainerName);
        if (trainer != nullptr) {
            return trainer;
        }
        std::cerr << "Invalid trainer email. Please try again.\n";
    }
}
std::string UserReservationPanel::insertDate(std::string prompt) {
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
Reservation* UserReservationPanel::selectReservationToCancel() {
    std::vector<Reservation*> reservations = dynamic_cast<ReservationController*>(reservationController)->getUserReservations(getLoggedInUser());
    if (reservations.empty()) {
        return nullptr;
    }
    std::string input;
    for (int i = 0; i <reservations.size(); i++) {
        Reservation* context = reservations[i];
        if (context->isCanceled()) continue;
        std::cout <<"\n"<< i + 1 << ". ";
        displayReservation(context);
    }
    input = getUserInput("Choose the reservation number");
    try {
        int index = std::stoi(input);
        return reservations[index - 1];
    } catch (std::exception& e) {
        std::cerr << "Invalid input. Please try again.\n";
        return nullptr;
    }
}
void UserReservationPanel::displayReservation(Reservation* reservation) {
    if(reservation->isCanceled()) return;
    User* client = dynamic_cast<UserController*>(userController)->getUserByID(reservation->getTraineeID());
    std::cout << "----- Reservation Details -----\n"
              << "Start Time: " << reservation->getStartTime() << "\n"
              << "End Time: " << reservation->getEndTime() << "\n"
              << "Trainee name: " << client->getName() << "\n"
              << "Reservation type: " << reservation->getReservationType().name << "\n"
              << "Room Number: " << reservation->getReservationType().roomNumber << "\n"
              << "Max Occupancy: " << reservation->getReservationType().maxOccupancy << "\n"
              << "Description: " << reservation->getReservationType().description << "\n";
        User* trainer = dynamic_cast<UserController*>(userController)->getUserByID(*reservation->getOptionalTrainerID());
        if (!(trainer==nullptr)) {
            std::cout << "Trainer: " << trainer->getName() << "\n";
        }
    std::cout << "--------------------------------\n\n";
}
void UserReservationPanel::displayReservationsByUser(User* user) {
    std::vector<Reservation*> reservations = dynamic_cast<ReservationController*>(reservationController)->getUserReservations(user);
    if (reservations.empty()) {
        std::cout << "No reservations found for this user.\n";
        return;
    }
    std::cout << "\n----- Reservations for User: " << user->getEmailAddress() << " -----\n";
    unsigned counter=1;
    for (Reservation* reservation : reservations) {
        if(reservation->isCanceled()) continue;
        std::cout << "Reservation #" << (counter) << ":\n";
        displayReservation(reservation);
        counter++;
    }
    std::cout << "\nEnd of reservations for user: " << user->getEmailAddress() << ".\n";
}
void UserReservationPanel::displayReservationsByDateAndUser(std::string startDate, std::string endDate, User* user) {
    std::vector<Reservation*> reservations = dynamic_cast<ReservationController*>(reservationController)->getReservationsByDateAndUser(startDate, endDate, user);
    if (reservations.empty()) {
        std::cout << "On date: " << startDate << " - "<< endDate <<" no reservations found for this user.\n";
        return;
    }
    std::cout << "----- Reservations for User: " << user->getName() << " on "<< startDate << " - "<< endDate <<" -----\n";
    for (Reservation* reservation : reservations) {
        if(reservation->isCanceled()) {
            std::cout << "On date: " << startDate << " - "<< endDate <<" no reservations found for this user.\n";
            return;
        }
        unsigned counter=1;
        std::cout << "Reservation #" << counter++ << ":\n";
        displayReservation(reservation);
    }
    std::cout << "\nEnd of reservations for user: " << user->getName() << " on "<< startDate << " - "<< endDate <<".\n";
}
void UserReservationPanel::displayAvailableReservations() {
    std::cout<<"";
}
void UserReservationPanel::displayTrainer(Trainer *trainer) {
    std::cout << "Name: " << trainer->getName() << "\n"
              << "Phone: " << trainer->getPhoneNumber() << "\n"
              << "Email: " << trainer->getEmailAddress() << "\n";
}
void UserReservationPanel::displayAllTrainers() {
    std::vector<Trainer*> trainers = dynamic_cast<UserController*>(userController)->getAllTrainers();
    if (trainers.empty()) {
        std::cout << "No trainers in the system." << std::endl;
        return;
    }
    std::cout << "----- All Trainers in the System -----\n\n";
    unsigned counter = 1;
    for (int i=0; i<trainers.size(); i++) {
        std::cout << "\n-----#" << counter++ <<" Trainer"<<" details-----\n";
        displayTrainer(trainers[i]);
    }
    for (auto trainer : trainers) {
        delete trainer;
    }
    trainers.clear();
    std::cout << "\nEnd of all trainers in the system.\n";
}
