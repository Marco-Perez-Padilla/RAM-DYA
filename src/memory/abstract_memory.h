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

** Archivo abstract_memory.h: Archivo de la clase para l interfaz que representa la memoria
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef ABSTRACT_MEMORY_H
#define ABSTRACT_MEMORY_H

#include <memory>     // std::unique_ptr
#include "register.h"

class AbstractMemory {
 public:
  virtual ~AbstractMemory() = default;
  virtual Register& getRegister(int reg) = 0; 
  virtual bool hasRegister(int reg) const = 0;
  int read(int reg);
  void write(int reg, int value);
  int read(int reg, int index);
  void write(int reg, int index, int value);
 protected:
  virtual void createRegister(int reg, bool vector = false) = 0;
};

#endif