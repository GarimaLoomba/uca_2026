// Normal code 

console.log("Code before the Browser API code");

// Browser API 
const xhr1 = new XMLHttpRequest() ;

xhr1.open("GET","https://dummyjson.com/products/1",false );

let apiResponse ;
xhr1.onload = function(){
    apiResponse = xhr1.responseText;
    console.log(xhr1.responseText);
}

xhr1.send() ;

console.log("API Response :",apiResponse);
console.log("Code after the Browser API");