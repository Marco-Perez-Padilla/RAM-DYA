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
** Archivo vector_direct_operand.cc: Implementación del operando de vector directo.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "vector_direct_operand.h"
#include "../core/execution_context.h"


/**
 * @brief Constructor that initializes the base register and index operand for this vector direct operand
 * @param baseRegister the index of the base register that this vector direct operand refers to
 * @param index a unique pointer to the operand that represents the index for this vector direct operand
 */
VectorDirectOperand::VectorDirectOperand(int baseRegister, std::unique_ptr<Operand> index)
  : baseRegister_(baseRegister), index_(std::move(index)) {}


/**
 * @brief Returns the value stored in the memory address computed by adding the value of the index operand to the base register
 * @param ctx the execution context, used to access memory
 * @return the value stored in the memory address computed by adding the value of the index operand
 */
int VectorDirectOperand::getValue(ExecutionContext& ctx) const {
  int idx = index_->getValue(ctx);
  return ctx.memory().read(baseRegister_, idx);
}


/**
 * @brief Writes a value to the memory address computed by adding the value of the index operand to the base register
 * @param ctx the execution context, used to access memory
 * @param value the value to write to the memory address computed by adding the value of the
 */
void VectorDirectOperand::setValue(ExecutionContext& ctx, int value) {
  int idx = index_->getValue(ctx);
  ctx.memory().write(baseRegister_, idx, value);
}


/**
 * @brief Returns the type of this operand, which is VECTOR_DIRECT
 * @return The operand type of this operand, which is OperandType::VECTOR_DIRECT
 */
OperandType VectorDirectOperand::getType() const {
  return OperandType::VECTOR_DIRECT;
}


/**
 * @brief Tells whether this operand is writable, which is true for a vector direct operand
 * @return true, since a vector direct operand can be written to
 */
bool VectorDirectOperand::isWritable() const {
  return true;
}