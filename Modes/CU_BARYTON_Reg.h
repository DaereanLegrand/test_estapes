#define ADDR_OFFSET_CU_ID 0 // \param CU Identifier  [0-255]
#define ADDR_OFFSET_VERSION 1 // \param Version du LV [0-255]
#define ADDR_OFFSET_MODE 2 // \param Mode de fonctionnement de la CU [0-5]
#define ADDR_OFFSET_MODE_SUIVANT 3 // \param Mode Suivant de la CU  [0-5]
#define ADDR_OFFSET_TIME_CCSDS_100MS 4 // \param Registre de Temps ( 100ms ecoule de la minute ) nan
#define ADDR_OFFSET_TIME_CCSDS_MIN 5 // \param Registre de Temps (minute ecoule du jour ) nan
#define ADDR_OFFSET_TIME_CCSDS_DAYS 6 // \param Registre de Temps ( Jour ecoule depuis le 01/01/2000) nan
#define ADDR_OFFSET_CTRL_uC 7 // \param AlimSec[15:13] | Ctrl_Fault(12) | T[11:0] nan
#define ADDR_OFFSET_NB_BYTE_DP_HK 8 // \param Nombre de Byte de type HK en mémoire [0-255]
#define ADDR_OFFSET_NB_BYTE_DP_RAW 9 // \param Nombre de Byte de type RAW en mémoire [0-255]
#define ADDR_OFFSET_RESERVE_DP_3 10 // \param Nombre de Byte de type "Bloc Data 3" en mémoire [0-255]
#define ADDR_OFFSET_RESERVE_DP_4 11 // \param Nombre de Byte de type "Bloc Data 4" en mémoire [0-255]
#define ADDR_OFFSET_RESERVE_DP_5 12 // \param Nombre de Byte de type "Bloc Data 5" en mémoire [0-255]
#define ADDR_OFFSET_RESERVE_DP_6 13 // \param Nombre de Byte de type "Bloc Data 6" en mémoire [0-255]
#define ADDR_OFFSET_RESERVE_DP_7 14 // \param Nombre de Byte de type "Bloc Data 7" en mémoire [0-255]
#define ADDR_OFFSET_RESERVE_DP_8 15 // \param Nombre de Byte de type "Bloc Data 8" en mémoire [0-255]
#define ADDR_OFFSET_ChargeCurrent 16 // \param Charge Current [0-65535]
#define ADDR_OFFSET_BAT1_STATE 17 // \param Battery 1 State [0-65535]
#define ADDR_OFFSET_BAT1_VOLTAGE 18 // \param Battery 2 Voltage [0-65535]
#define ADDR_OFFSET_BAT1_TEMP 19 // \param Battery 1 Temperature [0-65535]
#define ADDR_OFFSET_BAT1_CYCLE 20 // \param Battery 1 Cycle Count since last mode change [0-65535]
#define ADDR_OFFSET_BAT1_RATE_10s 21 // \param Battery 1 "Rate of Charge/Discharge" over 5s [0-65535]
#define ADDR_OFFSET_EMPTY_1 22 // \param nan [0-65535]
#define ADDR_OFFSET_EMPTY_2 23 // \param nan [0-65535]
#define ADDR_OFFSET_DischargeCurrent 24 // \param Discharge Current [0-65535]
#define ADDR_OFFSET_BAT2_STATE 25 // \param Battery 2 State [0-65535]
#define ADDR_OFFSET_BAT2_VOLTAGE 26 // \param Battery 2 Voltage [0-65535]
#define ADDR_OFFSET_BAT2_TEMP 27 // \param Battery 2 Temperature [0-65535]
#define ADDR_OFFSET_BAT2_CYCLE 28 // \param Battery 2 Cycle Count since last mode change [0-65535]
#define ADDR_OFFSET_BAT2_RATE_10s 29 // \param Battery 2 "Rate of Charge/Discharge" over 5s [0-65535]
#define ADDR_OFFSET_EMPTY_3 30 // \param nan [0-65535]
#define ADDR_OFFSET_EMPTY_4 31 // \param nan [0-65535]
#define ADDR_OFFSET_DIAG_CHARGE_DURATION 32 // \param Duration of the Charge cycle in mode Diagnostic [0-65535]
#define ADDR_OFFSET_DIAG_DISCHARGE_DURATION 33 // \param Duration of the Charge cycle in mode Diagnostic [0-3]
#define ADDR_OFFSET_BAT_1_Disable 34 // \param Disable Battery 1 (no charge or discharge) [0-3]
#define ADDR_OFFSET_BAT_1_Max 35 // \param Maximum Voltage to reach while charging nan
#define ADDR_OFFSET_BAT_1_Min 36 // \param Minimum Voltage to reach while discharging nan
#define ADDR_OFFSET_BAT_2_Disable 37 // \param Disable Battery 2 (no charge or discharge) nan
#define ADDR_OFFSET_BAT_2_Max 38 // \param Maximum Voltage to reach while charging nan
#define ADDR_OFFSET_BAT_2_Min 39 // \param Minimum Voltage to reach while discharging nan
#define ADDR_OFFSET_TEST25 40 // \param SPARE nan
#define ADDR_OFFSET_TEST26 41 // \param SPARE nan
#define ADDR_OFFSET_TEST27 42 // \param SPARE nan
#define ADDR_OFFSET_TEST28 43 // \param SPARE nan
#define ADDR_OFFSET_TEST29 44 // \param SPARE nan
#define ADDR_OFFSET_TEST30 45 // \param SPARE nan
#define ADDR_OFFSET_TEST31 46 // \param SPARE nan
#define ADDR_OFFSET_TEST32 47 // \param SPARE nan
#define ADDR_OFFSET_TEST33 48 // \param SPARE nan
#define ADDR_OFFSET_TEST34 49 // \param SPARE nan
#define ADDR_OFFSET_TEST35 50 // \param SPARE nan
#define ADDR_OFFSET_TEST36 51 // \param SPARE nan
#define ADDR_OFFSET_TEST37 52 // \param SPARE nan
#define ADDR_OFFSET_TEST38 53 // \param SPARE nan
#define ADDR_OFFSET_TEST39 54 // \param SPARE nan
#define ADDR_OFFSET_TEST40 55 // \param SPARE nan
#define ADDR_OFFSET_ERROR_uC 56 // \param nan nan
#define ADDR_OFFSET_ERROR_SpikCU 57 // \param Dernier code d'erreur produit nan
#define ADDR_OFFSET_ERROR_Alim 58 // \param Fault_uC(3) | Fault_3V3S(2) | Fault_5VS(1) | Fault_Vbatt(0) nan
#define ADDR_OFFSET_STATUS_SPARE1 59 // \param nan nan
#define ADDR_OFFSET_STATUS_SPARE2 60 // \param nan nan
#define ADDR_OFFSET_STATUS_SPARE3 61 // \param nan nan
#define ADDR_OFFSET_STATUS_SPARE4 62 // \param nan nan
#define ADDR_OFFSET_STATUS_SPARE5 63 // \param nan nan

