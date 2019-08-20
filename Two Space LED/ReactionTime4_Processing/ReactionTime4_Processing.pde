

//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;
String val;
// We will use this variable to keep track of how many times the program has run
int i = 0;

void setup() {
  udSerial = new Serial(this, "/dev/cu.usbmodem14401", 9600);  //i have connected arduino to com, it would be different in linux and mac os

  // We are going to create an object that will write out our data to a filename with the date and time
  output = createWriter ("TWO_LED.csv");
  size(1000, 1000);
}

  void draw() {
    if (udSerial.available() > 0) {
      // We will read the data from our Arduino
      String SenVal = udSerial.readStringUntil('\n');
      // Here we make sure that there is some output from the Arduino
      if (SenVal != null) {
        // This line will print what we want to the file
        output.println(SenVal);
        background(60);
        // Let's also write the value to the screen
        text(SenVal, 100+50*i, 100);
        // Now we will increase the value of i to count the number of iterations this has gone through
        i=i+1;
      }
    }
    if (i>100){
      output.flush();
      output.close();
      exit(); 
    }
    
  }

  void keyPressed(){
    // We will have another option to stop the code by pressing a button
    output.flush();
    output.close();
    exit(); 
  }
