#include "driver_bat.h"

static uint16_t bms_getChargeCurrent(void)
{
    return bms.chargeCurrent;
}

static uint16_t bms_getDischargeCurrent(void)
{
    return bms.dischargeCurrent;
}

static void charge_battery0()
{
	bms.battery0.state = CHARGE;
}

static void discharge_battery0()
{
	bms.battery0.state = DISCHARGE;
}

static void standby_battery0()
{
	bms.battery0.state = STANDBY;
}

static int getVoltage_battery0()
{
	bms.battery0.voltage = 0;
	return bms.battery0.voltage;
}

static int getTemperature_battery0()
{
	bms.battery0.temperature = 0;
	return bms.battery0.temperature;
}

static void Battery1_init(Battery *bat)
{
	bat->vMax = 2600;
	bat->vMin = 2000;
	bat->enabled = true;
	bat->charge = charge_battery0;
	bat->discharge = discharge_battery0;
	bat->standby = standby_battery0;
	bat->getVoltage = getVoltage_battery0;
	bat->getTemperature = getTemperature_battery0;
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

static void Battery2_init(Battery *bat)
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

BatteryManagementSystem *bms_get(void)
{
	static BatteryManagementSystem instance;
	static bool initialized = false;

	if (!initialized) {
		Battery1_init(&instance.battery0);
		Battery2_init(&instance.battery1);
		instance.batteries[0] = &instance.battery0;
		instance.batteries[1] = &instance.battery1;
        instance.getChargeCurrent = bms_getChargeCurrent;
        instance.getDischargeCurrent = bms_getDischargeCurrent;
		initialized = true;
	}

	return &instance;
}
