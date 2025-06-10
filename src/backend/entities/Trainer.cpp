#include "Trainer.h"
float Trainer::getSalary() const {
    return salary;
}
void Trainer::setSalary(float salary) {
    this->salary = salary;
}
Trainer::Trainer(std::string name, std::string phoneNumber, std::string emailAddress, float salary, std::string password)
        : User(std::move(name), std::move(password), std::move(phoneNumber), std::move(emailAddress)) {
    this->salary = salary;
}
Trainer::Trainer(): User() {
}
Json Trainer::toJsonFormat() {
    return {
            {"uuid", uuid},
            {"name", name},
            {"phoneNumber", phoneNumber},
            {"emailAddress", emailAddress},
            {"password", password},
            {"salary", salary}
    };
}
void Trainer::fromJsonFormat(Json json) {
    if (json.contains("uuid")) uuid = json["uuid"].get<std::string>();
    if (json.contains("name")) name = json["name"].get<std::string>();
    if (json.contains("phoneNumber")) phoneNumber = json["phoneNumber"].get<std::string>();
    if (json.contains("emailAddress")) emailAddress = json["emailAddress"].get<std::string>();    if (json.contains("password")) password = json["password"].get<std::string>();
    if (json.contains("salary")) salary = json["salary"].get<float>();
}
