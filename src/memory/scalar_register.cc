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

int ScalarRegister::getValue() const {
  return value_;
}

void ScalarRegister::setValue(int value) {
  value_ = value;
}

int ScalarRegister::getValueAt(int index) const {
  throw InvalidOperandException("Intento de acceso indexado a un registro escalar");
}

void ScalarRegister::setValueAt(int index, int value) {
  throw InvalidOperandException("Intento de acceso indexado a un registro escalar");
}

bool ScalarRegister::isVector() const {
  return false;
}