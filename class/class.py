class Person:
    def __init__(self,name,age):
        self.name = name
        self.age = age
        self.gomi = "mogeogfsdjakl"

    def __del__(self):
        print("clash")
    def show(self) -> str:
        print("{0}さん{1}歳".format(self.name,self.age))
        return "str"

class BussinesPerson(Person):
    def __init__(self, name, age,Bussines):
        super().__init__(name,age)
        self.Bussines = Bussines
    
    def __del__(self):
        return super().__del__()
    
    def show(self) -> str:
        print("{0}さん{1}歳　職業 {2}".format(self.name,self.age,self.Bussines))
        return "str"

p = Person("スズキ",23)
p.show()
print(p.age)
print(p.gomi)
bp = BussinesPerson("田中",22,"無職")

bp.show()
