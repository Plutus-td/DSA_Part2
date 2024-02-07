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
void add_first (list &L,node p)
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

int size (list &L)
{
    node head = L.head;
    int count;
    while (head != NULL)
    {
        ++count;
        head = head->next;
    }
    return count; 
}

void add_any_position (list &L,int k,node p)
{
   int n = size(L);
   if (k < 1 || k > n + 1)
   {
    cout << "Vi tri nhap khong hop le !";
    return;
   }
   if (k == 1)
   {
    add_first(L,p);
   }
   node temp  = L.head;
   for (int i = 1; i <= k - 2; i++ )
   {
      temp = temp->next;
   }
   // node temp đang ở vị trí thứ k - 1
   //temp->next đang trỏ tới vị trí thứ k 
   p->next = temp->next;
   temp->next = p;
}

void delete_first (list &L)
{
    if (L.head == NULL)
    {
        return;
    }

    node p = L.head;
    L.head = L.head->next;
    delete p;
}

void delete_last (list &L)
{
    if (L.head == NULL)
    {
        return;
    }
    
    if (L.head->next == NULL)
    {
        delete_first(L);
        return;
    }

    for (node k = L.head; k != NULL; k = k->next)
    {
        if (k->next == L.tail)
        {
            delete L.tail;  //xóa đi phần tử cuối
            k->next = NULL; //cho con trỏ node kế cuối trỏ đến vùng nhớ NULL
            L.tail = k;
			return;     //cập nhật lại tail
        }
    }
}

void delete_any_position (list &L,int k)
{
   int n = size(L);
   
   if (k < 1 || k > n)
   {
        cout << "Vi tri xoa khong hop le !";
        return;
   }

   if (k == 1)
   {
        delete_first(L);
        return;
   }
   node temp = L.head;
   for (int i = 1; i <= k - 2; i++)
   {
        temp = temp->next;
   }
   //temp ở vị trí thứ k - 1

   node vi_tri_k = temp->next; //node thứ k
   temp->next = vi_tri_k->next; //cho k - 1 => kết nối với node k + 1 
   delete vi_tri_k;
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
        cout << "\t\t================== MENU ==================\n";
        cout << "\t\t1.Them node vao danh sach\n";
        cout << "\t\t2.Them node vao dau danh sach\n";
        cout << "\t\t3.Them node vao cuoi danh sach\n";
        cout << "\t\t4.Them node vao vi tri bat ki\n";
        cout << "\t\t5.Xoa node dau danh sach\n";
        cout << "\t\t6.Xoa node cuoi danh sach\n";
        cout << "\t\t7.Xoa node o vi tri bat ki\n";
        cout << "\t\t8.Xuat danh sach lien ket don\n";
        cout << "\t\t0.Thoat\n";
        cout << "\t\t================== END ==================";

        cout << "\nNhap lua chon: ";
        cin >> lua_chon;
        
        if (lua_chon < 0 || lua_chon > 9)
        {
            cout << "Lua chon khong hop le";
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
            int x;
            cout << "Nhap gia tri them vao dau: ";
            cin >> x;
            node p = create_node(x); 
            add_first(L,p);
        }
        else if (lua_chon == 3)
        {
            int x;
            cout << "Nhap gia tri them vao cuoi: ";
            cin >> x;
            node p = create_node(x); 
            add_last(L,p);
        }
        else if (lua_chon == 4)
        {
            int x,k;
            cout << "Nhap vi tri muon them: ";
            cin >> k;
            cout << "Nhap gia tri muon them vao vi tri thu " << k << ": ";
            cin >> x;
            node p = create_node(x); 
            add_any_position(L,k,p);
        }
        else if (lua_chon == 5)
        {
            delete_first(L);            
        }
        else if (lua_chon == 6)
        {
            delete_last(L);
        }
        else if (lua_chon == 7)
        {
            int k;
            cout << "Nhap vi tri muon xoa ";
            cin >> k;
            delete_any_position(L,k);
        }
        else if (lua_chon == 8)
        {
            output_linked_list(L);
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
    return 0;
}


