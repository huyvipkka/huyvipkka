- 👋 Hi, I’m @huyvipkka
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...

<!---
huyvipkka/huyvipkka is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
---> // linked list and oop
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Student {
    private:
        string name;
        int age;
    public:
        Student(string name, int age){
            this->name = name;
            this->age = age;
        }
        Student(){
            string a[10]{"Huy", "Phuong", "Han", "Hien", "Lam", "Thao", "Nguyen", "Nhi", "Trang", "Quan"};
            name = a[rand() % 10];
            age = rand() % 40 + 10;
        }
        string getName() { return name; }
        int getAge() { return age; }
        void setName(string name) { this->name = name;}
        void setAge(int age) { this->age = age;}
        void Nhap (){
            cin.ignore();
            cout << "Nhap ten : "; getline(cin, name);
            cout << "Nhap tuoi : "; cin >> age;
        }
};

struct Node {
    Student data;
    Node* next;
};

Node* makeList(Student a){
    Node* tmp = new Node;
    tmp->data = a;
    tmp->next = NULL;
    return tmp;
}

Node* getNodeIndex (Node* head, int index){
    Node* tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp;
}

int Len (Node* a){
    int count = 0;
    while (a != NULL)
    {
        count++;
        a = a->next;
    }
    return count;
}

void SwapStuden (Student &a, Student &b){
    Student tmp = a;
    a = b;
    b = tmp;
}

void Append(Node* &head, Student a){
    if (head == NULL)
        head = makeList(a);
    else
    {
        Node* p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = makeList(a);
    }
}

void SuaSVthu (Node* head, int stt){
    for (int i = 1; i < stt; i++)
        head = head->next;
    Student sua;
    sua.Nhap();
    head->data = sua;
}

void ChenSvthu (Node* &head, int stt){
    Node* tmp = head;
    Student a;
    a.Nhap();
    Node* Ins = makeList(a);
    if (stt = 1){
        Ins->next = head;
        head = Ins;
    }
    else{
        for (int i = 1; i < stt - 1; i++)
            tmp = tmp->next;
        Node* tmp_next = tmp->next;
        tmp->next = Ins;
        Ins->next = tmp_next;
    }
}

void XoaSvthu (Node* &head, int stt){
    if (Len(head) == 1){
        head = NULL;
    }
    else if (stt == 1){
        head = head->next;
    }
    else
    {
        Node* truoc = NULL, *sau = head;
        for (int i = 1; i < stt; i++)
        {
            truoc = sau;
            sau = sau->next;
        }
        truoc->next = sau->next;
    }
}

