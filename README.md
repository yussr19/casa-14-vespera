**Immersive music and light experince IOT project** 


-IOT project  prototype that allows light to react to music


 Prototype Project Overview :

 
This project conncects a Grove Sound Sensor to an ARDUINO mkr WIFI 1010 board.The sensor picks up 
the changes in the sound frequency (>250).The code in the arduino sketch assosiates  the music peaks / sound vaule to 
trigger a chnage in the RGB value cycling from one colour to another. The arduino board the send colour as a message to the MQTT which sends it to Vesprea which displays the color chnages seemingly in sync with the sound.

![IMG_5524](https://github.com/user-attachments/assets/ea4c08bc-0bea-49be-9d45-0beb5f8eb182)

**Repository Content Summary**

1. Intial sketcks of prototype
2. code that checks the connecttion between the sound sensor and the Arduino 1010
3. Interations of the code that connects the sound to the light
4. Images and videos of art projects that insipred the idea

**Components Used**

Hardware:

-Grove Sound Sensor -analog mic 
-Arduino mkr WIFI 1010 board
-Vespera LED panel (6×12 = 72 pixels)  

Software:

-Arduino IDE

libaries to support the software:


SPI.h
WiFiNINA.h
PubSubClient.h 
utility/wifi_drv.h

Inspiration and rationale of this prototype
I am very intrested in how sound affects our built enviroment espically through a cultural lense. This protoype aims to explore the relationship of how sound can infulence light and how it works. 
the objectives of the protype was to demonstrate how an IOT system that uses a  physical sound sensor would intreact with netwroked actuator (Vespera)
To better understand how musical peaks would be illustrated in a color light vaule 




