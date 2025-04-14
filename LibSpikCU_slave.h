#ifndef LIBSPIKCU_SLAVE_H
#define LIBSPIKCU_SLAVE_H
#include <cstdint>

inline uint16_t HK[64] = {0};
inline uint16_t params[64] = {0};

inline void write_HK(int index, uint16_t value) {
    HK[index] = value;
}

inline void write_param(int index, uint16_t value) {
    params[index] = value;
}

inline uint16_t read_param(uint8_t reg_offset) {
    return params[reg_offset];
}
#endif
