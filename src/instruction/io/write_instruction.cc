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
** Archivo write_instruction.cc: Implementación de la instrucción WRITE.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "write_instruction.h"
#include "../../core/execution_context.h"


/**
 * @brief Executes the WRITE instruction, which writes the value of the specified operand to the output tape.
 * @param ctx The execution context containing the memory, input tape, output tape, label table
 */
void WriteInstruction::execute(ExecutionContext& ctx) {
  int valor = operand_->getValue(ctx);
  ctx.output().write(valor);
  ++ctx.steps();
  ++ctx.pc();
}