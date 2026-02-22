/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 2: Máquina RAM
** Autor: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es, alu0101485904@ull.edu.es
** Fecha: 21/02/2026
**
** Archivo direct_operand.cc: Implementación del operando directo.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "direct_operand.h"
#include "../core/execution_context.h"


/**
 * @brief Constructor that initializes the register index for this direct operand
 * @param registerIndex the index of the register that this direct operand refers to
 * @throws InvalidR0OperandException if the register index is 0, since R0 cannot be used as a direct operand
 */
DirectOperand::DirectOperand(int registerIndex) : registerIndex_(registerIndex) {
  if (registerIndex == 0) {
    throw InvalidR0OperandException("DirectOperand");
  }
}


/**
 * @brief Returns the value stored in the register that this direct operand refers to
 * @param ctx The execution context, used to access memory
 * @return The value stored in the register that this direct operand refers to
 */
int DirectOperand::getValue(ExecutionContext& ctx) const {
  return ctx.memory().read(registerIndex_);
}


/**
 * @brief Writes a value to the register that this direct operand refers to
 * @param ctx the execution context, used to access memory
 * @param value the value to write to the register that this direct operand refers to
 */
void DirectOperand::setValue(ExecutionContext& ctx, int value) {
  ctx.memory().write(registerIndex_, value);
}

OperandType DirectOperand::getType() const {
  return OperandType::DIRECT;
}

bool DirectOperand::isWritable() const {
  return true;
}