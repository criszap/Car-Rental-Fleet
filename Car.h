#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Car {
public:
    // constructors
    Car();
    Car(int id, std::string make, std::string model);

    // getters/setters
    int getID() { return _id; }
    std::string getModel() { return _model; }
    std::string getMake() { return _make; }

    void setID(int id) { _id = id; }
    void setModel(std::string model) { _model = model; }
    void setMake(std::string make) { _make = make; }

    // search functions
    void searchID(std::vector<Car>& carv);
    void searchMake(std::vector<Car>& carv);
    void searchModel(std::vector<Car>& carv);

    // init + other functions
    void readFile(std::fstream& carf, std::vector<Car>& carv);
    void printInfo();
    void deleteCar(std::vector<Car>& carv);
    void addCar(std::vector<Car>& carv);
    void mainMenu(std::fstream& carf, std::vector<Car>& carv);

private:
    int _id;
    std::string _model;
    std::string _make;
};