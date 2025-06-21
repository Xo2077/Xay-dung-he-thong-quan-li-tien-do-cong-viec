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
    int maNhanVien;     // ma nhân viên phu trách
} CongViec;

// Ghi danh sách nhân viên vào tep
void luuNhanVien(NhanVien *dsNV, int soNV, FILE *f) {
    fprintf(f, "%d\n", soNV);
    for (int i = 0; i < soNV; i++) {
        fprintf(f, "%d|%s|%s\n", dsNV[i].id, dsNV[i].ten, dsNV[i].chucVu);
    }
}

// Ghi danh sách công viec vào tep
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

