/**
 * @file       TinyGsmGPS.tpp
 * @author     Volodymyr Shymanskyy
 * @license    LGPL-3.0
 * @copyright  Copyright (c) 2016 Volodymyr Shymanskyy
 * @date       Nov 2016
 */

#ifndef SRC_TINYGSMGPS_H_
#define SRC_TINYGSMGPS_H_

#include "TinyGsmCommon.h"

#define TINY_GSM_MODEM_HAS_GPS

template <class modemType>
class TinyGsmGPS {
 public:
  /*
   * GPS/GNSS/GLONASS location functions
   */
  bool enableGPS() {
    return thisModem().enableGPSImpl();
  }
  bool disableGPS() {
    return thisModem().disableGPSImpl();
  }
  String getGPSraw() {
    return thisModem().getGPSrawImpl();
  }
  bool getGPS(float* lat, float* lon, float* speed = 0, float* course = 0, float* alt = 0,
              int* vsat = 0, int* usat = 0, float* accuracy = 0, int* year = 0,
              int* month = 0, int* day = 0, int* hour = 0, int* minute = 0,
              int* second = 0) {
    return thisModem().getGPSImpl(lat, lon, speed, course, alt, vsat, usat, accuracy,
                                  year, month, day, hour, minute, second);
  }
  bool getGPSTime(int* year, int* month, int* day, int* hour, int* minute,
                  int* second) {
    float lat = 0;
    float lon = 0;
    return thisModem().getGPSImpl(&lat, &lon, 0, 0, 0, 0, 0, year, month, day,
                                  hour, minute, second);
  }

  /**
   * Set GNSS-Mode
   * 
   * @brief This command is used to configure GPS, GLONASS, BEIDOU and QZSS support
   * 
   * @param gps Enable GPS support (not for SIM7600, always enabled)
   * @param glonass Enable GLONASS support
   * @param beidou Enable BEIDOU support
   * @param galileo Enable GALILEO support
   * @param qzss Enable QZSS support (not for SIM7000/SIM7080)
   * @param dpo Enable Dynamic Power Optimization (not for SIM7000/SIM7080)
   * 
   * @return true if success, false if error
   */
  bool setGNSSMode(bool gps, bool glonass, bool beidou, bool galileo, bool qzss, bool dpo) {
    return thisModem().setGNSSModeImpl(gps, glonass, beidou, galileo, qzss, dpo);
  }

  /**
   * @brief Get status of GNSS-Mode and writes into bool pointers
   * 
   * @param gps GPS support enabled (SIM7600 = always enabled)
   * @param glonass GLONASS support enabled
   * @param beidou BEIDOU support enabled
   * @param galileo GALILEO support enabled
   * @param qzss QZSS support enabled (SIM7000/SIM7080 = false)
   * @param dpo Dynamic Power Optimization enabled (SIM7000/SIM7080 = false)
   * 
   * @return true if success, false if error 
   */
  bool getGNSSMode(bool* gps, bool* glonass, bool* beidou, bool* galileo, bool* qzss, bool* dpo) {
    return thisModem().getGNSSModeImpl(gps, glonass, beidou, galileo, qzss, dpo);
  }

  bool enableAGPS() {
    return thisModem().enableAGPSImpl();
  }

  bool disableAGPS() {
    return thisModem().disableAGPSImpl();
  }

  bool validateAGPS() {
    return thisModem().validateAGPSImpl();
  }
  
  bool updateAGPS(const char* apn, bool force=false) {
    return thisModem().updateAGPSImpl(apn, force);
  }
  

  /*
   * CRTP Helper
   */
 protected:
  inline const modemType& thisModem() const {
    return static_cast<const modemType&>(*this);
  }
  inline modemType& thisModem() {
    return static_cast<modemType&>(*this);
  }

  /*
   * GPS/GNSS/GLONASS location functions
   */

  bool    enableGPSImpl() TINY_GSM_ATTR_NOT_IMPLEMENTED;
  bool    disableGPSImpl() TINY_GSM_ATTR_NOT_IMPLEMENTED;
  String  getGPSrawImpl() TINY_GSM_ATTR_NOT_IMPLEMENTED;
  bool    getGPSImpl(float* lat, float* lon, float* speed = 0, float* course = 0, float* alt = 0,
                     int* vsat = 0, int* usat = 0, float* accuracy = 0,
                     int* year = 0, int* month = 0, int* day = 0, int* hour = 0,
                     int* minute = 0, int* second = 0 ) TINY_GSM_ATTR_NOT_IMPLEMENTED;
  bool setGNSSModeImpl(bool gps, bool glonass, bool beidou, bool galileo, bool qzss, bool dpo) TINY_GSM_ATTR_NOT_IMPLEMENTED;
  bool getGNSSModeImpl(bool* gps, bool* glonass, bool* beidou, bool* galileo, bool* qzss, bool* dpo) TINY_GSM_ATTR_NOT_IMPLEMENTED;
};


#endif  // SRC_TINYGSMGPS_H_
