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
class Exporter;
class Airport;

class Airplane {
protected:  //Protected variables for inherited classes
    Airplane* initCheck;
    std::string number;
    std::string model;
    std::string type;
    std::string engine;
    int fuel;
    int height;
    int squawk;
    bool communicating;
    bool awaitingLeader;
    bool hasFlightPlan;
    int time;
    int passengers;
    std::string callsign;
    std::string status;
    std::string destination;
    int departure;
    bool skipGateSteps;
    int originalSquawk;
    int arrival;
    int interval;

public:
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    bool useFlightPlan();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param hasFlightPlan
     */
    void setHasFlightPlan(bool hasFlightPlan);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    bool isAwaitingLeader();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param awaitingLeader
     */
    void setAwaitingLeader(bool awaitingLeader);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getOriginalSquawk();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param originalSquawk
     */
    void setOriginalSquawk(int originalSquawk);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    bool getSkipGateSteps();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param skipGateSteps
     */
    void setSkipGateSteps(bool skipGateSteps);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    const std::string &getDestination();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param destination
     */
    void setDestination(const std::string &destination);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getDeparture();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param departure
     */
    void setDeparture(int departure);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getArrival();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param arrival
     */
    void setArrival(int arrival);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getInterval();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param interval
     */
    void setInterval(int interval);


