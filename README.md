# Language Course Management System

### Descrição do Projeto
O "Language Course Management System" é um sistema de gerenciamento de cursos de idiomas que permite ao usuário criar, visualizar, editar e excluir informações sobre estudantes matriculados nos cursos de idiomas. O sistema é baseado em uma árvore binária de pesquisa que armazena os dados dos alunos de forma organizada.

### Funcionalidades Principais
- **Inserir Aluno**: Adicione novos alunos ao sistema com informações detalhadas, como nome, nível de classe e idioma.
- **Listar Todos os Alunos**: Exiba uma lista de todos os alunos em - ordem alfabética.
- **Listar Alunos por Idioma**: Exiba uma lista de alunos que estudam em um idioma específico.
- **Editar Aluno**: Atualize as informações de um aluno existente.
- **Excluir Aluno**: Remova um aluno da lista de matrículas.

### Tecnologias Utilizadas
- Linguagem de Programação: C
- Estruturas de Dados: Árvore Binária de Pesquisa
- Bibliotecas: Stdio, Stdlib, String

### Como Usar

1. Clone o repositório para sua máquina local:

```shell
git clone https://github.com/HermanoCastro65/crud-language-course-in-c.git
```

2. Compile o código-fonte:
Navegue até o diretório onde você clonou o repositório e compile o código. Suponhamos que o código-fonte esteja em um arquivo chamado main.c.

```shell
cd crud-language-course-in-c
gcc app.c constants.c file.c main.c mocks.c tree.functions.c tree.tests.c -o language_course_management_system 
```

Isso compilará o código e gerará um executável chamado system.

3. Execute o programa:

Agora você pode executar o programa compilado.

```shell
./language_course_management_system
```
O programa deve ser executado, e você poderá começar a usá-lo para gerenciar os alunos matriculados em cursos de idiomas.

Para utilizar o "test mode" execute o seguinte comando.

```shell
./language_course_management_system -test
```
Este comando permite a vizualização de execução dos testes antes de iniciar o sistema.

Certifique-se de ter um ambiente de desenvolvimento C/C++ configurado em seu sistema para compilar o código. Se você estiver usando um sistema operacional diferente ou uma IDE específica, os comandos podem variar. Certifique-se de ajustar os comandos conforme necessário.

### Exemplos de Uso
```c
// Adicione um novo aluno
Student student = {generate_registration(), "Alice", class_level_types[1], language_types[0]};
root = include_student(root, student);

// Liste todos os alunos
list_all_students(root);

// Liste alunos que estudam em um idioma específico
show_course_students_by_language(root, "English");

// Edite as informações de um aluno
Node* studentToEdit = search_student(root, "Alice");
Student updatedStudent = {studentToEdit->student.registration, "Alicia", class_level_types[2], language_types[1]};
root = change_student(root, studentToEdit, updatedStudent);

// Exclua um aluno
root = delete_student(root, "Alicia");
```

### Licença
Este projeto está licenciado sob a Licença MIT - consulte o arquivo LICENSE para obter detalhes.


# Crud Language Course Documentation

