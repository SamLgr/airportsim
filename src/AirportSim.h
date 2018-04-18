//
// Created by lander on 3/16/18.
//

#ifndef AIRPORTSIM_AIRPORTSIM_H
#define AIRPORTSIM_AIRPORTSIM_H


#include "airport.h"

class AirportSim {
    std::vector<Airport*> airports;
    std::vector<Airplane*> airplanes;
public:
    const std::vector<Airport *> &getAirports() const;

    void setAirports(const std::vector<Airport *> &airports);

    const std::vector<Airplane *> &getAirplanes() const;

    void setAirplanes(const std::vector<Airplane *> &airplanes);

    void simulate(std::ostream &output);

    bool checkSimEnd();
};


#endif //AIRPORTSIM_AIRPORTSIM_H
