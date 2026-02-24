afd.py

def es_mayuscula(c): return ‘A’ <= c <= ‘Z’

def es_minuscula_o_digito(c): return (‘a’ <= c <= ‘z’) or (‘0’ <= c <=
‘9’)

def afd(token): estado = “q0”

    for c in token:
        if estado == "q0":
            if c == '+':
                estado = "q1"
            elif es_mayuscula(c):
                estado = "q3"
            else:
                return "NO ACEPTA"

        elif estado == "q1":
            if c == '+':
                estado = "q2"
            else:
                return "NO ACEPTA"

        elif estado == "q2":
            return "NO ACEPTA"

        elif estado == "q3":
            if es_minuscula_o_digito(c):
                estado = "q4"
            else:
                return "NO ACEPTA"

        elif estado == "q4":
            if es_minuscula_o_digito(c):
                estado = "q4"
            else:
                return "NO ACEPTA"

    if estado == "q1":
        return "SUMA"
    elif estado == "q2":
        return "INCREMENTO"
    elif estado == "q4":
        return "ID"
    else:
        return "NO ACEPTA"

with open(“entrada.txt”, “r”) as archivo: for linea in archivo: tokens =
linea.split() for token in tokens: resultado = afd(token)
print(f”{token} -> {resultado}“)
