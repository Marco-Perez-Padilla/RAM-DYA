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

** Archivo program_parser.h: Archivo de la clase que representa el parser de programas
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef PROGRAM_PARSER_H
#define PROGRAM_PARSER_H

#include <string>
#include <vector>
#include <memory>
#include "../instruction/instruction.h"
#include "label_table.h"

class ProgramParser {
 public:
  // Carga un programa desde un archivo, ignorando comentarios y líneas vacías.
  static std::pair<std::vector<std::unique_ptr<Instruction>>, LabelTable> parse(const std::string& filename);
};

#endif