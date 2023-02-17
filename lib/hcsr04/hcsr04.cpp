/**
 * \file hcsr04.cpp
 * \brief Archivo de implementación para el sensor de distancia ultrasonico HC-SR04
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#include <Arduino.h>
#include "hcsr04.hpp"

const float soundSpeed = 0.03432;  // Velocidad del sonido [cm/us]
const uint8_t minDistRange = 2.3;  // Mínima distancia que puede medir el sensor [cm]
const uint16_t maxDistRange = 400; // Máxima distancia que puede medir el sensor [cm]

HC_SR04::HC_SR04() {}

void HC_SR04::setup(int triggerPin, int echoPin, unsigned long pulseTimeout)
{
    // Ajuste de variables
    _triggerPin = triggerPin;
    _echoPin = echoPin;
    _pulseTimeout = pulseTimeout;
    // Definición del pin de TRIGGER como salida.
    pinMode(_triggerPin, OUTPUT);
    // Definición del pin de ECHO como entrada.
    pinMode(_echoPin, INPUT);
}

float HC_SR04::getDistance()
{
    // Definición de variables
    float duration = 0;
    float distance = 0;
    // Limpieza del pin de Trigger
    digitalWrite(_triggerPin, 0);
    delayMicroseconds(2);
    // Establecer el pin de Trigger en un estado alto durante 10 us.
    digitalWrite(_triggerPin, 1);
    delayMicroseconds(10);
    // Apagar el pin de Trigger estableciendolo en un estado bajo.
    digitalWrite(_triggerPin, 0);
    // Lectura del pin Echo. Retorna el tiempo total [us] que le toma a la onda de sonido viajar
    // desde el sensor, rebotar en el objeto y volver hacia el sensor.
    duration = pulseIn(_echoPin, 1, _pulseTimeout);
    // Se calcula solo la duración del viaje de ida de la onda
    duration = duration / 2;
    // Si la onda de sonido retornó antes del tiempo de espera máximo definido en _pulseTimeout
    if (duration != 0)
    {
        // Se obtiene la distancia a partir de la velocidad del sonido aproximada para el lugar.
        distance = duration * soundSpeed;
        // Validación
        // Si el valor es menor que la mínima distancia que puede medir el sensor
        if (distance < minDistRange)
        {
            // La distancia es igual a la mínima distancia que puede medir el sensor
            distance = minDistRange;
        }
        // Si el valor es mayor que la máxima distancia que puede medir el sensor
        if (distance > maxDistRange)
        {
            // La distancia es igual a la máxima distancia que puede medir el sensor
            distance = maxDistRange;
        }
    }
    // Si no se recibe ninguna onda de sonido antes de _pulseTimeout, se supone que los objetos
    // estan muy lejos y por lo tanto se toma la distancia máxima que puede medir el sensor.
    else
    {
        distance = maxDistRange;
    }

    return distance;
}
