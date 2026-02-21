/**
** Universidad de La Laguna
** Escuela Superior de Ingeniería y Tecnología
** Grado en Ingeniería Informática
** Asignatura: Diseño y Análisis de Algoritmos
** Curso: 3º
** Práctica 2: Máquina RAM
** Autores: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es
** Fecha: 01/02/2026

** Archivo main.cc: Programa principal que ejecuta el menú
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      21/02/2026 - Creación (primera versión)
**/

#include <string>
// #include "menu/menu.h"
#include "help/help_functions.h"

int main(int argc, char* argv[]) {
  int result = ValidateArguments(argc, argv);
  if (result >= 0) return result;
  //Menu menu;
  //menu.Run();
  return 0;
}
