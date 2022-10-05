#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct BookInfo
{
    string book;
    int price;
    int pages;
    double rating;
    void Out();
};

struct DLList
{
    struct Node
    {
        BookInfo data;
        Node* next;
        Node* prev;
    };

    Node* F = NULL;
    Node* L = NULL;
    Node* C = NULL;
    Node* Temp = NULL;
    int Count;

    void Out();
    void Info();
    void Clear();

    bool MoveNext();
    bool MovePrev();
    bool MoveFirst();
    bool MoveLast();

    bool Init(BookInfo);
    bool AddNext(BookInfo);
    bool AddPrev(BookInfo);
    bool AddFirst(BookInfo);
    bool AddLast(BookInfo);

    bool Del(BookInfo&);
    bool DelNext(BookInfo&);
    bool DelPrev(BookInfo&);
    bool DelFirst(BookInfo&);
    bool DelLast(BookInfo&);

    void sort();
};

bool DLList::MoveNext()
{
    if (!F)       return false;
    if (!C) { C = F; return true; }
    if (!C->next) return false;
    C = C->next;
    return true;
}

bool DLList::MovePrev()
{
    if (!F)       return false;
    if (!C) { C = F; return true; }
    if (!C->prev) return false;
    C = C->prev;
    return true;
}
bool DLList::MoveFirst()
{
    if (!F) return false;
    C = F;
    return true;
}

bool DLList::MoveLast()
{
    if (!L) return false;
    C = L;
    return true;
}

bool DLList::Init(BookInfo data)
{
    if (!F)
    {
        F = new Node;
        L = F;
        C = F;
        F->prev = NULL;
        F->next = NULL;
        F->data = data;
        Count = 1;
        return true;
    }
    else
        return false;
}

bool DLList::AddNext(BookInfo data)
{
    if (!F) return Init(data);

    Node* temp = C->next;
    C->next = new Node;
    C->next->next = temp;
    C->next->prev = C;

    if (!temp)
        L = C->next;
    else
        temp->prev = C->next;

    C = C->next;
    C->data = data;
    Count++;
    return true;

}

bool DLList::AddPrev(BookInfo data)
{
    if (!F) return Init(data);

    Node* temp = C->prev;
    C->prev = new Node;
    C->prev->next = C;
    C->prev->prev = temp;

    if (!temp)
        F = C->prev;
    else
        temp->next = C->prev;

    C = C->prev;
    C->data = data;
    Count++;
    return true;
}

bool DLList::AddFirst(BookInfo data)
{
    if (MoveFirst())return AddPrev(data);
    else return false;
}

bool DLList::AddLast(BookInfo data)
{
    if (MoveLast())return AddNext(data);
    else return false;
}

void DLList::Out()
{
    if (!F)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = F;
    cout << "List: " << endl << endl;
    do
    {
        temp->data.Out();
        temp = temp->next;
    } while (temp);
    cout << endl;
}

void DLList::Info()
{

    if (Count)
        cout << "List node count: "
        << Count << endl << endl;
    else
        cout << "List is empty" << endl;
    if (C)
    {
        if (MoveFirst())
        {
            cout << "Current node data: ";
            C->data.Out();
        }
    }
}

bool DLList::DelFirst(BookInfo& data)
{
    if (!F)      return false;
    if (C != F)    MoveFirst();

    Node* temp = C->next;
    data = C->data;

    if (temp) temp->prev = NULL;
    delete C;

    C = temp;
    F = temp;
    Count--;
    if (!temp) { L = NULL; return false; }
    return true;
}

bool DLList::DelLast(BookInfo& data)
{
    if (!F)      return false;
    if (C != L)    MoveLast();

    Node* temp = C->prev;
    data = C->data;

    if (temp) temp->next = NULL;
    delete C;

    C = temp;
    L = temp;
    Count--;

    if (!temp) { F = NULL; return false; }
    return true;
}

bool DLList::Del(BookInfo& data)
{
    if (!F) return false;
    if (!C) return false;

    if (C == F) return DelFirst(data);
    if (C == L) return DelLast(data);

    Node* temp = C->next;
    data = C->data;

    C->prev->next = C->next;
    C->next->prev = C->prev;

    delete C;
    C = temp;
    Count--;
    return true;
}

bool DLList::DelNext(BookInfo& data)
{
    if (!F) return false;
    if (!C) return false;
    if (MoveNext()) return Del(data);
    return false;
}
bool DLList::DelPrev(BookInfo& data)
{
    if (!F) return false;
    if (!C) return false;
    if (MovePrev()) return Del(data);
    return false;
}

void DLList::Clear()
{
    if (!MoveFirst())
    {
        cout << "List is empty" << endl;
        return;
    }
    BookInfo k;
    while (Del(k));
}

void BookInfo::Out()
{
    cout << "Book: " << book << "\t\t" << "Price: " << price << "\t" << "Pages: " << pages << "\t" << "Rating: " << rating << endl << endl;
}

bool GetFile(DLList&, BookInfo&);
bool WriteFile(DLList&, BookInfo&);
void GetBook(BookInfo&); 
void SortPrice(DLList&);
void SortName(DLList&);

