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

** Archivo label_table.h: Archivo de la clase que representa una tabla de etiquetas
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef LABEL_TABLE_H
#define LABEL_TABLE_H

#include <string>
#include <unordered_map>
#include <stdexcept>

class LabelTable {
 public:
  void addLabel(const std::string& label, int address);
  int getAddress(const std::string& label) const;
  bool contains(const std::string& label) const;
 private:
  std::unordered_map<std::string, int> table_;
};

#endif