from dummy import Dummy

x = Dummy(message="Oh no", a=1.5, b=2.5)
y = Dummy()

print("Object x")
print(x.a)
print(x.b)
print(x.message)

y.a = 1.1
print("Object y")
print(y.a)
print(y.b)
print(y.message)