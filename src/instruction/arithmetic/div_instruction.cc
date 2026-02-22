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
** Archivo div_instruction.cc: Implementación de la instrucción DIV.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "div_instruction.h"
#include "../../core/execution_context.h"
#include "../../exceptions/exceptions.h"


/**
 * @brief Executes the DIV instruction, which divides the value in the accumulator by the value of the operand and stores the result back in the accumulator.
 * @param ctx The execution context containing the memory, input tape, output tape, label table, accumulator, program counter, and step count.
 * @throws DivisionByZeroException If the operand value is zero, as division by zero is not allowed.
 */
void DivInstruction::execute(ExecutionContext& ctx) {
  int valor = operand_->getValue(ctx);
  if (valor == 0) {
    throw DivisionByZeroException();
  }
  ctx.accumulator() = ctx.accumulator() / valor;
  ++ctx.steps();
  ++ctx.pc();
}