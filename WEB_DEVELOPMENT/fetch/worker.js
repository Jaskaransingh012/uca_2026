self.onmessage = async (params) => {
    console.log("params in worker function", params)
    try {
        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error(`HTTP Error: ${response.status}`);
        }

        const users = await response.json();

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
