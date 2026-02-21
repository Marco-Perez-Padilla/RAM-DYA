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

** Archivo abstract_instruction.h: Archivo de la clase que representa una instrucción abstracta
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef ABSTRACT_INSTRUCTION_H
#define ABSTRACT_INSTRUCTION_H

#include "instruction.h"

class AbstractInstruction : public Instruction {
 public:
  explicit AbstractInstruction(int line) : line_(line) {}
  int getLine() const override { return line_; }
 private:
  int line_;
};

#endif