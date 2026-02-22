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

** Archivo direct_operand.h: Archivo de la clase especifica de operando directo
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef DIRECT_OPERAND_H
#define DIRECT_OPERAND_H

#include "operand.h"

class DirectOperand : public Operand {
 public:
  explicit DirectOperand(int registerIndex);  
  int getRegisterIndex() const { return registerIndex_; }
  int getValue(ExecutionContext& ctx) const override;
  void setValue(ExecutionContext& ctx, int value) override;
  OperandType getType() const override;
  bool isWritable() const override;

 private:
  int registerIndex_;
};

#endif