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
**
** Archivo file_manager.cc: Implementación de la gestión de archivos
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#include "file_manager.h"
#include "../exceptions/exceptions.h"
#include <fstream>
#include <sstream>
#include <iostream>


/**
 * @brief Read the program file and return its lines as a vector of strings.
 * @param filename Name of the file to read from.
 * @return Vector of strings containing the lines of the file.
 * @throw FileNotFoundException if the file cannot be opened.
 */
std::vector<std::string> FileManager::readProgramFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw FileNotFoundException(filename);
  }

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    // Delete comments and trim whitespace
    size_t commentPos = line.find('#');
    if (commentPos != std::string::npos) {
      line = line.substr(0, commentPos);
    }
    // Delete spaces and tabs from the beginning and end of the line
    line.erase(0, line.find_first_not_of(" \t"));
    line.erase(line.find_last_not_of(" \t") + 1);
    if (!line.empty()) {
      lines.push_back(line);
    }
  }

  return lines;
}


/**
 * @brief Read the input tape from a file.
 * @param filename Name of the file to read from.
 * @return Vector of integers read from the file.
 * @throw FileNotFoundException if the file cannot be opened.
 */
std::vector<int> FileManager::readInputTape(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw FileNotFoundException(filename);
  }

  std::vector<int> data;
  int value;
  while (file >> value) {
    data.push_back(value);
  }

  return data;
}


/**
 * @brief Write the output tape to a file.
 * @param filename Name of the file to write to.
 * @param data Vector of integers to write to the file.
 * @throw FileNotFoundException if the file cannot be opened for writing.
 */
void FileManager::writeOutputTape(const std::string& filename, const std::vector<int>& data) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    throw FileNotFoundException(filename);
  }

  for (size_t i = 0; i < data.size(); ++i) {
    file << data[i];
    if (i != data.size() - 1) file << "\n";
  }
}