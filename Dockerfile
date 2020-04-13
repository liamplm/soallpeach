FROM pypy:3
WORKDIR /app

COPY main-cache.py main.py
COPY cache .

ENTRYPOINT ["pypy3", "main.py"]


