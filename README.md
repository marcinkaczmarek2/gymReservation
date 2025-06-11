# Gym Reservation CLI Application (C++)

This is a command-line application for managing gym training reservations, created as a university project to practice object-oriented programming in C++.

Users can register or log in as gym members, trainers, or administrator. The admin panel allows managing both users and trainers.

>  Created as part of the Object-Oriented Programming course at Lodz University of Technology (2024).

---

## 📸 Screenshots

Below are screenshots showcasing key functionalities of the application:

<p align="center">
  <img src="https://github.com/user-attachments/assets/069ce33e-ab7f-4960-8d1f-5c37f4479e6c" width="400"/>
  <img src="https://github.com/user-attachments/assets/2931d67d-fff0-412c-9ac2-9e072535f0db" width="400"/>
  <img src="https://github.com/user-attachments/assets/e5cc6251-dc5e-4205-8d98-4f0fcf53ad12" width="400"/>
  <img src="https://github.com/user-attachments/assets/994afaf8-6c83-4e7a-906f-aa377a2d732d" width="400"/>
  <img src="https://github.com/user-attachments/assets/24d1b837-455d-480f-a1d1-098769916803" width="400"/>
  <img src="https://github.com/user-attachments/assets/0012daa4-95bb-496c-8a51-206ce751be04" width="400"/>
  <img src="https://github.com/user-attachments/assets/cdbc37ab-a659-4b71-9562-74036fa6b62f" width="400"/>
  <img src="https://github.com/user-attachments/assets/88a87810-d618-422a-875e-02a5f1d39793" width="400"/>
</p>

---

## ⚙️ Installation

To run this application, follow these steps:

1. **Use WSL** ([guide](https://learn.microsoft.com/en-us/windows/wsl/install)) or a Debian-based system.
2. Update the system:
   sudo apt update && sudo apt upgrade
3. Install required tools and libraries:
   sudo apt install build-essential cmake gdb libboost-all-dev uuid-dev
4. Clone the project:
   git clone https://github.com/marcinkaczmarek2/gymReservation.git
5. Create and enter a build directory:
   mkdir build && cd build
6. Generate build files using CMake:
   cmake -G "Unix Makefiles" ../gymReservation
7. Build the application:
   make
8. Run the application:
   ./Project

✅ Done!
You can now test the application and explore its functionality.

P.S  - The login and password to admin panel are both "admin"
