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
** Archivo program_parser.cc: Implementación del parser de programas.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "program_parser.h"
#include "instruction_parser.h"
#include "../file_manager/file_manager.h"
#include "../instruction/instruction_factory.h"
#include "../exceptions/exceptions.h"
#include <vector>
#include <memory>


/**
 * @brief Loads a program from a file, ignoring comments and empty lines.
 * @param filename The name of the file to load
 * @return A pair containing the vector of instructions and the label table
 * @throws EmptyFileException if the file is empty or has no valid content
 */
std::pair<std::vector<std::unique_ptr<Instruction>>, LabelTable> ProgramParser::parse(const std::string& filename) {

  std::vector<std::string> lines = FileManager::readProgramFile(filename);
  if (lines.empty()) {
    throw EmptyFileException(filename);
  }

  LabelTable label_table;

  std::vector<ParsedInstruction> parsed_instructions;
  std::vector<int> line_numbers;

  // First pass: parse lines and build label table
  for (size_t i = 0; i < lines.size(); ++i) {
    int line_num = i + 1;

    ParsedInstruction parsed = InstructionParser::parse(lines[i], line_num);

    if (!parsed.label.empty()) {
      label_table.addLabel(parsed.label, parsed_instructions.size());
    }

    if (!parsed.opcode.empty()) {
      parsed_instructions.push_back(std::move(parsed));
      line_numbers.push_back(line_num);
    }
  }

  // Second pass: create instruction objects
  std::vector<std::unique_ptr<Instruction>> program;

  for (size_t i = 0; i < parsed_instructions.size(); ++i) {
    auto& parsed = parsed_instructions[i];
    int line_num = line_numbers[i];

    auto instr = InstructionFactory::create(parsed.opcode, std::move(parsed.operand), line_num, parsed.jump_label);

    program.push_back(std::move(instr));
  }

  return {std::move(program), std::move(label_table)};
}