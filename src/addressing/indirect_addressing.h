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

** Archivo indirect_addressing.h: Archivo de la clase especifica de direccionamiento indirecto
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef INDIRECT_ADDRESSING_H
#define INDIRECT_ADDRESSING_H

#include "addressing_mode.h"

class IndirectAddressing : public AddressingMode {
 public:
  int getValue(ExecutionContext& ctx, int argument) const override;
  int getAddress(ExecutionContext& ctx, int argument) const override;
  bool isWritable() const override;
};

#endif