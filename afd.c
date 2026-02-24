/* afd.c */

#include <stdio.h> #include <string.h>

int es_mayuscula(char c) { return (c >= ‘A’ && c <= ‘Z’); }

int es_minuscula_o_digito(char c) { return ((c >= ‘a’ && c <= ‘z’) ||
(c >= ‘0’ && c <= ‘9’)); }

const char* afd(char *token) { int estado = 0;

    for (int i = 0; token[i] != '\0'; i++) {
        char c = token[i];

        switch (estado) {
            case 0:
                if (c == '+')
                    estado = 1;
                else if (es_mayuscula(c))
                    estado = 3;
                else
                    return "NO ACEPTA";
                break;

            case 1:
                if (c == '+')
                    estado = 2;
                else
                    return "NO ACEPTA";
                break;

            case 2:
                return "NO ACEPTA";

            case 3:
                if (es_minuscula_o_digito(c))
                    estado = 4;
                else
                    return "NO ACEPTA";
                break;

            case 4:
                if (es_minuscula_o_digito(c))
                    estado = 4;
                else
                    return "NO ACEPTA";
                break;
        }
    }

    if (estado == 1)
        return "SUMA";
    else if (estado == 2)
        return "INCREMENTO";
    else if (estado == 4)
        return "ID";
    else
        return "NO ACEPTA";

}

int main() { FILE *archivo; char token[100];

    archivo = fopen("entrada.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fscanf(archivo, "%s", token) != EOF) {
        printf("%s -> %s\n", token, afd(token));
    }

    fclose(archivo);
    return 0;

}
