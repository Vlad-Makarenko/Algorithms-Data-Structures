#include <iostream>
#include <string>

using namespace std;

struct CityElement{

    CityElement *next;
    string name;
};

struct CityList {

    CityElement *head;
};

struct CountryElement{

    CityList *cities_list;
    CountryElement *next;
    string name;
};

struct CountriesList{

    CountryElement *head;
};

void InitCountryList(struct CountriesList &country_list){

    country_list.head = new struct CountryElement;
    country_list.head->next = NULL;
}

void AddCountry(struct CountriesList &country_list, string name){

    struct CountryElement *new_country = new struct CountryElement;
    new_country->name = name;
    new_country->next = NULL;
    new_country->cities_list = NULL;
    struct CountryElement *current_last = country_list.head->next;
    if (current_last == NULL)
        country_list.head->next = new_country;
    else
    {
        while (current_last->next != NULL)
        {
            current_last = current_last->next;
        }
        current_last->next = new_country;
    }
}

void AddCity(struct CountriesList &country_list, string country_name, string name){

    struct CountryElement *current = country_list.head->next;
    while (current->name != country_name)
    {
        current = current->next;
        if (current == NULL)
        {
            cout << "Not country with name " << country_name << endl;
            return;
        }
    }
    if (current->cities_list == NULL)
    {
        current->cities_list = new struct CityList;
        current->cities_list->head = new struct CityElement;
        current->cities_list->head->next = NULL;
    }
    struct CityElement *new_city = new struct CityElement;
    new_city->next = NULL;
    new_city->name = name;
    struct CityElement *current_handed_over_object = current->cities_list->head->next;
    if (current_handed_over_object == NULL)
    {
        current->cities_list->head->next = new_city;
    }
    else
    {
        while (current_handed_over_object->next != NULL)
        {
            current_handed_over_object = current_handed_over_object->next;
        }
        current_handed_over_object->next = new_city;
    }
}

void DeleteCountry(struct CountriesList &country_list, string country_name)
{
    struct CountryElement *deleted = country_list.head->next;
    struct CountryElement *prev = country_list.head->next;
    if (deleted == NULL)
    {
        cout << "Not country with name " << country_name << endl;
        return;
    }
    while (deleted->name != country_name)
    {
        prev = deleted;
        deleted = deleted->next;
        if (deleted == NULL)
        {
            cout << "Not country with name " << country_name << endl;
            return;
        }
    }
    if (deleted == country_list.head->next)
        country_list.head->next = deleted->next;
    else
    {
        prev->next = deleted->next;
    }

    struct CityElement *current_city = NULL;
    if (deleted->cities_list != NULL)
    {
        if (deleted->cities_list->head != NULL)
        {
            current_city = deleted->cities_list->head->next;
        }
    }

    if (current_city != NULL)
    {
        struct CityElement *deleted_handed_over_object_element = current_city;
        while (current_city != NULL)
        {
            current_city = current_city->next;
            delete (deleted_handed_over_object_element);
            deleted_handed_over_object_element = current_city;
        }
        if (deleted->cities_list->head != NULL)
            delete (deleted->cities_list->head);
        if (deleted->cities_list != NULL)
            delete (deleted->cities_list);
    }
    delete (deleted);
}

void DeleteCityFromCountry(struct CountriesList &country_list, string country_name, string city_name)
{
    struct CountryElement *country_from_deleted = country_list.head->next;
    if (country_from_deleted != NULL)
    {
        while (country_from_deleted->name != country_name)
        {
            country_from_deleted = country_from_deleted->next;
            if (country_from_deleted == NULL)
            {
                cout << "No country with name: " << country_name << endl;
                return;
            }
        }
        if (country_from_deleted->cities_list != NULL)
        {
            struct CityElement *deleted_city = country_from_deleted->cities_list->head->next;
            struct CityElement *prev = NULL;
            while (deleted_city->name != city_name)
            {
                prev = deleted_city;
                deleted_city = deleted_city->next;
                if (deleted_city == NULL)
                    break;
            }
            if (deleted_city != NULL)
            {
                if (deleted_city == country_from_deleted->cities_list->head->next)
                {
                    country_from_deleted->cities_list->head->next = deleted_city->next;
                }
                else
                {
                    prev->next = deleted_city->next;
                }
                delete (deleted_city);
            }
            else
            {
                cout << "Not city in country: " << country_name << " with name: " << city_name << endl;
                return;
            }
        }
        else
        {
            cout << "Not city in country: " << country_name << " with name: " << city_name << endl;
            return;
        }
    }
    else
    {
        cout << "Not country with name: " << country_name << endl;
    }
}

void DeleteCountriesList(struct CountriesList &country_list)
{
    struct CountryElement *current = country_list.head->next;
    if (current != NULL)
    {
        while (current != NULL)
        {
            string deleted_name = current->name;
            current = current->next;
            DeleteCountry(country_list, deleted_name);
        }
    }
    delete (country_list.head);
    delete (&country_list);
}

void PrintCountriesList(struct CountriesList &country_list)
{
    struct CountryElement *current_country = country_list.head->next;
    if (current_country == NULL)
    {
        cout << "Not countries" << endl;
    }
    else
    {
        while (current_country != NULL)
        {
            cout << "Country: " << current_country->name << endl;
            if (current_country->cities_list != NULL)
            {
                if (current_country->cities_list->head != NULL)
                {
                    struct CityElement *current_city = current_country->cities_list->head->next;
                    if (current_city != NULL)
                    {
                        cout << "Cities: " << endl;
                        while (current_city != NULL)
                        {
                            cout << "- " << current_city->name << endl;
                            current_city = current_city->next;
                        }
                    }
                }
            }
            current_country = current_country->next;
        }
    }
}

int main()
{
    struct CountriesList *country_list = new struct CountriesList;
    InitCountryList(*country_list);
    AddCountry(*country_list, "Ukraine");
    AddCountry(*country_list, "USA");
    PrintCountriesList(*country_list);
    cout << endl << "Add cities: " << endl;
    AddCity(*country_list, "Ukraine", "Kharkiv");
    AddCity(*country_list, "Ukraine", "Kiev");
    AddCity(*country_list, "Ukraine", "Lviv");
    AddCity(*country_list, "USA", "Washington");
    AddCity(*country_list, "USA", "California");
    PrintCountriesList(*country_list);
    cout << endl << "Delete the country:" << endl;
    DeleteCountry(*country_list, "USA");
    PrintCountriesList(*country_list);
    cout << endl << "Delete the city:" << endl;
    DeleteCityFromCountry(*country_list, "Ukraine", "Lviv");
    PrintCountriesList(*country_list);
    AddCountry(*country_list, "England");
    cout << endl << "Add country: " << endl;
    PrintCountriesList(*country_list);
    cout << endl << "Delete the list:" << endl;;
    DeleteCountriesList(*country_list);
    PrintCountriesList(*country_list);
    return 0;
}
