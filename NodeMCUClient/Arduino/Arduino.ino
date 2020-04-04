

#include <ArduinoJson.h>
#include <SerialCommand.h>


int tb1=2;
int tb2=3;
int tb3=4;
int tb4=5;

String  val ="0" ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(250000);


//pinMode(tb1, OUTPUT);
//pinMode(tb2, OUTPUT);
//pinMode(tb3, OUTPUT);
//pinMode(tb4, OUTPUT);

//pinMode(tb1, LOW);
//pinMode(tb2, LOW);
//pinMode(tb3, LOW);
//pinMode(tb4, LOW);
/// digitalWrite(tb1, LOW);
//  digitalWrite(tb2, LOW);
 //  digitalWrite(tb3, LOW);
 //   digitalWrite(tb4, LOW);
  
}
char buf[100];
void kiemtra(){
//char *json = Serial.read();


//
    if(Serial.available())
    {
             bool LED1STT ;
             bool LED2STT;
            val = Serial.readString();
            val.toCharArray(buf,val.length());
           //  Serial.println(val);
        

                  StaticJsonBuffer<200> jb;
                JsonObject& root = jb.parseObject(buf);
                if(!root.success()) {
                 Serial.println("parseObject() failed");
                  return false;
                }
                else{
                  
                    LED1STT = root["LED1"];               
                    LED2STT = root["LED2"];
                    
              
                    if(LED1STT){
                       Serial.println("Bong 1 bat");
                        pinMode(tb1, HIGH);
                      }

                      if(!LED1STT) {
                      Serial.println("Bong 1 tat");
                        pinMode(tb1, LOW);
                      }
                      if(LED2STT){
                       Serial.println("Bong 2 bat");
                        pinMode(tb2, HIGH);
                      }
                      if(!LED2STT)
                     {
                      Serial.println("Bong 2 tat");
                        pinMode(tb2, LOW);
                      }

                    }
     }
}
//LOOP



  void loop()
{

kiemtra();
 
}


   
