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
** Archivo load_instruction.cc: Implementación de la instrucción LOAD.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "load_instruction.h"
#include "../../core/execution_context.h"


/**
 * @brief Executes the LOAD instruction, which loads the value from the specified operand into the accumulator.
 * @param ctx The execution context containing the memory, input tape, output tape, label table, accumulator, program counter, and step count.
 */
void LoadInstruction::execute(ExecutionContext& ctx) {
  int valor = operand_->getValue(ctx);
  ctx.accumulator() = valor;
  ++ctx.steps();
  ++ctx.pc();
}