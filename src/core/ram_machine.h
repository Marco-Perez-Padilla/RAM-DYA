/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 2: Máquina RAM
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 21/02/2026

** Archivo ram_machine.h: Archivo de la clase que representa una máquina RAM
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef RAM_MACHINE_H
#define RAM_MACHINE_H

#include <string>
#include <vector>
#include <memory>
#include "../core/execution_context.h"
#include "../core/instruction_executor.h"
#include "../memory/register_memory.h"
#include "../tape/input_tape.h"
#include "../tape/output_tape.h"
#include "../parser/label_table.h"

class RAMMachine {
 public:
  RAMMachine();
  void loadProgram(const std::string& progFile);
  void loadInputTape(const std::string& inputFile);
  void setOutputFile(const std::string& outputFile);
  void run();
  int getStepCount() const { return steps_; }

 private:
  std::vector<std::unique_ptr<Instruction>> program_;
  LabelTable labels_;
  RegisterMemory memory_;
  InputTape inputTape_;
  OutputTape outputTape_;
  std::string outputFile_;
  int steps_ = 0;
};

#endif