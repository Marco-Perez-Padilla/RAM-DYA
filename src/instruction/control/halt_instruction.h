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

** Archivo halt_instruction.h: Archivo de la clase que representa una instrucción de parada
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef HALT_INSTRUCTION_H
#define HALT_INSTRUCTION_H

#include "../abstract_instruction.h"

class HaltInstruction : public AbstractInstruction {
 public:
  explicit HaltInstruction(int line) : AbstractInstruction(line) {}
  void execute(ExecutionContext& ctx) override;
};

#endif