const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = (event) => {
    const data = event.data;

    if (!data.success) {
        console.error("Error:", data.error);
        return;
    }

    console.log(data);
    data.users.users.forEach(user => {
        console.log(
            `${user.firstName + " " + user.lastName} - ${user.active ? "Active" : "Inactive"}`
        );
    });
};

worker.onerror = (error) => {
    console.error("Worker Error:", error.message);
};
