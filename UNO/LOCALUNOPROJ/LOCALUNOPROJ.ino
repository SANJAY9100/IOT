
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); 


int RED = 3;
int YELLOW = 4;
int GREEN = 5;
 
void setup() 
{
  Serial.begin(9600);  
  SPI.begin();     
  mfrc522.PCD_Init(); 

  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  
  Serial.begin(9600);
  
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW); 
}

void loop()
{

    Serial.println("Go !");       
    digitalWrite(GREEN,HIGH);
    delay(3000);
    digitalWrite(GREEN,LOW);
    
    
    Serial.println("Reduce Speed !");
    digitalWrite(YELLOW,HIGH);       
    delay(3000);
    digitalWrite(YELLOW,LOW);
    
    
  

    SPI.begin();
    Serial.println("Stop !");
    digitalWrite(RED, HIGH); 
    int z=0;
    while(z<30)
    {
      an();
      delay(100);
      z++;
    }
    SPI.end();
    digitalWrite(RED, LOW);

}

void an()
 {
 
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
  return;
  }
  
  //Show UID on serial monitor
  Serial.print("Vehicle No :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  
}
