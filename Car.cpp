#include "Car.h"

// CONSTRUCTORS
Car::Car()
    : _id { -999 }, _make { "" }, _model { "" } {}

Car::Car(int id, std::string make, std::string model)
    : _id { id }, _make { make }, _model { model } {}


// PRINT CAR INFO
void Car::printInfo() {
    std::cout << "ID: " << _id << "\n";
    std::cout << "MAKE: " << _make << "\n";
    std::cout << "MODEL: " << _model << "\n";
    std::cout << "\n";
}

// READ FILE & INITIALIZE VECTOR
void Car::readFile(std::fstream& carf, std::vector<Car>& carv) {
    while (!carf.eof()) {
        Car c{};
           
        // car ID
        carf >> _id;
        c.setID(_id);

        // car Make
        std::getline(carf, _make);
        std::getline(carf, _make);
        c.setMake(_make);

        // car Model 
        std::getline(carf, _model);
        c.setModel(_model);

        // push into vector
        carv.push_back(c);
    }

    carv.pop_back();
}

// SEARCH CAR BY ID
void Car::searchID(std::vector<Car>& carv) {
    int in_id;
    bool id_found = false;
    Car c{};

    std::cout << "*** ID's start from '0' and so on... ***\n";
    std::cout << "Enter Car ID: \n";
    std::cin >> in_id;
    std::cout << "\n";

    for (int i = 0; i < carv.size(); ++i) {
        if (carv[i]._id == in_id) {
            id_found = true;
            c = carv[i];
            break;
        }
        id_found = false;
    }

    if (id_found) {
        std::cout << "CAR INFO FOUND: \n";
        c.printInfo();
    }
    else {
        searchID(carv);
    }
}

// SEARCH CAR BY MAKE
void Car::searchMake(std::vector<Car>& carv) {
    std::string in_make;
    Car c{};

    std::cout << "*** ALL Cars will be displayed ***\n";
    std::cout << "Enter Car Make: \n";
    std::cin >> in_make;
    std::cout << "\n";

    for (int i = 0; i < carv.size(); ++i) {
        if (carv[i]._make == in_make) {
            c = carv[i];
            c.printInfo();
        }
    }

    if (c._id == -999) {
        std::cout << "NO CARS FOUND!\n";
        searchMake(carv);
    }
}

// SEARCH CAR BY MODEL
void Car::searchModel(std::vector<Car>& carv) {
    std::string in_model;
    Car c{};

    std::cout << "*** ALL Cars will be displayed ***\n";
    std::cout << "Enter Car Model: \n";
    std::cin >> in_model;
    std::cout << "\n";

    for (int i = 0; i < carv.size(); ++i) {
        if (carv[i]._model.find(in_model) != std::string::npos) {
            c = carv[i];
            c.printInfo();
        }
    }

    if (c._id == -999) {
        std::cout << "NO CARS FOUND!\n";
        searchModel(carv);
    }
}

// DELETE CAR
void Car::deleteCar(std::vector<Car>& carv) {
    int car_id;
    bool found = false;
    std::cout << "Enter ID of Car: \n";
    std::cin >> car_id;

    for (int i = 0; i < carv.size(); ++i) {
        if (carv[i]._id == car_id) {
            found = true;
            carv.erase(carv.begin() + i);
            std::cout << "CAR DELETED. \n";
            break;
        }
    }

    if (!found) {
        std::cout << "NO CARS OF ID - " << car_id << " WERE FOUND.\n";
    }
}

// ADD CAR
void Car::addCar(std::vector<Car>& carv) {
    int in_id;
    std::cout << "Enter ID: ";
    std::cin >> in_id;

    bool same = true;
    for (int i = 0; i < carv.size(); ++i) {
		if (in_id == carv[i]._id) {
			std::cout << "ID IS TAKEN.\n \n";
			same = false;
		}
    }

    if (same) {
        // gets user-inputted Make & Model
        std::string in_make;
		std::cout << std::endl << "Enter Make: ";
		std::getline(std::cin, in_make);
		std::getline(std::cin, in_make);

        std::string in_model;
		std::cout << std::endl << "Enter Model: ";
		std::getline(std::cin, in_model);
		std::cout << std::endl;

		// creates new object with user-inputted info
		// and pushes into vector.
		Car c = { in_id, in_make, in_model };
		carv.push_back(c);
    }
    else {
        addCar(carv);
    }
}

// MAIN MENU
void Car::mainMenu(std::fstream& carf, std::vector<Car>& carv) {
	// main menu interface
	std::cout << "------------------------------------\n";
	std::cout << "Display all cars (1) \n";
	std::cout << "Search by ID (2) \n";
	std::cout << "Search by Make (3) \n";
	std::cout << "Search by Model (4) \n";
	std::cout << "Add New Car (5) \n";
	std::cout << "Delete Car (6) \n";
	std::cout << "Exit (7) \n";
	std::cout << "------------------------------------\n";
	std::cout << std::endl;

    // choice interface
	int choice;
	std::cout << "Enter choice: \n";
	std::cin >> choice;
	std::cout << std::endl;

    // Display all cars (1)
    if (choice == 1) {
        for (int i = 0; i < carv.size(); ++i) {
            if (carv[i]._id != 999) {
				carv[i].printInfo();
			}
        }
        mainMenu(carf, carv);
    }

    // Search by ID (2)
    else if (choice == 2) {
        searchID(carv);
        mainMenu(carf, carv);
    }

    // Search by Make (3)
    else if (choice == 3) {
        searchMake(carv);
        mainMenu(carf, carv);
    }

    // Search by Model (4)
    else if (choice == 4) {
        searchModel(carv);
        mainMenu(carf, carv);
    }

    // Add New Car (5)
    else if (choice == 5) {
        addCar(carv);
        mainMenu(carf, carv);
    }

    // Delete Car (6)
    else if (choice == 6) {
        deleteCar(carv);
        mainMenu(carf, carv);
    }

    // Exit (7)
    else if (choice == 7) {
        carf.open("cars.data", std::ios::out);
        for (int i = 0; i < carv.size(); ++i) {
            if (carv[i]._id != -999) {
				carf << carv.at(i)._id << std::endl;
				carf << carv.at(i)._make << std::endl;
				carf << carv.at(i)._model << std::endl << std::endl;
            }
        }

        carf.close();
        exit(1);
    }
    else {
        std::cout << "INVALID CHOICE.\n";
        mainMenu(carf, carv);
    }
}