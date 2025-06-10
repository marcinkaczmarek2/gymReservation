#ifndef USERRESERVATIONPANEL_H
#define USERRESERVATIONPANEL_H
#include "UserPanel.h"
#include "UserMainPanel.h"
#include "../../backend/entities/fields/ReservationType.h"
#include "../../backend/utills/DateUtill.h"
class UserReservationPanel: public UserPanel {
public:
    UserReservationPanel(Controller* userController, Controller* reservationController, User* user);
    void displayMenu() override;
    void handleUserAction() override;
    std::string getTrainerChoice(std::string prompt);
    std::string insertDate(std::string prompt) ;
    Trainer* chooseTrainer();
    void displayReservation (Reservation* reservation);
    void displayAvailableReservations();
    void displayReservationsByUser(User* user);
    void displayReservationsByDateAndUser(std::string startDate, std::string endDate, User* user);
    void displayTrainer(Trainer* trainer);
    void displayAllTrainers();
    Reservation *selectReservationToCancel();
};
#endif //USERRESERVATIONPANEL_H
