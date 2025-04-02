# Dockerfile.app
FROM gcc:latest AS builder

# Установка зависимостей
RUN apt-get update && \
    apt-get install -y \
    cmake \
    libgtest-dev \
    git

# Копирование исходного кода
WORKDIR /app
COPY . .

# Сборка проекта
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make

CMD cd build && \
    ctest --output-on-failure > /app/output/index.txt
