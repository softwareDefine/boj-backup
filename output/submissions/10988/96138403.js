const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
let input;
rl.on("line", function(line){
    input = line.toString;
    let flag =1;

    for(let i=0;i<=input.length/2;i++){
        if(input[i] != input[input.length-i-1]){
            flag = 0;
            break;
        }
    }
    console.log(flag);
    rl.close();
}).on("close", function(){
    solution(input);
    process.exit();
});