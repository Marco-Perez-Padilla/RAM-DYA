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
** Archivo register_memory.cc: Implementación de la memoria de registros.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "register_memory.h"
#include "scalar_register.h"
#include "vector_register.h"
#include "../exceptions/exceptions.h"
#include <utility>


/**
 * @brief Get a reference to a register by its number. If the register does not exist, it is created as a scalar register.
 * @param reg The register number to retrieve.
 * @return A reference to the requested register.
 */
Register& RegisterMemory::getRegister(int reg) {
  auto it = registers_.find(reg);
  if (it != registers_.end()) {
    return *(it->second);
  }
  createRegister(reg, false);
  return *(registers_[reg]);
}


/**
 * @brief Check if a register exists in memory.
 * @param reg The register number to check.
 * @return True if the register exists, false otherwise.
 */
bool RegisterMemory::hasRegister(int reg) const {
  return registers_.find(reg) != registers_.end();
}


/**
 * @brief Create a new register in memory.
 * @param reg The register number to create.
 * @param vector If true, creates a vector register; otherwise, creates a scalar register.
 * @throws Exceptions if the register already exists.
 */
void RegisterMemory::createRegister(int reg, bool vector) {
  if (hasRegister(reg)) {
    throw Exceptions("El registro ya existe");
  }
  std::unique_ptr<Register> newReg;
  if (vector) {
    newReg = std::make_unique<VectorRegister>();
  } else {
    newReg = std::make_unique<ScalarRegister>();
  }
  registers_[reg] = std::move(newReg);
}