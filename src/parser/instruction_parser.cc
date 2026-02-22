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
** Archivo instruction_parser.cc: Implementación del parser de instrucciones.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "instruction_parser.h"
#include "operand_parser.h"
#include "../exceptions/exceptions.h"
#include "../help/help_functions.h"


/**
 * @brief Parses a line of program (without comments) and returns a ParsedInstruction structure.
 * @param line The line to parse
 * @param line_number The original line number in the source file (for error reporting)
 * @return A ParsedInstruction structure containing the parsed components of the instruction
 * @throws ProgramSyntaxException if the line cannot be parsed as a valid instruction
 */
ParsedInstruction InstructionParser::parse(const std::string& line, int line_number) {
  std::string trimmed = trim(line);
  if (trimmed.empty()) {
    throw ProgramSyntaxException("empty line", line_number);
  }

  auto tokens = tokenize(trimmed);
  if (tokens.empty()) {
    throw ProgramSyntaxException("empty line", line_number);
  }

  ParsedInstruction result;
  result.line_number = line_number;
  result.operand = nullptr;
  result.jump_label = "";

  // If first token ends with ':' then it is jump label
  if (tokens[0].back() == ':') {
    result.label = tokens[0].substr(0, tokens[0].size() - 1);
    if (result.label.empty()) {
      throw ProgramSyntaxException("empty label", line_number);
    }
    tokens.erase(tokens.begin());
    if (tokens.empty()) {
      throw ProgramSyntaxException("label without instruction", line_number);
    }
  } else {
    result.label = "";
  }

  // Next token: Opcode
  result.opcode = tokens[0];
  tokens.erase(tokens.begin());

  // No more tokens: No operands needed instructions
  if (tokens.empty()) {
    return result;
  }

  //One more token: Operand or jump label
  if (isJumpOpcode(result.opcode)) {
    result.jump_label = tokens[0];
    if (tokens.size() > 1) {
      throw ProgramSyntaxException("extra tokens after jump label", line_number);
    }
  } else {
    std::string operand_string;
    for (size_t i = 0; i < tokens.size(); ++i) {
      if (i > 0) operand_string += " ";
      operand_string += tokens[i];
    }

    try {
      // Parse the operand
      result.operand = OperandParser::parse(operand_string);
    } catch (const InvalidOperandException& error) {
      throw ProgramSyntaxException(std::string("invalid operand: ") + error.what(), line_number);
    }
  }

  return result;
}