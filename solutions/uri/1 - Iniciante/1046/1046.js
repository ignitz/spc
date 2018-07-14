var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

// https://www.urionlinejudge.com.br/judge/pt/problems/view/1046

function get_start() {
  return Number(input.split('\n')[0].split(' ')[0]);
}

function get_end() {
  return Number(input.split('\n')[0].split(' ')[1]);
}

let start_hour = get_start();
let end_hour = get_end();

if (start_hour < end_hour) {
  console.log("O JOGO DUROU", String(end_hour - start_hour), "HORA(S)");
} else if (start_hour == end_hour) {
  console.log("O JOGO DUROU 24 HORA(S)");
} else {
  console.log("O JOGO DUROU", String(end_hour + 24 - start_hour), "HORA(S)");
}
