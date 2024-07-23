#include <LedControl.h>
 
#define dataPin0   12
#define dataClock0 11
#define dataLoad0  10
 
#define pot_pin    A0
 
unsigned int adc_valor;
LedControl matrix_unidades = LedControl(dataPin0, dataClock0, dataLoad0, 1);
 
byte pacman_open[8] =
{
  B00111000,
  B01000100,
  B10001000,
  B10010000,
  B10001000,
  B01000100,
  B00111000,
  B00000000
};
 
byte pacman_close[8] =
{
  B00111000,
  B01000100,
  B10000010,
  B10011110,
  B10000010,
  B01000100,
  B00111000,
  B00000000
};
 
unsigned long update_delay = 850;
 
void print_pacman_open(void)
{
  for (int i = 0; i < 8; i++)
  {
    matrix_unidades.setRow(0, i, pacman_open[i]);
  }
}
 
void print_pacman_close(void)
{
  for (int i = 0; i < 8; i++)
  {
    matrix_unidades.setRow(0, i, pacman_close[i]);
  }
}
 
void setup()
{
  Serial.begin(9600);
  matrix_unidades.shutdown(0, false);
  matrix_unidades.setIntensity(0, 30);
  matrix_unidades.clearDisplay(0);
  pinMode(pot_pin, INPUT);
}
 
void loop()
{
  adc_valor = analogRead(pot_pin);
  print_pacman_open();
  delay(adc_valor);
  print_pacman_close();
  delay(adc_valor);
 
  Serial.print("El valor del ADC es: ");
  Serial.println(adc_valor);
}