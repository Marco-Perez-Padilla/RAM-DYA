/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 2: Máquina RAM
** Autor: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es
** Fecha: 21/02/2026

** Archivo vector_direct_operand.h: Archivo de la clase especifica de operando directo de vector
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef VECTOR_DIRECT_OPERAND_H
#define VECTOR_DIRECT_OPERAND_H

#include "operand.h"

class VectorDirectOperand : public Operand {
 public:
  VectorDirectOperand(int baseRegister, std::unique_ptr<Operand> index);
  int getValue(ExecutionContext& ctx) const override;
  void setValue(ExecutionContext& ctx, int value) override;
  OperandType getType() const override;
  bool isWritable() const override;

 private:
  int baseRegister_;
  std::unique_ptr<Operand> index_;  
};

#endif