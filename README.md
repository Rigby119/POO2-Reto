# Shangri-La Project
Proyecto de Pogramación Orientada a Objetos en C++ con tematica de juego RPG por turnos. El programa que simula un juego de rol por turnos en el que hay un sistema de mazmorras y clases. También en este podremos subir de nivel matando monstruos y así conseguir mejores atributos para hacer más fácil el resto del juego.

## Funcionalidad
El programa toma algunos parametros directamente del main aunque podrían ser consultados al usuario, estos no afectan mucho a la jugabilidad de igual manera.

El jugador tiene la opción de configurar a dos personajes que podrán después atacar monstruos y ser atacados por los mismos.

Al derrotar monstruos el jugador correspondiente recibirá experiencia y podrá subir de nivel.

Si se derrota a los monstruos de todas las habitaciones antes del jefe, los jugadores se enfrentaran a el en una habitacion de jefe

En caso de que no haya personajes de clase Mago, la pelea contra el boss será completamente automatica debido a que la unica opción de las otras clases en ese turno es atacar.

Un jugador sin vida no podrá atacar. Si los 2 jugadores se quedan sin vida, se fallará la dungeon.

## Casos de error

Al momento de usar rand() se puede producir un error en algunos IDEs, el error es el siguiente: [Error] 'rand' was not declared in this scope

Este error se puede solucionar instalando la libreria <stdlib.h> que normalmente viene incluida dentro de la Biblioteca de plantillas estándar de C++

Si el usuario ingresa un valor no deseado en las preguntas que se le hacen, el programa pedirá que se ingrese un valor valido y repetirá la pregunta.

## Documentación

En este proyecto se hizo uso de la biblioteca de iostream, biblioteca que permite mostrar y pedir datos al usuario, así mismo, se uso la biblioteca string, que nos permite usar datos y variables de tipo string.

Referencias:
https://cplusplus.com/reference/iostream/
https://cplusplus.com/reference/string/

## Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

## Reevaluación

En este caso, los aspectos de SICT0301A se encuentran dentro del UML que está en este repositorio, los 3 rubros de este módulo necesitan ser reevaluados.

Los aspectos de SICT0303A que necesitan ser reevaluados son:
-Concepto de herencia (Visible en clases Player y Monster con sus hijas)
-Modificadores de acceso (Visible en todas las clases)
-Sobrecarga y sobreescritura de métodos (Visible en Player.h o Monster.h y sus hijas)
-Implementacion de clases abstractas (visible en Monster.h y sus hijas)

Para SEG0702A se puede usar cómo referencia este README.md y los diferentes commits que se realizaron.