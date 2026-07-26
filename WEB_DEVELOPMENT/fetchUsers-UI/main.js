const worker = new Worker("worker.js");

worker.postMessage("fetch api");

worker.onmessage = (event) => {
  const data = event.data;

  if (!data.success) {
    console.error("Error:", data.error);
    document.getElementById("statusMessage").textContent =
      "Unable to load users.";
    return;
  }

  renderUsersTable(data.users?.users || []);
};

worker.onerror = (error) => {
  console.error("Worker Error:", error.message || error);
  document.getElementById("statusMessage").textContent =
    "Failed to load users.";
};

function renderUsersTable(users) {
  const tableBody = document.getElementById("usersTableBody");
  const statusMessage = document.getElementById("statusMessage");

  if (!tableBody) {
    return;
  }

  if (!users.length) {
    tableBody.innerHTML = `
      <tr>
        <td colspan="5">No users found.</td>
      </tr>
    `;
    if (statusMessage) {
      statusMessage.textContent = "No users available.";
    }
    return;
  }

  tableBody.innerHTML = users
    .map(
      (user) => `
        <tr>
          <td>${user.firstName} ${user.lastName}</td>
          <td>${user.email}</td>
          <td>${user.age}</td>
          <td>${user.gender || "-"}</td>
          <td>
            <span class="${user.active ? "status-active" : "status-inactive"}">
              ${user.active ? "Active" : "Inactive"}
            </span>
          </td>
        </tr>
      `,
    )
    .join("");

  if (statusMessage) {
    statusMessage.textContent = `Loaded ${users.length} users.`;
  }
}
