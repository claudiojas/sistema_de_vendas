# Sistema de Vendas

Este projeto faz parte da avaliação da graduação da UEMA/ADDS. Ele implementa um sistema de vendas simples, permitindo o cadastro de clientes e produtos, realização de vendas e consulta de informações registradas. O projeto foi desenvolvido em C e utiliza Docker para containerização e execução.

## Estrutura do Projeto

A estrutura do projeto é organizada da seguinte forma:

sistema_de_vendas/ │ <br>
  ├── docker-compose.yml <br>
  ├── Dockerfile <br>
  ├── main.c <br>



### Dockerfile

O `Dockerfile` é responsável por construir a imagem do Docker para o projeto. Ele contém as instruções necessárias para configurar o ambiente de execução do sistema de vendas, incluindo a instalação do compilador C e a execução do programa principal.

### docker-compose.yml

O `docker-compose.yml` define e gerencia o ambiente de containers Docker. Ele facilita a construção e execução do projeto sem precisar lidar com comandos complexos do Docker diretamente.

### main.c

O arquivo `main.c` contém o código-fonte do sistema de vendas, incluindo funções para cadastrar clientes e produtos, realizar vendas e consultar os dados registrados.

## Instruções para Execução

Para executar o projeto utilizando Docker, siga os seguintes passos:

### 1. Clone o repositório

Clone o repositório para o seu ambiente local:

```bash
git clone https://github.com/claudiojas/sistema_de_vendas.git
```

### 2. Construção da Imagem Docker

Navegue até o diretório do projeto e construa a imagem Docker com o seguinte comando:

```bash
docker build -t sistema_vendas .
```
### 3. Execução do Contêiner Docker
Após a construção da imagem, execute o contêiner com o comando:
```bash
docker run --rm -it sistema_vendas
```
Isso iniciará o programa no terminal, permitindo interagir com o sistema de vendas.

## Funcionalidades do Sistema

O sistema de vendas possui as seguintes funcionalidades:

- **Cadastrar Clientes**: Permite registrar informações sobre os clientes.
- **Cadastrar Produtos**: Permite cadastrar produtos no sistema, com a definição de nome, quantidade e valor.
- **Consultar Clientes**: Exibe a lista de clientes registrados.
- **Consultar Produtos**: Exibe a lista de produtos cadastrados, com suas quantidades e valores.
- **Realizar Vendas**: Permite realizar uma venda, associando um cliente a um produto e registrando a quantidade vendida.
- **Consultar Vendas**: Exibe as vendas realizadas, com detalhes sobre os produtos e clientes.

## Tecnologias Utilizadas

- **Linguagem de Programação**: C
- **Docker**: Para containerização e execução do ambiente de desenvolvimento.

## Repositório Git

- **SSH**: `git@github.com:claudiojas/sistema_de_vendas.git`
- **HTTPS**: [https://github.com/claudiojas/sistema_de_vendas.git](https://github.com/claudiojas/sistema_de_vendas.git)

## Contribuições

Se desejar contribuir para o projeto, sinta-se à vontade para realizar um fork e enviar pull requests. Qualquer melhoria ou correção será bem-vinda.


[Cláudio Soares - LinkedIn](https://www.linkedin.com/in/claudio-soares-dev/)
