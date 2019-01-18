function read_file () {
    console.log('::read_file ');
    var fs = require('fs-js');
    console.log("fs = ",  fs);
    

    // fsx.open('/clamav/test.txt', 'r', (err, fd) => {
    // 	if (err) throw err;

    // 	var buffer = new Buffer(10);
    // 	fsx.read(fd, buffer, 0, buffer.length, null, function(error, bytesRead, buffer) {
    //       var data = buffer.toString("utf8", 0, buffer.length);
    //       console.log(data);
    //     });
    // 	fsx.close(fd, (err) => {
    // 	    if (err) throw err;
    // 	});
    // });

    return "return value of read_file";
};

export {read_file};
