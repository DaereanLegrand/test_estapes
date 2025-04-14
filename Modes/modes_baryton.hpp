#ifndef MODES_BARYTON_HPP
#define MODES_BARYTON_HPP

#include "mode.hpp"
#undef PARAMETERS_H
#include "../CU_BARYTON_Reg.h"
#include "driver_bat.hpp"

uint32_t readTime();
class BarytonMode : public Mode
{
protected:
    BatteryManagementSystem bms;
    uint32_t lastTimeStampParam;

public:
    BarytonMode(int mode) : Mode(mode) {};
    void entering() override;
    void routine() override;
    void leaving(int nextMode) override;
    void shootHK() override;
};

class BarytonModeInit : public BarytonMode
{
public:
    BarytonModeInit() : BarytonMode(0) {};
    void entering() override;
    void routine() override;
    void leaving(int nextMode) override;
    void shootHK() override;
};
/***
 * @brief BarytonModeDiagnostic is used to test the batteries
 */
class BarytonModeDiagnostic : public BarytonMode
{
private:
    uint32_t lastTimeStamp;
    int currentBattery;
    int chargeCycleLength;
    int dischargeCycleLength;
    bool bat1_enable;
    bool bat2_enable;

public:
    BarytonModeDiagnostic() : BarytonMode(0x1000) {};
    void entering() override;
    void routine() override;
    void leaving(int nextMode) override;
    void shootHK() override;
};

class BarytonModeExperiment : public BarytonMode
{
private:
    int lastTimeStamp;
    int maxChargeCurrent;
    int currentBattery;
    BatteryState state;
    BatteryState prevState;
    int count = 0;

public:
    BarytonModeExperiment() : BarytonMode(0x2000) {};
    void entering() override;
    void routine() override;
    void leaving(int nextMode) override;
    void shootHK() override;
};

class BarytonModeError : public BarytonMode
{
public:
    BarytonModeError() : BarytonMode(0xFF00) {};
    void entering() override;
    void routine() override;
    void leaving(int nextMode) override;
    void shootHK() override;
};

class BarytonModeEnd : public BarytonMode
{
public:
    BarytonModeEnd() : BarytonMode(0xEE00) {};
    void entering() override;
    void routine() override;
    void leaving(int nextMode) override;
    void shootHK() override;
};

#endif