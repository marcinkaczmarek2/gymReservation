#include "FileManager.h"
#include <sstream>
#include <stdexcept>
template <typename T, typename ID>
FileManager<T, ID>::FileManager(std::string filePath) {
    this->filePath = filePath;
}
template <typename T, typename ID>
std::vector<T*> FileManager<T, ID>::readFile() {
    std::vector<T*> entities;
    std::ifstream file(filePath);
    Json j;
    try {
        file >> j;
    } catch (const std::exception& e) {
        j = Json::array();
    }
    for (const auto& item : j) {
        T* entity = new T();
        entity->fromJsonFormat(item);
        entities.push_back(entity);
    }
    return entities;
    file.close();
    return entities;
}
template <typename T, typename ID>
bool FileManager<T, ID>::writeFile(T* entity) {
    Json j;
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        try {
            inputFile >> j;
        } catch (const std::exception& e) {
            std::cerr << "Błąd podczas wczytywania JSON: " << e.what() << std::endl;
            return false;
        }
        inputFile.close();
    } else {
        std::cerr << "Plik nie istnieje lub nie można go otworzyć. Tworzymy nową listę."<< std::endl;
        j = Json::array();
    }
    if (!j.is_array()) {
        std::cerr << "Dane w pliku nie są listą. Nadpisujemy je nową listą."<< std::endl;
        j = Json::array();
    }
    Json entityJson = entity->toJsonFormat();
    j.push_back(entityJson);
    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << j.dump(4);
        outputFile.close();
    } else {
        std::cerr << "Nie można otworzyć pliku do zapisu."<< std::endl;
        return false;
    }
    return true;
}
template <typename T, typename ID>
T* FileManager<T, ID>::removeEntityById(const ID& id) {
    Json j;
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        try {
            inputFile >> j;
        } catch (const std::exception& e) {
            std::cerr << "Błąd podczas wczytywania JSON: " << e.what() << std::endl;
            return nullptr;
        }
        inputFile.close();
    } else {
        std::cerr << "Plik nie istnieje lub nie można go otworzyć." << std::endl;
        return nullptr;
    }
    if (!j.is_array()) {
        std::cerr << "Dane w pliku nie są listą." << std::endl;
        return nullptr;
    }
    bool removed = false;
    Json updatedJson = Json::array();
    T tempEntity;
    for (const auto& item : j) {
        tempEntity.fromJsonFormat(item);
        if (tempEntity.getUUID() != id) {
            updatedJson.push_back(item);
        } else {
            removed = true;
        }
    }
    if (removed) {
        std::ofstream outputFile(filePath);
        if (outputFile.is_open()) {
            outputFile << updatedJson.dump(4);
            outputFile.close();
        } else {
            std::cerr << "Nie można otworzyć pliku do zapisu." << std::endl;
            return nullptr;
        }
    }
    return &tempEntity;
}
template <typename T, typename ID>
std::vector<T*> FileManager<T, ID>::getEntityByField(std::string fieldName, std::any value) {
    Json j;
    std::vector<T*> results;
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        try {
            inputFile >> j;
        } catch (const std::exception& e) {
            std::cerr << "Błąd podczas wczytywania JSON: " << e.what() << std::endl;
            return results;
        }
        inputFile.close();
    } else {
        std::cerr << "Plik nie istnieje lub nie można go otworzyć." << std::endl;
        return results;
    }
    if (!j.is_array()) {
        std::cerr << "Dane w pliku nie są listą." << std::endl;
        return results;
    }
    Json updatedJson = Json::array();
    for (const auto& item : j) {
        if (item.contains(fieldName)) {
            T* tempEntity = new T();
            tempEntity->fromJsonFormat(item);
            try {
                if (item[fieldName] == std::any_cast<std::string>(value)) {
                    results.push_back(tempEntity);
                } else if (item[fieldName] == std::any_cast<int>(value)) {
                    results.push_back(tempEntity);
                } else if (item[fieldName] == std::any_cast<double>(value)) {
                    results.push_back(tempEntity);
                }
            } catch (const std::bad_any_cast&) {
                continue;
            }
        }
    }
    return results;
}
template <typename T, typename ID>
T* FileManager<T, ID>::getEntityById(const ID& id) {
    Json j;
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        try {
            inputFile >> j;
        } catch (const std::exception& e) {
            std::cerr << "Błąd podczas wczytywania JSON: " << e.what() << std::endl;
            return nullptr;
        }
        inputFile.close();
    } else {
        std::cerr << "Plik nie istnieje lub nie można go otworzyć." << std::endl;
        return nullptr;
    }
    if (!j.is_array()) {
        std::cerr << "Dane w pliku nie są listą." << std::endl;
        return nullptr;
    }
    bool removed = false;
    Json updatedJson = Json::array();
    T tempEntity;
    for (const auto& item : j) {
        T* tempEntity = new T();
        tempEntity->fromJsonFormat(item);
        if (tempEntity->getUUID() == id) {
            return tempEntity;
        }
        delete tempEntity;
    }
    return nullptr;
}
template class FileManager<Member, std::string>;
template class FileManager<Trainer, std::string>;
template class FileManager<Reservation, std::string>;