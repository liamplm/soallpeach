FROM node:lts

WORKDIR /usr/src/app

COPY package*.json ./
COPY index.js ./

RUN npm i

ENTRYPOINT ["node", "index.js"]

