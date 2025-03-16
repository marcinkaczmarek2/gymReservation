//
// Created by Jakub Grad on 25/01/2025.
//

#ifndef OOP24_WW_MON_0830_07_ENTITY_H
#define OOP24_WW_MON_0830_07_ENTITY_H

#include <nlohmann/json.hpp>
#include <uuid/uuid.h>

using UUID = uuid_t;
using Json = nlohmann::json;

class Entity {

    public:
        virtual std::string getUUID() = 0;
        virtual Json toJsonFormat() = 0;
        virtual void fromJsonFormat(Json json) = 0;

};


#endif //OOP24_WW_MON_0830_07_ENTITY_H
