#include <SPI.h>
#include <Ethernet.h>

// MAC address for shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 137, 177);
EthernetServer server(80); // Using port 80

const int pumpR = 5 ; //pump 1 right 
const int pumpL = 9 ; //pump 2 left
const int skimmer =  3; // skimmer pin3
const int pumpV = 6 ; //pump 3 vertical

void setup() {
  delay(3000);
pinMode(pumpR,OUTPUT) ;  //Logic pins are also set as output
pinMode(pumpL,OUTPUT) ; 
pinMode(skimmer,OUTPUT) ;  
pinMode(pumpV,OUTPUT) ;
digitalWrite(skimmer, HIGH);
digitalWrite(pumpR, LOW);
digitalWrite(pumpL, LOW);
digitalWrite(pumpV, LOW);
  Ethernet.begin(mac,ip); // Start the Ethernet shield
  server.begin();
  Serial.begin(9600); // Start serial communication
  Serial.println("Server address:"); // Print server address
  // (Arduino shield)
  Serial.println(Ethernet.localIP());
}
void loop() {
  EthernetClient client = server.available();
  if (client) {
    boolean currentLineIsBlank = true;
    String buffer = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read(); // Read from the Ethernet shield
        buffer += c; // Add character to string buffer
        // Client sent request, now waiting for response
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK"); // HTTP response
          client.println("Content-Type: text/html");
          client.println(); // HTML code
          client.print("<center><br><h1>Internet Controlled RO </h1><br><br><br><FORM>");
          client.print("<P> <INPUT type=\"submit\" name=\"motion\" value=\"MOTION_ON\">");
          client.print("<P> <INPUT type=\"submit\" name=\"motion\" value=\"MOTION_OFF\">");

          client.print("<P> <INPUT type=\"submit\" name=\"suction\" value=\"SUCTION_ON\">");
          client.print("<P> <INPUT type=\"submit\" name=\"suction\" value=\"SUCTION_OFF\">");

          client.print("<P> <INPUT type=\"submit\" name=\"skimmer\" value=\"SKIMMER_ON\">");
          client.print("<P> <INPUT type=\"submit\" name=\"skimmer\" value=\"SKIMMER_OFF\">");

          client.print("<P> <INPUT type=\"submit\" name=\"right\" value=\"RIGHT_ON\">");
          client.print("<P> <INPUT type=\"submit\" name=\"right\" value=\"RIGHT_OFF\">");

          client.print("<P> <INPUT type=\"submit\" name=\"left\" value=\"LEFT_ON\">");
          client.print("<P> <INPUT type=\"submit\" name=\"left\" value=\"LEFT_OFF\">");
          
          client.print("</FORM></center>");
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
          buffer = "";
        }
        else if (c == '\r') { // Command from webpage
          // Did the on button get pressed
          if (buffer.indexOf("GET /?motion=MOTION_ON") >= 0){
            digitalWrite(pumpR, HIGH);
            digitalWrite(pumpL, HIGH);
          }
          // Did the off button get pressed
          if (buffer.indexOf("GET /?motion=MOTION_OFF") >= 0){
            digitalWrite(pumpR, LOW);
            digitalWrite(pumpL, LOW);
          }
        if (buffer.indexOf("GET /?suction=SUCTION_ON") >= 0){
            
            digitalWrite(pumpV, HIGH);
          }
          // Did the off button get pressed
          if (buffer.indexOf("GET /?suction=SUCTION_OFF") >= 0){
            
            digitalWrite(pumpV, LOW);
          }
        if (buffer.indexOf("GET /?skimmer=SKIMMER_ON") >= 0){
            digitalWrite(skimmer, LOW);
            
          }
          // Did the off button get pressed
          if (buffer.indexOf("GET /?skimmer=SKIMMER_OFF") >= 0){
            digitalWrite(skimmer, HIGH);
            
          }
          if (buffer.indexOf("GET /?right=RIGHT_ON") >= 0){
            
            digitalWrite(pumpR, HIGH);
          }
          // Did the off button get pressed
          if (buffer.indexOf("GET /?right=RIGHT_OFF") >= 0){
            
            digitalWrite(pumpR, LOW);
          }
          if (buffer.indexOf("GET /?left=LEFT_ON") >= 0){
            
            digitalWrite(pumpL, HIGH);
          }
          // Did the off button get pressed
          if (buffer.indexOf("GET /?left=LEFT_OFF") >= 0){
            
            digitalWrite(pumpL, LOW);
          }
        }
        else {
          currentLineIsBlank = false;
        }
      }
    }
    client.stop(); // End server
  }
}
