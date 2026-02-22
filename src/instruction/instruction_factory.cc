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
** Archivo instruction_factory.cc: Implementación de la factoría de instrucciones.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/02/2026 - Creacion (primera version) del codigo
**/

#include "instruction_factory.h"
#include "../exceptions/exceptions.h"
#include "../help/help_functions.h"
#include "../operand/direct_operand.h"
#include "arithmetic/add_instruction.h"
#include "arithmetic/sub_instruction.h"
#include "arithmetic/mul_instruction.h"
#include "arithmetic/div_instruction.h"
#include "arithmetic/load_instruction.h"
#include "arithmetic/store_instruction.h"
#include "io/read_instruction.h"
#include "io/write_instruction.h"
#include "control/halt_instruction.h"
#include "control/jump_instruction.h"
#include "control/jump_zero_instruction.h"
#include "control/jump_greater_zero_instruction.h"
#include <memory>


/**
 * @brief Auxiliary function to check if an operand is a direct reference to R0, which is not allowed for certain instructions
 * @param operand The operand to check
 * @return true if the operand is a direct reference to R0, false otherwise
 */
bool isDirectR0(Operand* operand) {
  if (!operand) return false;
  if (operand->getType() != OperandType::DIRECT) return false;
  DirectOperand* dir = dynamic_cast<DirectOperand*>(operand);
  return dir && dir->getRegisterIndex() == 0;
}


/**
 * @brief Factory method to create an instruction based on the opcode, operand, line number, and optional label
 * @param opcode The opcode of the instruction (e.g., "LOAD", "ADD", "JUMP")
 * @param operand A unique pointer to the operand (can be nullptr if the instruction does not require one)
 * @param line The line number of the instruction in the source code
 * @param label An optional label for jump instructions (default is an empty string)
 * @return A unique pointer to the created Instruction object
 * @throws InvalidInstructionException if the opcode is not recognized or if the instruction format is invalid
 * @throws IncompatibleOperandException if the operand type is not compatible with the instruction
 * @throws InvalidR0OperandException if the instruction cannot use R0 as an operand but
 */
std::unique_ptr<Instruction> InstructionFactory::create( const std::string& opcode, std::unique_ptr<Operand> operand, int line, const std::string& label) {
  std::string op = toUpper(opcode);

  // HALT
  if (op == "HALT") {
    if (operand || !label.empty()) {
      throw InvalidInstructionException(opcode + " with operand or label", line);
    }
    return std::make_unique<HaltInstruction>(line);
  }

  // Jumps (control)
  if (op == "JUMP" || op == "JZERO" || op == "JGTZ") {
    if (operand || label.empty()) {
      throw InvalidInstructionException(opcode + " requires a label", line);
    }
    if (op == "JUMP") return std::make_unique<JumpInstruction>(line, label);
    if (op == "JZERO") return std::make_unique<JumpZeroInstruction>(line, label);
    if (op == "JGTZ") return std::make_unique<JumpGreaterZeroInstruction>(line, label);
  }

  if (!operand) {
    throw InvalidInstructionException(opcode + " requires an operand", line);
  }

  // Store or IO
  if (op == "STORE" || op == "READ" || op == "WRITE") {
    if (operand->getType() == OperandType::CONSTANT) {
      throw IncompatibleOperandException(opcode, "constant");
    }
  }

  // IO
  if (op == "READ" || op == "WRITE") {
    if (isDirectR0(operand.get())) {
      throw InvalidR0OperandException(opcode);
    }
  }

  // Arithmetic and Load/Store
  if (op == "LOAD") return std::make_unique<LoadInstruction>(line, std::move(operand));
  if (op == "STORE") return std::make_unique<StoreInstruction>(line, std::move(operand));
  if (op == "ADD") return std::make_unique<AddInstruction>(line, std::move(operand));
  if (op == "SUB") return std::make_unique<SubInstruction>(line, std::move(operand));
  if (op == "MUL") return std::make_unique<MulInstruction>(line, std::move(operand));
  if (op == "DIV") return std::make_unique<DivInstruction>(line, std::move(operand));
  if (op == "READ") return std::make_unique<ReadInstruction>(line, std::move(operand));
  if (op == "WRITE") return std::make_unique<WriteInstruction>(line, std::move(operand));

  throw InvalidInstructionException(opcode, line);
}