from random import randint

archivo = open("asistencia2.txt", "w")
formato = "E {} {}\n"
formato2 = "{}-{}"
formato3 = "{}:{}"
lista = []
j = 0

while j < 100:
    lista.append( (randint(00,23), randint(00,59)) )
    j +=1

lista.sort()

i = 0
while i < 100:
    archivo.write(formato.format( formato2.format(randint(5000000, 25000000), randint(0,9)), formato3.format(lista[i][0], lista[i][1]) ))
    i +=1
archivo.close()