#ifndef USERREGISTRATIONPANEL_H
#define USERREGISTRATIONPANEL_H
#include "UserPanel.h"
#include "UserMainPanel.h"
#include <regex>
class UserRegistrationPanel : public UserPanel {
public:
    UserRegistrationPanel(Controller* userController, Controller* reservationController, User* user);
    void displayMenu() override;
    void handleUserAction() override;
    std::string getPhoneNumber(std::string prompt);
    std::string getEmail(std::string prompt);
};
#endif //USERREGISTRATIONPANEL_H
