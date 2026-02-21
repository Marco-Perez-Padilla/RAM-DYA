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

** Archivo scalar_register.h: Archivo de la clase para registros escalares
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef SCALAR_REGISTER_H
#define SCALAR_REGISTER_H

#include "register.h"

class ScalarRegister : public Register {
 public:
  ScalarRegister(int value = 0);
  int getValue() const override;
  void setValue(int value) override;
  int getValueAt(int index) const override;
  void setValueAt(int index, int value) override;
  bool isVector() const override;
 private:
    int value_;
};

#endif