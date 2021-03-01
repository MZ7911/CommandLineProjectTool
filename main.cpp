/// This is a functional implementation.

/// Types

typedef int InputDataType;
typedef const InputDataType ConstIDT;
typedef InputDataType & EditableIDT;
typedef ConstIDT & FastIDT;

typedef int OutputDataType;
typedef const OutputDataType ConstODT;
typedef OutputDataType & EditableODT;
typedef ConstODT & FastODT;

typedef void StatementType;

/// Prototypes

FastIDT input();
FastODT calculate(FastIDT inputData);
StatementType output(FastODT outputData);

/// Main

int main() {
    output(calculate(input()));
    return 0;
}

/// Implementations

FastIDT input() {
    InputDataType res;
    return res;
}

FastODT calculate(FastIDT inputData) {
    OutputDataType res;
    return res;
}

StatementType output(FastODT outputData) {

}
