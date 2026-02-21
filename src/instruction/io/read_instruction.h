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

** Archivo read_instruction.h: Archivo de la clase que representa una instrucción de lectura
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef READ_INSTRUCTION_H
#define READ_INSTRUCTION_H

#include "io_instruction.h"

class ReadInstruction : public IOInstruction {
 public:
  ReadInstruction(int line, std::unique_ptr<Operand> operand)
      : IOInstruction(line, std::move(operand)) {}
  void execute(ExecutionContext& ctx) override;
};

#endif