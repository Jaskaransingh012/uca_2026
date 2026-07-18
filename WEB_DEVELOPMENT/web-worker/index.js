const worker = new Worker("worker.js");

const handleClick = () => {
  console.log("I am clicked");
};

worker.postMessage(25);

worker.onmessage = function (event) {
  console.log(event.data);
};
