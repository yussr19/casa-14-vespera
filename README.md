**Immersive music and light experince IOT project** 


-IOT project  prototype that allows light to react to music


 Prototype Project Overview :

 
This project conncects a Grove Sound Sensor to an ARDUINO mkr WIFI 1010 board.The sensor picks up 
the changes in the sound frequency (>250).The code in the arduino sketch assosiates  the music peaks / sound vaule to 
trigger a change in the RGB value cycling from one colour to another. The arduino board sends the colour as a message to the MQTT which sends it to Vesprea which displays the color changes seemingly in sync with the sound.

![IMG_5524](https://github.com/user-attachments/assets/ea4c08bc-0bea-49be-9d45-0beb5f8eb182)

**Repository Content Summary**

1. Intial sketcks of prototype
2. code that checks the connection  between the sound sensor and the Arduino 
3. Interations of the code that connects the sound to the light


**Components Used**

Hardware:

-Grove Sound Sensor -analog mic 
-Arduino mkr WIFI 1010 board
-Vespera LED panel (6×12 = 72 pixels)  

Software:

-Arduino IDE

Libaries  to support the software:


SPI.h
WiFiNINA.h
PubSubClient.h 
utility/wifi_drv.h

**Inspiration and rationale of this prototype**

I am very interested in how sound affects our built environment, especially through a cultural lens. I visited some art installations to see how artists have explored this [idea](https://youtube.com/shorts/BgwDOJD0LtY).
This protoype aims to explore the relationship of how sound can be used to influence light and how sound can be represneted through colours via the Vesprea light instulation.

**How to reproduce this project** 

Gather the components outlined above.
Connect the sensor to the MKR1010 board connect:
-connect the  analog sound pin using A2
-Connect VCC to 5V to power the device 
-connect GND TO GND
Tip :to ensure better sound detection is to place the sound sensor flat with the microphone facing upward.
Software setup up 
install Arduino IDE and install the libraries mentioned above. 
Enter wifi login detials(SSID and Password) in the arduino_secrets .
Update the MQTT topic number to the relevant number ; for this project, I was assigned the number 20.
Ensure network connection to MQTT 
Upload the code provided to the Arduino sketch 
Play music close to  the sensor 
Tip: Play music that contians distinct sharp peaks such as kicks or snares as the microhone picks them up quite well.
The Vesprea light instulation should change colors after it detects any sound that is above the threshold.


**Sound Detection**


The grove sensor uses an anaglong microphone that is desinged  to detect the loudness of the audio in the sensors environment. This is then outputed via an analog signal . The sensor kit recommends the use of noises such as clapping or knocking to illustarte how the sensor detects loud noises.
![Grove - Sound Sensor v1 6 Schematic](https://github.com/user-attachments/assets/501d5230-80c3-4c43-87f4-45274247b81d)

Essentially, this sensor picks up any sound above a threshold.  When the microphone in the sensor detects a loud sound, such as a clap, it detects it well. However, when the loud sound is repeated, such as 5 claps in a row , the sensor will sense them all but only react to 2 out of 5 of the claps.  I belive this is because when the sensor is exposed to mutiples of the same loud nosie even if all of the noises excced the sound threshold, it only reacts to the peaks or the highest noise produced. The sensor often detects the quieter sounds but does not produce an output for them. 
This is why I used music as my chosen noise for this project, as music contains a continuous beat coupled with  sharp peaks. This works with the limitations of the microphone to produce an output for peaks in the music, creating readings with improved stability. Thus, when the user observes the music and  the colour chnages in the Vespera, it appears as though the light is changing in a ryhtmic manner.



**Current Issues and Constrains**

 Delay in the transition from one light to another. 
 After reviewing the code, I believe that this is due to the program sending too many messages to MQTT at once. In my code, there is a function that changes the colours of all 72 LEDs when the sensor detects noise. However, this function also  goes through each LED individually. The code is publishing the same RGB data repatedly for each LED rather than sending one message to the whole installation. This led to 73 messages being sent every time the colour changed. This caused lagging where the sensor and light appaer to not be responsive. It also caused  a deylay in the light changing, leading the vespera  colours to change for only half of the LEDs whilst the rest would stay on the previous color. 

**Furture Imporvement**
1. Instead of having simple color changes, adding animations such as a ripple effect or a pulse effect would provide a far more visually expressive experience for the user
   
2. If the connection was changed from a WIFI connection to MQTT to a Bluetooth connection, this would allow the project to be adopted by a variety of music venues, as Bluetooth offers a simpler setup  by allowing devices to connect directly. This direct connection would be better suited for a music venue that experiences heavy foot traffic. The Bluetooth connection would also provide a faster response that would reduce transmission delays as the Bluetooth would create a direct connection between the Arduino board (that is connected to the sensor)and the Vespera