    /**
     * ENSURE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     */
    Airplane();
    /**
     * ENSURE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     */
    Airplane(Airplane* airplane);
    /**
     * ENSURE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     */
    virtual ~Airplane();
    /**
     *
     * @return
     */
    bool properlyInitialized();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param output
     */
    void printInfo(std::ofstream &output);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getSquawk();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param squawk
     */
    void setSquawk(int squawk);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    bool isCommunicating();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param communication
     */
    void setCommunication(bool communication);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getTime();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param time
     */
    void setTime(int time);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    const std::string &getCallsign();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param callsign
     */
    void setCallsign(const std::string &callsign);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    const std::string &getNumber();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param number
     */
    void setNumber(const std::string &number);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    const std::string &getModel();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param model
     */
    void setModel(const std::string &model);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    const std::string &getStatus();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param status
     */
    void setStatus(const std::string &status);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getPassengers();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param passengers
     */
    void setPassengers(int passengers);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getFuel();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param fuel
     */
    void setFuel(int fuel);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    int getHeight();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param height
     */
    void setHeight(int height);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    const std::string &getType();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param type
     */
    void setType(const std::string &type);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    const std::string &getEngine();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param engine
     */
    void setEngine(const std::string &engine);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    bool isAtGate();
    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @return
     */
    bool isAtRunway();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Approaching", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Descending to 5k", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     */
    void approach(std::ostream &output, const std::string& airport);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Flying wait pattern, "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Flying wait pattern", "Plane should be set to the correct state.");
     * @param output
     */
    void flyWaitPattern(std::ostream &output);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Descending to 5k", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Descending to 5k" || this->getStatus() == "Flying wait pattern", "Plane should be set to the correct state.");
     * @param output
     */
    void descendTo5k(std::ostream &output);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Descending to 3k", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Descending to 3k" || this->getStatus() == "Flying wait pattern", "Plane should be set to the correct state.");
     * @param output
     */
    void descendTo3k(std::ostream &output);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Final Approach", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Landing" || this->getStatus() == "Final Approach", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     * @param runway
     */
    void finalapproach(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Landing", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Landed" || this->getStatus() == "Landing", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     * @param runway
     */
    void land(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Landed", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Landed", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     * @param runway
     */
    void landed(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Taxiing to Gate", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Unboarding Plane", "Plane should be set to the correct state.");
     * @param output
     * @param gate
     */
    void taxiToGate(std::ostream &output, int gate);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Unboarding Plane", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Checking Plane" || this->getStatus() == "Unboarding Plane", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     * @param gate
     */
    virtual void unboardPlane(std::ostream &output, const std::string& airport, int gate){};

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Checking Plane", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Refueling Plane" || this->getStatus() == "Checking Plane", "Plane should be set to the correct state.");
     * @param output
     */
    virtual void checkPlane(std::ostream &output){};

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Refueling Plane", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Boarding Plane", "Plane should be set to the correct state.");
     * @param output
     */
    virtual void refuelPlane(std::ostream &output){};

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Boarding Plane", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Standing at Gate" || this->getStatus() == "Boarding Plane", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     * @param gate
     */
    virtual void boardPlane(std::ostream &output, const std::string& airport, int gate){};

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Standing at Gate", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Standing at Gate", "Plane should be set to the correct state.");
     * @param output
     * @param gate
     */
    void stand(std::ostream &output, int gate);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Pushing back", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Taxiing to Runway" || this->getStatus() == "Pushing back", "Plane should be set to the correct state.");
     * @param output
     */
    virtual void pushBack(std::ostream &output){};

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Taxiing to Runway", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Ready for Takeoff", "Plane should be set to the correct state.");
     * @param output
     * @param runway
     */
    void taxiToRunway(std::ostream &output, const std::string& runway);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Ready for Takeoff", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Taking Off", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     * @param runway
     */
    void readyForTakeoff(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Taking Off", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Ascending" || this->getStatus() == "Taking Off", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     * @param runway
     */
    void takeOff(std::ostream &output, const std::string& airport, const std::string& runway);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Ascending", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Leaving Airport" || this->getStatus() == "Ascending", "Plane should be set to the correct state.");
     * @param output
     */
    void ascend(std::ostream &output);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * REQUIRE(this->getStatus() == "Leaving Airport", "Plane has to the be in correct state.");
     * ENSURE(this->getStatus() == "Travelling", "Plane should be set to the correct state.");
     * @param output
     * @param airport
     */
    void leaveAirport(std::ostream &output, const std::string& airport);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     */
    virtual void consumeFuel(){};

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param runway
     * @param nextrunway
     * @param airport
     * @param exporter
     * @param SimOutput
     * @param simTime
     */
    void executeTaxiingToGate(Runway* runway, Runway* nextrunway, Airport* airport, Exporter &exporter, std::ostream &SimOutput, unsigned int &simTime);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param runway
     * @param nextrunway
     * @param airport
     * @param exporter
     * @param SimOutput
     * @param simTime
     */
    void executeWaitingToCrossToGate(Runway* runway, Runway* nextrunway, Airport* airport, Exporter &exporter, std::ostream &SimOutput, unsigned int &simTime);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param runway
     * @param airport
     * @param exporter
     * @param SimOutput
     * @param simTime
     */
    void executeTaxiingToRunway(Runway* runway, Airport* airport, Exporter &exporter, std::ostream &SimOutput, unsigned int &simTime);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param runway
     * @param nextrunway
     * @param airport
     * @param exporter
     * @param SimOutput
     * @param simTime
     */
    void executeWaitingToCrossToRunway(Runway* runway, Runway* nextrunway, Airport* airport, Exporter &exporter, std::ostream &SimOutput, unsigned int &simTime);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param airport
     * @param exporter
     * @param SimOutput
     * @param simTime
     */
    void executeFlyingWaitPattern(Airport* airport, Exporter &exporter, std::ostream &SimOutput, unsigned int &simTime);

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     */
    void landImmediately();

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param output
     * @param airport
     * @param runway
     */
    virtual void unboardAtRunway(std::ostream &output, const std::string &airport, const std::string &runway){};

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param output
     */
    virtual void checkAtRunway(std::ostream &output){};

    /**
     * REQUIRE(this->properlyInitialized(), "Plane wasn't properly initialized.");
     * @param output
     */
    virtual void refuelAtRunway(std::ostream &output){};
};


#endif //AIRPORTSIM_AIRPLANE_H
