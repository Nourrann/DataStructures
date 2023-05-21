#include <iostream>
#include <cstring>
using namespace std;

class SuffixTreeNode;

// class Node to store the data of each node: its child, its parent, its data(char), and
// an object of the SuffixTreeNode class cause each node has its children(an array of children),
// the start index and end index of each node
class Node
{
public:
    char chr; // data of the node
    SuffixTreeNode *suffixNode;
    Node *child ;
    Node *parent;

    Node()
    {
        chr = ' ';             // initializing the data of the node (empty string)
        suffixNode = nullptr; // and initializing each pointer as null pointer
        child = nullptr;
        parent = nullptr;
   }
};

class Trie
{
public:

    // each node has an end and start pointers, end pointer points to the next
    Node *end;
    Node *start;

    Trie()
    {
        end = nullptr;
        start = nullptr;
    }

    // function to insert nodes in trie
    void insertInTrie(Node *newSuffixNode)
    {
        Node *node = newSuffixNode;

        // if start equals null, it means that the trie is empty
        // and contains root only, so the start and end equals the inserted node
        if (start == nullptr)
        {
            start = end = node;
        }

        // if the trie is not empty, then child of the end node points to the inserted node,
        // and the parent of this node points to the end, then end equals node, for the new insertion
        else
        {
            end->child = node;
            node->parent = end;
            end = node;
        }
    }


// function to check if the inserted node exists, called in the SuffixTree class
SuffixTreeNode *checkNewNode(char Char)
{
    if (start == nullptr)
    {
        return nullptr;
    }

    Node *temp = start;
    while (temp != nullptr)
    {
        if (temp->chr == Char)
        {
           return temp->suffixNode;
        }
        temp = temp->child;
    }

    return nullptr;
}


// destructor to delete nodes in trie before the program terminates
~Trie()
{
    Node *temp = start;
    while (temp != nullptr)
    {
        Node *del = temp;
        temp = temp->child;
        delete del;
    }
}
};


// class to store the data of the suffix tree node, the start index, the end index,
// and the children array
class SuffixTreeNode
{
public:
    //array of trie pointers to child nodes with the size of the alphabet
    Trie *children;
    int suffixIndex; // The starting index of the suffix ending at this node (represents the leaf node), -1 otherwise (non-leaf node)
    int start;      // the start index of each substring
    SuffixTreeNode()
    {
        //this is for small characters of the alphabet only (lowercase)
        children = new Trie[27];
        suffixIndex = -1;
    }
};
// class to build suffix tree
class SuffixTree
{
private:
    SuffixTreeNode *root;
public:
SuffixTree(char str[])
{
    int n = strlen(str);
    root = new SuffixTreeNode;
    for (int i = 0; i < n; i++)
    {
        SuffixTreeNode *current = root;
        for (int j = i; j < n; j++)
        {
            SuffixTreeNode *temp = current->children->checkNewNode(str[j]);  // check if the node exists in the tree
            if (temp == nullptr)  // if the node does not exist
            {
                Node *tempNode = new Node;                // create new node
                tempNode->chr = str[j];                   // assigns the data of the node to the current char of the string
                tempNode->suffixNode = new SuffixTreeNode;
                current->children->insertInTrie(tempNode); // insert the data in the trie
                temp = tempNode->suffixNode;
            }
            current = temp;
       }
        current->suffixIndex = i;  // the index of inserted char, will be -1 if the node is non leaf
        current->start = i;       //  the index of inserted char
    }
}
// function to search for a given substring
void Search(char str[])
{
    int n = strlen(str);
    SuffixTreeNode *tmp = root;
    for (int i = 0; i < n; i++)
    {
        tmp = tmp->children->checkNewNode(str[i]);
        // if temp equals null, it means that the substring does not exist in the tree
        if (tmp == nullptr)
        {
             break;
        }
    }
    // if temp equals null, it means that the substring does not exist in the tree, prints does't exist
    if (tmp == nullptr)
    {
        cout << "Does not exist";
    }
    // else if the substring exists, print the end index of its leaf nodes
    else
    {
        displaySuffixIndex(tmp);
    }
    cout << endl;
}

void displaySuffixIndex(SuffixTreeNode *node)
{
    Node *currentNode = node->children->start;
    while (currentNode != nullptr)
    {
        if (currentNode->suffixNode->suffixIndex != -1) // checks if the currentNode is leaf or not
        {
            cout << currentNode->suffixNode->suffixIndex << " ";
        }
        else
        {
            displaySuffixIndex(currentNode->suffixNode);    // if the node is non leaf, it loops again till it reaches the leaf node
        }
        currentNode = currentNode->child;
    }
}
};

int main()
{
    // Construct a suffix trie containing all suffixes of "bananabanaba$"
    //            0123456789012
    SuffixTree t("bananabanaba$");
    t.Search("ana"); // Prints: 1 3 7
    t.Search("naba"); // Prints: 4 8


    cout << "\n---test 1---" <<endl;
    //test1
    SuffixTree a("abdalla$");
    a.Search("alla"); // Prints: 3
    a.Search("l"); // Prints: 4 5
    a.Search("ab"); // Prints: 0

    cout << "\n---test 2---" <<endl;
    //test2
    SuffixTree h("hanaessamsayedahmedamerya$");
    h.Search("hana"); // Prints: 0
    h.Search("ahmed"); // Prints: 14
    h.Search("ss"); // Prints: 5

    cout << "\n---test 3---" <<endl;
    //test3
    SuffixTree r("aaaaaaa$");
    r.Search("a"); // Prints: 0 1 2 3 4 5 6
    r.Search("aaaa"); // Prints: 0 1 2 3
    r.Search("b"); // Prints: Does not exist

    cout << "\n---test 4---" <<endl;
    //test4
    SuffixTree m("mississippi$");
    m.Search("i"); // Prints: 1 4 7 10
    m.Search("s"); // Prints: 2 5 3 6
    m.Search("ss"); // Prints: 2 5

    cout << "\n---test 5---" <<endl;
    //test5
    SuffixTree d("dddddda$");
    d.Search("a"); // Prints: 6
    d.Search("i"); // Prints: Does not exist
    d.Search("dd"); // Prints: 0 1 2 3 4

    cout << "\n---test 6---" <<endl;
    //test6
    SuffixTree g("gatagaca$");
    g.Search("a"); // Prints: 1 3 5 7
    g.Search("tagaca"); // Prints: 2
    g.Search("t"); // Prints: 2

    cout << "\n---test 7---" <<endl;
    //test7
    SuffixTree n("nouran$");
    n.Search("n"); // Prints: 0 5
    n.Search("ran"); // Prints: 3
    n.Search("ou"); // Prints: 1

    cout << "\n---test 8---" <<endl;
    //test8
    SuffixTree mh("mariamhany$");
    mh.Search("mar"); // Prints: 0
    mh.Search("h"); // Prints: 6
    mh.Search("hany"); // Prints: 6

    cout << "\n---test 9---" <<endl;
    //test9
    SuffixTree me("malakemad$");
    me.Search("alak"); // Prints: 1
    me.Search("emad"); // Prints: 5
    me.Search("a"); // Prints: 1 3 7

    cout << "\n---test 10---" <<endl;
    //test10
    SuffixTree x("aabbcc$");
    x.Search("ab"); // Prints: 1
    x.Search("bc"); // Prints: 3
    x.Search("d"); // Prints: Does not exist

    return 0;

}
