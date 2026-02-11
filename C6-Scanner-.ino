#include <WiFi.h>

void setup(){

  Serial.begin(115200);
  //setting the baud rate 

  WiFi.mode(  WIFI_STA);
  // setting the Board as the Receiver 

  WiFi.disconnect();
  //to disconect from any previous networks if there were

  delay(100);
  Serial.printf("RF Intializing....\n");

}

void loop(){

int n= WiFi.scanNetworks() ;
// to tell the board to scan the 2.4 Ghz channel and count the "n" it found
int i;
for(i=0;i<n;i++){
  Serial.printf("The RSSI is %d Dbm\n ", WiFi.RSSI(i));
  Serial.printf("SSID is %s\n", WiFi.SSID(i).c_str());
  Serial.printf("Channel is %d\n",WiFi.channel(i));
// printing the RSSI , SSID and Channel number 
}

WiFi.scanDelete();
delay(10000);
}
