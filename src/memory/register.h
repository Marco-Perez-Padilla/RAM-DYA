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

** Archivo register.h: Archivo de la interfaz Register
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include "../exceptions/exceptions.h"

class Register {
public:
  virtual ~Register() = default;
  virtual int getValue() const = 0; // scalar
  virtual void setValue(int value) = 0; // scalar
  virtual int getValueAt(int index) const = 0; // vector
  virtual void setValueAt(int index, int value) = 0; // vector
  virtual bool isVector() const = 0;
};

#endif