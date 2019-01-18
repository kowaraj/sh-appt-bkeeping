module.exports.read_file = function () {

    var fs = require('fs-js');
    
    fs.open('/clamav/test.txt', 'r', (err, fd) => {
	if (err) throw err;

	var buffer = new Buffer(10);
	fs.read(fd, buffer, 0, buffer.length, null, function(error, bytesRead, buffer) {
          var data = buffer.toString("utf8", 0, buffer.length);
          console.log(data);
        });
	fs.close(fd, (err) => {
	    if (err) throw err;
	});
    });

    return "return value of read_file";
};

//export {read_file};
