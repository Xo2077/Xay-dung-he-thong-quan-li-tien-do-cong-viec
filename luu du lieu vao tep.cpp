#include <stdio.h>

typedef struct {
    int id;
    char ten[50];
    char chucVu[30];
} NhanVien;

typedef struct {
    int maCV;
    char tenCV[100];
    char trangThai[20]; // "Chua lam", "Dang lam", "Hoan thanh"
    int maNhanVien;     // ma nh�n vi�n phu tr�ch
} CongViec;

// Ghi danh s�ch nh�n vi�n v�o tep
void luuNhanVien(NhanVien *dsNV, int soNV, FILE *f) {
    fprintf(f, "%d\n", soNV);
    for (int i = 0; i < soNV; i++) {
        fprintf(f, "%d|%s|%s\n", dsNV[i].id, dsNV[i].ten, dsNV[i].chucVu);
    }
}

// Ghi danh s�ch c�ng viec v�o tep
void luuCongViec(CongViec *dsCV, int soCV, FILE *f) {
    fprintf(f, "%d\n", soCV);
    for (int i = 0; i < soCV; i++) {
        fprintf(f, "%d|%s|%s|%d\n", dsCV[i].maCV, dsCV[i].tenCV, dsCV[i].trangThai, dsCV[i].maNhanVien);
    }
}

// Ham chinh de luu toan bo du lieu vao file 
void luuDuLieu(NhanVien *dsNV, int soNV, CongViec *dsCV, int soCV) {
    FILE *f = fopen("dulieu.txt", "w");
    if (f == NULL) {
        printf("Khong mo duoc tep de ghi.\n");
        return;
    }

    fprintf(f, "== DANH SACH NHAN VIEN ==\n");
    luuNhanVien(dsNV, soNV, f);

    fprintf(f, "== DANH SACH CONG VIEC ==\n");
    luuCongViec(dsCV, soCV, f);

    fclose(f);
    printf("Da luu du lieu vao tep thanh cong.\n");
}

