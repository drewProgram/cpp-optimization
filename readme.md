## lvalue
Tudo que conseguimos referenciar, dar um endereço de memória (variáveis, funções). Tudo que está antes do operador de atribuição (=)

## rvalues
Tudo que não tem um endereço de memória (valor temporário)
para poder referenciar um rvalue, é possível fazer o
```cpp
// Copiando o parâmetro (pegando o lvalue ou rvalue)
void recebeLance(Lance)

// Referência para lvalue
void recebeLance(Lance&)

// Referência para rvalue (apenas a partir de C++ 11)
void recebeLance(Lance&&)
```