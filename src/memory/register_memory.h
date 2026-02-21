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

** Archivo register_memory.h: Archivo de la clase que representa la memoria de registros
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef REGISTER_MEMORY_H
#define REGISTER_MEMORY_H

#include "abstract_memory.h"
#include <unordered_map>
#include <memory>

class RegisterMemory : public AbstractMemory {
 public:
  RegisterMemory() = default;
  virtual ~RegisterMemory() = default;
  Register& getRegister(int reg) override;
  bool hasRegister(int reg) const override;

 protected:
  void createRegister(int reg, bool vector = false) override;

 private:
  std::unordered_map<int, std::unique_ptr<Register>> registers_;
};

#endif