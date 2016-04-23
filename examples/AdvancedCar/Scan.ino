/* 
 * Function to scan surroundings and turn to the best path 
 */
const byte RIGHT  = 0;
const byte CENTER = 1;
const byte LEFT   = 2;

void moveLR(int turntime) {
  float minrange = car.getRange(); // get center distance again
  byte bestdir = CENTER;  // best direction is straight back 
  int servodelay = 500;  // allow some miliseconds for servo to get to position
  
  // scan right
  car.setServo(135);
  delay(servodelay);
  float dist = car.getRange(); // get right wall range
  if (dist > minrange) {
    bestdir = RIGHT;  // best direction so far is to the right
    minrange = dist;  // range to furthest wall so far
  }
  // scan left
  car.setServo(45);
  delay(servodelay);
  dist = car.getRange(); // get left wall range
  if (dist > minrange) {
    bestdir = LEFT;  // best direction is to the left
  }
  car.setServo(90);  // center the proximity sensor again
  delay(servodelay);

  // back up to the right or left or center
  if (bestdir == RIGHT) {
      //car.motorsWrite(-1*carspeed, 0); // back to the right
      car.motorsWrite(0, -1*carspeed); // back to the right
      delay(turntime);
      //delay(900);
      //car.motorsWrite(0, -1*carspeed); // back to the left
      //delay(1000);
  } else if (bestdir == LEFT){
      //car.motorsWrite(0, -1*carspeed); // back to the left
      car.motorsWrite(-1*carspeed, 0); // back to the right
      delay(turntime);
      //delay(900);
      //car.motorsWrite(-1*carspeed, 0); // back to the right
      //delay(1000);
  } else {
      car.motorsWrite(-1*carspeed, -1*carspeed); // back up straight
      delay(turntime);
  }
  car.stopMotors();
}

