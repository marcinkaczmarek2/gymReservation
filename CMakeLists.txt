cmake_minimum_required(VERSION 3.4)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#Source files here
set(SOURCE_FILES
        src/main.cpp
        src/backend/repositories/Repository.h
        src/backend/repositories/Repository.cpp
        src/backend/entities/Entity.h
        src/backend/entities/Entity.cpp
        src/backend/entities/Reservation.h
        src/backend/entities/Reservation.cpp
        src/backend/entities/User.cpp
        src/backend/entities/User.h
        src/backend/entities/Trainer.h
        src/backend/entities/Trainer.cpp
        src/backend/entities/Member.cpp
        src/backend/entities/Member.h
        src/backend/entities/fields/ReservationType.cpp
        src/backend/fileManagers/FileManager.h
        src/backend/entities/fields/ReservationType.h
        src/backend/repositories/UserRepository.h
        src/backend/repositories/UserRepository.cpp
        src/backend/fileManagers/FileManager.cpp
        src/backend/repositories/ReservationRepository.h
        src/backend/repositories/ReservationRepository.cpp
        src/backend/services/Service.h
        src/backend/services/Service.cpp
        src/backend/services/UserService.h
        src/backend/services/UserService.cpp
        src/backend/dtos/RegisterDTO.h
        src/backend/dtos/RegisterDTO.cpp
        src/backend/dtos/LoginDTO.h
        src/backend/dtos/LoginDTO.cpp
        src/backend/services/ReservationService.cpp
        src/backend/dtos/ReservationDTO.h
        src/backend/dtos/ReservationDTO.cpp
        src/backend/controllers/Controller.cpp
        src/backend/controllers/ReservationController.cpp
        src/backend/controllers/ReservationController.h
        src/backend/controllers/UserController.cpp
        src/backend/controllers/Controller.h
        src/frontend/panels/UserPanel.cpp
        src/frontend/panels/UserPanel.h
        src/frontend/panels/UserRegistrationPanel.cpp
        src/frontend/panels/UserRegistrationPanel.h
        src/frontend/panels/UserLoginPanel.cpp
        src/frontend/panels/UserLoginPanel.h
        src/frontend/panels/UserReservationPanel.cpp
        src/frontend/panels/UserReservationPanel.h
        src/backend/controllers/UserController.h
        src/frontend/panels/UserMainPanel.cpp
        src/frontend/panels/UserMainPanel.h
        src/backend/utills/DateUtill.h
        src/backend/utills/DateUtill.cpp
        test/backend/entities/fields/ReservationTypeTest.cpp
        src/frontend/panels/AdminPanel.h
        src/frontend/panels/AdminPanel.cpp
)

set(CMAKE_SOURCE_DIR gymReservationProject)
include_directories("${CMAKE_SOURCE_DIR}/include")
add_executable(Project ${SOURCE_FILES})

target_include_directories(Project PUBLIC include)
if(APPLE)
    # Dla systemów macOS nie łączymy libuuid
    message(STATUS "System macOS, pomijamy libuuid")
elseif(UNIX AND NOT APPLE)
    # Dla systemów uniksowych (ale nie macOS) dodajemy libuuid
    find_library(UUID_LIBRARY uuid)
    if(UUID_LIBRARY)
        target_link_libraries(Project ${UUID_LIBRARY})
    else()
        message(FATAL_ERROR "Nie znaleziono biblioteki libuuid")
    endif()
endif()

#add_subdirectory(googletest)

#TESTS
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
        test/master.cpp
        test/backend/entities/MemberTest.cpp
        src/backend/entities/User.cpp
        src/backend/entities/Member.cpp
        src/backend/entities/Trainer.cpp
        src/backend/entities/Reservation.cpp
        src/backend/entities/fields/ReservationType.cpp
        src/backend/entities/fields/ReservationType.h
        src/backend/dtos/ReservationDTO.cpp
        src/backend/dtos/LoginDTO.cpp
        src/backend/dtos/RegisterDTO.cpp
        test/backend/entities/TrainerTest.cpp
        test/backend/entities/ReservationTest.cpp
        test/backend/entities/fields/ReservationTypeTest.cpp
        test/backend/dtos/ReservationDTO.cpp
        test/backend/dtos/LoginDTO.cpp
        test/backend/dtos/RegisterDTO.cpp
        test/backend/utills/DateUtillTest.cpp
        src/backend/utills/DateUtill.cpp
        src/backend/utills/DateUtill.h
)

add_executable(TestProject ${SOURCE_TEST_FILES})

target_include_directories(TestProject PUBLIC include)

if(APPLE)
    # Dla systemów macOS nie łączymy libuuid
    message(STATUS "System macOS, pomijamy libuuid")
elseif(UNIX AND NOT APPLE)
    # Dla systemów uniksowych (ale nie macOS) dodajemy libuuid
    find_library(UUID_LIBRARY uuid)
    if(UUID_LIBRARY)
        target_link_libraries(TestProject ${UUID_LIBRARY}) # Bez PRIVATE
    else()
        message(FATAL_ERROR "Nie znaleziono biblioteki libuuid")
    endif()
endif()


target_link_libraries(Project ${Boost_LIBRARIES})

target_link_libraries (TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)