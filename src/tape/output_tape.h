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

** Archivo output_tape.h: Archivo de la clase abstracte para la cinta de salida
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef OUTPUT_TAPE_H
#define OUTPUT_TAPE_H

#include "tape.h"

class OutputTape : public Tape {
 public:
  OutputTape();
  bool hasNext() const override; // exception
  int read() override; // exception
  void write(int value) override;
  void reset() override;
  const std::vector<int>& getData() const;
 private:
  std::vector<int> data_;
};

#endif