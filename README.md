# Simulador de Máquina RAM

Este proyecto implementa un simulador de una máquina RAM. Permite cargar programas escritos en ensamblador RAM, ejecutarlos con una cinta de entrada y generar una cinta de salida

## Jerarquía de clases

```mermaid
classDiagram
    direction TB

    class Exceptions

    class Tape {
        <<abstract>>
    }
    class InputTape
    class OutputTape
    Tape <|-- InputTape
    Tape <|-- OutputTape

    class Register {
        <<abstract>>
        +getValue()
        +setValue()
        +getValueAt()
        +setValueAt()
        +isVector()
    }
    class ScalarRegister {
        -value_
    }
    class VectorRegister {
        -data_
    }
    Register <|-- ScalarRegister
    Register <|-- VectorRegister

    class AbstractMemory {
        <<abstract>>
        +read()
        +write()
    }
    class RegisterMemory {
        -registers_
    }
    AbstractMemory <|-- RegisterMemory

    class Operand {
        <<abstract>>
        +getValue()
        +setValue()
        +getType()
        +isWritable()
    }
    class ConstantOperand
    class DirectOperand
    class IndirectOperand
    class VectorDirectOperand
    Operand <|-- ConstantOperand
    Operand <|-- DirectOperand
    Operand <|-- IndirectOperand
    Operand <|-- VectorDirectOperand

    class ExecutionContext

    class Instruction {
        <<abstract>>
        +execute()
        +getLine()
    }
    class AbstractInstruction {
        <<abstract>>
    }
    class InstructionWithOperand {
        <<abstract>>
    }
    class ArithmeticInstruction {
        <<abstract>>
    }
    class LoadInstruction
    class StoreInstruction
    class AddInstruction
    class SubInstruction
    class MulInstruction
    class DivInstruction
    Instruction <|-- AbstractInstruction
    AbstractInstruction <|-- InstructionWithOperand
    InstructionWithOperand <|-- ArithmeticInstruction
    ArithmeticInstruction <|-- LoadInstruction
    ArithmeticInstruction <|-- StoreInstruction
    ArithmeticInstruction <|-- AddInstruction
    ArithmeticInstruction <|-- SubInstruction
    ArithmeticInstruction <|-- MulInstruction
    ArithmeticInstruction <|-- DivInstruction

    class JumpInstructionBase {
        <<abstract>>
    }
    class JumpInstruction
    class JumpZeroInstruction
    class JumpGreaterZeroInstruction
    AbstractInstruction <|-- JumpInstructionBase
    JumpInstructionBase <|-- JumpInstruction
    JumpInstructionBase <|-- JumpZeroInstruction
    JumpInstructionBase <|-- JumpGreaterZeroInstruction

    class IOInstruction {
        <<abstract>>
    }
    class ReadInstruction
    class WriteInstruction
    class HaltInstruction
    InstructionWithOperand <|-- IOInstruction
    IOInstruction <|-- ReadInstruction
    IOInstruction <|-- WriteInstruction
    AbstractInstruction <|-- HaltInstruction

    class FileManager

    class OperandParser
    class InstructionParser
    class ProgramParser

    class InstructionExecutor
    class RAMMachine
```
