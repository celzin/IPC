<div align="center" style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div>

# 🗂️​ Estrutura do Repositório

- `src/`: Diretório com os scripts C.
- `imgs/`: Diretório com as imagens utilizadas na documentação.
- `imgs/`: Diretório contendo as instruções do trabalho em PDF.

# ⚠️ Apresentação do Problema 

### Sistema de Gestão de Filas em Supermercado

<div align="justify">
Imagine que você foi contratado por um supermercado local para desenvolver um sistema de gestão de filas para os caixas. Esse supermercado deseja oferecer um atendimento eficiente e justo para todos os clientes, mas com atenção especial para aqueles que necessitam de prioridade, como idosos, gestantes e pessoas com deficiência. Para tanto, implemente um programa em C que simule um sistema de gerenciamento de filas em um supermercado, utilizando estruturas, listas encadeadas e filas com prioridade para organizar o atendimento dos clientes.
</div>

## Especificações:
<div align="justify">

### 1. Estruturas de Dados:
- **Cliente:**
    - Nome (máximo de 100 caracteres)
    - CPF (inteiro de 11 dígitos)
    - Prioridade (inteiro, onde 1 representa alta prioridade, 2 prioridade média, e 3 baixa prioridade)
    - Número de itens no carrinho (inteiro)
- **Caixa:**
    - Número de identificação do caixa (inteiro)
    - Estado do caixa (aberto ou fechado)

### 2. Número de Caixas:
 - O sistema deve começar com um número fixo de caixas, por exemplo, **5 caixas**. Todos os caixas iniciam como **abertos**.
 - O usuário pode **abrir ou fechar caixas** conforme necessário, mas não pode cadastrar novos caixas além dos 5 já disponíveis.
 - Se um caixa for fechado, os clientes na fila desse caixa devem ser realocados para outros caixas abertos.

### 3. Filas com Prioridade:
 - O sistema deve manter filas com prioridade para o atendimento dos clientes. Clientes com prioridade mais
alta (1) devem ser atendidos antes dos demais.
 - Cada caixa terá sua própria fila, e o sistema deve gerenciar essas filas de acordo com a prioridade dos
clientes.

### 4. Operações do Programa: 
O programa deve oferecer ao usuário as seguintes opções: 
   
1. Cadastrar um Cliente 
    - Solicitar nome, CPF, prioridade, e número de itens no carrinho. Adicionar o cliente à fila de acordo com a sua prioridade e o caixa escolhido. 

2. Atender um Cliente 
    - Remover o cliente da fila com maior prioridade para ser atendido no caixa especificado. 

3. Abrir ou Fechar um Caixa 
    - Permitir ao usuário abrir ou fechar um dos 5 caixas disponíveis. Se o caixa estiver fechado, os clientes na fila desse caixa devem ser realocados para outro caixa aberto. 

4. Imprimir a Lista de Clientes em Espera 
    - Exibir os dados dos clientes em espera em cada caixa, organizados por prioridade. 
    
5. Imprimir o Status dos Caixas 
    - Exibir o estado (aberto ou fechado) de cada caixa e o número de clientes em espera.

### Implementação Básica: 
- Estruturas e Funções:
    - Criar as estruturas `Cliente`, `Caixa`, e `FilaPrioridade` para armazenar os dados de cada entidade. 
    - Utilizar listas encadeadas para armazenar os registros de clientes nas filas de cada caixa. 
    - Implementar funções para as operações de cadastro, atendimento, abertura e fechamento de caixas, e impressão dos dados.

### Exemplo de Uso: 
O `main` deve apresentar um menu de opções ao usuário, que fique em loop e permita que se realize as operações mencionadas. Ao digitar 0, o programa deve terminar.

</div>

# Execução

<div align="justify">

Esse programa possui um arquivo `Makefile` que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

</div>

### Makefile

<table align="center">
  <tr>
    <th>Comando</th>
    <th>Função</th>
  </tr>
  <tr>
    <td><code>make clean</code></td>
    <td>Apaga a última compilação realizada contida na pasta build</td>
  </tr>
  <tr>
    <td><code>make</code></td>
    <td>Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build</td>
  </tr>
  <tr>
    <td><code>make run</code></td>
    <td>Executa o programa da pasta build após a realização da compilação</td>
  </tr>
</table>

# 📞 Contato

<table align="center">
  <tr>
    <th>Contribuinte</th>
    <th>Contato</th>
  </tr>
  <tr>
    <td>Celso</td>
    <td><a href="https://t.me/celso_vsf"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> </td>
  </tr>
</table>