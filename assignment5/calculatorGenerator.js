
function* calc(initialValue) {
    if (typeof initialValue !== "number" || !Number.isFinite(initialValue)) {
        yield "Invalid input";
        return;
    }

    let result = initialValue;

    while (true) {
        const input = yield result;

        if (!input || typeof input !== "object") {
            yield "Invalid input";
            continue;
        }

        const { operation, value } = input;

        if (
            !["add", "subtract", "multiply", "divide"].includes(operation) ||
            typeof value !== "number" ||
            !Number.isFinite(value)
        ) {
            yield "Invalid input";
            continue;
        }

        if (operation === "add") {
            result += value;
        } else if (operation === "subtract") {
            result -= value;
        } else if (operation === "multiply") {
            result *= value;
        } else if (operation === "divide") {
            if (value === 0) {
                yield "Cannot divide by zero";
                continue;
            }

            result /= value;
        }

        yield result;
    }
}

const calculator = calc(50);

console.log(calculator.next().value);
console.log(calculator.next({ operation: "add", value: 30 }).value);
console.log(calculator.next({ operation: "multiply", value: 2 }).value);
console.log(calculator.next({ operation: "add", value: "30" }).value);
console.log(calculator.next({ operation: "multiply", value: 0 }).value);


