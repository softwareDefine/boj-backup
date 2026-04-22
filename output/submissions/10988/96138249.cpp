let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');

let flag =1;

for(let i=0;i<=input.length/2;i++){
    if(input[i] != input[input.length-i-1]){
        flag = 0;
        break;
    }
}
console.log(flag);