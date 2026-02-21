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
** Archivo label_table.cc: Implementación de la tabla de etiquetas.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "label_table.h"
#include "../exceptions/exceptions.h"


/**
 * @brief Agrega una etiqueta a la tabla con su dirección correspondiente
 * @param label La etiqueta a agregar
 * @param address La dirección a la que apunta la etiqueta
 */
void LabelTable::addLabel(const std::string& label, int address) {
  table_[label] = address;
}


/**
 * @brief Obtiene la dirección asociada a una etiqueta
 * @param label La etiqueta a buscar
 * @return La dirección asociada a la etiqueta
 * @throws UndefinedLabelException Si la etiqueta no está definida en la tabla
 */
int LabelTable::getAddress(const std::string& label) const {
  auto it = table_.find(label);
  if (it == table_.end()) {
    throw UndefinedLabelException(label);
  }
  return it->second;
}


/**
 * @brief Verifica si una etiqueta está definida en la tabla
 * @param label La etiqueta a verificar
 * @return true si la etiqueta está definida, false en caso contrario
 */
bool LabelTable::contains(const std::string& label) const {
  return table_.find(label) != table_.end();
}