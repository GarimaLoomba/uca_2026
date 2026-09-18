
const users = [
    { name: "Alice", age: 53 },
    { name: "Tim", age: 74 }
];

function generateTable() {
    const rows = users.map(user => `
  <tr>
    <td>${user.name}</td>
    <td>${user.age}</td>
  </tr>`).join("");

    return `
<table>
${rows}
</table>`;
}

console.log(generateTable());

