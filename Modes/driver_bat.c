#include "driver_bat.h"

static uint16_t bms_getChargeCurrent(void)
{
    return bms.chargeCurrent;
}

static uint16_t bms_getDischargeCurrent(void)
{
    return bms.dischargeCurrent;
}

static void charge_battery1()
{
	bms.battery1.state = CHARGE;
}

static void discharge_battery1()
{
	bms.battery1.state = DISCHARGE;
}

static void standby_battery1()
{
	bms.battery1.state = STANDBY;
}

static int getVoltage_battery1()
{
	bms.battery1.voltage = 0;
	return bms.battery1.voltage;
}

static int getTemperature_battery1()
{
	bms.battery1.temperature = 0;
	return bms.battery1.temperature;
}

static void Battery1_init(Battery *bat)
{
	bat->vMax = 2600;
	bat->vMin = 2000;
	bat->enabled = true;
	bat->charge = charge_battery1;
	bat->discharge = discharge_battery1;
	bat->standby = standby_battery1;
	bat->getVoltage = getVoltage_battery1;
	bat->getTemperature = getTemperature_battery1;
}

static void charge_battery2()
{
	bms.battery2.state = CHARGE;
}

static void discharge_battery2()
{
	bms.battery2.state = DISCHARGE;
}

static void standby_battery2()
{
	bms.battery2.state = STANDBY;
}

static int getVoltage_battery2()
{
	bms.battery2.voltage = 0;
	return bms.battery2.voltage;
}

static int getTemperature_battery2()
{
	bms.battery2.temperature = 0;
	return bms.battery2.temperature;
}

static void Battery2_init(Battery *bat)
{
	bat->vMax = 2600;
	bat->vMin = 2000;
	bat->enabled = true;
	bat->charge = charge_battery2;
	bat->discharge = discharge_battery2;
	bat->standby = standby_battery2;
	bat->getVoltage = getVoltage_battery2;
	bat->getTemperature = getTemperature_battery2;
}

BatteryManagementSystem *bms_get(void)
{
	static BatteryManagementSystem instance;
	static bool initialized = false;

	if (!initialized) {
		Battery1_init(&instance.battery1);
		Battery2_init(&instance.battery2);
		instance.batteries[0] = &instance.battery1;
		instance.batteries[1] = &instance.battery2;
        instance.getChargeCurrent = bms_getChargeCurrent;
        instance.getDischargeCurrent = bms_getDischargeCurrent;
		initialized = true;
	}

	return &instance;
}
