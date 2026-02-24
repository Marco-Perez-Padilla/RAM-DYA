/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 2: Máquina RAM
** Autor: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es, alu0101485904@ull.edu.es
** Fecha: 24/02/2026

** Archivo exp_instruction.h: Archivo de la clase que representa una instrucción de exponencial
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      24/02/2026 - Creacion (primera version) del codigo
**/

#ifndef EXP_INSTRUCTION_H
#define EXP_INSTRUCTION_H

#include "arithmetic_instruction.h"

class ExpInstruction : public ArithmeticInstruction {
 public:
  ExpInstruction(int line, std::unique_ptr<Operand> operand)
      : ArithmeticInstruction(line, std::move(operand)) {}
  void execute(ExecutionContext& ctx) override;
};

#endif