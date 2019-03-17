
function http_upload(some_str, cb) {
    const http = require('http');

    http.get('http://ec2-52-211-128-21.eu-west-1.compute.amazonaws.com:8080/', (resp) => {
	let data = '';

	// A chunk of data has been recieved.
	resp.on('data', (chunk) => {
	    data += chunk;
	});

	// The whole response has been received. Print out the result.
	resp.on('end', () => {
	    //console.log(JSON.parse(data).explanation);
	    cb(data);
	});

    }).on("error", (err) => {
	console.log("Error: " + err.message);
    });
}

export { http_req };
