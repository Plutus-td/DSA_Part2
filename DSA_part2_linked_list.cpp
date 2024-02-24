#include<iostream>
#include <cstring>
using namespace std;

struct SinhVien{
    string name;
    int age;
    string lop;
};
typedef struct SinhVien sinhvien;

struct Node{
    sinhvien data;
    Node *next;
};
typedef struct Node* node;

//Khai báo cấu trúc DSLK
struct List{
    node head;
    node tail;
};
typedef struct List list;

void KhoTaoDSLK (list &L)
{
    L.head = NULL;
    L.tail = NULL;
}

node create_node (sinhvien x)
{
    node p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

sinhvien input_1_sv (sinhvien &sv)
{
    fflush(stdin);
    cout << "\nNhap ho ten: ";
    getline (cin,sv.name);

    cout << "Nhap tuoi: ";
    cin >> sv.age;

    fflush(stdin);
    cout << "Nhap lop hoc: ";
    cin >> sv.lop;

    return sv;
}

void output_1_sv (sinhvien sv)
{
    cout << "\nName: " << sv.name;
    cout << "\nAge: " << sv.age;
    cout << "\nClass: " << sv.lop;
    cout << "\n============================\n";
}

void add_first (list &L,node p)
{
    if (L.head == NULL)
    {
        L.head = L.tail = p;
    }
    else{
        p->next = L.head;
        L.head = p;
    }
}

void add_last (list &L,node p)
{
    if (L.tail == NULL)
    {
        L.head = L.tail = p;
    }
    else{
       L.tail->next = p;
       L.tail = p;
    }
}

void search (list &L)
{
    string ten_sv;
    fflush(stdin);
    cout << "Nhap ten sinh vien can tim thong tin:";
    getline (cin,ten_sv);

    for (node k = L.head; k != NULL; k = k->next)
    {
        if (k->data.name == ten_sv)
        {
            output_1_sv (k->data);
        }
    }
}

void oldlest_student (list &L)
{
    sinhvien max;
    max = L.head->data;
    max.age = L.head->data.age;
    
    for (node k = L.head; k != NULL; k = k->next)
    {
        if (k->data.age > max.age)
        max = k->data;
    }

    output_1_sv(max);
}

void youngest_student (list &L)
{
    sinhvien min;
    min = L.head->data;
    min.age = L.head->data.age;
    
    for (node k = L.head; k != NULL; k = k->next)
    {
        if (k->data.age < min.age)
        min = k->data;
    }

    output_1_sv(min);
}


int size (list &L)
{
    node p = L.head;
    int count;
    
    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

void swap (sinhvien &a,sinhvien &b)
{
    sinhvien tmp = a;
    a = b;
    b = tmp;
}

void output_linkedlist (list &L)
{
    for (node k = L.head; k != NULL; k= k->next)
    {
        output_1_sv(k->data);
    }
}


void change_place (list &L)
{
    int position_1,position_2;
    cout << "\nCHON 2 VI TRI HOAN DOI\n";
    
    cout << "Vi tri 1: ";
    cin >> position_1;
    
    cout << "\nVi tri 2: ";
    cin >> position_2;

    
    int i = 0;

    for (node k = L.head; k != NULL; k = k->next)
    {
        int j = i + 1;
        for (node p = L.head->next; p != NULL; p = p->next)
        {
            if (i == position_1 && j == position_2)
            {
                swap (k->data,p->data);
            }
            j++;
        }
        j = 0;
        i++;
    }

    output_linkedlist(L);
    system ("pause");
}


void Menu (list &L)
{
    int lua_chon;
    while (1)
    {
        system ("cls");
        cout << "\t\t=================== MENU ===================";
        cout << "\n\t\t1.Them thong tin sinh vien";
        cout << "\n\t\t2.Xuat thong tin sinh vien";
        cout << "\n\t\t3.In thong tin sinh vien dau tien";
        cout << "\n\t\t4.In thong tin sinh vien cuoi cung";
        cout << "\n\t\t5.Tim thong tin sinh vien thong qua ten";
        cout << "\n\t\t6.In thong tin sinh vien nhieu tuoi nhat";
        cout << "\n\t\t7.In thong tin sinh vien it tuoi nhat";
        cout << "\n\t\t8.Doi cho sinh vien theo yeu cau";
        cout << "\n\t\t0.Thoat";
        cout << "\n\t\t=================== END ===================";

        do{
            cout << "\nNhap lua chon: ";
            cin >> lua_chon;
            if (lua_chon < 0 || lua_chon > 8)
            {
                cout << "Lua chon khong hop le. Moi nhap lai!";
            }
        }while(lua_chon < 0 || lua_chon > 8);

        if (lua_chon == 1)
        {
             cout << "\n\tNHAP DANH SACH THONG TIN SINH VIEN\n";
            sinhvien x;
            node p = create_node(input_1_sv(x));
            add_last (L,p);
        }
        else if (lua_chon == 2)
        {
            cout << "\n\tXUAT DANH SACH THONG TIN SINH VIEN\n";
            output_linkedlist(L);
            system ("pause");
        }
        else if (lua_chon == 3)
        {
            cout << "\n\tTHONG TIN SINH VIEN DAU TIEN\n";
            output_1_sv(L.head->data);
            system ("pause");
        }
         else if (lua_chon == 4)
        {
            cout << "\n\tTHONG TIN SINH VIEN CUOI CUNG\n";
            output_1_sv(L.tail->data);
            system ("pause");
        }
        else if (lua_chon == 5)
        {
            cout << "\n\tTIM THONG TIN SINH VIEN THONG QUA TEN\n";
            search (L);
            system ("pause");
        }
        else if (lua_chon == 6)
        {
            cout << "\n\tTHONG TIN SINH VIEN NHIEU TUOI NHAT\n";
            oldlest_student(L);
            system ("pause");
        }
        else if (lua_chon == 7)
        {
            cout << "\n\tTHONG TIN SINH VIEN IT TUOI NHAT\n";
            youngest_student(L);
            system ("pause");
        }
        else if (lua_chon == 8)
        {
            cout << "\n\tDOI CHO SINH VIEN THEO YEU CAU\n";
            change_place(L);   
        }
        else
        {
            break;
        }
    }
}

int main (){
    list L;
    KhoTaoDSLK(L);
    Menu(L);
    system ("pause");
    return 0;
}



