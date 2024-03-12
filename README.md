# Ultrasonic_sensor_interfacing
This is a project about interfacing ultrasonic sensor with ATmega32 and 2*16 LCD to show distance of an object
ultrasonic sensor used in proteus is HCSR04 
The sensor works by sending a pulse for a period of 10us to the Trigger pin by the microcontroller (I made it 30us as to not make the time of pulse too tight that might make error)
The sensor then sends an ultrasonic wave with a frequency of 40kHZ, the sonic wave when it reflects of an object the sensor receive it.
Untill the sensor receives the sonic wave it gives back a high signal on the Echo pin and when the sensor receives the sonic wave it gives back a low signal on the Echo pin   (look at the online datasheet for graphs and more info)
In this code the sensor does not read distance more than 90cm (you can adjust the code for more leeway but the actual hardware has a maximum theoretical distance of 400cm)
![Capture](https://github.com/AhmedAlsheikh0234/Ultrasonic_sensor_interfacing/assets/154998275/d4601a60-c508-44c4-8d48-cd19330756ec)

![1](https://github.com/AhmedAlsheikh0234/Ultrasonic_sensor_interfacing/assets/154998275/2cffa8f9-27d6-466c-b756-5c185ffe08b7)
# Update
I added 3 LEDs as to simulate street light saving system
The aim of this is to save more energy wasted on streetlights remaining on even if there isnt any car on the road 
when a car passes by the sensor untill a distace of 30 the first LED (streetlight) comes on and when car exits its range and the distance increases untill 60 the second light is on and so on 
When the distance increase to 90 all LEDs off as the car left the range of the sensor 
![1](https://github.com/AhmedAlsheikh0234/Ultrasonic_sensor_interfacing/assets/154998275/a88b6e7a-9396-4e60-825d-a38a07cba49a)

![2](https://github.com/AhmedAlsheikh0234/Ultrasonic_sensor_interfacing/assets/154998275/49595704-2dab-4123-b2b8-38f657a4695d)

![3](https://github.com/AhmedAlsheikh0234/Ultrasonic_sensor_interfacing/assets/154998275/218c76c4-644b-4a37-81a7-aefd5cc1ad31)
