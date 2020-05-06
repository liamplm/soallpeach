const http = require('http');
const cluster = require("cluster");

const PORT = parseInt(process.argv[2])

let nums = [];

function getBody(req) {
    return new Promise((resolve/*, reject*/) => {
        let body = '';
        req.on('data', (chunk) => {
            body += chunk;
        })
        req.on('end', () => resolve(body))
        //req.on('error', reject)
    })
}

function sum(arr) {
    let res = 0;
    for (let i = 0; i < arr.length; i++) {
        res += arr[i];
    }
    return res;
}

const server = http.createServer(async (req, res) => {
    if (req.method == 'POST') {
        // Add number
        const body = await getBody(req);
        nums.push(parseInt(body));
        res.end()
    } else {
        // Get result
        res.end(sum(nums).toString());
    }
})

server.listen(PORT, () => {
    console.log(`Server is listening on ${PORT}`)
})

