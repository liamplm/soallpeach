const http = require('http');
const cluster = require("cluster");
const CPU_COUNT = require('os').cpus().length;
const PORT = parseInt(process.argv[2])

//let nums = [];

if (cluster.isMaster) {
    let num = 0;

    for (let i = 0; i < CPU_COUNT; i++) {
        const worker = cluster.fork();
        worker.on('message', (msg) => {
            //console.log('[master]', msg)
            if (msg == 'get') {
                worker.send(num)
            } else {
                num += parseInt(msg);
            }
        })
    }
} else {

    function getBody(req, cb) {
        let body = '';
        req.on('data', (chunk) => {
            body += chunk;
        })
        req.on('end', () => cb(body))
    }

    function getSumFromMaster(cb) {
        process.send('get', () => {
            process.on('message', cb)
        })
    }

    const server = http.createServer((req, res) => {
        if (req.method == 'POST') {
            // Add number
            getBody(req, (body) => {
                process.send(body)
                res.end()
            });
        } else {
            // Get result
            getSumFromMaster((sum) => {
                res.end(sum.toString());
            })
        }
    })

    server.listen(PORT, () => {
        console.log(`Server is listening on ${PORT}`)
    })

    process.on('SIGINT', () => { process.exit(); });
}
