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

** Archivo instruction.h: Archivo de la clase que representa una instrucción
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../core/execution_context.h"

class Instruction {
 public:
  virtual ~Instruction() = default;
  virtual void execute(ExecutionContext& ctx) = 0;
};

#endif