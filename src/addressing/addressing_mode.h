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

** Archivo addressing_mode.h: Archivo de la clase interfaz de direccionamientos
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef ADDRESSING_MODE_H
#define ADDRESSING_MODE_H

#include <memory>

class ExecutionContext;

class AddressingMode {
 public:
  virtual ~AddressingMode() = default;
  virtual int getValue(ExecutionContext& ctx, int argument) const = 0; // InvalidOperand
  virtual int getAddress(ExecutionContext& ctx, int argument) const = 0; // InvalidOperand
  virtual bool isWritable() const = 0;
};

#endif