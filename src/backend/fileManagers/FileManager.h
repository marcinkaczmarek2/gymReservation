//
// Created by Jakub Grad on 25/01/2025.
//

#ifndef OOP24_WW_MON_0830_07_FILEMANAGER_H
#define OOP24_WW_MON_0830_07_FILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../entities/Entity.h"
#include "../entities/User.h"
#include "../entities/Member.h"
#include "../entities/Trainer.h"
#include "../entities/Reservation.h"

template <typename T, typename ID>
class FileManager {

    private:
        std::string filePath;

    public:

        static_assert(std::is_base_of<Entity, T>::value, "T must be a subclass of Entity");

        FileManager(std::string filePath);

        std::vector<T*> readFile();

        bool writeFile(T* entity);

        T* removeEntityById(const ID& id);
        T* getEntityById(const ID& id);

        std::vector<T*> getEntityByField(std::string fieldName, std::any value);



    };


#endif //OOP24_WW_MON_0830_07_FILEMANAGER_H
