///The group/feed name and the API token (could be smart to parse this on server side)
const feedName = "hydroponie";
const apiToken = "f704760b2225debc64a79dedece9b60f049aacc0"

function debug(){
    randomizeDatas();
}

///Local storage of the datas value
var datasObj = {
    hum: {value : 60,
         lastUp : 0},
    temp: {value : 25,
         lastUp : 0},
    pump: {value : 0,
         lastUp : 0}
};

function randomizeDatas() {
    datasObj.hum.value  = getRandom(50, 100);
    datasObj.temp.value = getRandom(15, 35);
    datasObj.pump.value = getRandom(0, 2);
}



function sendRandomDatas() {
    randomizeDatas();

    sendData((Object.entries(datasObj)));
}


function sendData(dataArr){
    
    let dataToSend = "";
    dataArr.forEach(function (element) {
        console.log(element);
        dataToSend += element[0] + "=" + element[1].value + "&&"
    });
    dataToSend = dataToSend.slice(0, -2);

    
    let ioLink = `https://io.adafruit.com/api/groups/${feedName}/send.json?x-aio-key=${apiToken}&${dataToSend}`;
    fetch(ioLink).then(r => r.json())
        .then(data => computeData(data))
        .catch(e => console.log("pas ok"))
}


function getDatas() {
    var ioLink = `https://io.adafruit.com/api/groups/${feedName}/receive.json?x-aio-key=${apiToken}`;
    fetch(ioLink).then(r => r.json())
        .then(data => computeData(data))
        .catch(e => console.log("pas ok"))
}


function computeData(data) {

    var dataList = document.getElementById("dataList");

    dataList.innerHTML = ("");

    (data.feeds).forEach(function (element) {
        
        
        if (datasObj[element.name] == undefined) {
            datasObj[element.name] = {value : 0, lastUp : 0};
        }
        
        datasObj[element.name].value = (element.stream.value);
        
        console.log((element.stream.value));

        let date = Date.parse(element.last_value_at)    ;
        let timeDif = parseInt((Date.now() - date) / 1000);
        let html = `<li><b>${element.name}</b> : <u>${element.stream.value}</u> - (last edit ${timeDif}s ago)</li>`;

        dataList.innerHTML = dataList.innerHTML + (html.toString());

    });
}

const getRandom = (min, max) => Math.round(Math.random() * (max - min) + min);
