/*import twitter4j.conf.*;
import twitter4j.*;
import twitter4j.auth.*;
import twitter4j.api.*;
import java.util.*;

Twitter twitter;
String searchString = "#processing";
List<Status> tweets;*/

import processing.serial.*;
Serial arduino;

int baudrate = 9600;


void setup() {
  arduino = new Serial(this, Serial.list()[5], baudrate);
}

void draw() {
  
  arduino.write('r');
  arduino.write('-');

}
