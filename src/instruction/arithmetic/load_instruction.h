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

** Archivo load_instruction.h: Archivo de la clase que representa una instrucción de carga
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef LOAD_INSTRUCTION_H
#define LOAD_INSTRUCTION_H

#include "arithmetic_instruction.h"

class LoadInstruction : public ArithmeticInstruction {
 public:
  LoadInstruction(int line, std::unique_ptr<Operand> operand)
      : ArithmeticInstruction(line, std::move(operand)) {}
  void execute(ExecutionContext& ctx) override;
};

#endif