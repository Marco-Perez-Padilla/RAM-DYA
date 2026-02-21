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

** Archivo instruction_factory.h: Archivo de la clase que representa las construcciones de las instrucciones
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef INSTRUCTION_FACTORY_H
#define INSTRUCTION_FACTORY_H

#include <memory>
#include <string>
#include "instruction.h"
#include "../operand/operand.h"

class InstructionFactory {
 public:
  // Crea una instrucción a partir del opcode, el operando (puede ser nullptr), una etiqueta (para saltos) y el número de línea.
  static std::unique_ptr<Instruction> create(const std::string& opcode, std::unique_ptr<Operand> operand, int line, const std::string& label = ""); // InvalidInstruction
};

#endif