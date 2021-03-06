import React, { Component } from 'react'

import axios from 'axios'

const endpoint = 'http://ec2-52-211-128-21.eu-west-1.compute.amazonaws.com:8080/upload'

class Apploader extends Component {
    constructor(props) {
	super()
	//props.cb("test cb-arg");
	this.state = {
	    selectedFile: null,
	    loaded: 0,
	    f: props.cb,
	}

    }
    
    handleselectedFile = event => {
	this.setState({
	    selectedFile: event.target.files[0],
	    loaded: 0,
	})
    }
    
    handleUpload = () => {
	const data = new FormData()
	data.append('file', this.state.selectedFile, this.state.selectedFile.name)
	
	axios
	    .post(endpoint, data, {
		onUploadProgress: ProgressEvent => {
		    this.setState({
			loaded: (ProgressEvent.loaded / ProgressEvent.total) * 100,
		    })
		},
	    })
	    .then(res => {
		console.log(res.statusText)
		console.log(res.data)
		// const retval = {status: 77, fn: res.data.ts, fn_ext: "some_ext"};
		// console.log(retval)
		this.state.f(res.data.fn, res.data.fn_ext, res.data.ts)
	    })
    }

    render() {
	return (
		<div className="App">
		<input type="file" name="" id="" onChange={this.handleselectedFile} />
		<button onClick={this.handleUpload}>Upload</button>
		<div> {Math.round(this.state.loaded, 2)} %</div>
		</div>
	)
    }
}

export default Apploader
