#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class sll
{
    Node *head;
public:
    sll()
    {
        head = NULL;
    }

    void create();
    int length();
    int sum();
    int max();
    int min();
    Node* Lsearch(int x);
    Node* Lsearch1(int x);
    void display();
    void insert(int index,int x);
    // void append(int x);
    void insertSort(int x);
    int Delete(int index);
    bool isSorted();
    void remove_duplicates();
    void reverse();
    void concat(sll *q);
    // sll *merge(sll *qq);
    void merge(sll *qq);
    bool isLoop();
};

void sll :: create()
{
    Node *p,*last;
    int n,x;
    cout << "How many node: ";
    cin >> n;
    cout << "Enter first data of first node: ";
    cin >> x;

    head = new Node;
    head->data=x;
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        p = new Node;
        cout << "Enter data of " << i+1 << " Node: ";
        cin >> x;
        p->data = x;
        p->next=NULL;
        last->next=p;
        last=p;
    }
}

int sll :: length()
{
    Node *p = head;
    int l=0;
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}

int sll :: sum()
{
    Node *p = head;
    int sum{};
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int sll :: max()
{
    Node *p = head;
    int max=INT32_MIN;

    while(p)
    {
        if(p->data>max)
            max = p->data;
        p=p->next;
    }
    return max;
}

int sll :: min()
{
    Node *p = head;
    int min=INT32_MAX;

    while(p)
    {
        if(p->data<min)
            min = p->data;
        p=p->next;
    }
    return min;
}

Node* sll :: Lsearch(int x)
{
    Node *p = head;
    while(p!=NULL)
    {
        if(x==p->data)
            return p;
        p=p->next;
    }
    return 0;
}

Node* sll :: Lsearch1(int x)
{
    Node *p = head;
    Node *q=nullptr;
    while(p!=NULL)
    {
        if(x==p->data)
        {
            q->next=p->next;
            p->next=head;
            head = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return 0;    
}

void sll :: display()
{
    Node *p = head;
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
    delete p;
}

void sll :: insert(int index,int x)
{
    Node *p = head;
    Node *t;
    if(index < 0 || index > length())
        return;
    t = new Node;
    t->data = x;    
    
    if(index==0)
    {
        t->next=head;
        head=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;

        t->next=p->next;
        p->next=t;
    }
}

void sll :: insertSort(int x)
{
    Node *p = head;
    Node *t,*q=nullptr;

    t=new struct Node;
    t->data=x;
    t->next=nullptr;

    if(head==NULL)
        head=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==head)
        {
            t->next=head;
        head=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

// void sll :: append(int x)
// {
//     Node *t = new Node;
//     Node *last = NULL;
//     t->data = x;
//     t->next=NULL;
//     if(head == NULL)
//     {
//         head=t;
//         last=t;
//     }
//     else
//     {
//         last->next = t;
//         last = t;
//     }
// }

int sll :: Delete(int index)
{
    Node *p=head;
    Node *q=NULL;
    int x = -1,i;

    if(index < 1 || index > length())
        return -1;

    if(index == 1)
    {
        p=head;
        x=head->data;
        head=head->next;
        delete p;
        return x;
    }
    else
    {
        p = head;q = NULL;
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        if(p!=NULL)
        {
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
    return x;
}

bool sll :: isSorted()
{
    int x = INT32_MIN;
    Node *p = head;
    while(p!=NULL)
    {
        if(p->data<x)
            return false;
        
        x=p->data;
        p=p->next;
    }
    return true;
}

void sll :: remove_duplicates()
{
    Node *p = head;
    Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

void sll :: reverse()
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    head = q;
}

void sll :: concat(sll *q)
{
    Node *third=head;

    while(third->next!=NULL)
        third=third->next;
    third->next=q->head;
}

void sll :: merge(sll *qq)
{
    Node *last;
    Node *third;
    Node *q = qq->head;
    if(head->data<q->data)
    {
        third=last=head;
        head=head->next;
        last->next = NULL;
    }
    else
    {
        third=last=qq->head;
        qq->head=qq->head->next;
        last->next = NULL;
    }
    while (head!=NULL && qq->head!=NULL)
    {
        if(head->data<qq->head->data)
        {
            last->next=head;
            last=head;
            head=head->next;
            last->next=NULL;
        }
        else
        {
            last->next=qq->head;
            last=qq->head;
            qq->head=qq->head->next;
            last->next=NULL;
        }
    }
    if(head)
        last->next=head;
    else
        last->next=qq->head;
    
    head = third;
    
}
int main()
{
    // sll *ll = new sll;
    // sll *ll1 = new sll;
    // int x{};
    // for(int i{0};i<10;i++)
    // {
    //     ll->insert(i,1);
    // }

    // for(int i{0};i<10;i++)
    // {
    //     ll1->insert(i,2);
    // }

    // ll->display();
    // ll1->display();
    // ll->concat(ll1);
    // ll->display();
    // // ll->remove_duplicates();
    // ll->reverse();
    // ll1->display();
    
    // ll->merge(ll1);
    sll *ll = new sll;
    ll->create();
    ll->display();
    

    // (ll->merge(ll1))->display();
    return 0;
}
