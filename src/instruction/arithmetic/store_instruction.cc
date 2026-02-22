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
** Archivo store_instruction.cc: Implementación de la instrucción STORE.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "store_instruction.h"
#include "../../core/execution_context.h"


/**
 * @brief Executes the STORE instruction, which stores the value of the accumulator into the specified operand.
 * @param ctx The execution context containing the memory, input tape, output tape, label table, accumulator, program counter, and step count.
 */
void StoreInstruction::execute(ExecutionContext& ctx) {
  operand_->setValue(ctx, ctx.accumulator());
  ++ctx.steps();
  ++ctx.pc();
}