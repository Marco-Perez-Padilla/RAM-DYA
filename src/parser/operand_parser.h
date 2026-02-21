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

** Archivo operand_parser.h: Archivo de la clase que representa un parser de operandos
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef OPERAND_PARSER_H
#define OPERAND_PARSER_H

#include <string>
#include <memory>
#include "../operand/operand.h"

class OperandParser {
 public:
  // Parsea un string como "=5", "3", "*2", o "1[2]" y devuelve un unique_ptr<Operand>
  static std::unique_ptr<Operand> parse(const std::string& token); // invalidOperand
};

#endif