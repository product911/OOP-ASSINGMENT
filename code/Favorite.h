#ifndef FAVORITE_H
#define FAVORITE_H

#include "Vehicle.h"

// Favorite stores a pointer to a Vehicle -> AGGREGATION - Vehicle exists independently and Favorite just references it
class Favorite
{
    Vehicle *vehicle;   // AGGREGATION: pointer, not owned

public:
    Favorite();
    void addFavorite(Vehicle *v);
    void showFavorite() const;
    Vehicle *getVehicle() const;
};

#endif
