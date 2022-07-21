#pragma once
#include <string>
#include <random>

using std::string;



class Vehicle
{
protected:
	string m_name = "";

	double m_fuel = 0;
	double m_distanceDriven = 0;
	double m_fuelCapacity = 0;
	double m_fuelConsumption = 0;

public:
	enum class VEHICLE_TYPE
	{
		UNDEFINED,
		CAR,
		BOAT,
		PLANE
	};

	enum class VEHICLE_DRIVE_RESULT {
		NOT_ENOUGH_FUEL,
		INVALID_DISTANCE,
		SUCCESS,
	};

	Vehicle(double fuelCapacity = 0, double fuelConsumption = 0) :
		m_fuelCapacity{ fuelCapacity },
		m_fuelConsumption{ fuelConsumption } {}

	void setName(string name);
	string getName();
	void output();
	bool addFuel(int amount);

	virtual VEHICLE_DRIVE_RESULT drive(double distance) = 0;
};
