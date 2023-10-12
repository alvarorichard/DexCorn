## DexCorn 


Este é um código fonte que implementa um emulador e analisador de código Dalvik para arquivos DEX, que são usados na plataforma Android. O projeto é dividido em três partes principais:

1. **`Emulator::Unicorn`**: Esta parte é responsável pela emulação de código de máquina usando a biblioteca Unicorn. Ela permite mapear memória, escrever na memória, escrever e ler registradores e iniciar a emulação. É usada para criar e configurar um emulador Unicorn com uma arquitetura e modo específicos.

2. **`Parser::Dalvik`**: Esta parte envolve a análise de arquivos DEX usando a biblioteca LIEF. Ela permite a extração de informações detalhadas sobre métodos e classes contidos em arquivos DEX. Existem métodos para configurar informações detalhadas sobre métodos e classes em arquivos DEX, bem como para listar todas as informações de métodos e classes.

3. **`dexcorn::Dalvik`**: Esta é a parte que faz a integração das duas partes anteriores. Ela usa o `Emulator::Unicorn` para emular código Dalvik e o `Parser::Dalvik` para analisar arquivos DEX. Os métodos em `Covinhas::Dalvik` permitem configurar a emulação de métodos específicos, encontrar o deslocamento (offset) de métodos com base em nomes e iniciar a emulação.

O código é útil para uma variedade de fins, incluindo análises de segurança, engenharia reversa, depuração ou qualquer outro propósito que envolva manipulação e compreensão do código Dalvik em aplicativos Android.

## Requisitos

- A biblioteca Unicorn para emulação de código de máquina.
- A biblioteca LIEF para análise de arquivos DEX.
- Compilador C++ compatível com C++11.

## Como Usar

1. Compile o código, certificando-se de que todas as dependências estejam instaladas.

2. Execute o programa para emular ou analisar código Dalvik.

## Exemplo de Uso

```cpp
#include "dexcorn/emulator-dalvik.hpp"
#include "emulator/emulator-unicorn.hpp"
#include "parser/dalvik/parser-dalvik.hpp"

int main() {
    // Criar instâncias do Emulator::Unicorn e Parser::Dalvik
    Emulator::Unicorn unicorn;
    Parser::Dalvik dalvik("arquivo.dex");

    // Configurar emulador e analisador
    Covinhas::Dalvik covinhas(unicorn, dalvik);
    covinhas.configureEmulator();

    // Emular um método específico
    covinhas.emulateMethod("nome_do_metodo", "nome_da_classe");

    // Obter informações sobre métodos e classes
    covinhas.getAllMethods();

    return 0;
}
