#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next; 
};
typedef struct Node* node;

//Khai báo cấu trúc danh sách liên kết đơn
struct List
{
    node head;
    node tail;
};
typedef struct List list;

//Khởi tạo cấu trúc danh sách liên kết đơn
void KhoiTaoDSL (list &l)
{
    //Cho 2 node đầu và cuối trỏ đến vùng nhớ rỗng
    l.head = NULL;
    l.tail = NULL;
}

node create_node (int x)
{
    node p = new Node;
    if (p == NULL)
    {
        cout << "Khong du bo nho de cap phat";
        return NULL;
    }
    
    p->data = x; // gán x cho data
    p->next = NULL;
    return p;
}

//thêm node p vào đầu danh sách
void add_first (list &L,node &p)
{
    //danh sách đang rỗng
    if (L.head == NULL)
    {
        L.head = L.tail = p;
    }
    else{
        p->next = L.head;   //dùng con trỏ của node p liên kết với l.head
        L.head = p;         //cập nhật lại l.head là p
    }
}

void add_last (list &L,node p)
{
    if (L.tail == NULL)
    {
        L.tail = L.head = p;
    }
    else{
        node a = L.head;
        while (a->next != NULL)
        {
            a = a->next;
        }
        a->next = p;
    }
}

void output_linked_list (list &L)
{
    for (node k = L.head; k != NULL; k = k->next)
    {
        cout << k->data << " ";
    }
}

void menu (list &L)
{
    int lua_chon;
    while (1)
    {
        system ("cls");
        cout << "\n\t\t================= MENU =================";
        cout << "\n\t1.Them node vao danh sach";
        cout << "\n\t2.Xuat danh sach lien ket don";
        cout << "\n\t0.Thoat";
        cout << "\n\t\t================= END =================";

        cout << "\nNhap lua chon: ";
        cin >> lua_chon;
        
        if (lua_chon < 0 || lua_chon > 3)
        {
            cout << "Nhung lua chon khong hop le";
            system ("pause"); //dừng màn hình
        }
        else if (lua_chon == 1)
        {
            int x;
            cout << "Nhap gia tri so nguyen: ";
            cin >> x;
            node p = create_node(x); //Khởi tạo 1 node x vừa nhập
            add_last(L,p);
        }
        else if (lua_chon == 2)
        {
            output_linked_list (L);
            system ("pause");
        }
        else
        {
            break;
        }
    }
}

int main()
{
    list L;
    KhoiTaoDSL (L); //luôn luôn gọi hàm khởi tạo DSLK đơn trước khi thao tác với danh sách
    menu(L);
    system ("pause");
}


