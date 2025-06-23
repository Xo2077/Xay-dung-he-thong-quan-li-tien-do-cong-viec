#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NHAN_VIEN 100

typedef struct {
    int id;
    char ten[50];
    char viTri[50];
} NhanVien;

NhanVien danhSachNhanVien[MAX_NHAN_VIEN];
int soLuongNhanVien = 0;

// --- Cac chuc nang quan ly nhan vien ---
void themNhanVien() {
    if (soLuongNhanVien >= MAX_NHAN_VIEN) {
        printf(">> Danh sach nhan vien da day!\n");
        return;
    }
    NhanVien nv;
    nv.id = soLuongNhanVien + 1;
    printf("Nhap ten nhan vien: ");
    scanf(" %49[^\n]", nv.ten);
    printf("Nhap vi tri: ");
    scanf(" %49[^\n]", nv.viTri);
    danhSachNhanVien[soLuongNhanVien++] = nv;
    printf(">> Da them nhan vien: %s, Vi tri: %s\n", nv.ten, nv.viTri);
}

void luuNhanVien() {
    FILE *f = fopen("nv.txt", "a");
    if (!f) {
        printf(">> Khong the mo file de ghi!\n");
        return;
    }
    for (int i = 0; i < soLuongNhanVien; i++) {
        fprintf(f, "%s\n", danhSachNhanVien[i].ten);
        fprintf(f, "%s\n", danhSachNhanVien[i].viTri);
        fprintf(f, "%d\n", danhSachNhanVien[i].id);
    }
    fclose(f);
    printf(">> Da luu danh sach nhan vien vao file nv.txt\n");
}

void hienThiNhanVien() {
    printf("\n--- Danh sach nhan vien ---\n");
    if (soLuongNhanVien == 0) {
        printf("Chua co nhan vien nao.\n");
        return;
    }
    for (int i = 0; i < soLuongNhanVien; i++) {
        printf("ID: %d, Ten: %s, Vi tri: %s\n",
               danhSachNhanVien[i].id,
               danhSachNhanVien[i].ten,
               danhSachNhanVien[i].viTri);
    }
}

void xoaNhanVien() {
    int id;
    printf("Nhap ID nhan vien can xoa: ");
    scanf("%d", &id);
    int timThay = 0;
    for (int i = 0; i < soLuongNhanVien; i++) {
        if (danhSachNhanVien[i].id == id) {
            timThay = 1;
            for (int j = i; j < soLuongNhanVien - 1; j++) {
                danhSachNhanVien[j] = danhSachNhanVien[j + 1];
            }
            soLuongNhanVien--;
            printf(">> Da xoa nhan vien ID %d\n", id);
            break;
        }
    }
    if (!timThay)
        printf(">> Khong tim thay nhan vien voi ID %d\n", id);
}

void quanLyNhanVien() {
    int luaChon;
    do {
        printf("\n--- QUAN LY NHAN VIEN ---\n");
        printf("1. Them nhan vien\n");
        printf("2. Hien thi danh sach nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Luu vao file\n");
        printf("0. Quay lai menu chinh\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1: themNhanVien(); break;
            case 2: hienThiNhanVien(); break;
            case 3: xoaNhanVien(); break;
            case 4: luuNhanVien(); break;
            case 0: printf("Quay lai menu chinh...\n"); break;
            default: printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    } while (luaChon != 0);
}
