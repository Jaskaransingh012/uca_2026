self.onmessage = async () => {
    try {
        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error(`HTTP Error: ${response.status}`);
        }

        let users = await response.json();

        console.log(users);

        users.users.forEach((element, index) => {
            console.log(element)
            if(getRandomInt(1,100)%2){
                element.active = true;
            }

        });
        console.log(users)

        self.postMessage({
            success: true,
            users
        });
    } catch (error) {
        self.postMessage({
            success: false,
            error: error.message
        });
    }
};

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}