int main()
{
    BookInfo Info;
    DLList DLList;
    GetFile(DLList, Info);
    DLList.Out();
    int num, key = 0, key1 = 0, key2 = 0;
    do
    {
        cout << "1) Add element" << endl
            << "2) Del element" << endl
            << "3) Clear list" << endl
            << "4) Upload data" << endl
            << "5) Sort price" << endl
            << "6) Sort name" << endl
            << "0) Exit" << endl;
        cout << endl << "Select an action: ";
        cin >> key;
        cout << endl;
        switch (key)
        {
        case 1:
            cout << "1) Add to start" << endl
                << "2) Add to end" << endl
                << "3) Add to k position" << endl
                << "0) Back" << endl;
            cout << endl << "Select an action: ";
            cin >> key1;
            cout << endl;
            switch (key1)
            {
            case 1:
                GetBook(Info);
                DLList.AddFirst(Info);
                DLList.Out();
                break;
            case 2:
                GetBook(Info);
                DLList.AddLast(Info);
                DLList.Out();
                break;
            case 3:
                cout << "Enter position: ";
                do
                {
                    cin >> num;
                } while (num < 1 || num > DLList.Count + 1);
                GetBook(Info);
                if (num == 1)
                {
                    DLList.AddFirst(Info);
                    DLList.Out();
                    break;
                }
                else if (num == DLList.Count + 1)
                {
                    DLList.AddLast(Info);
                    DLList.Out();
                    break;
                }
                DLList.MoveFirst();
                for (int i = 1; i < num - 1; i++)
                {
                    DLList.MoveNext();
                }
                DLList.AddNext(Info);
                DLList.Out();
                break;
            default:
                if (key1 != 0)
                {
                    cout << "There is no such action !" << endl << endl;
                }
                break;
            }
            break;
        case 2:
            cout << "1) Delete first" << endl
                << "2) Delete last" << endl
                << "3) Delete k position" << endl
                << "0) Back" << endl;
            cout << endl << "Select an action: ";
            cin >> key2;
            cout << endl;
            switch (key2)
            {
            case 1:
                DLList.DelFirst(Info);
                DLList.Out();
                break;
            case 2:
                DLList.DelLast(Info);
                DLList.Out();
                break;
            case 3:
                cout << "Enter position: ";
                do
                {
                    cin >> num;
                } while (num < 1 || num > DLList.Count);
                if (num == 1)
                {
                    DLList.DelFirst(Info);
                    DLList.Out();
                    break;
                }
                else if (num == DLList.Count)
                {
                    DLList.DelLast(Info);
                    DLList.Out();
                    break;
                }
                DLList.MoveFirst();
                for (int i = 1; i < num; i++)
                {
                    DLList.MoveNext();
                }
                DLList.Del(Info);
                DLList.Out();
                break;
            default:
                if (key2 != 0)
                {
                    cout << "There is no such action !" << endl << endl;
                }
                break;
            }
            break;
        case 3:
            DLList.Clear();
            DLList.Out();
            break;
        case 4:
            WriteFile(DLList, Info);
            break;
        case 5:
            SortPrice(DLList);
            DLList.Out();
            break;
        case 6:
            SortName(DLList);
            DLList.Out();
            break;
        default:
            if (key != 0)
            {
                cout << "There is no such action !" << endl << endl;
            }
            DLList.Clear();
            DLList.Out();
            break;
        }
    } while (key != 0);
}

bool GetFile(DLList& DLList, BookInfo& Info)
{
    ifstream F("Books.txt");
    if (!F)
    {
        cout << "Cant find file" << endl;
        return false;
    }
    while (F >> Info.book >> Info.price >> Info.pages >> Info.rating)
    {
        DLList.AddNext(Info);
    }
    F.close();
    return true;
}

bool WriteFile(DLList& DLList, BookInfo& Info)
{
    ofstream F("Books.txt");
    if (!F)
    {
        cout << "Cant find file" << endl;
        return false;
    }
    DLList.MoveFirst();
    do
    {
        F << DLList.C->data.book << " " << DLList.C->data.pages << " " << DLList.C->data.price << " " << DLList.C->data.rating << endl;
    } while (DLList.MoveNext());
    DLList.MoveFirst();
    F.close();
    return true;
}

void GetBook(BookInfo& Info)
{
    cout << "Enter the title: ";
    cin >> Info.book;
    cout << endl;
    cout << "Enter the price: ";
    cin >> Info.price;
    cout << endl;
    cout << "Enter the amount pages: ";
    cin >> Info.pages;
    cout << endl;
    cout << "Enter the rating: ";
    cin >> Info.rating;
    cout << endl;
}

void SortPrice(DLList& List) 
{
    List.C = List.F;
    List.Temp = List.F;
    for (int i = 0; i < List.Count; i++) 
    {
        for (int j = 0; j < List.Count; j++)
        {
            if (List.C == List.Temp) continue;
            if (List.Temp->data.price > List.C->data.price)
            {
                swap(List.Temp->data, List.C->data);
            }
            if (List.Temp->next != NULL) List.Temp = List.Temp->next;

        }
        List.Temp = List.F;
        List.C = List.C->next;
    }
    List.C = List.F;
}

void SortName(DLList& List)
{
    List.C = List.F;
    List.Temp = List.F;
    for (int i = 0; i < List.Count; i++)
    {
        for (int j = 0; j < List.Count; j++)
        {
            if (List.C == List.Temp) continue;
            if (List.Temp->data.book > List.C->data.book)
            {
                swap(List.Temp->data, List.C->data);
            }
            if (List.Temp->next != NULL) List.Temp = List.Temp->next;

        }
        List.Temp = List.F;
        List.C = List.C->next;
    }
    List.C = List.F;
}