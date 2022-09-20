#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100

struct contact
{
    int id;
    char name[100];
};

// Número máximo de contatos
struct contact contacts[MAX_CONTACTS];

// Quantidade de contatos
int total_contacts = 0;

// Insere um contato
int insert()
{
    if (total_contacts == MAX_CONTACTS)
    {
        printf("Cannot insert new records\n"); // Lista de contatos preenchida
        return 0;
    }
    printf("Contact name: ");
    scanf("%s", contacts[total_contacts].name);
    contacts[total_contacts].id = total_contacts + 1;
    total_contacts++;
    printf("\n");
    return 1; // Contato adicionado
}

// Mostra todos os contatos
void show()
{
    int i;
    for (i = 0; i < MAX_CONTACTS; i++)
    {
        if (contacts[i].id != 0)
        {
            printf("Id: %d, Name: %s\n", contacts[i].id, contacts[i].name);
        }
    }
    printf("\n");
}

// Mostra os contatos por ordem alfabética
void sort()
{
    int i, j, r;
    char aux[100];
    for (i = 0; i < MAX_CONTACTS - 1; i++)
    {
        for (j = 0; j < MAX_CONTACTS - i - 1; j++)
        {
            r = strcmp(contacts[j].name, contacts[j + 1].name);
            if (r > 0)
            {
                strcpy(aux, contacts[j].name);
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j + 1].name, aux);
            }
        }
    }
    show();
}

// Procura um contato por nome
int search(char name[100])
{
    int i;
    for (i = 0; i < MAX_CONTACTS; i++)
    {
        if (strcmp(name, contacts[i].name) == 0)
        {
            return i + 1;
        }
    }
    return 0;
}

// Deleta um contato por id
int delete (int id)
{
    int i;
    for (i = 0; i < MAX_CONTACTS; i++)
    {
        if (id == contacts[i].id)
        {
            contacts[i].id = 0;
            return 1; // Contato deletado
        }
    }
    return 0; // Contato não deletado
}

// Menu de opções
int menu()
{
    int response = 0;
    printf("--- MENU ---\n");
    printf("1 - List people\n");
    printf("2 - List People in Alphabetical Order\n");
    printf("3 - Search Person by name\n");
    printf("4 - Insert Person\n");
    printf("5 - Remove Person by id\n");
    printf("6 - Exit\n");
    printf("Enter a option: ");
    scanf("%d", &response);
    printf("\n");
    return response;
}

int main(void)
{
    int id_contact_delete;
    char name_contact_wanted[100];

    int option = menu();
    while (option != 6)
    {
        switch (option)
        {
        case 1:
            show();
            break;
        case 2:
            sort();
            break;
        case 3:
            printf("Search a name: ");
            scanf("%s", name_contact_wanted);
            int wanted = search(name_contact_wanted);
            if (wanted == 0)
            {
                printf("\nContact not found!\n\n");
            }
            else
            {
                printf("\nContact found!\n");
                printf("Id: %d, Name: %s\n\n", contacts[wanted - 1].id, contacts[wanted - 1].name);
            }
            break;
        case 4:
            insert();

            break;
        case 5:
            printf("Delete an id: ");
            scanf("%d", &id_contact_delete);

            int deleted = delete (id_contact_delete);
            if (deleted == 0)
            {
                printf("\nContact not found!\n");
            }
            else
            {
                printf("\nContact deleted\n\n");
            }
            break;
        default:
            break;
        }
        option = menu();
    }
    return 0;
}
