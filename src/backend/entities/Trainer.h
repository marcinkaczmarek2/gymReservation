#ifndef TRAINER_H
#define TRAINER_H
#include "User.h"
class Trainer : public User {
    private:
        float salary;
    public:
        Trainer(std::string name, std::string phoneNumber, std::string emailAddress, float salary, std::string password);
        Trainer();
        [[nodiscard]] float getSalary() const;
        void setSalary(float salary);
        Json toJsonFormat() override;
        void fromJsonFormat(Json json) override;
};
#endif //TRAINER_H
