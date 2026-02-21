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

** Archivo program_counter.h: Archivo de la clase que representa un contador de programa
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef PROGRAM_COUNTER_H
#define PROGRAM_COUNTER_H

class ProgramCounter {
 public:
  ProgramCounter() : address_(0) {}
  unsigned int get() const { return address_; }
  void next() { ++address_; }
  void jump(unsigned int addr) { address_ = addr; }
  void reset() { address_ = 0; }

 private:
  unsigned int address_;
};

#endif