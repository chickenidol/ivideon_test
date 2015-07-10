#ifndef DIODE_H
#define DIODE_H

class Diode {
  bool state;
  
  int rate;
  
public:
  enum color {
    undefined = 0,
    red = 1,
    green = 2,
    blue = 3
  };
  
  Diode();
  void setState(bool s);
  bool getState();
  
  void setRate(int r);
  int getRate();
  
  void setColor(Diode::color c);
  int getColor();
  
private:
  Diode::color current_color;
};
#endif // DIODE_H
