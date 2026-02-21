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

** Archivo jump_instruction_base.h: Interfaz para representar instrucciones de salto
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef JUMP_INSTRUCTION_BASE_H
#define JUMP_INSTRUCTION_BASE_H

#include "../abstract_instruction.h"
#include <string>

class JumpInstructionBase : public AbstractInstruction {
 public:
  JumpInstructionBase(int line, const std::string& label)
      : AbstractInstruction(line), label_(label) {}
  virtual ~JumpInstructionBase() = default;
 protected:
  std::string label_;
};

#endif