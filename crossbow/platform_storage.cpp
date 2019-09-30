#include "platform_storage.h"

PlatformStorage::PlatformStorage(void) {
//#ifdef ARDUINO_ESP32_DEV
#if defined(ARDUINO_ESP32_DEV) || defined(ARDUINO_TTGO_LoRa32_V1)
    EEPROM.begin(64);
#endif
}

void PlatformStorage::commit(void) {
#if defined(ARDUINO_SAMD_FEATHER_M0) || defined(ARDUINO_ESP32_DEV) || defined(ARDUINO_TTGO_LoRa32_V1)

    EEPROM.commit();
#endif
}

void PlatformStorage::write(int address, uint8_t val) {
    EEPROM.write(address, val);
}

uint8_t PlatformStorage::read(int address) {
    return EEPROM.read(address);
}
