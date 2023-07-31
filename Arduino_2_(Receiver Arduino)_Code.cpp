#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN pins
const byte address[6] = "00001"; // Verici ve Alıcı arasında aynı olmalı

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_LOW); // Veri alım gücünü düşük olarak ayarla
  radio.startListening(); // Verileri dinleme moduna geç
}

void loop() {
  if (radio.available()) {
    String message = ""; // Alınan mesajı saklamak için boş bir dize oluştur
    radio.read(&message, sizeof(message)); // Kablosuz mesajı al
    Serial.println("Alınan mesaj: " + message);
  }
}
