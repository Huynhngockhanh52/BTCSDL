#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::max;

class NhanVien{
public:

    int id;
    string hoTen;
    string congViec;
    int namSinh;
    float hsLuong;
    static char sortBy;
    static bool acs;

    NhanVien(){
        id = 0;
        hoTen = "";
        congViec = "";
        namSinh = 0;
        hsLuong = 0;
    }

    NhanVien(int _id, string _hoTen, string _congViec, int _namSinh, float _hsLuong){
        id = _id;
        hoTen = _hoTen;
        congViec = _congViec;
        namSinh = _namSinh;
        hsLuong = _hsLuong;
    }

    static void setComp(char by = 'i', bool a = true){
        sortBy = by;
        acs = a;
    }

    static bool comp(const NhanVien& a, const NhanVien& b){
        bool c = false;
        switch(sortBy){
            case 'i':
                c = a.id < b.id;
                break;
            case 'h':
                c = a.hoTen < b.hoTen;
                break;
            case 'c':
                c = a.congViec < b.congViec;
                break;
            case 'n':
                c = a.namSinh < b.namSinh;
                break;
            case 'l':
                c = a.hsLuong < b.hsLuong;
                break;                
        }

        /*
        a: sort by acensing
        c: less than compare
            a c result
            1 1   1
            1 0   0
            0 1   0
            0 0   1
            => use nxor
        */
        return !(NhanVien::acs ^ c);
    }

    bool operator<(const NhanVien& other){
        return id < other.id;
    }

    friend ostream& operator<<(ostream& os, NhanVien& nv){
        os << "Id: " << nv.id << endl;
        os << "Ho va Ten: " << nv.hoTen << endl;
        os << "Cong viec: " << nv.congViec << endl;
        os << "Nam sinh: " << nv.namSinh << endl;
        os << "He so luong: " << nv.hsLuong << endl;
        return os;
    }

};

bool NhanVien::acs = true;
char NhanVien::sortBy = 'i';

class QuanLyNhanVien{
public:
    vector<NhanVien> nhanVien;
    string dataPath;

    QuanLyNhanVien(string path = ".\\data\\nhanvien.txt"){
        dataPath = path;
        std::ifstream data(dataPath);
        if(data.is_open()){
            int cnt = 0;
            data >> cnt;
            while (cnt--){
                NhanVien nv;
                data >> nv.id;
                data.ignore();
                std::getline(data, nv.hoTen);
                std::getline(data, nv.congViec);
                data >> nv.namSinh;
                data >> nv.hsLuong;
                nhanVien.push_back(nv);
            }
        }
        data.close();
        NhanVien::setComp();
    }

    void themNhanVien(NhanVien nv){
        nhanVien.push_back(nv);
    }

    void xoaNhanVien(int index){
        nhanVien.erase(nhanVien.begin() + index);
    }

    void suaNhanVien(int stt, NhanVien nv){
        nhanVien[stt-1] = nv;
    }

    void writeData(){
        std::sort(nhanVien.begin(), nhanVien.end());
        std::ofstream data(dataPath);
        data << nhanVien.size() << endl;

        for(NhanVien nv: nhanVien){
            data << nv.id << endl;
            data << nv.hoTen << endl;
            data << nv.congViec << endl;
            data << nv.namSinh << endl;
            data << nv.hsLuong << endl;
        }
        data.close();
    }

    void rmrf(){
        std::ofstream data(dataPath);
        nhanVien.erase(nhanVien.begin(), nhanVien.end());
        data << 0;
        data.close();
    }

    void sapxep(char by = 'i', bool a = true){
        NhanVien::setComp(by, a);
        std::sort(nhanVien.begin(), nhanVien.end(), NhanVien::comp);
    }

    friend ostream& operator<<(ostream& os, const QuanLyNhanVien& qlnv){
        if(qlnv.nhanVien.size() == 0){
            os << "Hien tai khong co nhan vien\n";
            return os;
        }
        // size of header filed
        int widths[] = {3,2,9,9,8,8};
        widths[0] = max(widths[0],(int) log10(qlnv.nhanVien.size()) + 1);
        
        for(NhanVien nv: qlnv.nhanVien){
            widths[1] = max(widths[1], nv.id);
            widths[2] = max(widths[2],(int) nv.hoTen.size());
            widths[3] = max(widths[3],(int) nv.congViec.size());
            widths[4] = max(widths[4], nv.namSinh);
            widths[5] = max(widths[5],(int) nv.hsLuong);
        }
        widths[1] = max(2,(int) log10(widths[1]) + 1);
        widths[4] = max(8,(int) log10(widths[4]) + 1);
        widths[5] = max(8,(int) log10(widths[5]) + 3);
        int sum = 0;
        for(int i: widths){
            sum += i;
        }
        sum += 5;

        os << setw(widths[0]) << left << "STT";
        os << "|";
        os << setw(widths[1]) << left << "ID";
        os << "|";
        os << setw(widths[2]) << left << "Ho va Ten";
        os << "|";
        os << setw(widths[3]) << left << "Cong Viec";
        os << "|";
        os << setw(widths[4]) << left << "Nam Sinh";
        os << "|";
        os << setw(widths[5]) << left << "HS Luong" << endl;
        os << string(sum, '-') << endl;

        int cnt = 0;
        for(NhanVien nv: qlnv.nhanVien){
            os << setw(widths[0]) << left << ++cnt;
            os << "|";
            os << setw(widths[1]) << left << nv.id;
            os << "|";
            os << setw(widths[2]) << left << nv.hoTen;
            os << "|";
            os << setw(widths[3]) << left << nv.congViec;
            os << "|";
            os << setw(widths[4]) << left << nv.namSinh;
            os << "|";
            os << setw(widths[5]) << left << std::fixed << std::setprecision(1) << nv.hsLuong << endl;
        }

        return os;
    }
};
