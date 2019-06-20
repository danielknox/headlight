/*
  L298N.cpp - Libreria per gestire i movimenti di un motore DC con il modulo L298N
  Autore:   Andrea Lombardo
  Sito web: http://www.lombardoandrea.com  
*/

#include "headlight.h"

typedef void (*CallBackFunction) ();

Headlight::Headlight(uint8_t pinIN1, uint8_t pinIN2){
  _pinIN1 = pinIN1;
  _pinIN2 = pinIN2;
  _isOn = false;
  _canBeOn = true;
  _lastMs = 0;

  pinMode(_pinIN1, OUTPUT);
  pinMode(_pinIN2, OUTPUT);
}

void Headlight::mainbeam(){
  digitalWrite(_pinIN1, HIGH);
  digitalWrite(_pinIN2, LOW);
  _isOn = true;
}


void Headlight::mainbeamFor(unsigned long delay, CallBackFunction callback){
  if ((_lastMs == 0) && _canBeOn) {
    _lastMs = millis();
    this->mainbeam();
  }

  if (((millis() - _lastMs) > delay) && _canBeOn) {
    this->off();
    _lastMs = 0;
    _canBeOn = false;
    callback();
  }

}

void Headlight::mainbeamFor(unsigned long delay){
  this->mainbeamFor(delay, fakeCallback);
}


void Headlight::dipped(){
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, HIGH);
  _isOn = true;
}

void Headlight::dippedFor(unsigned long delay, CallBackFunction callback){

  if ((_lastMs == 0) && _canBeOn) {
    _lastMs = millis();
    this->dipped();
  }

  if (((millis() - _lastMs) > delay) && _canBeOn) {
    this->off();
    _lastMs = 0;
    _canBeOn = false;
    callback();
  }

}

void Headlight::dippedFor(unsigned long delay){
  this->dippedFor(delay, fakeCallback);
}

void Headlight::on(uint8_t mode){
  switch(mode){
    case DIPPED:
      this->dipped();
    break;
    case MAINBEAM:
      this->mainbeam();
    break;
  }
}

void Headlight::off(){
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, LOW);  
  _isOn = false;
}

void Headlight::reset(){
  _canBeOn = true;
}

boolean Headlight::isOn(){
  return _isOn;
}

void Headlight::fakeCallback(){

}