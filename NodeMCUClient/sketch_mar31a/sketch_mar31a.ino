
#include <SocketIOClient.h>
#include <ESP8266WiFi.h>

#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>

#include "Ethernet.h"
#include "SPI.h"
extern "C"
{ 
  #include "user_interface.h"
 }
const byte RX =3;
const byte TX =1;

//SoftwareSerial mySerial(3, 1);

//SerialCommand sCmd(mySerial);
SocketIOClient client;
const char* ssid ="LynkCherry";
const char* pass ="lamgicomatkhau";
char host[] ="192.168.153.101";   //Dịa chỉ IP dịch vụ, hãy thay đổi nó theo địa chỉ IP Socket serv
int port = 3000;    //Cổng dịch vụ socket server do chúng ta tạo!
  
  
  //từ khóa extern: dùng để #include các biến toàn cục ở một số thư viện khác. Trong thư viện SocketIOClient có hai biến toàn cục
// mà chúng ta cần quan tâm đó là
// RID: Tên hàm (tên sự kiện
// Rfull: Danh sách biến (được đóng gói lại là chuối JSON)

extern String RID;
extern String Rfull;


void setup() {
  Serial.begin(250000);
//  mySerial.begin(57600);
  delay(10);  

  Serial.print("Ket Noi Vao Mang ");
  Serial.print(ssid );
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED) // Cho Ket Noi
  {
    delay (200);
  Serial.print('.');  
  }
  Serial.println();
    Serial.println("Da Ket Noi Vao Mang");
    Serial.println(ssid);
    Serial.println("Dia Chi Ip Cua Client ESP 8266 La :");
    Serial.println(WiFi.localIP());
    
    if(!client.connect(host,port))
    {
      Serial.println(F("Ket Noi That Bai"));
      return;
      }

     else
     
     {
      Serial.println("connect to socket success! ");
      client.send("espSend","tt","connet");
      }
     
     
   
  }

void batsukien()
{

// dua cho arduino
    if(client.monitor()){
      
  // dua ra COM
  
//  Serial.println(RID);
  Serial.print(' ');
    Serial.println(Rfull);
  //kiem tra ram trong
    }

  
  if(!client.connected())
  {
    client.reconnect(host,port);
  }
  
}

 // void defautCommand(String command)
 // {
//client.send(command,(String) json);

  // Serial.println(json);
  // }
  
void loop()
{
  batsukien();
}
