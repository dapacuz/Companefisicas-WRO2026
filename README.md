Equipo Compañefísicas
====

Este repositorio contiene los materiales y proceso de construcción del vehículo autónomo para el Torneo Nacional WRO El Salvador 2026 en la categoría Future Engineers.

# Contenido

* `t-photos` contiene X fotos del equipo
* `v-photos` contiene 6 fotos del vehículo (una de cada ángulo, desde arriba y abajo)
* `video` contiene el archivo de video con una demostración de manejo
* `schemes` contiene diagramas en formato JPEG, PNG o PDF de los componentes electromecánicos e ilustraciones de todos los elementos (componentes electrónicos y motores) utilizados en el vehículo, además de cómo se conectan entre sí.
* `src` contiene el código de control de sodtware para todos los componentes. Fue programado en Arduino IDE.
* `models` contiene los archivos de los modelos diseñados por nosotras en Tinkercad y utilizados por las impresoras 3D y máquinas para cortar láser con las que se fabricaron los elementos del vehículo.
* `management` contiene datos sobre la gestión de movilidad, poder, sentido, diagramas y obstáculos.
* `other` contiene otros archivos sobre cómo se preparó el vehículo para la competencia, documentación, especificaciones, protocolos de comunicación etc.

# Nuestro robot
Nuestro robot, MIGAJA, es un vehículo construido a partir de distintos componentes diseñados por nosotras para la categoría Future Engineers.

# Herramientas
* Lenguaje: C++ (Arduino IDE)
* Librerías: HUSKYLENS, Servo, AFMotor, L298N, Wire y PID_v1

# Gestión de la movilidad
Para nuestro robot, utilizamos 2 tipos de motores:
1.	Un motor DC con un diferencial ensamblado con piezas de LEGO en el tren trasero para ayudar con la propulsión.
2.	Un micro servo SG90 en el tren delantero para controlar la dirección de las ruedas.


## Diseño del chasis 
El chasis está compuesto por piezas diseñadas por nosotras en Onshape y cortadas en acrílico, con el fin de que nuestro diseño sea simple y liviano pero efectivo. MIGAJA es una evolución de los modelos “Jonny Carre Brave”, utilizado para la WRO El Salvador 2025 y “Hadita”, utilizado para la WRO El Salvador 2024. Para los dos modelos anteriores, el chasis fue impreso en 3D, pero se cambió a un nuevo material que puede ser cortado de manera más fácil en caso de modificaciones, conservando un peso similar y aportando una base más sólida. 


# Gestión de potencia, sentidos y obstáculos
## Elementos principales
Los elementos principales para la gestión de potencia y sensores son:
* Fuente de energía: 2 sets de baterías, uno para alimentar el controlador de motores y uno para el Arduino.
* Distribución de energía: una placa reguladora/convertidora de voltaje Elegoo Power MV V2.
* Controlador de motores L298N para controlar el servo y motor DC.
* Arduino UNO R4 para el control del vehículo y gestión de la Huskylens

## Sensores
* Cámara con IA Huskylens para detectar las señales de tránsito, objetos y líneas con la función “Color Recognition”. 
