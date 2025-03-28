# Usa uma imagem do Ubuntu com suporte ao GCC
FROM ubuntu:latest

# Atualiza os pacotes e instala o GCC e Make
RUN apt update && apt install -y gcc make

# Define o diretório de trabalho dentro do container
WORKDIR /app

# Copia todos os arquivos do projeto (incluindo main.c) para dentro do container
COPY . .

# Compila o código
RUN gcc -o sistema main.c

# Comando padrão ao rodar o container
CMD ["./sistema"]
