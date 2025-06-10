#ifndef MEMBER_H
#define MEMBER_H
#include "User.h"
class Member : public User {
    private:
        std::string gymMembershipEndDate;
    public:
        Member(std::string name, std::string phoneNumber, std::string emailAddress, std::string gymMembershipEndDate, std::string password);
        Member();
        [[nodiscard]] std::string getGymMembershipEndDate() const;
        bool isMembershipValid();
        void setGymMembershipEndDate(std::string gymMembershipEndDate);
        Json toJsonFormat() override;
        void fromJsonFormat(Json json) override;
};
#endif //MEMBER_H
