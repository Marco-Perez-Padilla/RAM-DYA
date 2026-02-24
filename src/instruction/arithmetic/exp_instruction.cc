/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 2: Máquina RAM
** Autor: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es, alu0101485904@ull.edu.es
** Fecha: 24/02/2026

** Archivo exp_instruction.h: Archivo de la clase que representa una instrucción de exponencial
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      24/02/2026 - Creacion (primera version) del codigo
**/

#include "exp_instruction.h"
#include "../../core/execution_context.h"
#include <cmath>

/**
 * @brief Executes the ADD instruction, which adds the value of the specified operand to the accumulator.
 * @param ctx The execution context containing the memory, input tape, output tape, label table, accumulator, program counter, and step count.
 */
void ExpInstruction::execute(ExecutionContext& ctx) {
  int valor = operand_->getValue(ctx);
  ctx.accumulator() = pow(ctx.accumulator(), valor);
  ++ctx.steps();
  ++ctx.pc();
}