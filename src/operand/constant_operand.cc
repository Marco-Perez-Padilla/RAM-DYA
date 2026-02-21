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
** Archivo constant_operand.cc: Implementación del operando constante.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "constant_operand.h"
#include "../core/execution_context.h"
#include "../exceptions/exceptions.h"


/**
 * @brief Constructor that initializes the constant value
 * @param value the constant value to be stored in this operand
 */
ConstantOperand::ConstantOperand(int value) : value_(value) {}


/**
 * @brief Returns the constant value stored in this operand
 * @param ctx the execution context (not used in this case)
 * @return the constant value of this operand
 */
int ConstantOperand::getValue(ExecutionContext& ctx) const {
  return value_;
}


/**
 * @brief throws an exception when trying to write to a constant operand, since it is read-only
 * @param ctx the execution context (not used in this case)
 * @param value the value that was attempted to be written (not used in this case)
 * @throws WriteOnConstantOperandException always throws this exception
 */
void ConstantOperand::setValue(ExecutionContext& ctx, int value) {
  throw WriteOnConstantOperandException();
}


/**
 * @brief Returns the type of this operand, which is CONSTANT
 * @return The operand type of this operand, which is OperandType::CONSTANT
 */
OperandType ConstantOperand::getType() const {
  return OperandType::CONSTANT;
}


/**
 * @brief Tells whether this operand is writable, which is false for a constant operand
 * @return false, since a constant operand cannot be written to
 */
bool ConstantOperand::isWritable() const {
  return false;
}