# DIY A Simple Three-axis Accelerometer Data Logger

![image](https://user-images.githubusercontent.com/65546290/220809343-1498fc52-f18f-40df-8472-533a36870821.png)


## Background 
ChatGPT has gained immense popularity recently, and the system has even been down due to a significant surge in usage. This aroused my interest in Machine Learning. I learned that TinyML enables the deployment of ML models on edge devices with limited resources, such as MCUs. So I decided to explore it by embarking on a simple project. 

## Thought
The first step is to collect and store data for future model training on TinyML. I just got an accelerometer+gyroscope module, so I plan to make a simple data logger, which will gather and save the three-axis (x, y, and z) data of hand movements to a microSD card and display them on an OLED screen in real-time. 

![image](https://user-images.githubusercontent.com/65546290/220807373-94c13fd6-9ec8-4f16-bd37-a0c77e8c080e.png)

# HARDWARE LIST

* ESP32-E IoT Microcontroller
* 0.96" OLED Display
* MicroSD Card Reader
* ICG 20660L Accel+Gyro 6-Axis IMU Module
* MicroSD Memory Card
* 3.7V Lithium-ion Battery
* 3D-printed Housing
* Switch


# Connection Diagram
![image](https://user-images.githubusercontent.com/65546290/220807596-de7b7058-db31-4d08-95fa-f3cee98dfd9e.png)
 

## ESP32-E to Accel+Gyro Module  
* 3.3V to 3.3V
* GND to GND
* SCK to SCK
* MI to SDI
* MO to SDO
* D12 to CS        

 

## ESP32-E to MicroSD card reader
* 5V to 5V
* GND to GND
* MO to MO
* D6 to SS
* SCK to SCK
* MI to MI

## ESP32-E to 0.96" OLED display
* 3.3V to 3.3V
* GND to GND
* D5 to SCL
* D7 to SDA
* D2 to D/C
* D10 to CS

# Housing Design 
To build the 3D model of the housing, we need to design the hardware layout and measure dimensions first, then draw the model on SolidWorks.
The housing of the data recorder includes a cover,  base, and main body(box without a top).
Meanwhile, we need to reserve the Type-C port, switch and SD card slots, and 4 holes for M2 screws on the housing.
![image](https://user-images.githubusercontent.com/65546290/220808779-58767824-cc2c-42b4-aa16-ad846abd8ae6.png)




# Upload Program
Then upload the program. 
In the program, the three-axis values are recorded and saved to the MicroSD card, and displayed on the LCD in real time.
![image](https://user-images.githubusercontent.com/65546290/220807704-dccf08f5-ef35-402c-8feb-79377e107d95.png)


# Data Collection
## Insert the MicroSD memory card into the corresponding slot to store data.
![image](https://user-images.githubusercontent.com/65546290/220807774-56be532b-b90c-4af0-a088-a6db7d436702.png)

## Power on the device, and record different movement trajectories such as square, triangle, circle, and cross (or X).
![image](https://user-images.githubusercontent.com/65546290/220807816-0ad409a8-9e5f-49bf-a976-6a74cded91ff.png)


## Read the data in CSV format from the MicroSD memory card.
![image](https://user-images.githubusercontent.com/65546290/220807829-3a0f0696-9de7-4669-a5ff-d61c1d6e7d08.png)



I just simply test the device by gathering hand movement data. It can also be used to measure the g-forces exerted on your body when you do your favorite sports.
I will continue to try using the data for TinyML training and generate a neural network model.



# Thank
Well, that's all for this project.Thanks for reading, feel free to leave your comments if you have any other good ideas!
