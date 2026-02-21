#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

class FileManager {
 public:  
  static std::vector<std::string> readProgramFile(const std::string& filename); // FileNotFoundException
  static std::vector<int> readInputTape(const std::string& filename); // FileNotFoundException
  static void writeOutputTape(const std::string& filename, const std::vector<int>& data); // FileNotFoundException
};

#endif