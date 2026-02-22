/**
** Universidad de La Laguna
** Escuela Superior de Ingeniería y Tecnología
** Grado en Ingeniería Informática
** Asignatura: Diseño y Análisis de Algoritmos
** Curso: 3º
** Práctica 1: Complejidad Computacional
** Autor: Marco Pérez Padilla, Keran Miranda González
** Correo: alu0101469348@ull.edu.es, alu0101485904@ull.edu.es
** Fecha: 01/02/2026

** Archivo help.h: Funciones de ayuda
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      01/02/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "help_functions.h"

/**
 * @brief Prints Help to the user
 */
void Help() {
    std::cout << "MATRIXES MULTIPLIER" << std::endl;
    std::cout << "Generates matrices and multiplies them using different algorithms.\n" << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << "  --help        Show this help message" << std::endl;
    std::cout << "  Run the program without arguments to start the interactive menu." << std::endl;
    std::cout << std::endl;

    std::cout << "Interactive Menu:" << std::endl;
    std::cout << "  1. Square matrices  -> Choose size n x n and multiplication algorithm." << std::endl;
    std::cout << "  2. Custom matrices  -> Specify rows and columns for matrices A and B, then choose algorithm." << std::endl;
    std::cout << "  3. Quit             -> Exit the program." << std::endl;
    std::cout << std::endl;

    std::cout << "Algorithm Options:" << std::endl;
    std::cout << "  1. Multiplication by Rows" << std::endl;
    std::cout << "  2. Multiplication by Columns" << std::endl;
    std::cout << "  3. Run both algorithms" << std::endl;
    std::cout << "  0. Back to main menu" << std::endl;
    std::cout << std::endl;
}


/**
 * @brief Prints how to use the program
 */
void Usage() {
    std::cout << "How to use: ./matrixes_multiplier [--help]" << std::endl;
    std::cout << "Try './matrixes_multiplier --help' for more information." << std::endl;
}


/**
 * @brief Validates arguments given in CLI
 * @param argc
 * @param argv
 */
int ValidateArguments(int argc, char* argv[]) {
  if (argc == 1) return -1;
  if (argc == 2) {
    std::string arg1 = argv[1];
    if (arg1 == "--help" || arg1 == "-h") {
      Help();
      return 0;
    } else {
      Usage();
      return 1;
    }
  } else {
    Usage();
    return 1;
  }
}


/**
 * @brief Elimina espacios en blanco al inicio y final de una cadena.
 */
std::string trim(const std::string& string) {
  size_t start = string.find_first_not_of(" \t");
  if (start == std::string::npos) return "";
  size_t end = string.find_last_not_of(" \t");
  return string.substr(start, end - start + 1);
}

/**
 * @brief Checks if a string represents a valid integer 
 * @param string The string to check
 * @return true if the string is a valid integer, false otherwise
 */
bool isInteger(const std::string& string) {
  if (string.empty()) return false;

  size_t i = 0;
  if (string[0] == '-' || string[0] == '+') {
    if (string.length() == 1) return false;
    i = 1;
  }

  for (; i < string.length(); ++i) {
    if (!std::isdigit(string[i])) return false;
  }

  return true;
}


/**
 * @brief Divide una línea en tokens separados por espacios.
 */
std::vector<std::string> tokenize(const std::string& line) {
  std::vector<std::string> tokens;
  std::istringstream iss(line);
  std::string token;
  while (iss >> token) {
    tokens.push_back(token);
  }
  return tokens;
}

/**
 * @brief Convierte un string a mayúsculas.
 */
std::string toUpper(const std::string& string) {
  std::string result = string;
  std::transform(result.begin(), result.end(), result.begin(),
                [](unsigned char c){ return std::toupper(c); });
  return result;
}

/**
 * @brief Comprueba si un opcode es de salto.
 */
bool isJumpOpcode(const std::string& op) {
  std::string uop = toUpper(op);
  return uop == "JUMP" || uop == "JZERO" || uop == "JGTZ";
}