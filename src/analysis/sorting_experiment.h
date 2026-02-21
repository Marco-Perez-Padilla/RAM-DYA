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

** Archivo sorting_experiment.h: Archivo de la clase que representa una tabla de experimentos de ordenación
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef SORTING_EXPERIMENT_H
#define SORTING_EXPERIMENT_H

#include <string>
#include <vector>

class SortingExperiment {
 public:
  void runInsertionSort(const std::vector<int>& sizes);
  void runBubbleSort(const std::vector<int>& sizes);
  void compareAndReport(const std::string& filename);
};

#endif