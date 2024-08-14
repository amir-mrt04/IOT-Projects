import processing.net.*;


// Client for communicating with NodeMCU
Client myClient;

// Variables for data
float temperature = 0;
float humidity = 0;

// Arrays to store historical data for plotting
float[] tempData = new float[60];
float[] humData = new float[60];
int index = 0;

void setup() {
  size(800, 400);
  
  // Replace with the IP address of your NodeMCU
  myClient = new Client(this, "192.168.1.146", 80);
  delay(1000);
  myClient.write("start");
}

void draw() {
  background(255);
  
  // Read incoming data
  if (myClient.available() > 0) {
    String data = myClient.readStringUntil('\n');
    if (data != null) {
      data = trim(data); // Remove extra white spaces
      parseData(data); // Parse the temperature and humidity
    }
  }
  
  // Draw temperature graph
  stroke(255, 0, 0); // Red color for temperature
  noFill();
  beginShape();
  for (int i = 0; i < tempData.length; i++) {
    vertex(map(i, 0, tempData.length - 1, 0, width/2), map(tempData[i], 0, 40, height, 0));
    if(i+1 == tempData.length ) text(tempData[i], 150 ,200);
}
  endShape();
  fill(255, 0, 0);
  text("Temperature (°C)", 10, 20);

  // Draw humidity graph
  stroke(0, 0, 255); // Blue color for humidity
  noFill();
  beginShape();
  for (int i = 0; i < humData.length; i++) {
    vertex(map(i, 0, humData.length - 1, width/2, width), map(humData[i], 0, 100, height, 0));
    if(i+1 == humData.length ) text(humData[i], 550 ,200);
}
  endShape();
  fill(0, 0, 255);
  text("Humidity (%)", width/2 + 10, 20);

  // Add the current data to the arrays
  if (index < tempData.length) {
    tempData[index] = temperature;
    humData[index] = humidity;
    index++;
  } else {
    // Shift all data to the left to make room for new data
    for (int i = 0; i < tempData.length - 1; i++) {
      tempData[i] = tempData[i + 1];
      humData[i] = humData[i + 1];
    }
    tempData[tempData.length - 1] = temperature;
    humData[humData.length - 1] = humidity;
  }
}

void parseData(String data) {
  String[] values = split(data, ',');
  if (values.length == 2) {
    // Extract temperature and humidity
    String[] tempParts = split(values[0], ':');
    String[] humParts = split(values[1], ':');
    if (tempParts.length == 2 && humParts.length == 2) {
      temperature = float(tempParts[1]);
      humidity = float(humParts[1]);
    }
  }
}
