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

** Archivo io_instruction.h: Archivo de la clase que representa una instrucción de entrada/salida
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef IO_INSTRUCTION_H
#define IO_INSTRUCTION_H

#include "../instruction_with_operand.h"

class IOInstruction : public InstructionWithOperand {
 public:
  IOInstruction(int line, std::unique_ptr<Operand> operand)
      : InstructionWithOperand(line, std::move(operand)) {}
  virtual ~IOInstruction() = default;
};

#endif