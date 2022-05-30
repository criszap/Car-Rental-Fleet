## Car Rental Fleet

### Basic program to help car rental companies manage their rental fleet.

* **Car** class consists of:
  *  Default and Paramaterized Constructors.
    
  *  Getters & Setters for **car_id**, **car_model**, and **car_make**.
    
  *  **searchID(), searchMake(), searchModel()** -> User inputs id, make or model
      * Iterates through **std::vector** until id, make or model of car is found. If car is found then the cars info is displayed, otherwise user can search again.

  *  **deleteCar()** -> User inputs id:
      * Iterate through **std::vector** until id is found and vector.erase() is called on index. Once performed, success message is displayed.

  *  **addCar()** -> User inputs id, model, make:
      * Checks if ID is taken, if not then new object created is pushed into **std::vector**

  *  **printInfo()**:
      * Prints all info for car object.

  *  **readFile()**:
      * Reads **cars.data** until end of file is reached.
      * New Car objects are created and pushed into **std::vector**

  *  **mainMenu()** -> Main terminal-based interface:
      * Options to run the functions above are displayed.
      * On exit, cars in std::vector are saved into cars.data.
