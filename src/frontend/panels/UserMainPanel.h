//
// Created by Marcin Kaczmarek on 1/28/25.
//

#ifndef USERMAINPANEL_H
#define USERMAINPANEL_H
#include "UserPanel.h"
#include "UserLoginPanel.h"
#include "UserRegistrationPanel.h"

class UserMainPanel : public UserPanel{
public:
    UserMainPanel(Controller* userController, Controller* reservationController, User* user);
    void displayMenu() override;
    void handleUserAction() override;
};



#endif //USERMAINPANEL_H
