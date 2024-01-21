#include <iostream>
#include <cstring>

using namespace std;

struct SinhVien{
    string name;
    int age;
    string lop;
};

typedef struct SinhVien sinhvien;

void nhap_1_sv (sinhvien &sv);
void xuat_1_sv (sinhvien sv);
void nhap (sinhvien a[],int &n);
void xuat (sinhvien a[],int n);
void tim_kiem (sinhvien a[],int n);
void sv_max_age (sinhvien a[],int n);
void sv_min_age (sinhvien a[],int n);
void sap_xep (sinhvien a[],int n);

void nhap_1_sv (sinhvien &sv)
{
    //nhap ten
    fflush (stdin);
    cout << "Nhap ten sinh vien: ";
    getline (cin,sv.name);

    //nhap tuoi
    cout << "Nhap tuoi sinh vien: ";
    cin >> sv.age;

    //nhap lop
    fflush (stdin);
    cout << "Nhap lop: ";
    cin >> sv.lop;
}

void xuat_1_sv (sinhvien sv)
{
    cout << sv.name;
    cout << "\t" << sv.age;
    cout << "\t" << sv.lop << "\n";
}

 void nhap (sinhvien a[],int &n)
{
    cout << "\tNHAP MANG SINH VIEN\n";
    cout << "Nhap so luong sinh vien:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        nhap_1_sv(a[i]);
    }
}

void xuat (sinhvien a[],int n)
{
    cout << "\tXUAT MANG SINH VIEN\n";
    cout << "Name" << "\t\tAge" << "\tClass\n";
    for (int i = 0; i < n; i++)
    {
        xuat_1_sv(a[i]);
    }
}

void tim_kiem (sinhvien a[],int n)
{
    cout << "\tTIM THONG TIN SINH VIEN THONG QUA TEN\n";
    string  ten_sv;
    fflush (stdin);
    cout << "Nhap ten sinh vien de tim thong tin: ";
    getline (cin,ten_sv);
    for (int i = 0; i < n; i++)
    {
        if (ten_sv == a[i].name)
        xuat_1_sv(a[i]);
    }
}

void sv_max_age (sinhvien a[],int n)
{
    sinhvien max = a[0];
    cout << "\tTHONG TIN SINH VIEN LON TUOI NHAT\n";
    for (int i = 0; i < n; i++)
    {
        if (a[i].age > max.age)
        xuat_1_sv (a[i]);
    }
}

void sv_min_age (sinhvien a[],int n)
{
    sinhvien min = a[0];
    cout << "\tTHONG TIN SINH VIEN NHO TUOI NHAT\n";
    for (int i = 0; i < n; i++)
    {
        if (a[i].age < min.age)
        {
            
            xuat_1_sv(a[i]);
        }
    }
}

void sap_xep (sinhvien a[],int n)
{
    cout << "\tMANG SAU KHI DOI CHO SINH VIEN\n";
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ( i == 0 && j == 3)
            {
                sinhvien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Name" << "\t\tAge" << "\tClass\n";
    for (int i = 0; i < n; i++)
    {
        xuat_1_sv(a[i]);
    }
    
}


int main ()
{
    sinhvien a[100];
    int n;
    nhap (a,n);
    xuat (a,n);
    tim_kiem(a,n);
    sv_max_age (a,n);
    sv_min_age (a,n);
    sap_xep (a,n);
    return 0;
}


