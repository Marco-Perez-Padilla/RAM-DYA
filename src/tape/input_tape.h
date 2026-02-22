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

** Archivo input_tape.h: Archivo de la clase abstracte para la cinta de entrada
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef INPUT_TAPE_H
#define INPUT_TAPE_H

#include <vector>
#include "tape.h"

class InputTape : public Tape {
 public:
  InputTape() : data_(), pos_(0) {}
  explicit InputTape(const std::vector<int>& data);
  bool hasNext() const override;
  int read() override;
  void write(int value) override; // exception
  void reset() override;
 private:
  std::vector<int> data_;
  unsigned int pos_;
};

#endif