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
** Archivo mul_instruction.cc: Implementación de la instrucción MUL.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "mul_instruction.h"
#include "../../core/execution_context.h"


/**
 * @brief Ejecuta la instrucción MUL, multiplicando el valor del operando por el acumulador.
 * @param ctx El contexto de ejecución que contiene el estado de la máquina RAM.
 */
void MulInstruction::execute(ExecutionContext& ctx) {
  int valor = operand_->getValue(ctx);
  ctx.accumulator() = ctx.accumulator() * valor;
  ++ctx.steps();
  ++ctx.pc();
}