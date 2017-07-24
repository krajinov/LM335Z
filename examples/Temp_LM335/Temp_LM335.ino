#include <LM335Z.h>

LM335Z mTemp(5.0, A0);//supply volts, analog pin

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.print(mTemp.measureV());
  Serial.println(" volts");
  Serial.println("Temperatures: ");
  Serial.print("Kelvin: ");
  Serial.println(mTemp.measureK());
  Serial.print("Fahrenheit: ");
  Serial.println(mTemp.measureF());
  Serial.print("Celsius: ");
  Serial.println(mTemp.measureC());
  Serial.print("Rankine: ");
  Serial.println(mTemp.measureRankine());
  delay(1000);
}
