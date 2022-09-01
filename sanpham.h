#ifndef SP_H
#define SP_H
#include "string"

using namespace std;

class SanPham {
	protected:
        string ID_SP;
        string Ten_SP;
        string Loai_SP;
        string HSD_SP;
        int SL_SP;
    public:
        void setSP(string, string, string, string, int);
        void setMaSP(string);
        void setTenSP(string);
        void setLoaiSP(string);
        void setHSDSP(string);
        void setSoluongSP(int);
        string getMaSP();
        string getTenSP();
        string getLoaiSP();
        string getHSDSP();
        int getSoluongSP();
};

#endif