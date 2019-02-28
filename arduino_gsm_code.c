//Variable to store text message
String textMessage;
 const int red = 8;
 const int yellow = 9;
const int green = 10;
const int white = 7;

void setup()
{
  //set leds as OUTPUT
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(white,OUTPUT);

//by default the leds off
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(white,LOW);

  //initializing serial communication
Serial.begin(19200);

  //give time to GSM shield log on to network
  delay(200);
  //AT-Command to set SIM900 to sms mode
  Serial.print("AT+CMGF=1\r");
  delay(100);
}

void loop()
{
  if(Serial.available()>0)
  {
    textMessage = Serial.readString();
    textMessage.toUpperCase();
    delay(10);
  }
if(textMessage.indexOf("WON")>=0)
  {
    //Turn On BLUE LED
    digitalWrite(white,HIGH);
    textMessage="";
  }
if(textMessage.indexOf("WOFF")>=0)
  {
    //Turn Off BLUE LED
    digitalWrite(white,LOW);
    textMessage="";
  }
  if(textMessage.indexOf("RON")>=0)
  {
    //Turn On RED LED
    digitalWrite(red,HIGH);
    textMessage="";
  }
if(textMessage.indexOf("ROFF")>=0)
  {
    //Turn Off RED LED
    digitalWrite(red,LOW);
    textMessage="";
  }
if(textMessage.indexOf("GON")>=0)
  {
    //Turn On GREEN LED
    digitalWrite(green,HIGH);
    textMessage="";
  }
if(textMessage.indexOf("GOFF")>=0)
  {
    //Turn Off GREEN LED
    digitalWrite(green,LOW);
    textMessage="";
  }
if(textMessage.indexOf("YON")>=0)
  {
    //Turn On BLUE LED
    digitalWrite(yellow,HIGH);
    textMessage="";
  }
if(textMessage.indexOf("YOFF")>=0)
  {
    //Turn Off BLUE LED
    digitalWrite(yellow,LOW);
    textMessage="";
  }
 
  if(textMessage.indexOf("ALLON")>=0)
  {
    //Turn on all LED's
    digitalWrite(red,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(white,HIGH);
    textMessage = "";
  }
if(textMessage.indexOf("ALLOFF")>=0)
  {
    //Turn on all LED's
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(white,LOW);
    textMessage = "";
  }

}