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
** Archivo scalar_register.cc: Implementación de registros escalares
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "scalar_register.h"
#include "../exceptions/exceptions.h"


/**
 * @brief Get the value of the register as a scalar.
 * @return The scalar value stored in the register.
 */
int ScalarRegister::getValue() const {
  return value_;
}


/**
 * @brief Set the value of the register as a scalar.
 * @param value The scalar value to set in the register.
 */
void ScalarRegister::setValue(int value) {
  value_ = value;
}


/**
 * @brief Get the value at a specific index in the scalar register (not supported for scalar registers).
 * @param index The index to access (not used since this function always throws an exception).
 * @return This function always throws an exception since scalar registers do not support indexed access.
 * @throw InvalidOperandException when trying to access a scalar register with an index.
 */
int ScalarRegister::getValueAt(int index) const {
  throw InvalidOperandException("Intento de acceso indexado a un registro escalar");
}


/**
 * @brief Set the value at a specific index in the scalar register (not supported for scalar registers).
 * @param index The index to access (not used since this function always throws an exception).
 * @param value The value to set at the specified index (not used since this function always throws an exception).
 * @throw InvalidOperandException when trying to access a scalar register with an index.
 */
void ScalarRegister::setValueAt(int index, int value) {
  throw InvalidOperandException("Intento de acceso indexado a un registro escalar");
}


/**
 * @brief Check if the register is a vector register.
 * @return false since this class represents a scalar register.
 */
bool ScalarRegister::isVector() const {
  return false;
}