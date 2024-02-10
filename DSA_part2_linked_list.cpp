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
    cout << "Nhap ho ten: ";
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
    cout << "Name: " << sv.name;
    cout << "\nAge: " << sv.age;
    cout << "\nClass: " << sv.lop;
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
            sinhvien x;
            input_1_sv (x);
            node p = create_node(input_1_sv(x));
        }

    }
}

int main (){
    list L;
    KhoTaoDSLK(L);
    Menu(L);
    system ("pause");
}



