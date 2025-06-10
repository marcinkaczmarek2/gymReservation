#ifndef OOP24_WW_MON_0830_07_ADMINPANEL_H
#define OOP24_WW_MON_0830_07_ADMINPANEL_H
#include "../../backend/controllers/Controller.h"
#include "../../backend/controllers/UserController.h"
#include "../../backend/controllers/ReservationController.h"
#include "UserPanel.h"
class AdminPanel : UserPanel {
    void displayMenu() override;
    void setMembershipEndDateToUser();
    std::string insertDate(std::string prompt);
    void setSalaryToTrainer();
public:
    AdminPanel(Controller *userController, Controller *reservationController, User *user);
    void handleUserAction() override;
};
#endif //OOP24_WW_MON_0830_07_ADMINPANEL_H
