FROM node:lts

WORKDIR /usr/src/app

COPY package*.json ./
COPY main.js ./

RUN npm i

CMD ["node", "main.js"]

