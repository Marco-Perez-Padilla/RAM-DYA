/**
** Universidad de La Laguna
** Escuela Superior de Ingeniería y Tecnología
** Grado en Ingeniería Informática
** Asignatura: Diseño y Análisis de Algoritmos
** Curso: 3º
** Práctica 2: Máquina RAM
** Autores: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es, alu0101485904@ull.edu.es
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


/**
 * YA IMPLEMENTADO:
 * - Todos los .h, lo siguiente es referente a los .cc
 * - tape (todos los archivos), cintas salida y entrada
 * - Parser: SOLO label table
 * - operand: Tdodos los archivos, tipos de operandos (ctes, directos, indirectos y vector para apto+)
 * - memory: Todos los archivos, memoria de la máquina RAM e implementación de los registros (y tmb la memoria de registros)
 * - file manager: Todos los archivos, lectura de archivos de entrada y escritura de archivos de salida
 * - exceptions: Implementación de las excepciones
 * - core: Execution context y program counter hechos
 * - Parser: Implementar el parser completo (Adicion de funciones en help, funciones de ayuda a parser)
 */

 /**
  * TODO:
  * - instruction: Implementar todos los .cc, tanto arithmetic, como control e io (asi como tmb el factory)
  * - help: Considerar si dejar las ayudas de parser en help_functions o crear un nuevo archivo más específico. Son funciones de toup, parse, tokenize, trim
  * - help: Actualizar mensajes de ayuda y ajustar a la ejecución del programa como se pide (último paso de todos)
  * - core: Instruction executor (ejecución de instrucciones) y ram machine (núcleo del programa)
  * - addressing: Implementacion de los tres tipos de addressing 
  */