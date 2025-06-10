#ifndef USERLOGINPANEL_H
#define USERLOGINPANEL_H
#include "UserPanel.h"
#include "UserReservationPanel.h"
#include "../../backend/controllers/Controller.h"
class UserLoginPanel: public UserPanel {
public:
    UserLoginPanel(Controller* userController, Controller* reservationController, User* user);
    void displayMenu() override;
    void handleUserAction() override;
};
#endif //USERLOGINPANEL_H
