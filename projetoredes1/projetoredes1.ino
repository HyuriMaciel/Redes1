
#include <SPI.h>
#include <Ethernet.h>
#include <SHT1x.h>

int sensorldr = A3;

// pinos do sensor STH15
#define dataPin  A4
#define clockPin A5

SHT1x sht1x(dataPin, clockPin);

//Definicoes de IP, mascara de rede e gateway
byte mac[] = { 0x90, 0xA2, 0xD2, 0x0D, 0x32, 0x52 };
IPAddress ip(172, 20, 9, 229);          //Define o endereco IP
IPAddress gateway(172, 20, 7, 1);      //Define o gateway
IPAddress subnet(255, 255, 255, 0); //Define a máscara de rede

//Inicializa o servidor web na porta 80
EthernetServer server(80);

void setup()
{
  //Inicializa a interface de rede
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();

  Serial.begin(9600);
  
  Serial.println("projeto de redes 1");
  pinMode(sensorldr, OUTPUT);
 

}

void loop() {
  
  float estadoldr = analogRead(sensorldr);
  float  temp_1 =  sht1x.readTemperatureC();
  float  umit_1 =  sht1x.readHumidity();
  
  //Aguarda conexao do browser
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");

    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        if (c == 'n' && currentLineIsBlank) {

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 2"); //Recarrega a pagina a cada 2seg
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          //Configura o texto e imprime o titulo no browser
          client.print("<font color=#FF0000><b><u>");
          client.print("Envio de informacoes pela rede utilizando Arduino");
          client.print("</u></b></font>");
          client.println("<br />");
          client.println("<br />");
          //Mostra os dados do sensor de temperatura
          client.print("Temperatura : ");
          client.print("<b>");
          client.print(temp_1 );
          client.print(" C ");
          client.println("</b>");
          client.println("<br />");
          //Mostra os dados do sensor de umidade
          client.print("Umidade : ");
          client.print("<b>");
          client.print(umit_1 );
          client.println("</b>");
          client.println("<br />");
          //Mostra as informacoes lidas pelo sensor luminosidade
          client.print("Sensor de luminosidade : ");
          client.print("<b>");
          client.print(estadoldr);
          client.print(" cm");
          client.println("</b></html>");
          break;
        }
        if (c == 'n') {
           currentLineIsBlank = true;
        }
        else if (c != 'r') {
           currentLineIsBlank = false;
        }
      }
    }
    
    delay(1);
   
    client.stop();
  }
}
