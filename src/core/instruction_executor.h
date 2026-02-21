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

** Archivo instruction_executor.h: Archivo de la clase que ejecuta las instrucciones del contexto
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef INSTRUCTION_EXECUTOR_H
#define INSTRUCTION_EXECUTOR_H

#include <vector>
#include <memory>
#include "execution_context.h"
#include "../instruction/instruction.h"

class InstructionExecutor {
 public:
  static void execute(const std::vector<std::unique_ptr<Instruction>>& program, ExecutionContext& context);
};

#endif