/**
 * \file main.hpp
 * \brief Ejemplo para realizar los movimientos básicos de un robot vehicular motorizado
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#include <Arduino.h>
#include "hcsr04.hpp"

// ---Constantes---
// Pines
const uint8_t echoPin = 35;    // GPIO al que se conecta el pin ECHO del sensor.
const uint8_t triggerPin = 32; // GPIO al que se conecta el pin TRIGGER del sensor.
// Tiempos
const uint16_t pulseTimeout = 5 * 1000; // µSegundos antes de abortar la recepción
// ---Variables---
float distance = 0.0;

// Creación de un objeto de la clase HC_SR04
HC_SR04 ultrasonico;

void setup()
{
  Serial.begin(115200); // Inicializar la comunicación serial a 115200 baudios.
  ultrasonico.setup(triggerPin, echoPin, pulseTimeout);
}

void loop()
{
  distance = ultrasonico.getDistance();
  Serial.print(String(distance) + " cm");
  delay(500);
}
