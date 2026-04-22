const fs = require('fs');
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
/*let input = "the quick brown fox.\n\
the <i><b>quick</b> brown</i> fox.\n\
<doc>fox &amp; socks.</doc>\n\
3x+5&gt;7\n\
Null: &x00;\n\
<doc>the quick brown fox.\n\
the <i>quick <b>brown</i></b> fox\n\
fox & socks.\n\
3x+5>7\n\
Null: &x0;".split('\n');*/
/*let input = "tags that are not lowercase <Tag1>hello</Tag1>\n\
&aaa;\n\
&xax;".split('\n');*/


for(let code of input){
    let stack = [];
    let flag = 0;
    code = code.split(/(<[^>]+>)/g);
    for(let element of code){
        if(element.at(0)=='<' && element.at(-1)=='>'){
            //단일
            if(element.at(-2) == '/'){
                if(!(/^[0-9a-z]+$/.test(element.slice(1,-2)))){
                    flag = 1;
                    break;
                }
            }//닫힘
            else if(element.at(1) == '/'){
                if(!(/^[0-9a-z]+$/.test(element.slice(2,-1)))){
                    flag = 1;
                    break;
                }
                if(stack.length && stack.at(-1) == element.slice(2,-1)){
                    stack.pop();
                }else{
                    flag = 1;
                    break;
                }
                
            }
            //열림
            else{
                if(!(/^[0-9a-z]+$/.test(element.slice(1,-1)))){
                    flag = 1;
                    break;
                }
                stack.push(element.slice(1,-1));
            }
        }else{
            // &lt,&gt,&amp -> ''
            // &x을 찾음 -> &x;
            let filtered=element.split(/(&[^;]+;)/g).map((s)=>{
                if(s == '&lt;' || s == '&gt;' || s=='&amp;'){ return '';}
                if(s.slice(0,2) == '&x'&& s.at(-1) == ';'){
                    let hex = s.slice(2,-1);
                    let hex2 =hex.match(/[0-9A-Fa-f]/g);
                    if(hex && hex2 && hex.length == hex2.length && hex.length % 2 == 0){
                        return '';
                    }
                }
                return s;
            });
            //console.log(filtered);
            for(let chk of filtered){
                for(let chkdeep of chk.split('')){
                    if(chkdeep == '<' || chkdeep == '>' || chkdeep == '&'){
                        flag = 1;
                    }
                }
            }
        }
    }
    if(stack.length){
        flag = 1;
    }
    if(flag){
        console.log('invalid');
    }else{
        console.log('valid');
    }
}