void BubbleSort (Node* &head )
{
    Node* tmp = head;
    Node* tmp2 = NULL;
    while (tmp->next != NULL)
    {
        tmp2 = tmp->next;
        while (tmp2 != NULL){
            if (tmp->data.getAge() > tmp2->data.getAge())
                SwapStuden(tmp->data, tmp2->data);
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}

void InsertionSort (Node* &head, int l, int h){
    Node* tmp = head;
    for (int i = l + 1; i < h; i++){
        Student x = getNodeIndex(tmp, i)->data;
        int pos = i - 1;
        while(pos >= 0 && x.getAge() < getNodeIndex(tmp, pos)->data.getAge()){
            getNodeIndex(tmp, pos + 1)->data = getNodeIndex(tmp, pos)->data;
            --pos;
        }
        getNodeIndex(tmp, pos + 1)->data = x;
    }   
}

void merge (Node* head, int l, int m, int h){
    Node* tmp = head;
    int k = l, i, j;
    int n1 = m - l + 1, n2 = h - m;
    Student L[n1], H[n2];

    for (i = 0; i < n1; i++)
        L[i] = getNodeIndex(tmp, i + l)->data;
    for (j = 0; j < n2; j++)
        H[j] = getNodeIndex(tmp, m + j + 1)->data;
    i = 0, j = 0;
    while (i < n1 && j < n2)
            getNodeIndex(tmp, k++)->data = (L[i].getAge() < H[j].getAge()) ? L[i++] : H[j++];
    while (i < n1)
        getNodeIndex(tmp, k++)->data = L[i++];
    while (j < n2)
        getNodeIndex(tmp, k++)->data = H[j++];
}
void MergeSort (Node* head, int l, int h){
    if (l < h){
        Node*tmp = head;
        int m = (l+h)/2;
        MergeSort (tmp, l, m);
        MergeSort (tmp, m+1, h);
        merge (tmp, l, m, h);
    }
}

void TimSort (Node* &head, int n){
    int RUN = 16;
    for (int i = 0; i < n; i += RUN)
        InsertionSort(head, 0, min(i + RUN, n));
    for(int size = RUN; size < n; size *= 2)
    {
        for(int l = 0; l < n; l += 2*size)
        {
            int m = l + size - 1;
            int h = min((l + 2*size - 1), (n-1));
            if (m < h)
                merge(head, l, m, h);
        }
    }
}

void Print (Node* head)
{
    if (Len(head) == 0){
        cout<<"Deo co ds nao ca"<< endl;
        cin.ignore();
    }
    else{
        Node* p = head;
        cout<<"________________________________________________" << endl;
        cout<<"| Stt\t|\tTen\t\t|\tTuoi\t|" << endl;
        int i = 1;
        while (p != NULL)
        {
            cout << "| " << i << "\t| ";
            cout << p->data.getName()<< "   \t\t| " << p->data.getAge() << "     \t|" << endl;
            p = p->next;
            i++;
        }
        cout<<"------------------------------------------------" << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    Node* head = NULL;
    int n;
    bool run = true;
    while(run)
    {
        cout<<"\n\t\t  MENU"<<endl;
        cout<<"|1.Random 1 list sv \t\t";
        cout<<"|2.Them sv"<< endl;
        cout<<"|3.Sua sv\t\t\t";
        cout<<"|4.Chen sv"<<endl;
        cout<<"|5.Xoa sv\t\t\t";
        cout<<"|6.Age Bubble sort"<<endl;
        cout<<"|7.Age Merge sort\t\t";
        cout<<"|8.Age Insertion sort"<<endl;
        cout<<"|9.Age Tim sort\t\t\t";
        cout<<"|..Nhap sai de out"<<endl;
        string lc = "";
        do{
            cout<<"Lua chon : ";
            getline(cin, lc);
        }while(lc == "");
        if (lc == "1"){
            do{
            cout<<"Nhap so luong sv : ";
            cin>>n;
            }while(n < 1);
            Student sv[n];
            head = NULL;
            for(int i = 0; i < n; i++)
                Append(head, sv[i]);
            Print(head);
            cin.ignore();
        }
        else if (lc == "2"){
            int sl;
            cout<<"Nhap so luong sv : ";
            cin>>sl;
            Student add[sl];
            for (int i = 0; i < sl; i++)
            {
                cout<<"Sinh vien " << 1 + Len(head) << endl;
                add[i].Nhap();
                Append(head, add[i]);
            }
            Print(head);
            cin.ignore();
        }
        else if (lc == "3"){
            int stt_sua;
            do{
                cout<<"Nhap stt sv muon sua : ";
                cin >> stt_sua;
                if (stt_sua < 1 || stt_sua > Len(head))
                    cout << 1 << "<= stt <=" << Len(head) << endl;
            }while (stt_sua < 1 || stt_sua > Len(head));
            SuaSVthu(head, stt_sua);
            Print(head);
            cin.ignore();
        }
        else if (lc == "4"){
            int stt_chen;
            do{
                cout<<"Nhap stt sv muon chen : ";
                cin >> stt_chen;
                if (stt_chen < 1 || stt_chen > Len(head))
                    cout << 1 << "<= stt <=" << Len(head) << endl;
            }while(stt_chen < 1 || stt_chen > Len(head));
            ChenSvthu(head, stt_chen);
            Print(head);
            cin.ignore();
        }
        else if (lc == "5"){
            int stt_xoa;
            do{
                cout<<"Nhap stt sv can xoa: ";
                cin >> stt_xoa;
                if (stt_xoa < 1 || stt_xoa > Len(head))
                    cout << 1 << "<= stt <=" << Len(head) << endl;
            }while(stt_xoa < 1 || stt_xoa > Len(head));
            XoaSvthu(head, stt_xoa);
            Print(head);
            cin.ignore();
        }
        else if (lc == "6"){
            BubbleSort(head);
            Print(head);
        }
        else if (lc == "7"){
            MergeSort(head, 0, Len(head) - 1);
            Print(head);
        }
        else if (lc == "8"){
            InsertionSort(head,0,  Len(head) - 1);
            Print(head);
        }
        else if (lc == "9"){
            TimSort(head, Len(head));
            Print(head);
        }
        else
            run = false;
    }
    return 0;
}
