const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
let input;
rl.on("line", function(line){
    input = line;
    rl.close();
}).on("close", function(){
    solution(input);
    process.exit();
});

function solution(input2){
    let flag =1;
    for(let i=0;i<=Math.floor(input2.length/2);i++){
        if(input2[i] != input2.at(-i-1)){
            flag = 0;
            break;
        }
    }
    console.log(flag);
}