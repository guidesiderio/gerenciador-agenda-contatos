#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 3

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
void insert()
{
    printf("Contact name: ");
    scanf("%s", contacts[total_contacts].name);
    contacts[total_contacts].id = total_contacts + 1;
    total_contacts++;
    printf("\n");
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

// Busca um contato por id
int search(int id)
{
    int i;
    for (i = 0; i < MAX_CONTACTS; i++)
    {
        if (id == contacts[i].id)
        {
            return id; // Retorna o id do contato buscado
        }
    }
    return 0; // Contato não encontrado
}

// Deleta um contato por id
int delete (int id)
{
    if (search(id) == 0)
    {
        return 0; // Contato não encontrado
    }
    int i;
    for (i = 0; i < MAX_CONTACTS; i++)
    {
        if (id == contacts[i].id)
        {
            contacts[i].id = NULL;
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
    printf("1 - Insert contact\n");
    printf("2 - Delete contact\n");
    printf("3 - Search contact\n");
    printf("4 - Show contact(s)\n");
    printf("5 - Exit\n");
    printf("Enter a option: ");
    scanf("%d", &response);
    printf("\n");
    return response;
}

int main(void)
{
    int i, id_contact_delete, id_contact_wanted;

    int option = menu();
    while (option != 5)
    {
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
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
        case 3:
            printf("Search an id: ");
            scanf("%d", &id_contact_wanted);

            int wanted = search(id_contact_wanted);
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
            show(contacts);
            break;
        default:
            break;
        }
        option = menu();
    }
    return 0;
}
