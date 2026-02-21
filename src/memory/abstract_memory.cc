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
** Archivo abstract_memory.cc: Implementación de los métodos concretos de AbstractMemory.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "abstract_memory.h"
#include "register.h"
#include "../exceptions/exceptions.h"


/**
 * @brief Read a value from a register.
 * @param regv The register number to read from.
 * @return The value stored in the register.
 */
int AbstractMemory::read(int regv) {
  Register& reg = getRegister(regv);
  return reg.getValue();
}


/**
 * @brief Write a value to a register.
 * @param regv The register number to write to.
 * @param value The value to write into the register.
 */
void AbstractMemory::write(int regv, int value) {
  Register& reg = getRegister(regv);
  reg.setValue(value);
}


/**
 * @brief Read a value from a vector register at a specific index.
 * @param regv The register number to read from.
 * @param index The index within the vector register to read.
 * @return The value stored at the specified index in the vector register.
 * @throws InvalidOperandException if the register is not a vector register.
 */
int AbstractMemory::read(int regv, int index) {
  Register& reg = getRegister(regv);
  if (!reg.isVector()) {
    throw InvalidOperandException("Intento de acceso indexado a un registro no vectorial");
  }
  return reg.getValueAt(index);
}


/**
 * @brief Write a value to a vector register at a specific index.
 * @param regv The register number to write to.
 * @param index The index within the vector register to write to.
 * @param value The value to write into the specified index of the vector register.
 * @throws InvalidOperandException if the register is not a vector register.
 */
void AbstractMemory::write(int regv, int index, int value) {
  Register& reg = getRegister(regv);
  if (!reg.isVector()) {
    throw InvalidOperandException("Intento de acceso indexado a un registro no vectorial");
  }
  reg.setValueAt(index, value);
}