/**DEFAULT_VALUE**/

#define DEFAULT_CU_ID 0xA1BA
#define DEFAULT_VERSION 22
#define DEFAULT_MODE 0x0000
#define DEFAULT_MODE_SUIVANT 0x0000
#define DEFAULT_TIME_CCSDS_100MS 0x0000
#define DEFAULT_TIME_CCSDS_MIN 0x0000
#define DEFAULT_TIME_CCSDS_DAYS 0x0000
#define DEFAULT_CTRL_uC 0x0000
#define DEFAULT_NB_BYTE_DP_HK 0x0000
#define DEFAULT_NB_BYTE_DP_RAW 0x0000
#define DEFAULT_RESERVE_DP_3 0x0000
#define DEFAULT_RESERVE_DP_4 0x0000
#define DEFAULT_RESERVE_DP_5 0x0000
#define DEFAULT_RESERVE_DP_6 0x0000
#define DEFAULT_RESERVE_DP_7 0x0000
#define DEFAULT_RESERVE_DP_8 0x0000
#define DEFAULT_ChargeCurrent 0x0000
#define DEFAULT_BAT1_STATE 0x0000
#define DEFAULT_BAT1_VOLTAGE 0x0000
#define DEFAULT_BAT1_TEMP 0x0000
#define DEFAULT_BAT1_CYCLE 0x0000
#define DEFAULT_BAT1_RATE_10s 0x0000
#define DEFAULT_EMPTY_1 0x0000
#define DEFAULT_EMPTY_2 0x0000
#define DEFAULT_DischargeCurrent 0x0000
#define DEFAULT_BAT2_STATE 0x0000
#define DEFAULT_BAT2_VOLTAGE 0x0000
#define DEFAULT_BAT2_TEMP 0x0000
#define DEFAULT_BAT2_CYCLE 0x0001
#define DEFAULT_BAT2_RATE_10s 0x0000
#define DEFAULT_EMPTY_3 0x0000
#define DEFAULT_EMPTY_4 0x0000
#define DEFAULT_DIAG_CHARGE_DURATION 10000
#define DEFAULT_DIAG_DISCHARGE_DURATION 1000
#define DEFAULT_BAT_1_Disable 0x0000
#define DEFAULT_BAT_1_Max 2500
#define DEFAULT_BAT_1_Min 2200
#define DEFAULT_BAT_2_Disable 0x0000
#define DEFAULT_BAT_2_Max 2500
#define DEFAULT_BAT_2_Min 2200
#define DEFAULT_TEST25 0x0000
#define DEFAULT_TEST26 0x0000
#define DEFAULT_TEST27 0x0000
#define DEFAULT_TEST28 0x0000
#define DEFAULT_TEST29 0x0000
#define DEFAULT_TEST30 0x0000
#define DEFAULT_TEST31 0x0000
#define DEFAULT_TEST32 0x0000
#define DEFAULT_TEST33 0x0000
#define DEFAULT_TEST34 0x0000
#define DEFAULT_TEST35 0x0000
#define DEFAULT_TEST36 0x0000
#define DEFAULT_TEST37 0x0000
#define DEFAULT_TEST38 0x0000
#define DEFAULT_TEST39 0x0000
#define DEFAULT_TEST40 0x0000
#define DEFAULT_ERROR_uC 0xFFFF
#define DEFAULT_ERROR_SpikCU 0xFFFF
#define DEFAULT_ERROR_Alim 0xFFFF
#define DEFAULT_STATUS_SPARE1 0xAAAA
#define DEFAULT_STATUS_SPARE2 0xBBBB
#define DEFAULT_STATUS_SPARE3 0xCCCC
#define DEFAULT_STATUS_SPARE4 0xDDDD
#define DEFAULT_STATUS_SPARE5 0xEEEE

