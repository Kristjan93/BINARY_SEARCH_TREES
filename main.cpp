#include <iostream>
#include <vector>
#include "InteractivePhoneBook.h"
#include <cstdlib>

#include "ContactNode.h"
#include "StringContactMap.h"
#include "Contact.h"
#include "StringContactMap.h"
#include "ContactManager.h"


using namespace std;

int main()
{
    /*
    InteractivePhoneBook phonebook;
    phonebook.start();
     
     vil geta updatað hvort fyrr sig !!! annars gengur þetta ekki 
     
    */
    Contact nytt_contact1, nytt_contact2, nytt_contact3;
    
    vector<Contact> bla;
    
    nytt_contact1.name = "aristjan";
    nytt_contact1.phone = "7741149";
    nytt_contact1.email = "Krillinn@hotmail.com";
    nytt_contact1.address = "Hellubakki 16";
    
    nytt_contact2.name = "ballu";
    nytt_contact2.phone = "666";
    nytt_contact2.email = "Kalli@hotmail.com";
    nytt_contact2.address = "Angband";
    
    nytt_contact3.name = "ballu";
    nytt_contact3.phone = "666";
    nytt_contact3.email = "Kalli@hotmail.com";
    nytt_contact3.address = "Angband";


    StringContactMap nytt_map;
    
    nytt_map.add("kristjan", nytt_contact1);
    nytt_map.add("calli", nytt_contact2
                 );
    nytt_map.add("c", nytt_contact3);
    nytt_map.add("c", nytt_contact1);
    
    
    bla = nytt_map.prefix_search("c");

    for (int i = 0; i < bla.size(); i++)
    {
        cout << bla[i] << endl;
    }
    

    return 0;
}
