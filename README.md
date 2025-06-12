🚗 Smart Vehicle Dashboard with Dual Radar Warning System


An interactive, real-time dashboard 
that combines IoT-based proximity sensing with a smart vehicle 
interface. The system uses dual ultrasonic sensors (left and right) 
connected via Arduino to monitor nearby obstacles, display radar 
visuals, and trigger alerts with adaptive speed control—ideal for smart 
vehicles and driver-assistance prototypes.


🛠️ Technologies Used




Frontend: HTML5, CSS3, JavaScript (Canvas API)




Backend: Node.js (Express)




Hardware: Arduino Uno, HC-SR04 Ultrasonic Sensors, USB Serial Communication




Protocols: Serial over USB, JSON (data exchange)




Others: REST API, Real-time data rendering










📌 Features




Dual radar-style visualizations to monitor left and right side of vehicle




Real-time data updates every 300 ms via fetch API




Smart warnings when an object is closer than 50 cm




Visual alerts and automatic speed reduction in case of proximity danger




Scrollable interface to adapt to various screen sizes




Clear display of distance and angular position of detected objects




Responsive design and aesthetic dashboard panels for speed, time, weather, and alerts





🧠 How It Works




Sensor Setup:

Two HC-SR04 ultrasonic sensors scan angles between 0°–180° (mounted on servo motors if desired).




Microcontroller (Arduino):

Reads angle and distance, and sends data via serial to the host system.




Node.js Server:

Listens to serial port, parses sensor data, and exposes it through a /distance API in JSON format.




Frontend Dashboard:

Polls the /distance API at 300ms intervals, draws radar arcs using the Canvas API, and dynamically updates alerts and speed displays.

