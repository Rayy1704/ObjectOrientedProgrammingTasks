Car Information Management System
This C++ program allows users to manage and display information about cars, including their make, model, engine cylinders, and horsepower. It provides a menu-driven interface for easy navigation.

Features
Set make (company) of the car
Set model of the car
Set number of cylinders in the car's engine
Set engine horsepower
Print car information
Exit the program
Implementation Details
The program consists of two main classes:

1. Engine
The Engine class represents the engine of the car.
It has private member variables cylinders and horsePower.
Public member functions include:
setHp(int hp): Set the horsepower of the engine.
setCyl(int c): Set the number of cylinders in the engine.
getHp(): Get the horsepower of the engine.
getCyl(): Get the number of cylinders in the engine.
2. Car
The Car class represents a car object, which contains information about the car's make, model, and engine.
It has private member variables make, model, and an instance of the Engine class.
Public member functions include:
Constructor: Initializes the car object with provided horsepower, number of cylinders, make, and model.
printInfo(): Prints the information about the car, including make, model, number of cylinders, and engine horsepower.
Setters and getters for make, model, engine horsepower, and number of cylinders.
Menu and User Interaction
The menu() function displays a menu for the user to interact with.
Users can navigate through the menu using arrow keys and select options by pressing Enter.
The process() function handles the user's choice and interacts with the Car object accordingly.
The main() function initializes a Car object with default values and runs a loop to process user input until the user chooses to exit.
How to Use
Compile the program using a C++ compiler.
Run the compiled executable.
Follow the on-screen prompts to interact with the program and manage car information.
Choose the "Exit" option to close the program.