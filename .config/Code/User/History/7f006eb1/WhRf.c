#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200
#define MAX_ITEMS 10

// Estrutura para representar um item no inventário
typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item* items[MAX_ITEMS];
    int count;
} Inventory;

Item* create_item(const char* name, const char* desc, int quantity, float price) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    if (newItem == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newItem->name, name, MAX_NAME_LEN);
    newItem->name[MAX_NAME_LEN - 1] = '\0';
    strncpy(newItem->description, desc, MAX_DESC_LEN);
    newItem->description[MAX_DESC_LEN - 1] = '\0';
    newItem->quantity = quantity;
    newItem->price = price;
    return newItem;
}

// Função para adicionar um item no inventário
void add_item(Inventory* inv, Item* item) {
    if (inv->count >= MAX_ITEMS) {
        printf("Inventário cheio! Não é possível adicionar mais itens.\n");
        return;
    }
    inv->items[inv->count++] = item;
}

// Função para imprimir um item formatado
void print_item(const Item* item) {
    printf("Nome: %s\nDescrição: %s\nQuantidade: %d\nPreço unitário: R$ %.2f\n",
           item->name, item->description, item->quantity, item->price);
}

// Função para imprimir o inventário completo
void print_inventory(const Inventory* inv) {
    printf("\n----- INVENTÁRIO -----\n");
    for (int i = 0; i < inv->count; i++) {
        printf("Item %d:\n", i + 1);
        print_item(inv->items[i]);
        printf("----------------------\n");
    }
}

// Função que busca um item pelo nome (case insensitive)
Item* find_item(const Inventory* inv, const char* name) {
    for (int i = 0; i < inv->count; i++) {
        if (strcasecmp(inv->items[i]->name, name) == 0) {
            return inv->items[i];
        }
    }
    return NULL;
}

// Função para calcular o valor total do inventário
float total_value(const Inventory* inv) {
    float total = 0.0f;
    for (int i = 0; i < inv->count; i++) {
        total += inv->items[i]->quantity * inv->items[i]->price;
    }
    return total;
}

// Função que converte uma string para maiúsculas
void to_uppercase(char* str) {
    for (; *str; str++) {
        *str = toupper((unsigned char)*str);
    }
}

// Função para atualizar a quantidade de um item
void update_quantity(Item* item, int new_quantity) {
    if (new_quantity < 0) {
        printf("Quantidade inválida!\n");
        return;
    }
    item->quantity = new_quantity;
}

// Função para liberar a memória do inventário
void free_inventory(Inventory* inv) {
    for (int i = 0; i < inv->count; i++) {
        free(inv->items[i]);
    }
    inv->count = 0;
}

// Função principal
int main() {
    Inventory myInventory = {.count = 0};
    char command[20];
    char inputName[MAX_NAME_LEN];
    int inputQuantity;
    float inputPrice;
    char inputDesc[MAX_DESC_LEN];

    printf("Bem-vindo ao sistema de gerenciamento de inventário!\n");
    printf("Comandos disponíveis:\n");
    printf("ADD - Adicionar item\n");
    printf("FIND - Procurar item\n");
    printf("UPDATE - Atualizar quantidade\n");
    printf("PRINT - Imprimir inventário\n");
    printf("TOTAL - Valor total do inventário\n");
    printf("EXIT - Sair\n");

    while (1) {
        printf("\nDigite um comando: ");
        if (scanf("%19s", command) != 1) break;

        // Converter comando para maiúsculas pra facilitar comparação
        to_uppercase(command);

        if (strcmp(command, "ADD") == 0) {
            getchar(); // limpar buffer
            printf("Nome do item: ");
            fgets(inputName, MAX_NAME_LEN, stdin);
            inputName[strcspn(inputName, "\n")] = '\0'; // remover \n

            printf("Descrição: ");
            fgets(inputDesc, MAX_DESC_LEN, stdin);
            inputDesc[strcspn(inputDesc, "\n")] = '\0';

            printf("Quantidade: ");
            if (scanf("%d", &inputQuantity) != 1) {
                printf("Quantidade inválida.\n");
                continue;
            }
            printf("Preço unitário: ");
            if (scanf("%f", &inputPrice) != 1) {
                printf("Preço inválido.\n");
                continue;
            }

            Item* newItem = create_item(inputName, inputDesc, inputQuantity, inputPrice);
            add_item(&myInventory, newItem);
            printf("Item adicionado com sucesso!\n");

        } else if (strcmp(command, "FIND") == 0) {
            getchar();
            printf("Nome do item para procurar: ");
            fgets(inputName, MAX_NAME_LEN, stdin);
            inputName[strcspn(inputName, "\n")] = '\0';

            Item* found = find_item(&myInventory, inputName);
            if (found) {
                printf("Item encontrado:\n");
                print_item(found);
            } else {
                printf("Item não encontrado.\n");
            }

        } else if (strcmp(command, "UPDATE") == 0) {
            getchar();
            printf("Nome do item para atualizar: ");
            fgets(inputName, MAX_NAME_LEN, stdin);
            inputName[strcspn(inputName, "\n")] = '\0';

            Item* found = find_item(&myInventory, inputName);
            if (!found) {
                printf("Item não encontrado.\n");
                continue;
            }

            printf("Nova quantidade: ");
            if (scanf("%d", &inputQuantity) != 1) {
                printf("Quantidade inválida.\n");
                continue;
            }
            update_quantity(found, inputQuantity);
            printf("Quantidade atualizada!\n");

        } else if (strcmp(command, "PRINT") == 0) {
            print_inventory(&myInventory);

        } else if (strcmp(command, "TOTAL") == 0) {
            printf("Valor total do inventário: R$ %.2f\n", total_value(&myInventory));

        } else if (strcmp(command, "EXIT") == 0) {
            break;

        } else {
            printf("Comando inválido!\n");
        }
    }

    free_inventory(&myInventory);
    printf("Programa encerrado. Até mais!\n");
    return 0;
}