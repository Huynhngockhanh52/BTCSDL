#include <bits/stdc++.h>
#include "sanpham.h"

using namespace std;
void SanPham :: setSP(string ID, string SP, string Type, string HSD, int SL) {
    ID_SP = ID;
    Ten_SP = SP;
    Loai_SP = Type;
    HSD_SP = HSD;
    SL_SP = SL;
}

void SanPham :: setMaSP(string ID) {
    this -> ID_SP = ID;
}

void SanPham :: setTenSP(string SP) {
    this -> Ten_SP = SP;
}

void SanPham :: setLoaiSP(string Type) {
    this -> Loai_SP = Type;
}

void SanPham :: setHSDSP(string HSD) {
    this -> HSD_SP = HSD;
}

void SanPham :: setSoluongSP(int SL) {
    this -> SL_SP = SL;
}

string SanPham :: getMaSP() {
    return ID_SP;
}

string SanPham :: getTenSP() {
    return Ten_SP;
}

string SanPham :: getLoaiSP(){
    return Loai_SP;
}

string SanPham :: getHSDSP(){
    return HSD_SP;
}

int SanPham :: getSoluongSP() {
    return SL_SP;
}