#ifndef CLIENT_DASHBOARD_H
#define CLIENT_DASHBOARD_H

typedef struct route
{
    char port[12];
    char port_code[3];
    int deck_cost;
    int airplaneseat_cost;
    int cabin_cost;
    int car_cost;
} Route;
typedef struct date
{
    int dd;
    int mm;
    int yyyy;
} Date;

typedef struct booked_trip
{
    char username[25];
    char id[40];
    int total_cost;
    Date start_date;
    Date return_date;
    char trip_type[8];
    char status[9];
} Book;

Book booking;

Route ports[] = {
    {"Kos", "KOS", 60, 80, 120, 100},
    {"Rodos", "RHO", 80, 100, 140, 100},
    {"Kalymnos", "KAL", 60, 80, 120, 100},
    {"Patmos", "PAT", 55, 75, 115, 100},
    {"Astypalaia", "AST", 50, 70, 110, 100},
    {"Kasos", "KAS", 65, 85, 125, 100},
    {"Kastelorizo", "KST", 100, 120, 160, 120},
    {"Leros", "LER", 60, 80, 120, 100},
    {"Karpathos", "KAR", 70, 90, 130, 100},
    {"Symi", "SYM", 80, 100, 140, 120},
    {"Xalki", "XAL", 70, 90, 130, 100},
    {"Tilos", "TIL", 75, 95, 135, 100},
    {"Pserimos", "PSE", 60, 80, 120, 100}};

#endif

void book_trip(Book booking, const Route ports[], int ports_count);
void view_routes(const Route ports[], int i);
