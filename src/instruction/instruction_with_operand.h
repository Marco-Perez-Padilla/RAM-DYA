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

** Archivo instruction_with_operand.h: Clase intermedia para trabajar con instrucciones que tienen un operando
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef INSTRUCTION_WITH_OPERAND_H
#define INSTRUCTION_WITH_OPERAND_H

#include "abstract_instruction.h"
#include "../operand/operand.h"
#include <memory>

class InstructionWithOperand : public AbstractInstruction {
 public:
  InstructionWithOperand(int line, std::unique_ptr<Operand> operand)
      : AbstractInstruction(line), operand_(std::move(operand)) {}
  virtual ~InstructionWithOperand() = default;

 protected:
  std::unique_ptr<Operand> operand_;
};

#endif