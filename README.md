
# Práctica 1 - Sistemas Informáticos Industriales
Javier Lerin Alonso Miercoles 11:30-13:30
David Alvarez Sanchez 
Repositorio para las prácticas de la asignatura.
Desarrollo de un juego de tenis utilizando C++, OpenGL y GLUT.

## Funcionalidades desarrolladas:
- Configuración inicial de CMake y Make.
- Implementación del movimiento básico de las raquetas.
- Implementación del movimiento de la pelota.

# Práctica 2 - Sistemas Informáticos Industriales
Javier Lerin Alonso Miercoles 11:30-13:30
David Alvarez Sanchez 

## Funcionalidades desarrolladas:
- Implementado proceso logger mediante tuberías con nombre (FIFO) 
- Finalización a los 3 puntos
- 
# Práctica 3 - Sistemas Informáticos Industriales
Javier Lerin Alonso Miercoles 11:30-13:30
David Alvarez Sanchez 

## Funcionalidades desarrolladas:
- Desarrollo de un bot que asume el control de la raqueta izquierda mediante una lógica que evalúa constantemente la coordenada Y de la pelota.
- Creación de la estructura centralizada DatosMemCompartida para intercambiar simultáneamente las coordenadas de los objetos y las órdenes de movimiento.
- Establecimiento de un puente de comunicación de alto rendimiento y bidireccional mapeando el archivo /tmp/mem_tenis directamente en la memoria RAM mediante mmap y ftruncate.
- Modificación del bucle principal del juego (OnTimer) para volcar el estado actual a la memoria compartida en cada frame y ejecutar la acción (w o s) dictada remotamente por el bot.
