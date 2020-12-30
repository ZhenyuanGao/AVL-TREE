//Learn from cprogramming.com/tutorial/lesson18.html
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <array>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;

struct node;
typedef node *node_ptr;

struct node
{
    int key_value;
    node_ptr left;
    node_ptr right;
    int height;
};
// string holds user input
string test_title;
// boolean flag
bool flag = true;
//vector that holds all potential unbalanced nodes
vector<node_ptr> node_out_of_bound;
//the resources is learned from cprogramming.com/tutorial/lession18.html.
//talking about building a binary tree

class avltree
{
public:
    avltree(/* args */);
    ~avltree();
    node_ptr search(int value);
    node_ptr root;
    void delete_node(node_ptr a);
    void insert(int key);
    int get_height_node(node_ptr leaf_node);
    int get_balance_factor(node_ptr leaf);
    int check_balance(node_ptr leaf);
    node_ptr check_balance2(node_ptr leaf);
    node_ptr right_rotation(node_ptr leaf);
    node_ptr left_rotation(node_ptr leaf);
    node_ptr left_right_rotation(node_ptr leaf);
    void get_parent(int value, node_ptr target, int parent);
    node_ptr right_left_rotation(node_ptr leaf);
    void general_function(node_ptr root);
    void general_function_delete(node_ptr root);
    node_ptr check_b_3(node_ptr leaf);
    node_ptr global_node;
    int counter = 0;
    void print_node(int key_value, node_ptr leaf);
    node_ptr special_right_left_rotation(node_ptr leaf);
    void get_input();
    int parent_num;
    node_ptr del_search(int value);
    void get_unbalanced_ones(node_ptr root);
private:
    // learn from tutorial, destory
    //void destroy_tree( node_ptr leaf);
    node_ptr search_node(int key_value, node_ptr leaf);
    void insert(int key_value, node_ptr leaf);
    node_ptr delete_search(int key_value, node_ptr leaf);

    int get_max(int a, int b);
};
// initialize the root to null for later functions.
avltree::avltree(/* args */)
{
    root = NULL;
}

avltree::~avltree()
{
    //destroy_tree();
}

avltree tree;

void avltree::insert(int key, node_ptr leaf_node)
{
    //the value is smaller

    if (key < leaf_node->key_value)
    {
        if (leaf_node->left != NULL)
        {
            insert(key, leaf_node->left);
        }

        if (leaf_node->left == NULL)
        {
            leaf_node->left = new node;
            leaf_node->left->key_value = key;
            leaf_node->left->left == NULL;
            leaf_node->left->right == NULL;
        }
    }
    if (key > leaf_node->key_value)
    {
        if (leaf_node->right != NULL)
        {
            insert(key, leaf_node->right);
        }

        if (leaf_node->right == NULL)
        {
            leaf_node->right = new node;
            leaf_node->right->key_value = key;
            //set the last node to be null
            leaf_node->right->left == NULL;
            leaf_node->right->right == NULL;
        }
    }
}

