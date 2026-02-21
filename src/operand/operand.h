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

** Archivo operand.h: Archivo de la clase que representa un operando
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef OPERAND_H
#define OPERAND_H

#include <memory>
#include "../exceptions/exceptions.h"

class ExecutionContext;

enum class OperandType {
  CONSTANT,
  DIRECT,
  INDIRECT,
  VECTOR_DIRECT
};

class Operand {
 public:
  virtual ~Operand() = default;
  virtual int getValue(ExecutionContext& ctx) const = 0;
  virtual void setValue(ExecutionContext& ctx, int value) = 0; // exception
  virtual OperandType getType() const = 0;
  virtual bool isWritable() const = 0;
};

#endif