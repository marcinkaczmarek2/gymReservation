#include <vector>
#ifndef RESERVATION_TYPE_CPP
#define RESERVATION_TYPE_CPP
#include "ReservationType.h"
const ReservationType ReservationType::Weightlifting = {"Weightlifting", 101, 20, "Weightlifting room with all necessary equipment."};
const ReservationType ReservationType::Yoga = {"Yoga", 102, 2, "Quiet and serene room for yoga practice."};
const ReservationType ReservationType::Fitness = {"Fitness", 103, 25, "Spacious fitness room with treadmills and weights."};
const ReservationType ReservationType::Pilates = {"Pilates", 104, 10, "Pilates room with mats and specialized equipment."};
const ReservationType ReservationType::Swimming = {"Swimming", 105, 30, "Olympic-sized pool with lanes for swimming practice."};
const ReservationType ReservationType::Spinning = {"Spinning", 106, 20, "Dedicated spinning studio with high-quality bikes."};
const ReservationType ReservationType::Crossfit = {"Crossfit", 107, 25, "Room equipped for CrossFit training with weights and rigs."};
const ReservationType ReservationType::Boxing = {"Boxing", 108, 12, "Boxing ring and training area with bags and gloves."};
const ReservationType ReservationType::Dance = {"Dance", 109, 20, "Spacious dance studio with mirrors and sound system."};
const ReservationType ReservationType::Zumba = {"Zumba", 110, 25, "Energetic room for Zumba classes with great music setup."};
const ReservationType ReservationType::Cardio = {"Cardio", 111, 35, "Large room with a variety of cardio machines like ellipticals and treadmills."};
const ReservationType ReservationType::StrengthTraining = {"StrengthTraining", 112, 15, "Well-equipped strength training area with machines and free weights."};
const ReservationType ReservationType::Meditation = {"Meditation", 113, 10, "Calm and peaceful room for meditation and mindfulness."};
const ReservationType ReservationType::HIIT = {"HIIT", 114, 20, "High-Intensity Interval Training room with functional fitness equipment."};
const ReservationType reservationTypes[] = {
    ReservationType::Weightlifting,
    ReservationType::Yoga,
    ReservationType::Fitness,
    ReservationType::Pilates,
    ReservationType::Swimming,
    ReservationType::Spinning,
    ReservationType::Crossfit,
    ReservationType::Boxing,
    ReservationType::Dance,
    ReservationType::Zumba,
    ReservationType::Cardio,
    ReservationType::StrengthTraining,
    ReservationType::Meditation,
    ReservationType::HIIT
};
const ReservationType ReservationType::getByName(const std::string& name) {
    for (const ReservationType reservationType : reservationTypes) {
        if (reservationType.name == name) {
            return reservationType;
        }
    }
    return ReservationType();
}
const std::vector<ReservationType> ReservationType::getAllReservationTypes() {
    std::vector<ReservationType> reservationTypesVector;
    for (const ReservationType& reservationType : reservationTypes) {
        reservationTypesVector.push_back(reservationType);
    }
    return reservationTypesVector;
}
#endif //RESERVATION_TYPE_CPP