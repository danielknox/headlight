#ifndef headlight_h
#define headlight_h

#include "Arduino.h"


typedef void (*CallBackFunction) ();

class Headlight{
   public:
      typedef enum
      {
            MAINBEAM  = 0,
            DIPPED = 1
      } mode;
      Headlight(uint8_t pinIN1, uint8_t pinIN2);
      void mainbeam();
      void mainbeamFor(unsigned long delay, CallBackFunction callback);
      void mainbeamFor(unsigned long delay);
      void dipped();
      void dippedFor(unsigned long delay, CallBackFunction callback);
      void dippedFor(unsigned long delay);
      void on(uint8_t mode);
      void off();
      void reset();
      boolean isOn();

   private:
      byte _pinIN1;
      byte _pinIN2;
      unsigned long _lastMs;
      boolean _canBeOn;
      boolean _isOn;
      static void fakeCallback();
};

#endif