FROM gcc:4.9
WORKDIR /app

COPY main-3.c main.c

RUN gcc main.c -O3 -Wall -ffast-math -o main

ENTRYPOINT ["./main"]


# FROM python:3
# WORKDIR /app

# COPY main-cache.py main.py
# COPY cache .

# ENTRYPOINT ["python3", "main.py"]


