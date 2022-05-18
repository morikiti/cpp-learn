class A:
    def __init__(self,a,b):
        self.a = a
        self.b = b
    
    def __call__(self,c):
        print("A-call")
        print(c)

class B(A):
    def __init__(self,a,b,c,d):
        super(B,self).__init__(a,b)
        self.c = c
        self.d = d
    
    def __call__(self,e):
        print("B--call")
        print(e)
        print("{} {} {} {}".format(self.a,self.b,self.c,self.d))



a = A(2,3)

b = B(2,3,54,43)