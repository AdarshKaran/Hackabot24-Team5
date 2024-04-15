#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1); // Motor 1 FL
AF_DCMotor motor2(2); // Motor 2 BL
AF_DCMotor motor3(3); // Motor 3 FR
AF_DCMotor motor4(4); // Motor 4 BR
String readString;

//Create software mySerial object to communicate with HC-05
SoftwareSerial mySerial(0, 1); //HC-05 Tx & Rx is connected to Arduino #3 & #2
Servo myservo;

int t = 0;
void setup()
{
  //Begin mySerial communication with Arduino and Arduino IDE (mySerial Monitor)
  mySerial.begin(9600);
  
  //Begin mySerial communication with Arduino and HC-05
  Serial.begin(9600);

  mySerial.println("Initializing...");
  mySerial.println("The device started, now you can pair it with bluetooth!");
  motor1.setSpeed(250);   //Set Motor Speed
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  myservo.attach(10);
}

void loop() {
  while(mySerial.available()){
    delay(50);
    char c=mySerial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){      // MOVE FORWARD
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
    }
    if (readString =="BACKWARD"){     // MOVE BACKWARD
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
    }
    if (readString =="LEFT"){     // MOVE LEFT SIDE
      motor1.run (BACKWARD);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (BACKWARD);
    }
    if (readString =="RIGHT"){     // MOVE RIGHT SIDE
      motor1.run (FORWARD);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (FORWARD);
    }
    if (readString =="FORWARDLEFT"){     // MOVE FORWARD LEFT
      motor1.run (RELEASE);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (RELEASE);
    }
    if (readString =="FORWARDRIGHT"){     // MOVE FORWARD RIGHT
      motor1.run (FORWARD);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (FORWARD);
    }
    if (readString =="BACKWARDLEFT"){     // MOVE BACKWARD LEFT
      motor1.run (BACKWARD);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (BACKWARD);
    }
    if (readString =="BACKWARDRIGHT"){     // MOVE BACKWARD RIGHT
      motor1.run (RELEASE);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (RELEASE);
    }
    if (readString =="ROTATELEFT"){     // ROTATE LEFT SIDE
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
    }
    if (readString =="ROTATERIGHT"){     // ROTATE RIGHT SIDE
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
    }
    if (readString =="STOP"){     // STOP
      motor1.run (RELEASE);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (RELEASE);
    }
    if (readString.startsWith("SERVO(") && readString.endsWith(")")) { // Check if message is in SERVO(VAL) format
      int startPos = readString.indexOf('(') + 1;
      int endPos = readString.indexOf(')');
      if (startPos != -1 && endPos != -1) {
        String valString = readString.substring(startPos, endPos);
        int servoVal = valString.toInt(); // Convert string to integer
        myservo.write(servoVal); // Set servo position
        Serial.print("Servo value set to: ");
        Serial.println(servoVal);
      }
    }
    readString="";
  }
}