#include "vehicle.h"
#include "car.h"
#include "boat.h"
#include "airplane.h"
#include "VehicleManager.h"

#include <iostream>
#include <string>

void interactionLoop();
void newVehicleMenu();
void renameVehicleMenu();
void fuelVehicleMenu();
void driveVehicleMenu();

VehicleManager g_vm;

int main()
{
	interactionLoop();
}

void interactionLoop()
{
	bool running = true;
	char userInput;

	while (running)
	{
		printf("\n---------------------------------------------------\n");
		g_vm.listVehicles();
		printf("\nOptions:\n");
		printf("  1. New Vehicle\n");
		printf("  2. Rename Vehicle\n");
		printf("  3. Fuel Vehicle\n");
		printf("  4. Drive Vehicle\n");
		printf("(1,2,3,4): ");
		std::cin >> userInput;
		switch (userInput) {
		case '1':
			newVehicleMenu();
			break;
		case '2':
			renameVehicleMenu();
			break;
		case '3':
			fuelVehicleMenu();
			break;
		case '4':
			driveVehicleMenu();
			break;
		default:
			printf("Invalid option.\n");
		}
	}
}

void renameVehicleMenu() {
	if (g_vm.getVehicleCount() <= 0)
	{
		printf("\nERROR: Can't rename vehicles that haven't been created yet!\n");
		return;
	}


	printf("\n\nType the position of Vehicle in the list:\n");
	g_vm.listVehicles();
	printf("(0-%d): ", g_vm.getVehicleCount() - 1);
	int vehicleIndex;
	std::cin >> vehicleIndex;

	if (vehicleIndex < 0 || vehicleIndex >= g_vm.getVehicleCount())
	{
		printf("\nERROR: Vehicle index out of range.\n");
		return;
	}

	printf("Selected: \n");
	g_vm.getVehicle(vehicleIndex)->output();
	printf("What would you like to rename the vehicle to?\n");
	printf("(string): ");
	string newName;
	string oldName = g_vm.getVehicle(vehicleIndex)->getName();
	std::cin >> newName;
	g_vm.getVehicle(vehicleIndex)->setName(newName);
	printf("Renamed %s to %s.\n", oldName.c_str(), newName.c_str());
	return;
}

void newVehicleMenu() {
	char userInput;
	printf("\n\nSelect Vehicle Type:\n");
	printf("  1. Car\n");
	printf("  2. Boat\n");
	printf("  3. Plane (Not done yet)\n");
	printf("(1,2,3): ");
	std::cin >> userInput;
	switch (userInput) {
	case '1':
		g_vm.newVehicle(Vehicle::VEHICLE_TYPE::CAR);
		break;
	case '2':
		g_vm.newVehicle(Vehicle::VEHICLE_TYPE::BOAT);
		break;
	case '3':
		g_vm.newVehicle(Vehicle::VEHICLE_TYPE::PLANE);
		break;
	}
}

void fuelVehicleMenu() {
	if(g_vm.getVehicleCount()<=0)
	{ 
		printf("\nERROR: Can't add fuel to vehicles that haven't been created yet!\n");
		return;
	}

	
	printf("\n\nType the position of Vehicle in the list:\n");
	g_vm.listVehicles();
	printf("(0-%d): ", g_vm.getVehicleCount()-1);
	int vehicleIndex;
	std::cin >> vehicleIndex;

	if (vehicleIndex < 0 || vehicleIndex >= g_vm.getVehicleCount())
	{
		printf("\nERROR: Vehicle index out of range.\n");
		return;
	}

	printf("Selected: \n");
	g_vm.getVehicle(vehicleIndex)->output();
	printf("How much fuel would you like to supply?\n");
	printf("(>=0): ");
	double fuelInput;
	std::cin >> fuelInput;
	if (fuelInput < 0)
	{
		printf("\nERROR: Can't add negative fuel.\n");
		return;
	}
	g_vm.getVehicle(vehicleIndex)->addFuel(fuelInput);
	printf("Added %g fuel to vehicle named %s.\n", fuelInput, g_vm.getVehicle(vehicleIndex)->getName().c_str());
	return;
}

void driveVehicleMenu() {
	if (g_vm.getVehicleCount() <= 0)
	{
		printf("\nERROR: Can't drive vehicles that haven't been created yet!\n");
		return;
	}


	printf("\n\nType the position of Vehicle in the list:\n");
	g_vm.listVehicles();
	printf("(0-%d): ", g_vm.getVehicleCount() - 1);
	int vehicleIndex;
	std::cin >> vehicleIndex;

	if (vehicleIndex < 0 || vehicleIndex >= g_vm.getVehicleCount())
	{
		printf("\nERROR: Vehicle index out of range.\n");
		return;
	}

	printf("Selected: \n");
	g_vm.getVehicle(vehicleIndex)->output();
	printf("How far would you like to drive?\n");
	printf("(>=0): ");
	double distance;
	std::cin >> distance;
	
	Vehicle::VEHICLE_DRIVE_RESULT driveResult = g_vm.getVehicle(vehicleIndex)->drive(distance);
	switch (driveResult) {
	case Vehicle::VEHICLE_DRIVE_RESULT::NOT_ENOUGH_FUEL:
		printf("Not enough fuel!");
		return;
	case Vehicle::VEHICLE_DRIVE_RESULT::INVALID_DISTANCE:
		printf("Not enough fuel!");
		return;
	}


	printf("Drove %s for %g miles.\n", g_vm.getVehicle(vehicleIndex)->getName().c_str(), distance);
	return;
}