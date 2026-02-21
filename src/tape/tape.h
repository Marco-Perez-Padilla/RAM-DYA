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

** Archivo tape.h: Archivo de la interfaz Tape
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef TAPE_H
#define TAPE_H

#include <vector>
#include "../exceptions/exceptions.h"

class Tape {
 public:
  virtual ~Tape() = default;
  virtual bool hasNext() const = 0;
  virtual int read() = 0;  
  virtual void write(int value) = 0;
  virtual void reset() = 0;
};

#endif