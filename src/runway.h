//
// Created by lander on 3/29/18.
//

#ifndef AIRPORTSIM_RUNWAY_H
#define AIRPORTSIM_RUNWAY_H

#include "airplane.h"
#include "Taxipoint.h"
#include <string>
#include <vector>

class Airplane;
class Taxipoint;

class Runway {
    Runway* initCheck;
    std::string name;
    std::string type;
    int length;
    Airplane* airplane;
    Airplane* airplaneCrossing;
    std::vector<Taxipoint*> taxipoints;
    std::vector<std::string> crossings;
public:
    Runway();

    bool properlyInitialized();

    const std::string &getName() const;

    void setName(const std::string &name);

    Airplane *getAirplane() const;

    void setAirplane(Airplane *airplane);

    const std::string &getType() const;

    void setType(const std::string &type);

    int getLength() const;

    void setLength(int length);

    void addTaxipoint(std::string taxipoint);

    void addCrossing(std::string crossing);

    const std::vector<Taxipoint*> &getTaxipoints() const;

    const std::vector<std::string> &getCrossings() const;

    Airplane *getAirplaneCrossing() const;

    void setAirplaneCrossing(Airplane *airplaneCrossing);

    void removePlaneFromTaxipoint(Airplane* airplane);
};


#endif //AIRPORTSIM_RUNWAY_H
