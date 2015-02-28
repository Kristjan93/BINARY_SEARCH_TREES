#include "ContactManager.h"


void ContactManager::add(Contact contact)
{
	name_map.add(contact.name, contact);
    phone_map.add(contact.phone, contact);
}

void ContactManager::remove(string name)
{
    if(name_map.contains(name))
    {
        Contact phone_contact = name_map.get(name);
        string phone = phone_contact.phone;
        name_map.remove(name);
        phone_map.remove(phone);
    }
}

void ContactManager::update_phone(string name, string new_number)
{
    if(name_map.contains(name) == false)
    {
        throw ContactMissingException();
    }
    else
    {
        Contact phone_contact = (name_map.get(name));
        
        string old_phone = phone_contact.phone;
        
        phone_contact.phone = new_number;
        
        phone_map.remove(old_phone);
        
        add(phone_contact);
    }
}
void ContactManager::update_email(string name, string new_email)
{
    if(name_map.contains(name) == false)
    {
        throw ContactMissingException();
    }
    else
    {
        Contact nytt_email = name_map.get(name);
        nytt_email.email = new_email;
        add(nytt_email);
    }
}

bool ContactManager::name_exists(string name)
{
    if(name_map.contains(name))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ContactManager::phone_exists(string phone)
{
	if(phone_map.contains(phone))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Contact ContactManager::get_contact_by_name(string name)
{
    if (name_map.contains(name) == false)
    {
        throw ContactMissingException();
    }
    else
    {
        return name_map.get(name);
    }
}
Contact ContactManager::get_contact_by_phone(string phone)
{
    if (phone_map.contains(phone) == false)
    {
        throw ContactMissingException();
    }
    else
    {
        return phone_map.get(phone);
    }
}

vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix)
{
	
	return name_map.prefix_search(name_prefix);
}

vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix)
{
	return phone_map.prefix_search(phone_prefix);
}

ostream& operator<< (ostream& out, ContactManager& manager)
{
	out << manager.name_map << endl << endl;
	out << manager.phone_map;
	return out;
}
