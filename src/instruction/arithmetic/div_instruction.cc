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
 * @brief Ejecuta la instrucción DIV, dividiendo el acumulador por el valor del operando.
 * @param ctx El contexto de ejecución que contiene el estado de la máquina RAM.
 * @throws DivisionByZeroException Si el valor del operando es cero.
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