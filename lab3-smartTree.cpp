#include <ostream>
using ::std::ostream;

#include <string>
using ::std::string;
using ::std::to_string;

#include <memory>
using ::std::unique_ptr;
using ::std::make_unique;

#include <iostream>
using ::std::cout;

struct SmartTree{
    int value;
    unique_ptr<SmartTree> leftChild;
    unique_ptr<SmartTree> rightChild;
};

unique_ptr<SmartTree> CreateLeaf(int value)
{
    auto newLeaf = make_unique<SmartTree>();
    newLeaf->value=value;
    newLeaf->leftChild=nullptr;
    newLeaf->rightChild=nullptr;
    
    return newLeaf;
}
unique_ptr<SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree)
{
    tree->leftChild = move(left_subtree);
    return tree;
}
unique_ptr<SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree)
{
    tree->leftChild = move(right_subtree);
    return tree;
}
void PrintTreeInOrder(const unique_ptr<SmartTree>&unique_ptr /*, ostream*out*/ )
{
    if (unique_ptr==nullptr) return;
    PrintTreeInOrder(unique_ptr->leftChild);
    cout << (unique_ptr->value) << " ";
    PrintTreeInOrder(unique_ptr->rightChild);
}
string DumpTree(const unique_ptr<SmartTree>&tree)
{
    string result;
    if (tree==nullptr) 
    {
        result.append("# ");
    } 
    else 
    {
        result.append(to_string(tree->value));
        result.append(" ");
        result.append(DumpTree(tree->leftChild));
        result.append(DumpTree(tree->rightChild));
    }
    return result;
}
string getToken(const string&tree)
{
    string token="";
    static int i=0;
    for(i; i<tree.size(); i++)
    {
        if (tree.at(i)==' ')
        {
            i++;
            return token;
        }
        token.push_back(tree.at(i));
    }
    if(i==tree.size()) i=0;
    return token;
}

unique_ptr<SmartTree> RestoreTree(const string&tree)
{
    auto NewTree = make_unique<SmartTree>();
    string nextToken=getToken(tree);
    if (nextToken == "#") return nullptr;
    NewTree=CreateLeaf(atoi(nextToken.c_str()));
    NewTree->leftChild=RestoreTree(tree);
    NewTree->rightChild=RestoreTree(tree);

    return NewTree;
}

int main()
{
    unique_ptr<SmartTree> tree = nullptr;
    string treeString = "30 10 50 # # # 20 45 # # 35 # #";

    cout << "Tree String na początku: " << treeString << std::endl;
    tree=RestoreTree(treeString);
    cout << "In order: ";
    PrintTreeInOrder(tree);
    string dumpedTree=DumpTree(tree);
    cout << std::endl << "Dumped Tree: "<<dumpedTree << std::endl;
    tree=RestoreTree(treeString);
    cout << "Na koniec, po przywróceniu: ";
    PrintTreeInOrder(tree);
}