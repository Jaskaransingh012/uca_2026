self.onmessage=function(event){

    let number=event.data;

    let sum = 0;

    for(let i = 0;i<1000000000000;i++){
        sum += i*5;
    }

    self.postMessage(sum);

}