void avltree::insert(int key)
{
    if (root == NULL)
    {
        root = new node;
        //put the key value in the root node
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
    if (root != NULL)
    {

        insert(key, root);
    }
}
node_ptr avltree::search_node(int key, node_ptr leaf_node)
{
    if (root == NULL)
    {
        cout << "there is no tree yet.\n";
        return NULL;
    }
    if (key == leaf_node->key_value)
    {
        cout << leaf_node->key_value << " ";
        cout << "(found) "; 
        global_node = leaf_node;
        return leaf_node;
    }

    if (key < leaf_node->key_value)
    {
        if (leaf_node->left != NULL)
        {
            cout << leaf_node->key_value << " ";
            search_node(key, leaf_node->left);
        }

        if (leaf_node->left == NULL)
        {
            cout << leaf_node->key_value << " ";

            cout << "(not found!)";
            return NULL;
        }
    }
    if (key > leaf_node->key_value)
    {
        if (leaf_node->right != NULL)
        {
            cout << leaf_node->key_value << " ";

            search_node(key, leaf_node->right);
        }

        if (leaf_node->right == NULL)
        {
            cout << leaf_node->key_value << " ";

            cout << "(not found!)";
            return NULL;
        }
    }

    return NULL;
}
node_ptr avltree::delete_search(int key, node_ptr leaf_node)
{
    if (root == NULL)
    {
        cout << "there is no tree yet.\n";
        return NULL;
    }
    if (key == leaf_node->key_value)
    {

        global_node = leaf_node;
        return leaf_node;
    }

    if (key < leaf_node->key_value)
    {
        if (leaf_node->left != NULL)
        {

            delete_search(key, leaf_node->left);
        }

        if (leaf_node->left == NULL)
        {

            return NULL;
        }
    }
    if (key > leaf_node->key_value)
    {
        if (leaf_node->right != NULL)
        {

            delete_search(key, leaf_node->right);
        }

        if (leaf_node->right == NULL)
        {

            return NULL;
        }
    }

    return NULL;
}

node_ptr avltree::search(int value)
{
    if (root != NULL)
    {
        return search_node(value, root);
    }
    if (root == NULL)
    {
        return NULL;
    }

    return NULL;
}

node_ptr avltree::del_search(int value)
{
    if (root != NULL)
    {
        return delete_search(value, root);
    }
    if (root == NULL)
    {
        return NULL;
    }

    return NULL;
}

// learn from Geeks for geeks website, how to get the parent of a node in the tree.
//Website:https://www.geeksforgeeks.org/find-the-parent-of-a-node-in-the-given-binary-tree/#:~:text=Approach%3A%20Write%20a%20recursive%20function,current%20node%20as%20the%20parent
//comments are provided through this function to indicate my understanding of the function
void avltree::get_parent(int value, node_ptr begin, int parent)
{
    // base case
    if (begin == NULL)
    {
        return;
    }
    // use recursion.
    if (begin->key_value == value)
    {
        parent_num = parent;
    }
    else
    {
        // make sure both right and left will be executed.
        get_parent(value, begin->left, begin->key_value);
        get_parent(value, begin->right, begin->key_value);
    }
}
/*
    1A. If BF(node) = +2 and BF(node -> left-child) = +1, perform R rotation.
    1B. If BF(node) = +2 and BF(node -> left-child) = -1, perform LR rotation.
    1C. If BF(node) = +2 and BF(node -> left-child) = 0, perform R rotation.

*/

void avltree::delete_node(node_ptr leaf_node)
{
    if (root == NULL)
    {
        cout << "there is no tree yet.\n";
    }

    if (leaf_node->left == NULL && leaf_node->right == NULL)
    {
        delete leaf_node;

        cout << "and deleted";
    }
    //delete general_function
    else if (leaf_node->left == NULL && leaf_node->right != NULL)
    {
        get_parent(leaf_node->key_value, root, -1);
        if (parent_num > leaf_node->key_value)
        {
            del_search(parent_num);
            global_node->left = leaf_node->right;
        }
        else if (parent_num < leaf_node->key_value)
        {
            del_search(parent_num);
            global_node->right = leaf_node->right;
        }
        delete leaf_node;

        cout << "and deleted";
    }
    else if (leaf_node->left != NULL && leaf_node->right == NULL)
    {
        get_parent(leaf_node->key_value, root, -1);
        if (parent_num > leaf_node->key_value)
        {

            del_search(parent_num);
            global_node->left = leaf_node->left;
        }
        else if (parent_num < leaf_node->key_value)
        {
            del_search(parent_num);

            global_node->right = leaf_node->left;
        }
        delete leaf_node;

        cout << "and deleted";
    }
    if (leaf_node->left != NULL && leaf_node->right != NULL)
    {
        // designed to hold the max of the left predecessor
        node_ptr maximum;
        node_ptr prev; //the parent of the max
        if (leaf_node == root)
        {
            maximum = leaf_node->left;
            prev = maximum;
            //get the max of the left sub tree by going right all the way.
            while (maximum->right != NULL)
            {

                maximum = maximum->right;
            }

            //now maximum is the new root.
            //since we go right, it is guarentee that prev will be less than maximum
            prev->right = NULL;
            maximum->left = root->left;
            maximum->right = root->right;
            delete leaf_node;
            root = maximum;
            cout << "and deleted";
        }
        if (leaf_node != root)
        {
            maximum = leaf_node->left;
            prev = maximum;
            //get the max of the left sub tree by going right all the way.
            while (maximum->right != NULL)
            {

                maximum = maximum->right;
            }

            //now maximum is the new root.
            //since we go right, it is guarentee that prev will be less than maximum
            prev->right = NULL;
            maximum->left = leaf_node->left;
            maximum->right = leaf_node->right;
            delete leaf_node;
            cout << "and deleted";
        }
    }
}

//return the max of the two,
int avltree::get_max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }

    if (b > a)
    {
        return b;
    }
    return 0;
}

//the the height of the node.
int avltree::get_height_node(node_ptr leaf_node)
{
    //get the height recursively.
    if (leaf_node == NULL)
    {
        
        return -1;
    }
    else
    {
        leaf_node->height = get_max(get_height_node(leaf_node->left), get_height_node(leaf_node->right)) + 1;
        return leaf_node->height;
    }

    return 200;
}

