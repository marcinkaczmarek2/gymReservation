#ifndef RESERVATION_TYPE_H
#define RESERVATION_TYPE_H
#include <iostream>
#include <vector>
struct ReservationType {
    std::string name;
    int roomNumber;
    int maxOccupancy;
    std::string description;
    static const ReservationType Weightlifting;
    static const ReservationType Yoga;
    static const ReservationType Fitness;
    static const ReservationType Pilates;
    static const ReservationType Swimming;
    static const ReservationType Spinning;
    static const ReservationType Crossfit;
    static const ReservationType Boxing;
    static const ReservationType Dance;
    static const ReservationType Zumba;
    static const ReservationType Cardio;
    static const ReservationType StrengthTraining;
    static const ReservationType Meditation;
    static const ReservationType HIIT;
    static const ReservationType getByName(const std::string& name);
    static const std::vector<ReservationType>  getAllReservationTypes();
};
#endif // RESERVATION_TYPE_H
