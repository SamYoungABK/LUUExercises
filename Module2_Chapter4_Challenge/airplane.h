#pragma once
#include "vehicle.h"

class Airplane :
	public Vehicle
{
public:
	Airplane(double fuelCapacity = 40, double fuelConsumption = 4) :
		Vehicle(fuelCapacity, fuelConsumption) {}

	VEHICLE_DRIVE_RESULT drive(double distance) override;
};
