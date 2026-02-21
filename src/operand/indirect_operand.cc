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
** Archivo indirect_operand.cc: Implementación del operando indirecto.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "indirect_operand.h"
#include "../core/execution_context.h"


/**
 * @brief Constructor that initializes the register index for this indirect operand
 * @param registerIndex the index of the register that this indirect operand refers to
 */
IndirectOperand::IndirectOperand(int registerIndex) : registerIndex_(registerIndex) {}


/**
 * @brief Returns the value stored in the memory address pointed to by the register that this indirect operand refers to
 * @param ctx The execution context, used to access memory
 * @return The value stored in the memory address pointed to by the register that this indirect operand
 */
int IndirectOperand::getValue(ExecutionContext& ctx) const {
  int addr = ctx.memory().read(registerIndex_);
  return ctx.memory().read(addr);
}


/**
 * @brief Writes a value to the memory address pointed to by the register that this indirect operand refers to
 * @param ctx the execution context, used to access memory
 * @param value the value to write to the memory address pointed to by the register that this
 */
void IndirectOperand::setValue(ExecutionContext& ctx, int value) {
  int addr = ctx.memory().read(registerIndex_);
  ctx.memory().write(addr, value);
}


/**
 * @brief Returns the type of this operand, which is INDIRECT
 * @return The operand type of this operand, which is OperandType::INDIRECT
 */
OperandType IndirectOperand::getType() const {
  return OperandType::INDIRECT;
}


/**
 * @brief Tells whether this operand is writable, which is true for an indirect operand
 * @return true, since an indirect operand can be written to
 */
bool IndirectOperand::isWritable() const {
  return true;
}