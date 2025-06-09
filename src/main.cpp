
#include <iostream>
#include <filesystem>

#include "backend/services/UserService.h"

namespace fs = std::filesystem;

#include "backend/entities/User.h"
#include "backend/entities/Member.h"
#include "backend/entities/Trainer.h"
#include "backend/fileManagers/FileManager.h"
#include "frontend/panels/UserLoginPanel.h"
#include "frontend/panels/UserRegistrationPanel.h"
#include "frontend/panels/UserReservationPanel.h"

using namespace std;


int main() {

    std::filesystem::path exePath = std::filesystem::current_path();

    std::filesystem::path trainerFilePath = exePath / "resources" / "data" / "trainer.json";
    std::filesystem::path memberFilePath = exePath / "resources" / "data" / "member.json";
    std::filesystem::path reservationFilePath = exePath / "resources" / "data" / "reservation.json";

    FileManager<Trainer, std::string> trainerFileManager(trainerFilePath);
    FileManager<Member, std::string> memberFileManager(memberFilePath);
    FileManager<Reservation, std::string> reservationFileManager(reservationFilePath);

    UserRepository userRepo(&trainerFileManager, &memberFileManager);
    ReservationRepository reservationRepo(&reservationFileManager);

    UserService userService(&userRepo);
    ReservationService reservationService(&reservationRepo);


    UserController userController(&userService);
    ReservationController reservationController(&reservationService);

    UserMainPanel userMainPanel(&userController, &reservationController, nullptr);


    userMainPanel.handleUserAction();

    return 0;
}
