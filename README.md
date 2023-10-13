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