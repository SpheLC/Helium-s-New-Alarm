// -<HNA>- v1.0.0 -<ⓇBlue Carrot Studio>-
// Helium's New Alarm, open source project, created by BCS
// You can edit the program if you want ;)
// Have fun!

#define echoPin 11
#define trigPin 12

long duration;
int distance;
int buz = 3;
int button = A1;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 9;
int led5 = 10;
int led6 = 8;
int mode = 0; //0 idle, 1 auto-set, 2 activate
int distlimit;
int val_butt;

void setup() {
  pinMode(buz, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  delay(1000);
  digitalWrite(led6, LOW);
  delay(1000);
  digitalWrite(led5, LOW);
  delay(1000);
  digitalWrite(led4, LOW);
  delay(1000);
  digitalWrite(led3, LOW);
  delay(1000);
  digitalWrite(led2, LOW);
  delay(1000);
  digitalWrite(led1, LOW);
  Serial.begin(9600);
  Serial.println("Alarm ready! -<Helium's alarm>-");
}

void loop() {
  val_butt = analogRead(button);
  if (val_butt >= 720 and val_butt <= 725) {
    delay(10);
    val_butt = analogRead(button);
    if (val_butt >= 720 and val_butt <= 725) {
      if (mode == 0) {
        Serial.println("Mode -> 1");
        digitalWrite(buz, HIGH);
        digitalWrite(led1, HIGH);
        delay(200);
        digitalWrite(buz, LOW);
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        duration = pulseIn(echoPin, HIGH);
        // Calculating the distance
        distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
        distlimit = distance + 10;
        if (distance < 100) {
          digitalWrite(led1, HIGH);
        } else if (distance < 150) {
          digitalWrite(led1, HIGH);
        } else if (distance < 200) {
          digitalWrite(led1, HIGH);
          delay(500);
          digitalWrite(led2, HIGH);
        } else if (distance < 250) {
          digitalWrite(led1, HIGH);
          delay(500);
          digitalWrite(led2, HIGH);
          delay(500);
          digitalWrite(led3, HIGH);
        } else if (distance < 300) {
          digitalWrite(led1, HIGH);
          delay(500);
          digitalWrite(led2, HIGH);
          delay(500);
          digitalWrite(led3, HIGH);
          delay(500);
          digitalWrite(led4, HIGH);
        }
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(buz, LOW);
        delay(200);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(buz, HIGH);
        delay(200);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(buz, LOW);
        delay(200);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(buz, HIGH);
        delay(200);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(buz, LOW);
        Serial.print("Distance: ");
        Serial.println(distance);
        Serial.print("Distance Limit: ");
        Serial.println(distlimit);
        mode = 1;
      } else if (mode == 1) {
        Serial.println("Mode -> 2");
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, HIGH);
        digitalWrite(buz, LOW);
        delay(800);
        digitalWrite(led6, LOW);
        digitalWrite(buz, HIGH);
        delay(800);
        digitalWrite(led6, HIGH);
        digitalWrite(buz, LOW);
        delay(800);
        digitalWrite(led6, LOW);
        digitalWrite(buz, HIGH);
        delay(800);
        digitalWrite(led6, HIGH);
        digitalWrite(buz, LOW);
        delay(800);
        digitalWrite(led6, LOW);
        digitalWrite(buz, HIGH);
        delay(800);
        digitalWrite(led6, HIGH);
        digitalWrite(buz, LOW);
        mode = 2;
      }
    }
  }

  if (mode == 2) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    //calculating the distance
    distance = duration * 0.034 / 2; //speed of sound wave divided by 2 (go and back)
    if (distance > distlimit) {
      Serial.print("ALARM ACTIVATED WITH DISTANCE = ");
      Serial.println(distance);
      digitalWrite(buz, HIGH);
      delay(10000);
      digitalWrite(led1, HIGH);
      delay(10000);
      digitalWrite(led2, HIGH);
      delay(10000);
      digitalWrite(led3, HIGH);
      delay(10000);
      digitalWrite(led4, HIGH);
      delay(10000);
      digitalWrite(led5, HIGH); //dopo 50 sec
      delay(5000);
      digitalWrite(led1, LOW);
      delay(1000);
      digitalWrite(led2, LOW);
      delay(1000);
      digitalWrite(led3, LOW);
      delay(1000);
      digitalWrite(led4, LOW);
      delay(1000);
      digitalWrite(led5, LOW);
      delay(1000);
      digitalWrite(led6, LOW);
      digitalWrite(buz, LOW);
      delay(1000);
      digitalWrite(led6, HIGH);
    }
    val_butt = analogRead(button);
    if (val_butt >= 720 and val_butt <= 725) {
      delay(10);
      val_butt = analogRead(button);
      if (val_butt >= 720 and val_butt <= 725) {
        Serial.println("Mode -> 0");
        mode = 0;
        delay(1000);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        digitalWrite(buz, LOW);
        delay(500);
        digitalWrite(led4, HIGH);
      }
    }
  }
}
