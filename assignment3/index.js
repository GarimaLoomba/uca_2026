const worker = new Worker("worker.js");

worker.postMessage("fetch");

worker.onmessage = function (event) {
    const data = event.data;

    if (!data.success) {
        console.error(data.error);
        return;
    }

    data.users.forEach(user => {
        console.log(
            `${user.name} - ${user.active ? "Active" : "Inactive"}`
        );
    });
};

worker.onerror = function (error) {
    console.error("Worker Error:", error.message);
};