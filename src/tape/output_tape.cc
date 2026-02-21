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
** Archivo output_tape.cc: Implementación de la cinta de salida.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "output_tape.h"
#include "../exceptions/exceptions.h"


/**
 * @brief Constructor of the OutputTape class
 */
OutputTape::OutputTape() : data_() {}


/**
 * @brief The output tape does not support reading, so hasNext always returns false
 * @return false always, since the output tape cannot be read from
 */
bool OutputTape::hasNext() const {
  return false;
}


/**
 * @brief Attempting to read from the output tape throws an exception
 * @return This function does not return, since it always throws an exception
 * @throws ReadOnOutputTapeException always, since reading from the output tape is not allowed
 */
int OutputTape::read() {
  throw ReadOnOutputTapeException();
}


/**
 * @brief Writes a value to the output tape by appending it to the data vector
 * @param value The integer value to write to the tape
 */
void OutputTape::write(int value) {
  data_.push_back(value);
}


/**
 * @brief Resets the output tape by clearing the data vector
 */
void OutputTape::reset() {
  data_.clear();
}


/**
 * @brief Returns a const reference to the vector of integers stored on the output tape
 * @return A const reference to the data vector containing the values written to the tape
 */
const std::vector<int>& OutputTape::getData() const {
  return data_;
}