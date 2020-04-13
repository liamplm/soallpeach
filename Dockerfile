FROM pypy:3
WORKDIR /app

COPY main-cache.py main.py
COPY test-3.txt .
COPY cache .

ENTRYPOINT ["pypy3", "main.py", "./test-3.txt"]


