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
**
** Archivo complexity_counter.h: Clase para contabilizar el número de instrucciones ejecutadas.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef COMPLEXITY_COUNTER_H
#define COMPLEXITY_COUNTER_H

class ComplexityCounter {
 public:
  ComplexityCounter() : count_(0) {}
  void reset() { count_ = 0; }
  void increment() { ++count_; }
  int getCount() const { return count_; }

 private:
  int count_;
};

#endif