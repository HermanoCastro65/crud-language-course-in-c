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
Navegue até o diretório onde você clonou o repositório e compile o código.

```shell
cd crud-language-course-in-c
gcc app.c constants.c file.c main.c mocks.c tree.functions.c tree.tests.c -o language_course_management_system 
```

Isso compilará o código e gerará um executável chamado language_course_management_system.

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

# Crud Language Course Documentation

## Índice
* [Mocks](#Mocks)
* [Constants](#Constants)
* [Tree](#Tree)
* [Functions](#Functions)
* [Tests](#Tests)
* [File](#File)
* [Application](#Application)
* [Main](#Main)

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

## Tree

```c
typedef struct student {
  int registration;
  char name[25];
  char class_level[25];
  char language[25];
} Student;

typedef struct tree_node {
  Student student;
  struct tree_node* right;
  struct tree_node* left;
} Node;

void run_test(char* test_name[25], int test, char* test_mode);

int is_empty(Node* node);
int test_is_empty(void);

Node* initialize_tree(void);
int test_initialize_tree(void);

void free_tree(Node* node);
int test_free_tree();

void initialize_random_seed(void);
int generate_registration(void);
int test_generate_registration(void);

void list_all_students(Node* node);
int test_list_all_students(void);

Node* search_student(Node* node, const char* name);
int test_search_student(void);

void show_student(Student student);
int test_search_student(void);

Node* create_node(Student student, Node* left, Node* right);
int test_create_node(void);

Node* include_student(Node* node, Student student);
void print_student_names(Node* node);
int is_tree_alphabetical(Node* node);
int test_include_student(void);

Node* change_student(Node* node, Node* student, Student change_student);
int test_change_student(void);

Node* find_min(Node* node);
Node* delete_student(Node* node, const char* name);
int test_delete_student(void);

void show_students_by_language(Node* students, const char* language);
int test_show_students_by_language(void);
```
O arquivo "tree.h" contém as declarações das funções e estruturas usadas para manipular uma árvore de estudantes (alunos) matriculados em cursos de idiomas. Aqui está uma explicação do código:

1. **`typedef struct tree_node`** : 
- Define a estrutura de um nó da árvore, onde cada nó contém informações de um estudante (do tipo **`Student`**), além de ponteiros para os nós à esquerda e à direita na árvore.

2. **`void run_test(char* test_name[25], int test, char* test_mode)`** : 
- Função que executa um teste específico no programa.

3. **`int is_empty(Node* node)`** :
- Verifica se a árvore está vazia (sem alunos).

4. **`Node* initialize_tree(void)`** :
- Inicializa uma árvore vazia e retorna o ponteiro para o nó raiz.

5. **`void free_tree(Node* node)`** :
- Libera a memória alocada para a árvore, incluindo todos os nós e estudantes.

6. **`void initialize_random_seed(void)`** :
- Inicializa a semente para geração de números aleatórios.

7. **`int generate_registration(void)`** :
- Gera um número de registro aleatório para um estudante.

8. **`void list_all_students(Node* node)`** :
- Exibe na saída padrão os nomes de todos os estudantes na árvore em ordem alfabética.

9. **`Node* search_student(Node* node, const char* name)`** :
- Procura um estudante pelo nome na árvore e retorna o nó correspondente.

10. **`void show_student(Student student)`** :
- Exibe os detalhes de um estudante na saída padrão.

11. **`Node* create_node(Student student, Node* left, Node* right)`** :
- Cria um novo nó com informações do estudante e ponteiros para os nós à esquerda e à direita.

12. **`Node* include_student(Node* node, Student student)`** :
- Insere um estudante na árvore, mantendo a ordem alfabética.

13. **`Node* change_student(Node* node, Node* student, Student change_student)`** :
- Altera as informações de um estudante específico na árvore.

14. **`Node* find_min(Node* node)`** :
- Encontra o nó com o menor nome na árvore.

15. **`Node* delete_student(Node* node, const char* name)`** :
- Exclui um estudante da árvore.

16. **`void show_students_by_language(Node* students, const char* language`** :
- Exibe na saída padrão os estudantes que falam uma língua específica.

Cada função possui um teste correspondente (**`int test_function_name(void)`**) que pode ser executado para verificar sua funcionalidade. As funções e testes são essenciais para a manipulação e gerenciamento de alunos em cursos de idiomas.

## Functions

O cabeçalho do arquivo [tree.functions.c](https://github.com/HermanoCastro65/crud-language-course-in-c/blob/creating-documentation/tree.functions.c) descreve as inclusões de bibliotecas e cabeçalhos de outros arquivos necessários para a implementação das funções relacionadas à árvore de estudantes. Aqui está uma explicação detalhada do cabeçalho:

- **`#include <stdio.h>`** : Inclui a biblioteca padrão de entrada e saída em C, que fornece funções para entrada (leitura) e saída (escrita) de dados.

- **`#include <stdlib.h>`** : Inclui a biblioteca padrão em C, que contém funções para alocação de memória, controle de processos e outras operações essenciais.

- **`#include <string.h>`** : Inclui a biblioteca padrão em C para manipulação de cadeias de caracteres, oferecendo funções para copiar, comparar e modificar strings.

- **`#include "constants.h"`** : Inclui o cabeçalho do arquivo "constants.h," que contém as constantes usadas no programa, como os tipos de níveis de classe e idiomas.

- **`#include "tree.h"`** : Inclui o cabeçalho do arquivo "tree.h," que contém as declarações das funções e estruturas usadas para manipular a árvore de estudantes.

Essas inclusões de bibliotecas e cabeçalhos são necessárias para que as funções implementadas em [tree.functions.c](https://github.com/HermanoCastro65/crud-language-course-in-c/blob/creating-documentation/tree.functions.c) tenham acesso a todas as funcionalidades e estruturas definidas no projeto. Isso permite que o código seja organizado em módulos e use as bibliotecas padrão sempre que necessário para o funcionamento correto do programa.

- **Functions:**

* [is_empty](#is_empty)
* [initialize_tree](#initialize_tree)
* [free_tree](#free_tree)
* [initialize_random_seed](#initialize_random_seed)
* [generate_registration](#generate_registration)
* [list_all_students](#list_all_students)
* [create_node](#create_node)
* [include_student](#include_student)
* [search_student](#search_student)
* [show_student](#show_student)
* [show_students_by_language](#show_students_by_language)
* [find_min](#find_min)
* [delete_student](#delete_student)
* [change_student](#change_student)

1. ### is_empty

```c
int is_empty(Node* node) { return node == NULL; }
```

A função is_empty é uma função simples que verifica se a árvore (ou subárvore) representada por um nó é vazia, ou seja, se não contém nenhum aluno. A função recebe como argumento um ponteiro para um nó (do tipo **`Node`**) e retorna um valor inteiro (int). O funcionamento da função é explicado da seguinte forma:

- Ela recebe um nó como argumento (**`Node* node`**), que é um ponteiro para um nó na árvore.

- A função verifica se o ponteiro **`node`** é igual a **`NULL`**. Se for, isso significa que o nó está vazio, e a função retorna 1 (verdadeiro) para indicar que a árvore está vazia.

- Caso o ponteiro **`node`** não seja **`NULL`**, a função retorna 0 (falso) para indicar que a árvore não está vazia.

Essa função é útil para verificar rapidamente se uma árvore está vazia ou não, o que pode ser útil em diversas operações de gerenciamento de árvores, como inserção, exclusão, pesquisa e listagem de elementos. Ela fornece uma verificação simples e eficiente para essa condição.

2. ### initialize_tree

```c
Node* initialize_tree() { return NULL; }
```

A função **`initialize_tree`** é uma função que cria e retorna uma árvore (ou subárvore) vazia. Ela não aloca memória para nenhum nó e, portanto, retorna **`NULL`** para indicar que a árvore está vazia.

Essa função é útil quando você deseja iniciar uma nova árvore do zero. Quando a árvore é inicializada, ela não contém nenhum aluno. À medida que novos alunos são adicionados à árvore, a estrutura da árvore é construída dinamicamente por meio das funções de inserção, como **`include_student`**. Portanto, a árvore começa como uma raiz nula.

O uso dessa função pode ser o ponto de partida para criar uma nova árvore de alunos. Ela cria a base vazia na qual os alunos serão inseridos posteriormente. Portanto, quando você desejar criar uma nova árvore, pode chamar **`initialize_tree`** para obter uma árvore vazia e, em seguida, começar a adicionar alunos a partir daí.

3. ### free_tree

```c
void free_tree(Node* root) {
  if (root == NULL) return;

  free_tree(root->left);
  free_tree(root->right);
  free(root);
}
```

A função **`free_tree`** é uma função de liberação de memória que é usada para desalocar todos os nós de uma árvore binária de alunos (ou subárvore) e liberar a memória associada a eles. Essa função é recursiva e é usada para garantir que todos os nós da árvore sejam liberados corretamente, incluindo os nós filhos.

Aqui está o funcionamento da função:

- A função recebe um ponteiro para o nó raiz da árvore, chamado **`root`**. Se a árvore estiver vazia (ou seja, o **`root`** é **`NULL`**), a função simplesmente retorna sem fazer nada, pois não há nós a serem liberados.

- Se a árvore não estiver vazia, a função entra na recursão. Ela chama a função **`free_tree`** em cada um dos nós filhos do nó atual, primeiro no nó à esquerda (subárvore esquerda) e depois no nó à direita (subárvore direita). Isso garante que todos os nós da árvore sejam visitados.

- Após chamar **`free_tree`** nos nós filhos, a função executa **`free(root)`** para desalocar o nó atual, ou seja, o nó referenciado pelo ponteiro **`root`**.

A recursão continua até que todos os nós da árvore tenham sido visitados e desalocados. Assim, a função libera a memória de todos os nós da árvore, garantindo que não ocorra vazamento de memória.

Essa função é fundamental para a liberação de recursos após o uso de uma árvore de alunos e ajuda a prevenir vazamentos de memória, especialmente quando a árvore precisa ser destruída ou quando você deseja reutilizar a estrutura.

4. ### initialize_random_seed

```c
void initialize_random_seed() { srand(time(NULL)); }
```

A função **`initialize_random_seed`** é responsável por inicializar a semente do gerador de números pseudoaleatórios. Nesse caso, ela utiliza a função **`srand`** da biblioteca padrão C para definir a semente do gerador de números pseudoaleatórios com base no tempo atual. Aqui está como a função funciona:

- **`srand`** é uma função que recebe um valor inteiro (semente) como argumento. Essa semente é usada pelo gerador de números pseudoaleatórios para iniciar sua sequência de números.

- **`time(NULL)`** é uma função que retorna o número de segundos desde uma data específica (normalmente, 1º de janeiro de 1970, conhecida como "época"). Ela é uma forma comum de obter um valor que muda com o tempo.

- **`srand(time(NULL))`** define a semente do gerador de números pseudoaleatórios como o número de segundos desde a época. Isso significa que a sequência de números gerados pelo gerador será diferente cada vez que o programa for executado, a menos que a semente seja definida manualmente.

Essa função é frequentemente usada para inicializar a semente do gerador de números pseudoaleatórios quando se deseja obter sequências de números aleatórios diferentes em diferentes execuções do programa. Ela é especialmente útil em casos nos quais a aleatoriedade é necessária, como para criar dados de teste ou simulações.

5. ### generate_registration

```c
int generate_registration() {
  int lower_bound = 10000;
  int upper_bound = 99999;
  int random_number = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
  return random_number;
}
```

A função generate_registration é usada para gerar números de registro aleatórios que normalmente têm cinco dígitos. Aqui está uma explicação passo a passo de como ela funciona:

- **`int lower_bound`** e **`int upper_bound`** são variáveis que definem o intervalo de valores entre os quais você deseja gerar números de registro aleatórios. Neste caso, **`lower_bound`** é definido como 10.000 e **`upper_bound`** é definido como 99.999. Isso garante que os números gerados estejam no intervalo entre 10.000 e 99.999.

- **`int random_number é uma variável que receberá o número de registro aleatório gerado.

- **`(rand() % (upper_bound - lower_bound + 1))`** é uma expressão que usa a função **`rand()`** para gerar um número pseudoaleatório, e o operador % (módulo) é usado para limitar esse número ao intervalo de valores entre **`lower_bound`** e **`upper_bound`**.

- **`+ lower_bound`** é adicionado ao número gerado para garantir que ele esteja dentro do intervalo desejado. Isso desloca a faixa de valores do número aleatório de volta ao intervalo desejado entre 10.000 e 99.999.

- A função retorna o **`random_number`**, que é um número de registro aleatório no intervalo especificado.

No geral, essa função gera números de registro aleatórios dentro de um intervalo específico para simular registros de estudantes, por exemplo, em um sistema de gerenciamento de cursos. O uso do operador % garante que os números gerados estejam distribuídos uniformemente dentro do intervalo especificado.

6. ### list_all_students

```c
void list_all_students(Node* node) {
  if (node == NULL) return;

  list_all_students(node->left);

  printf("Student (%d): %s - Level: %s - Language: %s\n",
         node->student.registration, node->student.name,
         node->student.class_level, node->student.language);

  list_all_students(node->right);
}
```

A função **`list_all_students`** é uma função de percurso em ordem que percorre uma árvore binária de alunos e imprime as informações de cada aluno em ordem alfabética. Aqui está uma explicação passo a passo de como ela funciona:

- A função recebe um ponteiro para um nó **`Node* node`**. Esse nó representa a raiz da árvore que será percorrida.

- A função começa com uma verificação para saber se o nó atual é nulo (**`node == NULL`**). Se for nulo, significa que a árvore ou subárvore em questão está vazia, e a função retorna imediatamente.

- A função chama **`list_all_students(node->left)`**. Isso faz com que a função percorra recursivamente a subárvore esquerda (com alunos cujos nomes estão em ordem alfabética antes do nó atual).

- Em seguida, a função imprime as informações do aluno no nó atual usando a função **`printf`**. Ela exibe o número de registro, nome, nível e idioma do aluno.

- A função chama **`list_all_students(node->right)`**. Isso faz com que a função percorra recursivamente a subárvore direita (com alunos cujos nomes estão em ordem alfabética após o nó atual).

- O resultado é que a função percorre a árvore binária em ordem alfabética, começando pelos alunos com nomes mais à esquerda e terminando com os alunos com nomes mais à direita.

Essa função é útil para listar todos os alunos em ordem alfabética, permitindo que sejam apresentados de forma organizada e legível. Ela é uma implementação do percurso em ordem de uma árvore binária de pesquisa.

7. ### create_node

```c
Node* create_node(Student student, Node* left, Node* right) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  if (!new_node) {
    perror("Memory allocation error");
    exit(1);
  }

  Student new_student;

  new_student.registration = student.registration;
  strncpy(new_student.name, student.name, sizeof(new_student.name));
  strncpy(new_student.class_level, student.class_level,
          sizeof(new_student.class_level));
  strncpy(new_student.language, student.language, sizeof(new_student.language));

  new_node->student = new_student;
  new_node->left = left;
  new_node->right = right;

  return new_node;
}
```

A função **`create_node`** é responsável por alocar memória para um novo nó em uma árvore binária de alunos (**`Node`**) e preenchê-lo com os dados do aluno (**`Student`**) fornecidos. Aqui está uma explicação passo a passo de como ela funciona:

- A função recebe três argumentos:

1. **`Student student`** : Um objeto **`Student`** contendo as informações do aluno que serão copiadas para o novo nó.
2. **`Node* left`** : Um ponteiro para o nó filho à esquerda.
3. **`Node* right`** : Um ponteiro para o nó filho à direita.

- A função começa por alocar dinamicamente memória para um novo nó usando **`malloc(sizeof(Node))`**. Isso cria um novo nó do tipo **`Node`** na memória.

- Após a alocação bem-sucedida, a função verifica se a alocação de memória foi bem-sucedida usando **`if (!new_node)`**. Se a alocação de memória falhar, a função imprime uma mensagem de erro usando **`perror`** e sai do programa com **`exit(1)`**.

- A função cria um novo objeto **`Student chamado **`new_student.

- Os campos do novo objeto **`new_student`** são preenchidos com os valores do aluno fornecido nos argumentos da função. Os campos são copiados usando a função **`strncpy`**. Isso garante que os campos do novo aluno sejam independentes dos campos originais e que não haja compartilhamento de memória.

- O novo nó (**`new_node`**) é preenchido com o objeto **`new_student`** e os ponteiros para os nós filhos à esquerda e à direita (**`left`** e **`right`**).

- A função retorna o novo nó criado, que agora faz parte da árvore binária de alunos.

Essa função é comumente usada ao adicionar novos alunos à árvore binária. Ela garante que um novo nó seja alocado e preenchido corretamente com os dados do aluno, mantendo a estrutura da árvore organizada.

8. ### include_student
```c
Node* include_student(Node* node, Student student) {
  if (!node) return create_node(student, NULL, NULL);

  int comparison = strcmp(student.name, node->student.name);

  if (comparison <= 0)
    node->left = include_student(node->left, student);
  else
    node->right = include_student(node->right, student);

  return node;
}
```
A função **`include_student`** é usada para adicionar um novo aluno à árvore binária de alunos. Aqui está uma explicação passo a passo de como ela funciona:

- A função recebe dois argumentos:

1. **`Node* node`** : Um ponteiro para o nó raiz da árvore na qual o aluno será adicionado.
2. **`Student student`** : O aluno que será adicionado à árvore.

- Primeiro, a função verifica se o nó atual (**`node`**) é nulo. Se o nó for nulo, significa que chegamos a uma posição vazia na árvore onde o novo aluno pode ser inserido. Nesse caso, a função cria um novo nó (usando a função **`create_node`**) com o aluno fornecido e ponteiros para os filhos à esquerda e à direita definidos como nulos. Em seguida, retorna esse novo nó como a nova raiz da árvore.

- Se o nó atual (**`node`**) não for nulo, a função prossegue para determinar onde o novo aluno deve ser inserido na árvore existente.

- Ela começa comparando o nome do aluno (**`student.name`**) com o nome do aluno no nó atual (**`node->student.name`**) usando a função **`strcmp`**. Isso ajuda a determinar se o novo aluno deve ser colocado à esquerda ou à direita do nó atual.

- Se a comparação resultar em um valor menor ou igual a zero (**`comparison <= 0`**), o novo aluno será inserido no subárvore esquerda do nó atual. A função **`include_student`** é chamada recursivamente com o nó esquerdo (**`node->left`**) como o novo nó raiz e o aluno a ser adicionado.

- Se a comparação resultar em um valor maior que zero, o novo aluno será inserido no subárvore direita do nó atual. A função **`include_student`** é chamada recursivamente com o nó direito (**`node->right`**) como o novo nó raiz e o aluno a ser adicionado.

- A função retorna o nó atual após a inserção do novo aluno. Se o nó raiz não foi modificado, ele retorna o mesmo nó raiz original.

No geral, essa função é responsável por percorrer a árvore e encontrar o local correto para adicionar o novo aluno, mantendo a ordem alfabética dos nomes dos alunos na árvore. Ela também lida com a criação de um novo nó, se necessário, e garante que a estrutura da árvore permaneça organizada.

9. ### search_student

```c
Node* search_student(Node* node, const char* name) {
  if (node == NULL) return NULL;

  int comparison = strcmp(name, node->student.name);

  if (comparison == 0)
    return node;
  else if (comparison < 0)
    return search_student(node->left, name);
  else
    return search_student(node->right, name);
}
```

A função **`search_student`** é usada para encontrar um aluno na árvore binária com base no nome do aluno. Aqui está uma explicação passo a passo de como ela funciona:

- A função recebe dois argumentos:

1. **`Node* node`** : Um ponteiro para o nó raiz da árvore onde a pesquisa será realizada.
2. **`const char* name`** : O nome do aluno que está sendo procurado.

- Primeiro, a função verifica se o nó atual (**`node`**) é nulo. Se o nó for nulo, significa que a árvore não contém o aluno com o nome pesquisado, e a função retorna **`NULL`** para indicar que o aluno não foi encontrado.

- Se o nó atual (**`node`**) não for nulo, a função procede a comparar o nome do aluno no nó atual (**`node->student.name`**) com o nome fornecido (**`name`**) usando a função **`strcmp`**.

- Se a comparação resultar em um valor igual a zero (**`comparison == 0`**), isso significa que o nome do aluno no nó atual é igual ao nome pesquisado. Nesse caso, a função retorna o próprio nó atual, representando o aluno encontrado na árvore.

- Se a comparação resultar em um valor menor que zero, isso significa que o nome pesquisado é alfabeticamente menor do que o nome do aluno no nó atual. A função **`search_student`** é chamada recursivamente no nó à esquerda (**`node->left`**) para continuar a pesquisa na subárvore esquerda.

- Se a comparação resultar em um valor maior que zero, isso significa que o nome pesquisado é alfabeticamente maior do que o nome do aluno no nó atual. A função **`search_student`** é chamada recursivamente no nó à direita (**`node->right`**) para continuar a pesquisa na subárvore direita.

- A função retorna o nó atual onde o aluno foi encontrado, ou retorna **`NULL`** se o aluno não foi encontrado na árvore.

No geral, essa função é responsável por percorrer a árvore e encontrar um aluno específico com base no nome. Ela utiliza a ordem alfabética dos nomes para direcionar a pesquisa na subárvore esquerda ou direita, conforme necessário.

10. ### show_student

```c
void show_student(Student student) {
  printf("Registration: %d\nName: %s\nLevel: %s\nLanguage: %s\n",
         student.registration, student.name, student.class_level,
         student.language);
}
```

A função **`show_student`** é responsável por exibir os detalhes de um aluno no console. Ela recebe uma estrutura **`Student`** como argumento e imprime as informações do aluno, como número de registro, nome, nível e idioma, formatadas em uma mensagem legível. Aqui está uma explicação dos elementos usados na função:

- **`void show_student(Student student)`** : Este é o cabeçalho da função que declara que ela não retorna um valor (tipo **`void`**) e recebe um parâmetro do tipo **`Student`** chamado student, que representa as informações do aluno a serem exibidas.

- **`printf("Registration: %d\nName: %s\nLevel: %s\nLanguage: %s\n", ...)`** : Esta linha usa a função **`printf`** para formatar e exibir as informações do aluno. Os marcadores de posição **`%d`**, **`%s`** e **`%s`** são usados para inserir os valores das propriedades do aluno na mensagem.

- **`student.registration`** : Essa parte do código insere o número de registro do aluno na mensagem de saída, substituindo **`%d`**.

- **`student.name`** : Esta parte insere o nome do aluno na mensagem, substituindo **`%s`**.

- **`student.class_level`** : Aqui, o nível do aluno é inserido na mensagem, substituindo outro **`%s`**.

- **`student.language`** : Finalmente, o idioma do aluno é inserido na mensagem, substituindo o último **`%s`**.

Ao chamar a função **`show_student`** e passar uma estrutura **`Student`** como argumento, os detalhes desse aluno específico são exibidos no console, tornando mais fácil visualizar e entender as informações do aluno.

Por exemplo, ao chamar **`show_student(student1);`**, a função exibirá as informações de **`student1`** no seguinte formato:

```cmd
Registration: [número de registro]
Name: [nome do aluno]
Level: [nível do aluno]
Language: [idioma do aluno]
```

Os valores reais serão preenchidos com os dados específicos do aluno que foram passados como argumento para a função. Isso é útil para visualizar e verificar as informações de um aluno em particular.

11. ### show_students_by_language

```c
void show_students_by_language(Node* students, const char* language) {
  if (students == NULL) return;

  show_students_by_language(students->left, language);

  if (strcmp(students->student.language, language) == 0)
    printf("Name: %s - Level: %s - Language: %s\n", students->student.name,
           students->student.class_level, students->student.language);

  show_students_by_language(students->right, language);
}
```

A função **`show_students_by_language`** percorre uma árvore de alunos (representada pelo nó **`students`**) e exibe informações dos alunos cujo idioma corresponde ao idioma especificado. Aqui está uma explicação passo a passo dessa função:

- **`if (students == NULL) return;`** : Isso é uma verificação para garantir que a função não prossiga se o nó atual (representando um aluno) for nulo. Isso ocorre quando a função atinge uma folha da árvore ou quando a árvore está vazia. Nesse caso, a função retorna sem fazer nada.

- **`show_students_by_language(students->left, language);`** : Aqui, a função é chamada recursivamente para percorrer o ramo esquerdo da árvore (alunos com nomes "menores" de acordo com a ordem alfabética). Isso permite que a função continue a busca por alunos com o idioma desejado em toda a árvore.

- **`if (strcmp(students->student.language, language) == 0) ...`** : Esta condição verifica se o idioma do aluno atual é igual ao idioma especificado. A função **`strcmp`** compara as strings do idioma do aluno e do idioma desejado. Se for igual (retorno zero), a função prossegue com a próxima etapa.

- **`printf("Name: %s - Level: %s - Language: %s\n", ...`** : Se a condição anterior for verdadeira, a função imprime informações sobre o aluno que atende aos critérios, incluindo o nome do aluno, o nível e o idioma, formatados em uma mensagem legível.

- **`show_students_by_language(students->right, language);`** : Após exibir as informações do aluno, a função é chamada recursivamente para percorrer o ramo direito da árvore (alunos com nomes "maiores" de acordo com a ordem alfabética), permitindo que a busca continue na parte direita da árvore.

A função **`show_students_by_language`** é útil para localizar e exibir informações específicas dos alunos com base em critérios de idioma. Por exemplo, ao chamar **`show_students_by_language(root, "English");`**, a função exibirá os detalhes de todos os alunos que têm "English" como seu idioma na árvore de alunos.

12. ### find_min

```c
Node* find_min(Node* node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}
```

A função **`find_min`** é usada para encontrar o nó com o valor mínimo (o aluno com o nome mais baixo em ordem alfabética) em uma árvore binária de busca. O funcionamento da função é explicado da seguinte forma:

- A função recebe um nó da árvore como argumento, que é onde a busca começa.

- Enquanto o nó da esquerda do nó atual não for nulo, o loop continua. Isso ocorre porque, em uma árvore binária de busca, o nó mais à esquerda contém o valor mínimo.

- Dentro do loop, o nó é atualizado para o seu filho esquerdo, o que move a busca para o próximo nó à esquerda na árvore.

- O loop continua até que o nó à esquerda seja nulo, indicando que o nó atual é o nó com o valor mínimo, pois não há mais filhos à esquerda.

- Quando o nó com o valor mínimo é encontrado, a função retorna esse nó.

Em resumo, a função **`find_min`** percorre a árvore binária de busca da raiz até o nó mais à esquerda, encontrando assim o nó com o valor mínimo. Essa função é comumente usada em operações de exclusão em árvores binárias de busca para encontrar o nó que deve ser removido quando não possui filhos à esquerda.

13. ### delete_student

```c
Node* delete_student(Node* node, const char* name) {
  if (node == NULL) return node;

  int comparison = strcmp(name, node->student.name);

  if (comparison < 0)
    node->left = delete_student(node->left, name);
  else if (comparison > 0)

    node->right = delete_student(node->right, name);
  else {
    if (node->left == NULL) {
      Node* temp = node->right;
      free(node);
      return temp;
    } else if (node->right == NULL) {
      Node* temp = node->left;
      free(node);
      return temp;
    }

    Node* temp = find_min(node->right);
    node->student = temp->student;
    node->right = delete_student(node->right, temp->student.name);
  }
  return node;
}
```

A função **`delete_student`** é usada para excluir um aluno da árvore binária de busca, com base no nome do aluno. Aqui está como a função funciona:

- A função recebe um nó da árvore e o nome do aluno que se deseja excluir.

- Se o nó passado for nulo (o que pode acontecer quando a busca chega a uma folha da árvore sem encontrar o aluno desejado), a função retorna nulo.

- A função compara o nome do aluno atual (no nó atual) com o nome que deseja-se excluir. Com base na comparação, a função decide se deve continuar a busca à esquerda (se o nome desejado for menor) ou à direita (se o nome desejado for maior).

- Se a comparação indicar que o nó atual contém o aluno a ser excluído (comparação igual a 0), a função inicia o processo de exclusão.

- Se o nó não tiver um filho à esquerda, ele é excluído e substituído por seu filho à direita (se houver um).

- Se o nó não tiver um filho à direita, ele é excluído e substituído por seu filho à esquerda.

- Se o nó tiver ambos os filhos, a função encontra o nó com o valor mínimo na subárvore à direita (usando a função **`find_min`**) e copia o conteúdo desse nó para o nó atual. Em seguida, a função exclui o nó com o valor mínimo na subárvore à direita.

- A função retorna o nó atual, que pode ter sido modificado ou substituído durante o processo de exclusão.

Portanto, a função **`delete_student`** permite excluir um aluno com base no nome, mantendo a propriedade da árvore binária de busca. Ela lida com três casos diferentes: se o nó a ser excluído não tiver filhos, se tiver apenas um filho e se tiver dois filhos.

14. ### change_student

```c
Node* change_student(Node* node, Node* student, Student change_student) {
  if (node == NULL) return node;

  if (student) {
    strncpy(student->student.name, change_student.name,
            sizeof(student->student.name));
    strncpy(student->student.class_level, change_student.class_level,
            sizeof(student->student.class_level));
    strncpy(student->student.language, change_student.language,
            sizeof(student->student.language));
  }

  return node;
}
```

A função **`change_student`** é usada para atualizar os campos de um aluno existente na árvore binária de busca. Aqui está como a função funciona:

- A função recebe três argumentos: o nó raiz da árvore, o nó do aluno a ser atualizado (ou seja, o nó que representa o aluno que se deseja alterar) e os novos dados do aluno (representados pela estrutura **`change_student`**).

- Primeiro, a função verifica se o nó atual (representado pelo argumento **`node`**) é nulo. Se for nulo, isso significa que a árvore está vazia ou que o aluno que se deseja alterar não foi encontrado na árvore. Nesse caso, a função simplesmente retorna o nó atual (que é nulo).

- Em seguida, a função verifica se o argumento **`student`** é diferente de nulo. Isso é importante porque o aluno que se deseja atualizar deve ser encontrado na árvore antes que qualquer atualização seja realizada.

- Se o nó do aluno a ser atualizado (**`student`**) não for nulo, a função utiliza a função **`strncpy`** para atualizar os campos do aluno com os novos valores fornecidos na estrutura **`change_student`**. Isso significa que os campos de nome, nível de classe e idioma do aluno no nó **`student`** serão atualizados com os valores correspondentes em **`change_student`**.

- Após a atualização, a função retorna o nó raiz original (representado pelo argumento **`node`**) sem fazer nenhuma modificação nele. Isso ocorre porque, em uma árvore binária de busca, a estrutura da árvore não deve ser alterada durante a atualização de um nó específico. Em vez disso, os campos do nó específico são atualizados.

Portanto, a função **`change_student`** permite a atualização dos campos de um aluno na árvore, mas não afeta a estrutura geral da árvore. O nó raiz original é retornado após a atualização.

## Tests

O arquivo [tree.tests.c](https://github.com/HermanoCastro65/crud-language-course-in-c/blob/creating-documentation/tree.tests.c) contém um conjunto de funções de teste que são usadas para verificar o funcionamento correto das funções definidas na árvore binária de busca. Vou explicar cada função individualmente:

1. **`run_test`**: Essa função é usada para executar um teste específico e imprimir o resultado do teste na saída padrão. Ela recebe o nome do teste, um valor de teste (0 para sucesso, 1 para falha) e um modo de teste (que não parece estar sendo usado no código fornecido).

2. **`test_constants`** : Este teste verifica se as constantes **`class_level_types`** e **`language_types`** são definidas corretamente e se seus valores correspondem aos esperados. Qualquer discrepância é relatada como uma falha.

3. **`test_is_empty`** : Verifica se a função **`is_empty`** está funcionando corretamente para um nó vazio e para um nó não vazio. Se a função retornar o resultado esperado, o teste é considerado bem-sucedido.

4. **`test_initialize_tree`** : Verifica se a função **`initialize_tree`** cria uma árvore vazia corretamente.

5. **`test_free_tree`** : Testa a função **`free_tree`** para garantir que ela libere adequadamente a memória associada à árvore. A função cria uma árvore com alguns nós de aluno, chama **`free_tree`** e verifica se a árvore é liberada corretamente.

6. **`test_generate_registration`** : Testa a função **`generate_registration`**, que gera números de registro aleatórios. Verifica se os números gerados estão dentro do intervalo esperado.

7. **`test_create_node`** : Verifica se a função **`create_node`** cria corretamente um novo nó com os valores de aluno, esquerda e direita fornecidos.

8. **`print_student_names`** e **`is_tree_alphabetical`** : Estas funções não são testes individuais, mas são usadas para verificar se a árvore está em ordem alfabética. A função **`print_student_names`** imprime os nomes dos alunos na ordem correta, e **`is_tree_alphabetical`** verifica se a árvore está em ordem.

9. **`test_include_student`** : Testa a função **`include_student`**, que insere alunos na árvore de acordo com a ordem alfabética de seus nomes e verifica se a árvore permanece ordenada após a inserção.

10. **`test_list_all_students`** : Testa a função **`list_all_students`** para listar todos os alunos da árvore.

11. **`test_search_student`** : Verifica se a função **`search_student`** encontra um aluno específico na árvore.

12. **`test_show_student`**: Testa a função **`show_student`** para exibir informações sobre um aluno específico.

13. **`test_show_students_by_language`**: Testa a função **`show_students_by_language`** para mostrar alunos com base no idioma especificado.

14. **`test_delete_student`**: Testa a função **`delete_student`** para remover um aluno da árvore.

15. **`test_change_student`**: Testa a função **`change_student`** para verificar se ela atualiza corretamente os campos de um aluno na árvore.

Essas funções de teste ajudam a garantir que as funções da árvore estejam funcionando conforme o esperado e fornecem feedback sobre o sucesso ou a falha de cada função.

## File
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "tree.h"

Node* read_file_and_insert_into_tree(Node* root) {
  FILE* file = fopen("students.txt", "r");
  if (file == NULL) {
    printf("Unable to open the file.\n");
    return root;
  }

  char line[100];
  Student student;

  while (fgets(line, sizeof(line), file) != NULL) {
    line[strcspn(line, "\n")] = '\0';

    strncpy(student.name, line, sizeof(student.name));

    student.registration = generate_registration();

    if (fgets(line, sizeof(line), file) != NULL) {
      line[strcspn(line, "\n")] = '\0';
      strncpy(student.class_level, line, sizeof(student.class_level));
    }
    if (fgets(line, sizeof(line), file) != NULL) {
      line[strcspn(line, "\n")] = '\0';
      strncpy(student.language, line, sizeof(student.language));
    }

    root = include_student(root, student);
  }

  fclose(file);

  if (!is_tree_alphabetical(root)) exit(1);
  printf("SYSTEM LOADED SUCCESSFULLY\n");
  getchar();
  return root;
}
```

Este código lê informações de um arquivo chamado "students.txt" e insere essas informações em uma árvore binária de busca. Vou explicar cada parte do código:

- **`#include <stdio.h>`** : Inclui a biblioteca padrão de E/S (entrada/saída) em C para usar funções relacionadas à leitura e gravação de arquivos.

- **`#include <stdlib.h>`** : Inclui a biblioteca padrão em C, que contém funções para alocação dinâmica de memória e outras operações.

- **`#include <string.h>`** : Inclui a biblioteca padrão em C para operações de strings, como **`strncpy`** e **`strcspn`**.

- **`#include "constants.h"`** : Inclui o arquivo de cabeçalho "constants.h", que contém as definições de constantes, como os tipos de níveis de classe e idiomas.

- **`#include "tree.h"`** : Inclui o arquivo de cabeçalho "tree.h", que contém a definição da estrutura da árvore e as funções relacionadas a ela.

- **`Node* read_file_and_insert_into_tree(Node* root)`** : Esta é a função principal que lê o arquivo "students.txt" e insere os alunos na árvore. Ela recebe um ponteiro para a raiz da árvore como entrada e retorna a raiz da árvore após a inserção.

- **`FILE* file = fopen("students.txt", "r");`** : Abre o arquivo "students.txt" em modo de leitura ("r"). Se o arquivo não puder ser aberto, exibe uma mensagem de erro e retorna a raiz da árvore inalterada.

- **`char line[100];`** : Declara um array de caracteres chamado "line" com espaço para 100 caracteres. Isso será usado para armazenar as linhas lidas do arquivo.

- **`Student student;`** : Declara uma variável do tipo **`Student`** chamada "student" para armazenar as informações lidas do arquivo.

- O loop **`while (fgets(line, sizeof(line), file) != NULL)`** lê cada linha do arquivo usando a função **`fgets`**. A função **`strcspn(line, "\n")`** remove o caractere de nova linha (se existir) no final de cada linha.

- Os dados lidos do arquivo são copiados para a estrutura "student" usando a função **`strncpy`**. Isso inclui o nome, número de registro, nível de classe e idioma.

- A função **`include_student`** é usada para inserir o aluno na árvore, com base no nome do aluno.

- Após a conclusão da leitura do arquivo e da inserção dos alunos na árvore, o arquivo é fechado com **`fclose(file)`**.

- A função verifica se a árvore está em ordem alfabética usando a função **`is_tree_alphabetical`**. Se não estiver, o programa é encerrado com **`exit(1)`**.

- Por fim, a função imprime uma mensagem de sucesso e aguarda uma entrada do usuário antes de retornar a raiz da árvore.

Este código lê um arquivo de texto com informações de alunos, insere essas informações em uma árvore binária de busca e verifica se a árvore está em ordem alfabética. Isso permite que o sistema carregue dados de alunos a partir de um arquivo de texto.

## Application

O arquivo [app.h](https://github.com/HermanoCastro65/crud-language-course-in-c/blob/creating-documentation/app.h) é um arquivo de cabeçalho que contém as declarações de funções e as inclusões de outros arquivos necessários para a aplicação principal. Vou explicar cada parte do arquivo:

- **`#include "constants.h"`** : Inclui o arquivo de cabeçalho "constants.h" que contém definições de constantes, como os tipos de níveis de classe e idiomas.

- **`#include "tree.h"`** : Inclui o arquivo de cabeçalho "tree.h," que contém a definição da estrutura da árvore e as funções relacionadas a ela.

- **`#include "file.h"`** : Inclui o arquivo de cabeçalho "file.h," que contém funções relacionadas à leitura e escrita de arquivos.

- **`void clear_console(void);`** : Declaração da função **`clear_console`**, que é responsável por limpar a tela do console. Essa função pode ser usada para melhorar a apresentação na interface do usuário.

- **`int run_all_tests(char* test_mode);`** : Declaração da função **`run_all_tests`**, que executa todos os testes definidos na aplicação. Ela recebe um argumento **`test_mode`** para controlar o modo de execução dos testes.

- **`void main_menu(void);`** : Declaração da função **`main_menu`**, que representa o menu principal da aplicação. Essa função é responsável por exibir as opções disponíveis ao usuário e direcioná-lo para diferentes partes da aplicação.

- **`Student add_student_menu(void);`** : Declaração da função **`add_student_menu`**, que é responsável por coletar informações do usuário para adicionar um novo aluno à árvore. Ela retorna uma estrutura **`Student preenchida com os dados fornecidos pelo usuário.

- **`char* chose_language_menu(void);`**: Declaração da função **`chose_language_menu`**, que exibe um menu para permitir que o usuário escolha um idioma a partir das opções definidas e retorna o idioma escolhido.

Essas declarações de função e inclusões de cabeçalho são importantes para a organização e funcionamento da aplicação principal. Elas fornecem acesso às funcionalidades da árvore, aos testes e à manipulação de arquivos, além de definir a estrutura geral do menu da aplicação.

O início do arquivo app.c inclui várias diretivas de pré-processador, incluindo inclusões de cabeçalho e definições de bibliotecas padrão. Vou explicar cada parte:

- **`#include <stdio.h>`** : Isso inclui o cabeçalho da biblioteca padrão de E/S em C. Ele é usado para acessar funções de entrada e saída, como **`printf`** e **`scanf`**, que permitem que o programa interaja com o usuário e exiba mensagens no console.

- **`#include <stdlib.h>`** : Isso inclui o cabeçalho da biblioteca padrão em C que fornece funções para alocação de memória, conversões numéricas, geração de números aleatórios e outras operações de sistema. Essa biblioteca é usada para funções como **`malloc`**, **`free`** e **`exit`**.

- **`#include <string.h>`** : Isso inclui o cabeçalho da biblioteca padrão de manipulação de strings em C. Ele fornece funções para operações de strings, como **`strncpy`** e **`strcmp`**. Essas funções são usadas para manipular cadeias de caracteres (strings) na aplicação.

- **`#include "app.h"`**: Isso inclui o arquivo de cabeçalho "app.h," que contém as declarações de funções, estruturas e inclusões de cabeçalho específicas para a aplicação principal. O arquivo "app.h" descreve as funcionalidades do programa e como ele interage com outras partes do código.

Essas inclusões de cabeçalho e definições de bibliotecas são essenciais para o funcionamento da aplicação. Elas fornecem acesso a funcionalidades fundamentais, como entrada/saída, alocação de memória, manipulação de strings e definições específicas da aplicação que são necessárias para a implementação da lógica do programa.

- **Applications:**

* [run_all_tests](#run_all_tests)
* [main_menu](#main_menu)
* [add_student_menu](#add_student_menu)
* [chose_language_menu](#chose_language_menu)

1. ### run_all_tests

```c
int run_all_tests(char* test_mode) {
  printf("\nRUNING ALL TESTS: \n\n");
  run_test("constants", test_constants(), test_mode);
  run_test("is_empty()", test_is_empty(), test_mode);
  run_test("initialize_tree()", test_initialize_tree(), test_mode);
  run_test("free_tree()", test_free_tree(), test_mode);
  run_test("generate_registration()", test_generate_registration(), test_mode);
  run_test("create_node()", test_create_node(), test_mode);
  run_test("include_student()", test_include_student(), test_mode);
  run_test("list_all_students()", test_list_all_students(), test_mode);
  run_test("search_student()", test_search_student(), test_mode);
  run_test("show_student()", test_show_student(), test_mode);
  run_test("show_students_by_language()", test_show_students_by_language(), test_mode);
  run_test("delete_student()", test_delete_student(), test_mode);
  run_test("change_student()", test_change_student(), test_mode);
  if(!test_mode) clear_console(); 
  
  return 0;
}
```

A função **`run_all_tests`** é responsável por executar uma série de testes da aplicação. Aqui está uma breve explicação do seu funcionamento:

- Ela recebe um argumento **`test_mod`**e, que determina se os resultados dos testes serão exibidos no console ou não.

- Em seguida, ela imprime uma mensagem informando que todos os testes estão sendo executados.

- Chama a função **`run_test`** para cada teste, fornecendo o nome do teste, a função do teste e o **`test_mode`** como argumentos. Essa função é usada para executar testes individuais.

- A função **`run_test`** imprime se o teste passou ou falhou, com base no valor retornado pela função de teste.

- Após executar todos os testes, a função verifica se **`test_mode`** é nulo (ou seja, se não estamos em modo de teste interativo) e, se for esse o caso, chama a função **`clear_console`** para limpar o console, removendo as saídas dos testes.

- Finalmente, a função retorna 0 para indicar que todos os testes foram concluídos.

Essa função é usada para automatizar a execução de testes unitários e exibir os resultados, facilitando a verificação da integridade do código. O **`test_mode`** permite que os testes sejam executados sem interação do usuário (modo de teste) ou com interação (modo interativo), dependendo de como o programa é executado.

2. ### main_menu

```c
void main_menu() {
  Node* students = initialize_tree();
  students = read_file_and_insert_into_tree(students);

  int option = 0, get_out = 0;

  do {
    clear_console();

    printf("\n(1) List students");
    printf("\n(2) Add student");
    printf("\n(3) Change student");
    printf("\n(4) Consult student");
    printf("\n(5) Delete student");
    printf("\n(6) Show students by language");
    printf("\n(7) Exit");
    printf("\n\nChoose option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        clear_console();
        printf("\nREGISTERED STUDENTS: \n\n");
        list_all_students(students);
        getch();
        break;
      case 2:
        printf("\nADD NEW STUDENT: \n\n");
        Student new_student = add_student_menu();
        if (new_student.registration) {
          students = include_student(students, new_student);
          printf("\nSTUDENT SUCCESSFULY INCLUDED \n\n");
        }
        getch();
        break;
      case 3:
      	clear_console();
        printf("\nCHANGE STUDENT: \n\n");
        print_student_names(students);
        char change_student_name[25];
        printf("\nChange student by name: ");
        scanf("%s", &change_student_name);
        clear_console();
        printf("\nSTUDENT: \n\n");
        Node* consult_change_student = search_student(students, change_student_name);
        if (consult_change_student) {
          show_student(consult_change_student->student);
          printf("\nCHANGE STUDENT \n\n");
          getch();
          int current_registration = consult_change_student->student.registration;
          Student change_student_informations = add_student_menu();
          if (change_student_informations.registration) {
          	change_student_informations.registration = current_registration;
            students = change_student(students, consult_change_student,
                                      change_student_informations);
            printf("\nSTUDENT SUCCESSFULY CHANGED \n\n");
          }
        } else
          printf("NOT FOUND ");
        getch();
        break;
      case 4:
        clear_console();
        printf("\nCONSULT STUDENT: \n\n");
        print_student_names(students);
        char student_name[25];
        printf("\nSearch student by name: ");
        scanf("%s", &student_name);
        clear_console();
        printf("\nSTUDENT: \n\n");
        Node* consult_student = search_student(students, student_name);
        if (consult_student)
          show_student(consult_student->student);
        else
          printf("NOT FOUND ");
        getch();
        break;
      case 5:
        clear_console();
        printf("\nDELETE STUDENT: \n\n");
        print_student_names(students);
        char delete_student_name[25];
        printf("\nDelete student by name: ");
        scanf("%s", &delete_student_name);
        Node* search_delete_student = search_student(students, delete_student_name);
        if(search_delete_student) {
          students = delete_student(students, delete_student_name);
          printf("\nSTUDENT DELETED \n\n");
        }
        else
          printf("\nNOT FOUND ");
        getch();
        break;
      case 6:
        clear_console();
        printf("\nSHOW STUDENTS BY LANGUAGE: \n\n");
        printf("\nSearch students by language: ");
        char* language = chose_language_menu();
        if (language) show_students_by_language(students, language);
        getch();
        break;
      case 7:
        printf("\nEXIT\n\n");
        get_out = 1;
        break;
      default:
        printf("\nINVALID OPTION! \n");
        getch();
        get_out = 0;
    }
  } while (!get_out);
}
```

A função **`main_menu`** é o núcleo da interação com o usuário do programa e controla o menu principal da aplicação. Aqui está uma breve explicação do seu funcionamento:

- Ela começa inicializando uma árvore de estudantes (**`students`**) e em seguida lê os dados de um arquivo e os insere na árvore utilizando a função **`read_file_and_insert_into_tree`**.

- Em seguida, entra em um loop que exibe as opções do menu e lê a opção escolhida pelo usuário.

- Dependendo da opção escolhida, o programa executa as seguintes ações:

1. **`List students (1)`** : Lista todos os estudantes registrados.
2. **`Add student (2)`** : Permite ao usuário adicionar um novo estudante.
3. **`Change student (3)`** : Permite ao usuário alterar informações de um estudante existente.
4.**`Consult student (4)`** : Permite ao usuário procurar informações sobre um estudante por nome.
5. **`Delete student (5)`** : Permite ao usuário excluir um estudante por nome.
6. **`Show students by language (6)`** : Permite ao usuário listar estudantes com base no idioma escolhido.
7. **`Exit (7)`** : Encerra o programa.

- O programa continua executando até que o usuário escolha a opção "Exit".

- Cada opção do menu executa a ação apropriada e interage com o usuário para coletar informações necessárias, como nome do estudante, informações de alteração, idioma, etc.

- Após a conclusão da ação escolhida, o programa geralmente exibe uma mensagem informativa, aguarda um pressionamento de tecla (**`getch`**) e, em seguida, volta ao menu principal.

Essa função é responsável por fornecer a interface de linha de comando para o programa, permitindo ao usuário realizar operações em uma coleção de estudantes e visualizar informações sobre eles.

3. ### add_student_menu

```c
Student add_student_menu() {
  Student new_student;

  int option = 0, get_out = 0, get_out_language = 0, get_out_level = 0, i = 0,
      language = 0, level = 0;

  do {
    clear_console();

    get_out_language = 0;
    get_out_level = 0;

    printf("\nName: ");
    scanf("%s", &new_student.name);

    printf("\nAvailable languages: ");
    for (i = 0; i < 4; i++) printf("\n(%d) %s", i + 1, language_types[i]);
    printf("\n(5) Cancel\n");
    printf("\nLanguage: ");
    scanf("%d", &language);

    switch (language) {
      case 1:
        strncpy(new_student.language, language_types[0],
                sizeof(new_student.language));
        break;
      case 2:
        strncpy(new_student.language, language_types[1],
                sizeof(new_student.language));
        break;
      case 3:
        strncpy(new_student.language, language_types[2],
                sizeof(new_student.language));
        break;
      case 4:
        strncpy(new_student.language, language_types[3],
                sizeof(new_student.language));
        break;
      case 5:
        printf("\nOPERATION CANCELED \n");
        new_student.registration = 0;
        return new_student;
      default:
        printf("\nINVALID OPTION! \n");
        get_out_language = 1;
        getch();
    }

    if (!get_out_language) {
      printf("\nClass level: ");
      for (i = 0; i < 3; i++) printf("\n(%d) %s", i + 1, class_level_types[i]);
      printf("\n(4) Cancel\n");
      printf("\nLevel: ");
      scanf("%d", &level);

      switch (level) {
        case 1:
          strncpy(new_student.class_level, class_level_types[0],
                  sizeof(new_student.class_level));
          break;
        case 2:
          strncpy(new_student.class_level, class_level_types[1],
                  sizeof(new_student.class_level));
          break;
        case 3:
          strncpy(new_student.class_level, class_level_types[2],
                  sizeof(new_student.class_level));
          break;
        case 4:
          printf("\nOPERATION CANCELED \n");
          new_student.registration = 0;
          return new_student;
        default:
          printf("\nINVALID OPTION! \n");
          get_out_level = 1;
          getch();
      }
    }

    if (!get_out_language && !get_out_level) {
      new_student.registration = generate_registration();
      return new_student;
    }

  } while (!get_out_language || !get_out_level);
}
```

A função **`add_student_menu`** permite ao usuário inserir informações sobre um novo estudante. Aqui está uma breve explicação de como funciona:

- Ela declara uma estrutura **`Student`** chamada **`new_student`** para armazenar as informações do novo estudante.

- Inicializa variáveis para controlar o fluxo do menu, como **`option`**, **`get_out`**, **`get_out_language`**, **`get_out_level`**, **`i`**, **`language`**, e **`level`**.

- Entra em um loop que exibe o menu para coletar informações sobre o novo estudante.

- O usuário é solicitado a inserir o nome do estudante.

- Em seguida, o usuário é solicitado a escolher um idioma a partir de uma lista de idiomas disponíveis (definidos em **`language_types`**).

- Dependendo da escolha do usuário, o programa atribui o idioma escolhido à estrutura **`new_student`**.

- Se o usuário escolher a opção "Cancelar" (opção 5), a função exibirá uma mensagem informando que a operação foi cancelada e definirá o campo **`registration`** de **`new_student`** como 0, indicando que a operação foi cancelada.

- Se o usuário escolher uma opção inválida para o idioma, a função informa que a opção é inválida, define **`get_out_language`** como 1 e espera que o usuário pressione uma tecla antes de continuar.

- Após coletar o idioma, o programa solicita ao usuário que escolha o nível de classe do estudante a partir de uma lista de níveis disponíveis (definidos em **`class_level_types`**).

- Dependendo da escolha do usuário, o programa atribui o nível de classe escolhido à estrutura **`new_student`**.

- Se o usuário escolher a opção "Cancelar" para o nível, a função exibirá uma mensagem informando que a operação foi cancelada e definirá o campo **`registration`** de **`new_student`** como 0.

- Se o usuário escolher uma opção inválida para o nível, a função informa que a opção é inválida, define **`get_out_level`** como 1 e espera que o usuário pressione uma tecla antes de continuar.

- Se o usuário tiver escolhido um idioma e um nível válidos (ou seja, **`get_out_language`** e **`get_out_level`** são ambos 0), a função gera um número de registro aleatório usando **`generate_registration`** e atribui o resultado ao campo **`registration`** de **`new_student`**.

- Finalmente, a função retorna a estrutura **`new_student`**, que agora contém as informações do novo estudante.

Essa função é projetada para guiar o usuário na entrada das informações do estudante, garantindo que o usuário escolha opções válidas para idioma e nível e permitindo que o usuário cancele a operação a qualquer momento.

4. ### chose_language_menu

```c
char* chose_language_menu() {
  int language = 0, get_out = 0, i = 0;

  for (i = 0; i < 4; i++) printf("\n(%d) %s", i + 1, language_types[i]);
  printf("\n\nLanguage: ");
  scanf("%d", &language);

  switch (language) {
    case 1:
      clear_console();
      printf("\nLANGUAGE: %s\n\n", language_types[0]);
      return language_types[0];
      break;
    case 2:
      clear_console();
      printf("\nLANGUAGE: %s\n\n", language_types[1]);
      return language_types[1];
      break;
    case 3:
      clear_console();
      printf("\nLANGUAGE: %s\n\n", language_types[2]);
      return language_types[2];
      break;
    case 4:
      clear_console();
      printf("\nLANGUAGE: %s\n\n", language_types[3]);
      return language_types[3];
      break;
    default:
      printf("\nINVALID OPTION! \n");
      return NULL;
  }
}
```

A função **`chose_language_menu`** permite ao usuário escolher um idioma a partir de uma lista de idiomas disponíveis (definidos em **`language_types`**). Aqui está uma breve explicação de como funciona:

- A função inicializa variáveis, como **`language`**, **`get_out`**, e **`i`**.

- Em um loop, a função exibe a lista de idiomas disponíveis, numerados de 1 a 4 (com base na posição no array **`language_types`**).

- O usuário é solicitado a escolher um idioma digitando o número correspondente.

- Dependendo da escolha do usuário, o programa limpa o console (chamando a função **`clear_console`**) para melhorar a apresentação e exibe uma mensagem informando o idioma escolhido. Em seguida, a função retorna o nome do idioma escolhido.

- Se o usuário escolher uma opção inválida, a função exibe a mensagem "OPÇÃO INVÁLIDA!" e retorna **`NULL`** para indicar que a seleção foi inválida.

Essa função permite ao usuário escolher um idioma disponível e retorna o nome do idioma escolhido ou **`NULL`** em caso de seleção inválida.

## Main

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"

int main(int argc, char* argv[]) {
  if (argv[1])
    if (strcmp(argv[1], "-test") != 0) {
      printf("\n\nINVALID ARGUMENT: '%s' \ntry '-test' for test mode\n\n",
             argv[1]);
      exit(1);
    }

  if (run_all_tests(argv[1])) exit(1);

  main_menu();

  return 0;
}
```

A função **`main`** é a função principal do programa. Aqui está uma breve explicação de como ela funciona:

1. Ela recebe dois argumentos como entrada: **`int argc`** e **`char* argv[]`**. Esses argumentos são comuns em programas C e C++ e representam o número de argumentos passados para o programa e um array de strings contendo os argumentos em si.

2. O programa começa verificando se o primeiro argumento (**`argv[1]`**) foi fornecido. Isso é feito com a condição **`if (argv[1])`**. Se **`argv[1]`** for diferente de nulo (ou seja, se um argumento foi fornecido), o programa verifica se o argumento é igual a **`"-test"`** usando a função **`strcmp`**. Se o argumento não for igual a **`"-test"`**, o programa exibe uma mensagem de erro indicando que o argumento é inválido e como usar o programa corretamente (no modo de teste) e encerra com um código de saída 1.

3. Se o programa não entrar na primeira condição (ou seja, se o argumento for nulo ou igual a **`"-test"`**), ele avança para a próxima etapa.

4. O programa chama a função **`run_all_tests(argv[1])`**. Esta função é responsável por executar todos os testes e verificar se eles passam com sucesso. Se algum teste falhar, a função **`run_all_tests`** retornará um valor diferente de zero e o programa principal encerrará com um código de saída 1, indicando que ocorreu um erro.

5. Se todos os testes passarem com sucesso, o programa chama a função **`main_menu()`**. Esta função inicia o menu principal do programa, que permite ao usuário executar várias operações, como listar estudantes, adicionar estudantes, alterar estudantes, consultar estudantes, excluir estudantes, mostrar estudantes por idioma ou sair do programa.

6. Após o término do **`main_menu()`**, o programa retorna 0 para indicar que a execução foi concluída com sucesso.

Em resumo, o **`main`** é responsável por verificar os argumentos de linha de comando, executar testes se necessário e iniciar o menu principal do programa. Se tudo correr bem, o programa funcionará normalmente; caso contrário, ele retornará códigos de saída diferentes de zero para indicar problemas.