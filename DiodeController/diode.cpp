#include "diode.h"
#include "define.h"

Diode::Diode(){
  state = false;
  current_color = blue;
  rate = 0;
}

void Diode::setState(bool s){
  state = s;
}

bool Diode::getState(){
  return state;
}

void Diode::setRate(int r){
  rate = MIN(MAX(0, r), 5);
}

int Diode::getRate(){
  return rate;
}

void Diode::setColor(Diode::color c) {
  current_color = c;
}

int Diode::getColor() {
  return current_color;
}