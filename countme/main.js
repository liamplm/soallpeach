const http = require('http');
const cluster = require("cluster");
const CPU_COUNT = require('os').cpus().length;
const PORT = parseInt(process.argv[2])

//let nums = [];

if (cluster.isMaster) {
    let num = 0;

    function sum(arr) {
        let res = 0;
        for (let i = 0; i < arr.length; i++) {
            res += arr[i];
        }
        return res;
    }

    for (let i = 0; i < CPU_COUNT; i++) {
        const worker = cluster.fork();
        worker.on('message', (msg) => {
            //console.log('[master]', msg)
            if (msg == 'get') {
                worker.send(num)
            } else {
                num += msg
            }
        })
    }
} else {

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



    function getSumFromMaster() {
        return new Promise((resolve) => {
            process.send('get', () => {
                //console.log('send req')
                process.on('message', (num) => {
                    //console.log('resuslt => ', num)
                    resolve(num);
                })
            })
        })
    }

    const server = http.createServer(async (req, res) => {
        //console.log('new req', process.pid, req.method)
        if (req.method == 'POST') {
            // Add number
            const body = await getBody(req);
            process.send(parseInt(body))
            //nums.push(parseInt(body));
            res.end()
        } else {
            // Get result
            const sum = await getSumFromMaster()
            res.end(sum.toString());
            //res.end(sum(nums).toString());
        }
    })

    server.listen(PORT, () => {
        console.log(`Server is listening on ${PORT}`)
    })

    process.on('SIGINT', () => { process.exit(); });

}
