#ifndef RESERVATION_H
#define RESERVATION_H
#include "fields/ReservationType.h"
#include <optional>
#include "Trainer.h"
class Reservation : public Entity {
      protected:
            std::string uuid;
            std::string startTime;
            std::string endTime;
            std::string traineeID;
            ReservationType reservationType;
            std::optional<std::string> optionalTrainerID;
            bool canceled;
      public:
            Reservation(std::string startTime, std::string endTime, std::string traineeID, ReservationType reservationType);
            Reservation(std::string startTime, std::string endTime, std::string traineeID, ReservationType reservationType, std::optional<std::string> optionalTrainerID);
            Reservation();
            std::string getStartTime();
            std::string getEndTime();
            std::string getTraineeID();
            ReservationType getReservationType();
            std::optional<std::string> getOptionalTrainerID();
            void setTraineeID(std::string traineeID);
            void setEndTime(std::string endTime);
            void setOptionalTrainerID(std::optional<std::string> optionalTrainerID);
            void setStartTime(std::string startTime);
            void setReservationType(ReservationType reservationType);
            void setCanceled(bool canceled);
            bool isCanceled();
            std::string getUUID() override;
            Json toJsonFormat() override;
            void fromJsonFormat(Json json) override;
};
#endif //RESERVATION_H