## Índice
* [Mocks](#Mocks)
* [Constants](#Constants)

## Mocks
- **mocks.h**

```c
#ifndef MOCKS_H
#define MOCKS_H

#include "constants.h"
#include "tree.h"

extern Student* students_array;

extern Student student1;
extern Student student2;
extern Student student3;
extern Student student4;
extern Student student5;
extern Student student6;
extern Student student7;
extern Student student8;
extern Student student9;
extern Student student10;

void initialize_students_mocks(void);
void free_all_students_mocks(void);

#endif
```

Esse código é um arquivo de cabeçalho (header file) em C que faz parte de um programa que lida com informações de estudantes (students) e cria "mocks" (dados fictícios) para fins de teste e desenvolvimento. Vou explicar as partes-chave deste código:

1. **`#ifndef MOCKS_H`** e **`#define MOCKS_H`** : Essas diretivas de pré-processador garantem que o conteúdo do arquivo de cabeçalho seja incluído apenas uma vez no programa. Isso evita problemas de inclusão múltipla.

2. **`#include "constants.h"`** e **`#include "tree.h"`** : Essas linhas incluem outros arquivos de cabeçalho necessários no código. O arquivo "constants.h" pode conter definições de constantes ou enumerações, enquanto o arquivo "tree.h" provavelmente contém definições relacionadas a uma estrutura de árvore para armazenar informações de estudantes.

3. **`extern Student* students_array;`** : Aqui, uma variável global **`students_array`** de tipo **`Student*`** (um ponteiro para estruturas de estudantes) é declarada como "extern". Isso significa que a variável será definida em algum outro lugar do código (provavelmente em um arquivo de origem separado) e será usada nesse arquivo.

4. **`extern Student student1;`** até **`extern Student student10;`** : Isso declara dez variáveis globais de estrutura **`Student`** (representando estudantes individuais). Elas são declaradas como "extern", o que significa que suas definições reais estarão em algum lugar no código-fonte do programa. Essas variáveis são usadas para armazenar informações sobre os estudantes fictícios criados para fins de teste.

5. **`void initialize_students_mocks(void);`** : Essa função é declarada, mas seu código real provavelmente está definido em outro lugar (provavelmente no arquivo "mocks.c"). A função **`initialize_students_mocks`** é usada para inicializar os dados fictícios dos estudantes e preencher as variáveis globais declaradas anteriormente com informações fictícias.

6. **`void free_all_students_mocks(void);`** : Essa função, assim como a anterior, é declarada no cabeçalho, mas seu código real provavelmente está definido em outro lugar. A função **`free_all_students_mocks`** é usada para liberar qualquer memória alocada dinamicamente relacionada aos dados fictícios dos estudantes.

Em resumo, este arquivo de cabeçalho "mocks.h" é uma parte importante do programa que fornece dados fictícios (mocks) para fins de teste e desenvolvimento. Os dados fictícios são usados para simular informações de estudantes e garantir que o código do programa funcione corretamente em diversas situações.

- **mocks.c**

```c
#include <stdlib.h>
#include <string.h>

#include "mocks.h"

Student* students_array;

Student student1;
Student student2;
Student student3;
Student student4;
Student student5;
Student student6;
Student student7;
Student student8;
Student student9;
Student student10;

void initialize_students_mocks() {
  Student* students_array = malloc(10 * sizeof(Student));
  if (!students_array) exit(1);

  student1.registration = generate_registration();
  strncpy(student1.name, "Zoe", sizeof(student1.name));
  strncpy(student1.class_level, class_level_types[0],
          sizeof(student1.class_level));
  strncpy(student1.language, language_types[2], sizeof(student1.language));
  students_array[0] = student1;

  student2.registration = generate_registration();
  strncpy(student2.name, "Alice", sizeof(student2.name));
  strncpy(student2.class_level, class_level_types[2],
          sizeof(student2.class_level));
  strncpy(student2.language, language_types[0], sizeof(student2.language));
  students_array[1] = student2;

  student3.registration = generate_registration();
  strncpy(student3.name, "Charlie", sizeof(student3.name));
  strncpy(student3.class_level, class_level_types[1],
          sizeof(student3.class_level));
  strncpy(student3.language, language_types[2], sizeof(student3.language));
  students_array[2] = student3;

  student4.registration = generate_registration();
  strncpy(student4.name, "Yasmine", sizeof(student4.name));
  strncpy(student4.class_level, class_level_types[1],
          sizeof(student4.class_level));
  strncpy(student4.language, language_types[0], sizeof(student4.language));
  students_array[3] = student4;

  student5.registration = generate_registration();
  strncpy(student5.name, "Anna", sizeof(student5.name));
  strncpy(student5.class_level, class_level_types[0],
          sizeof(student5.class_level));
  strncpy(student5.language, language_types[1], sizeof(student5.language));
  students_array[4] = student5;

  student6.registration = generate_registration();
  strncpy(student6.name, "Bob", sizeof(student6.name));
  strncpy(student6.class_level, class_level_types[1],
          sizeof(student6.class_level));
  strncpy(student6.language, language_types[3], sizeof(student6.language));
  students_array[5] = student6;

  student7.registration = generate_registration();
  strncpy(student7.name, "Catherine", sizeof(student7.name));
  strncpy(student7.class_level, class_level_types[2],
          sizeof(student7.class_level));
  strncpy(student7.language, language_types[0], sizeof(student7.language));
  students_array[6] = student7;

  student8.registration = generate_registration();
  strncpy(student8.name, "Henry", sizeof(student8.name));
  strncpy(student8.class_level, class_level_types[2],
          sizeof(student8.class_level));
  strncpy(student8.language, language_types[1], sizeof(student8.language));
  students_array[7] = student8;

  student9.registration = generate_registration();
  strncpy(student9.name, "Xander", sizeof(student9.name));
  strncpy(student9.class_level, class_level_types[1],
          sizeof(student9.class_level));
  strncpy(student9.language, language_types[1], sizeof(student9.language));
  students_array[8] = student9;

  student10.registration = generate_registration();
  strncpy(student10.name, "Zach", sizeof(student10.name));
  strncpy(student10.class_level, class_level_types[2],
          sizeof(student10.class_level));
  strncpy(student10.language, language_types[3], sizeof(student10.language));
  students_array[9] = student10;
}

void free_all_students_mocks() {
  memset(&student1, 0, sizeof(Student));
  memset(&student2, 0, sizeof(Student));
  memset(&student3, 0, sizeof(Student));
  memset(&student4, 0, sizeof(Student));
  memset(&student5, 0, sizeof(Student));
  memset(&student6, 0, sizeof(Student));
  memset(&student7, 0, sizeof(Student));
  memset(&student8, 0, sizeof(Student));
  memset(&student9, 0, sizeof(Student));
  memset(&student10, 0, sizeof(Student));

  free(students_array);
}

```

Este é um arquivo de código-fonte em C que define funções para inicializar e liberar mocks (dados fictícios) de estudantes. Vou explicar o código passo a passo:

1. **`#include <stdlib.h>`** e **`#include <string.h>`** : Estas linhas incluem os cabeçalhos padrão da biblioteca C para funções relacionadas à alocação de memória dinâmica e manipulação de strings.

2. **`#include "mocks.h"`** : Isso inclui o arquivo de cabeçalho "mocks.h" no código para que as funções definidas aqui possam ser usadas em outros arquivos de código que incluem "mocks.h".

3. **`Student* students_array;`** : Aqui, uma variável global chamada **`students_array`** é declarada. Ela é um ponteiro para um array de estruturas **`Student`** que conterá os dados fictícios dos estudantes.

4. As próximas linhas declaram dez variáveis globais **`Student`** chamadas **`student1`**, **`student2`**, até **`student10`**. Cada uma dessas variáveis representará informações fictícias de um estudante individual.

5. **`void initialize_students_mocks()`** : Esta função é definida para inicializar os mocks dos estudantes. Ela aloca memória para o array de estudantes (**`students_array`**) e preenche os dados fictícios de cada estudante (de **`student1`** até **`student10`**). Os dados fictícios incluem informações como registro, nome, nível de classe e idioma, e são preenchidos manualmente.

6. **`malloc(10 * sizeof(Student))`**: A função **`malloc`** é usada para alocar espaço na memória para armazenar dados fictícios de 10 estudantes. O tamanho alocado é calculado como o tamanho de uma única estrutura **`Student`** multiplicado por 10.

7. **`free_all_students_mocks()`**: Essa função é definida para liberar a memória alocada para os mocks de estudantes. Ela redefine as variáveis **`student1`**, **`student2`**, até **`student10`** para que seus valores sejam "zerados" e, em seguida, libera a memória alocada dinamicamente para o array **`students_array`** usando a função **`free`**.

Em resumo, esse arquivo de código "mocks.c" contém as implementações de funções relacionadas à criação e liberação de dados fictícios de estudantes. Esses dados fictícios são usados para testar e simular informações de estudantes em um programa C.

## Constants

- **constants.h**

```c
#ifndef CONSTANTS_H
#define CONSTANTS_H

extern const char* class_level_types[];
extern const char* language_types[];

int test_constants(void);

#endif
```

Este é um arquivo de cabeçalho (header) em C chamado "constants.h" que define constantes e protótipos de funções relacionadas a constantes. Vou explicar o código passo a passo:

1. **`#ifndef CONSTANTS_H`** : Isso é uma diretiva de pré-processador que verifica se o símbolo **`CONSTANTS_H`** ainda não foi definido. Isso é usado para evitar a inclusão repetida do mesmo arquivo de cabeçalho em um arquivo-fonte. Se **`CONSTANTS_H`** ainda não foi definido, o código abaixo é incluído.

2. **`#define CONSTANTS_H`** : Aqui, o símbolo **`CONSTANTS_H`** é definido, indicando que este arquivo de cabeçalho foi incluído no arquivo de código-fonte. Isso evita a inclusão repetida.

3. **`extern const char* class_level_types[];`** : Esta linha declara uma variável global externa chamada **`class_level_types`**. A palavra-chave **`extern`** indica que a definição real desta variável existe em outro arquivo de código-fonte. Neste arquivo de cabeçalho, apenas a declaração da variável é fornecida. Essa variável representa um array de ponteiros para strings, que contém os tipos de nível de classe.

4. **`extern const char* language_types[];`**: Da mesma forma, esta linha declara uma variável global externa chamada **`language_types`**. Ela representa outro array de ponteiros para strings, que contém os tipos de idioma.

5. **`int test_constants(void);`** : Esta linha declara um protótipo de função chamado **`test_constants`**. A função **`test_constants`** é definida em outro lugar e é responsável por realizar testes relacionados a essas constantes.

6. **`#endif`**: Isso encerra o bloco de inclusão condicional **`#ifndef`** iniciado na primeira linha do arquivo. Garante que o conteúdo deste arquivo de cabeçalho seja incluído apenas uma vez em cada arquivo de código-fonte.

Em resumo, esse arquivo de cabeçalho "constants.h" define constantes globais para tipos de nível de classe e tipos de idioma, bem como o protótipo de uma função de teste relacionada a essas constantes. Ele é projetado para ser incluído em outros arquivos de código que precisam dessas constantes em seus programas.

- **constans.c**

```c
#include "constants.h"

const char* class_level_types[] = {"Beginner", "Intermediate", "Advanced"};
const char* language_types[] = {"English", "Spanish", "French", "Italian"};
```

O código que você forneceu é um exemplo de definição de constantes globais para tipos de nível de classe e tipos de idioma. Vou explicar o código passo a passo:

1. **`#include "constants.h"`**: Esta linha inclui o arquivo de cabeçalho "constants.h" em seu código-fonte. Isso permite que você use as constantes e protótipos de função declarados no arquivo de cabeçalho neste arquivo.

2. **`const char* class_level_types[] = {"Beginner", "Intermediate", "Advanced"};`** : Nesta linha, você está definindo uma matriz de ponteiros para strings chamada **`class_level_types`**. Esta matriz contém três elementos, que são as strings "Beginner," "Intermediate" e "Advanced." Cada elemento da matriz é uma constante que representa um tipo de nível de classe.

3. **`const char* language_types[] = {"English", "Spanish", "French", "Italian"};`** : Da mesma forma, nesta linha, você está definindo outra matriz de ponteiros para strings chamada **`language_types`**. Esta matriz contém quatro elementos, que são as strings "English," "Spanish," "French" e "Italian." Cada elemento da matriz é uma constante que representa um tipo de idioma.

Essas constantes são declaradas como globais e podem ser acessadas em qualquer parte do código após a inclusão do arquivo de cabeçalho "constants.h". Elas são úteis para armazenar informações que são usadas em vários lugares em seu programa e permitem que você as atualize facilmente em um único local, caso seja necessário fazer alterações futuras.

Note que as constantes são declaradas como ponteiros para strings, e as strings são armazenadas na memória como constantes de caracteres. Portanto, essas constantes não podem ser modificadas em tempo de execução, garantindo que seus valores permaneçam fixos durante a execução do programa.