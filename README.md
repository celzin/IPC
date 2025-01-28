# Sistema de Gestão de Filas em Supermercado

<div align="center" style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
</div>

## 🗂️​ Estrutura do Repositório

- `src/`: Diretório com os Scripts C.
- `docs/`: Diretório contendo as [Instruções do Trabalho](https://github.com/celzin/IPC/blob/main/docs/Trabalho_1.pdf) em PDF.

## ⚠️ Resumo do Problema 

<div align="justify">

Imagine que você foi contratado por um supermercado local para desenvolver um **sistema de gestão de filas** para os caixas. Esse supermercado deseja oferecer um atendimento eficiente e justo para todos os clientes, mas com atenção especial para aqueles que necessitam de prioridade, como idosos, gestantes e pessoas com deficiência. Para tanto, implemente um programa em C que simule um sistema de gerenciamento de filas em um supermercado, utilizando estruturas, listas encadeadas e filas com prioridade para organizar o atendimento dos clientes.

</div>

## ⚙️ Especificações

### 1. Estruturas de Dados: 
- **Cliente:** Nome (100 caracteres), CPF (11 dígitos), Prioridade (1, 2 ou 3), Itens no carrinho (inteiro).  
- **Caixa:** ID, Estado (aberto/fechado), Fila com prioridade.  

### 2. Número de Caixas:
- **5 caixas fixos**, todos iniciam abertos.  
- O usuário pode abrir/fechar caixas, mas **ao menos um deve permanecer aberto**.  
- Clientes de caixas fechados são **realocados para a menor fila disponível**.  

### 3. Filas com Prioridade:
- **Clientes com prioridade maior (1) são atendidos primeiro**.  
- As filas são **listas encadeadas ordenadas automaticamente**.  

### 4. Operações do Programa:  
1. **Cadastrar Cliente** – Nome, CPF, prioridade, itens, caixa válido e aberto.  
2. **Atender Cliente** – Remove o cliente com **maior prioridade** do caixa escolhido.  
3. **Abrir/Fechar Caixa** – Impede o fechamento do último caixa aberto; realoca clientes.  
4. **Lista de Clientes em Espera** – Exibe filas organizadas por prioridade.  
5. **Status dos Caixas** – Mostra quais caixas estão abertos e o número de clientes.  

### 5. Implementação: 
- Estruturas `Cliente`, `Caixa`, `FilaPrioridade`.  
- **Listas encadeadas** para filas com prioridade.  
- **Validações** para CPF, nome, prioridade, itens e caixa válido.  
- **Proteção contra entradas inválidas no menu**.  

### 6. Exemplo de Uso:  
O programa exibe um **menu contínuo**, permitindo operações até o usuário **escolher sair (0)**.  

</div>

## 🔄 Execução

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

## 📞 Contato

<table align="center">
  <tr>
    <th>Contribuinte</th>
    <th>Contato</th>
  </tr>
  <tr>
    <td>Celso Vinícius</td>
    <td><a href="https://www.linkedin.com/in/celsovinicius23/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/> </td>
  </tr>
</table>