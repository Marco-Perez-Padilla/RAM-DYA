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
** Archivo instruction_executor.cc: Implementación del ejecutor de instrucciones.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "instruction_executor.h"
#include "../instruction/instruction.h"
#include "../exceptions/exceptions.h"
#include <iostream>
#include <vector>


/**
 * @brief Executes a program represented as a vector of unique pointers to Instructions, using the provided ExecutionContext
 * @param program The vector of unique pointers to Instructions that make up the program
 * @param context The ExecutionContext that holds the state of the machine (memory, input/output tapes, labels, registers, etc.)
 * @throws Exceptions if any instruction execution results in an error
 */
void InstructionExecutor::execute(const std::vector<std::unique_ptr<Instruction>>& program, ExecutionContext& context) {
  while (context.pc() >= 0 && context.pc() < static_cast<int>(program.size())) {
    try {
      Instruction& instr = *program[context.pc()];
      instr.execute(context);
    } catch (const HaltException&) {
      break;
    } catch (const Exceptions& error) {
      throw;
    }
  }
}