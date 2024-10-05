#include "DHT.h"

#define DHTPIN 2     // Pin donde está conectado el sensor DHT22
#define DHTTYPE DHT22   // DHT 22 (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Espera 2 segundos entre lecturas

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Verifica si alguna lectura falló
  if (isnan(h) || isnan(t)) {
    Serial.println("Error en la lectura del sensor!");
    return;
  }

  // Envía los valores de humedad y temperatura con coma entre ellos, y salto de línea al final
  Serial.print(h);
  Serial.print(",");
  Serial.println(t);
}
