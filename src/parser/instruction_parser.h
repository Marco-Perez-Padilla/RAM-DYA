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

** Archivo instruction_parser.h: Archivo de la clase que representa un parser de instrucciones
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef INSTRUCTION_PARSER_H
#define INSTRUCTION_PARSER_H

#include <string>
#include <memory>
#include "../instruction/instruction.h"
#include "../operand/operand.h"

struct ParsedInstruction {
  std::string label;
  std::string opcode;
  std::unique_ptr<Operand> operand;  
  std::string jump_label;
  int line_number;
};

class InstructionParser {
 public:
  // Parsea una línea de programa sin comentarios y devuelve una estructura ParsedInstruction.
  static ParsedInstruction parse(const std::string& line, int line_umber); // InvalidInstruction
};

#endif