/**Readable/Writable**/

#define CHMOD_CU_ID 0 
#define CHMOD_VERSION 0 
#define CHMOD_MODE 0 
#define CHMOD_MODE_SUIVANT 1 
#define CHMOD_TIME_CCSDS_100MS 1 
#define CHMOD_TIME_CCSDS_MIN 1 
#define CHMOD_TIME_CCSDS_DAYS 1 
#define CHMOD_CTRL_uC 1 
#define CHMOD_NB_BYTE_DP_HK 0 
#define CHMOD_NB_BYTE_DP_RAW 0 
#define CHMOD_RESERVE_DP_3 0 
#define CHMOD_RESERVE_DP_4 0 
#define CHMOD_RESERVE_DP_5 0 
#define CHMOD_RESERVE_DP_6 0 
#define CHMOD_RESERVE_DP_7 0 
#define CHMOD_RESERVE_DP_8 0 
#define CHMOD_ChargeCurrent 0 
#define CHMOD_BAT1_STATE 0 
#define CHMOD_BAT1_VOLTAGE 0 
#define CHMOD_BAT1_TEMP 0 
#define CHMOD_BAT1_CYCLE 0 
#define CHMOD_BAT1_RATE_10s 0 
#define CHMOD_EMPTY_1 #define CHMOD_EMPTY_2 1 
#define CHMOD_DischargeCurrent 0 
#define CHMOD_BAT2_STATE 0 
#define CHMOD_BAT2_VOLTAGE 0 
#define CHMOD_BAT2_TEMP 0 
#define CHMOD_BAT2_CYCLE 0 
#define CHMOD_BAT2_RATE_10s 0 
#define CHMOD_EMPTY_3 #define CHMOD_EMPTY_4 1 
#define CHMOD_DIAG_CHARGE_DURATION 1 
#define CHMOD_DIAG_DISCHARGE_DURATION 1 
#define CHMOD_BAT_1_Disable 1 
#define CHMOD_BAT_1_Max 1 
#define CHMOD_BAT_1_Min 1 
#define CHMOD_BAT_2_Disable 1 
#define CHMOD_BAT_2_Max 1 
#define CHMOD_BAT_2_Min 1 
#define CHMOD_TEST25 1 
#define CHMOD_TEST26 1 
#define CHMOD_TEST27 1 
#define CHMOD_TEST28 1 
#define CHMOD_TEST29 1 
#define CHMOD_TEST30 1 
#define CHMOD_TEST31 1 
#define CHMOD_TEST32 1 
#define CHMOD_TEST33 1 
#define CHMOD_TEST34 1 
#define CHMOD_TEST35 1 
#define CHMOD_TEST36 1 
#define CHMOD_TEST37 1 
#define CHMOD_TEST38 1 
#define CHMOD_TEST39 1 
#define CHMOD_TEST40 1 
#define CHMOD_ERROR_uC 0 
#define CHMOD_ERROR_SpikCU 0 
#define CHMOD_ERROR_Alim 0 
#define CHMOD_STATUS_SPARE1 0 
#define CHMOD_STATUS_SPARE2 0 
#define CHMOD_STATUS_SPARE3 0 
#define CHMOD_STATUS_SPARE4 0 
#define CHMOD_STATUS_SPARE5 0 

/**************PRACTICITY*********/

