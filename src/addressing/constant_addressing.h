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

** Archivo constant_addressing.h: Archivo de la clase especifica de direccionamiento constante
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef CONSTANT_ADDRESSING_H
#define CONSTANT_ADDRESSING_H

#include "addressing_mode.h"

class ConstantAddressing : public AddressingMode {
 public:
  int getValue(ExecutionContext& ctx, int argument) const override;
  int getAddress(ExecutionContext& ctx, int argument) const override;
  bool isWritable() const override;
};

#endif