int avltree::get_balance_factor(node_ptr leaf_node)
{
    int balance_factor;
    if (leaf_node->left != NULL && leaf_node->right != NULL)
    {
        balance_factor = leaf_node->left->height - leaf_node->right->height;
    }
    else
    {
        balance_factor = get_height_node(leaf_node->left) - get_height_node(leaf_node->right);
    }
    return balance_factor;
}

int avltree::check_balance(node_ptr leaf)
{

    if (leaf == NULL)
    {
        return true;
    }
   
    return (abs(get_balance_factor(leaf)) <= 1 && check_balance(leaf->left) && check_balance(leaf->right));
}


node_ptr avltree::right_rotation(node_ptr leaf)
{

    node_ptr parent = leaf;
    node_ptr children;
    node_ptr child_right;
    get_balance_factor(parent);
    children = parent->left;
    child_right = children->right;
    children->right = parent;
    parent->left = child_right;
    //cout<<get_balance_factor(children);

    //update the height
    get_height_node(children);
    if (parent == root)
    {
        root = children;
    }
    else
    {
        root->left = children;
    }

    return children;
}
node_ptr avltree::left_rotation(node_ptr leaf)
{

    node_ptr parent = leaf;
    node_ptr children;
    node_ptr child_left;
    get_balance_factor(parent);
    children = parent->right;
    child_left = children->left;
    children->left = parent;
    parent->right = NULL;
    parent->right = child_left;
    //update the height.
    get_height_node(children);
    return children;
}
node_ptr avltree::left_right_rotation(node_ptr leaf)
{
    node_ptr parent = leaf;
    node_ptr children;
    node_ptr second_children;
    node_ptr child_left;
    if (get_balance_factor(leaf->left) == -1)
    {
        children = leaf->left;
        second_children = children->right;
        leaf->left = second_children;
        second_children->left = children;
        //set the right hand side of second_children
        //set both to NULL;
        second_children->right = NULL;
        children->right = NULL;

        node_ptr parent2 = leaf;
        node_ptr children2;
        node_ptr child_right;
        get_balance_factor(parent2);
        children2 = parent2->left;
        children2->right = parent2;
        parent2->left = NULL;
        get_height_node(children2);

        return children2;
    }

    return NULL;
}
node_ptr avltree::right_left_rotation(node_ptr leaf)
{

    
    node_ptr parent = leaf;
    node_ptr children;
    node_ptr second_children;
    node_ptr child_left;
    if (get_balance_factor(leaf->right) == 1)
    {
        children = leaf->right;
        second_children = children->left;
        leaf->right = second_children;
        second_children->right = children;

        //set the right hand side of second_children
        //set both to NULL;
        second_children->left = NULL;
        children->left = NULL;
        node_ptr parent2 = leaf;
        node_ptr children2;
        node_ptr child_left;
        get_balance_factor(parent2);
        children2 = parent2->right;
        children2->left = parent2;
        parent2->right = NULL;
        //remember to recover the previous command
        //update the height.
        get_height_node(children2);
        return children2;
    }

    return leaf;
}
node_ptr avltree::special_right_left_rotation(node_ptr leaf)
{
    node_ptr parent = leaf;
    node_ptr children;
    node_ptr second_children;
    node_ptr child_left;
    if (get_balance_factor(leaf->right) == 1)
    {
        children = leaf->right;
        second_children = children->left;
        leaf->right = second_children;
        children->left = second_children->right;
        second_children->right = children;
        node_ptr parent2 = leaf;
        node_ptr children2;
        node_ptr child_left;
        get_balance_factor(parent2);
        children2 = parent2->right;
        child_left = children2->left;
        children2->left = parent2;
        //remember to recover the previous command
        parent2->right = child_left;
        //update the height.
        get_height_node(children2);
        //set the new node to root.
        root = children2;
        return children2;
    }

    return leaf;
}

