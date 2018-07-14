var input = require("fs").readFileSync("/dev/stdin", "utf8");
var lines = input.split("\n");

class Figura {
  constructor(a, b, c) {
    this.a = a;
    this.b = b;
    this.c = c;
    this.name = "";
  }

  get area() {
    return 0.0;
  }

  print() {
    return this.name + String(this.area.toFixed(3));
  }
}

class Triangulo extends Figura {
  constructor(a, b, c) {
    super(a, b, c);
    this.name = "TRIANGULO: ";
  }

  get area() {
    return (this.a * this.c) / 2;
  }
}

class Circulo extends Figura {
  constructor(a, b, c) {
    super(a, b, c);
    this.name = "CIRCULO: ";
  }

  get area() {
    return 3.14159 * Math.pow(this.c, 2);
  }
}

class Trapezio extends Figura {
  constructor(a, b, c) {
    super(a, b, c);
    this.name = "TRAPEZIO: ";
  }

  get area() {
    return ((this.a + this.b) * this.c) / 2;
  }
}

class Quadrado extends Figura {
  constructor(a, b, c) {
    super(a, b, c);
    this.name = "QUADRADO: ";
  }

  get area() {
    return Math.pow(this.b, 2);
  }
}

class Retangulo extends Figura {
  constructor(a, b, c) {
    super(a, b, c);
    this.name = "RETANGULO: ";
  }

  get area() {
    return this.a * this.b;
  }
}

function main() {
  entrada = lines[0].split(" ").map(parseFloat);

  figura1 = new Triangulo(...entrada);
  figura2 = new Circulo(...entrada);
  figura3 = new Trapezio(...entrada);
  figura4 = new Quadrado(...entrada);
  figura5 = new Retangulo(...entrada);

  console.log(figura1.print());
  console.log(figura2.print());
  console.log(figura3.print());
  console.log(figura4.print());
  console.log(figura5.print());
}

main();
