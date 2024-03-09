# Ultrasonic_sensor_interfacing
This is a project about interfacing ultrasonic sensor with ATmega32 and 2*16 LCD to show distance of an object
ultrasonic sensor used in proteus is HCSR04 
The sensor works by sending a pulse for a period of 10us to the Trigger pin by the microcontroller (I made it 30us as to not make the time of pulse too tight that might make error)
The sensor then sends an ultrasonic wave with a frequency of 40kHZ, the sonic wave when it reflects of an object the sensor receive it.
Untill the sensor receives the sonic wave it gives back a high signal on the Echo pin and when the sensor receives the sonic wave it gives back a low signal on the Echo pin   (look at the online datasheet for graphs and more info)
In this code the sensor does not read distance more than 90cm (you can adjust the code for more leeway but the actual hardware has a maximum theoretical distance of 400cm)
![Capture](https://github.com/AhmedAlsheikh0234/Ultrasonic_sensor_interfacing/assets/154998275/d4601a60-c508-44c4-8d48-cd19330756ec)

![1](https://github.com/AhmedAlsheikh0234/Ultrasonic_sensor_interfacing/assets/154998275/2cffa8f9-27d6-466c-b756-5c185ffe08b7)
