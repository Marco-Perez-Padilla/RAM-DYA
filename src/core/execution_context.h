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

** Archivo execution_context.h: Archivo de la clase que representa un contexto de ejecución
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef EXECUTION_CONTEXT_H
#define EXECUTION_CONTEXT_H

#include <memory>
#include "../memory/abstract_memory.h"
#include "../tape/input_tape.h"
#include "../tape/output_tape.h"
#include "../parser/label_table.h"

class ExecutionContext {
 public:
  ExecutionContext(AbstractMemory& mem, InputTape& input, OutputTape& output, LabelTable& labels);
    
  int& accumulator() { return acc_; }
  int accumulator() const { return acc_; }
    
  int& pc() { return pc_; }
  int pc() const { return pc_; }
    
  AbstractMemory& memory() { return memory_; }
    
  InputTape& input() { return input_; }
  OutputTape& output() { return output_; }
    
  LabelTable& labels() { return labels_; }
    
  int& steps() { return steps_; }
  int steps() const { return steps_; }
    
 private:
  AbstractMemory& memory_;
  InputTape& input_;
  OutputTape& output_;
  LabelTable& labels_;
  int acc_ = 0;
  int pc_ = 0;  
  int steps_ = 0;
};

#endif