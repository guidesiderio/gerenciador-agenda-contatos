#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3

struct contact
{
    int id;
    char name[100];
};

void show(struct contact contacts[N])
{
    int i;
    printf("\n");
    for (i = 0; i < N; i++)
    {
        if (contacts[i].id != 0)
        {
            printf("Id: %d, Name: %s\n", contacts[i].id, contacts[i].name);
        }
    }
}

int main(void)
{

    struct contact contacts[N];
    int i;

    for (i = 0; i < N; i++)
    {
        printf("Contact name %d: ", i + 1);
        scanf("%s", contacts[i].name);
        contacts[i].id = i + 1;
    }

    show(contacts);

    int id_contact_wanted;
    int found;
    int response;
    char name_contact_wanted[100];

    printf("\nFind: (1 - name, 2 - id): ");
    scanf("%d", &response);

    if (response == 1)
    {
        printf("\nEnter a name: ");
        scanf("%s", name_contact_wanted);
        for (i = 0; i < N; i++)
        {
            if (strcmp(name_contact_wanted, contacts[i].name) == 0)
            {
                printf("\nContact found!\n");
                printf("Id: %d, Name: %s\n", contacts[i].id, contacts[i].name);
                found = 1;
                break;
            }
            found = 0;
        }

        if (found == 0)
        {
            printf("\nContact not found!\n");
        }
    }
    else if (response == 2)
    {
        printf("\nEnter an id: ");
        scanf("%d", &id_contact_wanted);
        for (i = 0; i < 3; i++)
        {
            if (id_contact_wanted == contacts[i].id)
            {
                printf("\nContact found!\n");
                printf("Id: %d, Name: %s\n", contacts[i].id, contacts[i].name);
                found = 1;
                break;
            }
            found = 0;
        }

        if (found == 0)
        {
            printf("\nContact not found!\n");
        }
    }
    char name_contact_delete[100];
    int id_contact_delete;

    printf("\nDelete: (1 - name, 2- id): ");
    scanf("%d", &response);
    if (response == 1)
    {
        printf("\nEnter a name: ");
        scanf("%s", name_contact_delete);
        for (i = 0; i < N; i++)
        {
            if (strcmp(name_contact_delete, contacts[i].name) == 0)
            {
                // contacts[i].name = "";
                break;
            }
        }
    }
    else if (response == 2)
    {
        printf("\nEnter an id: ");
        scanf("%d", &id_contact_delete);
        for (i = 0; i < N; i++)
        {
            if (id_contact_delete == contacts[i].id)
            {
                contacts[i].id = NULL;
                break;
            }
        }
    }

    show(contacts);

    return 0;
}
