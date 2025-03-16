//
// Created by Marcin Kaczmarek on 1/25/25.
//

#ifndef USER_H
#define USER_H

#pragma once



#include <utility>
#include <uuid/uuid.h>

#include "Entity.h"

class User: public Entity {

    protected:
        std::string uuid;
        std::string name;
        std::string password;
        std::string phoneNumber;
        std::string emailAddress;

    public:

        User();
        User(std::string name, std::string password, std::string phoneNumber, std::string emailAddress);

        std::string getName() const;
        std::string getPhoneNumber() const;
        std::string getEmailAddress() const;

        void setName(std::string name);
        void setPassword(std::string password);
        void setPhoneNumber(std::string phoneNumber);
        void setEmailAddress(std::string emailAddress);

        bool validatePassword(std::string input);

        std::string getUUID() override;

        virtual Json toJsonFormat() override;

        virtual void fromJsonFormat(Json json) override;

};
#endif //USER_H
