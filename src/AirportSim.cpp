//
// Created by lander on 3/16/18.
//

#include <sstream>
#include "AirportSim.h"
#include "utils.h"
#include "Exporter.h"

const std::vector<Airport *> &AirportSim::getAirports() const {
    return airports;
}

void AirportSim::setAirports(const std::vector<Airport *> &airports) {
    AirportSim::airports = airports;
}

const std::vector<Airplane *> &AirportSim::getAirplanes() const {
    return airplanes;
}

void AirportSim::setAirplanes(const std::vector<Airplane *> &airplanes) {
    AirportSim::airplanes = airplanes;
}

void AirportSim::simulate(std::ostream& SimOutput) {
    unsigned int time = 0;
    AirLeader leader;
    Airport* airport = airports[0];
//    int filecounter = -1;
    while (!checkSimEnd()) {
//        filecounter++;
//        std::stringstream iniFileNameStream;
//        std::stringstream fileNameStream;
//        iniFileNameStream << "../Engine/EngineTest" << filecounter << ".ini";
//        fileNameStream << "EngineTest" << filecounter << ".ini";
//        std::string iniFileName = iniFileNameStream.str();
//        std::string fileName = iniFileNameStream.str();
//        std::ofstream myfile;
//        myfile.open(iniFileName.c_str());
//        Exporter* exporter = new Exporter();
//        exporter->exportIni(myfile, airports);
//        exporter->generateImg(fileName.c_str());
        for (unsigned int i = 0; i<airplanes.size(); ++i) {
            Airplane* airplane = airplanes[i];
            if (airplane->getStatus() == "Travelling") {
                continue;
            }
            if (airplane->getStatus() == "Leaving Airport") {
                airplane->leaveAirport(SimOutput, airport->getName());
                continue;
            }
            if (airplane->getStatus() == "Ascending") {
                Runway* runway = airport->findPlaneInRunway(airplane);
                if (runway != NULL) {
                    runway->setAirplane(NULL);
                }
                airplane->ascend(SimOutput);
                continue;
            }
            if (airplane->getStatus() == "Taking Off") {
                Runway *runway = airport->findPlaneInRunway(airplane);
                if (runway == NULL) {
                    continue;
                }
                airplane->takeOff(SimOutput, airport->getName(), runway->getName());
                continue;
            }
            if (airplane->getStatus() == "Taxiing to Runway") {
                if (airport->findPlaneInGate(airplane) != -1){
                    airport->removePlaneFromGate(airplane);
                    airplane->setEndpoint(airport->getAvailableRunway());
                    Runway* runway = airplane->getEndpoint();
                    if (runway == NULL) {
                        continue;
                    }
                    if (runway->getCrossings().size() > 0){
                        SimOutput << airplane->getCallsign() << " is taxiing to holding point " << runway->getCrossings().front() << " via " << runway->getTaxipoints().front()->getName() << std::endl;
                        airplane->setCrossing(airport->findRunway(runway->getCrossings().front()));
                        runway->getTaxipoints().front()->setPlaneToRunway(airplane);
                    }
                    else{
                        SimOutput << airplane->getCallsign() << " is taxiing to runway " << runway->getName() << " via " << runway->getTaxipoints().back()->getName() << std::endl;
                        runway->removePlaneFromTaxipoint(airplane);
                        runway->setAirplaneCrossing(NULL);
                        airplane->taxiToRunway(SimOutput, runway->getName());
                        runway->setAirplane(airplane);
                    }
                }
                else if (airplane->getCrossing() == NULL){
                    Runway* runway = airplane->getEndpoint();
                    if (!runway->getCrossings().empty()){
                        Runway* runway2 = airport->findPlaneInCrossing(airplane);
                        for (unsigned int j = 0; j < runway->getCrossings().size(); ++j) {
                            if (airport->findRunway(runway->getCrossings()[j]) == runway2 && j - 1 >= 0){
                                SimOutput << airplane->getCallsign() << " is taxiing to holding point " << runway->getCrossings()[j - 1] << " via " << runway->getTaxipoints()[j]->getName() << std::endl;
                                runway->getTaxipoints()[j]->setPlaneToRunway(airplane);
                                runway->setAirplaneCrossing(NULL);
                                airplane->setCrossing(airport->findRunway(runway->getCrossings()[j - 1]));
                            }
                        }
                    }
                    if (airport->findPlaneInCrossing(airplane) != NULL && airplane->getEndpoint()->getAirplane() == NULL){
                        SimOutput << airplane->getCallsign() << " is taxiing to runway " << runway->getName() << " via " << runway->getTaxipoints().back()->getName() << std::endl;
                        runway->setAirplaneCrossing(NULL);
                        runway->removePlaneFromTaxipoint(airplane);
                        airplane->taxiToRunway(SimOutput, runway->getName());
                        runway->setAirplane(airplane);
                    }
                }
                else{
                    Runway* runway = airplane->getCrossing();
                    if (runway->getTaxipoints().back()->getPlaneToRunway() != NULL){   //Check if next taxipoint is occupied
                        continue;
                    }
                    if (runway->getAirplane() == NULL){   //If runway is not occupied
                        SimOutput << airplane->getCallsign() << " is crossing " << runway->getName() << std::endl;
                        runway->removePlaneFromTaxipoint(airplane);
                        airplane->setCrossing(NULL);
                        runway->setAirplaneCrossing(airplane);
                    }
                    else{
                        SimOutput << airplane->getCallsign() << " is holding short at " << runway->getName() << std::endl;
                    }
                }
                continue;
            }
            if(airplane->getStatus() == "Standing at Gate"){
                airplane->stand(SimOutput, airport->findPlaneInGate(airplane));
            }
            if (airplane->getStatus() == "Boarding Plane") {
                airplane->boardPlane(SimOutput, airport->getName(), airport->findPlaneInGate(airplane));
                continue;
            }
            if (airplane->getStatus() == "Refueling Plane") {
                airplane->refuelPlane(SimOutput);
                continue;
            }
            if (airplane->getStatus() == "Checking Plane") {
                airplane->checkPlane(SimOutput);
                continue;
            }
            if (airplane->getStatus() == "Unboarding Plane") {
                airplane->unboardPlane(SimOutput, airport->getName(), airport->findPlaneInGate(airplane));
                continue;
            }
            if (airplane->getStatus() == "Taxiing to Gate") {
                if (airport->findPlaneInRunway(airplane) != NULL) { //Remove plane from the runway that it landed on
                    Runway *runway = airport->findPlaneInRunway(airplane);
                    leader.printMessage(time, "AIR", airport->getCallsign() + ", " + airplane->getCallsign() + ",  runway " + runway->getName() + " vacated.");
                    leader.printMessage(time, "ATC", "TODO: Instructions for taxiing");
                    runway->setAirplane(NULL);
                    runway->setAirplaneCrossing(airplane);
                }
                if (airplane->getCrossing() == NULL){
                    Runway *runway = airport->findPlaneInCrossing(airplane);
                    if (!runway->getCrossings().empty()){
                        SimOutput << airplane->getCallsign() << " is taxiing to holding point " << runway->getCrossings().back() << " via " << runway->getTaxipoints().back()->getName() << std::endl;
                        runway->setAirplaneCrossing(NULL);
                        runway->getTaxipoints().back()->setPlaneToGate(airplane);   //Set taxipoint
                        airplane->setCrossing(airport->findRunway(runway->getCrossings().back()));
                    }
                    else{
                        airport->getFarthestRunway()->removePlaneFromTaxipoint(airplane);     //Remove plane from taxipoint
                        int gate = airport->getAvailableGate();
                        if (gate == -1) {
                            continue;
                        }
                        airport->addPlaneToGate(airplane, gate);
                        airplane->taxiToGate(SimOutput, gate);
                    }
                }
                else{
                    Runway* runway = airplane->getCrossing();
                    if (runway->getTaxipoints().size() > 1 && runway->getTaxipoints()[runway->getTaxipoints().size()-2]->getPlaneToGate() != NULL){   //Check if next taxipoint is occupied
                        continue;
                    }
                    if (runway->getAirplane() == NULL){   //If runway is not occupied
                        SimOutput << airplane->getCallsign() << " is crossing " << runway->getName() << std::endl;
                        runway->removePlaneFromTaxipoint(airplane);     //Remove plane from taxipoint
                        runway->setAirplaneCrossing(airplane);
                        airplane->setCrossing(NULL);
                    }
                    else{
                        SimOutput << airplane->getCallsign() << " is holding short at " << runway->getName() << std::endl;
                    }
                }
                continue;
            }
            if (airplane->getStatus() == "Landed") {
                Runway* runway = airport->findPlaneInRunway(airplane);
                airplane->landed(SimOutput, airport->getName(), runway->getName());
                continue;
            }
            if (airplane->getStatus() == "Landing") {
                Runway* runway = airport->findPlaneInRunway(airplane);
                airplane->land(SimOutput, airport->getName(), runway->getName());
                continue;
            }
            if (airplane->getStatus() == "Final Approach") {
                Runway* runway = airport->findPlaneInRunway(airplane);
                airplane->finalapproach(SimOutput, airport->getName(), runway->getName());
                leader.printMessage(time, "ATC", airplane->getCallsign() + ", cleared ILS approach runway " + runway->getName());
                leader.printMessage(time, "AIR", "Cleared ILS approach runway " + runway->getName() + ", " + airplane->getCallsign());
                continue;
            }
            if (airplane->getStatus() == "Flying wait pattern") {
                if (airplane->getHeight() == 5000 && airport->getH3000() == NULL) {
                    airport->setH5000(NULL);
                    airport->setH3000(airplane);
                    airplane->setStatus("Descending to 3k");
                    airplane->descendTo3k(SimOutput);
                    continue;
                }
                else if (airplane->getHeight() == 3000 && airport->getAvailableRunway()) {
                    Runway* runway = airport->getAvailableRunway();
                    airport->setH3000(NULL);
                    airplane->setStatus("Final Approach");
                    airplane->finalapproach(SimOutput, airport->getName(), runway->getName());
                    runway->setAirplane(airplane);
                    continue;
                }
                airplane->flyWaitPattern(SimOutput);
                leader.printMessage(time, "ATC", airplane->getCallsign() + ", hold south on the one eighty radial, expect further clearance at " + to_string(time));
                leader.printMessage(time, "AIR", "Holding south on the one eighty radial, " + airplane->getCallsign());
                continue;
            }
            if (airplane->getStatus() == "Descending to 3k") {
                airplane->descendTo3k(SimOutput);
                continue;
            }
            if (airplane->getStatus() == "Descending to 5k") {
                airplane->descendTo5k(SimOutput);
                continue;
            }
            if (airplane->getStatus() == "Approaching") {
                if (airport->getH5000() == NULL) {
                    airport->setH5000(airplane);
                    airplane->approach(SimOutput, airport->getName());
                    leader.printMessage(time, "AIR", airport->getCallsign()+ ", " + airplane->getCallsign() + ", arriving at " + airport->getName());
                    leader.printMessage(time, "ATC", airplane->getCallsign() + ", radar contact, descendTo5k and maintain five thousand feet, squawk " + airplane->getType());
                    leader.printMessage(time, "AIR", "Descend and maintain five thousand feet, squawking " + airplane->getType() + ", " + airplane->getCallsign());
                }
                continue;
            }
        }
        time += 1;
    }
}

bool AirportSim::checkSimEnd() {
    for (unsigned int i = 0; i<airplanes.size(); ++i) {
        Airplane* airplane = airplanes[i];
        if (airplane->getStatus() != "Travelling") {
            return false;
        }
    }
    return true;
}
