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
    unique_ptr<SmartTree> left;
    unique_ptr<SmartTree> right;
};

unique_ptr<SmartTree> CreateLeaf(int value)
{
    auto newLeaf = make_unique<SmartTree>();
    newLeaf->value=value;
    newLeaf->left=nullptr;
    newLeaf->right=nullptr;
    
    return newLeaf;
}

unique_ptr<SmartTree> Insertleft(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree)
{
    tree->left = move(left_subtree);
    return tree;
}

unique_ptr<SmartTree> InsertRight(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree)
{
    tree->left = move(right_subtree);
    return tree;
}

void PrintTreeInOrder(const unique_ptr<SmartTree>&unique_ptr)
{
    if (unique_ptr==nullptr) return;
    PrintTreeInOrder(unique_ptr->left);
    cout << (unique_ptr->value) << " ";
    PrintTreeInOrder(unique_ptr->right);
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
        result.append(DumpTree(tree->left));
        result.append(DumpTree(tree->right));
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
    NewTree->left=RestoreTree(tree);
    NewTree->right=RestoreTree(tree);

    return NewTree;
}

int main()
{
    unique_ptr<SmartTree> tree = nullptr;
    string treeString = "30 10 50 # # # 20 45 # # 35 # #";
    tree=RestoreTree(treeString);

    cout << "In order: ";
    PrintTreeInOrder(tree);

    string dumpedTree=DumpTree(tree);
    tree=RestoreTree(treeString);

    cout << std::endl << "In order (po usunięciu i przywróceniu drzewa): ";
    PrintTreeInOrder(tree);
}