node_ptr avltree::check_balance2(node_ptr l)
{
    return l->left;
}
void avltree::general_function(node_ptr root)
{
    /*
// stragety I google the standard to do rotation, code implemented by me and only myself.
if BF(node) = +2 and BF(node -> left-child) = +1, perform right rotation.
If BF(node) = -2 and BF(node -> right-child) = 1, perform left rotation.
If BF(node) = -2 and BF(node -> right-child) = +1, perform Right Left rotation.
If BF(node) = +2 and BF(node -> left-child) = -1, perform Left Right rotation.
*/
    node_ptr current_node;
    if (check_balance(root))
    {
        return;
    }
    else
    {
        current_node = root;
        if (get_balance_factor(current_node) == 2)
        {
            if (get_balance_factor(current_node->left) == 1)
            {
                right_rotation(current_node);
            }
            else if (get_balance_factor(current_node->left) == -1)
            {
                left_right_rotation(current_node);
            }
            //level is and there are two at the same time.
            else if (get_balance_factor(current_node->left) == 2)
            {
                //connect with previous node
                root->left = left_right_rotation(current_node->left);
            }
        }
        if (get_balance_factor(current_node) == -2)
        {
            if (get_balance_factor(current_node->right) == -1)
            {
                left_rotation(current_node);
            }
            if (get_balance_factor(current_node->right) == 1)
            {
                if (current_node->right->right != NULL)
                {
                    special_right_left_rotation(current_node);
                }
                else
                    right_left_rotation(current_node);
            }
        }
      
    }
}
void avltree::print_node(int key, node_ptr leaf_node)
{
    if (root == NULL)
    {
        cout << "there is no tree yet.\n";
    }
    if (key == leaf_node->key_value)
    {

        cout << leaf_node->key_value << " "
             << "(inserted)";
    }
    if (key < leaf_node->key_value)
    {
        if (leaf_node->left != NULL)
        {
            cout << leaf_node->key_value << " ";
            print_node(key, leaf_node->left);
        }

        if (leaf_node->left == NULL)
        {
            cout << "not found";

        }
    }
    if (key > leaf_node->key_value)
    {
        if (leaf_node->right != NULL)
        {
            cout << leaf_node->key_value << " ";
            print_node(key, leaf_node->right);
        }

        if (leaf_node->right == NULL)
        {
        }
    }
}

void avltree::general_function_delete(node_ptr leaf_)
{

    if (check_balance(root))
    {
        return;
    }
    else
    {
        //pop up the potential unbalanced vector.
        get_unbalanced_ones(root);
        node_ptr current_node = node_out_of_bound[0];
        if (get_balance_factor(current_node) == 2)
        {
            if (get_balance_factor(current_node->left) == 1)
            {
                
                right_rotation(current_node);
                
            }
            else if (get_balance_factor(current_node->left) == -1)
            {
                left_right_rotation(current_node);
            }

            else if (get_balance_factor(current_node->left) == 0)
            {
                right_rotation(current_node);
            }
        }
        //left rotation delete, different delete situations.
        else if (get_balance_factor(current_node) == -2)
        {
            if (get_balance_factor(current_node->left) == -1)
            {
                left_rotation(current_node);
            }

            if (get_balance_factor(current_node->left) == 1)
            {
                right_left_rotation(current_node);
            }

            if (get_balance_factor(current_node->left) == 0)
            {
                left_rotation(current_node);
            }
        }
    }
}
// fill up the vector that holds all of the potential nodes from the tree.
void avltree::get_unbalanced_ones(node_ptr a)
{
    if (a == NULL)
    {
        return;
    }

    if (abs(get_balance_factor(a)) == 2)
    {
        node_out_of_bound.push_back(a);
    }

    get_unbalanced_ones(a->left);
    get_unbalanced_ones(a->right);
}
//read user command
void evaluate_command(string a)
{
    string number;
    string command = string(a.c_str(), a.c_str() + a.find(" "));
    //cout<<command;
    int numb;

    number = string(a.c_str() + a.find(" ") + 1, a.c_str() + a.size());
    numb = stoi(number);

    if (command == "insert")
    {

        tree.insert(numb);
        tree.print_node(numb, tree.root);
        cout << "\n";
        tree.get_height_node(tree.root);
        tree.general_function(tree.root);
    }
    else if (command == "find")
    {
        tree.search(numb);
        cout << "\n";
    }
    else if (command == "delete")
    {
        tree.search(numb);
        if (tree.global_node != NULL)
        {
            tree.delete_node(tree.global_node);
            tree.get_height_node(tree.root);
            tree.general_function_delete(tree.root);
            cout << "\n";
        }

        else
        {
            cout << "give a valid input command, for example:Insert 4\n";
        }

    } 

    
}
int counter = 0;
// get userinput
void get_input()
{
    while (flag)
    {
        cout << "Please input your command here: ";
        getline(cin, test_title);
        if (test_title == "")
        {
            cout << "Give a valid input next time\n";
            exit(3);
        }
        evaluate_command(test_title);
        counter++;
    }
}

int main()
{

    get_input();
    return 0;
}
