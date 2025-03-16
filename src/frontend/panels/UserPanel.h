//
// Created by Marcin Kaczmarek on 1/28/25.
//

#ifndef USERPANEL_H
#define USERPANEL_H

#include "../../backend/controllers/Controller.h"
#include "../../backend/controllers/UserController.h"
#include "../../backend/controllers/ReservationController.h"

class UserPanel {

protected:
    Controller* userController;
    Controller* reservationController;
    User* loggedInUser;
public:
    UserPanel(Controller* userController, Controller* reservationController, User* user);
    virtual void displayMenu() = 0;
    virtual void handleUserAction() = 0;
    virtual std::string getUserInput(std::string prompt);
    void setLoggedInUser(User* loggedInUser);
    void userLogout();
    User* getLoggedInUser() const;
    static void clearConsole();
};



#endif //USERPANEL_H
