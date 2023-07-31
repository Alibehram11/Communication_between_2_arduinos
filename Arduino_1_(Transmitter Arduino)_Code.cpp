#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN pins
const byte address[6] = "00001"; // Verici ve Alıcı arasında aynı olmalı

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW); // Veri iletim gücünü düşük olarak ayarla
}

void loop() {
  String message = "Merhaba, Arduino 2!"; // Gönderilecek mesaj
  radio.write(&message, sizeof(message)); // Mesajı kablosuz olarak gönder
  Serial.println("Mesaj gönderildi: " + message);
  delay(1000); // 1 saniye bekle
}
