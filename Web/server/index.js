import * as http from "http";
// const http =require("http");
// http is a module(object) which has some inbuilt propeties used to perform functions in server 


let value = "Hello World!";
console.log("Node.js First Program", value);

const server = http.createServer((req , res) => {
    res.writeHead(200,{'Content-Type': 'application/json'}),
    res.end(JSON.stringify({response : "Hello from server"}));
}) 
// req is argument passed by client and res is the object created by node server
// nodemon --> starts the server in monitoring mode .

const hostname = "127.0.0.1";

const port =  5000;

server.listen(port,hostname);
