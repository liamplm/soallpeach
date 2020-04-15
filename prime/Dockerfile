FROM gcc
WORKDIR /app

COPY main-xxx.c main.c

RUN gcc main.c -O3 -o main

ENTRYPOINT ["./main"]


# FROM python:3
# WORKDIR /app

# COPY main-cache.py main.py
# COPY cache .

# ENTRYPOINT ["python3", "main.py"]


