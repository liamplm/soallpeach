const express = require('express');
const app = express()

let count = 0;

app.post('/', (req, res) => {
    let body = '';
    req.on('data', (chunk) => {
        body += chunk;
    })
    req.on('end', () => {
        //console.log('end => ', body)
        count += parseInt(body);

        res.sendStatus(200);
    })

})

app.get('/count', (req, res) => {
    //console.log('==>', count)
    res.send(count.toString())
})

const PORT = 80;

app.listen(PORT, '0.0.0.0', () => {
    console.log(`server is listening on ${PORT} ...`)
})


