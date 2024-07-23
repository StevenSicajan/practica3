
#include <Wire.h>             
#include <Adafruit_GFX.h>     
#include <Adafruit_SSD1306.h> 
 
#define widht_oled    128       
#define height_oled   64        
#define pot_pin       A0        
 
Adafruit_SSD1306 oled_display(widht_oled,height_oled,&Wire, -1);
 
unsigned int adc_valor;
 
void setup()
{
 
 Serial.begin(9600);  
 delay(100);          
 pinMode(A0, INPUT);

 
 if(!oled_display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
 {
  Serial.println("No puedo comunicarme con la pantalla oled");
  Serial.println("Favor de revisar conexiones o alimentacion");
  while(1);   
 }
 
 oled_display.setTextSize(4);
 oled_display.setTextColor(SSD1306_WHITE);
 //Coloco el cursor en una posicion especifica
 oled_display.setCursor(0, 0);
}

void loop()
{
 
  oled_display.setTextSize(1);
 oled_display.setTextColor(SSD1306_WHITE);
 oled_display.setCursor(0, 0);
 oled_display.println("Valor del ADC");
 oled_display.display();
  adc_valor = analogRead(A0);       
  Serial.print("El valor del ADC es de: ");
  Serial.println(adc_valor);
  oled_display.setTextSize(3);
  oled_display.setTextColor(SSD1306_WHITE);
  oled_display.setCursor(0,12);
  oled_display.println(adc_valor);
  oled_display.display();
  delay(150);
  oled_display.clearDisplay();
}
 
