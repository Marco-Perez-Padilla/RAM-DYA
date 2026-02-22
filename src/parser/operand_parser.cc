/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 2: Máquina RAM
** Autor: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es, alu0101485904@ull.edu.es
** Fecha: 22/02/2026
**
** Archivo operand_parser.cc: Implementación del parser de operandos.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "operand_parser.h"
#include "../exceptions/exceptions.h"
#include "../operand/constant_operand.h"
#include "../operand/direct_operand.h"
#include "../operand/indirect_operand.h"
#include "../operand/vector_direct_operand.h"
#include "../help/help_functions.h"
#include <regex>


/**
 * @brief Parses a string as an operand, which can be in the form of "=5", "3", "*2", or "1[2]"
 * @param token The string to parse
 * @return A unique pointer to the parsed Operand
 * @throws InvalidOperandException if the token is not a valid operand
 */
std::unique_ptr<Operand> OperandParser::parse(const std::string& tokenv) {
  std::string token = trim(tokenv);
  if (token.empty()) {
    throw InvalidOperandException("empty token");
  }

  // cte: =num
  if (token[0] == '=') {
    std::string num_string = token.substr(1);
    if (!isInteger(num_string)) {
      throw InvalidOperandException("invalid constant: " + token);
    }
    int value = std::stoi(num_string);
    return std::make_unique<ConstantOperand>(value);
  }

  // indirect: *num
  if (token[0] == '*') {
    std::string num_string = token.substr(1);
    if (!isInteger(num_string)) {
      throw InvalidOperandException("invalid indirect operand: " + token);
    }
    int reg = std::stoi(num_string);
    return std::make_unique<IndirectOperand>(reg);
  }

  // vector: num1[num2] or num1[op]
  std::regex vector_regex(R"(^(\d+)\[(.*)\]$)");
  std::smatch match;
  if (std::regex_match(token, match, vector_regex)) {
    int base = std::stoi(match[1]);     // num1
    std::string index_str = match[2];   // num2 o op
    // Parse the index operand (recursively, should be allowing combinations)
    auto index_operand = parse(index_str);
    return std::make_unique<VectorDirectOperand>(base, std::move(index_operand));
  }

  // direct: (num)
  if (isInteger(token)) {
    int reg = std::stoi(token);
    return std::make_unique<DirectOperand>(reg);
  }

  throw InvalidOperandException(token);
}