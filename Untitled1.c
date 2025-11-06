#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    int shift, razao;
    char alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alfabeto_shift[27];
    char alfabeto_cifra[27];
    int i;

    // Entrada dos dados
    printf("Digite uma palavra (sem espacos): ");
    scanf("%s", palavra);

    printf("Digite o valor do shift: ");
    scanf("%d", &shift);

    printf("Digite a razao da P.A.: ");
    scanf("%d", &razao);

    // Cria o alfabeto deslocado pelo shift
    for (i = 0; i < 26; i++) {
        alfabeto_shift[i] = alfabeto[(i + shift) % 26];
    }
    alfabeto_shift[26] = '\0';

    // Cria o alfabeto cifrante com a P.A. aplicada
    int usado[26] = {0};
    int index = razao - 1;
    for (i = 0; i < 26; i++) {
        while (usado[index % 26])
            index = (index + 1) % 26;

        alfabeto_cifra[i] = alfabeto_shift[index % 26];
        usado[index % 26] = 1;
        index = (index + razao) % 26;
    }
    alfabeto_cifra[26] = '\0';

    // Criptografa a palavra
    for (i = 0; i < strlen(palavra); i++) {
        char c = palavra[i];

        // Converte para maiúscula
        if (c >= 'a' && c <= 'z')
            c -= 32;

        // Se for letra do alfabeto, substitui pela letra cifrada
        if (c >= 'A' && c <= 'Z') {
            int pos = c - 'A';
            palavra[i] = alfabeto_cifra[pos];
        }
    }

    // Exibe apenas o resultado final
    printf("\nPalavra cifrada: %s\n", palavra);

    return 0;
}

