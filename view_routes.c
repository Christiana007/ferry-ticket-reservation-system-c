#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "Administration_Dashboard/admin.h"

void view_routes(Route ports[], int i)
{
    printf("These are all the available destinations:\n"); // emfanizei olous tous available destinations
    printf("----------------------------------------------------\n");
    printf("Island/Port , Port Code , Seat Cost, Additional Fee  \n");
    printf("Seat Cost ( Deck Airplane Type Cabin) \n");
    for (int i = 0; i < 13; i++)
    {
        printf("%s  %s   %d %d  %d  %d\n", ports[i].port, ports[i].port_code, ports[i].deck_cost, ports[i].airplaneseat_cost, ports[i].cabin_cost, ports[i].car_cost);
    }
}