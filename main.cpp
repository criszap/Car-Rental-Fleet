#include "Car.h"

int main() {
    std::fstream carf("cars.data");
    std::vector<Car> carv;
    Car c{};

    c.readFile(carf, carv);
    carf.close();
    
    c.mainMenu(carf, carv);
}