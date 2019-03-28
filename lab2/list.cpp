#include <iostream>
using ::std::cout;
using ::std::endl;

struct ForwardList{
    int num;
    ForwardList *next;

    ForwardList *PushFront(ForwardList *list, ForwardList *head);
    void Append(ForwardList *list, ForwardList *tail);
};

ForwardList *ForwardList::PushFront(ForwardList *list, ForwardList *head)
    {
        head->next=list;
        list=head;
        return list;
    }

void ForwardList::Append(ForwardList *list, ForwardList *tail)
    {
        while(list->next)
        {
            list=list->next;
        }
        
        list->next=tail;
        tail->next=NULL;
    }

ForwardList *CreateNode(int value)
{
    ForwardList *newNode= new ForwardList;
    newNode->num=value;
    return newNode;
}

void DestroyList(ForwardList *list)
{
    while(list)
    {
        ForwardList *deletingNode=list;
        list=list->next;
        delete deletingNode;
    }
}

void printingListElements(ForwardList *list)
{
    cout << "Zawartość listy: " << endl;
    if(!list) cout << "Brak elemntów" << endl;
    while(list)
    {
        cout << list->num << " ";;
        list=list->next;
    }
    cout << endl;
}

int main()
{
    ForwardList *headList=NULL;
    printingListElements(headList);

    cout << "Wstawianie liczb <1,5> na początek listy" << endl;
    for (int i=1; i<6; i++)
    {
        ForwardList *newNode=CreateNode(i);
        headList=headList->PushFront(headList, newNode);
    }
    printingListElements(headList);

    cout << "Wstawianie liczb <6,10> na koniec listy" << endl;
    for (int i=6; i<11; i++)
    {
        ForwardList *newNode=CreateNode(i);
        headList->Append(headList, newNode);
    }
    printingListElements(headList);
    DestroyList(headList);
}