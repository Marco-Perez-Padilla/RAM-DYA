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
** Archivo read_instruction.cc: Implementación de la instrucción READ.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "read_instruction.h"
#include "../../core/execution_context.h"
#include "../../exceptions/exceptions.h"


/**
 * @brief Executes the READ instruction, which reads an integer from the input tape and stores it in the specified operand.
 * @param ctx The execution context containing the memory, input tape, output tape, label table, accumulator, program counter, and step count.
 * @throws OutOfTapeException If the input tape has no more values to read.
 * @throws InvalidR0OperandException If the operand is R0, which is not allowed
 */
void ReadInstruction::execute(ExecutionContext& ctx) {
  int valor = ctx.input().read();
  operand_->setValue(ctx, valor);
  ++ctx.steps();
  ++ctx.pc();
}