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
** Archivo jump_instruction.cc: Implementación de la instrucción JUMP.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "jump_instruction.h"
#include "../../core/execution_context.h"


/**
 * @brief Executes the JUMP instruction, setting the program counter to the address of the specified label
 * @param ctx Context of execution for the RAM machine
 */
void JumpInstruction::execute(ExecutionContext& ctx) {
  int direccion = ctx.labels().getAddress(label_);
  ctx.pc() = direccion;
  ++ctx.steps();
}