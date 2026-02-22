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
** Archivo ram_machine.cc: Implementación de la máquina RAM.
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      22/02/2026 - Creación (primera versión)
**/

#include "ram_machine.h"
#include "../file_manager/file_manager.h"
#include "../parser/program_parser.h"
#include "instruction_executor.h"
#include "../exceptions/exceptions.h"
#include <iostream>
#include <memory>


/**
 * @brief Loads a RAM program from a file, parsing it and storing the instructions and labels.
 * @param progFile The filename of the RAM program to load.
 * @throws Exceptions if there is an error loading or parsing the program file.
 */
void RAMMachine::loadProgram(const std::string& progFile) {
  try {
    auto [prog, lblTable] = ProgramParser::parse(progFile);
    program_ = std::move(prog);
    labels_ = std::move(lblTable);
  } catch (const Exceptions& error) {
    std::cerr << "Error loading program: " << error.what() << std::endl;
    throw;
  }
}


/**
 * @brief Loads input data for the RAM machine from a file, initializing the input tape.
 * @param inputFile The filename of the input tape data to load.
 * @throws Exceptions if there is an error loading the input tape file.
 */
void RAMMachine::loadInputTape(const std::string& inputFile) {
  try {
    auto data = FileManager::readInputTape(inputFile);
    inputTape_ = InputTape(data);
    } catch (const Exceptions& error) {
    std::cerr << "Error loading input tape: " << error.what() << std::endl;
    throw;
  }
}


/**
 * @brief Sets the output file where the RAM machine will write its output tape data after execution.
 * @param outputFile The filename of the output file to write the output tape data to.
 */
void RAMMachine::setOutputFile(const std::string& outputFile) {
  outputFile_ = outputFile;
}


/**
 * @brief Executes the loaded RAM program, managing the execution context and handling any runtime exceptions.
 * After execution, it writes the output tape data to the specified output file if one was set
 */
void RAMMachine::run() {
  if (program_.empty()) {
    std::cerr << "No program loaded." << std::endl;
    return;
  }

  ExecutionContext context(memory_, inputTape_, outputTape_, labels_);

  try {
    InstructionExecutor::execute(program_, context);
    steps_ = context.steps();
    std::cout << "Program finished successfully. Steps: " << steps_ << std::endl;
  } catch (const Exceptions& error) {
    std::cerr << "Runtime error at line " << context.pc() << ": " << error.what() << std::endl;
  }

  if (!outputFile_.empty()) {
    try {
      FileManager::writeOutputTape(outputFile_, outputTape_.getData());
    } catch (const Exceptions& e) {
      std::cerr << "Error writing output tape: " << e.what() << std::endl;
    }
  }
}