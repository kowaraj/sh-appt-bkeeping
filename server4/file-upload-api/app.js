const express = require('express')
const path = require('path')
const logger = require('morgan')
const cookieParser = require('cookie-parser')
const bodyParser = require('body-parser')
const fileUpload = require('express-fileupload')
const cors = require('cors')

const app = express()

// view engine setup
app.set('views', path.join(__dirname, 'views'))
app.set('view engine', 'jade')

// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'))
app.use(cors())
app.use(bodyParser.json())
app.use(
  bodyParser.urlencoded({
    extended: false,
  }),
)
app.use(cookieParser())
app.use(fileUpload())
app.use('/public', express.static(__dirname + '/public'))

app.post('/upload', (req, res, next) => {
    let uploadFile = req.files.file
    var date = new Date();
    var ts_s = date.getTime();
    var ts_ms = date.getMilliseconds();
    var timestamp = ts_s + "_" + ts_ms;
    console.log(timestamp);
    const fileName_original = req.files.file.name;
    const fileNameExt = fileName_original.split('.').pop();
    const fileName_saved = timestamp + "." + fileNameExt;
    console.log(fileName_saved);
    
    uploadFile.mv(
	`${__dirname}/public/files/${fileName_saved}`,
	function (err) {
	    if (err) {
		return res.status(500).send(err)
	    }
	    res.json({
		fn: `${fileName_original}`,
		ts: `${timestamp}`,
		fn_ext: `${fileNameExt}`,
	    })
	},
    )
})

// catch 404 and forward to error handler
app.use(function (req, res, next) {
  const err = new Error('Not Found')
  err.status = 404
  next(err)
})

// error handler
app.use(function (err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message
  res.locals.error = req.app.get('env') === 'development' ? err : {}

  // render the error page
  res.status(err.status || 500)
  res.render('error')
})

module.exports = app
