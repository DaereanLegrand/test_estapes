#ifndef DRIVER_BAT_H
#define DRIVER_BAT_H

#define smooth 4

#define ADC_CHARGE ADC_CH4
#define ADC_DISCHARGE ADC_CH5

// Battery 1 Connections
#define OC1_INIT() INIT_GPIO7(OUT)
#define OC1_CLOSE() WRITE_GPIO7(HIGH)
#define OC1_OPEN() WRITE_GPIO7(LOW)
#define OC3_INIT() INIT_GPIO4(OUT)
#define OC3_CLOSE() WRITE_GPIO4(HIGH)
#define OC3_OPEN() WRITE_GPIO4(LOW)
#define ADC_BAT1 ADC_CH2
#define ADC_TEMP1 ADC_CH0

// Battery 2 Connections
#define OC2_INIT() INIT_GPIO5(OUT)
#define OC2_CLOSE() WRITE_GPIO5(HIGH)
#define OC2_OPEN() WRITE_GPIO5(LOW)
#define OC4_INIT() INIT_GPIO6(OUT)
#define OC4_CLOSE() WRITE_GPIO6(HIGH)
#define OC4_OPEN() WRITE_GPIO6(LOW)
#define ADC_BAT2 ADC_CH3
#define ADC_TEMP2 ADC_CH1

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief Battery Management System class, handle the two batteries on Bariton/Alto
     */
    enum BatteryState
    {
        CHARGE,
        DISCHARGE,
        STANDBY
    };

    class Battery
    {

    public:
        uint16_t voltage;     // In mV
        uint16_t temperature; // in mC
        uint16_t nbCycle;
        BatteryState state;
        uint16_t vMax = 2600;
        uint16_t vMin = 2000;
        bool enabled = true;
        virtual void charge();
        virtual void discharge();
        virtual void standby();
        virtual int getVoltage();
        virtual int getTemperature();
    };

    class Battery1 : public Battery
    {
    public:
        static Battery1 &getInstance()
        {
            static Battery1 instance;
            return instance;
        }

        void charge() override;
        void discharge() override;
        void standby() override;
        int getVoltage() override;
        int getTemperature() override;

    private:
        Battery1();
        Battery1(const Battery1 &) = delete;
        Battery1 &operator=(const Battery1 &) = delete;
    };

    class Battery2 : public Battery
    {
    public:
        static Battery2 &getInstance()
        {
            static Battery2 instance;
            return instance;
        }

        void charge() override;
        void discharge() override;
        void standby() override;
        int getVoltage() override;
        int getTemperature() override;

    private:
        Battery2();
        Battery2(const Battery2 &) = delete;
        Battery2 &operator=(const Battery2 &) = delete;
    };

    class BatteryManagementSystem
    {
    public:
        uint16_t chargeCurrent;
        uint16_t dischargeCurrent;
        Battery1 &battery1 = Battery1::getInstance();
        Battery2 &battery2 = Battery2::getInstance();
        Battery *batteries[2] = {&battery1, &battery2};
        int getChargeCurrent(void);
        int getDischargeCurrent(void);
    };

#ifdef __cplusplus
}
#endif
#endif // DRIVER_BAT_H