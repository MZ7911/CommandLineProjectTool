/// This is a functional implementation.

typedef int InputDataType;
typedef const InputDataType ConstIDT;
typedef InputDataType & EditableIDT;
typedef ConstIDT & FastIDT;

typedef int OutputDataType;
typedef const OutputDataType ConstODT;
typedef OutputDataType & EditableODT;
typedef ConstODT & FastODT;

typedef void StatementType;

FastIDT input();
FastODT calculate(FastIDT inputData);
StatementType output(FastODT outputData);

int main() {
    output(calculate(input()));
    return 0;
}
