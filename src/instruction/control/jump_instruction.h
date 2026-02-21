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

** Archivo jump_instruction.h: Archivo de la clase que representa una instrucción de salto incondicional
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef JUMP_INSTRUCTION_H
#define JUMP_INSTRUCTION_H

#include "jump_instruction_base.h"

class JumpInstruction : public JumpInstructionBase {
 public:
  JumpInstruction(int line, const std::string& label)
      : JumpInstructionBase(line, label) {}
  void execute(ExecutionContext& ctx) override;
};

#endif