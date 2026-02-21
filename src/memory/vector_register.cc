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

VectorRegister::VectorRegister(const std::vector<int>& data) : data_(data) {}

int VectorRegister::getValue() const {
  throw InvalidOperandException("Intento de acceso escalar a un registro vectorial");
}

void VectorRegister::setValue(int value) {
  throw InvalidOperandException("Intento de acceso escalar a un registro vectorial");
}

int VectorRegister::getValueAt(int index) const {
  if (index < 0 || index >= static_cast<int>(data_.size())) {
    throw InvalidOperandException("Índice fuera de rango en registro vectorial");
  }
  return data_[index];
}

void VectorRegister::setValueAt(int index, int value) {
  if (index < 0) {
    throw InvalidOperandException("Índice negativo en registro vectorial");
  }
  if (index >= static_cast<int>(data_.size())) {
    data_.resize(index + 1, 0);
  }
  data_[index] = value;
}

bool VectorRegister::isVector() const {
  return true;
}