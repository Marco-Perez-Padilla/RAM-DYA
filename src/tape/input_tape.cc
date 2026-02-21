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
** Archivo input_tape.cc: Implementación de la cinta de entrada.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "input_tape.h"
#include "../exceptions/exceptions.h"


/**
 * @brief Constructor of the InputTape class
 * @param data Vector of integers to initialize the input tape with
 */
InputTape::InputTape(const std::vector<int>& data) : data_(data), pos_(0) {}


/**
 * @brief Checks if there are more values to read on the input tape
 * @return true if there are more values to read, false otherwise
 */
bool InputTape::hasNext() const {
  return pos_ < data_.size();
}


/**
 * @brief Reads the next value from the input tape
 * @return The next integer value on the tape
 * @throws OutOfTapeException if there are no more values to read
 */
int InputTape::read() {
  if (!hasNext()) {
    throw OutOfTapeException();
  }
  return data_[pos_++];
}


/**
 * @brief Attempting to write on the input tape throws an exception
 * @param value The value to write (not used)
 * @throws WriteOnInputTapeException always, since writing on the input tape is not allowed
 */
void InputTape::write(int value) {
  throw WriteOnInputTapeException();
}


/**
 * @brief Resets the input tape to the beginning
 */
void InputTape::reset() {
  pos_ = 0;
}