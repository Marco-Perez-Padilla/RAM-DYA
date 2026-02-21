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
** Archivo vector_register.cc: Implementación de registros vectoriales
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "vector_register.h"
#include "../exceptions/exceptions.h"


/**
 * @brief Construct a new Vector Register object with the given data.
 * @param data Vector of integers to initialize the register with.
 */
VectorRegister::VectorRegister(const std::vector<int>& data) : data_(data) {}


/**
 * @brief Get the value of the register as a scalar (not supported for vector registers).
 * @return This function always throws an exception since vector registers do not support scalar access.
 * @throw InvalidOperandException when trying to access a vector register as a scalar.
 */
int VectorRegister::getValue() const {
  throw InvalidOperandException("Intento de acceso escalar a un registro vectorial");
}


/**
 * @brief Set the value of the register as a scalar (not supported for vector registers).
 * @param value The scalar value to set (not used since this function always throws an exception).
 * @throw InvalidOperandException when trying to access a vector register as a scalar.
 */
void VectorRegister::setValue(int value) {
  throw InvalidOperandException("Intento de acceso escalar a un registro vectorial");
}


/**
 * @brief Get the value at a specific index in the vector register.
 * @param index The index to access.
 * @return The value at the specified index.
 * @throw InvalidOperandException if the index is out of range.
 */
int VectorRegister::getValueAt(int index) const {
  if (index < 0 || index >= static_cast<int>(data_.size())) {
    throw InvalidOperandException("Índice fuera de rango en registro vectorial");
  }
  return data_[index];
}


/**
 * @brief Set the value at a specific index in the vector register.
 * @param index The index to access.
 * @param value The value to set at the specified index.
 * @throw InvalidOperandException if the index is negative.
 */
void VectorRegister::setValueAt(int index, int value) {
  if (index < 0) {
    throw InvalidOperandException("Índice negativo en registro vectorial");
  }
  if (index >= static_cast<int>(data_.size())) {
    data_.resize(index + 1, 0);
  }
  data_[index] = value;
}


/**
 * @brief Check if the register is a vector register.
 * @return true since this class represents a vector register.
 */
bool VectorRegister::isVector() const {
  return true;
}