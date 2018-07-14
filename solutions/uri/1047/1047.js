var input = require("fs").readFileSync("/dev/stdin", "utf8");
var lines = input.split("\n");

// https://www.urionlinejudge.com.br/judge/pt/problems/view/1047

let line = lines[0].split(" ").map(function(value) {
  return parseInt(value);
});

function timestamp(hour, minute) {
  return hour * 60 + minute;
}

function back_to_hour_minute(timoso) {
  return [parseInt(timoso / 60), timoso % 60];
}

let start_time = timestamp(...line.slice(0, 2));
let end_time = timestamp(...line.slice(2, 4));

let duration;

if (start_time < end_time) {
  duration = end_time - start_time;
} else if (start_time == end_time) {
  duration = 24 * 60;
} else {
  duration = end_time + 24 * 60 - start_time;
}

let response = back_to_hour_minute(duration);

console.log(`O JOGO DUROU ${response[0]} HORA(S) E ${response[1]} MINUTO(S)`);
