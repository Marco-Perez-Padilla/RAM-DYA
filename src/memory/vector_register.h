/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 2: Máquina RAM
** Autor: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es
** Fecha: 21/02/2026

** Archivo vector_register.h: Archivo de la clase para registros vectoriales
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef VECTOR_REGISTER_H
#define VECTOR_REGISTER_H

#include "register.h"

class VectorRegister : public Register {
 public:
  VectorRegister() = default;
  explicit VectorRegister(const std::vector<int>& data);
  int getValue() const override; // exception
  void setValue(int value) override; // exception
  int getValueAt(int index) const override;
  void setValueAt(int index, int value) override;
  bool isVector() const override;
private:
  std::vector<int> data_;
};

#endif