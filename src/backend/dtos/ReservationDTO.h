#ifndef OOP24_WW_MON_0830_07_RESERVATIONDTO_H
#define OOP24_WW_MON_0830_07_RESERVATIONDTO_H
#include "../entities/User.h"
#include "../entities/fields/ReservationType.h"
#include "../entities/Trainer.h"
class ReservationDTO {
    private:
        User* user;
        std::string startTime;
        std::string endTime;
        ReservationType reservationType;
        std::optional<Trainer*> optionalTrainer;
    public:
        User *const getUser() const;
        void setUser(User* user);
        const std::string getStartTime() const;
        void setStartTime(std::string startTime);
        const std::string getEndTime() const;
        void setEndTime(std::string endTime);
        const ReservationType getReservationType() const;
        void setReservationType(ReservationType reservationType);
        const std::optional<Trainer*> getOptionalTrainer() const;
        void setOptionalTrainer(std::optional<Trainer*> optionalTrainer);
};
#endif //OOP24_WW_MON_0830_07_RESERVATIONDTO_H
