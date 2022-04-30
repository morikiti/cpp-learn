class Person {
    constructor(name,age) { 
        this.name = name;
        this.age = age;
    }
    show() { 
        console.log(this.name+"さん "+this.age+"歳")
    }
}

class MathPerson extends Person {
    constructor(name,age,math) {
        super(name,age);
        this.math = math
    }
    show_math() { 
        console.log(this.name +"さん" + this.math + "を学んでいます");
    }
}

let p = new Person("スズキ",32);
p.show();

let mp = new MathPerson("田中",53,"代数");
mp.show();
mp.show_math();