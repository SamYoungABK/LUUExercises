#include "Airplane.h"

Vehicle::VEHICLE_DRIVE_RESULT Airplane::drive(double distance)
{
	if (distance < 0)
		return VEHICLE_DRIVE_RESULT::INVALID_DISTANCE;

	if ((distance * 1 / m_fuelConsumption) > m_fuel)
		return VEHICLE_DRIVE_RESULT::NOT_ENOUGH_FUEL;

	m_fuel -= distance * 1 / m_fuelConsumption;
	m_distanceDriven += distance;

	return VEHICLE_DRIVE_RESULT::SUCCESS;
}