/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 2: Máquina RAM
** Autor: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es, alu0101485904@ull.edu.es
** Fecha: 22/02/2026
**
** Archivo halt_instruction.cc: Implementación de la instrucción HALT.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "halt_instruction.h"
#include "../../core/execution_context.h"
#include "../../exceptions/exceptions.h"


/**
 * @brief Executes the HALT instruction, throwing a HaltException to signal the end of execution
 * @param ctx Context of execution for the RAM machine
 */
void HaltInstruction::execute(ExecutionContext& ctx) {
  ++ctx.steps();
  throw HaltException();
}