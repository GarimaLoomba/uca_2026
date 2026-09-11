Implement a custom promise
Implement the below custom promise method/constructor function "NewPromise"

function NewPromise(executorFunction) {
    // Implementation here
}
This method should have fill implementation for below:

executorFunction should be called with resolve and reject methods
resolve()
reject()
then()
catch()
Promise chaining as below
🛈 Return new custom promise from then function

new MyPromise(resolve => {
    resolve(5);
})
.then(value => {
    return value * 2;
})
.then(value => {
    return value * 5;
})
.then(value => {
    console.log(value);
});

Output: 50

<span title="This is a helpful hint explaining what to do!" style="cursor: help;">&#x1F6C8;</span>
Return new custom promise from then function
