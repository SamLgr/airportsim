//
// Created by sam on 01.03.18.
//

#ifndef AIRPORTSIM_AIRPLANE_H
#define AIRPORTSIM_AIRPLANE_H

#include <iostream>
#include <fstream>
#include "DesignByContract.h"
#include "runway.h"

class Runway;

class Airplane {
    Airplane* initCheck;
    std::string number;
    std::string callsign;
    std::string model;
    std::string status;
    std::string type;
    std::string engine;
    std::string size;
    int passengers;
    int fuel;
    int height;
    int squawk;
    int time;
    bool communicating;
public:
    Airplane();
    bool properlyInitialized();
    void printInfo(std::ofstream &output);

    int getSquawk() const;
    void setSquawk(int squawk);

    bool isCommunicating() const;
    void setCommunication(bool communication);

    int getTime() const;
    void setTime(int time);

    const std::string &getCallsign() const;
    void setCallsign(const std::string &callsign);

    const std::string &getNumber() const;
    void setNumber(const std::string &number);

    const std::string &getModel() const;
    void setModel(const std::string &model);

    const std::string &getStatus() const;
    void setStatus(const std::string &status);

    int getPassengers() const;
    void setPassengers(int passengers);

    int getFuel() const;
    void setFuel(int fuel);

    int getHeight() const;
    void setHeight(int height);

    const std::string &getType() const;
    void setType(const std::string &type);

    const std::string &getEngine() const;
    void setEngine(const std::string &engine);

    const std::string &getSize() const;
    void setSize(const std::string &size);

    bool isAtGate();
    bool isAtRunway();

    /**
     * REQUIRE(this->getStatus() == "Approaching", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Descending to 5k", "Plane hasn't been set to the correct state.");
     */
    void approach(std::ostream &output, const std::string& airport);

    /**
     * REQUIRE(this->getStatus() == "Flying wait pattern, "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Final Approach" || this->getStatus() == "Descending to 5k" || this->getStatus() == "Descending to 3k", "Plane hasn't been set to the correct state.");
     */
    void flyWaitPattern(std::ostream &output);

    /**
     * REQUIRE(this->getStatus() == "Descending to 5k", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Descending to 3k" || this->getStatus() == "Descending to 5k" || this->getStatus() == "Flying wait pattern", "Plane hasn't been set to the correct state.");
     */
    void descendTo5k(std::ostream &output);

    /**
     * REQUIRE(this->getStatus() == "Descending to 3k" || this->getStatus() == "Flying wait pattern", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Final Approach" || this->getStatus() == "Descending to 3k" || this->getStatus() == "Flying wait pattern", "Plane hasn't been set to the correct state.");
     */
    void descendTo3k(std::ostream &output);

    /**
     * REQUIRE(this->getStatus() == "Final Approach" || this->getStatus() == "Flying wait pattern", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Landing" || this->getStatus() == "Final Approach", "Plane hasn't been set to the correct state.");
     */
    void finalapproach(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->getStatus() == "Landing", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Landed", "Plane hasn't been set to the correct state.");
     */
    void land(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->getStatus() == "Landed", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Taxiing to Gate", "Plane hasn't been set to the correct state.");
     */
    void landed(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->getStatus() == "Taxiing to Gate", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Unboarding Plane", "Plane hasn't been set to the correct state.");
     */
    void taxiToGate(std::ostream &output, int gate);

    /**
     * REQUIRE(this->getStatus() == "Unboarding Plane", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Checking Plane", "Plane hasn't been set to the correct state.");
     */
    void unboardPlane(std::ostream &output, const std::string& airport, int gate);

    /**
     * REQUIRE(this->getStatus() == "Checking Plane", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Refueling Plane", "Plane hasn't been set to the correct state.");
     */
    void checkPlane(std::ostream &output);

    /**
     * REQUIRE(this->getStatus() == "Refueling Plane", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Boarding Plane", "Plane hasn't been set to the correct state.");
     */
    void refuelPlane(std::ostream &output);

    /**
     * REQUIRE(this->getStatus() == "Boarding Plane", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Standing at Gate", "Plane hasn't been set to the correct state.");
     */
    void boardPlane(std::ostream &output, const std::string& airport, int gate);

    /**
     * REQUIRE(this->getStatus() == "Standing at Gate", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Pushing back", "Plane hasn't been set to the correct state.");
     */
    void stand(std::ostream &output, int gate);

    /**
     * REQUIRE(this->getStatus() == "Pushing back", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Taxiing to Runway", "Plane hasn't been set to the correct state.");
     */
    void pushBack(std::ostream &output);

    /**
     * REQUIRE(this->getStatus() == "Taxiing to Runway", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Taking Off", "Plane hasn't been set to the correct state.");
     */
    void taxiToRunway(std::ostream &output, const std::string& runway);

    void readyForTakeoff(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->getStatus() == "Taking Off", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Ascending", "Plane hasn't been set to the correct state.");
     */
    void takeOff(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->getStatus() == "Ascending", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Leaving Airport" || this->getStatus() == "Ascending", "Plane hasn't been set to the correct state.");
     */
    void ascend(std::ostream &output);

    /**
     * REQUIRE(this->getStatus() == "Leaving Airport", "Plane wasn't in correct state.");
     * ENSURE(this->getStatus() == "Travelling", "Plane hasn't been set to the correct state.");
     */
    void leaveAirport(std::ostream &output, const std::string& airport);
};


#endif //AIRPORTSIM_AIRPLANE_H
