#ifndef DRIVER_BAT_H
#define DRIVER_BAT_H

#include <stdint.h>
#include <stdbool.h>

#define smooth 4

#define ADC_CHARGE ADC_CH4
#define ADC_DISCHARGE ADC_CH5

#define OC1_INIT() INIT_GPIO7(OUT)
#define OC1_CLOSE() WRITE_GPIO7(HIGH)
#define OC1_OPEN() WRITE_GPIO7(LOW)
#define OC3_INIT() INIT_GPIO4(OUT)
#define OC3_CLOSE() WRITE_GPIO4(HIGH)
#define OC3_OPEN() WRITE_GPIO4(LOW)
#define ADC_BAT1 ADC_CH2
#define ADC_TEMP1 ADC_CH0

#define OC2_INIT() INIT_GPIO5(OUT)
#define OC2_CLOSE() WRITE_GPIO5(HIGH)
#define OC2_OPEN() WRITE_GPIO5(LOW)
#define OC4_INIT() INIT_GPIO6(OUT)
#define OC4_CLOSE() WRITE_GPIO6(HIGH)
#define OC4_OPEN() WRITE_GPIO6(LOW)
#define ADC_BAT2 ADC_CH3
#define ADC_TEMP2 ADC_CH1

typedef enum {
	CHARGE,
	DISCHARGE,
	STANDBY
} BatteryState;

typedef struct Battery Battery;

struct Battery {
	uint16_t voltage;
	uint16_t temperature;
	uint16_t nbCycle;
	BatteryState state;
	uint16_t vMax;
	uint16_t vMin;
	bool enabled;

	void (*charge)();
	void (*discharge)();
	void (*standby)();
	int (*getVoltage)();
	int (*getTemperature)();
};

typedef struct {
	Battery battery0;
	Battery battery1;
	Battery *batteries[2];
	uint16_t chargeCurrent;
	uint16_t dischargeCurrent;
    uint16_t (*getChargeCurrent)();
    uint16_t (*getDischargeCurrent)();
} BatteryManagementSystem;

BatteryManagementSystem *bms_get(void);

#define bms (*bms_get())

#endif
