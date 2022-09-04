#include "nhanvien.h"

using namespace std;

class NhanVienMenu{
public:
    QuanLyNhanVien qlnv;

    NhanVienMenu(){}

    int showMenu(int index = 0){
        int opt = 0;
        int options[] = {1,5,10};

        switch (index){
            case 0:
                cout 
                    << "===Quan Ly Nhan Vien===\n"
                    << "Hien tai dang co " << qlnv.nhanVien.size() << " nhan vien\n"
                    << "1. Xem danh sach nhan vien\n"
                    << "0. Quay lai\n"
                    << "Lua chon: ";
                break;
            
            case 1:
                cout
                    << qlnv << endl
                    << "1. Them nhan vien\n"
                    << "2. Xoa Nhan vien\n"
                    << "3. Sua thong tin nhan vien\n"
                    << "4. Sap xep nhan vien\n"
                    << "5. Luu thong tin vao co so du lieu\n"
                    << "0. Quay lai\n"
                    << "Lua chon: ";
                break;

            case 2:
                cout
                    << "===Sap xep nhan vien===\n"
                    << "Sap xep TANG dan:\n"
                    << "1. Sap xep theo id\n"
                    << "2. Sap xep theo ho ten\n"
                    << "3. Sap xep theo cong viec\n"
                    << "4. Sap xep theo nam sinh\n"
                    << "5. Sap xep theo he so luong\n\n"

                    << "Sap xep GIAM dan:\n"
                    << "6. Sap xep theo id\n"
                    << "7. Sap xep theo ho ten\n"
                    << "8. Sap xep theo cong viec\n"
                    << "9. Sap xep theo nam sinh\n"
                    << "10. Sap xep theo he so luong\n\n"

                    << "0. Quay lai\n"
                    << "Lua chon: ";
                break;
        }
        
        cin >> opt;
        while(opt < 0 || opt > options[index]){
            cout << "Lua chon khong hop le, vui long nhap lai: ";
            cin >> opt;
        }

        return opt;
    }

    void run(){
        int option = 0;
        int menuIndex = 0;
        do{
            option = showMenu(menuIndex);
            cout << endl;
            if(option == 0){
                if(menuIndex <= 0) 
                    break;
                else{
                    menuIndex--;
                    continue;
                }
            }

            switch(menuIndex){
                case 0:
                    menuIndex++;
                    continue;
                    break;
                
                case 1:
                    switch(option){
                        case 1:
                            themNhanVien();
                            break;
                        case 2:
                            xoaNhanVien();
                            break;
                        case 3:
                            chinhSua();
                            break;
                        case 4:
                            menuIndex++;
                            continue;
                            break;
                        case 5:
                            save();
                            break;
                        }
                    break;

                case 2:
                    sapxep(option);
                    menuIndex--;
                    break;
            }

        }while(true);
    }

    NhanVien nhapNhanVien(){
        NhanVien nv;
        cout << "===Nhap thong tin nhan vien moi===\n";
        do{
            cout << "Nhap id: ";
            cin >> nv.id;
            cout << "Nhap Ho va Ten: ";
            cin.ignore();
            getline(cin, nv.hoTen);
            cout << "Nhap Cong viec: ";
            getline(cin, nv.congViec);
            cout << "Nhap nam sinh: ";
            cin >> nv.namSinh;
            cout << "Nhap he so luong: ";
            cin >> nv.hsLuong;

            cout 
                << "\n===Thong tin nhan vien moi===\n"
                << nv
                << "Xac nhan thong tin? (y/n): ";
            char confirm;
            cin >> confirm;
            cout << endl;
            if(confirm == 'y')
                break;
            cout << "===Nhap lai thong tin===\n";
        }while(true);
        
        return nv;
    }

    void themNhanVien(){
        bool unique = true;
        NhanVien nv;
        do{
            nv = nhapNhanVien();
            unique = true;
            for(NhanVien i: qlnv.nhanVien){
                if(i.id == nv.id){
                    unique = false;
                    break;
                }
            }

            if(unique) break;

            cout << "ID da ton tai, vui long nhap lai!" << endl;
        }while (true);
        
        qlnv.themNhanVien(nv);
    }

    void xoaNhanVien(){
        do{
            cout 
                << "===Xoa nhan vien===\n"
                << "-1. Xoa tat ca\n"
                << "0. Quay lai\n"
                << "Nhap stt cua nhan vien can xoa: ";
            int stt;
            cin >> stt;
            cout << endl;

            if(stt > qlnv.nhanVien.size() || stt < -1){
                cout << "stt khong hop le, vui long nhap lai!" << endl;
            }else if(stt == -1){
                cout << "Xac nhan xoa tat ca? (y/n): ";
                char confirm;
                cin >> confirm;
                cout << endl;
                if(confirm == 'y'){
                    qlnv.rmrf();
                    break;
                }
            }else if(stt == 0){
                break;
            }else{
                cout << "Nhan vien stt " << stt << endl
                     << qlnv.nhanVien[stt-1]
                     << "Xac nhan xoa? (y/n): ";
                char confirm;
                cin >> confirm;
                cout << endl;
                if(confirm == 'y'){
                    qlnv.xoaNhanVien(stt-1);
                    cout << qlnv << endl;
                }
            }
        }while (true);
    }

    void chinhSua(){
        cout 
            << "===Sua thong tin nhan vien===\n"
            << "0. Quay lai\n"
            << "nhap stt cua nhan vien can chinh sua: ";
        int stt;
        cin >> stt;
        while(stt < 0 || stt > qlnv.nhanVien.size()){
            cout << "stt khong hop le, vui long nhap lai: ";
            cin >> stt;
        }
        
        NhanVien nv = qlnv.nhanVien[stt-1];
        while(true){
            cout 
                << "Nhan vien stt " << stt << endl
                << nv << endl
                << "1. Sua id\n"
                << "2. Sua Ho va Ten\n"
                << "3. Sua cong viec\n"
                << "4. Sua nam sinh\n"
                << "5. Sua he so luong\n"
                << "0. Luu va thoat\n"
                << "-1. Khong luu va thoat\n"
                << "Lua chon: ";
            int opt;
            cin >> opt;
            
            while(opt < -1 || opt > 5){
                cout << "Lua chon khong hop le, vui long nhap lai: ";
                cin >> opt;
            } 
            if(opt == -1){
                break;
            }else if(opt == 0){
                qlnv.nhanVien[stt-1] = nv;
                break;
            }

            switch(opt){
                case 1:
                    cout << "Nhap Id moi: ";
                    cin >> nv.id;
                    break;
                case 2:
                    cout << "Nhap Ho Ten moi: ";
                    cin.ignore();
                    getline(cin, nv.hoTen);
                    break;
                case 3:
                    cout << "Nhap Cong viec moi: ";
                    cin.ignore();
                    getline(cin, nv.congViec);
                    break;
                case 4:
                    cout << "Nhap Nam sinh moi: ";
                    cin >> nv.namSinh;
                    break;
                case 5:
                    cout << "Nhap He so luong moi: ";
                    cin >> nv.hsLuong;
                    break;
            }
        }
        
    }

    void sapxep(int opt){
        qlnv.sapxep("lihcn"[opt%5], opt<=5);
        cout << qlnv << endl;
    }

    void save(){
        cout << "Xac nhan luu thong tin vao CSDL? (y/n): ";
        char confirm;
        cin >> confirm;

        if(confirm == 'y'){
            qlnv.writeData();
            cout << "Da luu thong tin\n";
        }else{
            cout << "Huy bo luu thong tin\n";
        }
        cout << endl;
    }
};
