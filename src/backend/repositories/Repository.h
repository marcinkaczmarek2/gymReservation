//
// Created by Jakub Grad on 25/01/2025.
//

#ifndef OOP24_WW_MON_0830_07_REPOSITORY_H
#define OOP24_WW_MON_0830_07_REPOSITORY_H

#include <iostream>
#include <vector>
template <typename T, typename ID>
class Repository {

    virtual T* removeEntity(T* entity) = 0;
    virtual T* removeEntityById(ID id) = 0;
    virtual T* addEntity(T* entity) = 0;

    virtual void createOrUpdateEntity(T* entity) = 0;

    virtual std::vector<T*> getAllEntities() = 0;
    virtual T* getEntityById(ID id) = 0;

};


#endif //OOP24_WW_MON_0830_07_REPOSITORY_H
