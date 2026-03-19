# Pou Console Edition (v1.0)

## ¡Bienvenido a la versión de terminal de la mascota virtual más famosa del mundo! Este es un simulador de cuidado integral desarrollado íntegramente en C++, diseñado para ejecutarse en entornos de línea de comandos (Windows).
## Características Actuales

  *  Sistema de Estadísticas Dinámico: Gestiona los niveles de Hambre, Energía y Salud de tu mascota.

   * Ciclo de Vida y Progresión: Gana XP interactuando con tu mascota y sube de nivel para desbloquear mejores recompensas.

   * Economía Integrada: Juega minijuegos para ganar "Pou-Coins" y gástalos en la tienda.

  * Gestión de Inventario: Compra y almacena hasta 5 tipos de artículos (Comida, Pociones y Objetos Especiales) con efectos únicos.

   * Persistencia de Datos: ¡Tu progreso está a salvo! El juego guarda automáticamente tu estado en un archivo .txt mediante flujos de archivos (fstream).

   * Estados Visuales: Arte ASCII que cambia según la salud, el hambre y el estado de ánimo general de tu mascota.

## Requisitos Técnicos

   * Lenguaje: C++ (se recomienda estándar C++11 o superior).

   * Compilador: MSVC.

## Librerías Utilizadas:

   * <iostream>: Entrada/Salida estándar.

   * <fstream>: Manejo de archivos y persistencia.

   * <ctime> & <cstdlib>: Generación de números aleatorios para juegos.

   * <conio.h>: Captura de entrada de teclado (Optimizado para entornos Windows).

## Cómo Jugar

   * Inicio: Al ejecutar, el juego busca un archivo de guardado (partida.txt). Si no lo encuentra, te pedirá que nombres a tu nueva mascota.

   ## Menú Principal:

     *   Jugar: Entra a la "Zona de Juegos" para adivinar el número y ganar monedas.

      *  Comer: Accede al inventario para alimentar o curar a tu mascota.

       * Dormir: Restaura la energía por 30 monedas.

       * Tienda: Compra suministros esenciales.

       * Stats: Mira las barras detalladas y tu progreso de experiencia.

   * Supervivencia: ¡Vigila las barras! Si el hambre o la salud bajan demasiado, la apariencia de tu mascota cambiará.

## Estructura del Proyecto

El código sigue una arquitectura modular basada en una clase central y funciones especializadas:
Componente	Descripción
class Mascota	Estructura de datos central con atributos y array de inventario.
Sistema de Guardado	Lógica de flujos de archivos (ofstream/ifstream) para persistencia.
Motor Gráfico	Funciones para limpiar pantalla, renderizar barras de UI y arte ASCII.
# Hoja de Ruta (Próximas Actualizaciones)

  *  [ ] Sistema en Tiempo Real: Las estadísticas disminuirán según el tiempo real transcurrido desde la última sesión.

  *  [ ] Misiones Diarias y Logros: Objetivos a largo plazo para mayor compromiso.

  *  [ ] Migración a POO Pura: Refactorización de todas las funciones a métodos de clase.

  *  [ ] Soporte de Color ANSI: Añadir colores a la terminal para una interfaz más vibrante.

Autor: Sukhoik8

Año: 2026