#define CU_ID ADDR_OFFSET_CU_ID
#define VERSION ADDR_OFFSET_VERSION
#define MODE ADDR_OFFSET_MODE
#define MODE_SUIVANT ADDR_OFFSET_MODE_SUIVANT
#define TIME_CCSDS_100MS ADDR_OFFSET_TIME_CCSDS_100MS
#define TIME_CCSDS_MIN ADDR_OFFSET_TIME_CCSDS_MIN
#define TIME_CCSDS_DAYS ADDR_OFFSET_TIME_CCSDS_DAYS
#define CTRL_uC ADDR_OFFSET_CTRL_uC
#define NB_BYTE_DP_HK ADDR_OFFSET_NB_BYTE_DP_HK
#define NB_BYTE_DP_RAW ADDR_OFFSET_NB_BYTE_DP_RAW
#define RESERVE_DP_3 ADDR_OFFSET_RESERVE_DP_3
#define RESERVE_DP_4 ADDR_OFFSET_RESERVE_DP_4
#define RESERVE_DP_5 ADDR_OFFSET_RESERVE_DP_5
#define RESERVE_DP_6 ADDR_OFFSET_RESERVE_DP_6
#define RESERVE_DP_7 ADDR_OFFSET_RESERVE_DP_7
#define RESERVE_DP_8 ADDR_OFFSET_RESERVE_DP_8
#define ChargeCurrent ADDR_OFFSET_ChargeCurrent
#define BAT1_STATE ADDR_OFFSET_BAT1_STATE
#define BAT1_VOLTAGE ADDR_OFFSET_BAT1_VOLTAGE
#define BAT1_TEMP ADDR_OFFSET_BAT1_TEMP
#define BAT1_CYCLE ADDR_OFFSET_BAT1_CYCLE
#define BAT1_RATE_10s ADDR_OFFSET_BAT1_RATE_10s
#define EMPTY_1 ADDR_OFFSET_EMPTY_1
#define EMPTY_2 ADDR_OFFSET_EMPTY_2
#define DischargeCurrent ADDR_OFFSET_DischargeCurrent
#define BAT2_STATE ADDR_OFFSET_BAT2_STATE
#define BAT2_VOLTAGE ADDR_OFFSET_BAT2_VOLTAGE
#define BAT2_TEMP ADDR_OFFSET_BAT2_TEMP
#define BAT2_CYCLE ADDR_OFFSET_BAT2_CYCLE
#define BAT2_RATE_10s ADDR_OFFSET_BAT2_RATE_10s
#define EMPTY_3 ADDR_OFFSET_EMPTY_3
#define EMPTY_4 ADDR_OFFSET_EMPTY_4
#define DIAG_CHARGE_DURATION ADDR_OFFSET_DIAG_CHARGE_DURATION
#define DIAG_DISCHARGE_DURATION ADDR_OFFSET_DIAG_DISCHARGE_DURATION
#define BAT_1_Disable ADDR_OFFSET_BAT_1_Disable
#define BAT_1_Max ADDR_OFFSET_BAT_1_Max
#define BAT_1_Min ADDR_OFFSET_BAT_1_Min
#define BAT_2_Disable ADDR_OFFSET_BAT_2_Disable
#define BAT_2_Max ADDR_OFFSET_BAT_2_Max
#define BAT_2_Min ADDR_OFFSET_BAT_2_Min
#define TEST25 ADDR_OFFSET_TEST25
#define TEST26 ADDR_OFFSET_TEST26
#define TEST27 ADDR_OFFSET_TEST27
#define TEST28 ADDR_OFFSET_TEST28
#define TEST29 ADDR_OFFSET_TEST29
#define TEST30 ADDR_OFFSET_TEST30
#define TEST31 ADDR_OFFSET_TEST31
#define TEST32 ADDR_OFFSET_TEST32
#define TEST33 ADDR_OFFSET_TEST33
#define TEST34 ADDR_OFFSET_TEST34
#define TEST35 ADDR_OFFSET_TEST35
#define TEST36 ADDR_OFFSET_TEST36
#define TEST37 ADDR_OFFSET_TEST37
#define TEST38 ADDR_OFFSET_TEST38
#define TEST39 ADDR_OFFSET_TEST39
#define TEST40 ADDR_OFFSET_TEST40
#define ERROR_uC ADDR_OFFSET_ERROR_uC
#define ERROR_SpikCU ADDR_OFFSET_ERROR_SpikCU
#define ERROR_Alim ADDR_OFFSET_ERROR_Alim
#define STATUS_SPARE1 ADDR_OFFSET_STATUS_SPARE1
#define STATUS_SPARE2 ADDR_OFFSET_STATUS_SPARE2
#define STATUS_SPARE3 ADDR_OFFSET_STATUS_SPARE3
#define STATUS_SPARE4 ADDR_OFFSET_STATUS_SPARE4
#define STATUS_SPARE5 ADDR_OFFSET_STATUS_SPARE5