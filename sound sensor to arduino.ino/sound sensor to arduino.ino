	
int sound_sensor = A2; //assign to pin A2

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //begin Serial Communication
}

void loop() {
  int soundValue = 0; //create variable to store many different readings
  for (int i = 0; i < 32; i++) //create a for loop to read 
  { soundValue += analogRead(sound_sensor);  } //read the sound sensor
 
  soundValue >>= 5; //bitshift operation 
  Serial.println(soundValue); //print the value of sound sensor
 
 
//if a value higher than 500 is registered, we will print the following
//this is done so that we can clearly see if the threshold is met
  if (soundValue > 450) { 
    Serial.println("         ||        ");
    Serial.println("       ||||||      ");
    Serial.println("     |||||||||     ");
    Serial.println("   |||||||||||||   ");
    Serial.println(" ||||||||||||||||| ");
    Serial.println("   |||||||||||||   ");
    Serial.println("     |||||||||     ");
    Serial.println("       ||||||      ");
    Serial.println("         ||        ");
  }
  delay(50); //a shorter delay between readings


}



