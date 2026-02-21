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

** Archivo abstract_instruction.h: Archivo de la clase que representa una instrucción aritmética
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef ARITHMETIC_INSTRUCTION_H
#define ARITHMETIC_INSTRUCTION_H

#include "../instruction_with_operand.h"
#include "../../operand/operand.h"
#include <memory>

class ArithmeticInstruction : public InstructionWithOperand {
 public:
  ArithmeticInstruction(int line, std::unique_ptr<Operand> operand)
        : InstructionWithOperand(line, std::move(operand)) {}
  virtual ~ArithmeticInstruction() = default;
 protected:
  std::unique_ptr<Operand> operand_;
};

#endif