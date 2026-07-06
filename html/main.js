//document.getElementById("datetime").innerHTML = "WebSocket is not connected";

const websocket = new WebSocket('ws://'+location.hostname+'/');

function take_picture(){
	sendText("take_picture");
}

function fetch_picture(){
	const request = new Request("picture.jpeg");
	fetch(request)
	.then( function(response){
		if (!response.ok) {
			alert(`HTTP error! status: ${response.status}`);
		}
		return response.blob();
	})
	.then( function(response){
		const objectURL = URL.createObjectURL(response);
		const img = document.querySelector("#IMG");
		img.src = objectURL;
	});
}

function sendText(name) {
	console.log('sendText');
	var data = {};
	data["id"] = name;
	console.log('data=', data);
	json_data = JSON.stringify(data);
	console.log('json_data=' + json_data);
	websocket.send(json_data);
}

websocket.onopen = function(evt) {
	console.log('WebSocket connection opened');
	var data = {};
	data["id"] = "init";
	console.log('data=', data);
	json_data = JSON.stringify(data);
	console.log('json_data=' + json_data);
	websocket.send(json_data);
	//document.getElementById("datetime").innerHTML = "WebSocket is connected!";
}

websocket.onmessage = function(evt) {
	var msg = evt.data;
	console.log("msg=" + msg);
	var values = msg.split('\4'); // \4 is EOT
	//console.log("values=" + values);
	switch(values[0]) {
		case 'HEAD':
			console.log("HEAD values[1]=" + values[1]);
			var h1 = document.getElementById( 'header' );
			h1.textContent = values[1];
			break;

		case 'TEXT':
			console.log("TEXT values[1]=" + values[1]);
			var text1 = document.getElementById("text1");
			text1.textContent = values[1];
			break;

		case 'PICTURE':
			console.log("PICTURE");
			fetch_picture();
			break;

		default:
			break;
	}
}

websocket.onclose = function(evt) {
	console.log('Websocket connection closed');
	//document.getElementById("datetime").innerHTML = "WebSocket closed";
}

websocket.onerror = function(evt) {
	console.log('Websocket error: ' + evt);
	//document.getElementById("datetime").innerHTML = "WebSocket error????!!!1!!";
}
