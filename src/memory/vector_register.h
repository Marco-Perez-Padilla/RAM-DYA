#ifndef VECTOR_REGISTER_H
#define VECTOR_REGISTER_H

#include "register.h"

class VectorRegister : public Register {
 public:
  VectorRegister() = default;
  explicit VectorRegister(const std::vector<int>& data);
  int getValue() const override; // exception
  void setValue(int value) override; // exception
  int getValueAt(int index) const override;
  void setValueAt(int index, int value) override;
  bool isVector() const override;
private:
  std::vector<int> data_;
};

#endif