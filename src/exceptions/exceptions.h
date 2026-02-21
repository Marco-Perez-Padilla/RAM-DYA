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

** Archivo exceptions.h: Archivo de excepciones
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      21/02/2026 - Creacion (primera version) del codigo
**/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

/**
 * @brief Class Exceptions that inheritages from std:exception, it has a protected member which is the message to be thrown if an error occurs
 * 
 */
class Exceptions : public std::exception {
 protected:
  std::string error_message_;
  
 public:

  explicit Exceptions(const std::string& error_message) : error_message_(error_message) {}
  const char* what() const throw() {return error_message_.c_str();}
};

/**
 * @brief Class InvalidInstructionException. Throws an exception if an instruction is invalid
 */
class InvalidInstructionException : public Exceptions {
 public:
  explicit InvalidInstructionException(const std::string& msg) : Exceptions(msg) {}
};

/**
 * @brief Class InvalidOperandException. Throws an exception if an operand is invalid
 */
class InvalidOperandException : public Exceptions {
 public:
  explicit InvalidOperandException(const std::string& msg) : Exceptions(msg) {}
};

/**
 * @brief Class OutOfTapeException. Throws an exception if the tape is out of bounds
 */
class OutOfTapeException : public Exceptions {
 public:
  explicit OutOfTapeException(const std::string& msg) : Exceptions(msg) {}
};

/**
 * @brief Class HaltException. Throws an exception if the halt instruction is encountered
 */
class HaltException : public Exceptions {
 public:
  HaltException() : Exceptions("HALT instruction encountered") {}
};

/**
 * @brief Class WriteOnInputTapeException. Throws an exception if a write operation is attempted on the input tape
 */
class WriteOnInputTapeException : public Exceptions {
 public:
  WriteOnInputTapeException() : Exceptions("Invalid operation: cannot write on input tape") {}
};

/**
 * @brief Class ReadOnOutputTapeException. Throws an exception if a read/hasNext operation is attempted on the output tape
 */
class ReadOnOutputTapeException : public Exceptions {
 public:
  ReadOnOutputTapeException() : Exceptions("Invalid operation: cannot read from output tape") {}
};

#endif