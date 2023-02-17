/**
 * \file hcsr04.hpp
 * \brief Archivo de cabecera para el sensor de distancia ultrasonico HC-SR04
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#ifndef HCSR04_HPP
#define HCSR04_HPP

/**
 * \brief Clase para instanciar un sensor. Incluye funciones
 * que permiten configurar sus pines y obtener la medición de distancia.
 */
class HC_SR04
{
public:
    /**
     * \brief Constructor inicial.
     */
    HC_SR04();

    /**
     * \brief Función para configurar el sensor.
     * \param triggerPin: GPIO al que se conecta el pin TRIGGER del sensor.
     * \param echoPin: GPIO al que se conecta el pin ECHO del sensor.
     * \param pulseTimeout: Tiempo de espera máximo para realizar la medición.
     */
    void setup(int triggerPin, int echoPin, unsigned long pulseTimeout = 25000);

    /**
     * \brief Función para medir la distancia con el sensor.
     * \param NA: Sin párametros.
     * \returns Distancia [cm].
     */
    float getDistance();

private:
    int _triggerPin;   // GPIO al que se conecta el pin TRIGGER del sensor.
    int _echoPin;      // GPIO al que se conecta el pin ECHO del sensor.
    int _pulseTimeout; // Tiempo de espera máximo para realizar la medición.
};

#endif
