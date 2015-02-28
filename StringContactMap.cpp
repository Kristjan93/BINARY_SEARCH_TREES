#include "StringContactMap.h"


using namespace std;

StringContactMap::StringContactMap ()
{
	root = NULL;
}

StringContactMap::~StringContactMap()
{
	free_memory(root);
}

int StringContactMap::size() const
{
    return (size(root));
}

int StringContactMap::size(NodePtr node) const
{
    if(node == NULL)
    {
        return 0;
    }
    return size(node->left) + size(node->right) + 1;
}

bool StringContactMap::empty() const
{
	return root == NULL;
}

vector<Contact> StringContactMap::all_contacts() const
{
    vector<Contact> increasing_order;
    
    all_contacts(root, increasing_order);

    return increasing_order;
}

void StringContactMap::all_contacts(NodePtr node, vector<Contact>& prefix_list) const
{
    if(node != NULL)
    {
        all_contacts(node->left, prefix_list);
        prefix_list.push_back(node->value);
        all_contacts(node->right, prefix_list);
    }
}

void StringContactMap::add(string key, Contact value)
{
        add(root, key, value);
}

void StringContactMap::add(NodePtr& node, string key, Contact value)
{
    if (node == NULL)
    {
        node = new ContactNode(key, value);
        return;
    }
    if (node->key == key)
    {
        node->value = value;
        return;
    }
    if (key < node->key)
    {
        add(node->left, key, value);
        return;
    }
    add(node->right, key, value);
}

void StringContactMap::remove(string key)
{
	remove(root, key);
}

bool StringContactMap::contains(string key) const
{
    return (contains(root, key));
}

bool StringContactMap::contains(NodePtr node, string key) const
{
    if(node ==  NULL)
    {
        return false;
    }
    if(node->key == key)
    {
        return true;
    }
    if (key < node->key)
    {
        return contains(node->left, key);
    }
    return contains(node->right, key);
}

Contact StringContactMap::get(string key) const
{
    if(!(contains(key)))
    {
        throw KeyException();
    }
    else
    {
        return get(root, key);
    }
}

Contact StringContactMap::get(NodePtr node, string key) const
{
    if(node == NULL)
    {
        Contact ekkert;
        return ekkert;
    }
    if(node->key == key)
    {
        return node->value;
    }
    if(key < node->key)
    {
        return get(node->left, key);
    }
    return get(node->right, key);
}

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    vector<Contact> prefix_names;
    
    prefix_search(root, prefix, prefix_names);
    
    return prefix_names;
}

void StringContactMap::prefix_search(NodePtr node, string prefix, vector<Contact>& v) const
{
    if(node == NULL)
    {
        return;
    }
    string temp = (node->key.substr(0, prefix.size()));
    
    prefix_search(node->left, prefix, v);
    
    if(prefix == temp)
    {
        v.push_back(node->value);
    }
    
    prefix_search(node->right, prefix, v);
}

void StringContactMap::free_memory(NodePtr node)
{
    if(node != NULL)
    {
        free_memory(node->left);
        free_memory(node->right);
        delete node;
    }
}

void StringContactMap::remove(NodePtr& node, string key)
{
	if(node == NULL) {
		return;
	} else if(node->key == key) {
		remove_root(node);
	} else if(key < node->key) {
		remove(node->left, key);
	} else {
		remove(node->right, key);
	}
}

void StringContactMap::remove_root(NodePtr& root)
{
	NodePtr succ;
	if(root->is_leaf()) {
		delete root;
		root = NULL;
	} else if(root->left == NULL) {
		succ = root->right;
		delete root;
		root = succ;
	} else if(root->right == NULL) {
		succ = root->left;
		delete root;
		root = succ;
	} else {
		NodePtr new_root = remove_min(root->right);
		new_root->left = root->left;
		new_root->right = root->right;
		delete root;
		root = new_root;
	}
}

NodePtr StringContactMap::remove_min(NodePtr& node)
{
	if(node->left == NULL) {
		NodePtr old_node = node;
		node = node->right;
		return old_node;
	} else {
		return remove_min(node->left);
	}
}

ostream& operator <<(ostream& out, const StringContactMap& map)
{
	vector<Contact> contacts = map.all_contacts();

	for(size_t i = 0; i < contacts.size(); i++) {
		out << contacts[i] << endl;
	}
	return out;
}

